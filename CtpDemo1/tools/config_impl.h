///配置文件解析类定义
/***********************************************************************
系统名称: NEEQ1.0
模块名称:
文 件 名: config_impl.h
功能说明:
作    者: 何李夫
开发日期: 2013-7-23   20:16:16
修改记录:
***********************************************************************/
#ifndef _CONFIG_IMPL_H_
#define _CONFIG_IMPL_H_

#include <config_interface.h>


#define CONFIG_MAX_LINE_COUNT	1024 /* 配置文件最大行数 */
#define CONFIG_MAX_LINE_LENGTH	2048 /* 配置文件每行最大长度 */

class CConfigImpl: public CConfigInterface 
{
public:
    ///单体类初始化接口
    static CConfigImpl* getInstance();

    ///析构函数
    virtual ~CConfigImpl();

    ///打开配置文件接口
    int32_t open(const char* chFileName);

    ///从配置文件指定“节”上获取指定“键”的整形“值”
	virtual int32_t GetInt(const char* chSection, const char* chKey, int32_t iVal) const;

    ///从配置文件指定“节”上获取指定“键”的字符串“值”
    virtual const char* GetString(const char* chSection, const char* chKey, const char* chVal) const;

protected:
private:
    ///屏蔽构造函数
    CConfigImpl();

    ///屏蔽拷贝构造函数
    CConfigImpl(const CConfigImpl& one);

    ///屏蔽赋值操作符
    const CConfigImpl& operator=(const CConfigImpl& one);

private:
    ///有效行数量
    int32_t m_iLineCount;

    ///有效行内容
    char* m_chLineContent[CONFIG_MAX_LINE_COUNT];
};

#define CCONFIG CConfigImpl::getInstance()

#endif
