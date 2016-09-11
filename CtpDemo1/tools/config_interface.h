///�����ļ������ӿڶ���
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: config_interface.h
����˵��:
��    ��: �����
��������: 2013-7-23   19:47:59
�޸ļ�¼:
***********************************************************************/
#ifndef _CONFIG_INTERFACE_H_
#define _CONFIG_INTERFACE_H_

#include <config_env.h>


class CConfigInterface 
{
public:
    ///���캯��
    CConfigInterface() {}

    ///��������
    virtual ~CConfigInterface() {}

    ///�������ļ�ָ�����ڡ��ϻ�ȡָ�������������Ρ�ֵ���������ڷ���Ĭ��ֵ
	/**
	 *@param const char* chSection��ָ�����ڡ�����
     *@param const char* chKey��ָ������������
     *@param int32_t iVal��ָ��������������ʱ���Ĭ��ֵ
	 *@return: ��������ֵ��������ʱ����Ĭ��ֵiVal
	 */
    virtual int32_t GetInt(const char* chSection, const char* chKey, int32_t iVal = 0) const = 0;

    ///�������ļ�ָ�����ڡ��ϻ�ȡָ�����������ַ�����ֵ���������ڷ���Ĭ��ֵ
	/**
	 *@param const char* chSection��ָ�����ڡ�����
     *@param const char* chKey��ָ������������
     *@param const char* chVal��ָ��������������ʱ���Ĭ��ֵ
	 *@return: �����ַ���ֵ��������ʱ����Ĭ��ֵchVal
	 */
    virtual const char* GetString(const char* chSection, const char* chKey, const char* chVal = NULL) const = 0;

};

#endif
