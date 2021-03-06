///定义交易撮合主机的程序框架
/**
 *源程序名称: 
 *系统名称: 
 *模块名称: 主框架
 *功能说明: 该头文件定义主应用框架
 *作   者: 
 *版   权: 
 *开发日期: 
 *修改记录：
 */
 
#ifndef _TS_APP_H_
#define _TS_APP_H_

#include "event.h"
#include "frame_app.h"

/// 版本信息
#define APP_VERSION "V1.0.0 ("__DATE__" "__TIME__")"
/// 应用相关在配置文件中的段名
#define TS_SEC_APP "APP"
/// 组播接收模块相关在配置文件中的段名
#define TS_SEC_RMREVEIVER "RMRECEIVER"
/// 组播发送模块（委托、成交、指令）相关在配置文件中的段名
#define TS_SEC_RMSENDER "RMSENDER"
/// 组播接收本地记录的数据文件
#define TSSERVER_DATA "ts_server.dat"

class CCtpDemo1: public CFrameApp
{
public:
    CCtpDemo1() { }
    ~CCtpDemo1()
    {
        // pUserApi->Join();
    }
    // 初始化接口
    virtual int32_t init(int32_t argc, char** argv);

    // 主线程工作函数
    void work();

    // 结束接口
    virtual int32_t fini();

    // 版本信息接口
    virtual const char* version() const;

protected:

private:
    int OrderInsert() const;
    int QueryTradingAccount();
    int QueryInvestorPosition();
};

extern CCtpDemo1* pApp;
#define CAPP pApp

#endif /* _TS_APP_H_ */

