///实现交易撮合主机的程序框架
/**
 *源程序名称:
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

///定义主框架
static CTS_APP g_TS_APP;
CTS_APP* pApp = &g_TS_APP;
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

// 重载基类的init函数 完成交易撮合主机的初始化操作
int32_t CTS_APP::init(int32_t argc, char** argv)
{
    NOTICE(TS_INFO_START, "CtpDemo1 start");
    NOTICE(TS_NOTICE_STATRTINIT, "CtpDemo1 init start");
    // sigset(SIGUSR1, sTerminate);
    // 初始化UserApi
    pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(); // 创建UserApi
    CTraderSpi* pUserSpi = new CTraderSpi();
    pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi); // 注册事件类
    pUserApi->SubscribePublicTopic(THOST_TERT_RESTART);    // 注册公有流
    pUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);   // 注册私有流
    pUserApi->RegisterFront(FRONT_ADDR);                   // connect
    pUserApi->Init();
    NOTICE(TS_NOTICE_FINISHINIT, "CtpDemo1 init finished");
    return 0;
}

// 重载基类的fini函数，用于结束撮合主机
int32_t CTS_APP::fini()
{
    NOTICE(TS_INFO_BEGIN_STOP, "CtpDemo1 stoping");
    return 0;
}

// 重载基类函数 用于指定版本号
const char* CTS_APP::version() const
{
    return APP_VERSION;
}

