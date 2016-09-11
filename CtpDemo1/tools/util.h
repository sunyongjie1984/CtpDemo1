/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: util.h
����˵��:
��    ��: �����
��������: 2013-10-11   14:33:32
�޸ļ�¼:
***********************************************************************/
#ifndef _UTIL_H_
#define _UTIL_H_

#include <config_env.h>


///��ȡ��ǰʱ�䣬��ʽ��HHMMSSCC
/**
 *@return ����HHMMSSCC��ʽ��ʱ��
 */
int getHHMMSSCC();

///��ȡ�߾��ȳ�ʱʱ��
/**
 *@param int iTimeout ��ʱʱ��������λ����
 *@param timespec& ts ����ʱ��
 *@return 0��ʾ�ɹ�������ֵ��ʾʧ��
 */
int getTimespec(int iTimeout, timespec& ts);

///����ʱ���
/**
 *@param uint32_t uiHHMMSSCC HHMMSSCC��ʽ��ʱ��
 *@return ����uiHHMMSSCC�뵱ǰʱ��Ĳ�ֵ����λ����
 *        <0��ʾ����ʱ���磬>0��ʾ����ʱ���
 */
int timeElapse(uint32_t uiHHMMSSCC);

#endif
