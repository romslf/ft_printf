/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 15:55:34 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 13:02:46 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_str(va_list list)
{
	char *str = va_arg(list, char *);
	ft_putstr(str);
}

void ft_print_char(va_list list)
{
	char c = va_arg(list, int);
	ft_putchar(c);
}

void ft_print_nb(va_list list)
{
	int num = va_arg(list, int);
	ft_putnbr(num);
}

void ft_print_unsigned(va_list list)
{
	int num = va_arg(list, unsigned);
	ft_putnbr(num);
}

void ft_printf_hex(va_list list)
{
	int num = va_arg(list, int);
	ft_putnbr_base(num, "0123456789abcdef");
}

void ft_printf_hexa(va_list list)
{
	int num = va_arg(list, int);
	ft_putnbr_base(num, "0123456789ABCDEF");
}

void ft_print_address(va_list list)
{
	long add = (long)va_arg(list, char **);
	ft_putnbr_base_pref(add, "0123456789abcdef");
}

int findIndex(char *flags, char element)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == element)
			return (i);
		i++;
	}
	printf("%c\n", flags[i]);
	printf("%c\n", element);
	return (-1);
}

int ft_printf(const char *str, ...)
{
	void (*functions[8])(va_list) = {ft_print_str, ft_print_char, ft_print_nb, ft_print_nb, ft_printf_hex, ft_printf_hexa, ft_print_address, ft_print_unsigned};
	char flags[9] = {'s', 'c', 'd', 'i', 'x', 'X', 'p', 'u', 0};
	va_list list;
	int tmp;
	int i;

	tmp = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (i != 0 && str[i - 1] == '%')
		{
			tmp = findIndex(flags, str[i]);
			if (tmp != -1)
				(*functions[tmp])(list);
		}
		else if (str[i] != '%')
			ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void header(void)
{
	printf("\033[1;36m");
	printf("-------------------------------------------\n");
	printf("  _____  _____  _____ _   _ _______ ______\n");
	printf(" |  __ \\|  __ \\|_   _| \\ | |__   __|  ____|\n | |__) | |__) | | | |  \\| |  | |  | |__   \n |  ___/|  _  /  | | | . ` |  | |  |  __|  \n | |    | | \\ \\ _| |_| |\\  |  | |  | |     \n |_|    |_|  \\_\\_____|_| \\_|  |_|  |_|     \n");
	printf("\033[1;33m");
	printf("				By rolaforg\n");
	printf("\033[1;36m");
	printf("-------------------------------------------\n");
	printf("\033[0m");
	printf("\n");
}

void test(int one, int two)
{
	int size = 0;
	char *sep = "-----------------------------------------------------------";
	if (one == two)
	{
		size = ft_strlen(sep) - one - two - 2;
		while (size--)
			printf(" ");
		printf("\033[0;32m");
		printf("OK\n");
	}
	else
	{
		size = ft_strlen(sep) - one - one - 4;
		while (size--)
			printf(" ");
		printf("\033[0;31m");
		printf("FAIL\n");
	}
	printf("\033[0m");
	printf("%s\n", sep);
}

int main(void)
{
	header();
	char *str = "test";
	char **ptr = &str;
	unsigned int one = 42;
	unsigned int two = 1337;
	test(printf("'%d'", 4), ft_printf("'%d'", 4));
	test(printf("'%d'", 42), ft_printf("'%d'", 42));
	test(printf("'%d'", 420), ft_printf("'%d'", 420));
	test(printf("'%i'", 4), ft_printf("'%i'", 4));
	test(printf("'%i'", 42), ft_printf("'%i'", 42));
	test(printf("'%i'", 420), ft_printf("'%i'", 420));
	test(printf("'%c'", '!'), ft_printf("'%c'", '!'));
	test(printf("'%c, %c'", '!', '?'), ft_printf("'%c, %c'", '!', '?'));
	test(printf("'%s'", "I"), ft_printf("'%s'", "I"));
	test(printf("'%s'", "Im"), ft_printf("'%s'", "Im"));
	test(printf("I"), ft_printf("I"));
	test(printf("'Im a str'"), ft_printf("'Im a str'"));
	test(printf("'%x'", 4), ft_printf("'%x'", 4));
	test(printf("'%x'", 42), ft_printf("'%x'", 42));
	test(printf("'%x'", 420), ft_printf("'%x'", 420));
	test(printf("'%X'", 4), ft_printf("'%X'", 4));
	test(printf("'%X'", 42), ft_printf("'%X'", 42));
	test(printf("'%X'", 420), ft_printf("'%X'", 420));
	test(printf("'%p'", ptr), ft_printf("'%p'", ptr));
	test(printf("'%u'", one), ft_printf("'%u'", one));
	test(printf("'%u'", two), ft_printf("'%u'", two));
	return (0);
}