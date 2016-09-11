///�̻߳�������ʵ��
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: thread_mutex.cpp
����˵��:
��    ��: �����
��������: 2013-7-11   11:08:55
�޸ļ�¼:
***********************************************************************/
#include <thread_mutex.h>


CThreadMutex::CThreadMutex()
{
    pthread_mutexattr_t attr;

    /* ��ʼ�����������Զ��� */
    pthread_mutexattr_init(&attr);

    /* ���û��������������� */
    pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);

    /* ��̬���������� */
    pthread_mutex_init(&m_Mutex, &attr);

    /* ���ٻ��������Զ��� */
    pthread_mutexattr_destroy(&attr);
}

CThreadMutex::~CThreadMutex()
{
    /* ���ٻ����� */
	pthread_mutex_destroy(&m_Mutex);
}

int32_t CThreadMutex::Acquire()
{
	return pthread_mutex_lock(&m_Mutex);
}

int32_t CThreadMutex::Release()
{
	return pthread_mutex_unlock(&m_Mutex);
}

int32_t CThreadMutex::TryAcquire()
{
    return pthread_mutex_trylock(&m_Mutex);
}

//////////////////////////////////////////////////////////////////////////
CAutoMutex::CAutoMutex(CThreadMutex* pMutex)
: m_lpMutex(pMutex)
{
    m_lpMutex->Acquire();
}

CAutoMutex::~CAutoMutex()
{
    m_lpMutex->Release();
}
