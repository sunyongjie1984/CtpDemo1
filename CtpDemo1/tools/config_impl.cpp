///�����ļ�������ʵ��
/***********************************************************************
ϵͳ����: 
ģ������:
�� �� ��: config_impl.cpp
����˵��:
��    ��: 
��������: 2013-7-23   20:16:21
�޸ļ�¼:
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
    /* �ļ���Ϊ�� */
    if (chFileName == NULL)
    {
        fprintf(stderr, "[%s:%d]File name is NULL.\n", __FILE__, __LINE__);
        return -1;
    }

    /* ���ı��ļ���ʽ���ļ� */
    FILE *fp = fopen(chFileName, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "[%s:%d]Failed to fopen file: [%s], errno: %d\n", __FILE__, __LINE__, chFileName, errno);
        return -1;
    }

    /* ��ʼ��ȡ�ļ� */
    char chLineContent[CONFIG_MAX_LINE_LENGTH];
    while (fgets(chLineContent, CONFIG_MAX_LINE_LENGTH, fp) != NULL)
    {
        /* ȥ��ͷ���ո� */
        char* chHead = chLineContent;
        while (*chHead != '\0' && *chHead == ' ')
        {
            chHead++;
        }

        if (chHead[0] == ';' || chHead[0] == '#')
        {
            continue; /* ����ע�� */
        }

        /* ȥ��β���ո񡢻��з� */
        size_t szLen = strlen(chHead);
        char* chTail = chHead + szLen - 1;
        while (chTail >= chHead && (*chTail == ' ' || *chTail == '\r' || *chTail == '\n'))
        {
            chTail--;
        }
        *(++chTail) = '\0'; /* �ý����� */

        szLen = chTail - chHead;
        if (szLen == 0)
        {
            continue; /* �������� */
        }

        /* ������Ч��¼ */
        char* chLine = new char[szLen+1];
        memcpy(chLine, chHead, szLen);
        chLine[szLen] = '\0';
        m_chLineContent[m_iLineCount++] = chLine;

        /* �������ޱ��� */
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
    /* ���������ֶ����Ƿ� */
    if (chSection == NULL || chKey == NULL)
    {
        fprintf(stderr, "The chSection: [%s] or chKey: [%s] is NULL.\n", chSection, chKey);
        return chVal;
    }

    /* �������ֶ���Ϊ�� */
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

        /* ֱ�ӱȽ϶������ȣ����Ȳ����ϣ����� */
        if (szLen != (szSectionLen+2))
        {
            continue;
        }

        /* �����Բ���ȷ������ */
        if (chLine[0] != '[' || chLine[szLen-1] != ']')
        {
            continue;
        }

        /* ������ƥ�䣬���� */
        if (memcmp(chSection, chLine+1, szSectionLen) != 0)
        {
            continue;
        }

        /* ���ҵ�Section����ʼ��Entry */
        for (int32_t j = i + 1; j < m_iLineCount; ++j)
        {
            /* ��һ�� */
            char *chNextLine = m_chLineContent[j];

            /* ����һSection�ˣ�˵�����ֶ�û������ */
            if (chNextLine[0] == '[')
            {
                return chVal;
            }

            /* �Ƚ��ֶ������� */
            if (szFieldLen + 1 > strlen(chNextLine))
            {
                continue;
            }

            /* �ҵ�Entry�����غ�������ݣ���������Կ������Ⱥ������ǲ������пո�� */
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
