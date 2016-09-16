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
static CCtpDemo1 g_TS_APP;
CCtpDemo1* pApp = &g_TS_APP;
// UserApi对象
CThostFtdcTraderApi* pUserApi;
CTraderSpi* pUserSpi;

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

// Events
CEvent RspSettlementEvent;
CEvent RspQryTradingEvent;
CEvent RspQryPositionEvent;
/*
 *   functions to handle the signal of SIGUSR1
 *    if the value of static variable iExtFlag is not equal zero, this func will exit without waiting for the main function to do to other things.
 */
/*void sTerminate()
{
    printf( "Get a SIGUSR1 signal!\n" );
    return;
}
*/


void MySleep(const int n)
{
    INFO(CTPDEMO1_DEBUG, "Enter %s", __FUNCTION__);
#ifdef _linux
    sleep(n);
#else
    Sleep(n * 1000);
#endif
}

// 重载基类的init函数 完成交易撮合主机的初始化操作
int32_t CCtpDemo1::init(int32_t argc, char** argv)
{
    NOTICE(TS_INFO_START, "CtpDemo1 start");
    NOTICE(TS_NOTICE_STATRTINIT, "CtpDemo1 init start");
    NOTICE(TS_NOTICE_STATRTINIT, "CtpDemo1 version %s", version());
    // sigset(SIGUSR1, sTerminate);
    // 初始化UserApi
    pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(); // 创建UserApi
    CTraderSpi* pUserSpi = new CTraderSpi();
    pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi); // 注册事件类
    pUserApi->SubscribePublicTopic(THOST_TERT_RESTART);    // 注册公有流
    pUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);   // 注册私有流
    pUserApi->RegisterFront(FRONT_ADDR);                   // connect
    NOTICE(TS_NOTICE_STATRTINIT, "front address: %s", FRONT_ADDR);
    pUserApi->Init();

    sleep(1);
    // 投资者结算结果确认
    pUserSpi->ReqSettlementInfoConfirm();
    RspSettlementEvent.Wait();
    DEBUG(CTPDEMO1_DEBUG, "Wait return ! RspSettlementIffoConfirm");
    NOTICE(TS_NOTICE_FINISHINIT, "CtpDemo1 init finished");
    return 0;
}

void CCtpDemo1::work()
{
    INFO(CTPDEMO1_DEBUG, "Enter %s", __FUNCTION__);
    /* 主线程等待系统终止信号 */
    while (!m_iShutdown)
    {
        usleep(100 * 1000);
        unsigned int option;
        DEBUG(CTPDEMO1_DEBUG, "0: QueryTradingAccount");
        DEBUG(CTPDEMO1_DEBUG, "1: QueryInvestorPosition");
        DEBUG(CTPDEMO1_DEBUG, "9: exit);
        std::cin >> option;
        switch (option)
          {
              case 0:
                  QueryTradingAccount();
                  break;
              case 1:
                  QueryInvestorPosition();
                  break;
              case 9:
				  m_iShutdown = true;
                  break;
              default:
                  break;
          }
    }
    return;
}


int CCtpDemo1::OrderInsert(CThostFtdcInputOrderField* pOrder) const
{
// const char* const pInstrument_ID, const TThostFtdcDirectionType direction, const TThostFtdcOffsetFlagType flag, const double price, const int amount)
	CThostFtdcInputOrderField order;
	memset(&order, 0, sizeof(order));
	const char* pInstrument_ID = "ag1612";
	const TThostFtdcDirectionType direction = THOST_FTDC_D_Buy;
	TThostFtdcOffsetFlagType flag = THOST_FTDC_OF_Close;
	TThostFtdcMoneyType price = 4430;
	TThostFtdcVolumeType amount = 14;
	pUserSpi->ReqOrderInsert(pInstrument_ID, direction, flag, price, amount);
}

int CCtpDemo1::QueryTradingAccount()
{
    INFO(CTPDEMO1_DEBUG, "Enter %s", __FUNCTION__);
    sleep(1);
    int iResult;
    iResult = pUserSpi->ReqQryTradingAccount();
    if (0 != iResult)
    {
        DEBUG(CTPDEMO1_DEBUG, "iResult = %d", iResult);
    }
    DEBUG(CTPDEMO1_DEBUG, "start waiting for RspQryTradingEvent");
    RspQryTradingEvent.Wait();
    DEBUG(CTPDEMO1_DEBUG, "Wait return ! RspQryTradingEvent");
    return iResult;
}

int CCtpDemo1::QueryInvestorPosition()
{
    INFO(CTPDEMO1_DEBUG, "Enter %s", __FUNCTION__);
    MySleep(1);
    int iResult;
    iResult = pUserSpi->ReqQryInvestorPosition();
    if (0 != iResult)
    {
        DEBUG(CTPDEMO1_DEBUG, "iResult = %d", iResult);
    }
    DEBUG(CTPDEMO1_DEBUG, "start waiting for RspQryPositionEvent");
    RspQryPositionEvent.Wait();
    DEBUG(CTPDEMO1_DEBUG, "Wait return ! RspQryPositionEvent");
    return iResult;
}

// 重载基类的fini函数，用于结束撮合主机
int32_t CCtpDemo1::fini()
{
    INFO(CTPDEMO1_DEBUG, "Enter %s", __FUNCTION__);
    NOTICE(TS_INFO_BEGIN_STOP, "CtpDemo1 stoping");
    return 0;
}

// 重载基类函数 用于指定版本号
const char* CCtpDemo1::version() const
{
    INFO(CTPDEMO1_DEBUG, "Enter %s", __FUNCTION__);
    return APP_VERSION;
}

