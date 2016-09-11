///����CThread�̻߳���
/***********************************************************************
ϵͳ����:
ģ������:
�� �� ��: thread.h
����˵��:
��    ��:
��������: 2013-9-7   9:14:45
�޸ļ�¼:
***********************************************************************/
#ifndef _THREAD_H_
#define _THREAD_H_

#include <os/config_env.h>

/// �̻߳��ඨ��
/**
   @note �߳�����
   1���߳�ִ����Run()ͨ��IsTerminated()������߳��Ƿ���Ҫ��ֹ
   2���̼߳���Ƿ���Ҫ��ֹ��ʱ���������100ms���С�������ܸ���ļ�⵽�߳��Ƿ���Ҫ��ֹ
       ����ֹStop()�ĵ����ߵȴ���ʱ��ɱ�߳�
       �����Ӧ����Ҫ1000ms��һ�λ���Խ��������Ϊ100ms��ÿ���10�θ�һ�λ�����̼��ʱ��
   3���̲߳��ܵ��������Stop()�������ﵽ��ֹ�Լ���Ŀ��

   @note ������
   1�������̣߳�����Start()�������������سɹ�ʱ���߳��Ѿ�������������
   2����ֹ�̣߳�����Stop()�������������ó�ʱʱ��(ms)����Stop(200)����ʱʱ��Ĭ��Ϊ���޵ȴ�
       ��ע�ⳬʱʱ����ô����̼߳��ֹͣ��ʱ������������ܵ���ɱ�̣߳��߳�ɱ������Դ�����ͷţ�������

    @example:
	class CMyThread: public CThread
	{
	public:
		CMyThread();
		virtual ~CMyThread();

		virtual long Run();
	};

	long CMyThread::Run()
	{
		while (!IsTerminated())
		{
            // wait(100)
			... // do something
		}

		return 0;
	}

    @usage:
    CMyThread Thread;
    Thread.Start();
    //... 
    Thread.Stop(200);
*/
class CThread
{
	friend void OnThreadExit(void* pArg);
	friend void * thread_function(void* pArg);

public:
	/// ���캯��
	CThread();

	/// ������������ֹ�̲߳��ͷ���Դ
	virtual ~CThread();

    /// �����߳�
    /**
     * @return 0�ɹ� ����ʧ��
     */
	int32_t Start();		

    /// ��ֹ�̣߳��߳������ܵ���Stop()����ֹ
	/**
	 * @param iWait ��ʱʱ��,<0��ʾ���޵ȴ�,Ĭ��Ϊ-1
     * @return 0�ɹ� ����ʧ�� 
     * @note ʧ�ܿ��ܵ������Run()ʵ���� 1���߳�������2���߳�ѭ���в�����cancel��
	 */
	int32_t Stop(int iWait = INFINITE);

	/// �߳��Ƿ��Ѿ�����
	/**
	 * @return true ��ʾ�߳��Ѿ�������false��ʾ�߳�δ����
	 */
	inline bool IsRunning() const
	{
	 	return m_bStarted;
	}

    /// �߳��Ƿ���Ҫ��ֹ
	/**
	 * @note Run()�п��Լ���ֵ�Խ����߳�
	 * @return true��ʾ��Ҫ��ֹ,false��ʾ����ֹ
	 */
	inline bool IsTerminated() const
	{
		return m_bTerminateRequest;
	}

    /// �����߳���Ҫ��ֹ��ʶ
	/**
     * @note �߳�ִ����һ��������ʱ��������û������ʱ�����Ⱥ�����������������:
     * while (!IsTerminated())
     * {
     *    task = wait_task(100ms);
     *    proc(task);
     * }
     * ����������ִ��:push(task)�������񣬴Ӷ����������wait_task(100ms)����
     *
     * ��ֹͣ�߳�ʱ�����԰���������ò��裬���ӿ��߳�ֹͣ��
     * 1��Terminate();      // ����ֹͣ��ʶ
     * 2��push_task(null);  // �����߳�
     * 3��Stop();           // ֹͣ�߳�
	 */
	inline void Terminate()
	{
		m_bTerminateRequest = true;
        __sync_synchronize();
	}

protected:
	/// �߳�ִ���壬ʹ���������ظú����������߳�ִ����
	virtual long Run() = 0;

private:
	/// ��ֹ���ƺ͸�ֵ
	CThread(const CThread& one);
	CThread& operator=(const CThread& one);

    /// �ȴ��ź�
    /**
     * @param iWait ��ʱʱ�� <0��ʾ���޵ȴ���Ĭ��Ϊ-1
     * @return 0�ɹ� ����ʧ��
     */
    int WaitCond(int iWait = INFINITE);

private:
    pthread_mutex_t		m_CondMutex;		/**< �߳��ź����� */
    pthread_cond_t		m_Cond;				/**< �߳��ź��� */
    pthread_t           m_hThread;		    /**< �߳̾�� */
	bool volatile		m_bStarted;			/**< �Ƿ��Ѿ����� */
	bool volatile       m_bTerminateRequest;/**< �Ƿ�ֹͣ�߳� */
};

#endif
