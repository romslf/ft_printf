/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:55:34 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/17 15:36:15 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init(t_buff *buffer)
{
	buffer->size = 0;
	buffer->spaces = 0;
	buffer->zero = 0;
	buffer->left = 0;
	buffer->preci = 0;
	buffer->precision = 0;
	buffer->tmp = 0;
}

int		find_index(char element)
{
	char	flags[9];
	int		i;

	flags[0] = 's';
	flags[1] = 'c';
	flags[2] = 'd';
	flags[3] = 'i';
	flags[4] = 'x';
	flags[5] = 'X';
	flags[6] = 'p';
	flags[7] = 'u';
	flags[8] = '0';
	i = 0;
	while (flags[i])
	{
		if (flags[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

int		handle_options(va_list list, const char *str, t_buff *buffer)
{
	unsigned int i;

	i = 0;
	if (str[i] == '-')
		i += handle_minus(list, str, buffer);
	else if (str[i] == '.')
		i += handle_point(list, str, buffer);
	else if (str[i] == '*')
	{
		buffer->spaces = va_arg(list, int);
		if (buffer->spaces < 0)
		{
			buffer->spaces *= -1;
			buffer->left = 1;
		}
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
	return (i);
}

int		ft_print(va_list list, const char *str, t_buff *buffer)
{
	void	(*functions[8])(va_list, t_buff *);
	int		tmp;
	int		i;

	tmp = -1;
	i = 0;
	functions[0] = ft_print_str;
	functions[1] = ft_print_char;
	functions[2] = ft_print_nb;
	functions[3] = ft_print_nb;
	functions[4] = ft_print_hex;
	functions[5] = ft_print_hexa;
	functions[6] = ft_print_address;
	functions[7] = ft_print_unsigned;
	while (str[i] && (tmp = handle_options(list, str + i, buffer)))
	{
		while (str[i] && tmp > 0)
		{
			i++;
			tmp--;
		}
	}
	if (str[i] == '%')
		ft_print_char_b(str[i], buffer);
	tmp = find_index(str[i]);
	if (tmp != -1)
		(*functions[tmp])(list, buffer);
	reset_buffer(buffer);
	return (i);
}

int		guard(const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((char *)str);
	if (str[i] == '%')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '-' || str[i] == '.' || str[i] == '*')
			i++;
		else
			break;
	}
	if (i == len)
		return (0);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	t_buff	buffer;
	va_list	list;
	int		i;

	i = 0;
	init(&buffer);
	if (!str)
		buffer.size += ft_putstr("(null)");
	else if (guard(str))
	{
		va_start(list, str);
		while (str[i])
		{
			if (i != 0 && str[i - 1] == '%' && str[i - 2] != '%')
				i += ft_print(list, str + i, &buffer);
			else if (str[i] != '%')
			{
				buffer.size += 1;
				ft_putchar(str[i]);
			}
			i++;
		}
		va_end(list);
	}
	return (buffer.size);
}
