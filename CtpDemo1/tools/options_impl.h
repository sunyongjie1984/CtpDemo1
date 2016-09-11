///�������������б��ඨ��
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: options_impl.h
����˵��:
��    ��: �����
��������: 2013-7-23   20:50:23
�޸ļ�¼:
***********************************************************************/
#ifndef _OPTIONS_IMPL_H_
#define _OPTIONS_IMPL_H_

#include <options_interface.h>


class COptionsImpl: public COptionsInterface
{
public:
    ///�������ʼ���ӿ�
    static COptionsImpl* getInstance();

    ///��������
    virtual ~COptionsImpl();

    ///���������нӿ�
    int32_t open(int32_t argc, char** argv);

    ///�����Ƿ���ʾ������Ϣ
    bool getHelpOpt() const;

    ///�����Ƿ���ʾ�汾��Ϣ
    bool getVersionOpt() const;

    ///�����Ƿ�رս��̱�ʶ
    bool getShutdownOpt() const;

    ///�����Ƿ�����core�ļ���true���Σ�false������
    bool getCoreOpt() const;

    ///�����Ƿ��̨����
    bool getDaemonOpt() const;

    ///�����Ƿ�ð�̲���
    virtual bool getSmokeTestOpt() const;

    ///������־����
    virtual int32_t getLogType() const;

    ///������־����
    virtual int32_t getLogLevel() const;

    ///������������
    virtual int32_t getAppType() const;

    ///���ؽ��̱��
    virtual int32_t getProNum() const;

    ///���������ļ�����
    virtual const char* getCfgFileName() const;

    ///���ؽ�������
    virtual const char* getProName() const;

    ///����Ԥ��ѡ��ֵ
    virtual const char* getReserveOpt() const;
protected:
private:
    ///���ι��캯��
    COptionsImpl();

    ///���ο������캯��
    COptionsImpl(const COptionsImpl& one);

    ///���θ�ֵ������
    const COptionsImpl& operator=(const COptionsImpl& one);

private:
    bool m_bHelpOpt;                    /* ������Ϣ */
    bool m_bVersionOpt;                 /* �汾��Ϣ */
    bool m_bShutdown;                   /* �Ƿ�رս��� */
    bool m_bCoreOpt;                    /* �Ƿ�����core�ļ���Ĭ�ϲ����� */
    bool m_bDaemonOpt;                  /* �Ƿ��̨���̣�Ĭ��ǰ̨���� */
    bool m_bSmokeTestOpt;               /* �Ƿ�ð�̲��ԣ�Ĭ�Ϸ�ð�̲��� */
    int32_t m_iLogType;                 /* ��־���ͣ��ն����������־�ļ� */
    int32_t m_iLogLevel;                /* ��־���� */
    int32_t m_iAppType;                 /* �������� */
    int32_t m_iProNum;                  /* ���̱�� */
    char m_chCfgFile[256];              /* �����ļ�������·�� */
    char m_chProName[256];              /* �������� */
    char m_chReserve[256];              /* Ԥ������ */
};

#define COPTIONS COptionsImpl::getInstance()

#endif
