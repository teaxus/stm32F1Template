#include<stdio.h>

#ifndef TSUsart_H_
#define TSUsart_H_
#ifdef __cplusplus
 extern "C" {
#endif
 /**
	 *
	 * @brief 初始化调试工具初始化
	 *
	 */
extern void StandardDebugInit(void); 
	 
	 
extern int fputc(int ch, FILE *f);
	 
#ifdef __cplusplus
}
#endif
#endif
