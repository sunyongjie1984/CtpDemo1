///�����в��������ӿڶ���
/***********************************************************************
ϵͳ����:
ģ������:
�� �� ��: options_interface.h
����˵��:
��    ��:
��������: 2013-7-23   19:41:48
�޸ļ�¼:
***********************************************************************/
#ifndef _OPTIONS_INTERFACE_H_
#define _OPTIONS_INTERFACE_H_

#include <config_env.h>


class COptionsInterface 
{
public:
    ///���캯��
    COptionsInterface() {}

    ///��������
    virtual ~COptionsInterface() {}

    ///�����Ƿ�ð�̲���
	/**
    *@param ��
    *@return: �����Ƿ�ð�̲��ԣ�true��ʾð�̲��ԣ�false��ʾ��ð�̲���
	 */
    virtual bool getSmokeTestOpt() const = 0;

    ///������־����
	/**
    *@param ��
    *@return: ������־����
	 */
    virtual int32_t getLogType() const = 0;

    ///������־����
	/**
    *@param ��
    *@return: ������־����
	 */
    virtual int32_t getLogLevel() const = 0;

    ///������������
	/**
    *@param ��
    *@return: ������������
	 */
    virtual int32_t getAppType() const = 0;

    ///���ؽ��̱��
	/**
    *@param ��
    *@return: ���ؽ��̱��
	 */
    virtual int32_t getProNum() const = 0;

    ///���������ļ�����
	/**
    *@param ��
    *@return: ���������ļ�����
	 */
    virtual const char* getCfgFileName() const = 0;

    ///���ؽ�������
	/**
    *@param ��
    *@return: ���ؽ�������
	 */
    virtual const char* getProName() const = 0;

    ///����Ԥ��ѡ��ֵ
	/**
    *@param ��
    *@return: ����Ԥ��ѡ��ֵ
	 */
    virtual const char* getReserveOpt() const = 0;
};

#endif
