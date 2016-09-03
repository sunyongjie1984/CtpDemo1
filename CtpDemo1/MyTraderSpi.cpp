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

// �Ự����
TThostFtdcFrontIDType FRONT_ID;     // ǰ�ñ��
TThostFtdcSessionIDType SESSION_ID; // �Ự���
TThostFtdcOrderRefType ORDER_REF;   // ��������

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
    ///�û���¼����
    ReqUserLogin();
}

// �����¼
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
    cout << "--->>> �����û���¼����: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        // ����Ự����
        FRONT_ID = pRspUserLogin->FrontID;
        SESSION_ID = pRspUserLogin->SessionID;
        int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
        iNextOrderRef++;
        sprintf(ORDER_REF, "%d", iNextOrderRef);
		cout << "--->>> FrontID = " << FRONT_ID << endl;
		cout << "--->>> SESSION_ID = " << SESSION_ID << endl;
		cout << "--->>> MaxOrderRef = " << pRspUserLogin->MaxOrderRef << endl;
		// ��ȡ��ǰ������
        cout << "--->>> ��ȡ��ǰ������ = " << pUserApi->GetTradingDay() << endl;
        MySleep(1);
        // Ͷ���߽�����ȷ��
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

// Ͷ���߽�����ȷ��
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
    cout << "--->>> ����Ͷ���߽�����ȷ��: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        MySleep(1);
        // �����ѯ��Լ
        ReqQryInstrument();
    }
}

// �����ѯ��Լ
void CTraderSpi::ReqQryInstrument()
{
	cout << "--->>> " << __FUNCTION__ << endl;
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
	cout << "--->>> " << __FUNCTION__ << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
		cout << "--->>> InstrumentID=: " << pInstrument->InstrumentID << endl;
		cout << "--->>> InstrumentName=: " << pInstrument->InstrumentName << endl;
		MySleep(1);
        // �����ѯ�ʽ��˻�
        ReqQryTradingAccount();
    }
}

// �����ѯ�ʽ��˻�
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
    cout << "--->>> ���������ѯ�ʽ��˻�: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        MySleep(1);
        // �����ѯͶ���ֲ߳�
        ReqQryInvestorPosition();
    }
}

// �����ѯͶ���ֲ߳�
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
    cout << "--->>> ���������ѯͶ���ֲ߳�: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "--->>> " << __FUNCTION__ << endl;
	if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        MySleep(1);
        // ����¼������
        ReqOrderInsert();
    }
}

// ����¼������
void CTraderSpi::ReqOrderInsert()
{
    cout << "--->>> " << __FUNCTION__ << endl;
    CThostFtdcInputOrderField req;
    memset(&req, 0, sizeof(req));
    // ���͹�˾����
    strcpy(req.BrokerID, BROKER_ID);
    // Ͷ���ߴ���
    strcpy(req.InvestorID, INVESTOR_ID);
    // ��Լ����
    strcpy(req.InstrumentID, INSTRUMENT_ID);
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
    req.LimitPrice = LIMIT_PRICE;
    // ����: 1
    req.VolumeTotalOriginal = 1;
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
	cout << "--->>> " << __FUNCTION__ << endl;
	IsErrorRspInfo(pRspInfo);
}

// ������������
void CTraderSpi::ReqOrderAction(CThostFtdcOrderField *pOrder)
{
	cout << "--->>> " << __FUNCTION__ << endl;
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

void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    IsErrorRspInfo(pRspInfo);
    ReqQryOrder();
}

// ����֪ͨ
void CTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (IsMyOrder(pOrder))
    {
        cout << "--->>> is my order" << endl;
        if (IsTradingOrder(pOrder))
            ReqOrderAction(pOrder);
        else if (pOrder->OrderStatus == THOST_FTDC_OST_Canceled)
            cout << "--->>> �����ɹ�" << endl;
    }
    else
    {
        cout << "--->>> not my order" << __FUNCTION__ << endl;
    }
}

// �ɽ�֪ͨ
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
// �����ѯ����
void CTraderSpi::ReqQryOrder()
{
    cout << "--->>> " << __FUNCTION__ << endl;
    CThostFtdcQryOrderField req;
    memset(&req, 0, sizeof(req));
    int iResult = pUserApi->ReqQryOrder(&req, 2222);
    cout << "--->>> iRequestID=: " << iRequestID << endl;
    cout << "--->>> iResult =: " << iResult << endl;
    cout << "--->>> ���Ͳ�ѯ����: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

// �����ѯ������Ӧ
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
