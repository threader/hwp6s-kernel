

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "drv_global.h"


#ifndef __DRV_SYSCTRL_H__
#define __DRV_SYSCTRL_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif



/*****************************************************************************
  2 宏定义
*****************************************************************************/
#define WCDMA_MODE      0
#define GSM_MODE        1
#define LTE_MODE        2
#define TDS_MODE        3

/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 消息头定义
*****************************************************************************/


/*****************************************************************************
  5 消息定义
*****************************************************************************/


/*****************************************************************************
  6 STRUCT定义
*****************************************************************************/


/*****************************************************************************
  7 UNION定义
*****************************************************************************/


/*****************************************************************************
  8 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  9 全局变量声明
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
/*****************************************************************************
 函 数 名  : BSP_GUSYS_DspReset
 功能描述  : 本接口实现ZSP模块的复位动作，包括zsp core、总线和外设。
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
extern void BSP_GUSYS_DspReset(void);
#define DRV_DSP_ZONE_RESET()    BSP_GUSYS_DspReset()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_DspResetCancel
 功能描述  : 本接口实现ZSP模块的解复位动作，包括zsp core、总线和外设。
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
extern void BSP_GUSYS_DspResetCancel(void);
#define DRV_DSP_ZONE_RESET_CANCEL()    BSP_GUSYS_DspResetCancel()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_ABBGSMRxCtrl
 功能描述  : 本接口实现ABB GSM接收控制。
 输入参数  : ucStatus：0：关闭；1：打开。
 输出参数  : 无。
 返 回 值  : 0:  操作成功；
             -1：操作失败。
*****************************************************************************/
extern unsigned int BSP_GUSYS_ABBGSMRxCtrl(unsigned char ucStatus);
#define DRV_ABB_GRX_CTRL(ucStatus)    BSP_GUSYS_ABBGSMRxCtrl(ucStatus)

/*****************************************************************************
 函 数 名  : ABBWCDMARxCtrl
 功能描述  : 本接口实现ABB WCDMA接收控制。
 输入参数  : ucStatus：0：关闭；1：打开。
 输出参数  : 无。
 返 回 值  : 0:  操作成功；
             -1：操作失败。
*****************************************************************************/
extern unsigned int BSP_GUSYS_ABBWCDMARxCtrl(unsigned char ucStatus);
#define DRV_ABB_WRX_CTRL(ucStatus)    BSP_GUSYS_ABBWCDMARxCtrl(ucStatus)

/*****************************************************************************
 函 数 名  : ABBTxCtrl
 功能描述  : 本接口实现ABB 发送控制。
 输入参数  : ucStatus：0：关闭；1：打开。
 输出参数  : 无。
 返 回 值  : 0:  操作成功；
             -1：操作失败。
 注意事项  ：ABB发送控制不区分W/G模式。
*****************************************************************************/
extern int BSP_GUSYS_ABBTxCtrl(unsigned char ucStatus);
#define DRV_ABB_TX_CTRL(ucStatus)    BSP_GUSYS_ABBTxCtrl(ucStatus)

