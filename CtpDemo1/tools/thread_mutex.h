///�̻߳�����CThreadMutex���Զ���CAutoMutex�ඨ��
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: thread_mutex.h
����˵��:
��    ��: �����
��������: 2013-7-11   11:07:12
�޸ļ�¼:
***********************************************************************/
#ifndef _THREAD_MUTEX_H_
#define _THREAD_MUTEX_H_

#include <config_env.h>


///�̻߳���������
class CThreadMutex
{
public:
	///���캯������ʼ���ٽ���
	CThreadMutex();

    ///���������� ����ٽ���
	~CThreadMutex();

	///�����ٽ���
	int32_t Acquire();

	///�뿪�ٽ���
	int32_t Release();

    ///���Խ����ٽ�����ʧ�ܷ��ط���
    int32_t TryAcquire();

private:
	///���Ļ��������
	pthread_mutex_t m_Mutex;

    ///��յ����溯��
    CThreadMutex(const CThreadMutex& one);
    CThreadMutex& operator=(const CThreadMutex& one);
};

///�Զ�������
class CAutoMutex
{
public:
    ///���캯��
	CAutoMutex(CThreadMutex* pMutex);

    ///��������
    ~CAutoMutex();

private:
	CThreadMutex* m_lpMutex;

    ///��յ����溯��
    CAutoMutex(const CAutoMutex& one);
    CAutoMutex& operator=(const CAutoMutex& one);
};

#endif
