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

// USER_API����
extern CThostFtdcTraderApi* pUserApi;

// ���ò���
extern char FRONT_ADDR[];                 // ǰ�õ�ַ
extern char BROKER_ID[];                  // ���͹�˾����
extern char INVESTOR_ID[];                // Ͷ���ߴ���
extern char PASSWORD[];                   // �û�����
extern char INSTRUMENT_ID[];              // ��Լ����
extern TThostFtdcPriceType LIMIT_PRICE;   // �۸�
extern TThostFtdcDirectionType DIRECTION; // ��������

// ������
extern int iRequestID;
// Events
extern CEvent RspSettlementEvent;
extern CEvent RspQryTradingEvent;
extern CEvent RspQryPositionEvent;

// �Ự����
TThostFtdcFrontIDType FRONT_ID;     // ǰ�ñ��
TThostFtdcSessionIDType SESSION_ID; // �Ự���
TThostFtdcOrderRefType ORDER_REF;   // ��������

extern void MySleep(const int n);

void CTraderSpi::OnFrontConnected()
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    ///�û���¼����
    ReqUserLogin();
}

// �����¼
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
        // ����Ự����
        FRONT_ID = pRspUserLogin->FrontID;
        SESSION_ID = pRspUserLogin->SessionID;
        int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
        iNextOrderRef++;
        sprintf(ORDER_REF, "%d", iNextOrderRef);
        ShowRspUserLoginField(pRspUserLogin);
        DEBUG(CTPDEMO1_DEBUG, "FrontID=: %d", FRONT_ID);
        DEBUG(CTPDEMO1_DEBUG, "SESSION_ID=: %d", SESSION_ID);
        DEBUG(CTPDEMO1_DEBUG, "MaxOrderRef=: %s", atoi(pRspUserLogin->MaxOrderRef));
        // ��ȡ��ǰ������
        DEBUG(CTPDEMO1_DEBUG, "TradingDay=: %s", pUserApi->GetTradingDay());
        // Ͷ���߽�����ȷ��
        // ReqSettlementInfoConfirm();
    }
    return;
}

// Ͷ���߽�����ȷ��
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

// �����ѯ��Լ
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

