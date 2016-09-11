///NEEQ全局常量定义
/***********************************************************************
系统名称: NEEQ1.0 公共
模块名称: Include
文 件 名: glbdef.h
功能说明: 定义NEEQ全局常量定义、IPC对象（共享内存、信号量）标识、通信端口缺省值等
作    者: 何李夫
开发日期: 2013-7-1   15:55:08
修改记录:
***********************************************************************/
#ifndef _GLBDEF_H_
#define _GLBDEF_H_


#define FALSE           0
#define TRUE            1
#define ERR_ALLOC       -1
#define SUCCEED         0
#define FAIL            -1

#define INIT_SEM_VALUE  0           /* 信号量初始值 */
#define SEM_MAX_VALUE   0x7fffffff  /* 信号量最大值 */

#define TRADE_DURATION  4        /* 交易时间 4个小时 */
#define PERFORMANCE     15000    /* 处理性能: 15000条委托单/秒 */    
#define PEAK            40000    /* 高峰性能：40000条委托单/秒 */

///应用主机类型：应用于监控的主机标识字段
enum AppServerType 
{
    //TEST_SERVER             = 0,    /* 测试主机 */
    TRADE_SERVER            = 1,    /* 交易主机 */
    QUOTATION_SERVER        = 2,    /* 行情主机 */
    SUPERVISE_SERVER        = 3,    /* 监察主机 */
    ORDER_QUEUE_SERVER      = 4,    /* 委托排队机 */
    ORDER_FEP_SERVER        = 5,    /* 委托前置机 */
    ARBITRATE_SERVER        = 6,    /* 委托仲裁机 */
    EXECUTION_FEP_SERVER    = 7,    /* 成交前置机 */
    QUOTATION_FEP_SERVER    = 8,    /* 行情前置机 */
    CLEAR_FEP_SERVER        = 9,    /* 中登前置机 */
    MANAGE_SERVER           = 10,   /* 管理主机 */
    MONITOR_SERVER          = 11,   /* 监控节点 */
    URCOMM_SERVER           = 12,   /* 紧急维护转换机 */
    DB2DBF_SERVER           = 13,   /* 初始化服务 */
    DATAGATEWAY_SERVER      = 14    /* 数据网关 */
};

//////////////////////////////////////////////////////////////////////////
///共享内存文件名，宏定义格式：模块_名称
/// 交易主机监控共享内存
#define TS_MON_SHAREMEMKEY  "TS_MON_SHAREMEM"

/** 成交前置机监控共享内存名称 */
#define REPCOMM_STATUS      "repcomm_status"
/**	紧急维护转换机 */
#define URCOMM_MEMORY       "URCOMM_SHARE"

//////////////////////////////////////////////////////////////////////////
///Order type 类型定义
#define OT_ORDER_TICKET                                 0   	/* 0：  委托数据 */

#define OT_TRADING_FIRST                                1   	/* 1：  最小一个开闭市指令，需要在调整以下开闭市指令时进行调整 */

#define OT_TRADING_START                                1   	/* 1：  开市 */
#define OT_TRADING_START_MATCH                          2   	/* 2：  开始撮合 */
#define OT_BIDDING_CLOSE                                3   	/* 3：  上午竞价休市 */
#define OT_BIDDING_OPEN                                 4   	/* 4：  下午竞价开始 */
#define OT_AFTER_HOURS                                  8   	/* 8：  盘后交易阶段开始 */
#define OT_TRADING_END                                  9   	/* 9：  全天闭市 */


#define OT_TRADING_LAST                                 9   	/* 9：  最大一个开闭市指令，需要在调整以上开闭市指令时进行调整 */

#define OT_TIMESLICE                                    40  	/* 40： 时间片指令 */

#define ORDER_MATCH_BEGIN                               100    /* 撮合指令起始值，所有撮合指令必须在这个范围内 */


#define ORDER_PUBLIC_REST                               100     /* 中午休市指令 */

#define ORDER_PUBLIC_NO_STOCKCODE                       150     /* 该指令为内部指令，特殊使用，当无代码错误时切换到此指令处理*/
    

#define ORDER_CALLAUCTION_TOWNET_NOTISSUE               200 	/* 两网虚拟成交不发布指令 */
#define ORDER_CALLAUCTION_TOWNET_ISSUE                  201 	/* 两网虚拟成交定时发布指令 */
#define ORDER_CALLAUCTION_TOWNET_ISSUE_REST             202  	/* 两网虚拟成交定时发布后中午休市指令 */
#define ORDER_CALLAUCTION_TOWNET_CLOSE                  203  	/* 两网收市集合竞价指令 */
#define ORDER_CALLAUCTION_TOWNET_NOTHANG                204  	/* 两网不挂牌阶段 */

#define ORDER_CALLAUCTION_BID_REVOCABLE                 210		/* 竞价转让集合竞价可撤阶段指令 */
#define ORDER_CALLAUCTION_BID_IRREVOCABLE               211		/* 竞价转让集合竞价不可撤阶段指令 */
#define ORDER_CALLAUCTION_BID_OPEN 						212  	/* 竞价转让开盘集合竞价指令 */
#define ORDER_CALLAUCTION_BID_CLOSE 					213  	/* 竞价转让收市集合竞价指令 */


