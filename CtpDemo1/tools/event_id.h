///NEEQȫ���¼�����
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: event_id.h
����˵��:
��    ��: �����
��������: 2013-9-5   18:19:25
�޸ļ�¼:
***********************************************************************/
#ifndef _EVENT_ID_H_
#define _EVENT_ID_H_


//////////////////////////////////////////////////////////////////////////
/*                                                                      */
/* �¼��궨���ʽ�� ģ����_���󼶱�_����                                */
/*                                                                      */
//////////////////////////////////////////////////////////////////////////

///��ģ��ҵ��״̬ʱ��ŶΣ�800000-805000
enum BusinessSequenceEventId
{
    CTPDEMO1_DEBUG                   = 200000,   /**CTPDEMO1 debug output                        */
    /* �������� */
    TS_NOTICE_STATRTINIT             = 800000,   /**<TS��ʼ����ʼ                                */
    TS_NOTICE_FINISHINIT             = 800001,   /**<TS��ʼ�����                                */
    TS_CRIT_INITFAILED               = 800002,   /**<TS��ʼ��ʧ��                                */
    TS_NOTICE_STARTMARKET            = 800003,   /**<TS����                                      */
    TS_NOTICE_STARTMARKET_MATCH      = 800004,   /**<TS��ʼ���                                  */
    TS_NOTICE_LUNCHBREAK             = 800006,   /**<TS�������                                  */
    TS_NOTICE_STATRTMARKETAFTERNOON  = 800009,   /**<TS���翪��                                  */
    TS_NOTICE_AFTERHOURS             = 800010,   /**<TS�������+���Ͽ���                         */
    TS_NOTICE_CLOSEMARKET            = 800012,   /**<TSȫ�����                                  */
    TS_NOTICE_TREATY_ISSUE           = 800015,   /**<Э��ת�ÿ�ʼ�����걨  500                   */
    TS_NOTICE_TREATY_MATCH           = 800016,   /**<Э��ת�ÿ�ʼ������ϳɽ� 501                */
    TS_NOTICE_TREATY_REST            = 800017,   /**<Э��ת���������  100                       */
    TS_NOTICE_TREATY_MATCH_AFTERNOON = 800018,   /**<Э��ת������������翪��501                 */
    TS_NOTICE_TREATY_FIX_MATCH_CLOSE = 800019,   /**<Э��ת�����̶���ƥ��ɽ������� 502          */
    TS_NOTICE_TOWNET_NOTISSUE        = 800020,   /**<���������п�ʼ�����걨  200                 */
    TS_NOTICE_TWO_NET_REST           = 800021,   /**<�����������������    202                   */
    TS_NOTICE_TOWNET_NOTISSUE_AFTERNOON = 800022,   /**<�������������翪��   200                 */
    TS_NOTICE_TOWNET_CLOSE           = 800023,   /**<��������������        203                   */
    TS_NOTICE_MARKET_REST           = 800024,   /**<������������        100                   */

    TS_NOTICE_TRADEORDERCOUNT        = 802001,   /**<TS������ָ������                            */
    TS_NOTICE_E_ACCOUNT              = 802002,   /**<TS����֤ȯ�ʻ�����ά��ָ��                  */
    TS_NOTICE_E_ACCOUNT_RESTRICT     = 802003,   /**<TS����֤ȯ�˻��������ƽ���ά��ָ��          */
    TS_NOTICE_E_CONFIG               = 802004,   /**<TS����֤ȯ���ײ�������ά��ָ��              */
    TS_NOTICE_E_BUSITYPE             = 802005,   /**<TS����֤ȯҵ��������ά��ָ��              */
    TS_NOTICE_E_UNITNO               = 802006,   /**<TS���ս��׵�Ԫ�������ƽ���ά��ָ��          */
    TS_NOTICE_E_SUSPEND              = 802007,   /**<TS����֤ȯ��ʱͣ��ָ��                      */
    TS_NOTICE_E_RESUME               = 802008,   /**<TS����֤ȯ����ָ��                          */

    TS_NOTICE_LOADSTOCKTYPE          = 802009,   /**<���س�ʼ�����ݣ�֤ȯ��𣩳ɹ�                                       */
    TS_NOTICE_LOADSTOCKCODE          = 802010,   /**<���س�ʼ�����ݣ�֤ȯ���룩�ɹ�                                       */
    TS_NOTICE_LOADSTOCKHOLDER        = 802011,   /**<���س�ʼ�����ݣ�֤ȯ�ʻ����ɹ�                                       */
    TS_NOTICE_LOADUNITNO             = 802012,   /**<���س�ʼ�����ݣ����׵�Ԫ���ɹ�                                       */
    TS_NOTICE_ALLOWBUSITYPE          = 802013,   /**<���س�ʼ�����ݣ�֤ȯ����ҵ����𣩳ɹ�                               */
    TS_NOTICE_LOADTNFLAG             = 802014,   /**<���س�ʼ�����ݣ�֤ȯ����T+n��ʶ���ɹ�                                */
    TS_NOTICE_LOADSTOCK              = 802015,   /**<���س�ʼ�����ݣ�֤ȯ�ֲ���Ϣ���ɹ�                                   */
    TS_NOTICE_LOADUNITNORESTRICT     = 802016,   /**<���س�ʼ�����ݣ����׵�Ԫ���Ʊ��ɹ�                                 */
    TS_NOTICE_LOADACCPROPRESTRICT    = 802017,   /**<���س�ʼ�����ݣ��˻��������ƣ��ɹ�                                   */
    TS_NOTICE_LOADACCOUNTRESTRICT    = 802018,   /**<���س�ʼ�����ݣ�֤ȯ�˻����ƣ��ɹ�                                   */
    TS_NOTICE_LOADMAKERRESTRICT      = 802019,   /**<���س�ʼ�����ݣ��������ƣ��ɹ�                                       */
    TS_NOTICE_LOADFORBIDTIME         = 802020,   /**<���س�ʼ�����ݣ��걨��ֹҵ��ʱ�䣩�ɹ�                               */
    TS_NOTICE_LOADMATCHTIME          = 802021,   /**<���س�ʼ�����ݣ���Ͻ��׽׶�ʱ�����ã��ɹ�                           */
    TS_NOTICE_LOADDEFAULTSYSDATA     = 802022,   /**<���س�ʼ�����ݣ�֤ȯ�˻����ʣ����׵�Ԫ����Ĭ�Ͻ�ֹ�б����ã��ɹ�     */
    TS_NOTICE_LOADDATE               = 802023,   /**<���س�ʼ�����ݣ���ʼ�����ڣ��ɹ�                                     */


    TS_ERROR_LOADSTOCKTYPE        = 802024,      /**<���س�ʼ�����ݣ�֤ȯ���ʧ��                                       */
    TS_ERROR_LOADSTOCKCODE        = 802025,      /**<���س�ʼ�����ݣ�֤ȯ���룩ʧ��                                       */
    TS_ERROR_LOADSTOCKHOLDER      = 802026,      /**<���س�ʼ�����ݣ�֤ȯ�ʻ���ʧ��                                       */
    TS_ERROR_LOADUNITNO           = 802027,      /**<���س�ʼ�����ݣ����׵�Ԫ��ʧ��                                       */
    TS_ERROR_LOADALLOWBUSITYPE    = 802028,      /**<���س�ʼ�����ݣ�֤ȯ����ҵ�����ʧ��                               */
    TS_ERROR_LOADTNFLAG           = 802029,      /**<���س�ʼ�����ݣ�֤ȯ����T+n��ʶ��ʧ��                                */
    TS_ERROR_LOADSTOCK            = 802030,      /**<���س�ʼ�����ݣ�֤ȯ�ֲ���Ϣ��ʧ��                                   */
    TS_ERROR_LOADUNITNORESTRICT   = 802031,      /**<���س�ʼ�����ݣ����׵�Ԫ���Ʊ�ʧ��                                 */
    TS_ERROR_LOADACCPROPRESTRICT  = 802032,      /**<���س�ʼ�����ݣ��˻��������ƣ�ʧ��                                   */
    TS_ERROR_LOADACCRESTRICT      = 802033,      /**<���س�ʼ�����ݣ�֤ȯ�˻����ƣ�ʧ��                                   */
    TS_ERROR_LOADMAKERRESTRICT    = 802034,      /**<���س�ʼ�����ݣ��������ƣ�ʧ��                                       */
    TS_ERROR_LOADFORBIDTIME       = 802035,      /**<���س�ʼ�����ݣ��걨��ֹҵ��ʱ�䣩ʧ��                               */
    TS_ERROR_LOADMATCHTIME        = 802036,      /**<���س�ʼ�����ݣ���Ͻ��׽׶�ʱ�����ã�ʧ��                           */
    TS_ERROR_LOADDEFAULTSYSDATA   = 802037,      /**<���س�ʼ�����ݣ�֤ȯ�˻����ʣ����׵�Ԫ����Ĭ�Ͻ�ֹ�б����ã�ʧ��     */
    TS_ERROR_LOADDATE             = 802038,      /**<���س�ʼ�����ݣ���ʼ�����ڣ�ʧ��                                     */

    TS_WARNING_LOADSTOCKTYPEPARTLYFAILED        = 802039,   /**<���س�ʼ�����ݣ�֤ȯ��𣩲��ֳɹ�                                   */
    TS_WARNING_LOADSTOCKCODEPARTLYFAILED        = 802040,   /**<���س�ʼ�����ݣ�֤ȯ���룩���ֳɹ�                                   */
    TS_WARNING_LOADSTOCKACCPARTLYFAILED         = 802041,   /**<���س�ʼ�����ݣ�֤ȯ�ʻ������ֳɹ�                                   */
    TS_WARNING_LOADUNITNOPARTLYFAILED           = 802042,   /**<���س�ʼ�����ݣ����׵�Ԫ�����ֳɹ�                                   */
    TS_WARNING_LOADBUSITYPEPARTLYFAILED         = 802043,   /**<���س�ʼ�����ݣ�֤ȯ����ҵ����𣩲��ֳɹ�                           */
    TS_WARNING_LOADTNFLAGEPARTLYFAILED          = 802044,   /**<���س�ʼ�����ݣ�֤ȯ����T+n��ʶ�����ֳɹ�                            */
    TS_WARNING_LOADSTOCKPARTLYFAILED            = 802045,   /**<���س�ʼ�����ݣ�֤ȯ�ֲ���Ϣ�����ֳɹ�                               */
    TS_WARNING_LOADUNITNORESTRICTPARTLYFAILED   = 802046,   /**<���س�ʼ�����ݣ����׵�Ԫ���Ʊ����ֳɹ�                             */
    TS_WARNING_LOADACCPROPRESTRICTARTLYFAILED   = 802047,   /**<���س�ʼ�����ݣ��˻��������ƣ����ֳɹ�                               */
    TS_WARNING_LOADACCRESTRICTPARTLYFAILED      = 802048,   /**<���س�ʼ�����ݣ�֤ȯ�˻����ƣ����ֳɹ�                               */
    TS_WARNING_LOADMAKERRESTRICTPARTLYFAILED    = 802049,   /**<���س�ʼ�����ݣ��������ƣ����ֳɹ�                                   */
    TS_WARNING_LOADFORBIDTIMEPARTLYFAILED       = 802050,   /**<���س�ʼ�����ݣ��걨��ֹҵ��ʱ�䣩���ֳɹ�                           */
    TS_WARNING_LOADMATCHTIMEPARTLYFAILED        = 802051,   /**<���س�ʼ�����ݣ���Ͻ��׽׶�ʱ�����ã����ֳɹ�                       */
    TS_WARNING_LOADDEFAULTSYSDATAPARTLYFAILED   = 802052,   /**<���س�ʼ�����ݣ�֤ȯ�˻����ʣ����׵�Ԫ����Ĭ�Ͻ�ֹ�б����ã����ֳɹ� */

    TS_NOTICE_TEMP_CLOSE            = 802053,   /**<TS��ʱ����ָ��                         */
    TS_NOTICE_MANUAL_CLOSING        = 802054,   /**<TS�ֹ�����                         */
    TS_NOTICE_TOWNET_ISSUE           = 802055,   /**<��������ɽ���ʱ����ָ��        201                   */
    TS_NOTICE_MARKET_ISSUE          = 802056,   /**<����ת�����鷢��       400                   */
    TS_NOTICE_MARKET_MATCH          = 802057,   /**<����ת�ô�Ͽ�ʼ       401                   */
    TS_NOTICE_MARKET_CLOSE          = 802058,   /**<����ת������       403                   */

    /* �������� */

    /* �ɽ�ǰ�û� */
    REPC_NOTICE_INIT_BEGIN              = 800401,	/**< �ɽ�ǰ�û���ʼ����ʼ */
    REPC_NOTICE_INIT_END                = 800402,	/**< �ɽ�ǰ�û���ʼ������ */
    REPC_CRIT_INIT_FAIL                 = 800403,	/**< �ɽ�ǰ�û���ʼ��ʧ�� */
    REPC_NOTICE_WORK_NORMAL             = 800404,	/**< �ɽ�ǰ�û����������� */
    REPC_CRIT_WORK_INNORMAL             = 800405,	/**< �ɽ�ǰ�û����������� */

    /* ����ǰ�û� */

    /* ί��ǰ�û� */

    /* ί���Ŷӻ� */

    /* ί���ٲû� */

    /* �е�ǰ�û� */
    CCOMM_NOTICE_INIT_BEGIN                = 800651,   //��ʼ��ʼ��,
    CCOMM_NOTICE_INIT_OK                   = 800652,   // ��ʼ���ɹ�
    CCOMM_CRIT_INIT_FAIL                   = 800653,   // ��ʼ��ʧ��
    CCOMM_NOTICE_WORK_NORMAL               = 800654,   // ����������
    CCOMM_CRIT_WORK_ERROR                  = 800655,   // ����������
    CCOMM_NOTICE_JYZHXX_OK                 = 800656,   //�����ۺ���Ϣ�ѷ���
    CCOMM_NOTICE_STATIC_PUT                = 800657,   //�ѿ�ʼ�����е�����
    CCOMM_CRIT_INITFILE_ERROR              = 802701,   //��ʼ���ļ�ʧ��
    CCOMM_NOTICE_INITFILE_OK               = 802702,   //��ʼ���ļ��ɹ�
    CCOMM_NOTICE_IV_OPEN                   = 802704,   //��IV�ļ�
    CCOMM_NOTICE_IB_OPEN                   = 802705,   //��IB�ļ�
    CCOMM_NOTICE_SG_OPEN                   = 802706,   //��SG�ļ�
    CCOMM_NOTICE_GF_OPEN                   = 802707,   //��GF�ļ�
    CCOMM_NOTICE_GC_OPEN                   = 802708,   //��GC�ļ�
    CCOMM_NOTICE_MX_OPEN                   = 802709,   //��MX�ļ�
    CCOMM_NOTICE_MC_OPEN                   = 802710,   //��MC�ļ�
    CCOMM_NOTICE_CC_OPEN                   = 802711,   //��CC�ļ�
    CCOMM_NOTICE_TD_OPEN                   = 802712,   //��TD�ļ�
    CCOMM_NOTICE_XW_OPEN                   = 802713,   //��XW�ļ�
    CCOMM_NOTICE_ZH_OPEN                   = 802714,   //��ZH�ļ�
    CCOMM_NOTICE_IV_OK                     = 802715,   //IV�ļ����ճɹ�
    CCOMM_NOTICE_IB_OK                     = 802716,   //IB�ļ����ճɹ�
    CCOMM_NOTICE_SG_OK                     = 802717,   //SG�ļ����ճɹ�
    CCOMM_NOTICE_GF_OK                     = 802718,   //GF�ļ����ճɹ�
    CCOMM_NOTICE_GC_OK                     = 802719,   //GC�ļ����ճɹ�
    CCOMM_NOTICE_MX_OK                     = 802720,   //MX�ļ����ճɹ�
    CCOMM_NOTICE_MC_OK                     = 802721,   //MC�ļ����ճɹ�
    CCOMM_NOTICE_CC_OK                     = 802722,   //CC�ļ����ճɹ�
    CCOMM_NOTICE_TD_OK                     = 802723,   //TD�ļ����ճɹ�
    CCOMM_NOTICE_XW_OK                     = 802724,   //XW�ļ����ճɹ�
    CCOMM_NOTICE_ZH_OK                     = 802725,   //ZH�ļ����ճɹ�
    
    
    /* �������� */
    DATAGATEWAY_NOTICE_INIT_BEGIN       = 800701,   /* �������س�ʼ����ʼ */
    DATAGATEWAY_NOTICE_INIT_END         = 800702,   /* �������س�ʼ����� */
    DATAGATEWAY_CRIT_INIT_FAILED        = 800703,   /* �������س�ʼ��ʧ�� */
    DATAGATEWAY_NOTICE_WORK_NORMAL      = 800704,   /* ������������������ */
    DATAGATEWAY_CRIT_WORK_ABNORMAL      = 800705,   /* �������ط��������� */

