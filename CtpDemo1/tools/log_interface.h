///д��־�ӿڶ���
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: log_interface.h
����˵��:
��    ��: �����
��������: 2013-7-23   20:05:22
�޸ļ�¼:
***********************************************************************/
#ifndef _LOG_INTERFACE_H_
#define _LOG_INTERFACE_H_

#include <config_env.h>


/* Log Types */
enum LogType
{
    LOG_TYPE_STDOUT     = 0,        /* �ն���� */
    LOG_TYPE_FILE       = 1         /* ��־��� */
};

/* Log levels��ֵԽ�󼶱�Խ�� */
enum LogLevel
{
    LOG_LEVEL_EMERG     = 0,        /* ��߼���ϵͳ�����ã��ݲ�ʹ�� */
    LOG_LEVEL_ALERT     = 1,        /* �������𣺽����¼�������������ȡ��ʩ���ݲ�ʹ�� */
    LOG_LEVEL_CRIT      = 2,        /* ���ؼ����ٽ�����������Ӱ��ҵ��������״̬ʱ����� */
    LOG_LEVEL_ERROR     = 3,        /* ���󼶱𣺴�����Ϣ��Ӱ��ҵ������Ҫ�˹����룬���ļ���ʧ�ܵ� */
    LOG_LEVEL_WARNING   = 4,        /* ���漶�𣺸澯����Ӱ��ҵ����Ϣ��һ�㲻��Ҫ�˹����룬����Ҫ�����Ա���������յ����Ϸ�����Ϣ */
    LOG_LEVEL_NOTICE    = 5,        /* ֪ͨ������ʾ��Ϣ������Ҫ����Ϣ��дsyslog��������״̬�¼� */
    LOG_LEVEL_INFO      = 6,        /* ��Ϣ����ҵ��������Ϣ����дsyslog�����ʼ���ɹ���������ָ�����ά��ָ�� */
    LOG_LEVEL_DEBUG     = 7         /* ���Լ��𣺵�������Ϣ����дsyslog */
};

class CLogInterface 
{
public:
    ///���캯��
    CLogInterface() {}

    ///��������
    virtual ~CLogInterface() {}

    ///д��־
	/**
     *@param int32_t iErrCode�������
	 *@param int32_t iLevel����־����
     *@param const char* chFormat����־��ʽ
     *@param ...���䳤����
	 *@return: ���ز��������0��ʾ�ɹ�������ֵ��ʾʧ��
	 */
    virtual int32_t write_log(int32_t iErrCode, int32_t iLevel, const char* chFormat, ...) = 0;

    ///���½ӿ�������ͬһ�����̲�ͬģ�飬Ŀǰ���ṩ������ģ��дϵͳ��־ʹ��
    ///д��־
	/**
     *@param const char* chAppName����������
     *@param int32_t iAppType��Ӧ������
     *@param int32_t iErrCode�������
	 *@param int32_t iLevel����־����
     *@param const char* chFormat����־��ʽ
     *@param ...���䳤����
	 *@return: ���ز��������0��ʾ�ɹ�������ֵ��ʾʧ��
	 */
    virtual int32_t write_log(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* chFormat, ...) = 0;
};

/* ��¼��־λ����Ϣ */
//#define FMT(str)    "[%s:%d %s]:"str, __FILE__, __LINE__, __FUNCTION__

/* д��־�� */
#define CRIT(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_CRIT, format, ##args))
#define ERROR(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_ERROR, format, ##args))
#define WARNING(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_WARNING, format, ##args))
#define NOTICE(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_NOTICE, format, ##args))
#define INFO(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_INFO, format, ##args))
#define DEBUG(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_DEBUG, format, ##args))

#define CRIT1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_CRIT, format, ##args))
#define ERROR1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_ERROR, format, ##args))
#define WARNING1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_WARNING, format, ##args))
#define NOTICE1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_NOTICE, format, ##args))
#define INFO1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_INFO, format, ##args))
#define DEBUG1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_DEBUG, format, ##args))

#endif
