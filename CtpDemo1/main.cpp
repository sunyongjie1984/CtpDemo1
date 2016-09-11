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
//#include "log_interface.h"
//#include "log_impl.h"
//#include "ts_app.h"
#else
#include <Windows.h>
#endif

///定义主框架
//static CTS_APP g_TS_APP;
//CTS_APP* pApp = &g_TS_APP;

// UserApi对象
CThostFtdcTraderApi* pUserApi;

// char FRONT_ADDR[] = "tcp://180.168.146.187:10000";     // 前置地址
char FRONT_ADDR[] = "tcp://180.168.146.187:10030";     // 前置地址
TThostFtdcBrokerIDType BROKER_ID = "9999";             // 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "069637";       // 投资者代码
TThostFtdcPasswordType PASSWORD = "sim0594184520";     // 用户密码

TThostFtdcInstrumentIDType INSTRUMENT_ID = "ag1612";   // 合约代码
TThostFtdcDirectionType DIRECTION = THOST_FTDC_D_Sell; // 买卖方向
TThostFtdcPriceType LIMIT_PRICE = 38850;               // 价格

// 请求编号
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

int32_t main(int32_t argc, char** argv)
{
    pFrame_App->run(argc, argv);
    /*
    int iResult;
    iResult = CLOG->open(0);
    if (iResult != 0)
    {
        fprintf(stderr, "[%s:%d]open log file failed.\n", __FILE__, __LINE__);
        exit(-1);
    }
    // sigset(SIGUSR1, sTerminate);
    // 初始化UserApi
    pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(); // 创建UserApi
    CTraderSpi* pUserSpi = new CTraderSpi();
    pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi); // 注册事件类
    pUserApi->SubscribePublicTopic(THOST_TERT_RESTART);    // 注册公有流
    pUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);   // 注册私有流
    pUserApi->RegisterFront(FRONT_ADDR);                   // connect
    pUserApi->Init();

    INFO(0, "start waiting for RspSettlementInfoConfirm");
    std::cout << "start waiting for RspSettlementInfoConfirm" << std::endl;
    RspSettlementEvent.Wait();
    std::cout << "Wait return ! RspSettlementEvent" << std::endl;
    iResult = pUserSpi->ReqQryTradingAccount();
    if (0 != iResult)
    {
        std::cout << "" << std::endl;
    }
    std::cout << "start waiting for RspQryTradingEvent" << std::endl;
    RspQryTradingEvent.Wait();
    std::cout << "Wait return ! RspQryTradingEvent" << std::endl;
    iResult = pUserSpi->ReqQryInvestorPosition();
    if (0 != iResult)
    {
        MySleep(1);
        pUserSpi->ReqQryInvestorPosition();
    }
    // MySleep(1);
    // 报单录入请求
    //pUserSpi->ReqOrderInsert(INSTRUMENT_ID, 4336.0, 1);
    // MySleep(1);
    // pUserSpi->ReqQryInstrument();
    // MySleep(1);
    // pUserSpi->ReqQryOrder();
    // MySleep(2);

    pUserApi->Join();
    // pUserApi->Release();

    */
    return 0;
}
