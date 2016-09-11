///NEEQȫ�ֳ�������
/***********************************************************************
ϵͳ����: NEEQ1.0 ����
ģ������: Include
�� �� ��: glbdef.h
����˵��: ����NEEQȫ�ֳ������塢IPC���󣨹����ڴ桢�ź�������ʶ��ͨ�Ŷ˿�ȱʡֵ��
��    ��: �����
��������: 2013-7-1   15:55:08
�޸ļ�¼:
***********************************************************************/
#ifndef _GLBDEF_H_
#define _GLBDEF_H_


#define FALSE           0
#define TRUE            1
#define ERR_ALLOC       -1
#define SUCCEED         0
#define FAIL            -1

#define INIT_SEM_VALUE  0           /* �ź�����ʼֵ */
#define SEM_MAX_VALUE   0x7fffffff  /* �ź������ֵ */

#define TRADE_DURATION  4        /* ����ʱ�� 4��Сʱ */
#define PERFORMANCE     15000    /* ��������: 15000��ί�е�/�� */    
#define PEAK            40000    /* �߷����ܣ�40000��ί�е�/�� */

///Ӧ���������ͣ�Ӧ���ڼ�ص�������ʶ�ֶ�
enum AppServerType 
{
    //TEST_SERVER             = 0,    /* �������� */
    TRADE_SERVER            = 1,    /* �������� */
    QUOTATION_SERVER        = 2,    /* �������� */
    SUPERVISE_SERVER        = 3,    /* ������� */
    ORDER_QUEUE_SERVER      = 4,    /* ί���Ŷӻ� */
    ORDER_FEP_SERVER        = 5,    /* ί��ǰ�û� */
    ARBITRATE_SERVER        = 6,    /* ί���ٲû� */
    EXECUTION_FEP_SERVER    = 7,    /* �ɽ�ǰ�û� */
    QUOTATION_FEP_SERVER    = 8,    /* ����ǰ�û� */
    CLEAR_FEP_SERVER        = 9,    /* �е�ǰ�û� */
    MANAGE_SERVER           = 10,   /* �������� */
    MONITOR_SERVER          = 11,   /* ��ؽڵ� */
    URCOMM_SERVER           = 12,   /* ����ά��ת���� */
    DB2DBF_SERVER           = 13,   /* ��ʼ������ */
    DATAGATEWAY_SERVER      = 14    /* �������� */
};

//////////////////////////////////////////////////////////////////////////
///�����ڴ��ļ������궨���ʽ��ģ��_����
/// ����������ع����ڴ�
#define TS_MON_SHAREMEMKEY  "TS_MON_SHAREMEM"

/** �ɽ�ǰ�û���ع����ڴ����� */
#define REPCOMM_STATUS      "repcomm_status"
/**	����ά��ת���� */
#define URCOMM_MEMORY       "URCOMM_SHARE"

//////////////////////////////////////////////////////////////////////////
///Order type ���Ͷ���
#define OT_ORDER_TICKET                                 0   	/* 0��  ί������ */

#define OT_TRADING_FIRST                                1   	/* 1��  ��Сһ��������ָ���Ҫ�ڵ������¿�����ָ��ʱ���е��� */

#define OT_TRADING_START                                1   	/* 1��  ���� */
#define OT_TRADING_START_MATCH                          2   	/* 2��  ��ʼ��� */
#define OT_BIDDING_CLOSE                                3   	/* 3��  ���羺������ */
#define OT_BIDDING_OPEN                                 4   	/* 4��  ���羺�ۿ�ʼ */
#define OT_AFTER_HOURS                                  8   	/* 8��  �̺��׽׶ο�ʼ */
#define OT_TRADING_END                                  9   	/* 9��  ȫ����� */


#define OT_TRADING_LAST                                 9   	/* 9��  ���һ��������ָ���Ҫ�ڵ������Ͽ�����ָ��ʱ���е��� */

#define OT_TIMESLICE                                    40  	/* 40�� ʱ��Ƭָ�� */

#define ORDER_MATCH_BEGIN                               100    /* ���ָ����ʼֵ�����д��ָ������������Χ�� */


#define ORDER_PUBLIC_REST                               100     /* ��������ָ�� */

#define ORDER_PUBLIC_NO_STOCKCODE                       150     /* ��ָ��Ϊ�ڲ�ָ�����ʹ�ã����޴������ʱ�л�����ָ���*/
    

#define ORDER_CALLAUCTION_TOWNET_NOTISSUE               200 	/* ��������ɽ�������ָ�� */
#define ORDER_CALLAUCTION_TOWNET_ISSUE                  201 	/* ��������ɽ���ʱ����ָ�� */
#define ORDER_CALLAUCTION_TOWNET_ISSUE_REST             202  	/* ��������ɽ���ʱ��������������ָ�� */
#define ORDER_CALLAUCTION_TOWNET_CLOSE                  203  	/* �������м��Ͼ���ָ�� */
#define ORDER_CALLAUCTION_TOWNET_NOTHANG                204  	/* ���������ƽ׶� */

#define ORDER_CALLAUCTION_BID_REVOCABLE                 210		/* ����ת�ü��Ͼ��ۿɳ��׶�ָ�� */
#define ORDER_CALLAUCTION_BID_IRREVOCABLE               211		/* ����ת�ü��Ͼ��۲��ɳ��׶�ָ�� */
#define ORDER_CALLAUCTION_BID_OPEN 						212  	/* ����ת�ÿ��̼��Ͼ���ָ�� */
#define ORDER_CALLAUCTION_BID_CLOSE 					213  	/* ����ת�����м��Ͼ���ָ�� */


