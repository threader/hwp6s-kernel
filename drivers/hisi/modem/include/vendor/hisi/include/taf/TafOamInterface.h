/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : TafOamInterface.h
  版 本 号   : 初稿
  作    者   : f62575
  生成日期   : 2011年10月11日
  最近修改   :
  功能描述   : TafOamInterface.h 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2011年10月11日
    作    者   : f62575
    修改内容   : 创建文件

******************************************************************************/

#ifndef __TAFOAMINTERFACE_H__
#define __TAFOAMINTERFACE_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "v_msg.h"
#include "TafAppMma.h"
#include "MnMsgApi.h"
#include "MnClient.h"
#include "omnvinterface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
#define SAR_ANTSTATE_IND                            0x1111

#define TAF_STK_CURC_RPT_CFG_MAX_SIZE               (8)

#define    COMM_LOG_PORT_USB                CPM_APP_PORT
#define    COMM_LOG_PORT_VCOM               CPM_VCOM_PORT

/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/

enum TAF_OAM_MSG_TYPE_ENUM
{
    /* SPY/DIAG/OM -> MMA */
    OAM_MMA_PHONE_MODE_SET_REQ          = 0x00,                                 /* _H2ASN_MsgChoice MN_APP_PHONE_MODE_SET_REQ_STRU */
    OAM_MMA_PHONE_LOADDEFAULT_REQ       = 0x01,                                 /* _H2ASN_MsgChoice MN_APP_PHONE_LOADDEFAULT_REQ_STRU */

    /* taf和stk交互消息定义移至NasStkInterface.h */

    /* TAF  -> OAM(VC) 请求OAM的语音端口，无需回复消息 */
    TAF_OAM_SET_TRANS_PORT_REQ          = 0x0f,                                 /* _H2ASN_MsgChoice MN_APP_CS_SET_TRANS_PORT_MSG_STRU */

    /* taf和stk交互消息定义移至NasStkInterface.h */

    /* PHONE -> SPY/DIAG/OM OAM_MMA_PHONE_MODE_SET_REQ的回复消息 */
    TAF_OAM_PHONE_EVENT_IND             = 0x11,                                 /* _H2ASN_MsgChoice MN_APP_PHONE_EVENT_INFO_STRU */

    /* PHONE -> SPY/DIAG/OM OAM_MMA_PHONE_LOADDEFAULT_REQ的回复消息 */
    TAF_OAM_PHONE_SET_CNF               = 0x12,                                 /* _H2ASN_MsgChoice MN_APP_PHONE_SET_CNF_STRU */

    TAF_STK_USSD_DCS_DECODE_HOOK        = 0xAAA0,                               /* _H2ASN_MsgChoice SSA_USSD_DCS_DECODE_HOOK_STRU */

    MMA_EVT_OM_SDT_CONNECTED_IND        = 0xAAAA,


    /* OAM->MMA, TRACE 配置消息 */
    OAM_MMA_TRACE_CONFIG_REQ            = 0xAAAB,

    MMA_OAM_TRACE_CONFIG_CNF,

    TAF_OAM_UNSOLICITED_RPT_INFO_IND,                                       /* _H2ASN_MsgChoice TAF_OAM_UNSOLICITED_RPT_INFO_STRU */

    /* VC  -> OAM 勾出VC模块需要挂断电话时的异常情况 */
    TAF_OAM_LOG_END_CALL_REQ,                                               /* _H2ASN_MsgChoice TAF_OAM_LOG_END_CALL_REQ_STRU */

    /* TAF  -> OAM 紧急呼叫状态消息，无需回复消息 */
    TAF_OAM_EMERGENCY_CALL_STATUS_NOTIFY    = 0xBBB0,                               /* _H2ASN_MsgChoice TAF_OAM_EMERGENCY_CALL_STATUS_STRU */

    TAF_OAM_MSG_TYPE_BUTT
};
typedef VOS_UINT32 TAF_OAM_MSG_TYPE_ENUM_UINT32;


