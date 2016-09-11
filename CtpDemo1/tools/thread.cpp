///ʵ��CThread�̻߳���
/***********************************************************************
ϵͳ����:
ģ������:
�� �� ��: thread.cpp
����˵��:
��    ��:
��������: 2013-9-7   9:14:45
�޸ļ�¼:
***********************************************************************/
#include <os/util.h>
#include <os/thread.h>

#include <Include/event_id.h>


void OnThreadExit(void* pArg)
{
	if (pArg)
	{
		CThread* pThread = (CThread* )pArg;

        pthread_mutex_lock(&pThread->m_CondMutex);
        pThread->m_bStarted = false;
        /** ֪ͨStop()�����ߣ��߳����˳� */
        pthread_cond_signal(&pThread->m_Cond);
        pthread_mutex_unlock(&pThread->m_CondMutex);
	}
}

void* thread_function(void* pArg)
{
    void* rc = NULL;

	if (pArg)
	{
        CThread* pThread = (CThread* )pArg;

        /** ������ֹ�̹߳������������pthread_create����ʧ�ܣ��ڵ����߽���ȴ�״̬��������ܼ����� */
        pthread_mutex_lock(&pThread->m_CondMutex);
        pThread->m_bStarted = true;
        /** ��ǰ�����߳��˳�����������֤�߳������˳���kill�˳�������ȷ�����߳�״̬ */
        pthread_cleanup_push(OnThreadExit, pThread);
        /** ֪ͨStart()�����ߣ��߳������� */
        pthread_cond_signal(&pThread->m_Cond);
        pthread_mutex_unlock(&pThread->m_CondMutex);

        /** ִ���������߳�ִ���� */
    	rc = (void* )pThread->Run();

        /** ������ִ���߳��˳������� */
        pthread_cleanup_pop(1);
	}

	return rc;
}

CThread::CThread()
: m_hThread(0)
, m_bStarted(false)
, m_bTerminateRequest(false)
{
	pthread_mutex_init(&m_CondMutex, NULL);
	pthread_cond_init(&m_Cond, NULL);
}

CThread::~CThread()
{
    if (m_bStarted)
    {
        Stop(100);
    }

    pthread_mutex_destroy(&m_CondMutex);
    pthread_cond_destroy(&m_Cond);
}

int32_t CThread::Start()
{
    int rc = 0;

    rc = pthread_mutex_lock(&m_CondMutex);
    if (rc != 0)
    {
        return rc;
    }

    /** ����߳��Ƿ����� */
	if (!m_bStarted)
    {
        m_bTerminateRequest = false;

        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setstacksize(&attr, 1024 * 1024 * 10);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

        /** �����߳� */
        int rc = pthread_create(&m_hThread, &attr, thread_function, (void* )this);
        if (rc == 0)
        {
            /** �ȴ��߳����� */
            WaitCond();
        }

        pthread_attr_destroy(&attr);
    }
	
    rc = pthread_mutex_unlock(&m_CondMutex);
	return (int32_t)rc;
}

int32_t CThread::Stop(int iWait)
{
    int rc = 0;

	rc = pthread_mutex_lock(&m_CondMutex);
    if (rc != 0)
    {
        return rc;
    }

	/** �߳��������ҷ��߳��Լ����� */
	if (m_bStarted && !pthread_equal(pthread_self(), m_hThread))
	{
		/** ֪ͨ�߳�ֹͣ */
		Terminate();

        /** �ȴ��߳�Run()�����˳� */
		WaitCond(iWait);

		/** �߳��ѽ��� */
        if (!m_bStarted)
        {
            m_bTerminateRequest = false;
        }
        else
        {
            /** ����̻߳�û����,�򵥴ֱ�ɱ�߳� */
            if (pthread_cancel(m_hThread) == 0)
            {
                /** kill�źŷ�����˵�����̻߳��ڣ�10ms�ȴ��߳��˳� */
                WaitCond(10);
            }

            /** �߳��˳� */
            if (!m_bStarted)
            {
                m_bTerminateRequest = false;
            }
            else
            {
                /** �߳�ûɱ�������ܵ������1���߳�������2���߳�ѭ���в�����cancel�� */
                rc = -1;
            }
        }
	}

	rc = pthread_mutex_unlock(&m_CondMutex);
    return (int32_t)rc;
}

int CThread::WaitCond(int iWait)
{
    int rc = 0;

    if (iWait < 0)
    {
        rc = pthread_cond_wait(&m_Cond, &m_CondMutex);
    }
    else
    {
        timespec ts;
        getTimespec(iWait, ts);
        rc = pthread_cond_timedwait(&m_Cond, &m_CondMutex, &ts);
    }

    return rc;
}