#define ORDER_BID_NOT_MATCH                             300     /* ����ת�ü��Ͼ��۲����  */
#define ORDER_BID_NO_WITHDRAW                           301     /* ����ת�ü��Ͼ��۲��ճ���9:20~9:25 14:55~15:00  */
#define ORDER_BIDDING_AUCTION_MATCH 					302 	/* ����ת�ü��Ͼ��۴��ָ�� */
#define ORDER_BIDDING_MATCH 						    303 	/* ����ת���������۴��ָ�� */
#define ORDER_BIDDING_AUCTION_MATCH_CLOSE   			304 	/* ����ת�ü��Ͼ��۴��ָ������ */


#define ORDER_MARKET_ISSUE 								400    	/* ����ת�����鷢��ָ�� */
#define ORDER_MARKET_MATCH 								401 	/* ����ת�ô��ָ�� */
#define ORDER_MARKET_TREATY_MATCH 						402   	/* ����ת��Э�齻��ָ���� */
#define ORDER_MARKET_CLOSE	 							403  	/* ����ת������ָ�� */


#define ORDER_TREATY_ISSUE  							500   	/* Э��ת�����鷢��ָ�� */
#define ORDER_TREATY_MATCH  							501   	/* Э��ת�ô��ָ�� */
#define ORDER_TREATY_FIX_MATCH_CLOSE                    502     /*Э��ת�ö����걨�Զ�ƥ��ָ�� */



#define ORDER_MATCH_END									600    /* ���ָ�����ֵ, ���д��ָ������������Χ�� */



#define OT_STOCK_ACC_URGENCY_MAINTAIN                   600050  /* 600050�� ֤ȯ�˻�����ά�� */
#define OT_STOCK_ACC_TRADE_LIMIT_URGENCY_MAINTAIN       600051  /* 600051�� ֤ȯ�˻��������ƽ���ά�� */
#define OT_STOCK_TRADE_PARAM_URGENCY_MAINTAIN           600052  /* 600052�� ֤ȯ���ײ�������ά�� */
#define OT_STOCK_BUSINESS_KIND_URGENCY_MAINTAIN         600053  /* 600053�� ֤ȯҵ��������ά�� */
#define OT_PLEDGED_REPO_BONDS_URGENCY_MAINTAIN          600054  /* 600054�� ��Ѻʽ�ع�ծȯ����ά�� */
#define OT_MARKETING_UNIT_TRADE_LIMIT_URGENCY_MAINTAIN  600055  /* 600055�� ���׵�Ԫ�������ƽ���ά�� */
#define OT_STOCK_TEMP_SUSPEND                           600060  /* 600060�� ֤ȯ��ʱͣ�� */
#define OT_STOCK_RESUMPTION                             600061  /* 600061�� ֤ȯ���� */
#define OT_MANUAL_CLOSING 								600098	/* 600098:  �ֹ����� */
#define OT_TEMP_CLOSE                                   600099  /* 600099:  ��ʱͣ�� */
#define OT_STOCKCODE_DUMP								600062  /* 600062�� ֤ȯ����dump����־�ļ��У����ڲ��Բ�������*/
#define OT_PUBLIC_INIT                                  800100 	/* 800100��QS��ʼ������ָ�� */
#define OT_PUBLIC_STOCKSNAP                             800101 	/* 800101��QS��ʾ�������ָ�� */
#define OT_PUBLIC_STOCKINFO                             800102 	/* 800102��QS��ʾ֤ȯ��Ϣָ�� */
#define OT_MARKET_CLOSE                                 800103	/* 800103��QS����ָ�� */
#define OT_MARKET_CLOSE2                                800104 	/* 800104��QS����ָ��2 */
#define OT_CLOSING_COMPLETE                             800105 	/* 800105��QS�������ָ�� */
#define OT_SYSTEM_START                                 800800 	/* 800800��QSϵͳ���� */
#define OT_STOCK_INFO                                   800801 	/* 800801��QS֤ȯ��Ϣ���� */
#define OT_QUOT_INFO                                    800802 	/* 800802��QS֤ȯ�������� */
#define OT_AGREEMENT_ORDER                              800803 	/* 800803��QSЭ�鶨���걨��Ϣ */
#define OT_AGREEMENT_PUBLIC_INFO                        800804 	/* 800804��QSЭ��ת�ù�����Ϣ */
#define OT_MARKET_PERSONAL_BUY_ORDER                    800805 	/* 800805��QS����ת��Ͷ�������걨��Ϣ �����ĸ������걨��Ϣ��������*/
#define OT_MARKET_PERSONAL_SALE_ORDER                   800806 	/* 800806��QS����ת��Ͷ�������걨��Ϣ */
#define OT_MARKET_MAKER_BUY_ORDER                       800807 	/* 800807��QS����ת�����������걨��Ϣ */
#define OT_MARKET_MAKER_SALE_ORDER                      800808 	/* 800808��QS����ת�����������걨��Ϣ */
#define OT_MARKET_PUBLIC_INFO                           800809 	/* 800809��QS����ת�ù�����Ϣ */
#define OT_MAKER_INFO                                   800810 	/* 800810��QS��������Ϣ */ 
#define OT_NORMAL_CONTRACT                              900900 	/* 900900�������ĳɽ� */
#define OT_VIRTUAL_CONTRACT                             900901 	/* 900901�����Ͼ�������ɽ� */

///v1.1�����޸�ǰ ���״��ģ���ڲ�ʹ��
//#define OT_END                      					99999999 /* 99999999����ʾ����ָ������ */
#define OT_AFTERHOURS_END                      				99999998 /* 99999998�����������������̺���ʱ�γɽ��󷢴�ָ�� */
#define OT_NORMALHOURS_END                      			99999999 /* 99999999�� ����������������������ʱ�γɽ��󷢴�ָ��*/


#endif
