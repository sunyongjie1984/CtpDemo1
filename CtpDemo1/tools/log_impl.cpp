///д��־��ʵ��
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: log_impl.cpp
����˵��:
��    ��: �����
��������: 2013-7-23   20:51:39
�޸ļ�¼:
***********************************************************************/
#include <stdarg.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/syscall.h>  
#include "log_impl.h"  

#include "frame_app.h"


/* ��־�����ַ��� */
const char* chLogLevel[] = {"EMERG", "ALERT", "CRIT", "ERROR", "WARNING", "NOTICE", "INFO", "DEBUG"};

/* ��ȡ�̺߳� */
#define gettid() syscall(__NR_gettid)  

/* Ĭ����־��Ϣ����� */
#define MAX_LOGMSG_LEN      1024 * 1024

/* ��־Ĭ�����Ŀ¼ */
#define LOG_OUTPUT_DIR      "./"

CLogImpl* CLogImpl::getInstance()
{
    static CLogImpl one;
    return &one;
}

CLogImpl::~CLogImpl()
{
    closelog();
    if (m_fp != stdout && m_fp != NULL)
    {
        fclose(m_fp);
    }
}

int32_t CLogImpl::open(int32_t iLogType /* = LOG_TYPE_STDOUT */)
{
    /* ��ʼ��������־ */
    int32_t iRet = 0;
    switch (iLogType)
    {
    case LOG_TYPE_STDOUT:
    	iRet = open_stdout();
        break;
    case LOG_TYPE_FILE:
        iRet = open_file();
        break;
    default:
        fprintf(stderr, "[%s:%d]Unknown log type: %d\n", __FILE__, __LINE__, iLogType);
        return -1;
    }
    /* ��ʼ��ʧ�ܣ�����ʧ�� */
    if (iRet != 0)
    {
        return iRet;
    }

    /* ��ʼ��ϵͳ��־ */
    iRet = open_syslog();
    
    return iRet;
}

int32_t CLogImpl::write_log(int32_t iErrCode, int32_t iLevel, const char* chFormat, ...)
{
    /* ��־�ȼ������趨ѡ�� */
    if ((iLevel&0xff) > COPTIONS->getLogLevel())
    {
        return 0;
    }

    if ((iLevel&0xff) < LOG_LEVEL_EMERG)
    {
        iLevel = LOG_LEVEL_EMERG;
    }

    /* ������־��ʽ */
    va_list ap;
    char msg[MAX_LOGMSG_LEN];
    va_start(ap, chFormat);
    vsnprintf(msg, sizeof(msg), chFormat, ap);
    va_end(ap);

    return writeLog(pFrame_App->getAppName(), COPTIONS->getAppType(), iErrCode, iLevel, msg);
}

int32_t CLogImpl::write_log(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* chFormat, ...)
{
    /* ��־�ȼ������趨ѡ�� */
    if ((iLevel&0xff) > COPTIONS->getLogLevel())
    {
        return 0;
    }

    if ((iLevel&0xff) < LOG_LEVEL_EMERG)
    {
        iLevel = LOG_LEVEL_EMERG;
    }

    /* ������־��ʽ */
    va_list ap;
    char msg[MAX_LOGMSG_LEN];
    va_start(ap, chFormat);
    vsnprintf(msg, sizeof(msg), chFormat, ap);
    va_end(ap);

    return writeLog(chAppName, iAppType, iErrCode, iLevel, msg);
}

CLogImpl::CLogImpl()
: m_iLogType(LOG_TYPE_STDOUT)
, m_fp(stdout)
{
}

int32_t CLogImpl::open_stdout()
{
    /* ���ն���Ļ��� */
    m_iLogType = LOG_TYPE_STDOUT;
    m_fp = stdout;

    return 0;
}

