///实现交易撮合主机的程序框架
/**
 *源程序名称: ts_app.cpp
 *系统名称: NEEQ1.0 交易撮合主机
 *模块名称: 主框架
 *功能说明: 该源文件实现主应用框架
 *作   者: shoujj
 *版   权: neeq
 *开发日期: 20130803
 *修改记录：
 *20140201  *****
 */
#include <iostream>

//#include <core/qs/qsqm_api.h>

#include "ts_app.h"
#include "event_id.h"
//#include "ts_init.h"

///定义主框架
static CTS_APP g_TS_APP;
CTS_APP* pApp = &g_TS_APP;

//重载基类的init函数 完成交易撮合主机的初始化操作
int32_t CTS_APP::init(int32_t argc, char** argv)
{
    NOTICE(TS_INFO_START, "TS start");
    NOTICE(TS_NOTICE_STATRTINIT, "TS init start");
    NOTICE(TS_NOTICE_FINISHINIT, "TSinit finished");
    return 0;
}

//重载基类的fini函数，用于结束撮合主机
int32_t CTS_APP::fini()
{
    NOTICE(TS_INFO_BEGIN_STOP, "TS start stoping");
    //停止组播接收
    INFO(TS_INFO_BEGIN_STOPMULTICASTRECV, "TS stop multi cast receiver");
    return 0;
}

//重载基类函数 用于指定版本号
const char* CTS_APP::version() const
{
    return APP_VERSION;
}