    /* ����ά��ת���� */
    URC_NOTICE_INIT_START  	    = 800751, ////	����ά��ת������ʼ����ʼ
    URC_NOTICE_INIT_FINISH 	    = 800752, ////	����ά��ת������ʼ�����
    URC_CRIT_INIT_FAILED 	    = 800753, ////	����ά��ת������ʼ��ʧ��
    URC_NOT_WORKING_OK 		    = 800754, ////	����ά��ת��������������
    URC_CRIT_WORK_ERR 		    = 800755,  ////	����ά��ת��������������
    /* ��ط��� */

    /* ��ʼ������ */
    DB2DBF_NOTICE_INIT_BEGIN            = 800901,   /* ��ʼ�����񣺳�ʼ����ʼ */
    DB2DBF_NOTICE_INIT_END              = 800902,   /* ��ʼ�����񣺳�ʼ����� */
    DB2DBF_CRIT_INIT_FAILED             = 800903,   /* ��ʼ�����񣺳�ʼ��ʧ�� */
    DB2DBF_NOTICE_DUMP_BEGIN            = 800904,   /* ��ʼ���������ݵ�����ʼ */
    DB2DBF_NOTICE_DUMP_END              = 800905,   /* ��ʼ���������ݵ������ */
    DB2DBF_CRIT_DUMP_FAILED             = 800906    /* ��ʼ���������ݵ���ʧ�� */
};



///����ģ�飺919000-919999
enum CommonEventId
{
    ERR_NONE                        = 0,        /* �ɹ� */

    COMMON_EVENT_ID_START           = 919000,   /* ���������뿪ʼ */

    /* main���¼����� */
    COMMON_ERROR_MAIN_CORE_DUMP     = 919100,   /* main��coredump�¼� */

    /* ���������� */
    COMMON_ERROR_READ_CONFIG_FAILED = 919900,   /* ��ȡ������ʧ�� */
    COMMON_ERROR_NEW_MEMORY_FAILED  = 919901,   /* �����ڴ�ʧ�� */
    COMMON_ERROR_OPEN_QUEUE         = 919902,   /* �򿪶���ʧ�� */
    COMMON_ERROR_CREATE_SHM         = 919903,   /* ���������ڴ�ʧ�� */
    COMMON_ERROR_SHM_MMAP           = 919904,   /* MMAP�����ڴ�ʧ�� */
    COMMON_ERROR_OPEN_SHM           = 919905,   /* �򿪹����ڴ�ʧ�� */
    COMMON_ERROR_SHM_FSTAT          = 919906,   /* FSTAT�����ڴ�ʧ��  */
    COMMON_ERROR_OPEN_SEM           = 919907,   /* ���ź���ʧ�� */
    COMMON_ERROR_POST_SEM           = 919908,   /* POST �ź���ʧ�� */
    COMMON_ERROR_WAIT_SEM           = 919909,   /* WAIT �ź���ʧ�� */
    COMMON_ERROR_TIME_WAIT_SEM      = 919910,   /* TIME WAIT�ź���ʧ�� */
    COMMON_ERROR_TRY_WAIT_SEM       = 919911,   /* TRY WAIT�ź���ʧ�� */
    COMMON_ERROR_GET_SEM_VALUE      = 919912,   /* ��ȡ�ź���ֵʧ��  */
    COMMON_ERROR_CLOSE_SEM          = 919913,   /* �ر��ź���ʧ�� */
    COMMON_ERROR_REMOVE_SEM         = 919914,   /* ɾ���ź���ʧ�� */





    COMMON_EVENT_ID_END             = 919999    /* ������������� */
};

///��ʼ������925000-929999
enum InitialServiceEventId
{
    DB2DBF_EVENT_ID_START               = 925000,   /* ��ʼ����������뿪ʼ */

    DB2DBF_ERROR_INIT_DB_FAILED         = 925001,   /* ��ʼ�����ݿ�ʧ�� */
    DB2DBF_ERROR_CREATE_DB_OBJ_FAILED   = 925002,   /* �������ݿ����ʧ�� */
    DB2DBF_INFO_TRANSFER_BEGIN          = 925003,   /* ת�����ݿ�ʼ */
    DB2DBF_ERROR_CONNECT_DB_FAILED      = 925004,   /* �������ݿ�ʧ�� */
    DB2DBF_ERROR_EXECUTE_SQL_FAILED     = 925005,   /* ִ��SQL���ʧ�� */
    DB2DBF_ERROR_SQL_SYNTAX_ERROR       = 925006,   /* SQL����﷨���� */
    DB2DBF_ERROR_CREATE_DBF_FAILED      = 925007,   /* ����DBF�ļ�ʧ�� */
    DB2DBF_ERROR_MAP_FIELD_FAILED       = 925008,   /* ���ݿ��ֶ�ת����DBF�ֶ�ʧ�� */
    DB2DBF_ERROR_ADD_FIELD_FAILED       = 925009,   /* ����DBF�ֶ�ʧ�� */
    DB2DBF_ERROR_OPEN_DBF_FAILED        = 925010,   /* ��DBF�ļ�ʧ�� */
    DB2DBF_ERROR_APPEND_FAILED          = 925011,   /* ��������ģʽʧ�� */
    DB2DBF_ERROR_SET_VALUE_FAILED       = 925012,   /* �����ֶ�ֵʧ�� */
    DB2DBF_ERROR_POST_FAILED            = 925013,   /* DBF�ύʧ�� */
    DB2DBF_ERROR_APPEND_NEXT_FAILED     = 925014,   /* ������һ��ʧ�� */
    DB2DBF_INFO_TRANSFER_FINISH         = 925015,   /* ת�����ݽ��� */

    DB2DBF_EVENT_ID_END                 = 929999    /* ��ʼ�������������� */
};

///��ط���930000-934999
enum MonProxyEventId
{
    MONPROXY_ERR_NOSHAREDMEMERRNO        =  931000,  /* �޷����ع����ڴ� */
    MONPROXY_CRIT_PROCESSSTOPERRNO       =  931001,  /* ����ֹͣ */
    MONPROXY_ERR_SRVTYPEDIF              =  931002,  /* �����ڴ��������ļ��е��������Ͳ�ͬ */
    MONPROXY_ERR_SRVIDDIF                =  931003,  /* �����ڴ��������ļ��е�������ʶ��ͬ */
    MONPROXY_ERR_FILESIZEDIF             =  931004,  /* �����ļ���С��ṹ��С��һ��*/
    MONPROXY_ERR_NOTEXISTPROC            =  931005,  /* �ڹ����ļ���û�л�ý���PID*/

    //liwh 20141030
    MONPROXY_ERR_NASDIRNOTFOUND          =  931006,  /* Nas dir not found*/
    MONPROXY_ERR_NASSPACEEXCEEDTHRESHOLD =  931007   /* Nas space exceed threshold*/
};

///���������935000-939999


///����ά��ת�����¼���940000-944999
enum UrcommEventId
{
    URCOMM_NOTICE_SUSPEND_SUCC      = 802801, ///����ͣ��ָ��ɹ�����
    URCOMM_NOTICE_SUSPEND_FAIL      = 802802, ///����ͣ��ָ��ʧ������
    URCOMM_NOTICE_RESUM_SUCC        = 802803, ///���͸���ָ��ɹ�����
    URCOMM_NOTICE_RESUM_FAIL        = 802804, ///���͸���ָ��ʧ������
    URCOMM_NOTICE_HOLDER_SUCC       = 802805, ///����֤ȯ�˻�����ά��ָ��ɹ�����
    URCOMM_NOTICE_HOLDER_FAIL       = 802806, ///����֤ȯ�˻�����ά��ָ��ʧ������
    URCOMM_NOTICE_HOLDERLIMIT_SUCC  = 802807, ///����֤ȯ�˻��������ƽ���ά��ָ��ɹ�����
    URCOMM_NOTICE_HOLDERLIMIT_FAIL  = 802808, ///����֤ȯ�˻��������ƽ���ά��ָ��ʧ������
    URCOMM_NOTICE_STOCKEMERG_SUCC   = 802809, ///����֤ȯ���ײ�������ά��ָ��ɹ�����
    URCOMM_NOTICE_STOCKEMERG_FAIL   = 802810, ///����֤ȯ���ײ�������ά��ָ��ʧ������
    URCOMM_NOTICE_STOCKLIMIT_SUCC   = 802811, ///����֤ȯҵ��������ά��ָ��ɹ�����
    URCOMM_NOTICE_STOCKLIMIT_FAIL   = 802812, ///����֤ȯҵ��������ά��ָ��ʧ������
    URCOMM_NOTICE_BOND_SUCC         = 802813, ///������Ѻʽ�ع�ծȯ����ά��ָ��ɹ�����
    URCOMM_NOTICE_BOND_FAIL         = 802814, ///������Ѻʽ�ع�ծȯ����ά��ָ��ʧ������
    URCOMM_NOTICE_BROKERNOLIMIT_SUCC = 802815, ///���ͽ��׵�Ԫ�������ƽ���ά��ָ��ɹ�����
    URCOMM_NOTICE_BROKERNOLIMIT_FAIL = 802816, ///���ͽ��׵�Ԫ�������ƽ���ά��ָ��ʧ������
    URCOMM_NOTICE_MANUAL_CLOSING_FAIL= 802817, /// �����ֹ�����ָ��ʧ��
    URCOMM_NOTICE_TEMP_CLOSE_FAIL    = 802818, /// ������ʱͣ��ָ��ʧ��
    URCOMM_NOTICE_MANUAL_CLOSING_SUCC= 802819, /// �����ֹ�����ָ��ɹ�
    URCOMM_NOTICE_TEMP_CLOSE_SUCC    = 802820, /// ������ʱͣ��ָ��ɹ�
    URCOMM_WAR_NO_LINK               = 802821, /// û����Ч�Ŷӻ�����
    URCOMM_WAR_VALID_LINK            = 802822, /// ����Ч���Ŷӻ�����

	URCOMM_ERR_NEW_NET				= 940001, /// ����ģ�鴴��ʧ��
	URCOMM_ERR_INIT_NET				= 940002, /// ����ģ���ʼ��ʧ��
	URCOMM_ERR_NEW_RM				= 940005, /// �鲥ģ�鴴��ʧ��
	URCOMM_ERR_INIT_RM				= 940006, /// �鲥ģ���ʼ��ʧ��
	URCOMM_INFO_WORK_CLOSE          = 940007, /// ����ά������ر�
	URCOMM_ERR_DATA_GET             = 940010, /// ��������ʧ��
	URCOMM_ERR_DATA_SEND            = 940011, /// ��������ʧ��
	URCOMM_ERR_DATA_UPDATE          = 940012, /// �����걨״̬ʧ��
	URCOMM_ERR_GET_ORDER            = 940014, /// ��ȡָ��ʧ��
	URCOMM_ERR_RM_NEW               = 940015, /// �����鲥����ʵ��ʧ��

	URCOMM_ERR_RM_CREATE            = 940017, /// ��ʼ���鲥����ʵ��ʧ��
	URCOMM_ERR_RM_START             = 940018, /// �����鲥������ʧ��
	URCOMM_ERR_RM_STOCKINFO         = 940020, /// �鲥ģ�����֤ȯ��Ϣ��ʧ��
	URCOMM_ERR_RM_UPDATE            = 940021, /// �鲥ģ�����ָ��ִ�н��ʧ��
	URCOMM_ERR_INIT_SM		        = 940022, /// �����ڴ��ʼ��ʧ��
	URCOMM_ERR_DBSTR		        = 940023, /// ���ݿ����Ӵ�Ϊ��


	URCOMM_ERR_INVALID_IP           = 940026, /// ��Чip��ַ����ip���������ļ���
	URCOMM_ERR_RM_INIT_PARAM        = 940027, /// �鲥�����пյ�
	URCOMM_ERR_RM_STOP              = 940028, /// �鲥ģ��ֹͣʧ��


	URCOMM_ERR_RM_CREAT_FILE		= 940031, /// �����鲥�����ļ�ʧ��

    URCOMM_ERR_CONFIG_RM_FILE       = 940033, /// �鲥�����ļ���������ΪNULL
    URCOMM_ERR_DB_CTX               = 940034, /// ��ȡ���ݿ�������ʧ��
    URCOMM_WAR_NET_TIMEOUT          = 940035, /// �������ӳ�ʱ���Զ��Ͽ�
    URCOMM_NET_INVALID_ARG          = 940036, /// ���������OnErrorʹ��
    URCOMM_ERR_DIS_LINK             = 940037, /// �������ӶϿ�ʧ��
    URCOMM_ERR_NET_ONERROR          = 940038, /// ����ײ���ִ���
    URCOMM_ERR_DATA_COUNT           = 940039, /// ��ȡָ������ʧ��
    URCOMM_ERR_DATA_COUNT_LESS      = 940040, /// ָ������С���Ŷӻ���������
    URCOMM_ERR_IP_NULL              = 940041, /// ���ip��˿�Ϊnull

    URCOMM_ERR_ACCEPTOR_NULL        = 940043, /// ������ΪNULL
    URCOMM_ERR_NET_NULL_IP          = 940044, /// ����ipΪ�գ���鿴�����ļ�
    URCOMM_ERR_SHAREDATA_NULL       = 940045, /// m_lpMonData is null
    URCOMM_ERR_WRONG_STATUS         = 940046, /// ����ͨ��״̬��һ��


    URCOMM_ERR_SOCK_INDEX_MISMATCH  = 940049, /// socket������ƥ��
    URCOMM_ERR_DISCONNECT           = 940050, /// �Ͽ����Ӵ���
    URCOMM_INFO_ON_DISCONNECT       = 940051, /// �ص��Ͽ�����
    URCOMM_ERR_NO_ACK               = 940052, /// û��ack,���������Զ��Ͽ�
    URCOMM_ERR_START_NET            = 940053, /// ��������ʧ��
    URCOMM_ERR_DB_CLOSE             = 940054, /// �Ͽ����ݿ�����ʧ��
    URCOMM_ERR_RM_FILE_CLOSE        = 940055, /// �ͷ�ӳ���ļ��ڴ�ʧ��
    URCOMM_ERR_SEND_ARRAYINDEX      = 940056, /// �����������ݵ������Ƿ�
    URCOMM_ERR_COMM_STATUS          = 940057, /// ����ͨ��״̬�Ƿ�
    URC_ERR_RM_ONERROR              = 940058, /// �鲥����
    URC_WAR_SVR_STATUS              = 940059, /// ������״̬û��׼����
    URCOMM_ERR_OBJ_NULL             = 940060, /// ��������ΪNULL
    URCOMM_ERR_CONNECT              = 940061, /// ����NEEQ_CONNECTʧ��
    URCOMM_ERR_SEQNO                = 940062, /// ����NEEQ_SEQNOʧ��
    URCOMM_ERR_WAIT_TIME            = 940063, /// wait_time���ô���
    URCOMM_ERR_LINK_TIME            = 940064, /// link_time���ô���
};

