#include <iostream>
#include "MyTraderSpi.h"

#ifdef _linux
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "event.h"
#include "event_id.h"
#include "CtpDemo1.h"
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
// Events
extern CEvent RspSettlementEvent;
extern CEvent RspQryTradingEvent;
extern CEvent RspQryPositionEvent;

// 会话参数
TThostFtdcFrontIDType FRONT_ID;     // 前置编号
TThostFtdcSessionIDType SESSION_ID; // 会话编号
TThostFtdcOrderRefType ORDER_REF;   // 报单引用

extern void MySleep(const int n);

void CTraderSpi::OnFrontConnected()
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    ///用户登录请求
    ReqUserLogin();
}

// 请求登录
void CTraderSpi::ReqUserLogin()
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    CThostFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.UserID, INVESTOR_ID);
    strcpy(req.Password, PASSWORD);
    int iResult = pUserApi->ReqUserLogin(&req, ++iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iRequestID =: %d", iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iResult =: %d", iResult);
}

void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    DEBUG(CTPDEMO1_DEBUG, "OnRsp iRequestID=: %d", iRequestID);
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        // 保存会话参数
        FRONT_ID = pRspUserLogin->FrontID;
        SESSION_ID = pRspUserLogin->SessionID;
        int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
        iNextOrderRef++;
        sprintf(ORDER_REF, "%d", iNextOrderRef);
        ShowRspUserLoginField(pRspUserLogin);
        DEBUG(CTPDEMO1_DEBUG, "FrontID=: %d", FRONT_ID);
        DEBUG(CTPDEMO1_DEBUG, "SESSION_ID=: %d", SESSION_ID);
        DEBUG(CTPDEMO1_DEBUG, "MaxOrderRef=: %s", atoi(pRspUserLogin->MaxOrderRef));
        // 获取当前交易日
        DEBUG(CTPDEMO1_DEBUG, "TradingDay=: %s", pUserApi->GetTradingDay());
        // 投资者结算结果确认
        // ReqSettlementInfoConfirm();
    }
    return;
}

// 投资者结算结果确认
void CTraderSpi::ReqSettlementInfoConfirm()
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    CThostFtdcSettlementInfoConfirmField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    int iResult = pUserApi->ReqSettlementInfoConfirm(&req, ++iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iRequestID =: %d", iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iResult =: %d", iResult);
}

void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    DEBUG(CTPDEMO1_DEBUG, "OnRsp iRequestID=: %d", iRequestID);
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        // RspSettlementEvent.Set();
    }
}

// 请求查询合约
void CTraderSpi::ReqQryInstrument()
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    CThostFtdcQryInstrumentField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.InstrumentID, INSTRUMENT_ID);
    int iResult = pUserApi->ReqQryInstrument(&req, ++iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iRequestID =: %d", iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iResult =: %d", iResult);
}

void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    DEBUG(CTPDEMO1_DEBUG, "OnRsp iRequestID=: %d", iRequestID);
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        cout << "--->>> InstrumentID=: " << pInstrument->InstrumentID << endl;
        cout << "--->>> InstrumentName=: " << pInstrument->InstrumentName << endl;
        MySleep(1);
    }
}

// 请求查询资金账户
int CTraderSpi::ReqQryTradingAccount()
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    CThostFtdcQryTradingAccountField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    int iResult = pUserApi->ReqQryTradingAccount(&req, ++iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iRequestID =: %d", iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iResult =: %d", iRequestID);
    return iResult;
}

