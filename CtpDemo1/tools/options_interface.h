///命令行参数解析接口定义
/***********************************************************************
系统名称:
模块名称:
文 件 名: options_interface.h
功能说明:
作    者:
开发日期: 2013-7-23   19:41:48
修改记录:
***********************************************************************/
#ifndef _OPTIONS_INTERFACE_H_
#define _OPTIONS_INTERFACE_H_

#include <config_env.h>


class COptionsInterface 
{
public:
    ///构造函数
    COptionsInterface() {}

    ///析构函数
    virtual ~COptionsInterface() {}

    ///返回是否冒烟测试
	/**
    *@param ：
    *@return: 返回是否冒烟测试，true表示冒烟测试，false表示非冒烟测试
	 */
    virtual bool getSmokeTestOpt() const = 0;

    ///返回日志类型
	/**
    *@param ：
    *@return: 返回日志类型
	 */
    virtual int32_t getLogType() const = 0;

    ///返回日志级别
	/**
    *@param ：
    *@return: 返回日志级别
	 */
    virtual int32_t getLogLevel() const = 0;

    ///返回主机类型
	/**
    *@param ：
    *@return: 返回主机类型
	 */
    virtual int32_t getAppType() const = 0;

    ///返回进程编号
	/**
    *@param ：
    *@return: 返回进程编号
	 */
    virtual int32_t getProNum() const = 0;

    ///返回配置文件名称
	/**
    *@param ：
    *@return: 返回配置文件名称
	 */
    virtual const char* getCfgFileName() const = 0;

    ///返回进程名称
	/**
    *@param ：
    *@return: 返回进程名称
	 */
    virtual const char* getProName() const = 0;

    ///返回预留选项值
	/**
    *@param ：
    *@return: 返回预留选项值
	 */
    virtual const char* getReserveOpt() const = 0;
};

#endif
