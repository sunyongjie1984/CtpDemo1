#include <iostream>
#include "MyTraderSpi.h"

#ifdef _linux
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "event.h"
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
extern CEvent RspSettlementEvent;
extern CEvent RspQryTradingEvent;

// �Ự����
TThostFtdcFrontIDType FRONT_ID;     // ǰ�ñ��
TThostFtdcSessionIDType SESSION_ID; // �Ự���
TThostFtdcOrderRefType ORDER_REF;   // ��������

extern void MySleep(const int n);

void CTraderSpi::OnFrontConnected()
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    ///�û���¼����
    ReqUserLogin();
}

// �����¼
void CTraderSpi::ReqUserLogin()
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    CThostFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.UserID, INVESTOR_ID);
    strcpy(req.Password, PASSWORD);
    int iResult = pUserApi->ReqUserLogin(&req, ++iRequestID);
    cout << "--->>>\tiRequestID=: " << iRequestID << endl;
    cout << "--->>>\tiResult =: " << iResult << endl;
    cout << "--->>>\t�����û���¼����: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    cout << "--->>>\tOnRsp iRequestID=: " << iRequestID << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        // ����Ự����
        FRONT_ID = pRspUserLogin->FrontID;
        SESSION_ID = pRspUserLogin->SessionID;
        int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
        iNextOrderRef++;
        sprintf(ORDER_REF, "%d", iNextOrderRef);
        ShowRspUserLoginField(pRspUserLogin);
        cout << "--->>>\tFrontID = " << FRONT_ID << endl;
        cout << "--->>>\tSESSION_ID = " << SESSION_ID << endl;
        cout << "--->>>\tMaxOrderRef = " << pRspUserLogin->MaxOrderRef << endl;
        // ��ȡ��ǰ������
        cout << "--->>>\t��ȡ��ǰ������ = " << pUserApi->GetTradingDay() << endl;
        // Ͷ���߽�����ȷ��
        ReqSettlementInfoConfirm();
    }
    return;
}

// Ͷ���߽�����ȷ��
void CTraderSpi::ReqSettlementInfoConfirm()
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    CThostFtdcSettlementInfoConfirmField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    int iResult = pUserApi->ReqSettlementInfoConfirm(&req, ++iRequestID);
    cout << "--->>>\tiRequestID=: " << iRequestID << endl;
    cout << "--->>>\tiResult =: " << iResult << endl;
    cout << "--->>>\t����Ͷ���߽�����ȷ��: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    cout << "--->>>\tOnRsp iRequestID=: " << iRequestID << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        RspSettlementEvent.Set();
    }
}

// �����ѯ��Լ
void CTraderSpi::ReqQryInstrument()
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    CThostFtdcQryInstrumentField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.InstrumentID, INSTRUMENT_ID);
    int iResult = pUserApi->ReqQryInstrument(&req, ++iRequestID);
    cout << "--->>> iRequestID=: " << iRequestID << endl;
    cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> ���������ѯ��Լ: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> Enter function " << __FUNCTION__ << endl;
    cout << "--->>>\tOnRsp iRequestID=: " << iRequestID << endl;
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
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    CThostFtdcQryTradingAccountField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    int iResult = pUserApi->ReqQryTradingAccount(&req, ++iRequestID);
    cout << "--->>>\tiRequestID=: " << iRequestID << endl;
    cout << "--->>>\tiResult =: " << iResult << endl;
    cout << "--->>>\t���������ѯ�ʽ��˻�: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
    return iResult;
}

void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    cout << "--->>>\tOnRsp iRequestID=: " << iRequestID << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        cout << "--->>>\tAccount=: " << pTradingAccount->AccountID << " Available=: " << pTradingAccount->Available << endl;
    }
    RspQryTradingEvent.Set();
}

