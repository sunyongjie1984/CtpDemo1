///框架类定义
/***********************************************************************
系统名称:
模块名称:
文 件 名: frame_app.cpp
功能说明:
作    者:
开发日期: 2013-7-16   16:33:19
修改记录:
***********************************************************************/
#ifndef _FRAMEAPP_H_
#define _FRAMEAPP_H_

#include <signal.h>

#include <config_env.h>

#include "log_impl.h"
#include "config_impl.h"
#include "options_impl.h"


/* 版本信息和编译时间：v<基线版本号>.<副版本号>.<补丁号> */
#define FRAME_APP_VERSION   "V2.0.0 ("__DATE__" "__TIME__")"

class CFrameApp
{
public:
    ///初始化接口：用户必须覆盖此接口
    virtual int32_t init(int32_t argc, char** argv);

    ///结束接口：用户必须覆盖此接口
    virtual int32_t fini();

    ///版本信息接口：用户必须覆盖此接口
    virtual const char* version() const;

    ///返回主机名称
    const char* getAppName() const;

    ///日志文件类对象
    CLogInterface* Log();

    ///配置文件类对象
    CConfigInterface* Config();

    ///命令行参数类对象
    COptionsInterface* Options();

    //////////////////////////////////////////////////////////////////////////
    /* 以下类成员对象及函数应用层用户不需要关心 */
    //////////////////////////////////////////////////////////////////////////
public:
    ///构造函数 
    CFrameApp();

    ///析构函数
    virtual ~CFrameApp();

    ///进程启动函数
    void run(int32_t argc, char** argv);

    ///进程终止函数
    void stop();
protected:
    ///终止程序开关
    volatile int32_t m_iShutdown;
    // 主线程工作函数
    virtual void work();

private:
    ///屏蔽拷贝构造函数
    CFrameApp(const CFrameApp& one);

    ///屏蔽赋值操作符
    const CFrameApp& operator=(const CFrameApp& one);

    ///注册全局应用对象
    void regist_app() const;

    ///注册信号函数
    void regist_signal() const;

    ///主线程工作函数
    //void work() const;

    ///显示命令行使用格式
    void show_usage() const;

    ///显示版本信息
    void show_version() const;

    ///关闭进程
    void shutdown() const;

    ///启动后台进程
    void daemon();

    ///创建pid文件
    void create_pid_file();

    ///删除pid文件
    void delete_pid_file() const;

private:
    ///终止程序开关
    // volatile int32_t m_iShutdown;

    ///pid文件句柄
    int32_t m_iPidFd;

    ///主机名称
    char m_chAppName[256];

    ///日志类对象
    CLogInterface* m_lpLog;

    ///配置类对象
    CConfigInterface* m_lpConfig;

    ///命令行参数类对象
    COptionsInterface* m_lpOptions;
};

extern CFrameApp* pFrame_App;

#endif
