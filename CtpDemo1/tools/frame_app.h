///����ඨ��
/***********************************************************************
ϵͳ����:
ģ������:
�� �� ��: frame_app.cpp
����˵��:
��    ��:
��������: 2013-7-16   16:33:19
�޸ļ�¼:
***********************************************************************/
#ifndef _FRAMEAPP_H_
#define _FRAMEAPP_H_

#include <signal.h>

#include <config_env.h>

#include "log_impl.h"
#include "config_impl.h"
#include "options_impl.h"


/* �汾��Ϣ�ͱ���ʱ�䣺v<���߰汾��>.<���汾��>.<������> */
#define FRAME_APP_VERSION   "V2.0.0 ("__DATE__" "__TIME__")"

class CFrameApp
{
public:
    ///��ʼ���ӿڣ��û����븲�Ǵ˽ӿ�
    virtual int32_t init(int32_t argc, char** argv);

    ///�����ӿڣ��û����븲�Ǵ˽ӿ�
    virtual int32_t fini();

    ///�汾��Ϣ�ӿڣ��û����븲�Ǵ˽ӿ�
    virtual const char* version() const;

    ///������������
    const char* getAppName() const;

    ///��־�ļ������
    CLogInterface* Log();

    ///�����ļ������
    CConfigInterface* Config();

    ///�����в��������
    COptionsInterface* Options();

    //////////////////////////////////////////////////////////////////////////
    /* �������Ա���󼰺���Ӧ�ò��û�����Ҫ���� */
    //////////////////////////////////////////////////////////////////////////
public:
    ///���캯�� 
    CFrameApp();

    ///��������
    virtual ~CFrameApp();

    ///������������
    void run(int32_t argc, char** argv);

    ///������ֹ����
    void stop();
protected:
    ///��ֹ���򿪹�
    volatile int32_t m_iShutdown;
    // ���̹߳�������
    virtual void work();

private:
    ///���ο������캯��
    CFrameApp(const CFrameApp& one);

    ///���θ�ֵ������
    const CFrameApp& operator=(const CFrameApp& one);

    ///ע��ȫ��Ӧ�ö���
    void regist_app() const;

    ///ע���źź���
    void regist_signal() const;

    ///���̹߳�������
    //void work() const;

    ///��ʾ������ʹ�ø�ʽ
    void show_usage() const;

    ///��ʾ�汾��Ϣ
    void show_version() const;

    ///�رս���
    void shutdown() const;

    ///������̨����
    void daemon();

    ///����pid�ļ�
    void create_pid_file();

    ///ɾ��pid�ļ�
    void delete_pid_file() const;

private:
    ///��ֹ���򿪹�
    // volatile int32_t m_iShutdown;

    ///pid�ļ����
    int32_t m_iPidFd;

    ///��������
    char m_chAppName[256];

    ///��־�����
    CLogInterface* m_lpLog;

    ///���������
    CConfigInterface* m_lpConfig;

    ///�����в��������
    COptionsInterface* m_lpOptions;
};

extern CFrameApp* pFrame_App;

#endif
