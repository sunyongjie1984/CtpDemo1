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

void MySleep(const int n)
{
#ifdef _linux
    sleep(n);
#else
    Sleep(n * 1000);
#endif
}

void CTraderSpi::OnFrontConnected()
{
    cout << "--->>> " << __FUNCTION__ << endl;
    ///用户登录请求
    ReqUserLogin();
}

// 请求登录
void CTraderSpi::ReqUserLogin()
{
    cout << "--->>> " << __FUNCTION__ << endl;
    CThostFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.UserID, INVESTOR_ID);
    strcpy(req.Password, PASSWORD);
    int iResult = pUserApi->ReqUserLogin(&req, ++iRequestID);
    cout << "--->>> iRequestID=: " << iRequestID << endl;
	cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> 发送用户登录请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        // 保存会话参数
        FRONT_ID = pRspUserLogin->FrontID;
        SESSION_ID = pRspUserLogin->SessionID;
        int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
        iNextOrderRef++;
        sprintf(ORDER_REF, "%d", iNextOrderRef);
		cout << "--->>> FrontID = " << FRONT_ID << endl;
		cout << "--->>> SESSION_ID = " << SESSION_ID << endl;
		cout << "--->>> MaxOrderRef = " << pRspUserLogin->MaxOrderRef << endl;
		// 获取当前交易日
        cout << "--->>> 获取当前交易日 = " << pUserApi->GetTradingDay() << endl;
        MySleep(1);
        // 投资者结算结果确认
        ReqSettlementInfoConfirm();
    }
    if (NULL != pRspInfo)
    {
        if (0 == pRspInfo->ErrorID)
        {
            std::cout << "--->>> log in successfully" << std::endl;
        }
        else
        {
            std::cout << "log in failed" << std::endl;
            std::cout << "Error ID = " << pRspInfo->ErrorID << std::endl;
            std::cout << "Error Msg = " << pRspInfo->ErrorMsg << std::endl;
        }
        if (NULL != pRspUserLogin)
        {
            ShowRspUserLoginField(pRspUserLogin);
        }
        else
        {
            std::cout << "Error !!! pRspUserLogin is nullptr" << std::endl;
        }
    }
    else
    {
            std::cout << "Error !!! pRspInfo is nullptr" << std::endl;
    }
    return;
}

// 投资者结算结果确认
void CTraderSpi::ReqSettlementInfoConfirm()
{
	cout << "--->>> " << __FUNCTION__ << endl;
    CThostFtdcSettlementInfoConfirmField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    int iResult = pUserApi->ReqSettlementInfoConfirm(&req, ++iRequestID);
    cout << "--->>> iRequestID=: " << iRequestID << endl;
	cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> 发送投资者结算结果确认: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        MySleep(1);
        // 请求查询合约
        ReqQryInstrument();
    }
}

// 请求查询合约
void CTraderSpi::ReqQryInstrument()
{
	cout << "--->>> " << __FUNCTION__ << endl;
    CThostFtdcQryInstrumentField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.InstrumentID, INSTRUMENT_ID);
    int iResult = pUserApi->ReqQryInstrument(&req, ++iRequestID);
    cout << "--->>> iRequestID=: " << iRequestID << endl;
	cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> 发送请求查询合约: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
		cout << "--->>> InstrumentID=: " << pInstrument->InstrumentID << endl;
		cout << "--->>> InstrumentName=: " << pInstrument->InstrumentName << endl;
		MySleep(1);
        // 请求查询资金账户
        ReqQryTradingAccount();
    }
}

// 请求查询资金账户
void CTraderSpi::ReqQryTradingAccount()
{
	cout << "--->>> " << __FUNCTION__ << endl;
    CThostFtdcQryTradingAccountField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    int iResult = pUserApi->ReqQryTradingAccount(&req, ++iRequestID);
    cout << "--->>> iRequestID=: " << iRequestID << endl;
	cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> 发送请求查询资金账户: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        MySleep(1);
        // 请求查询投资者持仓
        ReqQryInvestorPosition();
    }
}

