///配置文件解析类实现
/***********************************************************************
系统名称: 
模块名称:
文 件 名: config_impl.cpp
功能说明:
作    者: 
开发日期: 2013-7-23   20:16:21
修改记录:
***********************************************************************/
#include <stdio.h>
#include <string.h>

#include "config_impl.h"


CConfigImpl* CConfigImpl::getInstance()
{
    static CConfigImpl one;
    return &one;
}

CConfigImpl::~CConfigImpl()
{
}

int32_t CConfigImpl::open(const char* chFileName)
{
    /* 文件名为空 */
    if (chFileName == NULL)
    {
        fprintf(stderr, "[%s:%d]File name is NULL.\n", __FILE__, __LINE__);
        return -1;
    }

    /* 以文本文件方式打开文件 */
    FILE *fp = fopen(chFileName, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "[%s:%d]Failed to fopen file: [%s], errno: %d\n", __FILE__, __LINE__, chFileName, errno);
        return -1;
    }

    /* 开始读取文件 */
    char chLineContent[CONFIG_MAX_LINE_LENGTH];
    while (fgets(chLineContent, CONFIG_MAX_LINE_LENGTH, fp) != NULL)
    {
        /* 去除头部空格 */
        char* chHead = chLineContent;
        while (*chHead != '\0' && *chHead == ' ')
        {
            chHead++;
        }

        if (chHead[0] == ';' || chHead[0] == '#')
        {
            continue; /* 跳过注释 */
        }

        /* 去除尾部空格、换行符 */
        size_t szLen = strlen(chHead);
        char* chTail = chHead + szLen - 1;
        while (chTail >= chHead && (*chTail == ' ' || *chTail == '\r' || *chTail == '\n'))
        {
            chTail--;
        }
        *(++chTail) = '\0'; /* 置结束符 */

        szLen = chTail - chHead;
        if (szLen == 0)
        {
            continue; /* 跳过空行 */
        }

        /* 保存有效记录 */
        char* chLine = new char[szLen+1];
        memcpy(chLine, chHead, szLen);
        chLine[szLen] = '\0';
        m_chLineContent[m_iLineCount++] = chLine;

        /* 容量上限保护 */
        if (m_iLineCount >= CONFIG_MAX_LINE_COUNT)
        {
            fprintf(stderr, "[%s:%d]Valid line count is going to exceed the limit.\n", __FILE__, __LINE__);
            break;
        }
    }

    fclose(fp);
    return 0;
}

int32_t CConfigImpl::GetInt(const char* chSection, const char* chKey, int32_t iVal) const
{
    const char* chVal = this->GetString(chSection, chKey, NULL);
    if (chVal == NULL)
    {
        return iVal;
    }

    return atoi(chVal);
}

const char* CConfigImpl::GetString(const char* chSection, const char* chKey, const char* chVal) const
{
    /* 段名或者字段名非法 */
    if (chSection == NULL || chKey == NULL)
    {
        fprintf(stderr, "The chSection: [%s] or chKey: [%s] is NULL.\n", chSection, chKey);
        return chVal;
    }

    /* 段名和字段名为空 */
    size_t szSectionLen = strlen(chSection);
    size_t szFieldLen = strlen(chKey);
    if (szSectionLen == 0 || szFieldLen == 0)
    {
        return chVal;
    }

    for (int32_t i = 0; i < m_iLineCount; ++i)
    {
        char* chLine = m_chLineContent[i];
        size_t szLen = strlen(chLine);

        /* 直接比较段名长度：长度不符合，跳过 */
        if (szLen != (szSectionLen+2))
        {
            continue;
        }

        /* 段属性不正确，跳过 */
        if (chLine[0] != '[' || chLine[szLen-1] != ']')
        {
            continue;
        }

        /* 段名不匹配，跳过 */
        if (memcmp(chSection, chLine+1, szSectionLen) != 0)
        {
            continue;
        }

        /* 已找到Section，开始找Entry */
        for (int32_t j = i + 1; j < m_iLineCount; ++j)
        {
            /* 下一行 */
            char *chNextLine = m_chLineContent[j];

            /* 到下一Section了，说明该字段没有配置 */
            if (chNextLine[0] == '[')
            {
                return chVal;
            }

            /* 比较字段名长度 */
            if (szFieldLen + 1 > strlen(chNextLine))
            {
                continue;
            }

            /* 找到Entry，返回后面的数据：从这里可以看出，等号左右是不允许有空格的 */
            if (memcmp(chNextLine, chKey, szFieldLen) == 0 && chNextLine[szFieldLen] == '=')
            {
                return chNextLine + szFieldLen + 1;
            }
        }
    }

    return chVal;
}

CConfigImpl::CConfigImpl()
: m_iLineCount(0)
{
    memset(m_chLineContent, '\0', sizeof(char*)*CONFIG_MAX_LINE_COUNT);
}
