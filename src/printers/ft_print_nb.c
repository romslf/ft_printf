/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:02 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/10 00:15:17 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_print_nb(va_list list, t_buff *buffer)
{
	int num = va_arg(list, int);
	int spaces = 0;
	int len = num_len(num);
	if (buffer->preci)
	{
		spaces = buffer->precision - len;
		if (!buffer->left)
		{
			while (spaces-- > 0)
				buffer->size += ft_putstr("0");
		}
	}
	else
		handle_spaces(len, buffer, 0);
	ft_putnbr(num, buffer);
	if (spaces)
	{
		while (spaces-- > 0)
			buffer->size += ft_putstr("0");
	}
	else
		handle_spaces(len, buffer, 1);
}
