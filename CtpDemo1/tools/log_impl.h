///写日志类定义
/***********************************************************************
系统名称:
模块名称:
文 件 名: log_impl.h
功能说明:
作    者:
开发日期: 2013-7-23   20:47:57
修改记录:
***********************************************************************/
#ifndef _LOG_IMPL_H_
#define _LOG_IMPL_H_

#include <thread_mutex.h>

#include <log_interface.h>


class CLogImpl: public CLogInterface 
{
public:
    ///单体类初始化接口
    static CLogImpl* getInstance();

    ///析构函数
    virtual ~CLogImpl();

    ///打开日志文件，默认为向终端输出
    int32_t open(int32_t iLogType = LOG_TYPE_STDOUT);

    ///写日志1
    virtual int32_t write_log(int32_t iErrCode, int32_t iLevel, const char* chFormat, ...);

    ///写日志2
    virtual int32_t write_log(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* chFormat, ...);

protected:
private:
    ///屏蔽构造函数
    CLogImpl();

    ///屏蔽拷贝构造函数
    CLogImpl(const CLogImpl& one);

    ///屏蔽赋值操作符
    const CLogImpl& operator=(const CLogImpl& one);

    ///打开本地日志：终端输出
    int32_t open_stdout();

    ///打开本地日志：本地日志
    int32_t open_file();

    ///打开系统日志
    int32_t open_syslog();

    ///写日志文件
    int32_t writeLog(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* msg);

    ///写本地日志文件
    int32_t writeLocal(const char* chAppName, int32_t iErrCode, int32_t iLevel, const char* msg);

    ///写系统日志文件
    int32_t writeSyslog(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* msg);

    ///统一时间戳
    int32_t getTimeStamp(char* chTimeStamp);

private:
    ///日志类型
    int32_t m_iLogType;

    ////日志文件句柄(C库)
    FILE* m_fp;

    ///互斥锁：用于写本地日志文件
    CThreadMutex m_mutex;
};

#define CLOG CLogImpl::getInstance()

#endif
