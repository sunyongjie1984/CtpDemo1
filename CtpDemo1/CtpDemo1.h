///���彻�״�������ĳ�����
/**
 *Դ��������: 
 *ϵͳ����: 
 *ģ������: �����
 *����˵��: ��ͷ�ļ�������Ӧ�ÿ��
 *��   ��: 
 *��   Ȩ: 
 *��������: 
 *�޸ļ�¼��
 */
 
#ifndef _TS_APP_H_
#define _TS_APP_H_

#include "event.h"
#include "frame_app.h"

/// �汾��Ϣ
#define APP_VERSION "V3.0.0 ("__DATE__" "__TIME__")"
/// Ӧ������������ļ��еĶ���
#define TS_SEC_APP "APP"
/// �鲥����ģ������������ļ��еĶ���
#define TS_SEC_RMREVEIVER "RMRECEIVER"
/// �鲥����ģ�飨ί�С��ɽ���ָ�����������ļ��еĶ���
#define TS_SEC_RMSENDER "RMSENDER"
/// �鲥���ձ��ؼ�¼�������ļ�
#define TSSERVER_DATA "ts_server.dat"

class CTS_APP: public CFrameApp
{
public:
    CTS_APP() { }
    ///��ʼ���ӿ�
   virtual int32_t init(int32_t argc, char** argv);

    ///�����ӿ�
    virtual int32_t fini();

    ///�汾��Ϣ�ӿ�
    virtual const char* version() const;

protected:

private:
    int QueryTradingAccountAndPosition();
};

extern CTS_APP* pApp;
#define CAPP pApp

#endif /* _TS_APP_H_ */

