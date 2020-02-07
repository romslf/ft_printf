#ifndef FT_PRINTF_H
#define FT_PRINTF_H

// printf
#include <stdio.h>
// to remove

#include <stdarg.h>
// @ts-ignore
#include <unistd.h>

// typedef struct buff
// {
//  	long size = 0;
// } buff;

int	ft_printf(const char *, ...);
int ft_strlen(char *str);
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(int n);
void ft_putnbr_base(long nb, char *base);
void ft_putnbr_base_pref(long nb, char *base);
void ft_print_str(va_list list);
void ft_print_char(va_list list);
void ft_print_nb(va_list list);
void ft_print_unsigned(va_list list);
void ft_print_hex(va_list list);
void ft_print_hexa(va_list list);
void ft_print_address(va_list list);

#endif