// �����ѯͶ���ֲ߳�
int CTraderSpi::ReqQryInvestorPosition()
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    CThostFtdcQryInvestorPositionField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    // strcpy(req.InstrumentID, INSTRUMENT_ID);
    int iResult = pUserApi->ReqQryInvestorPosition(&req, ++iRequestID);
    cout << "--->>>\tiRequestID=: " << iRequestID << endl;
    cout << "--->>>\tiResult =: " << iResult << endl;
    cout << "--->>>\t���������ѯͶ���ֲ߳�: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
    return iResult;
}

void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    cout << "--->>>\tOnRsp iRequestID=: " << iRequestID << endl;
    if (NULL == pInvestorPosition)
    {
        cout << "--->>>\tNULL == pInvestorPosition" << endl;
        cout << "--->>>\tno position" << endl;
        return;
    }
    // if (bIsLast && !IsErrorRspInfo(pRspInfo))
    if (!IsErrorRspInfo(pRspInfo))
    {
        cout << "--->>>\t" << pInvestorPosition->InstrumentID
            << " position direction: "
            << pInvestorPosition->PosiDirection
            << " hedgeFlag: "
            << pInvestorPosition->HedgeFlag
            << " positionDate: "
            << pInvestorPosition->PositionDate
            << " YdPosition: "
            << pInvestorPosition->YdPosition
            << " position: "
            << pInvestorPosition->Position
            << " long frozen: "
            << pInvestorPosition->LongFrozen
            << " short frozen: "
            << pInvestorPosition->ShortFrozen
            << " LongFrozenAmount: "
            << pInvestorPosition->LongFrozenAmount
            << " ShortFrozenAmount: "
            << pInvestorPosition->ShortFrozenAmount
            << " OpenVolume: "
            << pInvestorPosition->OpenVolume
            << " CloseVolume: "
            << pInvestorPosition->CloseVolume
            << " OpenAmount: "
            << pInvestorPosition->OpenAmount
            << " CloseAmount: "
            << pInvestorPosition->CloseAmount
            << " PositionCost: "
            << pInvestorPosition->PositionCost
            << " PreMargin: "
            << pInvestorPosition->PreMargin
            << " UseMargin: "
            << pInvestorPosition->UseMargin
            << " FrozenMargin: "
            << pInvestorPosition->FrozenMargin
            << " FrozenCash: "
            << pInvestorPosition->FrozenCash
            << " FrozenCommission: "
            << pInvestorPosition->FrozenCommission
            << " CashIn: "
            << pInvestorPosition->CashIn
            << " Commission: "
            << pInvestorPosition->Commission
            << " CloseProfit: "
            << pInvestorPosition->CloseProfit
            << " PositionProfit: "
            << pInvestorPosition->PositionProfit
            << " PreSettlementPrice: "
            << pInvestorPosition->PreSettlementPrice
            << " SettlementPrice: "
            << pInvestorPosition->SettlementPrice
            << " TradingDay: "
            << pInvestorPosition->TradingDay
            << " OpenCost: "
            << pInvestorPosition->OpenCost
            << " ExchangeMargin: "
            << pInvestorPosition->ExchangeMargin
            << " CombPosition: "
            << pInvestorPosition->CombPosition
            << " CombLongFrozen: "
            << pInvestorPosition->CombLongFrozen
            << " CombShortFrozen: "
            << pInvestorPosition->CombShortFrozen
            << " CloseProfitByDate: "
            << pInvestorPosition->CloseProfitByDate
            << " CloseProfitByTrade: "
            << pInvestorPosition->CloseProfitByTrade
            << " TodayPosition: "
            << pInvestorPosition->TodayPosition
            << " MarginRateByMoney: "
            << pInvestorPosition->MarginRateByMoney
            << " MarginRateByVolume: "
            << pInvestorPosition->MarginRateByVolume
            << " StrikeFrozen: "
            << pInvestorPosition->StrikeFrozen
            << " StrikeFrozenAmount: "
            << pInvestorPosition->StrikeFrozenAmount
            << " AbandonFrozen: "
            << pInvestorPosition->AbandonFrozen
            << " "
            << endl;
    }
}

