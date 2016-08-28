#pragma once
#include "ThostFtdcTraderApi.h"


class CTraderSpi : public CThostFtdcTraderSpi
{
public:
    // ���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
    virtual void OnFrontConnected();
    // ��¼������Ӧ
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField*, CThostFtdcRspInfoField*, int, bool);

private:
    // �û���¼����
    void ReqUserLogin();
    void ShowRspUserLoginField(const CThostFtdcRspUserLoginField* const) const;
};
