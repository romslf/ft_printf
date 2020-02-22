/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 15:55:34 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 15:37:58 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_buff(t_buff *buffer)
{
	buffer->size = 0;
}

int		findIndex(char *flags, char element)
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

int		ft_printf(const char *str, ...)
{
	void (*functions[8])(va_list, t_buff *) = {ft_print_str, ft_print_char, ft_print_nb, ft_print_nb, ft_print_hex, ft_print_hexa, ft_print_address, ft_print_unsigned};
	char flags[9] = {'s', 'c', 'd', 'i', 'x', 'X', 'p', 'u', 0};
	t_buff buffer;
	va_list list;
	int tmp;
	int i;
	int x;


	tmp = 0;
	i = 0;
	x= 0;
	init_buff(&buffer);
	va_start(list, str);
	while (str[i])
	{
		if (i != 0 && str[i - 1] == '%')
		{
			tmp = findIndex(flags, str[i]);
			if (tmp != -1)
				(*functions[tmp])(list, &buffer);
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i]);
			x++;
		}
		i++;
	}
	buffer.size = buffer.size + x;
	return (buffer.size);
}
