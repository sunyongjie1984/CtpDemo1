#pragma once
#include <iostream>
#include "ThostFtdcTraderApi.h"

using std::cerr;
using std::endl;
using std::cout;

class CTraderSpi : public CThostFtdcTraderSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();

private:
	///�û���¼����
	void ReqUserLogin();
};