enum TAF_STK_RPT_CMD_INDEX_ENUM
{
    TAF_STK_RPT_CMD_MODE                     = 0,
    TAF_STK_RPT_CMD_RSSI,
    TAF_STK_RPT_CMD_SRVST,
    TAF_STK_RPT_CMD_SIMST,
    TAF_STK_RPT_CMD_TIME,
    TAF_STK_RPT_CMD_SMMEMFULL,
    TAF_STK_RPT_CMD_CTZV,
    TAF_STK_RPT_CMD_DSFLOWRPT,
    TAF_STK_RPT_CMD_ORIG,
    TAF_STK_RPT_CMD_CONF,
    TAF_STK_RPT_CMD_CONN,
    TAF_STK_RPT_CMD_CEND,
    TAF_STK_RPT_CMD_STIN,
    TAF_STK_RPT_CMD_CERSSI,
    TAF_STK_RPT_CMD_ANLEVEL,
    TAF_STK_RPT_CMD_LWCLASH,
    TAF_STK_RPT_CMD_XLEMA,
    TAF_STK_RPT_CMD_ACINFO,
    TAF_STK_RPT_CMD_PLMN,
    TAF_STK_RPT_CMD_CALLSTATE,
    TAF_STK_RPT_CMD_CREG,
    TAF_STK_RPT_CMD_CUSD,
    TAF_STK_RPT_CMD_CSSI,
    TAF_STK_RPT_CMD_CSSU,
    TAF_STK_RPT_CMD_LWURC,
    TAF_STK_RPT_CMD_CUUS1I,
    TAF_STK_RPT_CMD_CUUS1U,
    TAF_STK_RPT_CMD_CGREG,
    TAF_STK_RPT_CMD_CEREG,
    TAF_STK_RPT_CMD_BUTT
};
typedef VOS_UINT8 TAF_STK_RPT_CMD_INDEX_ENUM_UINT8;



enum TAF_APS_USER_CONN_STATUS_ENUM
{
    TAF_APS_USER_CONN_EXIST,
    TAF_APS_USER_CONN_NOT_EXIST,
    TAF_APS_USER_CONN_BUTT
};
typedef VOS_UINT8 TAF_APS_USER_CONN_STATUS_ENUM_UINT8;


enum TAF_OAM_SDT_CONNECT_STATUS_ENUM
{
    TAF_OAM_SDT_CONNECT_STATUS_CONNECTED,                                       /* SDT和单板已连接 */
    TAF_OAM_SDT_CONNECT_STATUS_DISCONNECTED,                                    /* SDT和单板断开连接 */
    TAF_OAM_SDT_CONNECT_STATUS_BUTT
};
typedef VOS_UINT8 TAF_OAM_SDT_CONNECT_STATUS_ENUM_UINT8;


enum TAF_OAM_PC_RECUR_CFG_ENUM
{
    TAF_OAM_PC_RECUR_CFG_ENABLE,                                                /* 使能发送PC回放消息 */
    TAF_OAM_PC_RECUR_CFG_DISABLE,                                               /* 去使能发送PC回放消息 */
    TAF_OAM_PC_RECUR_CFG_BUTT
};
typedef VOS_UINT8 TAF_OAM_PC_RECUR_CFG_ENUM_UINT8;



enum TAF_OAM_EMERGENCY_CALL_STATUS_ENUM
{
    TAF_OAM_EMERGENCY_CALL_START,                                               /* 发起紧急呼叫 */
    TAF_OAM_EMERGENCY_CALL_END,                                                 /* 紧急呼叫结束 */
    TAF_OAM_EMERGENCY_CALL_STATUS_BUTT
};
typedef VOS_UINT8 TAF_OAM_EMERGENCY_CALL_STATUS_ENUM_UINT8;


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT16                         usPrimId;                                /* 消息名 */
    VOS_UINT16                         usReserve;                               /* 保留 */
    VOS_UINT32                         ulStatus;                                /* 命令类型 */
    VOS_UINT32                         ulPort;                                  /* 端口号 */
}MN_APP_CS_SET_TRANS_PORT_MSG_STRU;