// 请求查询投资者持仓
void CTraderSpi::ReqQryInvestorPosition()
{
	cout << "--->>> " << __FUNCTION__ << endl;
    CThostFtdcQryInvestorPositionField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    strcpy(req.InstrumentID, INSTRUMENT_ID);
    int iResult = pUserApi->ReqQryInvestorPosition(&req, ++iRequestID);
    cout << "--->>> iRequestID=: " << iRequestID << endl;
	cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> 发送请求查询投资者持仓: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        MySleep(1);
        // 报单录入请求
        ReqOrderInsert();
    }
}

// 报单录入请求
void CTraderSpi::ReqOrderInsert()
{
    cout << "--->>> " << __FUNCTION__ << endl;
    CThostFtdcInputOrderField req;
    memset(&req, 0, sizeof(req));
    // 经纪公司代码
    strcpy(req.BrokerID, BROKER_ID);
    // 投资者代码
    strcpy(req.InvestorID, INVESTOR_ID);
    // 合约代码
    strcpy(req.InstrumentID, INSTRUMENT_ID);
    // 报单引用
    strcpy(req.OrderRef, ORDER_REF);
    // 用户代码
    //  TThostFtdcUserIDType    UserID;
    // 报单价格条件: 限价
    req.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
    // 买卖方向: 
    req.Direction = DIRECTION;
    // 组合开平标志: 开仓
    req.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
    // 组合投机套保标志
    req.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
    // 价格
    req.LimitPrice = LIMIT_PRICE;
    // 数量: 1
    req.VolumeTotalOriginal = 1;
    // 有效期类型: 当日有效
    req.TimeCondition = THOST_FTDC_TC_GFD;
    // GTD日期
    // TThostFtdcDateType  GTDDate;
    // 成交量类型: 任何数量
    req.VolumeCondition = THOST_FTDC_VC_AV;
    // 最小成交量: 1
    req.MinVolume = 1;
    // 触发条件: 立即
    req.ContingentCondition = THOST_FTDC_CC_Immediately;
    // 止损价
    // TThostFtdcPriceType StopPrice;
    // 强平原因: 非强平
    req.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
    // 自动挂起标志: 否
    req.IsAutoSuspend = 0;
    // 业务单元
    // TThostFtdcBusinessUnitType  BusinessUnit;
    // 请求编号
    // TThostFtdcRequestIDType RequestID;
    // 用户强评标志: 否
    req.UserForceClose = 0;

    int iResult = pUserApi->ReqOrderInsert(&req, ++iRequestID);
    cout << "--->>> iRequestID=: " << iRequestID << endl;
	cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> 发送报单录入请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	IsErrorRspInfo(pRspInfo);
}

// 报单操作请求
void CTraderSpi::ReqOrderAction(CThostFtdcOrderField *pOrder)
{
	cout << "--->>> " << __FUNCTION__ << endl;
    static bool ORDER_ACTION_SENT = false;      //是否发送了报单
    if (ORDER_ACTION_SENT)
        return;

    CThostFtdcInputOrderActionField req;
    memset(&req, 0, sizeof(req));
    // 经纪公司代码
    strcpy(req.BrokerID, pOrder->BrokerID);
    // 投资者代码
    strcpy(req.InvestorID, pOrder->InvestorID);
    // 报单操作引用
    // TThostFtdcOrderActionRefType    OrderActionRef;
    // 报单引用
    strcpy(req.OrderRef, pOrder->OrderRef);
    // 请求编号
    // TThostFtdcRequestIDType RequestID;
    // 前置编号
    req.FrontID = FRONT_ID;
    // 会话编号
    req.SessionID = SESSION_ID;
    // 交易所代码
    // TThostFtdcExchangeIDType    ExchangeID;
    // 报单编号
    // TThostFtdcOrderSysIDType    OrderSysID;
    // 操作标志
    req.ActionFlag = THOST_FTDC_AF_Delete;
    // 价格
    //  TThostFtdcPriceType LimitPrice;
    // 数量变化
    // TThostFtdcVolumeType    VolumeChange;
    // 用户代码
    // TThostFtdcUserIDType    UserID;
    // 合约代码
    strcpy(req.InstrumentID, pOrder->InstrumentID);

    int iResult = pUserApi->ReqOrderAction(&req, ++iRequestID);
    cout << "--->>> iRequestID=: " << iRequestID << endl;
    cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> 发送报单操作请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
    ORDER_ACTION_SENT = true;
}

