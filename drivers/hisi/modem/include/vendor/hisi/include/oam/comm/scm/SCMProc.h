/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名      : SCMProc.h
  版 本 号      : 初稿
  作    者      : zhuli
  生成日期      : 2012年8月3日
  最近修改      :
  功能描述      : 该头文件为SOCP API的头文件，主要提供给外部部件使用
  函数列表      :
  修改历史      :
  1.日    期    : 2012年8月3日
    作    者    : zhuli
    修改内容    : 创建文件

******************************************************************************/
#ifndef _SCM_PROC_H_
#define _SCM_PROC_H_

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "SOCPInterface.h"
#include "vos.h"

#if(VOS_OS_VER == VOS_LINUX)
#include <asm/dma-mapping.h>
#include <linux/dma-mapping.h>
#include <asm/io.h>
#include <linux/gfp.h>
#include <linux/mm.h>
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

/**************************************************************************
  2 宏定义
**************************************************************************/
/* 编译宏开关 */
#if (VOS_OS_VER == VOS_WIN32)
#define SCM_ACORE
#define SCM_CCORE
#else

#if (OSA_CPU_ACPU == VOS_OSA_CPU)
#define SCM_ACORE
#endif

#if (OSA_CPU_CCPU == VOS_OSA_CPU)
#define SCM_CCORE
#endif

#endif    /*(VOS_OS_VER == VOS_WIN32)*/

/* 通道接收数据和数据长度 */
typedef VOS_VOID (*SCM_CODERDESTFUCN)(SOCP_CODER_DST_ENUM_U32 enChanID,VOS_UINT8 *pucData, VOS_UINT8 *pucPHYData, VOS_UINT32 ulSize);

/* 通道接收数据、数据长度、回卷数据、回卷数据长度 */
typedef VOS_VOID (*SCM_DECODERDESTFUCN)(SOCP_DECODER_DST_ENUM_U32 enChanID,VOS_UINT8 *pucData, VOS_UINT32 ulSize, VOS_UINT8 *pucRBData, VOS_UINT32 ulRBSize);

#if (VOS_OS_VER == VOS_WIN32)               /*PC Stub*/
#define SCM_CODER_SRC_NUM           (4)       /* 编码源通道个数 */
#define SCM_CODER_DST_NUM           (3)       /* 编码目的通道个数 */
#define SCM_DECODER_SRC_NUM         (1)       /* 解码源通道个数 */
#define SCM_DECODER_DST_NUM         (1)       /* 编码目的通道个数 */

#else
#if (OSA_CPU_CCPU == VOS_OSA_CPU)

#if (RAT_MODE != RAT_GU)                /* Mutil Mode */
#define SCM_CODER_SRC_NUM           (4)       /* 编码源通道个数 */
#else                                       /* GU Single Mode */
#define SCM_CODER_SRC_NUM           (1)       /* 编码源通道个数 */
#endif  /* (RAT_MODE != RAT_GU) */

#endif  /* (OSA_CPU_CCPU == VOS_OSA_CPU) */

#if (OSA_CPU_ACPU == VOS_OSA_CPU)

#if (RAT_MODE != RAT_GU)                /* Mutil Mode */
#define SCM_CODER_SRC_NUM           (3)       /* 编码源通道个数 */
#define SCM_CODER_DST_NUM           (3)       /* 编码目的通道个数 */
#define SCM_DECODER_SRC_NUM         (1)       /* 解码源通道个数 */
#define SCM_DECODER_DST_NUM         (1)       /* 编码目的通道个数 */
#else                                       /* GU Single Mode */
#define SCM_CODER_SRC_NUM           (1)       /* 编码源通道个数 */
#define SCM_CODER_DST_NUM           (1)       /* 编码目的通道个数 */
#endif  /* (RAT_MODE != RAT_GU) */

#endif  /* (OSA_CPU_ACPU == VOS_OSA_CPU) */

#endif /*(VOS_OS_VER == VOS_WIN32)*/


#define SCM_CODER_SRC_MAX_LEN       (16*1024)       /* 编码通道最大发送数据长度  */

