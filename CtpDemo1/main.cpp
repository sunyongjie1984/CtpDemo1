#include <iostream>
#include "MyTraderSpi.h"
#ifdef _linux
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#else
#include <Windows.h>
#endif

// UserApi����
CThostFtdcTraderApi* pUserApi;

char FRONT_ADDR[] = "tcp://180.168.146.187:10000";     // ǰ�õ�ַ
//char FRONT_ADDR[] = "tcp://180.168.146.187:10030";     // ǰ�õ�ַ
TThostFtdcBrokerIDType BROKER_ID = "9999";             // ���͹�˾����
TThostFtdcInvestorIDType INVESTOR_ID = "069637";       // Ͷ���ߴ���
TThostFtdcPasswordType PASSWORD = "sim0594184520";     // �û�����

TThostFtdcInstrumentIDType INSTRUMENT_ID = "ag1612";   // ��Լ����
TThostFtdcDirectionType DIRECTION = THOST_FTDC_D_Sell; // ��������
TThostFtdcPriceType LIMIT_PRICE = 38850;               // �۸�

// ������
int iRequestID = 0;
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

int main()
{
    // sigset(SIGUSR1, sTerminate);
    // ��ʼ��UserApi
    pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(); // ����UserApi
    CTraderSpi* pUserSpi = new CTraderSpi();
    pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi); // ע���¼���
    pUserApi->SubscribePublicTopic(THOST_TERT_RESTART);    // ע�ṫ����
    pUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);   // ע��˽����
    pUserApi->RegisterFront(FRONT_ADDR);                   // connect
    pUserApi->Init();

    // MySleep(5);
    // pUserSpi->ReqQryTradingAccount();
    // MySleep(2);
    // pUserSpi->ReqQryInvestorPosition();
    // ����¼������
    // pUserSpi->ReqOrderInsert(INSTRUMENT_ID, 4200.0, 14);
    // MySleep(1);
    // pUserSpi->ReqQryInstrument();
    // MySleep(1);
    // pUserSpi->ReqQryOrder();
    // MySleep(2);

    pUserApi->Join();
    // pUserApi->Release();

    return 0;
}
