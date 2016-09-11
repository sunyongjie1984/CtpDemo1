///写日志接口定义
/***********************************************************************
系统名称: NEEQ1.0
模块名称:
文 件 名: log_interface.h
功能说明:
作    者: 何李夫
开发日期: 2013-7-23   20:05:22
修改记录:
***********************************************************************/
#ifndef _LOG_INTERFACE_H_
#define _LOG_INTERFACE_H_

#include <config_env.h>


/* Log Types */
enum LogType
{
    LOG_TYPE_STDOUT     = 0,        /* 终端输出 */
    LOG_TYPE_FILE       = 1         /* 日志输出 */
};

/* Log levels，值越大级别越低 */
enum LogLevel
{
    LOG_LEVEL_EMERG     = 0,        /* 最高级别：系统不可用，暂不使用 */
    LOG_LEVEL_ALERT     = 1,        /* 紧急级别：紧急事件，必须立即采取措施，暂不使用 */
    LOG_LEVEL_CRIT      = 2,        /* 严重级别：临界条件，严重影响业务，如运行状态时序出错 */
    LOG_LEVEL_ERROR     = 3,        /* 错误级别：错误信息，影响业务处理，需要人工介入，如文件打开失败等 */
    LOG_LEVEL_WARNING   = 4,        /* 警告级别：告警但不影响业务信息，一般不需要人工介入，但需要监控人员分析，如收到不合法的消息 */
    LOG_LEVEL_NOTICE    = 5,        /* 通知级别：提示信息，很重要的信息，写syslog，如运行状态事件 */
    LOG_LEVEL_INFO      = 6,        /* 信息级别：业务流程信息，不写syslog，如初始化成功、开闭市指令、紧急维护指令 */
    LOG_LEVEL_DEBUG     = 7         /* 调试级别：调试类信息，不写syslog */
};

class CLogInterface 
{
public:
    ///构造函数
    CLogInterface() {}

    ///析构函数
    virtual ~CLogInterface() {}

    ///写日志
	/**
     *@param int32_t iErrCode：错误号
	 *@param int32_t iLevel：日志级别
     *@param const char* chFormat：日志格式
     *@param ...：变长参数
	 *@return: 返回操作结果，0表示成功，其他值表示失败
	 */
    virtual int32_t write_log(int32_t iErrCode, int32_t iLevel, const char* chFormat, ...) = 0;

    ///以下接口适用于同一个进程不同模块，目前仅提供给行情模块写系统日志使用
    ///写日志
	/**
     *@param const char* chAppName：主机名称
     *@param int32_t iAppType：应用类型
     *@param int32_t iErrCode：错误号
	 *@param int32_t iLevel：日志级别
     *@param const char* chFormat：日志格式
     *@param ...：变长参数
	 *@return: 返回操作结果，0表示成功，其他值表示失败
	 */
    virtual int32_t write_log(const char* chAppName, int32_t iAppType, int32_t iErrCode, int32_t iLevel, const char* chFormat, ...) = 0;
};

/* 记录日志位置信息 */
//#define FMT(str)    "[%s:%d %s]:"str, __FILE__, __LINE__, __FUNCTION__

/* 写日志宏 */
#define CRIT(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_CRIT, format, ##args))
#define ERROR(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_ERROR, format, ##args))
#define WARNING(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_WARNING, format, ##args))
#define NOTICE(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_NOTICE, format, ##args))
#define INFO(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_INFO, format, ##args))
#define DEBUG(err, format, args...) (CLOG->write_log(err, LOG_LEVEL_DEBUG, format, ##args))

#define CRIT1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_CRIT, format, ##args))
#define ERROR1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_ERROR, format, ##args))
#define WARNING1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_WARNING, format, ##args))
#define NOTICE1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_NOTICE, format, ##args))
#define INFO1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_INFO, format, ##args))
#define DEBUG1(name, type, err, format, args...) (CLOG->write_log(name, type, err, LOG_LEVEL_DEBUG, format, ##args))

#endif