void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    DEBUG(CTPDEMO1_DEBUG, "OnRsp iRequestID=: %d", iRequestID);
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        DEBUG(CTPDEMO1_DEBUG, "经纪公司代码BrokerID: %s 投资者帐号AccountID: %s 上次质押金额PreMortgage: %lf 上次信用额度PreCredit: %lf 上次存款额PreDeposit: %lf 上次结算准备金PreBalance: %lf 上次占用的保证金PreMargin: %lf 利息基数InterestBase: %lf 利息收入Interest: %lf 入金金额Deposit: %lf 出金金额Withdraw: %lf 冻结的保证金FrozenMargin: %lf 冻结的资金FrozenCash: %lf 冻结的手续费FrozenCommission: %lf  当前保证金总额CurrMargin: %lf 资金差额CashIn %lf 手续费Commission: %lf 平仓盈亏CloseProfit: %lf 持仓盈亏PositionProfit: %lf 期货结算准备金Balance: %lf 可用资金Available: %lf 可取资金WithdrawQuota: %lf 基本准备金Reserve: %lf 交易日TradingDay: %s 结算编号SettlementID: %d 信用额度Credit: %lf 质押金额Mortgage: %lf 交易所保证金ExchangeMargin: %lf 投资者交割保证金DeliveryMargin: %lf 交易所交割保证金ExchangeDeliveryMargin: %lf 保底期货结算准备金ReserveBalance: %lf 币种代码CurrencyID: %s 上次货币质入金额PreFundMortgageIn: %lf 上次货币质出金额PreFundMortgageOut: %lf 货币质入金额FundMortgageIn: %lf 货币质出金额FundMortgageOut: %lf 货币质押余额FundMortgageAvailable: %lf 可质押货币金额MortgageableFund: %lf 特殊产品占用保证金SpecProductMargin: %lf 特殊产品冻结保证金SpecProductFrozenMargin: %lf 特殊产品手续费SpecProductCommission: %lf 特殊产品冻结手续费SpecProductFrozenCommission: %lf 特殊产品持仓盈亏SpecProductPositionProfit: %lf 特殊产品平仓盈亏SpecProductCloseProfit: %lf 根据持仓盈亏算法计算的特殊产品持仓盈亏SpecProductPositionProfitByAlg: %lf 特殊产品交易所保证金SpecProductExchangeMargin: %lf",
        pTradingAccount->BrokerID,
        pTradingAccount->AccountID,
        pTradingAccount->PreMortgage,
        pTradingAccount->PreCredit,
        pTradingAccount->PreDeposit,
        pTradingAccount->PreBalance,
        pTradingAccount->PreMargin,
        pTradingAccount->InterestBase,
        pTradingAccount->Interest,
        pTradingAccount->Deposit,
        pTradingAccount->Withdraw,
        pTradingAccount->FrozenMargin,
        pTradingAccount->FrozenCash,
        pTradingAccount->FrozenCommission,
        pTradingAccount->CurrMargin,
        pTradingAccount->CashIn,
        pTradingAccount->Commission,
        pTradingAccount->CloseProfit,
        pTradingAccount->PositionProfit,
        pTradingAccount->Balance,
        pTradingAccount->Available,
        pTradingAccount->WithdrawQuota,
        pTradingAccount->Reserve,
        pTradingAccount->TradingDay,
        pTradingAccount->SettlementID,
        pTradingAccount->Credit,
        pTradingAccount->Mortgage,
        pTradingAccount->ExchangeMargin,
        pTradingAccount->DeliveryMargin,
        pTradingAccount->ExchangeDeliveryMargin,
        pTradingAccount->ReserveBalance,
        pTradingAccount->CurrencyID,
        pTradingAccount->PreFundMortgageIn,
        pTradingAccount->PreFundMortgageOut,
        pTradingAccount->FundMortgageIn,
        pTradingAccount->FundMortgageOut,
        pTradingAccount->FundMortgageAvailable,
        pTradingAccount->MortgageableFund,
        pTradingAccount->SpecProductMargin,
        pTradingAccount->SpecProductFrozenMargin,
        pTradingAccount->SpecProductCommission,
        pTradingAccount->SpecProductFrozenCommission,
        pTradingAccount->SpecProductPositionProfit,
        pTradingAccount->SpecProductCloseProfit,
        pTradingAccount->SpecProductPositionProfitByAlg,
        pTradingAccount->SpecProductExchangeMargin);
    }
    // RspQryTradingEvent.Set();
}

// 请求查询投资者持仓
int CTraderSpi::ReqQryInvestorPosition()
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    CThostFtdcQryInvestorPositionField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    // strcpy(req.InstrumentID, INSTRUMENT_ID);
    int iResult = pUserApi->ReqQryInvestorPosition(&req, ++iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iRequestID =: %d", iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iResult =: %d", iRequestID);
    return iResult;
}