// �����ѯ�ʽ��˻�
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
        DEBUG(CTPDEMO1_DEBUG, "���͹�˾����BrokerID: %s Ͷ�����ʺ�AccountID: %s �ϴ���Ѻ���PreMortgage: %lf �ϴ����ö��PreCredit: %lf �ϴδ���PreDeposit: %lf �ϴν���׼����PreBalance: %lf �ϴ�ռ�õı�֤��PreMargin: %lf ��Ϣ����InterestBase: %lf ��Ϣ����Interest: %lf �����Deposit: %lf ������Withdraw: %lf ����ı�֤��FrozenMargin: %lf ������ʽ�FrozenCash: %lf �����������FrozenCommission: %lf  ��ǰ��֤���ܶ�CurrMargin: %lf �ʽ���CashIn %lf ������Commission: %lf ƽ��ӯ��CloseProfit: %lf �ֲ�ӯ��PositionProfit: %lf �ڻ�����׼����Balance: %lf �����ʽ�Available: %lf ��ȡ�ʽ�WithdrawQuota: %lf ����׼����Reserve: %lf ������TradingDay: %s ������SettlementID: %d ���ö��Credit: %lf ��Ѻ���Mortgage: %lf ��������֤��ExchangeMargin: %lf Ͷ���߽��֤��DeliveryMargin: %lf ���������֤��ExchangeDeliveryMargin: %lf �����ڻ�����׼����ReserveBalance: %lf ���ִ���CurrencyID: %s �ϴλ���������PreFundMortgageIn: %lf �ϴλ����ʳ����PreFundMortgageOut: %lf ����������FundMortgageIn: %lf �����ʳ����FundMortgageOut: %lf ������Ѻ���FundMortgageAvailable: %lf ����Ѻ���ҽ��MortgageableFund: %lf �����Ʒռ�ñ�֤��SpecProductMargin: %lf �����Ʒ���ᱣ֤��SpecProductFrozenMargin: %lf �����Ʒ������SpecProductCommission: %lf �����Ʒ����������SpecProductFrozenCommission: %lf �����Ʒ�ֲ�ӯ��SpecProductPositionProfit: %lf �����Ʒƽ��ӯ��SpecProductCloseProfit: %lf ���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ��SpecProductPositionProfitByAlg: %lf �����Ʒ��������֤��SpecProductExchangeMargin: %lf",
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

// �����ѯͶ���ֲ߳�
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
        DEBUG(CTPDEMO1_DEBUG, "%s ,�ֲֶ�շ���PosiDirection %c, Ͷ���ױ���־HedgeFlag %c, �ֲ�����PositionDate %c, ���ճֲ�YdPosition %d, ���ճֲ�Position %d, ��ͷ����LongFrozen %d, ��ͷ����ShortFrozen %d, ���ֶ�����LongFrozenAmount %lf, ���ֶ�����ShortFrozenAmount %lf, ������OpenVolume %d, ƽ����CloseVolume %d, ���ֽ��OpenAmount %lf, ƽ�ֽ��CloseAmount %lf, �ֲֳɱ�PositionCost %lf, �ϴ�ռ�õı�֤��PreMargin %lf, ռ�õı�֤��UseMargin %lf, ����ı�֤��FrozenMargin %lf, ������ʽ�FrozenCash %lf, �����������FrozenCommission %lf, �ʽ���CashIn %lf, ������Commission %lf, ƽ��ӯ��CloseProfit %lf, �ֲ�ӯ��PositionProfit %lf, �ϴν����PreSettlementPrice %lf, ���ν����SettlementPrice %lf, ������TradingDay %s, ������SettlementID %d, ���ֳɱ�OpenCost %lf, ��������֤��ExchangeMargin %lf, ��ϳɽ��γɵĳֲ�CombPosition %d, ��϶�ͷ����CombLongFrozen %d, ��Ͽ�ͷ����CombShortFrozen %d, ���ն���ƽ��ӯ��CloseProfitByDate %lf, ��ʶԳ�ƽ��ӯ��CloseProfitByTrade %lf, ���ճֲ�TodayPosition: %d, ��֤����MarginRateByMoney %lf, ��֤����(������)MarginRateByVolume %lf, ִ�ж���StrikeFrozen %d, ִ�ж�����StrikeFrozenAmount %lf, ����ִ�ж���AbandonFrozen %d",
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

// ����¼������
int CTraderSpi::ReqOrderInsert(const CThostFtdcInputOrderField* pOrder)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    return 0;
}

// ����¼������
int CTraderSpi::ReqOrderInsert(const char* const pInstrument_ID, const TThostFtdcDirectionType direction, const TThostFtdcOffsetFlagType flag, const double price, const int amount)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    CThostFtdcInputOrderField req;
    memset(&req, 0, sizeof(req));
    // ���͹�˾����
    strcpy(req.BrokerID, BROKER_ID);
    // Ͷ���ߴ���
    strcpy(req.InvestorID, INVESTOR_ID);
    // ��Լ����
    strcpy(req.InstrumentID, pInstrument_ID);
    // ��������
    strcpy(req.OrderRef, ORDER_REF);
    // �û�����
    //  TThostFtdcUserIDType    UserID;
    // �����۸�����: �޼�
    req.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
    // ��������:
    req.Direction = direction;
    // ��Ͽ�ƽ��־: ����
    req.CombOffsetFlag[0] = flag;
    // ���Ͷ���ױ���־
    req.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
    // �۸�
    req.LimitPrice = price;
    // ����: 1
    req.VolumeTotalOriginal = amount;
    // ��Ч������: ������Ч
    req.TimeCondition = THOST_FTDC_TC_GFD;
    // GTD����
    // TThostFtdcDateType  GTDDate;
    // �ɽ�������: �κ�����
    req.VolumeCondition = THOST_FTDC_VC_AV;
    // ��С�ɽ���: 1
    req.MinVolume = 1;
    // ��������: ����
    req.ContingentCondition = THOST_FTDC_CC_Immediately;
    // ֹ���
    // TThostFtdcPriceType StopPrice;
    // ǿƽԭ��: ��ǿƽ
    req.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
    // �Զ������־: ��
    req.IsAutoSuspend = 0;
    // ҵ��Ԫ
    // TThostFtdcBusinessUnitType  BusinessUnit;
    // ������
    // TThostFtdcRequestIDType RequestID;
    // �û�ǿ����־: ��
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

// ������������
void CTraderSpi::ReqOrderAction(CThostFtdcOrderField *pOrder)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    static bool ORDER_ACTION_SENT = false;      //�Ƿ����˱���
    if (ORDER_ACTION_SENT)
        return;

    CThostFtdcInputOrderActionField req;
    memset(&req, 0, sizeof(req));
    // ���͹�˾����
    strcpy(req.BrokerID, pOrder->BrokerID);
    // Ͷ���ߴ���
    strcpy(req.InvestorID, pOrder->InvestorID);
    // ������������
    // TThostFtdcOrderActionRefType    OrderActionRef;
    // ��������
    strcpy(req.OrderRef, pOrder->OrderRef);
    // ������
    // TThostFtdcRequestIDType RequestID;
    // ǰ�ñ��
    req.FrontID = FRONT_ID;
    // �Ự���
    req.SessionID = SESSION_ID;
    // ����������
    // TThostFtdcExchangeIDType    ExchangeID;
    // �������
    // TThostFtdcOrderSysIDType    OrderSysID;
    // ������־
    req.ActionFlag = THOST_FTDC_AF_Delete;
    // �۸�
    //  TThostFtdcPriceType LimitPrice;
    // �����仯
    // TThostFtdcVolumeType    VolumeChange;
    // �û�����
    // TThostFtdcUserIDType    UserID;
    // ��Լ����
    strcpy(req.InstrumentID, pOrder->InstrumentID);

    int iResult = pUserApi->ReqOrderAction(&req, ++iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iRequestID =: %d", iRequestID);
    DEBUG(CTPDEMO1_DEBUG, "iResult =: %d", iResult);
    ORDER_ACTION_SENT = true;
}

// ������������--����
void CTraderSpi::ReqOrderActionAFDelete(CThostFtdcOrderField *pOrder)
{
    DEBUG(CTPDEMO1_DEBUG, "Enter Function %s", __FUNCTION__);
    static bool ORDER_ACTION_SENT = false;      //�Ƿ����˱���
    if (ORDER_ACTION_SENT)
        return;

    CThostFtdcInputOrderActionField req;
    memset(&req, 0, sizeof(req));
    // ���͹�˾����
    strcpy(req.BrokerID, pOrder->BrokerID);
    // Ͷ���ߴ���
    strcpy(req.InvestorID, pOrder->InvestorID);
    // ������������
    // TThostFtdcOrderActionRefType    OrderActionRef;
    // ��������
    strcpy(req.OrderRef, pOrder->OrderRef);
    // ������
    // TThostFtdcRequestIDType RequestID;
    // ǰ�ñ��
    req.FrontID = pOrder->FrontID;
    // �Ự���
    req.SessionID = pOrder->SessionID;
    // ����������
    // TThostFtdcExchangeIDType    ExchangeID;
    // �������
    // TThostFtdcOrderSysIDType    OrderSysID;
    // ������־
    req.ActionFlag = THOST_FTDC_AF_Delete;
    // �۸�
    //  TThostFtdcPriceType LimitPrice;
    // �����仯
    // TThostFtdcVolumeType    VolumeChange;
    // �û�����
    // TThostFtdcUserIDType    UserID;
    // ��Լ����
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

// ����֪ͨ
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
            cout << "--->>> �����ɹ�" << endl;
            */
    }
    else
    {
        cout << "--->>>\tnot my order" << endl;
    }
}

// �ɽ�֪ͨ
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
    // ���0 != ErrorID, ˵���յ��˴������Ӧ
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

// �����ѯ����
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

// �����ѯ������Ӧ
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
