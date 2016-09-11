///�������������б���ʵ��
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: options_impl.cpp
����˵��:
��    ��: �����
��������: 2013-7-23   21:52:39
�޸ļ�¼:
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "glbdef.h"
#include "log_interface.h"

#include "options_impl.h"


COptionsImpl* COptionsImpl::getInstance()
{
    static COptionsImpl one;
    return &one;
}

COptionsImpl::~COptionsImpl()
{
}

int32_t COptionsImpl::open(int32_t argc, char** argv)
{
    /* ֻ�н���������ʾ������Ϣ */
    /*if (argc <= 1)
    {
        m_bHelpOpt = true;
        return 0;
    }*/

    /* �����б�˵����
       ѡ���ַ� "x"  ��ʾѡ�� "-x"
       ѡ���ַ� "x:" ��ʾѡ�������� "-x argument"  */
    int32_t ch = 0;
    while ((ch = getopt(argc, argv, "hvscdmt:f:o:l:n:r:")) != -1)
    {
        switch (ch)
        {
        case 'h': /* ��ʾ���� */
            m_bHelpOpt = true;
            break;
        case 'v': /* ��ʾ�汾 */
            m_bVersionOpt = true;
            break;
        case 's': /* �رս��� */
            m_bShutdown = true;
            break;
        case 'c': /* �Ƿ�����core�ļ� */
            m_bCoreOpt = true;
            break;
        case 'd': /* ��̨���� */
            m_bDaemonOpt = true;
            break;
        case 'm': /* �Ƿ�ð�̲��� */
            m_bSmokeTestOpt = true;
            break;
        case 't': /* ������������  */
            m_iAppType = atoi(optarg);
            break;
        case 'f': /* ���������ļ� */
            memcpy(m_chCfgFile, optarg, strlen(optarg));
            break;
        case 'o': /* ����������� */
            m_iLogType = atoi(optarg);
            break;
        case 'l': /* ����������� */
            m_iLogLevel = atoi(optarg);
            break;
        case 'n': /* �������̱�� */
            m_iProNum = atoi(optarg);
            break;
        case 'r': /* Ԥ��ѡ��ֵ */
            memcpy(m_chReserve, optarg, strlen(optarg));
            break;
        default:
            fprintf(stderr, "[%s:%d]%s: illegal options -- [%c]\n", __FILE__, __LINE__, argv[0], ch);
            return -1;
        }
    }

    /* Ӧ�ý������ƣ�Ʋȥ·��ǰ׺��ֻ���������� */
    const char* chProName = argv[0];
    size_t szLen = strlen(chProName);
    int32_t i = szLen - 1;
    while (i >= 0 && chProName[i] != '/') --i;
    memcpy(m_chProName, chProName+i+1, szLen-i-1);
    m_chProName[szLen-i-1] = '\0';

    /* δָ�������ļ���Ĭ��ʹ�á�������.ini�� */
    if (strlen(m_chCfgFile) == 0)
    {
        sprintf(m_chCfgFile, "%s.ini", m_chProName);
    }

    return 0;
}

bool COptionsImpl::getHelpOpt() const
{
    return m_bHelpOpt;
}

bool COptionsImpl::getVersionOpt() const
{
    return m_bVersionOpt;
}

bool COptionsImpl::getShutdownOpt() const
{
    return m_bShutdown;
}

bool COptionsImpl::getCoreOpt() const
{
    return m_bCoreOpt;
}

bool COptionsImpl::getDaemonOpt() const
{
    return m_bDaemonOpt;
}

bool COptionsImpl::getSmokeTestOpt() const
{
    return m_bSmokeTestOpt;
}

int32_t COptionsImpl::getLogType() const
{
    return m_iLogType;
}

int32_t COptionsImpl::getLogLevel() const
{
    return m_iLogLevel;
}

int32_t COptionsImpl::getAppType() const
{
    return m_iAppType;
}

int32_t COptionsImpl::getProNum() const
{
    return m_iProNum;
}

const char* COptionsImpl::getCfgFileName() const
{
    return m_chCfgFile;
}

const char* COptionsImpl::getProName() const
{
    return m_chProName;
}

const char* COptionsImpl::getReserveOpt() const
{
    return m_chReserve;
}

COptionsImpl::COptionsImpl()
: m_bHelpOpt(false)
, m_bVersionOpt(false)
, m_bShutdown(false)
, m_bCoreOpt(false)
, m_bDaemonOpt(false)
, m_bSmokeTestOpt(false)
, m_iLogType(0)
, m_iLogLevel(LOG_LEVEL_DEBUG)
, m_iAppType(0)
, m_iProNum(0)
{
    memset(m_chCfgFile, '\0', sizeof(m_chCfgFile));
    memset(m_chProName, '\0', sizeof(m_chProName));
    memset(m_chReserve, '\0', sizeof(m_chReserve));
}