///���������¼���945000-949999
enum DataGatewayEventId
{
    DATAGATEWAY_EVENT_ID_START          = 945000,   /* �������ش����뿪ʼ */

    DATAGATEWAY_ERROR_WRITEMSG_FAILED   = 945001,   /* д����ļ�ʧ�� */
    DATAGATEWAY_ERROR_RM_ERROR          = 945002,   /* �鲥�������Ϣ */
    DATAGATEWAY_ERROR_INVALID_LENGTH    = 945003,   /* ���յ���Ϣ���ȷǷ� */

    DATAGATEWAY_EVENT_ID_END            = 949999    /* �������ش�������� */
};

///�е�ǰ�û��¼���950000-954999
enum CcommEventId
{
    CCOMM_INFO_NORMAL_MSG                = 950000,   // ��������Ϣ
    CCOMM_WARN_INIT_WARN                 = 950103,   // ��ʼ��ʱ���־���
    CCOMM_WARN_RM_WARN                   = 950100,   // �鲥��ؾ���
    CCOMM_INFO_RM_MSG                    = 950101,   // �鲥ģ�������Ϣ
    CCOMM_ERROR_RM_ERROR                 = 950102,   // �鲥ģ�����
    CCOMM_INFO_TCP_MSG                   = 950201,   // tcp�������Ϣ
    CCOMM_ERROR_TCP_ERROR                = 950202,   // tcp��ײ����
    CCOMM_WARN_CC_WARN                   = 950300,   // �е�ͨѶ����
    CCOMM_INFO_CC_MSG                    = 950301,   // �е�ͨ�������Ϣ
    CCOMM_ERROR_CC_ERROR                 = 950302,   // �е�ͨ����ش���(Ӧ�ò����)
    CCOMM_ERROR_CC_FILE_SYNC             = 950304,   // ���Ͷϵ�ͬ����
    CCOMM_ERROR_CC_DATA_ERROR            = 950306,   // ���ݳ���
    CCOMM_ERROR_CC_VERIFY_ERROR          = 950308,   // ���ݰ��������
    CCOMM_ERROR_DBFFILE_ERROR            = 950402,   // DBF�ļ���������
    CCOMM_ERROR_OKFILE_ERROR             = 950404,   // OK�ļ���������
    CCOMM_ERROR_DAYEND_ERROR             = 950408,	// ���ռ�����
    CCOMM_ERROR_NO_CONNECTION            = 950409,  //�ѿ��е��е�δ����
    CCOMM_ERROR_DISCONNECTED             = 950410,  //�����ڼ�ɽ��������ӶϿ�
};

///ί���ٲû��¼���955000-959999
enum ARBEventId
{
    ARB_NOTICE_START_INIT              = 800601,    //�ٲû���ʼ��ʼ��
    ARB_NOTICE_INIT_OK                 = 800602,    //��ʼ���ɹ�
    ARB_CRIT_INIT_FAIL                 = 800603,    //��ʼ��ʧ��
    ARB_NOTICE_IN_WORKING              = 800604,    //������
    ARB_NOTICE_OUT_OF_WORKING          = 800605,    //������������

    ARB_NOTICE_LOAD_CONFIG             = 803301,    //װ�����ò���
    ARB_ERROR_LOAD_CONFIG_FAILED       = 803302,    //װ�����ò���ʧ��
    ARB_NOTICE_START_TCP_SERVER        = 803303,    //����TCP SERVER
    ARB_ERROR_START_TCP_SERVER_FAILED  = 803304,    //����TCP SERVERʧ��
    ARB_NOTICE_INIT_MON_DATA           = 803305,    //��ʼ����������
    ARB_NOTICE_START_TCP_SERVER_OK     = 803306,    //����ABNET TCP SERVER�ɹ�

    ARB_RUN_LOG                        = 955001,    //�ٲû�DEBUG��INFO�µ�log
    ARB_ERROR_ALLOCATE_OBJECT          = 955002,    //�ٲû�ALLOCATE����ʧ��
    ARB_ERROR_CONFIG_PARAMTER          = 955003,    //�ٲû������ļ�������
    ARB_ERROR_START_TCP_SERVER         = 955004,    //�ٲû�����TCP SERVERʧ��
    ARB_WARNING_TCP_DISCONNECTED       = 955005,    //���ٲô���TCP���ӶϿ�
    ARB_WARNING_LOST_ACD_CONNECTION    = 955006,    //ʧȥ���ٲô����TCP����
    ARB_WARNING_UNKNOWN_MSG            = 955007,    //���յ��Ƿ����͵���Ϣ
    ARB_WARNING_TCP_ERROR              = 955008,    //������TCP���ӳ���
    ARB_ERROR_ILLEGAL_SOCKET_INDEX     = 955009,    //�Ƿ���SOCKET_INDEX.
    ARB_ERROR_ACD_NO_RESPONSE          = 955010,    //�Ŷӻ��ڵ�λʱ��������Ӧ
    ARB_WARNING_ACTION_TYPE            = 955011,    //ACTION���ͳ���
    ARB_WARNING_SEND_DATA              = 955012,    //����TCP ����ʧ��
    ARB_WARNING_EVENT_ID               = 955013,    //���յ��Ƿ����¼�
    ARB_WARNING_ACD_ID                 = 955014,    //�Ŷӻ�ID�Ƿ�
    ARB_WARNING_STATUS_CHANGE          = 955015,    //�Ŷӻ�״̬�ı�
    ARB_CRIT_ACD_STATUS                = 955016,    //�Ŷӻ�����״̬����ȷ
    ARB_ERROR_OPEN_FILE                = 955017,    //���Ŷӻ�״̬�����ļ�ʧ
    ARB_WARNNING_GET_EVENT             = 955018,    //�Ŷӻ��յ��¼���Ϣ
    ARB_WARNING_NO_ACD_USABLE          = 955019,    //�����Ŷӻ���������
    ARB_ERROR_CREATE_TIMER             = 955020,    //������ʱ��ʧ��

};

///ί���Ŷӻ��¼���960000-964999
enum AcdEventId
{
    ACD_NOTICE_INIT_START               = 800551,  // �Ŷӻ���ʼ����ʼ
    ACD_NOTICE_INIT_COMPLETE            = 800552,  // �Ŷӻ���ʼ�����
    ACD_CRIT_INIT_FAIL                  = 800553,  // �Ŷӻ���ʼ��ʧ��
    ACD_NOTICE_IN_WORKING               = 800554,  // �Ŷӻ�����������
    ACD_ERROR_OUT_OF_WORKING            = 800555,  // �Ŷӻ�����������

    ACD_NOTICE_INIT_INDEX_SHM           = 803001,  // ��ʼ���Ŷӻ��ڴ�ָ�빲���ڴ�
    ACD_NOTICE_INIT_STAT_SHM            = 803002,  // ��ʼ��ͳ����Ϣ�����ڴ�
    ACD_NOTICE_INIT_TRADE_INFO_SHM      = 803003,  // ��ʼ��������Ϣ�����ڴ�
    ACD_NOTICE_INIT_LINK_STATUS_SHM     = 803004,  // ��ʼ��LINK״̬�����ڴ�
    ACD_NOTICE_INIT_ORDER_SHM           = 803005,  // ��ʼ��ί�е������ڴ�
    ACD_NOTICE_INIT_MODULE_INFO_SHM     = 803006,  // ��ʼ��ģ����Ϣ�����ڴ�
    ACD_NOTICE_INIT_SHM_OK              = 803007,  // �����ڴ��ʼ���ɹ�
    ACD_NOTICE_INIT_MON_DATA            = 803008,  // ��ʼ�������Ϣ
    ACD_NOTICE_INIT_MON_DATA_OK         = 803009,  // ��ʼ�������Ϣ�ɹ�
    ACD_ERROR_LOAD_ORDER                = 803010,  // ��ί�е������ļ���
                                                   // װ��ί�е�ʧ��
    ACD_NOTICE_START_PROXY              = 803011,  // ׼�������ٲô���
    ACD_NOTICE_LOAD_CONFIG              = 803012,  // װ�����ò���
    ACD_NOTCIE_LOAD_CONFIG_FAILED       = 803013,  // װ�����ò���ʧ��
    ACD_NOTCIE_LOAD_CONFIG_OK           = 803014,  // װ�����ò����ɹ�
    ACD_NOTICE_CONNECT_ARB              = 803015,  // �����ٲ÷�����
    ACD_NOTICE_CONNECT_ARB_OK           = 803016,  // �����ٲ÷������ɹ�
    ACD_NOTICE_CONNECT_ARB_FAILED       = 803017,  // �����ٲ÷�����ʧ��
    ACD_NOTICE_GET_STATUS               = 803018,  // ��ȡ�Ŷӻ�������״̬
    ACD_NOTICE_GET_STATUS_OK            = 803019,  // ��ȡ�Ŷӻ�׼����״̬�ɹ�
    ACD_NOTICE_START_PROCESS            = 803020,  // ����ҵ�����
    ACD_NOTICE_START_PROCESS_OK         = 803021,  // ҵ����������ɹ�
    ACD_NOTICE_START_PROCESS_FAILED     = 803022,  // ҵ���������ʧ��
    ACD_NOTICE_GOES_INTO_SERVICE        = 803023,  // �Ŷӻ�����ҵ����״̬

    DISPATCH_DEBUG_QUEUE_PACKAGE        = 960001,       // �յ�QUEUE�е����ݰ�
    DISPATCH_DEBUG_TCP_PACKAGE          = 960002,       // �յ�TCP���ݰ�
    DISPATCH_DEBUG_RECEIVE_IDLE         = 960003,       // ���յ��������ݰ�
    DISPATCH_DEBUG_ON_HEART             = 960004,       // TCP�����¼�
    DISPATCH_NOTICE_LINK                = 960005,       // LINK�����
    DISPATCH_NOTICE_EXIT                = 960006,       // ģ���˳�����
    DISPATCH_NOTICE_CONNECT             = 960007,       // TCP�ͻ������ӷ������ɹ�
    DISPATCH_WARNING_PACKAGE_LENGTH     = 960008,       // ���ݰ����ȴ���
    DISPATCH_WARNING_SET_TCP_PARAM      = 960009,       // ����TCP����ʧ��
    DISPATCH_WARNING_CLOSE              = 960010,       // �ر�TCP����
    DISPATCH_WARNING_RECEIVE_UNKNOWN    = 960011,       // ���յ�����ʶ�����͵����ݰ�
    DISPATCH_WARNING_TIME_OUT           = 960012,       // TCP TIMEOUT�¼�
    DISPATCH_WARNING_LINK_STATUS        = 960013,       // LINK״̬���󣬵�ǰ���ڴ���ί��
    DISPATCH_WARNING_CONNECTION_INVALID = 960014,       // ��Ч����·��TCP����
    DISPATCH_ERROR_LINK_LENGTH          = 960015,       // LINK ID֪ͨ�У����ȴ���
    DISPATCH_ERROR_PROCESS_ID           = 960016,       // PROCESS ID����
    DISPATCH_ERROR_INIT_THREAD          = 960017,       // �̳߳�ʼ��ʧ��
    DISPATCH_ERROR_INIT_TCP             = 960018,       // TCP��ʼ��ʧ��
    DISPATCH_ERROR_CONFIG               = 960019,       // ���ü���ʧ��
    DISPATCH_ERROR_CONNECT              = 960020,       // ����ǰ�û����߽���ָ�����ʧ��
    DISPATCH_ERROR_QUEUE_WRITE          = 960021,       // д��QUEUEʧ��
    DISPATCH_ERROR_QUEUE_READ           = 960022,       // ��ȡQUEUEʧ��
    DISPATCH_ERROR_TCP_SEND             = 960023,       // TCP��������ʧ��
    DISPATCH_ERROR_TCP_RECONNECT        = 960024,       // TCP������ʧ��
    DISPATCH_ERROR_TCP_MES              = 960025,       // TCP ERROR�¼�
    DISPATCH_ERROR_START_TIMER          = 960026,       // ���ü�ʱ��ʧ��
    DISPATCH_ERROR_TCP_ALL_DISCONNECT   = 960027,       // ����TCP���ӶϿ�
    DISPATCH_ERROR_CREATE_TIMER         = 960028,       // ����������ʱ��ʧ��
    DISPATCH_WARNING_DISCARD_ORDERS     = 960029,       // ����ί�е�����

    HANDLER_DEBUG_QUEUE_PACKAGE         = 960501,       // �յ������е����ݰ�
    HANDLER_DEBUG_SHM_INDEX             = 960502,       // ���¹����ڴ��е�ί��ָ��
    HANDLER_DEBUG_RM_SEMAPHORE          = 960503,       // ֪ͨ�鲥ģ�鿪ʼ�鲥
    HANDLER_DEBUG_SYNC_SEMAPHORE        = 960504,       // ֪ͨͬ��ģ�鿪ʼͬ��
    HANDLER_DEBUG_ORDER_ACK             = 960505,       // �ظ�ORDER ACK
    HANDLER_INFO_IGNORE_PACKAGE         = 960506,       // ʱ���ʼ��ǰ�����Զ����е����ݰ�
    HANDLER_NOTICE_EXIT                 = 960507,       // ģ���˳�����
    HANDLER_ERROR_PROCESS_ID            = 960508,       // PROCESS ID����
    HANDLER_ERROR_INIT_THREAD           = 960509,       // �̳߳�ʼ��ʧ��
    HANDLER_ERROR_QUEUE_WRITE           = 960510,       // д��QUEUEʧ��
    HANDLER_ERROR_QUEUE_READ            = 960511,       // ��ȡQUEUEʧ��
    HANDLER_ERROR_ORDER_IGNORE          = 960512,       // ���к���������ί��
    HANDLER_ERROR_MACHINE_STATUS        = 960513,       // MACHINE STATUS����
    HANDLER_ERROR_MIRROR                = 960514,       // д������ļ�ʧ��
    HANDLER_ERROR_ORDER_LENGTH          = 960515,       // ί�л���αί�г��ȴ���
    HANDLER_ERROR_CONFIG                = 960516,       // ���ü���ʧ��
    HANDLER_ERROR_GET_SYSTEM_DATE       = 960517,       // ��ȡ��ǰʱ��ʧ��
    HANDLER_CRIT_MEMORY_OVERFLOW        = 960518,       // ί�е������ڴ��þ�
    HANDLER_WARNING_MEMORY_THRESHOLD    = 960519,       // ί�е������ڴ�ﵽ�澯��ֵ
    HANDLER_WARNING_MARKET_CLOSE        = 960520,       // �����г����л�������ָ��

    INSTR_DEBUG_TIME_STAMP              = 961001,       // ����ʱ��Ƭαί��
    INSTR_NOTICE_MARCKET                = 961002,       // �����г���Ϣαί��
    INSTR_NOTICE_EXIT                   = 961003,       // ģ���˳�����
    INSTR_ERROR_CONFIG                  = 961004,       // ���ü���ʧ��
    INSTR_ERROR_PROCESS_ID              = 961005,       // PROCESS ID����
    INSTR_ERROR_INIT_THREAD             = 961006,       // �̳߳�ʼ��ʧ��
    INSTR_ERROR_DBF_FILE                = 961007,       // DBF�ļ�����ʧ��
    INSTR_ERROR_QUEUE_WRITE             = 961008,       // д��QUEUEʧ��

