#include<stdio.h>

#ifndef TSUsart_H_
#define TSUsart_H_
#ifdef __cplusplus
 extern "C" {
#endif
 /**
	 *
	 * @brief ��ʼ�����Թ��߳�ʼ��
	 *
	 */
extern void StandardDebugInit(void); 
	 
	 
extern int fputc(int ch, FILE *f);
	 
#ifdef __cplusplus
}
#endif
#endif