/*****************************************************************************
 结构名    : MN_APP_PHONE_MODE_SET_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : STK/SPY发给MMA关机请求
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgId;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           opID;
    VOS_UINT8                           aucReserved1[1];
    TAF_PH_OP_MODE_STRU                 stPhOpMode;
} MN_APP_PHONE_MODE_SET_REQ_STRU;

/*****************************************************************************
 结构名    : MN_APP_PHONE_LOADDEFAULT_REQ_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : STK/SPY发给MMA恢复出厂设置请求
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgId;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           opID;
    VOS_UINT8                           aucReserved1[1];
}MN_APP_PHONE_LOADDEFAULT_REQ_STRU;

/*****************************************************************************
 结构名    : MN_APP_PHONE_EVENT_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : PHONE 发给STK 业务
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgId;
    TAF_PHONE_EVENT_INFO_STRU           stPhoneEvent;
}MN_APP_PHONE_EVENT_INFO_STRU;

/*****************************************************************************
 结构名    : MN_APP_PHONE_SET_CNF_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : PHONE 发给STK 业务
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgId;
    VOS_UINT16                          usClientId;
    VOS_UINT8                           opID;
    VOS_UINT8                           aucReserved1[1];
    TAF_PARA_TYPE                       ucParaType;
    VOS_UINT8                           aucReserved2[3];
    TAF_PARA_SET_RESULT                 ucResult;
}MN_APP_PHONE_SET_CNF_STRU;




/*****************************************************************************
 结构名    : MN_APP_SAR_ANTENSTATUS_MSG_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : OAM发给TAF的ANTEN事件结构
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgId;
    VOS_INT32                           lAntenStatus; /* 天线状态上报给Taf */
} MN_APP_SAR_ANTENSTATUS_MSG_STRU;

/*****************************************************************************
 结构名    : MN_APP_SAR_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 发给DSP的Reduction事件结构
*****************************************************************************/
typedef struct
{
    VOS_UINT32                  ulSarType;      /* 上报操作类型 */
    VOS_INT32                   lAntenStatus;   /* 天线状态 */
    VOS_UINT32                  ulSarReduction; /* 降sar等级 */
}MN_APP_SAR_INFO_STRU;
typedef struct
{
    TAF_OAM_PC_RECUR_CFG_ENUM_UINT8     enPcRecurCfgFlg;
    VOS_UINT8                           aucRsv3[3];
}TAF_OAM_TRACE_CFG_STRU;


typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgId;            /* 原语ID*/

    TAF_OAM_TRACE_CFG_STRU              stTraceCfg;         /* TRACE配置信息 */
}TAF_OAM_TRACE_CFG_IND_STRU;





/* Deleted SSA_USSD_DCS_DECODE_HOOK_STRU by f62575 for V9R1 STK升级, 2013-6-26 */

typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgId;
    VOS_UINT32                          ulRptCmdIndex;
    VOS_UINT8                           aucCurcRptCfg[TAF_STK_CURC_RPT_CFG_MAX_SIZE];
    VOS_UINT8                           aucUnsolicitedRptCfg[TAF_STK_CURC_RPT_CFG_MAX_SIZE];
 }TAF_OAM_UNSOLICITED_RPT_INFO_STRU;



typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                                  ulMsgId;
    TAF_OAM_EMERGENCY_CALL_STATUS_ENUM_UINT8    enEmergencyCallStatus;
    VOS_UINT8                                   aucReserved1[3];
}TAF_OAM_EMERGENCY_CALL_STATUS_STRU;





typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                                              ulMsgId;
    VOS_UINT32                                              ulCause;
}TAF_OAM_LOG_END_CALL_REQ_STRU;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
extern TAF_APS_USER_CONN_STATUS_ENUM_UINT8 TAF_APS_GetUserConnStatus(VOS_VOID);

extern VOS_VOID Spy_SarSendToDsp(MODEM_ID_ENUM_UINT16 enModemID, MN_APP_SAR_INFO_STRU *pstSpyToDsp);

extern VOS_UINT16 Spy_SarGetReduction(VOS_VOID);

/* Deleted by f62575 for V9R1 STK升级, 2013-6-26, begin */
/* Deleted SSA_GetDcsMsgCoding */
/* Deleted by f62575 for V9R1 STK升级, 2013-6-26, end */

extern VOS_VOID SSA_UssdDcsHook(
    VOS_UINT32                          ulReceiverPid,
    VOS_UINT8                           ucDcs,
    MN_MSG_MSG_CODING_ENUM_U8           enMsgCoding
);

extern VOS_UINT32 GU_OamLogPortSwitch(VOS_UINT32  ulPhyPort);

extern VOS_UINT32 GU_OamQueryLogPort(VOS_UINT32  *pulLogPort);

#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of TafOamInterface.h */