// ����¼������
void CTraderSpi::ReqOrderInsert(const char* const pInstrument_ID, const double price, const int amount)
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
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
    req.Direction = DIRECTION;
    // ��Ͽ�ƽ��־: ����
    req.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
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
    cout << "--->>> iRequestID=: " << iRequestID << endl;
	cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> ���ͱ���¼������: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> Enter function " << __FUNCTION__ << endl;
    cout << "--->>>\tOnRsp iRequestID=: " << iRequestID << endl;
	IsErrorRspInfo(pRspInfo);
}

// ������������
void CTraderSpi::ReqOrderAction(CThostFtdcOrderField *pOrder)
{
	cout << "--->>> Enter function " << __FUNCTION__ << endl;
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
    cout << "--->>> iRequestID=: " << iRequestID << endl;
    cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> ���ͱ�����������: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
    ORDER_ACTION_SENT = true;
}

// ������������--����
void CTraderSpi::ReqOrderActionAFDelete(CThostFtdcOrderField *pOrder)
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
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
    cout << "--->>> iRequestID=: " << iRequestID << endl;
    cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> ���ͱ�����������: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
    ORDER_ACTION_SENT = true;
}

void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    cout << "--->>>\tOnRsp iRequestID=: " << iRequestID << endl;
    IsErrorRspInfo(pRspInfo);
    // ReqQryOrder();
}

// ����֪ͨ
void CTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
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
	cout << "--->>> Enter function " << __FUNCTION__ << endl;
}

void CTraderSpi::OnFrontDisconnected(int nReason)
{
	cout << "--->>> Enter function " << __FUNCTION__ << endl;
	cout << "--->>> Reason = " << nReason << endl;
}

void CTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	cout << "--->>> nTimerLapse = " << nTimeLapse << endl;
}

void CTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> Enter function " << __FUNCTION__ << endl;
	IsErrorRspInfo(pRspInfo);
}

bool CTraderSpi::IsErrorRspInfo(const CThostFtdcRspInfoField* const pRspInfo) const
{
    // ���0 != ErrorID, ˵���յ��˴������Ӧ
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
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    if (NULL != pRspUserLogin)
    {
        std::cout << "--->>>\tdate: " << pRspUserLogin->TradingDay << std::endl;
        std::cout << "--->>>\tlogin time: " << pRspUserLogin->LoginTime << std::endl;
        std::cout << "--->>>\tbroker: " << pRspUserLogin->BrokerID << std::endl;
        std::cout << "--->>>\tuser: " << pRspUserLogin->UserID << std::endl;
        std::cout << "--->>>\tsystem name: " << pRspUserLogin->SystemName << std::endl;
    }
    else
    {
        std::cout << "--->>>\tdate: " << pRspUserLogin->TradingDay << std::endl;
        std::cout << "--->>>\tlogin time: " << pRspUserLogin->LoginTime << std::endl;
        std::cout << "--->>>\tbroker: " << pRspUserLogin->BrokerID << std::endl;
        std::cout << "--->>>\tuser: " << pRspUserLogin->UserID << std::endl;
        std::cout << "--->>>\tsystem name: " << pRspUserLogin->SystemName << std::endl;
    }
    return;
}

// �����ѯ����
void CTraderSpi::ReqQryOrder()
{
    cout << "--->>> Enter function " << __FUNCTION__ << endl;
    CThostFtdcQryOrderField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.InvestorID, INVESTOR_ID);
    int iResult = pUserApi->ReqQryOrder(&req, iRequestID++);
    cout << "--->>>\tiRequestID=: " << iRequestID << endl;
    cout << "--->>>\tiResult =: " << iResult << endl;
    cout << "--->>>\t���Ͳ�ѯ����: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

// �����ѯ������Ӧ
void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    static unsigned int n = 0;
    cout << "--->>> Enter function " << __FUNCTION__ << " " << n++ << " times" << endl;
    cout << "--->>>\tOnRsp iRequestID=: " << iRequestID << endl;
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
