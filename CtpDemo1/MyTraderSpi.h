#pragma once
#include <iostream>
#include "ThostFtdcTraderApi.h"

using std::cerr;
using std::endl;
using std::cout;

class CTraderSpi : public CThostFtdcTraderSpi
{
public:
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected();

private:
	///用户登录请求
	void ReqUserLogin();
};