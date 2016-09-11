///配置文件解析接口定义
/***********************************************************************
系统名称: NEEQ1.0
模块名称:
文 件 名: config_interface.h
功能说明:
作    者: 何李夫
开发日期: 2013-7-23   19:47:59
修改记录:
***********************************************************************/
#ifndef _CONFIG_INTERFACE_H_
#define _CONFIG_INTERFACE_H_

#include <config_env.h>


class CConfigInterface 
{
public:
    ///构造函数
    CConfigInterface() {}

    ///析构函数
    virtual ~CConfigInterface() {}

    ///从配置文件指定“节”上获取指定“键”的整形“值”，不存在返回默认值
	/**
	 *@param const char* chSection：指定“节”名称
     *@param const char* chKey：指定“键”名称
     *@param int32_t iVal：指定“键”不存在时候的默认值
	 *@return: 返回整形值，不存在时返回默认值iVal
	 */
    virtual int32_t GetInt(const char* chSection, const char* chKey, int32_t iVal = 0) const = 0;

    ///从配置文件指定“节”上获取指定“键”的字符串“值”，不存在返回默认值
	/**
	 *@param const char* chSection：指定“节”名称
     *@param const char* chKey：指定“键”名称
     *@param const char* chVal：指定“键”不存在时候的默认值
	 *@return: 返回字符串值，不存在时返回默认值chVal
	 */
    virtual const char* GetString(const char* chSection, const char* chKey, const char* chVal = NULL) const = 0;

};

#endif
