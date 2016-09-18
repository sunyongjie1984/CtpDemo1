#pragma once
#include "ThostFtdcTraderApi.h"


class CTraderSpi : public CThostFtdcTraderSpi
{
public:
    // ���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
    virtual void OnFrontConnected();
    // ��¼������Ӧ
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField*, CThostFtdcRspInfoField*, int, bool);
    // Ͷ���߽�����ȷ����Ӧ
    virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
    // �����ѯ��Լ��Ӧ
    virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    // �����ѯ�ʽ��˻���Ӧ
    virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    // When the investor has no position, the pointer
    // pInvestorPosition will be nullptr, opps! be careful
    // �����ѯͶ���ֲ߳���Ӧ
    virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    // ����¼��������Ӧ
    virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    // ��������������Ӧ
    virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    // ����Ӧ��
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    // ���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
    virtual void OnFrontDisconnected(int);
    // ������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
    virtual void OnHeartBeatWarning(int nTimeLapse);

    ///����֪ͨ
    virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);

    ///�ɽ�֪ͨ
    virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);

    // �����ѯ������Ӧ
    // do ReqOrderInsert before ReqQryOrder
    // or the following function pOrder or pRspInfo will be 0 when recall
    virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    ///�����ѯ����
    void ReqQryOrder();
    // ����¼������
    int ReqOrderInsert(const CThostFtdcInputOrderField* pOrder);
    // ����¼������
    int ReqOrderInsert(const char* const pInstrument_ID, const TThostFtdcDirectionType direction, const TThostFtdcOffsetFlagType flag, const double price, const int amount);
    // ������������
    void ReqOrderAction(CThostFtdcOrderField *pOrder);
    // ������������--����
    void ReqOrderActionAFDelete(CThostFtdcOrderField *pOrder);
    // �����ѯ�ʽ��˻�
    int ReqQryTradingAccount();
    // Ͷ���߽�����ȷ��
    void ReqSettlementInfoConfirm();
    // �����ѯ��Լ
    void ReqQryInstrument();
    // �����ѯͶ���ֲ߳�
    int ReqQryInvestorPosition();

    void ShowRspUserLoginField(const CThostFtdcRspUserLoginField* const) const;
private:
    // �û���¼����
    void ReqUserLogin();

    // �Ƿ��յ��ɹ�����Ӧ
    bool IsErrorRspInfo(const CThostFtdcRspInfoField* const pRspInfo) const;
    // �Ƿ��ҵı����ر�
    bool IsMyOrder(CThostFtdcOrderField *pOrder);
    // �Ƿ����ڽ��׵ı���
    bool IsTradingOrder(CThostFtdcOrderField *pOrder);
};
