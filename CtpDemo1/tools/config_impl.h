///�����ļ������ඨ��
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: config_impl.h
����˵��:
��    ��: �����
��������: 2013-7-23   20:16:16
�޸ļ�¼:
***********************************************************************/
#ifndef _CONFIG_IMPL_H_
#define _CONFIG_IMPL_H_

#include <config_interface.h>


#define CONFIG_MAX_LINE_COUNT	1024 /* �����ļ�������� */
#define CONFIG_MAX_LINE_LENGTH	2048 /* �����ļ�ÿ����󳤶� */

class CConfigImpl: public CConfigInterface 
{
public:
    ///�������ʼ���ӿ�
    static CConfigImpl* getInstance();

    ///��������
    virtual ~CConfigImpl();

    ///�������ļ��ӿ�
    int32_t open(const char* chFileName);

    ///�������ļ�ָ�����ڡ��ϻ�ȡָ�������������Ρ�ֵ��
	virtual int32_t GetInt(const char* chSection, const char* chKey, int32_t iVal) const;

    ///�������ļ�ָ�����ڡ��ϻ�ȡָ�����������ַ�����ֵ��
    virtual const char* GetString(const char* chSection, const char* chKey, const char* chVal) const;

protected:
private:
    ///���ι��캯��
    CConfigImpl();

    ///���ο������캯��
    CConfigImpl(const CConfigImpl& one);

    ///���θ�ֵ������
    const CConfigImpl& operator=(const CConfigImpl& one);

private:
    ///��Ч������
    int32_t m_iLineCount;

    ///��Ч������
    char* m_chLineContent[CONFIG_MAX_LINE_COUNT];
};

#define CCONFIG CConfigImpl::getInstance()

#endif
