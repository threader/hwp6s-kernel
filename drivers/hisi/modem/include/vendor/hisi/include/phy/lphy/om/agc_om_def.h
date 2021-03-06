


#ifndef __AGC_OM_DEF_H__
#define __AGC_OM_DEF_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
/************************************************************
                     包含其它模块的头文件
************************************************************/

/************************************************************
                               宏定义
************************************************************/

/************************************************************
                             数据结构定义
************************************************************/

/************************************************************
                             接口函数声明
 ************************************************************/

/************************************************************
                           1. REQ命令和对应的数据结构定义
************************************************************/
typedef enum
{
    LPHY_REQ_AGC_REPORT_ENA         = OM_CMD_ID(LPHY_AGC_MID, OM_TYPE_REQ, 0x1),
    LPHY_REQ_RSSI_DS_FRAME_CONFIG_ENA,
    LPHY_REQ_RSSI_GAP_MODE_CONFIG_ENA,
    LPHY_REQ_RSSI_POINT_CONFIG_ENA,
    LPHY_REQ_RSSI_COMPEMSATE_CONFIG_ENA,

    LPHY_REQ_AAGC_FIXED_RF_GAIN_CONFIG_ENA,
    LPHY_REQ_AAGC_FIXED_PRE_GAIN_CONFIG_ENA,
    LPHY_REQ_AAGC_FIXED_POST_GAIN_CONFIG_ENA,
    LPHY_REQ_AAGC_ANTENNA_ADJUST_CONFIG_ENA,
    LPHY_REQ_AAGC_INTERFERENCE_CONFIG_ENA,
    LPHY_REQ_AAGC_DEM_PERIOD_CONFIG_ENA,
    LPHY_REQ_AAGC_POWER_CALC_CONST_CONFIG_ENA,
    LPHY_REQ_AAGC_PRE_TARGET_CONFIG_ENA,
    LPHY_REQ_AAGC_POST_TARGET_CONFIG_ENA,
    LPHY_REQ_AAGC_PRE_DAGC_ENA,
    LPHY_REQ_AAGC_POST_DAGC_ENA,
    LPHY_REQ_AAGC_NOISE_LOWER_BOUNDARY_CONFIG_ENA,
    LPHY_REQ_AAGC_RS_DIFF_THRE_CONFIG_ENA,
    LPHY_REQ_AAGC_TDD_BLOCK_POWER_THRE_CONFIG_ENA,
    LPHY_REQ_AAGC_TDD_BLOCK_GAIN_STEPSIZE_CONFIG_ENA,

    LPHY_REQ_DAGCF_FIXED_GAIN_CONFIG_ENA,
    LPHY_REQ_DAGCF_ADJ_BIT_CONFIG_ENA,
    LPHY_REQ_DAGCF_EXTRA_PA_CONFIG_ENA,
    LPHY_REQ_DAGCF_SHIFT_BIT_CONFIG_ENA,
    LPHY_REQ_DAGCF_FIXED_NOISE_ENA,

    LPHY_REQ_AGC_SPECIAL_SENARIO_CONFIG_ENA,
    LPHY_REQ_TRIGGER_RFIN_SAMPLING_ENA,
}LPHY_REQ_AGC_ENUM;

typedef enum
{
    AGC_OM_SWITCH_OFF = 0,
    AGC_OM_SWITCH_ON,
}AGC_OM_SWITCH_ENUM;

typedef enum
{
    DEBUG_RFIN_NO_TRIGGER = 0,
    DEBUG_RFIN_SAMPLING_ENABLE,
    DEBUG_RFIN_PBCH_FAILURE,
    DEBUG_RFIN_INTER_FREQ_START,
    DEBUG_RFIN_INTER_FREQ_FINISH,
    DEBUG_RFIN_PRE_DEFINED_SUBFRAME,
    DEBUG_RFIN_DLSCH_CRC,
    DEBUG_RFIN_BCCH_CRC,
    DEBUG_RFIN_PCH_CRC,
    DEBUG_RFIN_TIMING_ERROR,
}LPHY_DEBUG_RFIN_SAMPLING_TYPE_ENUM;
typedef UINT16 LPHY_DEBUG_RFIN_SAMPLING_TYPE_ENUM_UINT16;

