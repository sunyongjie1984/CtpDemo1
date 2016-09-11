///���彻�״�������ĳ�����
/**
 *Դ��������: ts_app.h
 *ϵͳ����: NEEQ1.0 ���״������
 *ģ������: �����
 *����˵��: ��ͷ�ļ�������Ӧ�ÿ��
 *��   ��: shoujj
 *��   Ȩ: neeq
 *��������: 20130803
 *�޸ļ�¼��
 *V0.0.2 20131002 xuzj ���ݴ�������ṹ�����������
 *V0.0.3 20131010 xuzj �޸�֤ȯ�����֤ȯ���ĳ�ʼ���ļ��ṹ����Ҫ�漰��Ч�۸��������ƵĿ��ƣ���Ҫ���³�ʼ��DBF�ļ���
 *V0.0.4 20131015 xuzj �޸�ԭʼί�нṹ����������ϵ�ˡ�������ϵ��ʽ���ֶ����͵ĳ��ȶ��壬��Ҫ������ģ��ͬ����ϼ���
 *       20131015 sunyj ���ݿ�ܽṹ����������Ӧ���
 *       20131016 xuzj Ϊ�˼���7000W���˻����ݣ��ѽ�֤ȯ�˻��б�����HASH�������Ϊ1�ڣ����ܵ�������ʱ��Ƚ���
 *V0.1.0 20131130 xuzj ���µ�ҵ��������е���
 *V0.1.1 20131202 xuzj ����������1.1���޸Ĵ���
 *V0.1.2 20131219 xuzj ��������ά����ص�bug��
 *V0.1.3 20131225 sunyj �������׵�Ԫ������ص�bug��
 *V0.1.6 20140114 xuzj ����ԭͣ�ƹ�Ʊ��������ʱ�޷���ȷ���ƵĴ������������ϵ�ʱ�ɽ����������Ϊ0�������
 *V0.1.8 20140225 sunyj �������ƣ���Ʊ��������֤ȯ���ס��������ֱ���˳�
 *V0.1.9 20140225 sunyj �޸�bug NEEQ-1569
 */
 
#ifndef _TS_APP_H_
#define _TS_APP_H_

//#include <os/memshared.h>

//#include <Class/file.h>
#include <event.h>

#include <frame_app.h>

//#include "ts_init.h"
//#include "ts_order_book.h"
//#include "ts_memory_pool.h"
//#include "ts_match_interface.h"

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
///// ��ع����ڴ��KeyĬ��ֵ
//#define TS_MON_SHAREMEMKEY "TS_MON_SHAREMEM"

class CTS_APP: public CFrameApp
{
public:
	//CTS_APP() : m_pMatch(NULL), m_pPublicQuotation(NULL), m_pRMReceiver(NULL), m_pRMSender(NULL),
	//m_pMonShareDataTS(NULL) { }
    CTS_APP() { }
    ///��ʼ���ӿ�
   virtual int32_t init(int32_t argc, char** argv);
   
    ///�����ӿ�
    virtual int32_t fini();

    ///�汾��Ϣ�ӿ�
    virtual const char* version() const;

protected:

private:
};

extern CTS_APP* pApp;
#define CAPP pApp

#endif /* _TS_APP_H_ */

