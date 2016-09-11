///ʵ�ֽ��״�������ĳ�����
/**
 *Դ��������:
 */
#include <iostream>

#include "MyTraderSpi.h"
#ifdef _linux
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "frame_app.h"
#include "event.h"
#else
#include <Windows.h>
#endif
#include "CtpDemo1.h"
#include "event_id.h"

///���������
static CTS_APP g_TS_APP;
CTS_APP* pApp = &g_TS_APP;
// UserApi����
CThostFtdcTraderApi* pUserApi;

// char FRONT_ADDR[] = "tcp://180.168.146.187:10000";     // ǰ�õ�ַ
char FRONT_ADDR[] = "tcp://180.168.146.187:10030";     // ǰ�õ�ַ
TThostFtdcBrokerIDType BROKER_ID = "9999";             // ���͹�˾����
TThostFtdcInvestorIDType INVESTOR_ID = "069637";       // Ͷ���ߴ���
TThostFtdcPasswordType PASSWORD = "sim0594184520";     // �û�����

TThostFtdcInstrumentIDType INSTRUMENT_ID = "ag1612";   // ��Լ����
TThostFtdcDirectionType DIRECTION = THOST_FTDC_D_Sell; // ��������
TThostFtdcPriceType LIMIT_PRICE = 38850;               // �۸�

// ������
int iRequestID = 0;
CEvent RspSettlementEvent;
CEvent RspQryTradingEvent;
/**
 *  * functions to handle the signal of SIGUSR1
 *   * if the value of static variable iExtFlag is not equal zero, this func will exit without waiting for the main function to do to other things.
 *    */
/*void sTerminate()
{
    printf( "Get a SIGUSR1 signal!\n" );
    return;
}
*/


void MySleep(const int n)
{
#ifdef _linux
    sleep(n);
#else
    Sleep(n * 1000);
#endif
}

// ���ػ����init���� ��ɽ��״�������ĳ�ʼ������
int32_t CTS_APP::init(int32_t argc, char** argv)
{
    NOTICE(TS_INFO_START, "CtpDemo1 start");
    NOTICE(TS_NOTICE_STATRTINIT, "CtpDemo1 init start");
    // sigset(SIGUSR1, sTerminate);
    // ��ʼ��UserApi
    pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(); // ����UserApi
    CTraderSpi* pUserSpi = new CTraderSpi();
    pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi); // ע���¼���
    pUserApi->SubscribePublicTopic(THOST_TERT_RESTART);    // ע�ṫ����
    pUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);   // ע��˽����
    pUserApi->RegisterFront(FRONT_ADDR);                   // connect
    pUserApi->Init();
    NOTICE(TS_NOTICE_FINISHINIT, "CtpDemo1 init finished");
    return 0;
}

// ���ػ����fini���������ڽ����������
int32_t CTS_APP::fini()
{
    NOTICE(TS_INFO_BEGIN_STOP, "CtpDemo1 stoping");
    return 0;
}

// ���ػ��ຯ�� ����ָ���汾��
const char* CTS_APP::version() const
{
    return APP_VERSION;
}