void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    IsErrorRspInfo(pRspInfo);
    ReqQryOrder();
}

// 报单通知
void CTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (IsMyOrder(pOrder))
    {
        cout << "--->>> is my order" << endl;
        if (IsTradingOrder(pOrder))
            ReqOrderAction(pOrder);
        else if (pOrder->OrderStatus == THOST_FTDC_OST_Canceled)
            cout << "--->>> 撤单成功" << endl;
    }
    else
    {
        cout << "--->>> not my order" << __FUNCTION__ << endl;
    }
}

// 成交通知
void CTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade)
{
	cout << "--->>> " << __FUNCTION__ << endl;
}

void CTraderSpi::OnFrontDisconnected(int nReason)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	cout << "--->>> Reason = " << nReason << endl;
}

void CTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	cout << "--->>> nTimerLapse = " << nTimeLapse << endl;
}

void CTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	IsErrorRspInfo(pRspInfo);
}

bool CTraderSpi::IsErrorRspInfo(const CThostFtdcRspInfoField* const pRspInfo) const
{
    // 如果0 != ErrorID, 说明收到了错误的响应
    bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
    if (bResult)
        cout << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
    return bResult;
}

bool CTraderSpi::IsMyOrder(CThostFtdcOrderField *pOrder)
{
    return ((pOrder->FrontID == FRONT_ID) &&
            (pOrder->SessionID == SESSION_ID) &&
            (strcmp(pOrder->OrderRef, ORDER_REF) == 0));
}

bool CTraderSpi::IsTradingOrder(CThostFtdcOrderField *pOrder)
{
    return ((pOrder->OrderStatus != THOST_FTDC_OST_PartTradedNotQueueing) &&
            (pOrder->OrderStatus != THOST_FTDC_OST_Canceled) &&
            (pOrder->OrderStatus != THOST_FTDC_OST_AllTraded));
}

void CTraderSpi::ShowRspUserLoginField(const CThostFtdcRspUserLoginField* const pRspUserLogin) const
{
	cout << "--->>> " << __FUNCTION__ << endl;
    if (NULL != pRspUserLogin)
    {
        std::cout << "--->>> date: " << pRspUserLogin->TradingDay << std::endl;
        std::cout << "--->>> login time: " << pRspUserLogin->LoginTime << std::endl;
        std::cout << "--->>> broker: " << pRspUserLogin->BrokerID << std::endl;
        std::cout << "--->>> user: " << pRspUserLogin->UserID << std::endl;
        std::cout << "--->>> system name: " << pRspUserLogin->SystemName << std::endl;
    }
    else
    {
        std::cout << "--->>> date: " << pRspUserLogin->TradingDay << std::endl;
        std::cout << "--->>> login time: " << pRspUserLogin->LoginTime << std::endl;
        std::cout << "--->>> broker: " << pRspUserLogin->BrokerID << std::endl;
        std::cout << "--->>> user: " << pRspUserLogin->UserID << std::endl;
        std::cout << "--->>> system name: " << pRspUserLogin->SystemName << std::endl;
    }
    return;
}
// 请求查询报单
void CTraderSpi::ReqQryOrder()
{
    cout << "--->>> " << __FUNCTION__ << endl;
    CThostFtdcQryOrderField req;
    memset(&req, 0, sizeof(req));
    int iResult = pUserApi->ReqQryOrder(&req, 2222);
    cout << "--->>> iRequestID=: " << iRequestID << endl;
    cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> 发送查询请求: " << ((iResult == 0) ? "成功" : "失败") << endl;
}

// 请求查询报单响应
void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    static unsigned int n = 0;
    cout << "--->>> " << __FUNCTION__ << " " << n++ << " times" << endl;
    if (!IsErrorRspInfo(pRspInfo))
    {
        MySleep(1);
        cout << "--->>> " << nRequestID << " " << pOrder->BrokerID << " " << pOrder->InvestorID
            << " " << pOrder->InstrumentID << endl;
    }
}