#define SCM_DECODER_SRC_SIZE        (8*1024)        /* 解码源通道空间大小 */
#define SCM_DECODER_DST_SIZE        (8*1024)        /* 解码目的通道空间大小 */
#define SCM_CODER_DST_IND_SIZE      (80*1024)       /* 主动上报编码目的通道空间大小 */
#define SCM_CODER_DST_CNF_SIZE      (16*1024)       /* 命令回复编码目的通道空间大小 */

#define SCM_CODER_DST_IND_SD_SIZE   (1024*1229)     /* SD卡主动上报编码目的通道空间大小 1.2M */

#define SCM_CODE_SRC_BD_NUM         (4*1024)        /* 链式通道BD的个数 */
#define SCM_CODE_SRC_RD_NUM         (4*1024)        /* 链式通道RD的个数 */

#define SCM_CODER_SRC_BDSIZE        (sizeof(SOCP_BD_DATA_STRU)*SCM_CODE_SRC_BD_NUM)   /* 链式通道的BD空间 */
#define SCM_CODER_SRC_RDSIZE        (sizeof(SOCP_RD_DATA_STRU)*SCM_CODE_SRC_RD_NUM)   /* 链式通道的RD空间 */

#define SCM_CDOER_DST_THRESHOLD_GU  (4)             /* GU编码目的通道阈值，单位KB */

#define SCM_CDOER_DST_THRESHOLD_L   (4)             /* L编码目的通道阈值，单位KB */

#define SCM_CODER_DST_GTHRESHOLD    ((4*1024)+8)    /* 编码源通道仲裁阈值 */

#define SCM_DECDOER_DST_THRESHOLD   (1)             /* 解码目的通道阈值, 单位HDLC帧 */

#define SCM_CODER_SRC_RD_THRESHOLD  (0)             /* 编码源通道RD阈值 */

#define SCM_DATA_SAVE_TAG           (0x5A)          /* SOCP保存数据的间隔标记 */

#if (VOS_OS_VER == VOS_WIN32)

#ifdef OAM_UT_DEBUG        /*only for UT test*/
#define SCM_MALLOC(ulBytes)         V_MemAlloc(0, 0, ulBytes, 0, 0, 0)
#else                     /*for ST test*/
#define SCM_MALLOC(ulBytes)         malloc(ulBytes)
#endif /* OAM_UT_DEBUG */
#endif /*(VOS_OS_VER == VOS_WIN32)*/

/**************************************************************************
  3 枚举定义
**************************************************************************/
enum  SCM_CHANNEL_INIT_ENUM
{
    SCM_CHANNEL_UNINIT = 0,             /* 未初始化 */
    SCM_CHANNEL_INIT_SUCC,              /* 初始化成功 */
    SCM_CHANNEL_MEM_FAIL,               /* 初始化申请内存错误 */
    SCM_CHANNEL_CFG_FAIL,               /* 初始化通道配置 */
    SCM_CHANNEL_START_FAIL,             /* 通道开启错误 */
    SCM_CHANNEL_INIT_BUTT
};
typedef VOS_UINT32 SCM_CHANNEL_INIT_ENUM_U32;

/**************************************************************************
  4 结构体定义
**************************************************************************/
typedef struct
{
    SCM_CHANNEL_INIT_ENUM_U32   enInitState;    /* 初始化状态 */
    VOS_UINT32                  ulChannelID;    /* 通道ID */
}SCM_CHANNEL_CFG_HEAD;

typedef struct
{
    SCM_CHANNEL_INIT_ENUM_U32   enInitState;    /* 通道初始化状态，初始化后自动修改 */
    SOCP_CODER_SRC_ENUM_U32     enChannelID;    /* 编码源通道ID，固定配置 */
    SOCP_CODER_DST_ENUM_U32     enDstCHID;      /* 编码目的通道ID */
    SOCP_DATA_TYPE_E            enDataType;     /* 数据来源类型 */
    SOCP_ENCSRC_CHNMODE_E       enCHMode;       /* 通道类型 */
    SOCP_CHAN_PRIORITY_E        enCHLevel;      /* 通道优先级 */
    VOS_UINT8                   *pucSrcBuf;     /* 编码源通道数据空间内存指针 */
    VOS_UINT8                   *pucSrcPHY;
    VOS_UINT32                  ulSrcBufLen;    /* 编码源通道数据空间大小 */
    VOS_UINT8                   *pucRDBuf;      /* 编码源通道RD数据空间内存指针 */
    VOS_UINT8                   *pucRDPHY;
    VOS_UINT32                  ulRDBufLen;     /* 编码源通道RD数据空间大小 */
}SCM_CODER_SRC_CFG_STRU;

