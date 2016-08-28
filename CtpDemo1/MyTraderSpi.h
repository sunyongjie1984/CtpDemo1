#pragma once
#include "ThostFtdcTraderApi.h"


class CTraderSpi : public CThostFtdcTraderSpi
{
public:
    // ���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
    virtual void OnFrontConnected();
    virtual void OnFrontDisconnected(int);
    // ��¼������Ӧ
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField*, CThostFtdcRspInfoField*, int, bool);

private:
    // �û���¼����
    void ReqUserLogin();
    // �Ƿ��յ��ɹ�����Ӧ
    bool IsErrorRspInfo(const CThostFtdcRspInfoField* const pRspInfo) const;
    void ShowRspUserLoginField(const CThostFtdcRspUserLoginField* const) const;
};
