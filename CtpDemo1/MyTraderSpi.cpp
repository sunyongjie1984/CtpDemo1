#include <iostream>
#include "MyTraderSpi.h"

#ifdef _linux
#include <string.h>
#endif

using std::cerr;
using std::endl;
using std::cout;

// USER_API参数
extern CThostFtdcTraderApi* pUserApi;

// 配置参数
extern char FRONT_ADDR[];                 // 前置地址
extern char BROKER_ID[];                  // 经纪公司代码
extern char INVESTOR_ID[];                // 投资者代码
extern char PASSWORD[];                   // 用户密码
extern char INSTRUMENT_ID[];              // 合约代码
extern TThostFtdcPriceType LIMIT_PRICE;   // 价格
extern TThostFtdcDirectionType DIRECTION; // 买卖方向

// 请求编号
extern int iRequestID;

// 会话参数
TThostFtdcFrontIDType FRONT_ID;     // 前置编号
TThostFtdcSessionIDType SESSION_ID; // 会话编号
TThostFtdcOrderRefType ORDER_REF;   // 报单引用

void CTraderSpi::OnFrontConnected()
{
    cerr << "--->>> " << "OnFrontConnected" << endl;
    ///用户登录请求
    ReqUserLogin();
}

void CTraderSpi::ReqUserLogin()
{
    CThostFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.UserID, INVESTOR_ID);
    strcpy(req.Password, PASSWORD);
    int iResult = pUserApi->ReqUserLogin(&req, ++iRequestID);
    cerr << "--->>> 发送用户登录请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if (nullptr != pRspInfo)
    {
        if (0 == pRspInfo->ErrorID)
        {
            std::cout << "log in successfully" << std::endl;
        }
        else
        {
            std::cout << "log in failed" << std::endl;
            std::cout << "Error ID = " << pRspInfo->ErrorID << std::endl;
            std::cout << "Error Msg = " << pRspInfo->ErrorMsg << std::endl;
        }
        if (nullptr != pRspUserLogin)
        {
            ShowRspUserLoginField(pRspUserLogin);
        }
        else
        {
        }
    }
    else
    {
            std::cout << "Error !!! pRspInfo is nullptr" << pRspInfo->ErrorMsg << std::endl;
    }
    return;
}

void CTraderSpi::ShowRspUserLoginField(const CThostFtdcRspUserLoginField* const pRspUserLogin) const
{
    if (nullptr != pRspUserLogin)
    {
        std::cout << "date: " << pRspUserLogin->TradingDay << std::endl;
        std::cout << "login time: " << pRspUserLogin->LoginTime << std::endl;
        std::cout << "broker: " << pRspUserLogin->BrokerID << std::endl;
        std::cout << "user: " << pRspUserLogin->UserID << std::endl;
        std::cout << "system name: " << pRspUserLogin->SystemName << std::endl;
    }
    else
    {
        std::cout << "date: " << pRspUserLogin->TradingDay << std::endl;
        std::cout << "login time: " << pRspUserLogin->LoginTime << std::endl;
        std::cout << "broker: " << pRspUserLogin->BrokerID << std::endl;
        std::cout << "user: " << pRspUserLogin->UserID << std::endl;
        std::cout << "system name: " << pRspUserLogin->SystemName << std::endl;
    }
}