void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    DEBUG(CTPDEMO1_DEBUG, "OnRsp iRequestID=: %d", iRequestID);
    if (NULL == pInvestorPosition)
    {
        DEBUG(CTPDEMO1_DEBUG, "NULL == pInvestorPositiond, no position");
        return;
    }
    // if (bIsLast && !IsErrorRspInfo(pRspInfo))
    if (!IsErrorRspInfo(pRspInfo))
    {
        DEBUG(CTPDEMO1_DEBUG, "%s ,持仓多空方向PosiDirection %c, 投机套保标志HedgeFlag %c, 持仓日期PositionDate %c, 上日持仓YdPosition %d, 今日持仓Position %d, 多头冻结LongFrozen %d, 空头冻结ShortFrozen %d, 开仓冻结金额LongFrozenAmount %lf, 开仓冻结金额ShortFrozenAmount %lf, 开仓量OpenVolume %d, 平仓量CloseVolume %d, 开仓金额OpenAmount %lf, 平仓金额CloseAmount %lf, 持仓成本PositionCost %lf, 上次占用的保证金PreMargin %lf, 占用的保证金UseMargin %lf, 冻结的保证金FrozenMargin %lf, 冻结的资金FrozenCash %lf, 冻结的手续费FrozenCommission %lf, 资金差额CashIn %lf, 手续费Commission %lf, 平仓盈亏CloseProfit %lf, 持仓盈亏PositionProfit %lf, 上次结算价PreSettlementPrice %lf, 本次结算价SettlementPrice %lf, 交易日TradingDay %s, 结算编号SettlementID %d, 开仓成本OpenCost %lf, 交易所保证金ExchangeMargin %lf, 组合成交形成的持仓CombPosition %d, 组合多头冻结CombLongFrozen %d, 组合空头冻结CombShortFrozen %d, 逐日盯市平仓盈亏CloseProfitByDate %lf, 逐笔对冲平仓盈亏CloseProfitByTrade %lf, 今日持仓TodayPosition: %d, 保证金率MarginRateByMoney %lf, 保证金率(按手数)MarginRateByVolume %lf, 执行冻结StrikeFrozen %d, 执行冻结金额StrikeFrozenAmount %lf, 放弃执行冻结AbandonFrozen %d",
                pInvestorPosition->InstrumentID,
                pInvestorPosition->PosiDirection,
                pInvestorPosition->HedgeFlag,
                pInvestorPosition->PositionDate,
                pInvestorPosition->YdPosition,
                pInvestorPosition->Position,
                pInvestorPosition->LongFrozen,
                pInvestorPosition->ShortFrozen,
                pInvestorPosition->LongFrozenAmount,
                pInvestorPosition->ShortFrozenAmount,
                pInvestorPosition->OpenVolume,
                pInvestorPosition->CloseVolume,
                pInvestorPosition->OpenAmount,
                pInvestorPosition->CloseAmount,
                pInvestorPosition->PositionCost,
                pInvestorPosition->PreMargin,
                pInvestorPosition->UseMargin,
                pInvestorPosition->FrozenMargin,
                pInvestorPosition->FrozenCash,
                pInvestorPosition->FrozenCommission,
                pInvestorPosition->CashIn,
                pInvestorPosition->Commission,
                pInvestorPosition->CloseProfit,
                pInvestorPosition->PositionProfit,
                pInvestorPosition->PreSettlementPrice,
                pInvestorPosition->SettlementPrice,
                pInvestorPosition->TradingDay,
                pInvestorPosition->SettlementID,
                pInvestorPosition->OpenCost,
                pInvestorPosition->ExchangeMargin,
                pInvestorPosition->CombPosition,
                pInvestorPosition->CombLongFrozen,
                pInvestorPosition->CombShortFrozen,
                pInvestorPosition->CloseProfitByDate,
                pInvestorPosition->CloseProfitByTrade,
                pInvestorPosition->TodayPosition,
                pInvestorPosition->MarginRateByMoney,
                pInvestorPosition->MarginRateByVolume,
                pInvestorPosition->StrikeFrozen,
                pInvestorPosition->StrikeFrozenAmount,
                pInvestorPosition->AbandonFrozen);
    }
    // RspQryPositionEvent.Set();
}

// 报单录入请求
int CTraderSpi::ReqOrderInsert(const CThostFtdcInputOrderField* pOrder)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    return 0;
}

// 报单录入请求
int CTraderSpi::ReqOrderInsert(const char* const pInstrument_ID, const TThostFtdcDirectionType direction, const TThostFtdcOffsetFlagType flag, const double price, const int amount)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    CThostFtdcInputOrderField req;
    memset(&req, 0, sizeof(req));
    // 经纪公司代码
    strcpy(req.BrokerID, BROKER_ID);
    // 投资者代码
    strcpy(req.InvestorID, INVESTOR_ID);
    // 合约代码
    strcpy(req.InstrumentID, pInstrument_ID);
    // 报单引用
    strcpy(req.OrderRef, ORDER_REF);
    // 用户代码
    //  TThostFtdcUserIDType    UserID;
    // 报单价格条件: 限价
    req.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
    // 买卖方向:
    req.Direction = direction;
    // 组合开平标志: 开仓
    req.CombOffsetFlag[0] = flag;
    // 组合投机套保标志
    req.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
    // 价格
    req.LimitPrice = price;
    // 数量: 1
    req.VolumeTotalOriginal = amount;
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
    DEBUG(CTPDEMO1_DEBUG, "iRequestID =: %d", iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iResult =: %d", iResult);
    return iResult;
}

void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    DEBUG(CTPDEMO1_DEBUG, "OnRsp iRequestID=: %d", iRequestID);
	IsErrorRspInfo(pRspInfo);
}

// 报单操作请求
void CTraderSpi::ReqOrderAction(CThostFtdcOrderField *pOrder)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
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
    DEBUG(CTPDEMO1_DEBUG, "iRequestID =: %d", iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iResult =: %d", iResult);
    ORDER_ACTION_SENT = true;
}

