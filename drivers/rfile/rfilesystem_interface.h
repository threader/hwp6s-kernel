

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/

#ifndef __RFILESYSTEM_INTERFACE__
#define __RFILESYSTEM_INTERFACE__

#include "rfilesystem_process.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif



/*****************************************************************************
  2 宏定义
*****************************************************************************/

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
FILE *BSP_fopen(const char *path, const char *mode);
int BSP_fseek(FILE *stream, long offset, int whence);
long BSP_ftell(FILE *stream);
int BSP_fread(void*buf,unsigned int size,unsigned int count, FILE *stream);
int BSP_fwrite(const void* buf,unsigned int size,unsigned int count,FILE *stream);
int BSP_fclose(FILE *fp);


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of __RFILESYSTEM_INTERFACE__ */

