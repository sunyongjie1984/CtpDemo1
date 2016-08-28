#include <iostream>
#include "MyTraderSpi.h"

// UserApi对象
CThostFtdcTraderApi* pUserApi;

// char  FRONT_ADDR[] = "tcp://180.168.146.187:10030";		// 前置地址
char  FRONT_ADDR[] = "tcp://180.168.146.187:10000";		// 前置地址
TThostFtdcBrokerIDType	BROKER_ID = "9999";				// 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "009637";			// 投资者代码
TThostFtdcPasswordType  PASSWORD = "sim0594184520";			// 用户密码

TThostFtdcInstrumentIDType INSTRUMENT_ID = "cu0909";	// 合约代码
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// 买卖方向
TThostFtdcPriceType	LIMIT_PRICE = 38850;				// 价格

														// 请求编号
int iRequestID = 0;

int main()
{
	// 初始化UserApi
	pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// 创建UserApi
 	CTraderSpi* pUserSpi = new CTraderSpi();
 	pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// 注册事件类
 	pUserApi->SubscribePublicTopic(THOST_TERT_RESTART);					// 注册公有流
 	pUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);					// 注册私有流
 	pUserApi->RegisterFront(FRONT_ADDR);							// connect
 	pUserApi->Init();

 	pUserApi->Join();
	//	pUserApi->Release();

	return 0;
}