    RMAPP_DEBUG_PACKAGE                 = 961501,       // �鲥ί��
    RMAPP_NOTICE_INIT_BEGIN             = 961502,       // ��ʼ����ʼ
    RMAPP_CRIT_INIT_FAIlED              = 961503,       // ��ʼ��ʧ��
    RMAPP_NOTICE_INIT_END               = 961504,       // ��ʼ���ɹ�
    RMAPP_ERROR_OPEN_SEM_FAILED         = 961505,       // ���źŵ�ʧ��
    RMAPP_ERROR_OPEN_SHM_FAILED         = 961506,       // �򿪹����ڴ�ʧ��
    RMAPP_ERROR_RMSENDER_NEW_FAILED     = 961507,       // ʵ�������Ͷ�ʧ��
    RMAPP_ERROR_RMSENDER_CREATE_FAILED  = 961508,       // ��ʼ�����Ͷ˶���ʧ��
    RMAPP_ERROR_RMSENDER_INIT_FAILED    = 961509,       // ��ʼ�����Ͷ�ʧ��
    RMAPP_ERROR_RMSENDER_START_FAILED   = 961510,       // ����ʧ��
    RMAPP_ERROR_RMSENDER_STOP_FAILED    = 961511,       // ֹͣʧ��
    RMAPP_ERROR_RMSENDER_PUSH_FAILED    = 961512,       // �����ݸ��鲥ģ��ʧ��

    MSYNC_ERROR_PROCESS_INDEX           = 962001,       // ������-r����������Ŵ���
    MSYNC_ERROR_CONFIG_PARAMETER        = 962002,       // �����ļ������ò�����
    MSYNC_ERROR_START_TCP_SERVER        = 962003,       // ����ͬ������TCP SERVERʧ��
    MSYNC_WARNING_TCP_DISCONNECTED      = 962004,       // ʧȥ�뱸��ͬ��TCP����
    MSYNC_WARNING_UNKNOW_MSG            = 962005,       // ����ͬ��������յ��Ƿ�������Ϣ
    MSYNC_WARNING_TCP_ERROR             = 962006,       // ����ͬ������TCP���ӱ���
    MSYNC_WARNING_NO_HISTRORY_DATA      = 962007,       // ����ͬ�������ȡ������ʷί�е�`
    MSYNC_WARNING_CURINDEX_ILLEGAL      = 962008,       // CurIndexֵ�Ƿ�
    MSYNC_WARNING_CONFIRMINDEX_ILLEGAL  = 962009,       // ConfirmIndexֵ�Ƿ�
    MSYNC_WARNING_SYNCINDEX_ILLEGAL     = 962010,       // SyncIndex ֵ�Ƿ�
    MSYNC_CRIT_CONFIRM_SYNCINDEX_ILLEGAL = 962011,      // ͬ��ȷ����Ϣ�е�ͬ��ָ��Ƿ�
    MSYNC_CRIT_SYNCINDEX_G_CONFIRMINDEX  = 962012,      // ͬ�������У�SYNCINDEX��ԽCONFIRMINDEX
    MSYNC_CRIT_SYNCINDEX_G_CURINDEX     = 962013,       // ͬ�������У�SYNCINDEX��ԽCURINDEX
    MSYNC_WARNING_LINKID                = 962014,       // LINKID��Խ���ֵ
    MSYNC_WARNING_WRITE_QUEUE           = 962015,       // д����ʧ��
    MSYNC_WARNING_SEND_DATA             = 962016,       // ����TCP����ʧ��
    MSYNC_ERROR_GET_MSG_SIZE            = 962017,       // ��ȡ��Ϣ���д�Сʧ��
    MSYNC_ERROR_ALLOCATE_BUF            = 962018,       // ���仺����ʧ��
    MSYNC_WARNING_READ_QUEUE_FAILED     = 962019,       // ��ȡ��������ʧ��
    MSYNC_WARNING_SYNC_RESP             = 962020,       // ��ͬ��Э��涨��ʱ����,
                                                        // ��������Ӧ
    MSYNC_WARNING_RECONNECT_TIMEOUT     = 962021,       // ����������ʱ
    MSYNC_ERROR_WRITE_QUEUE             = 962022,       // ����ͬ��ģ��д����ʧ��
    MSYNC_ERROR_CREATE_TIMER            = 962023,       // ������ʱ��ʧ��

    SSYNC_ERROR_PROCESS_INDEX           = 963001,       //����ͬ������PROCESS INDEX�Ƿ�
    SSYNC_ERROR_CONFIG_PARAMETER        = 963002,       //����ͬ�����������ļ���������
    SSYNC_ERROR_CONNECT_MMSYC           = 963003,       //������������ͬ��ʧ��
    SSYNC_WARNING_TCP_DISCONNECTED      = 963004,       //������ͬ��TCP���ӶϿ�
    SSYNC_WARNING_UNKNOWN_MSG           = 963005,       //����ͬ��������ܵ��Ƿ�������Ϣ
    SSYNC_WARNING_TCP_ERROR             = 963006,       //ͬ��TCP���ӳ���
    SSYNC_WARNING_SEND_DATA             = 963007,       //����TCP����ʧ��
    SSYNC_WARNIN_GET_SYSTEM_DATE        = 963008,       //ȡϵͳ����ʧ��
    SSYNC_ERROR_OPEN_MIRROR_FILE        = 963009,       //��ί�е������ļ�ʧ��
    SSYNC_WARNING_SYNCINDEX             = 963010,       //ͬ��ָ��Ƿ�
    SSYNC_WARNING_WRITE_MIRROR          = 963011,       //дί�е�����ʧ��
    SSYNC_WARNING_RECONNECT_N           = 963012,       //ͬ��TCP������N��ʧ��
    SSYNC_WARNING_FINAL_RECONNECT       = 963013,       //ͬ������N�κ����ʧ��
    SSYNC_ERROR_WRITE_QUEUE             = 963014,       //����ͬ��ģ��дEVENT QUEUEʧ��
    SSYNC_CRIT_SYNC_POINT               = 963015,       //����ӵ�е�ί�е�����������������
                                                        //ͬ���㲻ƥ��
    SSYNC_WARNING_SERVICE_STOP          = 963016,       //����ͬ��ֹͣ
    SSYNC_WARNING_ROLLBACK              = 963017,       //����ͬ�����˼�¼
    SSYNC_ERROR_CONNECT_MSYNC           = 963018,       //��������������ͬ��������ʧ��

    PROXY_ERROR_CONFIG_PARAMETER        = 965001,       // PROXY�����ļ����������
    PROXY_ERROR_CONNECT_ARB             = 965002,       // PROXY�����ٲ�ʧ��
    PROXY_WARNING_TCP_ERROR             = 965003,       // ���ٲ÷�������TCP���ӳ���
    PROXY_WARNING_UNKNOWN_MSG           = 965004,       // �ٲô�����յ��Ƿ�������Ϣ
    PROXY_WARNING_TCP_DISCONNECTED      = 965005,       // ���ٲ÷�������TCP���ӶϿ�
    PROXY_WARNING_SEND_DATA             = 965006,       // ��������ʧ��
    PROXY_ERROR_NEW_MACHINE_STATUS      = 965007,       // �ٲô������µĻ���״̬ʧ��
    PROXY_WARNING_WRITE_QUEUE           = 965008,       // �ٲô���д����ʧ��
    PROXY_ERROR_WAIT_CHILD_PROCESS      = 965009,       // �ٲô����ȡ�ӽ���״̬ʧ��
    PROXY_WARNING_READ_QUEUE            = 965010,       // �ٲô����ȡ����ʧ��
    PROXY_WARNING_UNKNOWN_EVENT         = 965011,       // �ٲô�����յ��Ƿ����͵��¼�
    PROXY_ERROR_GET_QUEUE_SIZE          = 965012,       // �ٲô����ȡ���д�Сʧ��
    PROXY_ERROR_ALLOCATE_BUF            = 965013,       // ��ȡ����QUEUE��Ϣ��BUFʧ��
    PROXY_ERROR_OPEN_PROCESS_CONFIG     = 965014,       // �򿪽��������ļ�ʧ��
    PROXY_ERROR_PROCESS_INDEX           = 965015,       // ����INDEX�Ƿ�
    PROXY_ERROR_PROCESS_NAME            = 965016,       // �������Ƿ�
    PROXY_WARNING_PROCESS_NAME_LEN      = 965017,       // ���������ȳ���
    PROXY_ERROR_PROCESS_POINTER         = 965018,       // ������Ϣ�ڴ�ָ��Ϊ��
    PROXY_ERROR_FORK                    = 965019,       // FORK�ӽ���ʧ��
    PROXY_WARNING_APP_STOP              = 965020,       // �ӽ���CRASH
    PROXY_ERROR_CREATE_TIMER            = 965021,       // ������ʱ��ʧ��

    ACD_RUN_LOG                         = 966001,       // DEBUG��INFO�ȼ��µ�LOG
    ACD_ERROR_ALLOCATE_OBJECT           = 966002,       // �������ʧ��
    ACD_ERROR_PROCESS_INDEX_ILLEGAL     = 966003,       // �Ƿ���PROCESS INDEX
    ACD_ERROR_STAT_TYPE                 = 966004,       // ͳ�����ʹ���
    ACD_ERROR_MACHINE_TYPE              = 966005,       // �������ʹ���

};

///ί��ǰ�û��¼���965000-969999
enum ACDFrontEventId
{
    FRONT_NOTICE_INIT_START                 = 800501,       // ί��ǰ�û���ʼ����ʼ
    FRONT_NOTICE_INIT_COMPLETE              = 800502,       // ��ʼ�����
    FRONT_CRIT_INIT_FAIL                    = 800503,       // ί��ǰ�û���ʼ��ʧ��
    FRONT_NOTICE_IN_WORKING                 = 800504,       // ί��ǰ�û�����������
    FRONT_ERROR_OUT_OF_WORKING              = 800505,       // ί��ǰ�û�����������

    FRONT_NOTICE_INIT_ACD_SERVER            = 802901,       // ��ʼ���Ŷӻ���TCP SERVER
    FRONT_NOTICE_INIT_SSC_SERVER            = 802902,       // ��ʼ����֤ͨ��TCP SERVER
    FRONT_NOTICE_INIT_MON_SHM               = 802903,       // ί��ǰ�û���ʼ�����ӹ����ڴ�
    FRONT_NOTICE_SEQ_NO                     = 802904,       // ����/���͵Ľ���ί�е�����SEQNO��Ҫ��Ϣ

    FRONT_DEBUG_RECEIVE_BIZ                 = 965001,       // ���յ����ݰ�
    FRONT_DEBUG_RECEIVE_IDLE                = 965002,       // ���յ��������ݰ�
    FRONT_DEBUG_ON_HEART                    = 965003,       // TCP�����¼�
    FRONT_RUN_LOG                           = 965004,       // INFO��DEBUG�ȼ�LOG

    FRONT_NOTICE_EXIT                       = 965101,       // �����˳�����
    FRONT_NOTICE_SERVER_ACCEPT              = 965102,       // ACCEPT�µ�TCP�ͻ���
    FRONT_NOTICE_UPDATE_ROLE                = 965103,       // ����ACD��LINK ROLE

    FRONT_WARNING_LINK_ID_UNKNOWN           = 965201,       // ��֤ͨ��LINK IDδ�ҵ�
    FRONT_WARNING_CLOSE                     = 965202,       // �ر�TCP����
    FRONT_WARNING_SET_TCP_PARAM             = 965203,       // ����TCP����ʧ��
    FRONT_WARNING_RECEIVE_QUIT              = 965204,       // ���յ��˳����ݰ�
    FRONT_WARNING_RECEIVE_UNKNOWN           = 965205,       // ���յ�����ʶ�����͵����ݰ�
    FRONT_WARNING_TIME_OUT                  = 965206,       // TCP TIMEOUT�¼�
    FRONT_WARNING_PACKAGE_LENGTH            = 965207,       // ���ݰ����ȷǷ�
    FRONT_WARNING_ROLE_DOWN                 = 965208,       // ���յ��Ŷӻ�����������ݰ�
    FRONT_WARNING_ROLE_FAIL                 = 965209,       // ACD ROLE���ʧ��
    FRONT_WARNING_ACD_INVALID               = 965210,       // ��Ч��ACD����
    FRONT_WARNING_SSC_INVALID               = 965211,       // ��Ч��SSC����

    FRONT_ERROR_ALLOCATE_SERVER             = 965301,       // ����SERVER�����ڴ�ʧ��
    FRONT_ERROR_CONFIG                      = 965302,       // ���ü���ʧ��
    FRONT_ERROR_SERVER_CREATE               = 965303,       // TCP SERVER����ʧ��
    FRONT_ERROR_TCP_MES                     = 965304,       // TCP ERROR�¼�
    FRONT_ERROR_SEND_DATA                   = 965305,       // TCP SEND����
    FRONT_ERROR_START_TIMER                 = 965306,       // ���ü�ʱ��ʧ��
};