#define ORDER_BID_NOT_MATCH                             300     /* 竞价转让集合竞价不撮合  */
#define ORDER_BID_NO_WITHDRAW                           301     /* 竞价转让集合竞价不收撤单9:20~9:25 14:55~15:00  */
#define ORDER_BIDDING_AUCTION_MATCH 					302 	/* 竞价转让集合竞价撮合指令 */
#define ORDER_BIDDING_MATCH 						    303 	/* 竞价转让连续竞价撮合指令 */
#define ORDER_BIDDING_AUCTION_MATCH_CLOSE   			304 	/* 竞价转让集合竞价撮合指令后闭市 */


#define ORDER_MARKET_ISSUE 								400    	/* 做市转让行情发布指令 */
#define ORDER_MARKET_MATCH 								401 	/* 做市转让撮合指令 */
#define ORDER_MARKET_TREATY_MATCH 						402   	/* 做市转让协议交易指令令 */
#define ORDER_MARKET_CLOSE	 							403  	/* 做市转让收市指令 */


#define ORDER_TREATY_ISSUE  							500   	/* 协议转让行情发布指令 */
#define ORDER_TREATY_MATCH  							501   	/* 协议转让撮合指令 */
#define ORDER_TREATY_FIX_MATCH_CLOSE                    502     /*协议转让定价申报自动匹配指令 */



#define ORDER_MATCH_END									600    /* 撮合指令结束值, 所有撮合指令必须在这个范围内 */



#define OT_STOCK_ACC_URGENCY_MAINTAIN                   600050  /* 600050： 证券账户紧急维护 */
#define OT_STOCK_ACC_TRADE_LIMIT_URGENCY_MAINTAIN       600051  /* 600051： 证券账户交易限制紧急维护 */
#define OT_STOCK_TRADE_PARAM_URGENCY_MAINTAIN           600052  /* 600052： 证券交易参数紧急维护 */
#define OT_STOCK_BUSINESS_KIND_URGENCY_MAINTAIN         600053  /* 600053： 证券业务类别紧急维护 */
#define OT_PLEDGED_REPO_BONDS_URGENCY_MAINTAIN          600054  /* 600054： 质押式回购债券紧急维护 */
#define OT_MARKETING_UNIT_TRADE_LIMIT_URGENCY_MAINTAIN  600055  /* 600055： 交易单元交易限制紧急维护 */
#define OT_STOCK_TEMP_SUSPEND                           600060  /* 600060： 证券临时停牌 */
#define OT_STOCK_RESUMPTION                             600061  /* 600061： 证券复牌 */
#define OT_MANUAL_CLOSING 								600098	/* 600098:  手工收市 */
#define OT_TEMP_CLOSE                                   600099  /* 600099:  临时停市 */
#define OT_STOCKCODE_DUMP								600062  /* 600062： 证券代码dump到日志文件中，用于测试查找问题*/
#define OT_PUBLIC_INIT                                  800100 	/* 800100：QS初始化发布指令 */
#define OT_PUBLIC_STOCKSNAP                             800101 	/* 800101：QS揭示行情快照指令 */
#define OT_PUBLIC_STOCKINFO                             800102 	/* 800102：QS揭示证券信息指令 */
#define OT_MARKET_CLOSE                                 800103	/* 800103：QS闭市指令 */
#define OT_MARKET_CLOSE2                                800104 	/* 800104：QS闭市指令2 */
#define OT_CLOSING_COMPLETE                             800105 	/* 800105：QS收盘完成指令 */
#define OT_SYSTEM_START                                 800800 	/* 800800：QS系统启动 */
#define OT_STOCK_INFO                                   800801 	/* 800801：QS证券信息数据 */
#define OT_QUOT_INFO                                    800802 	/* 800802：QS证券行情数据 */
#define OT_AGREEMENT_ORDER                              800803 	/* 800803：QS协议定价申报信息 */
#define OT_AGREEMENT_PUBLIC_INFO                        800804 	/* 800804：QS协议转让公开信息 */
#define OT_MARKET_PERSONAL_BUY_ORDER                    800805 	/* 800805：QS做市转让投资者买申报信息 以下四个做市申报信息必须连续*/
#define OT_MARKET_PERSONAL_SALE_ORDER                   800806 	/* 800806：QS做市转让投资者卖申报信息 */
#define OT_MARKET_MAKER_BUY_ORDER                       800807 	/* 800807：QS做市转让做市商买申报信息 */
#define OT_MARKET_MAKER_SALE_ORDER                      800808 	/* 800808：QS做市转让做市商卖申报信息 */
#define OT_MARKET_PUBLIC_INFO                           800809 	/* 800809：QS做市转让公开信息 */
#define OT_MAKER_INFO                                   800810 	/* 800810：QS做市商信息 */ 
#define OT_NORMAL_CONTRACT                              900900 	/* 900900：正常的成交 */
#define OT_VIRTUAL_CONTRACT                             900901 	/* 900901：集合竞价虚拟成交 */

///v1.1需求修改前 交易撮合模块内部使用
//#define OT_END                      					99999999 /* 99999999：表示所有指令处理完毕 */
#define OT_AFTERHOURS_END                      				99999998 /* 99999998：交易主机处理完盘后交易时段成交后发此指令 */
#define OT_NORMALHOURS_END                      			99999999 /* 99999999： 交易主机处理完正常交易时段成交后发此指令*/


#endif
