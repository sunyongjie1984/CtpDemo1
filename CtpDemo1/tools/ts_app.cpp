///ʵ�ֽ��״�������ĳ�����
/**
 *Դ��������: ts_app.cpp
 *ϵͳ����: NEEQ1.0 ���״������
 *ģ������: �����
 *����˵��: ��Դ�ļ�ʵ����Ӧ�ÿ��
 *��   ��: shoujj
 *��   Ȩ: neeq
 *��������: 20130803
 *�޸ļ�¼��
 *20140201  *****
 */
#include <iostream>

//#include <core/qs/qsqm_api.h>

#include "ts_app.h"
#include "event_id.h"
//#include "ts_init.h"

///���������
static CTS_APP g_TS_APP;
CTS_APP* pApp = &g_TS_APP;

//���ػ����init���� ��ɽ��״�������ĳ�ʼ������
int32_t CTS_APP::init(int32_t argc, char** argv)
{
    NOTICE(TS_INFO_START, "TS start");
    NOTICE(TS_NOTICE_STATRTINIT, "TS init start");
    NOTICE(TS_NOTICE_FINISHINIT, "TSinit finished");
    return 0;
}

//���ػ����fini���������ڽ����������
int32_t CTS_APP::fini()
{
    NOTICE(TS_INFO_BEGIN_STOP, "TS start stoping");
    //ֹͣ�鲥����
    INFO(TS_INFO_BEGIN_STOPMULTICASTRECV, "TS stop multi cast receiver");
    return 0;
}

//���ػ��ຯ�� ����ָ���汾��
const char* CTS_APP::version() const
{
    return APP_VERSION;
}