///����ǰ�û��¼���970000-974999
enum QfepEventId
{
	///800451-800500
	///ʱ��
	QFEP_NOTICE_INIT_BEGIN = 800451,//970601,///��ʼ����ʼ
	QFEP_NOTICE_INIT_END = 800452,//970602,///��ʼ������
	QFEP_CRIT_INIT_FAILED = 800453,///��ʼ��ʧ��
	QFEP_NOTICE_QUOT_PUBLICING = 800454,///���鷢����
	QFEP_NOTICE_CLOSE_1_BEGIN = 800456,///����1��ʼ
	QFEP_NOTICE_CLOSE_1_END = 800457,///����1����
	QFEP_CRIT_CLOSE_1 = 800458,///����1ʧ��
	QFEP_NOTICE_CLOSE_2_BEGIN = 800459,///����2��ʼ
	QFEP_NOTICE_CLOSE_2_END = 800460,///����2����
	QFEP_CRIT_CLOSE_2 = 800461,///����2ʧ��
	QFEP_NOTICE_LOAD_MATCHTIME_END = 802501,///����qfep_matchtime.dbf�ɹ�
	QFEP_CRIT_LOAD_MATCHTIME_FAILED = 802502,///����qfep_matchtime.dbfʧ��
	QFEP_NOTICE_MKTALLOWORDER = 802503,////**< ����:0915 */
	QFEP_NOTICE_MKTAMCLOSE = 802504,////**< ���羺������:1130 */
	QFEP_NOTICE_MKTPMOPEN = 802505,////**< ���羺�ۿ�ʼ:1300 */
	QFEP_NOTICE_MKTPMCLOSE = 802506,///**������У�1500 <= time
	QFEP_NOTICE_MKTEVOPEN = 802507,///**�̺��׿��У�1500��time��1530 */
	QFEP_NOTICE_MKTEVCLOSE = 802508,///**< �̺��ױ��У�1530��time */
	QFEP_NOTICE_MKTAMOPEN = 802509,////**< ����:0930 */
	///***crit(970000~970100)***/
	///����
	QFEP_CRIT_MEM_OUT = 970000,///�ڴ治��
	QFEP_CRIT_READ_CONF = 970001,///��ȡ�����ļ�����
	QFEP_CRIT_SHAREDMEM_INIT = 970002,///�����ڴ��ʼ��
	QFEP_CRIT_LOAD_INIT = 970003,///��ʼ����ȡdbf����
	QFEP_CRIT_READ_BACKUP_FILE = 970004,///��ȡ�ֱ��ļ�����
	///�鲥(11~20)
	QFEP_CRIT_RM_INIT = 970011,///�鲥��ʼ��ʧ��
	QFEP_CRIT_RM_LOCAL_FIlE_INIT = 970012,///�鲥����ļ���ʼ��ʧ��
	///write dbf(21~30)
	QFEP_CRIT_WRITE_DBF_INIT = 970021,///дdbf��ʼ��ʧ��
	///tcp(31~40)
	QFEP_CRIT_TCP_INIT = 970031,///tcp��ʼ��ʧ��
	///udp(41~50)
	QFEP_CRIT_UDP_INIT = 970041,///udp��ʼ��ʧ��
	///����(51~60)
	QFEP_CRIT_NOTICE_INIT = 970051,///����ɨ���ʼ��ʧ��
	///***err(970101~970400)***/
	///����(101~150)
	QFEP_ERROR_GET_MEMDATA = 970101,///����ڴ����ݴ���
	///�鲥(151~170)
	QFEP_ERROR_RM_THREAD_START = 970151,///�鲥�߳�����ʧ��
	QFEP_ERROR_RM_THREAD_STOP = 970152,///�鲥�߳�ֹͣʧ��
	QFEP_ERROR_RM = 970153,///�鲥����
	QFEP_ERROR_RM_DATA = 970154,///�ɿ��鲥���յ���������
	QFEP_ERROR_RM_WRITE_LOCAL_FILE = 970155,///�鲥�������ʧ��
	///write dbf(171~190)
	QFEP_ERROR_WRITE_DBF_THREAD_START = 970171,///dbf�߳�����ʧ��
	QFEP_ERROR_WRITE_DBF_THREAD_STOP = 970172,///dbf�߳�ֹͣʧ��
	QFEP_ERROR_WRITE_DBF = 970173,///Dbfд��ʧ��
	QFEP_ERROR_BACKUP_DBF = 970174,///����ʧ��
	///tcp(191~210)
	QFEP_ERROR_TCP_THREAD_START = 970191,///tcp�߳�����ʧ��
	QFEP_ERROR_TCP_THREAD_STOP = 970192,///tcp�߳�ֹͣʧ��
	QFEP_ERROR_TCP_SEND = 970193,///TCP����ʧ��
	QFEP_ERROR_TCP_SOCKET_MANAGE = 970194,///����sockindexʧ��
	///udp(211~230)
	QFEP_ERROR_UDP_THREAD_START = 970211,///udp�߳�����ʧ��
	QFEP_ERROR_UDP_THREAD_STOP = 970212,///udp�߳�ֹͣʧ��
	QFEP_ERROR_UDP_SEND = 970213,///UDP����ʧ��
	///����(231~250)
	QFEP_ERROR_NOTICE_THREAD_START = 970231,///notice�߳�����ʧ��
	QFEP_ERROR_NOTICE_THREAD_STOP = 970232,///notice�߳�ֹͣʧ��
	QFEP_ERROR_SCAN_NOTICE = 970233,///ɨ�蹫�����
	///***warning(970401~970600)***/
	///����(401~450)
	///�鲥(451~470)
	QFEP_WARNING_DATA = 970451,///�յ����鲥����Խ��
	///write dbf(471~490)
	///tcp(491~510)
	QFEP_WARNING_TCP_SOCKET_FULL = 970500,///tcp���ӳ���
	///udp(511~530)
	///����(531~550)
	///***notice(970601~970700)***/
	///����(601~630)
	QFEP_NOTICE_WORK_NORMAL = 970603,///��������
	QFEP_NOTICE_RM_RECOVERY = 970604,///�鲥�ֱ�
	QFEP_NOTICE_NOTICE_RECOVERY = 970605,///�����ֱ�
	///�г�״ָ̬��(631~640)
	QFEP_NOTICE_TMP_CLOSE = 970634,///��ʱͣ��
	///tcp(641~650)
	QFEP_NOTICE_TCP_DISCONNECT = 970641,///tcp�Ͽ�����
	///����(651~660)
	QFEP_NOTICE_TCP_SEND_SUCCESS = 970651,///���淢�ͳɹ�
	///***info(970701~970900)***/
	///����(701~730)
	///���ݴ���(731~740)
	QFEP_INFO_DATA_PROCESSOR_INIT_BEGIN = 970731,///���ݴ���ģ���ʼ����ʼ
	QFEP_INFO_DATA_PROCESSOR_INIT_END = 970732,///���ݴ���ģ���ʼ������
	///�����ڴ�(741~750)
	QFEP_INFO_SHAREDMEM_INIT_BEGIN = 970741,///�����ڴ��ʼ����ʼ
	QFEP_INFO_SHAREDMEM_INIT_END = 970742,///�����ڴ��ʼ������
	///����dbf(751~760)
	QFEP_INFO_LOAD_DBF_INIT_BEGIN = 970751,///����DBF��ʼ����ʼ
	QFEP_INFO_LOAD_DBF_INIT_END = 970752,///����DBF��ʼ������
	///�鲥(761~770)
	QFEP_INFO_RM_INIT_BEGIN = 970761,///�鲥��ʼ����ʼ
	QFEP_INFO_RM_INIT_END = 970762,///�鲥��ʼ������
	QFEP_INFO_RM_THREAD_START = 970763,///�鲥�߳�����
	QFEP_INFO_RM_THREAD_STOP = 970764,///�鲥�߳�ֹͣ
	//QFEP_INFO_RM_CREATE_DATA_FILE_BEGIN = 970765,///�����鲥����ļ���ʼ
	//QFEP_INFO_RM_CREATE_DATA_FILE_END = 970766,///�����鲥����ļ�����
	///write dbf(771~780)
	QFEP_INFO_DBF_WRITER_INIT_BEGIN = 970771,///�鲥��ʼ����ʼ
	QFEP_INFO_DBF_WRITER_INIT_END = 970772,///�鲥��ʼ������
	QFEP_INFO_WRITE_DBF_THREAD_START = 970773,///dbf�߳�����
	QFEP_INFO_WRITE_DBF_THREAD_STOP = 970774,///dbf�߳�ֹͣ
	///tcp(781~790)
	QFEP_INFO_TCP_SENDER_INIT_BEGIN = 970781,///tcp��ʼ����ʼ
	QFEP_INFO_TCP_SENDER_INIT_END = 970782,///tcp��ʼ������
	QFEP_INFO_TCP_THREAD_START = 970783,///tcp�߳�����
	QFEP_INFO_TCP_THREAD_STOP = 970784,///tcp�߳�ֹͣ
	///udp(791~800)
	QFEP_INFO_UDP_SENDER_INIT_BEGIN = 970791,///udp��ʼ����ʼ
	QFEP_INFO_UDP_SENDER_INIT_END = 970792,///udp��ʼ������
	QFEP_INFO_UDP_THREAD_START = 970793,///udp�߳�����
	QFEP_INFO_UDP_THREAD_STOP = 970794,///udp�߳�ֹͣ
	///����(801~810)
	QFEP_INFO_NOTICE_INIT_BEGIN = 970801,///�����ʼ����ʼ
	QFEP_INFO_NOTICE_INIT_END = 970802,///�����ʼ������
	QFEP_INFO_NOTICE_THREAD_START = 970803,///notice�߳�����
	QFEP_INFO_NOTICE_THREAD_STOP = 970804,///notice�߳�ֹͣ
	///***debug(970901~971000)***/
	QFEP_DEBUG = 970901///debug
};

///�ɽ�ǰ�û��¼���975000-979999
enum RepcommEventId
{
    REPC_NOTICE_S_BROKENO               = 802601, /**< ���ͽ��׵�Ԫ������ʱ��  */
    REPC_NOTICE_S_STOCKTYPE             = 802602, /**< ����֤ȯ��������ʱ��  */
    REPC_NOTICE_S_TRADING_START         = 802603, /**< ���Ϳ���ָ���ʱ��  */
    REPC_NOTICE_S_AM_OPEN               = 802604, /**< �������羺��ָ��  */
    REPC_NOTICE_S_AM_CLOSE              = 802605, /**< ������������ָ��  */
    REPC_NOTICE_S_PM_OPEN               = 802606, /**< �������羺��ָ��  */
    REPC_NOTICE_S_PM_CLOSE              = 802607, /**< ������������ָ��  */
    REPC_NOTICE_R_TRADING_START         = 802608, /**< ���տ���ָ��  */
    REPC_NOTICE_R_AM_OPEN               = 802609, /**< �������羺��ָ��  */
    REPC_NOTICE_R_AM_CLOSE              = 802610, /**< ������������ָ��  */
    REPC_NOTICE_R_PM_OPEN               = 802611, /**< �������羺��ָ��  */
    REPC_NOTICE_R_PM_CLOSE              = 802612, /**< ������������ָ��  */
    REPC_NOTICE_DBF_MAKET_MAKER         = 802613, /**< �Ѽ���������dbf  */
    REPC_NOTICE_DBF_MATCHTIME           = 802614, /**< �Ѽ��ؽ���ʱ��dbf  */
    REPC_NOTICE_DBF_PBU                 = 802615, /**< �Ѽ��ؽ��׵�Ԫdbf  */
    REPC_NOTICE_DBF_STOCK_INFO          = 802616, /**< �Ѽ���֤ȯ��Ϣdbf  */
    REPC_NOTICE_S_TIME_NOW              = 802617, /**< ���ͽ���ϵͳʱ�������ʱ��*/
    REPC_NOTICE_S_MARKET_MAKER          = 802618, /**< ���������̴�����ʱ�� */
    REPC_NOTICE_S_BUSINESS_PERIOD       = 802619, /**< ����ʱ��δ�����ʱ�� */
    REPC_NOTICE_S_STOCK_INFO            = 802620, /**< ����֤ȯ��Ϣ������ʱ��*/
    REPC_NOTICE_S_MARKET_STATUS         = 802621, /**< �����г�״̬������ʱ��*/
    REPC_WAR_NO_LINK                    = 802622, /**< û����֤ͨ��Ч���ӽ���*/
    REPC_WAR_VALIAD_LINK                = 802623, /**< ����֤ͨ��Ч���ӽ���*/
    REPC_NOTICE_SECUKIND                = 802624, /**< �Ѽ���֤ȯ���  */
    REPC_NOTICE_MANUAL_CLOSING          = 802625, /**< �����ֹ�����ָ��  */
    REPC_NOTICE_MAKER_CLOSE             = 802626, /**< �����̺�����ָ���9  */

    REPC_CRI_NO_MEM				      = 975000,	/**< �����ڴ�ʧ�� */
    REPC_ERR_RM_ONERROR			      = 975001,	/**< �鲥���� */
    REPC_WAR_STOCK_CODE	              = 975002,	/**< ����֤ȯ��Ϣʱ�����ڵ�֤ȯ���� */
    REPC_INF_INIT                     = 975003, /**< ��ʼ��ʱ��ӡ��Ϣ */
    REPC_ERR_CFG			          = 975004,	/**< ��ʼ��ʱ���ô��� */
    REPC_ERR_SHM                      = 975005, /**< ��ʼ��ʱ��ع����ڴ���� */
    REPC_WAR_SVR_STATUS               = 975006, /**< ϵͳ״̬���� */
    REPC_WAR_SSC_INDEX                = 975007, /**< ����ͨ�ص�ʱ���ӺŲ�ƥ�� */
    REPC_WAR_SSC_ARG                  = 975008, /**< ����ͨ�ص�ʱ������Ч */
    REPC_INF_SSC_CONNECT    	      = 975009, /**< ����ͨ�������� */
    REPC_INF_SSC_DISCONNECT    	      = 975010, /**< ����ͨ�Ͽ����� */
    REPC_ERR_SSC_PROTOCOL             = 975011, /**< ����ͨЭ����� */
    REPC_ERR_SSC_IP                   = 975012, /**< ����ͨ�������ӵ�IP��ַ���������ļ��� */
    REPC_WAR_SSC_SEND                 = 975013, /**< ����ͨ���ӷ���ʧ�� */
    REPC_ERR_SSC_TIME_OUT             = 975014, /**< ����ͨ���ճ�ʱ30sû�յ����� */
    REPC_ERR_ACCEPTOR_CREATE          = 975015, /**< ����tcp����ʧ�� */
    REPC_ERR_ACCEPTOR_DESTROY         = 975016, /**< ����tcp����ʧ�� */
    REPC_ERR_ACCEPTOR_ONERROR         = 975017, /**< tcpͨ�ſ���� */
    REPC_ERR_ACCEPTOR_DISCONNECT      = 975018, /**< tcp�Ͽ�����ʧ�� */
    REPC_INF_THREAD_START             = 975019, /**< �߳����� */
    REPC_INF_THREAD_STOP              = 975020, /**< �߳�ֹͣ */
    REPC_ERR_THREAD_START             = 975021, /**< �߳�����ʧ�� */
    REPC_ERR_THREAD_STOP              = 975022, /**< �߳�ֹͣʧ�� */
    REPC_ERR_FILE_OPEN                = 975023, /**< ���ļ�ʧ�� */
    REPC_ERR_FILE_READ                = 975024, /**< ���ļ�ʧ�� */
    REPC_WAR_FILE_WRITE               = 975025, /**< д�ļ�ʧ�� */
    REPC_WAR_FILE_SEEK                = 975026, /**< �ƶ��ļ�ƫ��ʧ�� */
    REPC_WAR_FILE_EINTR               = 975027, /**< �����߳�ֹͣ,д�ļ��ж� */
    REPC_WAR_FILE_SYNC                = 975028, /**< �ļ�ˢ����ʧ�� */
    REPC_ERR_FILE_DATA                = 975029,  /**< �ļ�ͷ�����ݲ�ƥ�� */
    REPC_WAR_NOT_RECV_RM_DATA         = 975030, /**< û���鲥������ʱ��Ƭ��Ϣ */
    REPC_ERR_SZT_INVALID_SEQNO        = 975031, /**< �Ƿ���seqno,seqno����dealnum  */
    REPC_INF_DEAL_NO                  = 975032, /**< ���ͳɽ������  */
    REPC_INFO_PKT                     = 975033, /**< �޷���������Ϣ  */
};

///���׹����¼���980000-984999
///��������¼���985000-989999

