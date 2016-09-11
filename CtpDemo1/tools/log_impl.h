///д��־�ඨ��
/***********************************************************************
ϵͳ����:
ģ������:
�� �� ��: log_impl.h
����˵��:
��    ��:
��������: 2013-7-23   20:47:57
�޸ļ�¼:
***********************************************************************/
#ifndef _LOG_IMPL_H_
#define _LOG_IMPL_H_

#include <thread_mutex.h>

#include <log_interface.h>


class CLogImpl: public CLogInterface 
{
public:
    ///�������ʼ���ӿ�
    static CLogImpl* getInstance();

    ///��������
    virtual ~CLogImpl();

    ///����־�ļ���Ĭ��Ϊ���ն����
    int32_t open(int32_t iLogType = LOG_TYPE_STDOUT);

    ///д��־1
    virtual int32_t write_log(int32_t iErrCode, int32_t iLevel, const char* chFormat, ...);

    ///д��־2
    virtual int32_t write_log(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* chFormat, ...);

protected:
private:
    ///���ι��캯��
    CLogImpl();

    ///���ο������캯��
    CLogImpl(const CLogImpl& one);

    ///���θ�ֵ������
    const CLogImpl& operator=(const CLogImpl& one);

    ///�򿪱�����־���ն����
    int32_t open_stdout();

    ///�򿪱�����־��������־
    int32_t open_file();

    ///��ϵͳ��־
    int32_t open_syslog();

    ///д��־�ļ�
    int32_t writeLog(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* msg);

    ///д������־�ļ�
    int32_t writeLocal(const char* chAppName, int32_t iErrCode, int32_t iLevel, const char* msg);

    ///дϵͳ��־�ļ�
    int32_t writeSyslog(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* msg);

    ///ͳһʱ���
    int32_t getTimeStamp(char* chTimeStamp);

private:
    ///��־����
    int32_t m_iLogType;

    ////��־�ļ����(C��)
    FILE* m_fp;

    ///������������д������־�ļ�
    CThreadMutex m_mutex;
};

#define CLOG CLogImpl::getInstance()

#endif
