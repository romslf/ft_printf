/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:55:34 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/24 17:16:46 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		handle_wild(list, buffer);
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

void	apply_conversion(int index, va_list list, t_buff *buffer)
{
	void	(*ptr_function[8]) (va_list, t_buff *);

	ptr_function[0] = &ft_print_str;
	ptr_function[1] = &ft_print_char;
	ptr_function[2] = &ft_print_nb;
	ptr_function[3] = &ft_print_nb;
	ptr_function[4] = &ft_print_hex;
	ptr_function[5] = &ft_print_hexa;
	ptr_function[6] = &ft_print_address;
	ptr_function[7] = &ft_print_unsigned;
	(ptr_function[index])(list, buffer);
}

int		ft_print(va_list list, const char *str, t_buff *buffer)
{
	int		tmp;
	int		i;

	tmp = -1;
	i = 0;
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
		apply_conversion(tmp, list, buffer);
	else if (str[i + 1] != '\0')
	{
		ft_putchar(str[++i]);
		buffer->size += 1;
	}
	reset_buffer(buffer);
	return (i);
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
				ft_putchar(str[i]);
				buffer.size += 1;
			}
			i++;
		}
		va_end(list);
	}
	return (buffer.size);
}
