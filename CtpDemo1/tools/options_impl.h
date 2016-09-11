///解析启动参数列表类定义
/***********************************************************************
系统名称: NEEQ1.0
模块名称:
文 件 名: options_impl.h
功能说明:
作    者: 何李夫
开发日期: 2013-7-23   20:50:23
修改记录:
***********************************************************************/
#ifndef _OPTIONS_IMPL_H_
#define _OPTIONS_IMPL_H_

#include <options_interface.h>


class COptionsImpl: public COptionsInterface
{
public:
    ///单体类初始化接口
    static COptionsImpl* getInstance();

    ///析构函数
    virtual ~COptionsImpl();

    ///解析命令行接口
    int32_t open(int32_t argc, char** argv);

    ///返回是否显示帮助信息
    bool getHelpOpt() const;

    ///返回是否显示版本信息
    bool getVersionOpt() const;

    ///返回是否关闭进程标识
    bool getShutdownOpt() const;

    ///返回是否屏蔽core文件：true屏蔽，false不屏蔽
    bool getCoreOpt() const;

    ///返回是否后台进程
    bool getDaemonOpt() const;

    ///返回是否冒烟测试
    virtual bool getSmokeTestOpt() const;

    ///返回日志类型
    virtual int32_t getLogType() const;

    ///返回日志级别
    virtual int32_t getLogLevel() const;

    ///返回主机类型
    virtual int32_t getAppType() const;

    ///返回进程编号
    virtual int32_t getProNum() const;

    ///返回配置文件名称
    virtual const char* getCfgFileName() const;

    ///返回进程名称
    virtual const char* getProName() const;

    ///返回预留选项值
    virtual const char* getReserveOpt() const;
protected:
private:
    ///屏蔽构造函数
    COptionsImpl();

    ///屏蔽拷贝构造函数
    COptionsImpl(const COptionsImpl& one);

    ///屏蔽赋值操作符
    const COptionsImpl& operator=(const COptionsImpl& one);

private:
    bool m_bHelpOpt;                    /* 帮助信息 */
    bool m_bVersionOpt;                 /* 版本信息 */
    bool m_bShutdown;                   /* 是否关闭进程 */
    bool m_bCoreOpt;                    /* 是否屏蔽core文件，默认不屏蔽 */
    bool m_bDaemonOpt;                  /* 是否后台进程，默认前台程序 */
    bool m_bSmokeTestOpt;               /* 是否冒烟测试，默认非冒烟测试 */
    int32_t m_iLogType;                 /* 日志类型：终端输出还是日志文件 */
    int32_t m_iLogLevel;                /* 日志级别 */
    int32_t m_iAppType;                 /* 主机类型 */
    int32_t m_iProNum;                  /* 进程编号 */
    char m_chCfgFile[256];              /* 配置文件名，带路径 */
    char m_chProName[256];              /* 进程名称 */
    char m_chReserve[256];              /* 预留参数 */
};

#define COPTIONS COptionsImpl::getInstance()

#endif
