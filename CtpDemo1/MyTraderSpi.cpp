#include <iostream>
#include "MyTraderSpi.h"

#ifdef _linux
#include <string.h>
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

void CTraderSpi::OnFrontConnected()
{
    cout << "--->>> " << "OnFrontConnected" << endl;
    ///�û���¼����
    ReqUserLogin();
}
void CTraderSpi::OnFrontDisconnected(int nReason)
{
    cerr << "--->>> " << "OnFrontDisconnected" << endl;
    cerr << "--->>> Reason = " << nReason << endl;
}

void CTraderSpi::ReqUserLogin()
{
    CThostFtdcReqUserLoginField req;
    memset(&req, 0, sizeof(req));
    strcpy(req.BrokerID, BROKER_ID);
    strcpy(req.UserID, INVESTOR_ID);
    strcpy(req.Password, PASSWORD);
    int iResult = pUserApi->ReqUserLogin(&req, ++iRequestID);
    cerr << "--->>> �����û���¼����: " << ((iResult == 0) ? "�ɹ�" : "ʧ��") << endl;
}

bool CTraderSpi::IsErrorRspInfo(const CThostFtdcRspInfoField* const pRspInfo) const
{
    // ���0 != ErrorID, ˵���յ��˴������Ӧ
    bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
    if (bResult)
        cerr << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
    return bResult;
}

void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cerr << "--->>> " << "OnRspUserLogin" << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo))
    {
        // ����Ự����
        FRONT_ID = pRspUserLogin->FrontID;
        SESSION_ID = pRspUserLogin->SessionID;
        int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
        iNextOrderRef++;
        sprintf(ORDER_REF, "%d", iNextOrderRef);
        // ��ȡ��ǰ������
        cerr << "--->>> ��ȡ��ǰ������ = " << pUserApi->GetTradingDay() << endl;
        // Ͷ���߽�����ȷ��
        // ReqSettlementInfoConfirm();
    }
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
            std::cout << "Error !!! pRspUserLogin is nullptr" << std::endl;
        }
    }
    else
    {
            std::cout << "Error !!! pRspInfo is nullptr" << std::endl;
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
    return;
}