typedef struct
{
    SCM_CHANNEL_INIT_ENUM_U32   enInitState;    /* 通道初始化状态，初始化后自动修改 */
    SOCP_CODER_DST_ENUM_U32     enChannelID;    /* 编码目的通道ID，固定配置 */
    VOS_UINT8                   *pucBuf;        /* 编码目的通道数据空间指针 */
    VOS_UINT8                   *pucBufPHY;
    VOS_UINT32                  ulBufLen;       /* 编码目的通道数据空间大小 */
    VOS_UINT32                  ulThreshold;    /* 编码目的通道阈值 */
    SCM_CODERDESTFUCN           pfunc;          /* 编码目的通道数据处理回调函数 */
}SCM_CODER_DEST_CFG_STRU;


typedef struct
{
    SCM_CHANNEL_INIT_ENUM_U32   enInitState;    /* 通道初始化状态，初始化后自动修改 */
    SOCP_DECODER_SRC_ENUM_U32   enChannelID;    /* 解码源通道ID，固定配置 */
    VOS_UINT8                   *pucSrcBuf;     /* 解码源通道数据空间指针 */
    VOS_UINT8                   *pucSrcPHY;
    VOS_UINT32                  ulSrcBufLen;    /* 解码源通道数据空间大小 */
}SCM_DECODER_SRC_CFG_STRU;

typedef struct
{
    SCM_CHANNEL_INIT_ENUM_U32   enInitState;    /* 通道初始化状态，初始化后自动修改 */
    SOCP_DECODER_DST_ENUM_U32   enChannelID;    /* 解码目的通道ID，固定配置 */
    SOCP_DECODER_SRC_ENUM_U32   enSrcCHID;      /* 解码源通道ID */
    SOCP_DATA_TYPE_E            enDataType;     /* 解码数据来源类型 */
    VOS_UINT8                   *pucBuf;        /* 解码目的数据空间指针 */
    VOS_UINT8                   *pucBufPHY;
    VOS_UINT32                  ulBufLen;       /* 解码目的数据空间大小 */
    VOS_UINT32                  ulThreshold;    /* 解码目的通道阈值 */
    SCM_DECODERDESTFUCN         pfunc;          /* 解码目的通道数据处理回调函数 */
}SCM_DECODER_DEST_CFG_STRU;


typedef struct
{
    VOS_UINT32                  aulBDUsedMax[SCM_CODER_SRC_NUM];    /* 记录上层调用的发送源通道BD使用最大值 */
    VOS_UINT32                  aulRDUsedMax[SCM_CODER_SRC_NUM];    /* 记录上层调用的发送源RD使用最大值 */
    INNER_LOG_DATA_STRU         stCoderSrcLog;                      /* 记录上层调用的发送接口log */
    INNER_LOG_DATA_STRU         stCoderSrcRDLog;                    /* 记录上层调用的释放RD接口log */
    /*INNER_LOG_DATA_STRU         stCoderSrcReset;*/                /* 记录上层调用的复位接口log,暂不使用 */
    INNER_LOG_DATA_STRU         stCoderSrcErr;                      /* 记录编码源通道回调错误Log */
#ifdef SCM_ACORE
    INNER_LOG_DATA_STRU         stCoderDstLog;                      /* 记录回调上层的编码目的通道函数Log */
    INNER_LOG_DATA_STRU         stCoderDstErr;                      /* 记录编码目的通道回调错误Log */
    /*INNER_LOG_DATA_STRU         stDoderSrcLog;*/                  /* 记录上层调用的解码源通道Log,暂不使用 */
    /*INNER_LOG_DATA_STRU         stDecoderDstLog;*/                /* 记录回调上层的解码目的通道函数Log,暂不使用 */
    /*INNER_LOG_DATA_STRU         stDecoderDstErr;*/                /* 记录解码目的通道回调错误Log,暂不使用 */
    /*INNER_LOG_DATA_STRU         stDecoderSrcErr;*/                /* 记录解码源通道回调错误Log,暂不使用 */
#endif
}SCM_INFODATA_STRU;