///���������¼���990000-994999
enum QsEventId
{
    /** ������ʱ��֪ͨ */
    QS_NOTICE_START_SUCCESS            =	800101,	/**< QS��ʼ����ʼ */
    QS_NOTICE_INIT_SUCCESS             =	800102,	/**< QS��ʼ����� */
    QS_NOTICE_INIT_FAIL                =	800103,	/**< QS��ʼ��ʧ�� */
    QS_NOTICE_AM_INIT_START            =	800104, /**< QS���翪�п�ʼ */
    QS_NOTICE_AM_INIT_END              =	800105, /**< QS���翪�н��� */
    QS_NOTICE_AM_INIT_FAIL             =	800106, /**< QS���翪��ʧ�� */
    QS_NOTICE_NM_INIT_START            =	800107, /**< QS�������п�ʼ */
    QS_NOTICE_NM_INIT_END              =	800108, /**< QS�������н��� */
    QS_NOTICE_NM_INIT_FAIL             =	800109, /**< QS��������ʧ�� */
    QS_NOTICE_PV_INIT_START            =	800110, /**< QS���翪�п�ʼ */
    QS_NOTICE_PV_INIT_END              =    800111, /**< QS���翪�н��� */
    QS_NOTICE_PV_INIT_FAIL             =    800112, /**< QS���翪��ʧ�� */
    QS_NOTICE_CLOSE_START              =	800113,	/**< QS���п�ʼ */
    QS_NOTICE_CLOSE_END                =	800114,	/**< QS���н��� */
    QS_NOTICE_CLOSE_FAIL               =	800115,	/**< QS����ʧ�� */
    QS_NOTICE_EV_INIT_START            =	800116, /**< QS���Ͽ��п�ʼ */
    QS_NOTICE_EV_INIT_END              =    800117, /**< QS���Ͽ��н��� */
    QS_NOTICE_EV_INIT_FAIL             =    800118, /**< QS���Ͽ���ʧ�� */
    QS_ORDER_TREATY_ISSUE              =    800119, /**< Э��ת�����鷢��ָ�ʼ 9:15 */
    QS_ORDER_TREATY_ISSUE_OK           =    800120, /**< Э��ת�����鷢��ָ�ʼ 9:15 */
    QS_ORDER_TREATY_MATCH              =    800121, /**< Э��ת�ô��ָ�ʼ 9:30 */
    QS_ORDER_TREATY_MATCH_OK           =    800122, /**< Э��ת�ô��ָ�ʼ 9:30 */
    QS_NOTICE_PA_CLOSE                 =    800123, /**< Э��ת������ָ�ʼ 15:00 */
    QS_NOTICE_PA_CLOSE_OK              =    800124, /**< Э��ת������ָ�ʼ 15:00 */
    QS_INFO_SEND_CLOSE_INSTRUCT1_OK    =	800125, /**< ����ָ��Ƿ��ѷ��ͷ���ʱ�䣩*/
    QS_INFO_SEND_CLOSE_INSTRUCT2_OK    =	800126, /**< ����ָ��2���Ƿ��ѷ��ͷ���ʱ�䣩 */
    QS_NOTICE_MATCH_START              =    800127, /**< ��Ͽ�ʼ **/
    QS_NOTICE_MATCH_END                =    800128, /**< ��Ͽ�ʼ�ɹ� **/
    QS_NOTICE_MATCH_FAIL               =    800129, /**< ��Ͽ�ʼʧ�� **/
        
    QS_ORDER_MARKET_ISSUE              =    800130, /**< ����ת�����鷢��ָ�ʼ 9:15 */
    QS_ORDER_MARKET_ISSUE_OK           =    800131, /**< ����ת�����鷢��ָ�ʼ 9:15 */
    QS_ORDER_MARKET_MATCH              =    800132, /**< ����ת�ô��ָ�ʼ 9:30 */
    QS_ORDER_MARKET_MATCH_OK           =    800133, /**< ����ת�ô��ָ�ʼ 9:30 */
    QS_NOTICE_MM_CLOSE                 =    800134, /**< ����ת������ָ�ʼ 15:00 */
    QS_NOTICE_MM_CLOSE_OK              =    800135, /**< ����ת������ָ�ʼ 15:00 */

    QS_ORDER_TOWNET_NOTISSUE           =    800136, /**< ��������ɽ�������ָ�ʼ 9:30 */
    QS_ORDER_TOWNET_NOTISSUE_OK        =    800137, /**< ��������ɽ�������ָ�ʼ 9:30 */
    QS_NOTICE_O3B_CLOSE                =    800138, /**< ��������������ָ�ʼ 15:00*/
    QS_NOTICE_O3B_CLOSE_OK             =    800139, /**< ��������������ָ�ʼ 15:00*/

	QS_ORDER_BID_ISSUE    			   =	800140,	/**< ����ת�ü��Ͼ���ָ�ʼ 9:15 */
	QS_ORDER_BID_ISSUE_OK			   =	800141,	/**< ����ת�ü��Ͼ���ָ�ʼ 9:15 */
	QS_ORDER_BID_MATCH				   =	800142,	/**< ����ת����������ָ�ʼ 9:30 */
	QS_ORDER_BID_MATCH_OK			   =	800143,	/**< ����ת����������ָ�ʼ 9:30 */
	QS_NOTICE_BID_CLOSE				   =	800144,	/**< ����ת������ָ�ʼ 15:00 */
	QS_NOTICE_BID_CLOSE_OK			   =	800145,	/**< ����ת������ָ�ʼ 15:00 */

    QS_NOTICE_LOAD_STOCKINFO_OK          =    802501, /**< qs_stock_info.dbf���Ƿ��Ѽ��ص�λ�ͼ���ʱ�䣩  */
    QS_NOTICE_LOAD_STOCK_PRECLOSE_OK     =    802502, /**< qs_stock_close.dbf���Ƿ��Ѽ��ص�λ�ͼ���ʱ�䣩 */
    QS_NOTICE_LOAD_STOCK_PUBLIC_PARAM_OK =    802503, /**< qs_stock_param.dbf���Ƿ��Ѽ��ص�λ�ͼ���ʱ�䣩 */
    QS_NOTICE_LOAD_CLOSE_PARAM_OK        =    802504, /**< qs_close_param.dbf���Ƿ��Ѽ��ص�λ�ͼ���ʱ�䣩 */
    QS_NOTICE_LOAD_MAKER_INFO_OK         =    802505, /**< qs_maker_info.dbf���Ƿ��Ѽ��ص�λ�ͼ���ʱ�䣩  */
    QS_NOTICE_LOAD_MAKER_NAME_OK         =    802506, /**< qs_maker_name.dbf���Ƿ��Ѽ��ص�λ�ͼ���ʱ�䣩  */
    QS_NOTICE_LOAD_TRADER_UNIT_OK        =    802507, /**< qs_trade_unit.dbf���Ƿ��Ѽ��ص�λ�ͼ���ʱ�䣩  */
    QS_NOTICE_LOAD_BRANCH_OK             =    802508, /**< qs_branch.dbf���Ƿ��Ѽ��ص�λ�ͼ���ʱ�䣩  */
    
    QS_INFO_SEND_CLOSE_INSTRUCT3_OK      =	802337, /**< ����ָ��3 ���Ƿ��ѷ��ͷ���ʱ�䣩*/
    QS_NOTICE_SUSPENSION                 =	802338, /**< ����ͣ��ָ������µĽ���ʱ�� */
    QS_NOTICE_RESUMPTION                 =	802339, /**< ���ո���ָ������µĽ���ʱ�� */
    QS_NOTICE_TEMP_CLOSE                 =  802345, /**< ��ʱ���� */
    QS_NOTICE_CLOSE_SUSPENSION           =  802346, /**< QSͣ��ָ�� */
    QS_NOTICE_CLOSE_RESUMPTION           =  802347, /**< QS����ָ�� */

    /** �����Ǵ���� 990000 */
    QS_ERROR_LOAD_INITIAL_FILE_FAIL      =	990000,	/**< ���س�ʼ���ļ�ʧ�� */
    QS_ERROR_NO_MEMORY                   =	990001,	/**< �ڴ治�� */
    QS_ERROR_STOCK_CODE_INVALID          =	990002,	/**< ��ʼ���ļ����ڷǷ���Ʊ���� */
    QS_ERROR_STOCK_COUNT                 =	990003,	/**< ֤ȯ���̱���֤ȯ��Ϣ��ƥ�� */
    QS_ERROR_CLOSE_PARAM                 =	990004,	/**< ���̲�������(����>=1)��Ч */
    QS_ERROR_NO_PUBLIC_PARAM             =	990005,	/**< δ���������ʾ���� */
    QS_ERROR_INIT_RMSEND                 =	990006,	/**< ��ʼ���鲥����ģ��ʧ�� */
    QS_ERROR_RMSEND_CREATE               =	990007,	/**< �鲥����ģ�鴴��ʧ�� */
    QS_ERROR_RMSEND_START                =	990008,	/**< �鲥����ģ������ʧ�� */
    QS_ERROR_ORDTYPE_INVALID             =	990009,	/**< �յ�ҵ�����ݷǷ� */
    QS_WARNING_NO_BUILDER                =	990010,	/**< �˽��׽׶�û�д����� */
    QS_ERROR_STRUCT_NOMATCH              =	990011,	/**< ��Ʊ��Ϣ�ṹ���Ȳ�ƥ�� */
    QS_ERROR_NOSUPPORT_BUSINESS          =	990012,	/**< ��֧�ִ���ҵ�� */
    QS_ERROR_CREATE_DATAMANAGER          =	990013,	/**< �������ݹ�����ʧ�� */
    QS_ERROR_LOAD_DATA                   =	990014,	/**< ���ݹ�������������ʧ�� */
    QS_ERROR_CANNOT_TREAT                =	990015,	/**< ����������ָ�� */
    QS_ERROR_CREATE_INVESTOR_BUY_BOOK    =	990016,	/**< ����Ͷ�����򶩵���ʧ�� */
    QS_ERROR_CREATE_INVESTOR_SALE_BOOK   =	990017,	/**< ����Ͷ������������ʧ�� */
    QS_ERROR_CREATE_LIMIT_BUY_BOOK       =	990018,	/**< �����޼�/�������򶩵���ʧ�� */
    QS_ERROR_CREATE_LIMIT_SALE_BOOK      =	990019,	/**< �����޼�/��������������ʧ�� */
    QS_ERROR_CREATE_SEND_COMPONENT       =	990020,	/**< ��ʼ���鲥����ģ��ʧ�� */
    QS_ERROR_CREATE_SHAREMEM             =	990021,	/**< ���������ڴ�ʧ����رչ����ڴ棬�������� */
    QS_ERROR_CREATE_ORDERBOOK_ARRAY      =	990022,	/**< ������Ʊ����������ʧ�� */
    QS_ERROR_CREATE_ORDERBOOK            =	990023,	/**< ������Ʊ������ʧ�� */
    QS_ERROR_CREATE_MEMSNAP              =	990024,	/**< ��ʼ���ڴ����ʧ�� */
    QS_ERROR_CREATE_AGREEMENT_DIRECTOR   =	990025,	/**< ����Э��ҵ��ָ��ʧ�� */
    QS_ERROR_CREATE_MARKET_DIRECTOR      =	990026,	/**< ��������ҵ��ָ��ʧ�� */
    QS_ERROR_CREATE_TWONET_DIRECTOR      =	990027,	/**< ��������������ҵ��ָ��ʧ�� */
    QS_ERROR_CREATE_INSTRUCTOR           =	990028,	/**< ����ָ�����ʧ�� */
    QS_ERROR_CANNOT_CLONE                =	990029,	/**< ����δ�������ܱ���¡ */
    QS_ERROR_CREATE_STOCKINFO_BUFFER     =	990030,	/**< ����֤ȯ��Ϣ����ʧ�� */
    QS_ERROR_CREATE_STOCKOTHER_BUFFER    =	990031,	/**< ����֤ȯ������Ϣ����ʧ�� */
    QS_ERROR_CREATE_STOCKQUOT_BUFFER     =	990032,	/**< ����֤ȯ������Ϣ����ʧ�� */
    QS_ERROR_CREATE_STOCKORDER_BUFFER    =	990033,	/**< ����ί���걨����ʧ�� */
    QS_ERROR_CREATE_MAKERINFO_BUFFER     =	990034,	/**< ������������Ϣ����ʧ�� */
    QS_ERROR_GET_FILEDBYNAME             =	990035,	/**< ��ȡ���ֶ�ʧ�� */
    QS_ERROR_ORDER_INDEX_INVALID         =	990036,	/**< ί���걨�������� */
    QS_ERROR_CREATE_BUILDER              =	990037,	/**< ����ҵ������ʧ�� */
    QS_ERROR_NO_CONFIG_LOG               =	990038,	/**< �����ļ�����־������� */
    QS_ERROR_NO_POSITION_TYPE            =	990039,	/**< ��ʾ����������󲻴��ڴ����������� */
    QS_ERROR_NO_CONFIG_SECTION_ITEM      =	990040,	/**< ���öλ��㲻���� */
    QS_ERROR_NO_REGISTER_ORDERBOOK       =	990041,	/**< �˹�Ʊ������δע���ע�᲻���� */
    QS_ERROR_CLOSE_STATE                 =	990042,	/**< ����״̬���� */
    QS_ERROR_RMSEND_INSTRUCT             =	990043,	/**< ��������ָ��ʧ�� */
    QS_ERROR_RMSEND_OUT_STOP_ORDER       =	990045,	/**< ����ͣ����������Ϣʧ�� */
    QS_ERROR_RMSEND_STOCK_QUOT           =	990046,	/**< ���͹�Ʊ����ʧ�� */
    QS_ERROR_RMSEND_STOCK_ORDER          =	990047,	/**< ���͹�Ʊί������ʧ�� */
    QS_ERROR_NOALLOW_MAKE_CLOSE_QUOT     =	990048,	/**< δ����ǰ����������������� */
    QS_ERROR_DIR_NOEXSIST                =	990049,	/**< ����Ŀ¼������ */
    QS_ERROR_CREATE_QUOTMAKER            =  990050, /**< ������������ʵ��ʧ�� */
    QS_ERROR_PUBLIC_QUOT_PARAM           =  990051, /**< ���ý�ʾ����Ƶ�ʲ����Ƿ� */
    QS_ERROR_PUBLIC_INFO_PARAM           =  990052, /**< ���ý�ʾ������ϢƵ�ʲ����Ƿ� */
    QS_ERROR_NOEXSIST_STOCK              =  990053, /**< ��Ʊ���벻���� */
    QS_ERROR_PUBLIC_INITIAZATION_PARAM   =  990054, /**< ���ó�ʼ������ʱ���Ƿ� */
    QS_ERROR_CONFIG_ITEM_VALID           =  990055, /**< ������Ƿ� */
    QS_ERROR_AGREEMENT_ORDER_ENQUEUE     =  990056, /**< Э��ί����Ӵ��� */
    QS_ERROR_AGREEMENT_ORDER_COPY        =  990057, /**< Э��ί���걨��Ϣ�������� */

    /** �����ǳ���������Ϣ 990500 */
    QS_INFO_PROGRAM_QUIT                = 802391,/**< ����رճɹ� */
    QS_INFO_LOAD_INIT_FILE_OK           = 802392,/**< ���س�ʼ���ļ��б���� */
    QS_INFO_DM_INIT_OK                  = 802393,/**< ���ݼ���ģ���ʼ���ɹ� */
    QS_INFO_RM_INIT_OK                  = 802394,/**< �鲥�����������ʼ���ɹ� */
    QS_INFO_SHAREMEM_INIT_OK            = 802395,/**< ������������ʼ���ɹ� */
    QS_INFO_ORDERBOOK_CREATE_OK         = 802396,/**< ������Ʊ�������洢�����ɹ� */
    QS_INFO_QM_MEM_CREATE_OK            = 802397,/**< �������������ڴ�ɹ� */
    QS_INFO_QM_BIZ_OBJECT_CREATE_OK     = 802398,/**< ����������������ҵ�������ɹ� */
    QS_INFO_QM_BIZ_STATE_CHANGED        = 802399,/**< ����ҵ��Ʒ�ֽ�ʾ״̬�仯 */
};


///���������¼���995000-999998
enum TsEventId
{
	TS_ERROR_CONFIGNOTEXIST       = 995000,      /**<�����ļ������ڻ򲻷���Ҫ��                                           */
	TS_ERROR_LOADSTOCKCODE_COMMONSTOCKTYPE_NOTFOUND = 995016,   /**<���س�ʼ�����ݣ�֤ȯ���룩ʱ���ֶ�Ӧ��ͨ���֤ȯ��𲻴���           */
	TS_ERROR_LOADSTOCKCODE_BIGSTOCKTYPE_NOTFOUND    = 995017,   /**<���س�ʼ�����ݣ�֤ȯ���룩ʱ���ֶ�Ӧ�����֤ȯ��𲻴���           */
	TS_ERROR_LACKOFMEMORY         = 995500,      /**<ϵͳ��Դ����                                                         */
	TS_ERROR_MULTICASTRECV        = 995501,      /**<�鲥���մ���                                                         */
	TS_ERROR_LOADMULTICASTSENDER  = 995502,      /**<���������鲥����ʧ��                                                 */
	TS_ERROR_LOADMULTICASTRECVER  = 995503,      /**<���������鲥����ʧ��                                                 */
    TS_ERROR_LOADMATCHMODULE      = 995504,      /**<���ؽ��״��ģ��ʧ��                                                 */
    TS_ERROR_LOADMAXAGREEMENTDEALNUM = 995505,   /**<����Э��ת�û����ɽ�ȷ�����Լ����ʧ��                               */
    TS_ERROR_PRICESTEPZERO        = 995506,      /**<����֤ȯ�����С�۲�Ϊ0                                              */
    TS_ERROR_LOADMAXLIMITDEALNUM  = 995507,      /**<�����޼�����ί�з�������Լ����ʧ��                                 */
    TS_ERROR_LOADBUYUNITZERO      = 995508,      /**<����֤ȯ������뵥λΪ0                                              */
    TS_ERROR_LOADSELLUNITZERO     = 995509,      /**<����֤ȯ���������λΪ0                                              */
    TS_ERROR_MAXAGREEDEALNO_LESSTHANLIMITDEALNO = 995510,   /**<���ؼ����޼�����ί�з�������Լ����ʧ�ܣ�С�ڻ����ɽ�ȷ�����Լ���� */
    TS_ERROR_WRITE_LOCAL_FILE     = 995511,      /**<д�����鲥�����ļ�ʧ�� */
    TS_ERROR_READ_DFB             = 995512,      /**<��dbf�ļ����� */
    TS_ERROR_INSERT_ORDER         = 995513,      /**<����ָ���ί�д��� */
    TS_ERROR_READ_LOCAL_FILE      = 995514,      /**<�������鲥�����ļ�ʧ�� */
    TS_ERROR_RECV_TOO_LARGE_DATA  = 995515,      /**<�鲥���յ����ݴ���ָ������� */

	TS_WARNING_STOCKTYPEPARANOTFOUND            = 996501,   /**<������֤ȯT+n��ʶ��֤ȯ�������ʱ���ֶ�Ӧ��֤ȯ���������ò�����    */
	TS_WARNING_STOCKCODENOTFOUND                = 996502,   /**<������֤ȯ����ҵ������з��ֶ�Ӧ֤ȯ���벻����                       */
	TS_WARNING_ACCOUNTNONOTFOUND                = 996503,   /**<������֤ȯ�ʻ����ơ����������ơ�֤ȯ�ֲֹ����з��ֶ�Ӧ֤ȯ�ʺŲ����� */
	TS_WARNING_UNITNONOTFOUND                   = 996504,   /**<�����Ӽ��Ե�Ԫ��Ϣ�з��ֶ�Ӧ֤ȯ���׵�Ԫ������                       */

	TS_WARNING_STOCKTYPEKEYDUP                  = 996601,   /**<���س�ʼ�����ݣ�֤ȯ��𣩶�Ӧ��¼�����ظ�                           */
	TS_WARNING_STOCKCODEKEYDUP                  = 996602,   /**<���س�ʼ�����ݣ�֤ȯ���룩��Ӧ��¼�����ظ�                           */
	TS_WARNING_ACCOUNTNOKEYDUP                  = 996603,   /**<���س�ʼ�����ݣ�֤ȯ�ʻ�����Ӧ��¼�����ظ�                           */
    TS_WARNING_UNITNOKEYDUP                     = 996604,   /**<���س�ʼ�����ݣ����׵�Ԫ����Ӧ��¼�����ظ�                           */
    TS_WARNING_ALLOWBUSITYPEKEYDUP              = 996605,   /**<���س�ʼ�����ݣ�֤ȯ����ҵ����𣩶�Ӧ��¼�����ظ�                   */
	TS_WARNING_TNFLAGKEYDUP                     = 996606,   /**<���س�ʼ�����ݣ�֤ȯ����T+n��ʶ����Ӧ��¼�����ظ�                    */
	TS_WARNING_STOCKKEYDUP                      = 996607,   /**<���س�ʼ�����ݣ�֤ȯ�ֲ���Ϣ����Ӧ��¼�����ظ�                       */
	TS_WARNING_UNITNORESTRICTKEYDUP             = 996608,   /**<���س�ʼ�����ݣ����׵�Ԫ���Ʊ���Ӧ��¼�����ظ�                     */
	TS_WARNING_ACCPROPRESTRICTKEYDUP            = 996609,   /**<���س�ʼ�����ݣ��˻��������ƣ���Ӧ��¼�����ظ�                       */
	TS_WARNING_ACCOUNTRESTRICTKEYDUP            = 996610,   /**<���س�ʼ�����ݣ�֤ȯ�˻����ƣ���Ӧ��¼�����ظ�                       */
	TS_WARNING_MAKERRESTRICTKEYDUP              = 996611,   /**<���س�ʼ�����ݣ��������ƣ���Ӧ��¼�����ظ�                           */
	TS_WARNING_FORBIDTIMERESTRICTKEYDUP         = 996612,   /**<���س�ʼ�����ݣ��걨��ֹҵ��ʱ�䣩��Ӧ��¼�����ظ�                   */
	TS_WARNING_MATCHTIMEKEYDUP                  = 996613,   /**<���س�ʼ�����ݣ���Ͻ��׽׶�ʱ�����ã���Ӧ��¼�����ظ�               */

	TS_WARNING_EMER_STOCKHOLDERNOTEXIST               = 996801,   /**<����֤ȯ�˻�����ά��ָ��ʱ���ֶ�Ӧ֤ȯ�˻�������                     */
	TS_WARNING_EMER_ACCRESTRICT_STOCKHOLDERNOTEXIST   = 996802,   /**<����֤ȯ�˻��������ƽ���ά��ָ��ʱ���ֶ�Ӧ֤ȯ�˻�������             */
	TS_WARNING_EMER_ACCRESTRICT_RESTRICTIONNOTEXIST   = 996803,   /**<����֤ȯ�˻��������ƽ���ά��ָ��ʱ����Ҫ��ɾ���Ľ������Ʋ�����       */
	TS_WARNING_EMER_ACCRESTRICT_ORDERERROR            = 996804,   /**<����֤ȯ�˻��������ƽ���ά��ָ��ʱ���ֶ�Ӧָ����Ϣ����ȷ             */
	TS_WARNING_EMER_PARA_STOCKCODENOTEXIST            = 996805,   /**<����֤ȯ���ײ�������ά��ָ��ʱ���ֶ�Ӧ֤ȯ���벻����                 */
	TS_WARNING_EMER_BUSITYPE_STOCKCODENOTEXIST        = 996806,   /**<����֤ȯҵ��������ά�����ֶ�Ӧ֤ȯ���벻����                       */
	TS_WARNING_EMER_UNITNORESTRICT_UNITNONOTEXIST     = 996807,   /**<�����׵�Ԫ�������ƽ���ά��ָ��ʱ���ֶ�Ӧ���׵�Ԫ������             */
	TS_WARNING_EMER_UNITNORESTRICT_RESTRICTIONNOTEXIST = 996808,   /**<�����׵�Ԫ�������ƽ���ά��ָ��ʱ����Ҫ��ɾ���Ľ������Ʋ�����       */
    TS_WARNING_EMER_UNITNORESTRICT_ORDERERROR         = 996809,   /**<�����׵�Ԫ�������ƽ���ά��ָ��ʱ���ֶ�Ӧָ����Ϣ����ȷ             */
    TS_WARNING_EMER_BUSITYPE_BUSITYPENOTEXIST         = 996810,   /**<����֤ȯҵ��������ά�����ֶ�Ӧ֤ȯ��������ҵ����𲻴���           */
    TS_WARNING_EMER_NOTINTEMPCLOSING               = 996811,   /**<�����ֹ�����ʱ����ϵͳ��δ������ʱ����״̬                     */

	TS_INFO_START                                   = 998001,   /**<�������������ʼ                                                     */
	TS_INFO_START_MULTICASTRECVERLOGOBJECT          = 998002,   /**<��ʼ������¼�鲥������־����                                         */
	TS_INFO_FINISH_MULTICASTRECVERLOGOBJECT         = 998003,   /**<������¼�鲥������־�������                                         */
	TS_INFO_START_MONMEMORYOBJECT                   = 998004,   /**<��ʼ����ڴ���ʶ���                                                 */
	TS_INFO_FINISH_MONMEMORYOBJECT                  = 998005,   /**<��������ڴ���ʶ������                                             */
	TS_INFO_START_PREINITDATA                       = 998006,   /**<��ʼ����Ԥ��ʼ������                                                 */
	TS_INFO_FINISH_PREINITDATA                      = 998007,   /**<����Ԥ��ʼ���������                                                 */
	TS_INFO_START_QUOTATION                             = 998008,   /**<��ʼ��������ģ��                                                     */
	TS_INFO_FINISH_QUOTA                            = 998009,   /**<��������ģ�����                                                     */
	TS_INFO_START_INITDATA                          = 998010,   /**<��ʼ���س�ʼ������                                                   */
	TS_INFO_FINISH_INITDATA                         = 998011,   /**<���س�ʼ���������                                                   */
	TS_INFO_START_MATCH                             = 998012,   /**<��ʼ�������״��ģ��                                                 */
	TS_INFO_FINISH_MATCH                            = 998013,   /**<�������״��ģ�����                                                 */
	TS_INFO_START_LOCALDATA                         = 998014,   /**<��ʼ���ر����ѽ�������                                               */
	TS_INFO_END_LOCALDATA                           = 998015,   /**<���ر����ѽ����������                                               */
	TS_INFO_START_MULTICASTRECVER                   = 998016,   /**<��ʼ�����鲥����ģ��                                                 */
	TS_INFO_FINISH_MULTICASTRECVER                  = 998017,   /**<�����鲥����ģ�����                                                 */
	TS_INFO_FINISH                                  = 998018,   /**<��������������                                                     */

	TS_INFO_CREATE_MATCHTIMEORDER                   = 998020,   /**<����������ɽ��׽׶�ʱ���л�ָ��                                     */

	TS_INFO_BEGIN_STOP                              = 998051,   /**<���������ʼֹͣ����                                                 */
	TS_INFO_BEGIN_STOPMULTICASTRECV                 = 998052,   /**<���������ʼֹͣ�鲥����                                             */
	TS_INFO_FINISH_STOPMULTICASTRECV                = 998053,   /**<�������ֹͣ�鲥�������                                             */
	TS_INFO_BEGIN_STOPQUOTA                         = 998054,   /**<���������ʼֹͣ����ģ��                                             */
	TS_INFO_FINISH_STOPQUOTA                        = 998055,   /**<�������ֹͣ����ģ�����                                             */
	TS_INFO_BEGIN_STOPMATCH                         = 998056,   /**<���������ʼֹͣ���״��ģ��                                         */
	TS_INFO_FINISH_STOPMATCH                        = 998057,   /**<�������ֹͣ���״��ģ�����                                         */
	TS_INFO_BEGIN_STOPMULTICASTSENDER               = 998058,   /**<���������ʼֹͣ�鲥����                                             */
	TS_INFO_FINISH_STOPMULTICASTSENDER              = 998059,   /**<�������ֹͣ�鲥�������                                             */
	TS_INFO_BEGIN_STOP_MULTICASTRECVERLOGOBJECT     = 998060,   /**<���������ʼ�ر��鲥����������־ģ��                                 */
	TS_INFO_FINISH_STOP_MULTICASTRECVERLOGOBJECT    = 998061,   /**<��������ر��鲥����������־ģ�����                                 */
	TS_INFO_BEGIN_STOP_MONMEMERY                    = 998062,   /**<���������ʼ�رղ��ͷż�ع����ڴ�                                   */
	TS_INFO_FINISH_STOP_MONMEMERY                   = 998063,   /**<��������رղ��ͷż�ع����ڴ����                                   */
	TS_INFO_FINISH_STOP                             = 998064,   /**<�������ֹͣ���̽���                                                 */
    TS_INFO_STOP_FAILED                             = 998065,   /**<�������ֹͣʧ��                                                     */
    TS_INFO_FINISH_STOPFAILED                       = 998066,   /**<�����������ʧ��                                                     */
    TS_INFO_ALLCLOSEORDER_NOTRECV                   = 998067,   /**<��������ѷ�������ָ���û���յ�ȫ�г�����ָ��                     */

    TS_DEBUG_CHECKFAILED                            = 998100,   /**<�������У��ʧ��                                                    */
    TS_DEBUG_VALIDRANGE                             = 998101,   /**<���������ϳɽ���Ч�۸�����                                                 */
    TS_NOTICE_READINGDBF                            = 998155,   /**<���������ȡDBF��                                                   */
	TS_DEBUG_GETMEMORYINFO                          = 998900,   /**<���������ȡ�ڴ�ṹ��Ϣ                                             */
    /*****************************add by shoujj 2013-09-28 ���״��ģ���¼�������*******************************/

	/*******************************************���󼶱�����*******************************************/
	TS_ERROR_ENTRUSTNULL							  = 999401,  /**< ȡ��һ��У��ͨ���Ŀ�ί�е� */
	TS_ERROR_MATCHDOTPATHNULL						  = 999402,  /**< ��ϵ���·��Ϊ��*/
	TS_ERROR_CONVENTION_LESS						  = 999403,  /**<Լ���ŷ�Χ����ȷ*/
	TS_ERROR_COMMON_PUTNEW							  = 999404,  /**<�޼�����������ʧ��*/
	TS_ERROR_COMMON_REMOVE							  = 999405,  /**<�������Ƴ�ʧ��*/
	TS_ERROR_NOTRMSENDER							  = 999406,  /**<�����鲥ʧ��*/
	TS_ERROR_NOTMAKEQUOTATION                         = 999407,  /**���ݴ��͸�����ģ��ʧ��*/
	TS_ERROR_NOTEVENTNOTIFY							  = 999408,  /**����߳��¼�֪ͨʧ�ܣ����ܴ���ί�е�*/
	TS_ERROR_NOTUNLOAD								  = 999409,  /**ָ����ϵ�ж��ʧ��*/
	TS_ERROR_NOTLOAD                                  = 999410,  /**ָ����ϵ���س�ʼ��ʧ��*/
	TS_ERROR_LOADSO_FAIL							  = 999411,  /**ָ����ϵ�������ʧ��*/
	TS_ERROR_MATCHDOT_NUM_LARGE						  = 999412,  /**��ȡ�Ĵ�ϵ�ų��������ţ���������ʹ��*/
	TS_ERROR_MATCHDOTFUN_NOTEXITST					  = 999413,  /**��ϵ���ָ���Ľӿں��������ڣ���������ʹ��*/
	TS_ERROR_MATCHDOT_NOTEXITST						  = 999414,  /**ָ��Ŀ¼��û���ҵ��Ϸ��Ĵ�ϵ㣬���ģ�鲻����������*/
	TS_ERROR_MATCHORDER_NOTEXITST					  = 999415,  /**��Ч�Ĵ��ָ��������������л�*/
	TS_ERROR_MATCHORDER_NOTINSERT                     = 999416,  /**��ָ���϶�������������Map��׼�����*/
	TS_ERROR_MATCHOBJET_NOTCREATE					  = 999417,  /**ָ���϶������������ɹ����⽫���²��ܽ��и�ָ����*/
	TS_ERROR_SENDDATAWRITE_FAIL						  = 999418,  /**�������ʧ�ܣ����ܴ��̿ռ�����*/
	TS_ERROR_SUSPENDORDERE_FAIL						  = 999419,  /**���벻���ڣ�ͣ����ָ��ִ��ʧ��*/
	TS_ERROR_INITRETURNFILE_FAIL					  = 999420,  /**��ʼ���ر��ɽ���������ļ�ʧ��*/
	TS_ERROR_CODETRAY_CLEAR_FAIL					  = 999421,  /**���������ʧ��*/
	TS_ERROR_MATCHDEAL_FAIL							  = 999422,  /**��ϴ���ʧ��*/
	TS_ERROR_NOTEXPECT_ORDER						  = 999423,  /**û�л�ȡ��������ָ��*/

