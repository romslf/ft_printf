/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:55:34 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/09 22:30:52 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

void	init_buff(t_buff *buffer)
{
	buffer->size = 0;
	buffer->spaces = 0;
	buffer->zero = 0;
	buffer->left = 0;
	buffer->preci = 0;
	buffer->precision = 0;
}

int		findIndex(char element)
{
	char flags[9] = {'s', 'c', 'd', 'i', 'x', 'X', 'p', 'u', 0};
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

int		get_spaces(const char *str, t_buff *buffer, unsigned int i, int mode)
{
	if (!i || i < 0)
		i = 0;
	if (str[i] >= '1' && str[i] <= '9')
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (mode == 0)
				buffer->spaces = buffer->spaces * 10 + (str[i++] - 48);
			else
				buffer->precision = buffer->precision * 10 + (str[i++] - 48);
		}
	return (i);
}

int		handle_options(va_list list, const char *str, t_buff *buffer)
{
	unsigned int i;

	i = 0;
	if (str[i] == '-')
	{
		buffer->left = 1;
		i++;
		if (str[i] == '*')
		{
			buffer->spaces = va_arg(list, int);
			i++;
			return (i);
		}
		while (str[i] >= '0' && str[i] <= '9')
			buffer->spaces = (buffer->spaces * 10) + (str[i++] - '0');
	}
	else if (str[i] == '.')
	{
		i++;
		buffer->preci = 1;
		if (str[i] == '*')
		{
			buffer->precision = va_arg(list, int);
			i++;
			return (i);
		}
		while (str[i] >= '0' && str[i] <= '9')
			buffer->precision = (buffer->precision * 10) + (str[i++] - '0');
	}
	else if (str[i] == '*')
	{
		buffer->spaces = va_arg(list, int);
		if (buffer->spaces < 0)
			buffer->spaces *= -1;
		i++;
	}
	else if (str[i] == '0')
	{
		buffer->zero = 1;
		i++;
	}
	else if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			buffer->spaces = (buffer->spaces * 10) + (str[i++] - '0');
	}
	return i;
}

// int		handle_options(va_list list, const char *str, t_buff *buffer)
// {
// 	unsigned int i;

// 	i = 0;
// 	while (str[i] >= '0' && str[i] <= '9')
// 		buffer->spaces = buffer->spaces * 10 + (str[i++] - 48);
	
// 	return i;
// }

int		ft_printf(const char *str, ...) // FIXME Norme (Lines nb)
{
	void (*functions[8])(va_list, t_buff *) = {ft_print_str, ft_print_char, ft_print_nb, ft_print_nb, ft_print_hex, ft_print_hexa, ft_print_address, ft_print_unsigned};
	t_buff buffer;
	va_list list;
	int tmp;
	int i;

	tmp = -1;
	i = 0;
	init_buff(&buffer);
	if (!str)
		buffer.size = buffer.size + ft_putstr("(null)");
	else {
		va_start(list, str);
		while (str[i])
		{
			if (i != 0 && str[i - 1] == '%' && str[i - 2] != '%')
			{	
				while (tmp != 0)
				{
					tmp = handle_options(list, str + i, &buffer);
					i += tmp;
				}
				tmp = -1;
				while (tmp != 0)
				{
					tmp = handle_options(list, str + i, &buffer);
					i += tmp;
				}
				if (str[i] == '%')
					ft_print_char_b(str[i], &buffer);
				tmp = findIndex(str[i]);
				if (tmp != -1)
					(*functions[tmp])(list, &buffer);
			}
			else if (str[i] != '%')
			{
				ft_putchar(str[i]);
				buffer.size += 1;
			}
			i++;
		}
		va_end(list);
	}
	return (buffer.size);
}
