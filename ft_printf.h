#ifndef FT_PRINTF_H
#define FT_PRINTF_H

// printf
#include <stdio.h>
// to remove

#include <stdarg.h>
// @ts-ignore
#include <unistd.h>

typedef struct s_buff
{
 	int size;
} t_buff;

int	ft_printf(const char *, ...);
int ft_strlen(char *str);
void ft_putchar(char c);
long ft_putstr(char *s);
void ft_putnbr(int n, t_buff *buffer);
void ft_putnbr_base(unsigned int nb, char *base, t_buff *buffer);
void ft_putnbr_base_pref(long nb, char *base, t_buff *buffer);
void ft_print_str(va_list list, t_buff *buffer);
void ft_print_char(va_list list, t_buff *buffer);
void ft_print_nb(va_list list, t_buff *buffer);
void ft_print_unsigned(va_list list, t_buff *buffer);
void ft_print_hex(va_list list, t_buff *buffer);
void ft_print_hexa(va_list list, t_buff *buffer);
void ft_print_address(va_list list, t_buff *buffer);

#endif