int32_t CLogImpl::open_file()
{
    /* �������ļ���� */
    m_iLogType = LOG_TYPE_FILE;

    /* ��־���Ŀ¼���������Ŀ¼ */
    const char* chLogDir = CCONFIG->GetString("APP", "log_dir", LOG_OUTPUT_DIR);
    /* mkdir(chLogDir, 0777); */

    /* ��־�ļ�����Ĭ�ϡ�������-���̱��-������.log�� */
    struct tm tmNow;
    time_t ttime = time(NULL); 
    localtime_r(&ttime, &tmNow);
    char chLogFileTmp[256];
    sprintf(chLogFileTmp, 
            "%s-%d-%d%02d%02d.log", 
            COPTIONS->getProName(), 
            COPTIONS->getProNum(), 
            tmNow.tm_year+1900, 
            tmNow.tm_mon+1, 
            tmNow.tm_mday);

    const char* chLogFile = CCONFIG->GetString("APP", "log_file", chLogFileTmp);

    char chLogFileFull[256];
    sprintf(chLogFileFull, "%s/%s", chLogDir, chLogFile);

    /* �������־�ļ����ڼ���ʹ�ã������½� */
    m_fp = fopen(chLogFileFull, "a");
    if (m_fp == NULL)
    {
        /* ���� */
        m_fp = fopen(chLogFileFull, "wt");
        if (m_fp == NULL)
        {
            fprintf(stderr, "[%s:%d]Failed to fopen log file.\n", __FILE__, __LINE__);
            return -1;
        }
        fclose(m_fp);

        /* �� */
        m_fp = fopen(chLogFileFull, "a");
        if (m_fp == NULL)
        {
            fprintf(stderr, "[%s:%d]Failed to fopen log file.\n", __FILE__, __LINE__);
            return -1;
        }
    }

    return 0;
}

int32_t CLogImpl::open_syslog()
{
    /* ��ʼ��ϵͳ��־ */
    openlog(pFrame_App->getAppName(), LOG_PID|LOG_NDELAY|LOG_NOWAIT, LOG_LOCAL6);

    return 0;
}

int32_t CLogImpl::writeLog(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* msg)
{
    /* д������־ */
    int32_t iRet = writeLocal(chAppName, iErrCode, iLevel, msg);
    if (iRet != 0)
    {
        fprintf(stderr, "[%s:%d]writeLocal failed: %d\n", __FILE__, __LINE__, iRet);
        return -1;
    }

    /* дϵͳ��־��������NOTICE���²�дϵͳ��־ */
    if (iLevel > LOG_LEVEL_NOTICE) return 0;

    /* дϵͳ��־ */
    iRet = writeSyslog(chAppName, iAppType, iErrCode, iLevel, msg);
    if (iRet != 0)
    {
        fprintf(stderr, "[%s:%d]writeSyslog failed: %d\n", __FILE__, __LINE__, iRet);
        return -1;
    }

    return 0;
}

int32_t CLogImpl::writeLocal(const char* chAppName, int32_t iErrCode, int32_t iLevel, const char* msg)
{
    /* ׼��ʱ��� */
    char chTimeStamp[256];
    getTimeStamp(chTimeStamp);

    /* ����Ļ�������ʽ��[ʱ���][��������][���̺�][�̺߳�][��־����][������]���� */
    CAutoMutex autoMutex(&m_mutex);
    fprintf(m_fp,"[%s][%s][%d][%d][%s][%d]%s\n", 
            chTimeStamp, 
            chAppName, 
            (int32_t)getpid(), 
            (int32_t)gettid(), 
            chLogLevel[iLevel], 
            iErrCode, 
            msg);
    fflush(m_fp);

    return 0;
}

int32_t CLogImpl::writeSyslog(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* msg)
{
    /* ׼��ʱ��� */
    struct tm tmNow;
    time_t ttime = time(NULL);
    localtime_r(&ttime, &tmNow);

    syslog(iLevel, 
           "|_I=%s|_K=%d|_T=%02d%02d%02d|_C=EVENT|_O=1|_E=1##CurrDate=%04d%02d%02d|CurrTime=%02d%02d%02d|EventId=%d|LogLevel=%d|LogBrief=%s|LogInfo=%s|", 
           chAppName, 
           iAppType, 
           tmNow.tm_hour, 
           tmNow.tm_min, 
           tmNow.tm_sec, 
           tmNow.tm_year+1900, 
           tmNow.tm_mon+1, 
           tmNow.tm_mday, 
           tmNow.tm_hour, 
           tmNow.tm_min, 
           tmNow.tm_sec, 
           iErrCode, 
           iLevel, 
           " ", 
           msg);

    return 0;
}

int32_t CLogImpl::getTimeStamp(char* chTimeStamp)
{
    struct tm tmNow;
    time_t ttime = time(NULL);
    localtime_r(&ttime, &tmNow);

    /* ��ʽ��11:43:21 */
    sprintf(chTimeStamp, 
            "%02d:%02d:%02d", 
            tmNow.tm_hour, 
            tmNow.tm_min, 
            tmNow.tm_sec);

    return 0;
}