// 报单操作请求--撤单
void CTraderSpi::ReqOrderActionAFDelete(CThostFtdcOrderField *pOrder)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
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
    req.FrontID = pOrder->FrontID;
    // 会话编号
    req.SessionID = pOrder->SessionID;
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
    DEBUG(CTPDEMO1_DEBUG, "iRequestID =: %d", iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iResult =: %d", iResult);
    ORDER_ACTION_SENT = true;
}

void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    DEBUG(CTPDEMO1_DEBUG, "OnRsp iRequestID=: %d", iRequestID);
    IsErrorRspInfo(pRspInfo);
    // ReqQryOrder();
}

// 报单通知
void CTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    if (IsMyOrder(pOrder))
    {
        cout << "--->>>\tis my order" << endl;
        /*
        if (IsTradingOrder(pOrder))
            ReqOrderAction(pOrder);
        else if (pOrder->OrderStatus == THOST_FTDC_OST_Canceled)
            cout << "--->>> 撤单成功" << endl;
            */
    }
    else
    {
        cout << "--->>>\tnot my order" << endl;
    }
}

// 成交通知
void CTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
}

void CTraderSpi::OnFrontDisconnected(int nReason)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    cout << "--->>> Reason = " << nReason << endl;
}

void CTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    cout << "--->>> nTimerLapse = " << nTimeLapse << endl;
}

void CTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    IsErrorRspInfo(pRspInfo);
}

bool CTraderSpi::IsErrorRspInfo(const CThostFtdcRspInfoField* const pRspInfo) const
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    // 如果0 != ErrorID, 说明收到了错误的响应
    bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
    if (bResult)
        cout << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
    return bResult;
}

bool CTraderSpi::IsMyOrder(CThostFtdcOrderField *pOrder)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    return ((pOrder->FrontID == FRONT_ID) &&
            (pOrder->SessionID == SESSION_ID) &&
            (strcmp(pOrder->OrderRef, ORDER_REF) == 0));
}

bool CTraderSpi::IsTradingOrder(CThostFtdcOrderField *pOrder)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    return ((pOrder->OrderStatus != THOST_FTDC_OST_PartTradedNotQueueing) &&
            (pOrder->OrderStatus != THOST_FTDC_OST_Canceled) &&
            (pOrder->OrderStatus != THOST_FTDC_OST_AllTraded));
}

void CTraderSpi::ShowRspUserLoginField(const CThostFtdcRspUserLoginField* const pRspUserLogin) const
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    if (NULL != pRspUserLogin)
    {
        DEBUG(CTPDEMO1_DEBUG, "date: %s", pRspUserLogin->TradingDay);
        DEBUG(CTPDEMO1_DEBUG, "login time: %s", pRspUserLogin->LoginTime);
        DEBUG(CTPDEMO1_DEBUG, "BrokerID: %s", pRspUserLogin->BrokerID);
        DEBUG(CTPDEMO1_DEBUG, "UserID: %s", pRspUserLogin->UserID);
        DEBUG(CTPDEMO1_DEBUG, "SystemName: %s", pRspUserLogin->SystemName);
    }
    return;
}

// 请求查询报单
void CTraderSpi::ReqQryOrder()
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    CThostFtdcQryOrderField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    int iResult = pUserApi->ReqQryOrder(&req, iRequestID++);
    DEBUG(CTPDEMO1_DEBUG, "iRequestID =: %d", iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iResult =: %d", iResult);
}

// 请求查询报单响应
void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    static unsigned int n = 0;
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s %d times", __FUNCTION__, n);
    DEBUG(CTPDEMO1_DEBUG, "OnRsp iRequestID=: %d", iRequestID);
    if (!IsErrorRspInfo(pRspInfo))
    {
        cout << "--->>>\t" << nRequestID << " " << pOrder->FrontID << " " << pOrder->SessionID << " " << pOrder->BrokerID << " " << pOrder->InvestorID
            << " " << pOrder->InstrumentID << " " << pOrder->OrderRef << " " << pOrder->OrderPriceType
            << " " << pOrder->Direction << " " << pOrder->LimitPrice << " " << pOrder->VolumeTotalOriginal
            << " " << pOrder->RequestID << pOrder->InsertDate << " " << pOrder->InsertTime << " " << pOrder->UpdateTime << " " << pOrder->OrderStatus
            << " " << pOrder->StatusMsg << endl;;
        cout << "--->>> " << pOrder->FrontID << " " << pOrder->SessionID << " " << pOrder->OrderRef
            << " " << pOrder->InstrumentID << endl;
        if (bIsLast == true)
        {
            // ReqOrderActionAFDelete(pOrder);
        }
    }
}