typedef struct
{
    LPHY_DEBUG_RFIN_SAMPLING_TYPE_ENUM  enRfinSamplingTrigger;
    UINT32                              ulCounter;
    UINT32                              ulPara;
}LPHY_DEBUG_RFIN_SAMPLING_CTRL_STRU;
typedef struct
{
    AGC_OM_SWITCH_ENUM    enReportEn;    /*1 使能AFC状态上报*/
}LPHY_REQ_AGC_REPORT_ENA_STRU;

typedef enum
{
    AGC_USE_ALL_DS_FRAME = 0,
    AGC_USE_LAST_DS_FRAME,
    AGC_USE_LAST_0_5_DS_FRAME,
}AGC_DEM_SUBFRAME_SEL_ENUM;
typedef UINT16  AGC_DEM_SUBFRAME_SEL_ENUM_UINT16;

typedef enum
{
    AGC_GAP_FAST = 0,
    AGC_GAP_FAST_SLOW =1,
    AGC_GAP_SLOW = 2,
}AGC_GAP_MODE_SEL_ENUM;
typedef UINT16  AGC_GAP_MODE_SEL_ENUM_UINT16;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    INT32     lFixedRssi;

}LPHY_REQ_RSSI_FIXED_VALUE_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    AGC_DEM_SUBFRAME_SEL_ENUM     enDemSubFrameSel;
}LPHY_REQ_RSSI_DS_FRAME_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    AGC_GAP_MODE_SEL_ENUM     enGAPModeSel;
}LPHY_REQ_RSSI_GAP_MODE_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    UINT32    ulRssiPoint;
}LPHY_REQ_RSSI_POINT_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    UINT32    ulRssiCompensate;
}LPHY_REQ_RSSI_COMPEMSATE_CONFIG_ENA_STRU;

typedef enum
{
    AGC_INDEPENDENT_ANTENNA,
    AGC_COMBINED_ANTENNA,
    AGC_NOISE_DECIDED,
    AGC_ON_AIR,
}AGC_ANT_CONFIG_ENUM;
typedef UINT16  AGC_ANT_CONFIG_ENUM_UINT16;

typedef enum
{
    AGC_NO_INTERFERENCE =0,
    AGC_ACS_INTERF_VAR,
    AGC_ACS_INTERF_CONST,
    AGC_NB_INTERF_VAR,
    AGC_NB_INTERF_CONST,
    AGC_INTERF_BUTT,
}AGC_INTERFERENCE_TYPE_ENUM;
typedef UINT16  AGC_INTERFERENCE_TYPE_ENUM_UINT16;

typedef enum
{
    AGC_DEM_PERIOD_1MS = 0,
    AGC_DEM_PERIOD_5MS,
    AGC_DEM_PERIOD_10MS,
    AGC_DEM_PERIOD_20MS,
    AGC_DEM_PERIOD_BUTT,
}AGC_DEM_MODE_SEL_ENUM;
typedef UINT16  AGC_DEM_MODE_SEL_ENUM_UINT16;
typedef enum
{
    AGC_RF_IDX0 = 0,
    AGC_RF_IDX1,
    AGC_RF_IDX2,
    AGC_RF_IDX3,
    AGC_RF_IDX4,
    AGC_RF_IDX5,
    AGC_RF_IDX6,
    AGC_RF_IDX7,
    AGC_RF_IDX8,
    AGC_RF_IDX9,
    AGC_RF_IDX10,
    AGC_RF_IDX11,
    AGC_RF_IDX12,
    AGC_RF_IDX13,
    AGC_RF_IDX14,
    AGC_RF_IDX15,
}AGC_RF_IDX_ENUM;
typedef UINT16  AGC_RF_IDX_ENUM_UINT16;
typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    AGC_RF_IDX_ENUM_UINT16       aenFixedRfIdx[LPHY_MAX_RX_ANTENNA_NUM];
}LPHY_REQ_AAGC_FIXED_RF_GAIN_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    INT16     asFixedPreDagcGain[LPHY_MAX_RX_ANTENNA_NUM];
}LPHY_REQ_AAGC_FIXED_PRE_GAIN_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    INT16     asFixedPostDagcGain[LPHY_MAX_RX_ANTENNA_NUM];
}LPHY_REQ_AAGC_FIXED_POST_GAIN_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    AGC_ANT_CONFIG_ENUM     enAntennaConfig; /* default AGC_ON_AIR*/
}LPHY_REQ_AAGC_ANTENNA_ADJUST_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    AGC_INTERFERENCE_TYPE_ENUM      enInterfConfig;
}LPHY_REQ_AAGC_INTERFERENCE_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
}LPHY_REQ_AAGC_GAIN_SWITCH_DELAY_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
}LPHY_REQ_AAGC_IDX_SWITCH_DELAY_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    AGC_DEM_MODE_SEL_ENUM      enDemPeriodSel;
}LPHY_REQ_AAGC_DEM_PERIOD_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    INT32     lPowerCalcConst;
}LPHY_REQ_AAGC_POWER_CALC_CONST_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    INT32     lPreTarPower;
}LPHY_REQ_AAGC_PRE_TARGET_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    INT32     lPostTarPower;
}LPHY_REQ_AAGC_POST_TARGET_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
}LPHY_REQ_AAGC_PRE_DAGC_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
}LPHY_REQ_AAGC_POST_DAGC_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    UINT32    ulNoiseLimit;
}LPHY_REQ_AAGC_NOISE_LOWER_BOUNDARY_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    UINT32    ulRsDifThre;
}LPHY_REQ_AAGC_RS_DIFF_THRE_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    INT32     lTddBlockPowerThresh;
}LPHY_REQ_AAGC_TDD_BLOCK_POWER_THRE_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    INT32     lTddBlockGainStep;
}LPHY_REQ_AAGC_TDD_BLOCK_GAIN_STEPSIZE_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    UINT32    ulFixedDagcFGain;
}LPHY_REQ_DAGCF_FIXED_GAIN_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    UINT32    ulAdjBit;
}LPHY_REQ_DAGCF_ADJ_BIT_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    UINT32    ulExtraPA;
}LPHY_REQ_DAGCF_EXTRA_PA_CONFIG_ENA_STRU;

typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    UINT32    ulBitShift;
}LPHY_REQ_DAGCF_SHIFT_BIT_CONFIG_ENA_STRU;
typedef struct
{
    AGC_OM_SWITCH_ENUM    enEnable;
    UINT32    ulNoiseFactor;
}LPHY_REQ_DAGCF_FIXED_NOISE_ENA_STRU;
typedef struct
{
    AGC_OM_SWITCH_ENUM    enCase1Enable;
    AGC_OM_SWITCH_ENUM    enCase3Enable;
    AGC_OM_SWITCH_ENUM    enCase4Enable;
    AGC_OM_SWITCH_ENUM    enCase6Enable;
}LPHY_REQ_AGC_SPECIAL_SENARIO_CONFIG_ENA_STRU;

#if 0
/************************************************************
                           2. CNF数据结构定义
************************************************************/
typedef enum
{
    LPHY_CNF_AFC_FIX_PDM_ENA         = OM_CMD_ID(LPHY_AFC_MID, OM_TYPE_CNF, 0x1),

}LPHY_CNF_AFC_ENUM;

typedef struct
{
    UINT32                  ulMsgId;    /*1 CNF消息ID*/
}LPHY_CNF_AFC_FIX_PDM_ENA_STRU;

#endif
/************************************************************
                           3. Sg数据结构定义
************************************************************/

typedef enum
{
    LPHY_SG_AGC_REPORT_ENA         = OM_CMD_ID(LPHY_AGC_MID, OM_TYPE_SG, 0x1),
}LPHY_SG_AGC_ENUM;

typedef struct
{
    INT16     sPreTargetPower;
    INT16     sPostTargetPower;
}AGC_TARGET_POWER_STRU;
typedef struct
{
    INT16     asPreRssidB[LPHY_MAX_RX_ANTENNA_NUM];                /*接收天线0/1的滤波前时域DAGC的RSSI*/
    INT16     asPreDAGCTgain[LPHY_MAX_RX_ANTENNA_NUM];         /*接收天线0/1的滤波前时域DAGC增益*/
    INT16     asPreAntPwrdBm[LPHY_MAX_RX_ANTENNA_NUM];           /*滤波前接收天线1天线口功率,dBm*/
    INT16     asPostRssidB[LPHY_MAX_RX_ANTENNA_NUM];              /*滤波后接收天线0/1的时域DAGC的RSSI*/
    INT16     asPostDAGCTgain[LPHY_MAX_RX_ANTENNA_NUM];       /*滤波后接收天线0/1的时域DAGC增益*/
    INT16     asPostAntPwrdBm[LPHY_MAX_RX_ANTENNA_NUM];          /*滤波后接收天线1天线口功率,dBm*/
    INT16     asAAGCgain[LPHY_MAX_RX_ANTENNA_NUM];             /*接收天线0/1的AAGC增益*/
    UINT16    ausLNAGain[LPHY_MAX_RX_ANTENNA_NUM];             /*当前接收天线0/1的LNA档位*/
    UINT16    ausRFGain[LPHY_MAX_RX_ANTENNA_NUM];
    UINT16    ausRFIdex[LPHY_MAX_RX_ANTENNA_NUM];
    AGC_RF_IDX_ENUM_UINT16    aenFinalIdx[LPHY_MAX_RX_ANTENNA_NUM];
    AGC_INTERFERENCE_TYPE_ENUM_UINT16    aenAAGCIdxSel[LPHY_MAX_RX_ANTENNA_NUM];          /*接收天线0/1索引选择信号*/
    /*last Value*/
    INT16     asLastRfGain[LPHY_MAX_RX_ANTENNA_NUM];      /*接收天线0/1的AAGC增益*/
    INT16     asLastPreAntPwrdBm[LPHY_MAX_RX_ANTENNA_NUM];      /*接收天线0/1的AAGC增益*/

    INT16     asLastAAGCgain[LPHY_MAX_RX_ANTENNA_NUM];      /*接收天线0/1的AAGC增益*/
    INT16     asLastPreDAGCTgain[LPHY_MAX_RX_ANTENNA_NUM];  /*滤波后接收天线0/1的时域DAGC增益*/
    INT16     asLastPostDAGCTgain[LPHY_MAX_RX_ANTENNA_NUM]; /*接收天线0/1的AAGC增益*/
    /*多模增加内容*/
     UINT8    ucFixAgcFlag;                                /*该频点固定AGC标识*/
     UINT8    ucReserved;                                     /*磁滞时能*/
    UINT16   usReserved;
    /*END*/
}AAGC_PARA_STRU;
typedef struct
{
    UINT8     ucCounter1;
    UINT8     ucCounter3;
    INT16     sDAGCFGain;              /*当前子帧DAGCF的增益值*/
    /*UINT16    usDAGCFSftBit;            //根据发送天线个数和系统带宽,当发生带宽切换需要变换*/
    /*UINT16    usDAGCFPAFac;             //根据传输模式和PA索引查表得到,在符号2中断中更新*/
    INT16     sAGCNoiseFactor;         /*噪声因子*/
    UINT16    usDAGCFTar;               /*根据ADJBit得到,计算DAGCF目标功率,在符号2中断中更新*/
    UINT16    usRSREAvgdb[LPHY_MAX_RX_ANTENNA_NUM];
    UINT32    ulRSREAccPower[LPHY_MAX_RX_ANTENNA_NUM];
}DAGCF_PARA_STRU;
typedef struct
{
    UINT8     ucAgcPaValue;                /*PA 索引*/
    UINT8     ucExtraPa;                   /*Extra PA*/
    UINT8     ucIndepAGCFlag;
    UINT8     ucFreqIndex;
	
    UINT8     ucMflag;
    UINT8     ucReserved;
    UINT16    usSubFrameNum;/* = SCHED_GetSubFrmNum();*/

    UINT16    usFreqInfo;
    UINT16    usMs1DagcfGain;
	
    INT16     sOutDiffPowdBm;/*PMCH子帧与之前紧邻的单播子帧滤波后天线口功率之差*/
    UINT16    usMDagcfGain;
    UINT16    usDagcfGainDiff;
    UINT16    usDagcfGainCoef;

    AAGC_PARA_STRU    stAAGCPara;
    DAGCF_PARA_STRU   stDAGCFPara;             /*当前子帧DAGCF的参数*/
} LPHY_SG_AGC_REPORT_ENA_STRU;

/************************************************************
                           4. TRACE数据结构定义
************************************************************/
typedef enum
{
    LPHY_TRACE_AGC_STATE         = OM_CMD_ID(LPHY_AGC_MID, OM_TYPE_TRACE, 0x1),
    LPHY_TRACE_AGC_TDD_BLOCK_EVENT,
    LPHY_TRACE_AGC_SPECIAL_SENARIO_1,
    LPHY_TRACE_AGC_SPECIAL_SENARIO_3,
    LPHY_TRACE_AGC_SPECIAL_SENARIO_4,
    LPHY_TRACE_AGC_SPECIAL_SENARIO_6,
    LPHY_TRACE_AGC_FREQ_INFO,
    LPHY_TRACE_AGC_EMBMS_FRAME,
    LPHY_TRACE_AGC_BAND_INFO,
}LPHY_TRACE_AGC_ENUM;
typedef enum
{
    AGC_BAND_SCAN = 0,                                /*初始模式，供扫频使用，RSSI统计时长FDD1ms/TDD5ms，使用全部符号数据*/
    AGC_INIT_CELL_SEARCH,                             /*初始小区搜索模式，RSSI统计时长5ms，使用全部符号数据*/
    AGC_DEMOD,                                        /*解调模式，RSSI统计使用导频符号*/
    AGC_GAP,                                          /*GAP模式,TDD/FDD,FAST/SLOW在AGC模块内部判断*/
    AGC_DRX,                                          /*DRX模式,TDD/FDD,FASTSLOW/SLOW在AGC模块内部判断*/
    AGC_DIF_SYS,                                      /*异系统调用,暂不实现,预留接口*/
    AGC_IDLE,
    AGC_FIXED_GAIN0,                                  /*固定增益*/
    AGC_FIXED_GAIN1,
    /*多模增加内容*/
    /*END*/
} AGC_WORKING_MODE_ENUM;
typedef UINT16 AGC_WORKING_MODE_ENUM_UINT16;
typedef enum
{
    AGC_INIT_MODE = 0,                                /*初始模式，供扫频使用，RSSI统计时长FDD1ms/TDD5ms，使用全部符号数据*/

    AGC_DEMOD_1MS = 4,                                        /*解调模式，RSSI统计使用导频符号*/
    AGC_DEMOD_5MS = 5,                                        /*解调模式，RSSI统计使用导频符号*/
    AGC_DEMOD_10MS = 6,                                        /*解调模式，RSSI统计使用导频符号*/
    AGC_DEMOD_20MS = 7,                                        /*解调模式，RSSI统计使用导频符号*/

    AGC_GAP_FDD_FAST = 8,                                 /*GAP模式,TDD/FDD,FAST/SLOW在AGC模块内部判断*/
    AGC_GAP_FDD_FAST_SLOW = 9,                            /*GAP模式,TDD/FDD,FAST/SLOW在AGC模块内部判断*/
    AGC_GAP_FDD_SLOW = 10,                                 /*GAP模式,TDD/FDD,FAST/SLOW在AGC模块内部判断*/

    AGC_GAP_TDD_FAST = 12,                                 /*GAP模式,TDD/FDD,FAST/SLOW在AGC模块内部判断*/
    AGC_GAP_TDD_FAST_SLOW = 13,                            /*GAP模式,TDD/FDD,FAST/SLOW在AGC模块内部判断*/
    AGC_GAP_TDD_SLOW = 14,                                 /*GAP模式,TDD/FDD,FAST/SLOW在AGC模块内部判断*/
} AGC_CONFIG_MODE_ENUM;

typedef UINT16 AGC_CONFIG_MODE_ENUM_UINT16;

typedef struct
{
    LTE_BAND_WIDTH_ENUM_UINT16      enAGCRFBW;     /*RF滤波器带宽*/
    LTE_BAND_WIDTH_ENUM_UINT16      enAGCBBBW;     /*基带滤波器带宽*/
} AGC_BW_CHANGE_STRU ;

typedef struct
{
    UINT16                             usAGCFreqInfo; /*AGC频点信息*/
    UINT16                             usBand;
    LTE_FRAME_TYPE_ENUM_UINT16         enFrametype;
    AGC_WORKING_MODE_ENUM_UINT16       enAAGCMode;    /*当前子帧AAGC工作模式*/
    UINT32                             ulBaseCellPos;
    AGC_BW_CHANGE_STRU                 stAGCBWChange; /*AGC带宽变化*/
} AGC_MODE_CFG_REQ_STRU;

typedef struct
{
    UINT32      ulLineNum;
    UINT16      usReserved;
    AGC_CONFIG_MODE_ENUM_UINT16      enLastConfigState;
    AGC_MODE_CFG_REQ_STRU            stAgcModeCfg;
}LPHY_TRACE_AGC_STATE_STRU;
typedef struct
{
    UINT32      ulSubframe;
}LPHY_TRACE_AGC_EMBMS_FRAME_STRU;

typedef enum
{
    AGC_ENTER_TDD_BLOCK_STATE = 0,
    AGC_TDD_BLOCK_INC_PWR,
    AGC_TDD_BLOCK_REACH_MAX_GAIN,
}AGC_TDD_BLK_EVENT_TRACE_ENUM;