/*****************************************************************************
 函 数 名  : BSP_GUSYS_WcdmaBbpPllEnable
 功能描述  : 本接口实现使能WCDMA BBP PLL。
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
extern void BSP_GUSYS_WcdmaBbpPllEnable(void);
#define DRV_WBBP_PLL_ENABLE()    BSP_GUSYS_WcdmaBbpPllEnable()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_WcdmaBbpPllDisable
 功能描述  : 本接口实现关闭WCDMA BBP PLL。
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
extern void BSP_GUSYS_WcdmaBbpPllDisable(void);
#define DRV_WBBP_PLL_DSABLE()    BSP_GUSYS_WcdmaBbpPllDisable()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_GsmBbpPllEnable
 功能描述  : 本接口实现使能GSM BBP PLL。
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
extern void BSP_GUSYS_GsmBbpPllEnable(void);
#define DRV_GBBP_PLL_ENABLE()    BSP_GUSYS_GsmBbpPllEnable()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_GsmBbpPllDisable
 功能描述  : 本接口实现关闭GSM BBP PLL。
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
extern void BSP_GUSYS_GsmBbpPllDisable(void);
#define DRV_GBBP_PLL_DISABLE()    BSP_GUSYS_GsmBbpPllDisable()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_RFLdoOn
 功能描述  : 本接口实现WCDMA和GSM RF LDO上电。
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
extern void BSP_GUSYS_RFLdoOn(void);
#define DRV_RF_LDOUP()    BSP_GUSYS_RFLdoOn()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_RFLdoDown
 功能描述  : 本接口实现WCDMA和GSM RF LDO下电。
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
extern void BSP_GUSYS_RFLdoDown(void);
#define DRV_RF_LDODOWN(enRfID)    BSP_GUSYS_RFLdoDown()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_WcdmaPllStatusGet
 功能描述  : 读取WCDMA BBP PLL稳定状态。
 输入参数  : 无。
 输出参数  :无。
 返 回 值  :
                     0：稳定
                     1：未稳定
*****************************************************************************/
extern unsigned long BSP_GUSYS_WcdmaPllStatusGet(void);
#define DRV_GET_WCDMA_PLL_STATUS()    BSP_GUSYS_WcdmaPllStatusGet()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_GsmPllStatusGet
 功能描述  : 读取GSM BBP PLL稳定状态。
 输入参数  : 无。
 输出参数  :无。
 返 回 值  :
                     0：稳定
                     1：未稳定
*****************************************************************************/
extern unsigned long BSP_GUSYS_GsmPllStatusGet(void);
#define DRV_GET_GSM_PLL_STATUS()    BSP_GUSYS_GsmPllStatusGet()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_DspPllStatusGet
 功能描述  : 读取DSP PLL稳定状态。
 输入参数  : 无。
 输出参数  :无。
 返 回 值  :
                     0：稳定
                     1：未稳定
*****************************************************************************/
extern unsigned long BSP_GUSYS_DspPllStatusGet(void);
#define DRV_GET_DSP_PLL_STATUS()    BSP_GUSYS_DspPllStatusGet()


/*****************************************************************************
 函 数 名  : BSP_GUSYS_ArmPllStatusGet
 功能描述  : 读取ARM PLL稳定状态。
 输入参数  : 无。
 输出参数  :无。
 返 回 值  :
                     0：稳定
                     1：未稳定
*****************************************************************************/
extern unsigned int BSP_GUSYS_ArmPllStatusGet(void);
#define DRV_GET_ARM_PLL_STATUS()    BSP_GUSYS_ArmPllStatusGet()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_BBPAutoAdjust
 功能描述  : 初始化ABB的自校准使能
 输入参数  : uiSysMode：0：WCDMA模式；1：GSM模式。
 输出参数  : 无。
 返 回 值  : 0:  操作成功；
             -1：操作失败。
*****************************************************************************/
extern int BSP_GUSYS_BBPAutoAdjust(unsigned char ucAdjustMode);
#define DRV_BBP_AUTO_ADJUST(ucAdjustMode)    BSP_GUSYS_BBPAutoAdjust(ucAdjustMode)

/*****************************************************************************
 函 数 名  : BSP_GUSYS_DspPllEnable
 功能描述  : 打开DSP PLL
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
extern void BSP_GUSYS_DspPllEnable(void);
#define DRV_DSP_PLL_ENABLE()    BSP_GUSYS_DspPllEnable()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_DspPllDisable
 功能描述  : 关闭DSP PLL
 输入参数  : 无。
 输出参数  : 无。
 返 回 值  : 无。
*****************************************************************************/
extern void BSP_GUSYS_DspPllDisable(void);
#define DRV_DSP_PLL_DISABLE()    BSP_GUSYS_DspPllDisable()

/*****************************************************************************
 函 数 名  : BSP_GUSYS_ModeSwitchs
 功能描述  : 本接口实现WCDMA/GSM系统模式切换。
 输入参数  : uiSysMode：0：切换到WCDMA模式；1：切换到GSM模式。
 输出参数  : 无。
 返 回 值  : 0:  操作成功；
             -1：操作失败。
*****************************************************************************/
extern int BSP_GUSYS_ModeSwitch(unsigned int uiSysMode);
#define DRV_SYSMODE_SWITCH(uiSysMode)    BSP_GUSYS_ModeSwitch(uiSysMode)



#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of drv_sysctrl.h */