	/*******************************************���漶������*******************************************/
	//TS_WARNING_STOCK_NOTENOUGH						  = 999501,  /**���㣬����������������*/
	//TS_WARNING_STOCK_NOTMULTIPLE					  = 999502,  /**������������������������������������*/
	//TS_WARNING_STOCK_LESSMINAMOUNT					  = 999503,  /**С����С�µ�����, ����������������*/
	//TS_WARNING_NOENTRUST							  = 999504,  /**����ԭʼ�������ڻ�����ȫ���ɽ�*/
	//TS_WARNING_INVALID_SORT							  = 999505,  /**�˽��׽׶�Ϊ�Ƿ����ֽ��г�������*/
	//TS_WARNING_NOT_WITHDRAWALS						  = 999506,  /**���ܽ��г��������������������ϵ�����*/
	//TS_WARNING_REPEATENTRUST						  = 999507,  /**֮ǰ�Ѿ������˺�ͬ��ί�е�, �ֲ�����*/
	//TS_WARNING_ENTRUSTNOTDEAL						  = 999508,  /**�˴����Ѿ����У����κ�ί�ж��Ų�����*/
	//TS_WARNING_MARKET_ONLYBOTH						  = 999509,  /**������˫�򱨼۵����ִ��˻�֮ǰ�ѱ��������ּ���֮ǰ��δ�ɽ����ȳ�����*/
	//TS_WARNING_MARKET_BOTHEXIST						  = 999510,  /**�յ�һ���µĵ��򱨼۵�, �����Ѵ���һ��˫�򱨼۵�, ���˵��򱨼۵�������������*/
	//TS_WARNING_MARKET_SINGLEEXIST					  = 999511,  /**�յ�һ���µĵ��򱨼۵�, �����Ѵ���һ�ʷ����򱨼۵�, ���˵��򱨼۵�������������*/
	//TS_WARNING_MARKET_ONLYSINGLE					  = 999512,  /**�յ�һ���µĵ��򱨼۵�, �����Ѵ���һ�ʵ��򱨼۵�, ��֮ǰ��δ�ɽ����ȳ�����*/
	//TS_WARNING_TREATY_RICEERROR						  = 999513,  /**������Ч�۸�����, ����������������*/
	//TS_WARNING_TREATY_LIMITCONFIRM_WITHDRAWALS		  = 999514,  /**�޼�ȷ�ϵ�û��ȫ���ɽ���ϣ�����������������*/
	//TS_WARNING_TREATY_CONFIRM_WITHDRAWALS			  = 999515,  /**ȷ�ϵ��ҵ����ַ�, ������δƥ��, ����������������������*/
	//TS_WARNING_TREATY_FIXEDCONFIRM_WITHDRAWALS		  = 999516,  /**����ȷ�ϵ��ҵ����ַ�, ������δƥ��, ��������ȷ�ϵ���������*/
	//TS_WARNING_UNABLEENTRUSTINCLOSE					  = 999517,  /**�ڱ���֮�䲻����ί�е�*/
	//TS_WARNING_GREATERTHAN_HIGHPRICE				  = 999518,  /**ί�м۸���ڵ�����߼�*/
	//TS_WARNING_LESSTHAN_LOWPRICE					  = 999519,  /**ί�м۸�С�ڵ�����ͼ�*/
	//TS_WARNING_GREATERTHAN_PREPRICE                   = 999520,  /**ί�м۸�������ռ۱�*/
	//TS_WARNING_LESSTHAN_PREPRICE					  = 999521,  /**ί�м۸�С�����ռ۱�*/
	//TS_WARNING_NOPREPRICE					          = 999522,  /**û��ǰ���̼�*/
	TS_WARNING_NOLASTMATCHORDER						  = 999501,	 /**�Դ�����и���ʱ��û���ҵ���һ�����ָ��׶�*/


	/*******************************************֪ͨ��������*******************************************/
	TS_NOTICE_ENGINESTART							  = 999601,  /**���ģ������������*/
	TS_NOTICE_ENGINESTOP							  = 999602,  /**���ģ��������ֹͣ*/
	TS_NOTICE_ENGINESTARTFAIL						  = 999603,  /**���ģ����������ʧ��*/
	TS_NOTICE_MATCHDOTLOAD							  = 999604,  /**���ش�ϵ�ɹ�, �ɽ������ָ�����*/
	TS_NOTICE_MATCHSWITCH							  = 999605,  /**���ָ���л�*/

	/*******************************************��Ϣ��������*******************************************/
	TS_INFO_MATCHTHREAD_START						  = 999701,  /**����߳�����������*/
	TS_INFO_MATCHTHREAD_OVER						  = 999702,  /**����߳��������˳�*/

	/*******************************************���Լ�������*******************************************/
	TS_DEBUG_WITHDRAWAL								  = 999801,  /**��ͨ���ɹ����ɳ����ر�*/
	TS_DEBUG_MARKET_WITHDRAWAL						  = 999802,  /**���е��ɹ����ɳ����ر�*/
	TS_DEBUG_COMMON_PUTNEW							  = 999803,  /**�ɹ������޼�������*/
	TS_DEBUG_TREATY_PUTNEW							  = 999804,  /**�ɹ������޼������������Զ�����Լ����*/
	TS_DEBUG_TREATY_CONFIRMPUTNEW					  = 999805,  /**�ɹ�����ȷ��������*/
	TS_DEBUG_MARKET_PUTNEW							  = 999806,  /**�ɹ��������б��۵�*/
	TS_DEBUG_CAllAUCTION_ISSUE						  = 999807,  /**���Ͼ��۽׶η���������ƥ���*/
	TS_DEBUG_DEALQUEUE								  = 999808,  /**Ŀǰ����ʱ�����, ������������*/
	TS_DEBUG_RETURNINFO								  = 999809,  /**��ͨ���״�ϳɽ��ɹ�*/
	TS_DEBUG_MARKET_RETURNINFOOFMAKER				  = 999810,  /**��������Ͷ���˴�ϳɽ��ɹ�*/
	TS_DEBUG_MARKET_RETURNINFOOFINVESTOR			  = 999811,  /**Ͷ�����������̴�ϳɽ��ɹ�*/
	TS_DEBUG_TREATY_RETURNINFO						  = 999812,  /**Э�齻�״�ϳɽ��ɹ�*/
	TS_DEBUG_REMOVE									  = 999813,  /**Ͷ���˳ɽ���ϴ������Ƴ�*/
	TS_DEBUG_MARKET_REMOVE							  = 999814,  /**�����̳ɽ���ϴ������Ƴ�*/
	TS_DEBUG_TIMEORDERDEAL							  = 999815,  /**�յ�ָ��ŶԴ�����д���*/
	TS_DEBUG_EVENTNOTIFY							  = 999816,	 /**���״��ģ���յ�һ��֪ͨ���ֽ��й���*/
	TS_DEBUG_CAllAUCTION_COMPUTE					  = 999817,  /**��ί�д������Ͼ��ۼ���*/
	TS_DEBUG_STOCK_FROZEN							  = 999818,  /**�ɷݶ�������*/
	TS_DEBUG_STOCK_CURRENT_ADD						  = 999819,  /**�ɷ���������*/
	TS_DEBUG_STOCK_CURRENT_DECR						  = 999820,	 /**�ɷ�������������*/
	TS_DEBUG_STOCK_FROZEN_DECR						  = 999821,	 /**�ɷݶ���ؼ�����*/
	TS_DEBUG_BUSINESSCOUNT							  = 999822,  /**�����ɽ����������͸��鲥ģ��*/
	TS_DEBUG_CODEDUMPSTART							  = 999823,  /**������dump��ʼ*/
	TS_DEBUG_PRICENODEDUMP							  = 999824,  /**�۸�λ�����Ϣ*/
	TS_DEBUG_ENTRUSTDUMP							  = 999825,	 /**ί�нڵ������Ϣ*/
	TS_DEBUG_CODEDUMPSTOP							  = 999826,   /**������dump����*/
	TS_DEBUG_DEALCOUNTOFPERSECOND					  = 999827,	 /**��¼���ģ��ÿ�봦��ı���*/
	TS_DEBUG_TREATY_LIMITCONFIRM_WITHDRAWALS		  = 999828,  /**�޼�ȷ�ϵ�û��ȫ���ɽ���ϣ�����������������*/
	TS_DEBUG_MARKET_ONLYBOTH                          = 999829,  /**������˫�򱨼۵����ִ��˻�֮ǰ�ѱ��������ּ���֮ǰ��δ�ɽ����ȳ�����*/

    TS_DEBUG_STOCK_NOTENOUGH						  = 999830,  /**���㣬����������������*/
    TS_DEBUG_STOCK_NOTMULTIPLE					      = 999831,  /**������������������������������������*/
    TS_DEBUG_STOCK_LESSMINAMOUNT					  = 999832,  /**С����С�µ�����, ����������������*/
    TS_DEBUG_NOENTRUST							      = 999833,  /**����ԭʼ�������ڻ�����ȫ���ɽ�*/
    TS_DEBUG_INVALID_SORT							  = 999834,  /**�˽��׽׶�Ϊ�Ƿ����ֽ��г�������*/
    TS_DEBUG_NOT_WITHDRAWALS						  = 999835,  /**���ܽ��г��������������������ϵ�����*/
    TS_DEBUG_REPEATENTRUST						      = 999836,  /**֮ǰ�Ѿ������˺�ͬ��ί�е�, �ֲ�����*/
    TS_DEBUG_ENTRUSTNOTDEAL						      = 999837,  /**�˴����Ѿ����У����κ�ί�ж��Ų�����*/
    TS_DEBUG_MARKET_BOTHEXIST						  = 999838,  /**�յ�һ���µĵ��򱨼۵�, �����Ѵ���һ��˫�򱨼۵�, ���˵��򱨼۵�������������*/
    TS_DEBUG_MARKET_SINGLEEXIST					      = 999839,  /**�յ�һ���µĵ��򱨼۵�, �����Ѵ���һ�ʷ����򱨼۵�, ���˵��򱨼۵�������������*/
    TS_DEBUG_MARKET_ONLYSINGLE					      = 999840,  /**�յ�һ���µĵ��򱨼۵�, �����Ѵ���һ�ʵ��򱨼۵�, ��֮ǰ��δ�ɽ����ȳ�����*/
    TS_DEBUG_TREATY_RICEERROR						  = 999841,  /**������Ч�۸�����, ����������������*/
    TS_DEBUG_TREATY_CONFIRM_WITHDRAWALS			      = 999842,  /**ȷ�ϵ��ҵ����ַ�, ������δƥ��, ����������������������*/
    TS_DEBUG_TREATY_FIXEDCONFIRM_WITHDRAWALS		  = 999843,  /**����ȷ�ϵ��ҵ����ַ�, ������δƥ��, ��������ȷ�ϵ���������*/
    TS_DEBUG_UNABLEENTRUSTINCLOSE					  = 999844,  /**�ڱ���֮�䲻����ί�е�*/
    TS_DEBUG_GREATERTHAN_HIGHPRICE				      = 999845,  /**ί�м۸���ڵ�����߼�*/
    TS_DEBUG_LESSTHAN_LOWPRICE					      = 999846,  /**ί�м۸�С�ڵ�����ͼ�*/
    TS_DEBUG_GREATERTHAN_PREPRICE                     = 999847,  /**ί�м۸�������ռ۱�*/
    TS_DEBUG_LESSTHAN_PREPRICE					      = 999848,  /**ί�м۸�С�����ռ۱�*/
    TS_DEBUG_NOPREPRICE					              = 999849,  /**û��ǰ���̼�*/
    TS_DEBUG_REMOVE_WITH_ORDERNO                      = 999850
	/************************************************************************************************************/
};

/*
enum ArbEventId
{
	  I_RUN_LOG                   = 955000,   // ������־
	  E_PARAMETER_CONFIG_ERROR   ,   // �������ļ��в�������
	  E_CREATE_SERVER_FAILED     ,   // TCP SERVER����ʧ��
	  E_CREATE_SHM_FAILED        ,   // ���������ڴ�ʧ��
          E_OPEN_SHM_FAILED          ,
          E_FSTAT_SHM_FAILED         ,
          E_MMAP_FAILED              ,
	  E_OPEN_FILE_FAILED         ,   // ���ļ�ʧ��
	  E_ACD_ID_ERROR             ,   // �Ŷӻ���ʾID��
	  E_ACD_STATUS_ERROR         ,   // �Ŷӻ�״̬��
	  E_ARB_MESSAGE_ERROR        ,   // �Ƿ��ٲð�������
	  E_TCP_CONNECT_ERROR        ,   // TCP���ӳ���
          E_UNKNOW_SOCKET_INDEX      ,
          E_ACD_NO_RESPONE           ,   // ACD��TIME OUTʱ��û�κ���Ϣ
	  E_ACTION_TYPE_ERROR        ,   // �ٲ�Ҫ���Ŷӻ�ִ�еĶ������ͷǷ�
          E_ACD_EVENT_ERROR          ,   // �Ŷӻ����͵��¼��Ƿ�
          E_NEW_OBJECT_FAILED        ,   // �������ʧ��
          E_SEND_DATA_FAILED         ,   //  TCP��������ʧ��
          E_TCP_DISCONNECTED         ,   // TCP���ӶϿ�
          E_LOST_ACD_CONNECTION      ,   // �Ŷӻ��ڹ涨��ʱ����û�������ٲû�
          E_PROCESS_STOP             ,   // ҵ�������CRASH
          E_CONNECT_SERVER_FAILED    ,   // ����TCP SERVERʧ��
          E_VALUE_ILLEGAL            ,   // ����ֵ����ȡֵ��Χ�ڻ򲻺Ϸ���������
          E_STRING_LENGTH_EXCEED     ,   // �ַ������ȳ���
          E_FORK_PROCESS_FAILED      ,   //  Fork�ӽ���ʧ��
          E_MALLOC_FAILED            ,   // malloc �����ڴ�ʧ��
          E_GET_QUEUE_SIZE_FAILED    ,   // ��ȡPOSIX��Ϣ���д�Сʧ��
          E_READ_QUEUE_FAILED        ,   // ��POSIX��Ϣ���ж�ȡ��Ϣʧ��
          E_WRITE_QUEUE_FAILED       ,
          E_OPEN_QUEUE_FAILED        ,   // ��POSIX��Ϣ����ʧ��
          E_SYNC_MESSAGE_ERROR       ,   // �Ƿ�ͬ����������
          E_SYNC_FAILED              ,   //  ͬ��ʧ��
          E_OPEN_SEM_FAILED          ,
          E_CLOSE_SEM_FAILED         ,
          E_REMOVE_SEM_FAILED        ,
          E_WAIT_SEM_FAILED          ,
          E_POST_SEM_FAILED          ,
          E_TRY_WAIT_SEM_FAILED      ,
          E_WRITE_FILE_FAILED        ,
          E_GET_DATE_FAILED          ,
          E_HANDLER_ERROR            ,
          I_STATUS_CHANGE            ,
          E_OPTION_ERROR             ,
          E_GET_SEM_VALUE_FAILED     ,
          E_MACHINE_TYPE             ,
          E_STAT_TYPE                ,
          E_GET_SYSTEM_TIME          ,


}; */
#endif