/**************************************************************************
  5 Log函数定义
**************************************************************************/
#define SCM_CODER_SRC_LOG(pucStr, ulP1, ulP2)\
    OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stCoderSrcLog, VOS_FILE_ID, __LINE__)

#define SCM_CODER_SRCRD_LOG(pucStr, ulP1, ulP2)\
    OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stCoderSrcRDLog, VOS_FILE_ID, __LINE__)

#define SCM_CODER_SRCRESET_LOG(pucStr, ulP1, ulP2)\
    /*OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stCoderSrcReset, VOS_FILE_ID, __LINE__)*/

#define SCM_CODER_SRC_ERR(pucStr, ulP1, ulP2)\
    OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stCoderSrcErr, VOS_FILE_ID, __LINE__)

#define SCM_CODER_DST_ERR(pucStr, ulP1, ulP2)\
    OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stCoderDstErr, VOS_FILE_ID, __LINE__)

#ifdef SCM_ACORE
#define SCM_DECODER_SRC_LOG(pucStr, ulP1, ulP2)\
    /*OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stDoderSrcLog, VOS_FILE_ID, __LINE__)*/

#define SCM_CODER_DST_LOG(pucStr, ulP1, ulP2)\
    OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stCoderDstLog, VOS_FILE_ID, __LINE__)

#define SCM_DECODER_DST_LOG(pucStr, ulP1, ulP2)\
    /*OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stDecoderDstLog, VOS_FILE_ID, __LINE__)*/

#define SCM_CODER_DST_ERR(pucStr, ulP1, ulP2)\
    OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stCoderDstErr, VOS_FILE_ID, __LINE__)

#define SCM_DECODER_DST_ERR(pucStr, ulP1, ulP2)\
    /*OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stDecoderDstErr, VOS_FILE_ID, __LINE__)*/

#define SCM_DECODER_SRC_ERR(pucStr, ulP1, ulP2)\
    /*OM_Inner_Log(pucStr, ulP1, ulP2, &g_stSCMInfoData.stDecoderSrcErr, VOS_FILE_ID, __LINE__)*/
#endif

extern SCM_INFODATA_STRU           g_stSCMInfoData;    /* 用于保存log信息 */

/**************************************************************************
  6 函数定义
**************************************************************************/

extern VOS_UINT32 OM_GetSlice(VOS_VOID);

extern VOS_UINT32 SCM_RlsSrcRDAll(SOCP_CODER_SRC_ENUM_U32 enChanlID, VOS_UINT32 *pulDataAddr, VOS_UINT32 *pulDataLen);

extern VOS_UINT32 SCM_RlsSrcRDFirst(SOCP_CODER_SRC_ENUM_U32 enChanlID,VOS_UINT32 *pulDataAddr,VOS_UINT32 *pulDataLen);

extern VOS_UINT32 SCM_GetBDFreeNum(SOCP_CODER_SRC_ENUM_U32 enChanlID, VOS_UINT32 *pulBDNum);

extern VOS_UINT32 SCM_SendCoderSrc(SOCP_CODER_SRC_ENUM_U32 enChanlID, VOS_UINT8 *pucSendData, VOS_UINT32 ulSendLen);

#if (OSA_CPU_ACPU == VOS_OSA_CPU)
extern VOS_UINT32 SCM_RlsDestBuf(VOS_UINT32 ulChanlID, VOS_UINT32 ulReadSize);

extern VOS_UINT32 SCM_RegCoderDestProc(SOCP_CODER_DST_ENUM_U32 enChanlID,SCM_CODERDESTFUCN func);

extern VOS_UINT32 SCM_RegDecoderDestProc(SOCP_DECODER_DST_ENUM_U32 enChanlID,SCM_DECODERDESTFUCN func);

extern VOS_UINT32 SCM_SendDecoderSrc(SOCP_DECODER_SRC_ENUM_U32 enChanlID, VOS_UINT8 *pucSendData, VOS_UINT32 ulSendLen);

#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif


