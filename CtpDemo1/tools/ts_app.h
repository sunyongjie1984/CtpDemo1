///定义交易撮合主机的程序框架
/**
 *源程序名称: ts_app.h
 *系统名称: NEEQ1.0 交易撮合主机
 *模块名称: 主框架
 *功能说明: 该头文件定义主应用框架
 *作   者: shoujj
 *版   权: neeq
 *开发日期: 20130803
 *修改记录：
 *V0.0.2 20131002 xuzj 根据代码评审结构修正相关问题
 *V0.0.3 20131010 xuzj 修改证券代码和证券类别的初始化文件结构，主要涉及有效价格区间限制的控制（需要更新初始化DBF文件）
 *V0.0.4 20131015 xuzj 修改原始委托结构，调整“联系人”、“联系方式”字段类型的长度定义，需要其他各模块同步配合集成
 *       20131015 sunyj 根据框架结构调整做出相应变更
 *       20131016 xuzj 为了加载7000W的账户数据，已将证券账户列表对象的HASH表参数改为1亿，可能导致启动时会比较慢
 *V0.1.0 20131130 xuzj 按新的业务需求进行调整
 *V0.1.1 20131202 xuzj 根据新需求1.1，修改代码
 *V0.1.2 20131219 xuzj 修正紧急维护相关的bug等
 *V0.1.3 20131225 sunyj 修正交易单元限制相关的bug等
 *V0.1.6 20140114 xuzj 修正原停牌股票紧急复牌时无法正确复牌的错误；修正撤单废单时成交数量输出不为0的问题等
 *V0.1.8 20140225 sunyj 加入限制，股票代码如无证券类别住处，程序直接退出
 *V0.1.9 20140225 sunyj 修改bug NEEQ-1569
 */
 
#ifndef _TS_APP_H_
#define _TS_APP_H_

//#include <os/memshared.h>

//#include <Class/file.h>
#include <event.h>

#include <frame_app.h>

//#include "ts_init.h"
//#include "ts_order_book.h"
//#include "ts_memory_pool.h"
//#include "ts_match_interface.h"

/// 版本信息
#define APP_VERSION "V3.0.0 ("__DATE__" "__TIME__")"
/// 应用相关在配置文件中的段名
#define TS_SEC_APP "APP"
/// 组播接收模块相关在配置文件中的段名
#define TS_SEC_RMREVEIVER "RMRECEIVER"
/// 组播发送模块（委托、成交、指令）相关在配置文件中的段名
#define TS_SEC_RMSENDER "RMSENDER"
/// 组播接收本地记录的数据文件
#define TSSERVER_DATA "ts_server.dat"
///// 监控共享内存的Key默认值
//#define TS_MON_SHAREMEMKEY "TS_MON_SHAREMEM"

class CTS_APP: public CFrameApp
{
public:
	//CTS_APP() : m_pMatch(NULL), m_pPublicQuotation(NULL), m_pRMReceiver(NULL), m_pRMSender(NULL),
	//m_pMonShareDataTS(NULL) { }
    CTS_APP() { }
    ///初始化接口
   virtual int32_t init(int32_t argc, char** argv);
   
    ///结束接口
    virtual int32_t fini();

    ///版本信息接口
    virtual const char* version() const;

protected:

private:
};

extern CTS_APP* pApp;
#define CAPP pApp

#endif /* _TS_APP_H_ */