typedef struct
{
    INT16     sCounter;
    UINT16    usState;
}AGC_SPECIAL_SENARION_TRACE_STRU;
typedef struct
{
    AGC_TDD_BLK_EVENT_TRACE_ENUM    enEvent;
}LPHY_TRACE_TDD_BLK_STRU;
typedef enum
{
    AGC_CONFIG_SCELL_FREQ_INFO = 0,                     /*配置AGC本频频点信息*/
    AGC_CONFIG_NCELL_FREQ_INFO,                         /*配置AGC异频频点信息*/
    AGC_SWITCH_SCELL_FREQ_INFO,                         /*切换AGC本频频点*/
} AGC_FREQ_CMD_ENUM;
typedef UINT16 AGC_FREQ_CMD_ENUM_UINT16;
#define AGC_FREQ_NUM_MAX         (4)
typedef struct
{
    AGC_FREQ_CMD_ENUM_UINT16            enAGCFreqCmd;
    UINT16                              usServCellBand;
    UINT16                              usAGCNumOfFreq;
    UINT16                             usAGCFreqInfo[AGC_FREQ_NUM_MAX];
} AGC_FREQ_INFO_STRU;

typedef struct
{
    AGC_FREQ_INFO_STRU      stFreqInfo;
}LPHY_TRACE_FREQ_INFO_STRU;
/*band 相关nv buffer*/
typedef enum
{
    AGC_SERV_CELL_NV_INDEX = 0,
    AGC_NEIGHBOR_CELL_NV_INDEX,    
}AGC_CELL_NV_TYPE_ENUM;
typedef UINT16   AGC_CELL_NV_TYPE_ENUM_UINT16;
typedef struct
{
    UINT16    usBandInd;
    AGC_CELL_NV_TYPE_ENUM_UINT16  enCellInd; 
    UINT16    usOldIndex;
    UINT16    usNewIndex;
}LPHY_TRACE_BAND_INFO_STRU;
/************************************************************
                           5. ERROR数据结构定义
************************************************************/
typedef enum
{
    LPHY_ERROR_AGC_ARRAY_INDEX         = OM_CMD_ID(LPHY_AGC_MID, OM_TYPE_ERROR, 0x1),
    LPHY_ERROR_AGC_CASE,
    LPHY_ERROR_AGC_FREQ_INFO,
    LPHY_ERROR_AGC_ISR_BLOCK,
    LPHY_ERROR_AGC_ZERO_DIV,
}LPHY_ERROR_AGC_ENUM;

typedef struct
{
    UINT32      ulLineNum;/*__LINE__*/
    UINT32      ulIncorrectValue;
}LPHY_ERROR_AGC_ARRAY_INDEX_STRU;

typedef struct
{
    UINT32      ulLineNum;/*__LINE__*/
    UINT32      ulCurrentCase;
    UINT32      ulLastCase;
}LPHY_ERROR_AGC_CASE_STRU;

typedef struct
{
    UINT32      ulLineNum;/*__LINE__*/
    UINT32      ulFreqInfo;
}LPHY_ERROR_AGC_FREQ_INFO_STRU;

typedef struct
{
    UINT32      ultimeout;
}LPHY_ERROR_AGC_ISR_BLOCK_STRU;
typedef struct
{
    UINT32      ulAgcMode;
}LPHY_ERROR_AGC_ISR_DELAY_STRU;

#if 0
/************************************************************
                           7. Ind数据结构定义
************************************************************/
typedef enum
{
    LPHY_IND_AGC_STATUS_ENA         = OM_CMD_ID(LPHY_AGC_MID, OM_TYPE_IND, 0x1),
}LPHY_IND_AGC_ENUM;

typedef struct
{
    AGC_WORKING_MODE_ENUM_UINT16    enAGCWorkingMode;                           /*当前AGC模式*/
    AGC_CONFIG_MODE_ENUM_UINT16     enAGCConfigMode;
    UINT16                          usFreqIndex;
    AAGC_FREQ_PARA                  stAAGCPara;
    DAGCF_PARA_STRU                 stDAGCFPara;             /*当前子帧DAGCF的参数*/
    AGC_TDD_BLOCK_PARA              stTDDBlockPara;
}LPHY_IND_AGC_STATUS_ENA_STRU;
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __AGC_OM_DEF_H__ */

