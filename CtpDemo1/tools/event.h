///�¼� CEvent �ඨ��
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: event.h
����˵��:
��    ��: �����
��������: 2013-7-11   9:14:45
�޸ļ�¼:
***********************************************************************/
#ifndef _EVENT_H_
#define _EVENT_H_

#include <config_env.h>


///�ȴ��¼�ʱ����ֵ
#define EVENT_OK        0   /* ���¼����� */
#define EVENT_TIMEOUT   110 /* �ȴ�ʱ�䳬ʱ */

///�¼�������
class CEvent
{
public:
    ///���캯��
    CEvent();
    
    ///��������
    ~CEvent();
    
    ///�ȴ�һ���¼�
    /**
     *@param iWait �ȴ���ʱ�䣬��λ���룬Ĭ��Ϊֱ�����¼�����
     *@return EVENT_OK��ʾ�ɹ��ȵ����¼����EVENT_TIMEOUT��ʾ��ʱ������ʧ��
     */
	int32_t Wait(int32_t iWait = INFINITE);
	
    ///�������¼�
    /**
     * @return EVENT_OK��ʾ�ɹ���������ʾʧ��
     */
	int32_t Set(void);
	
    ///�����¼�״̬Ϊfalse 
    /**
     * @return EVENT_OK��ʾ�ɹ���������ʾʧ��
    */
    int32_t Reset(void);

private:
    pthread_mutex_t m_Mutex; /* �������������Ļ����� */
    pthread_cond_t m_Cond; /* ����������� */    
    bool m_bNotify;

    ///��յ����溯��
    CEvent(const CEvent& one);
    CEvent& operator=(const CEvent& one);
};

#endif
