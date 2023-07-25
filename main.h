#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
/**
 * struct formats - structure to handle different formats
 * @f: the format to prints
 * @func: the function pointer
 */
typedef struct formats
{
	char *f;
	int (*func)(va_list);
} formats_t;

int _putchar(char c);
int _printf(const char *format, ...);
int op_c(va_list c);
int op_s(va_list s);
int op_i(va_list i);
int op_d(va_list d);
int op_u(va_list u);
int op_b(va_list b);
int op_o(va_list o);
int op_x(va_list x);
int op_X(va_list X);
int op_p(va_list p);
int op_S(va_list S);
int op_r(va_list r);
int op_R(va_list R);

#endif  /* _MAIN_H */
