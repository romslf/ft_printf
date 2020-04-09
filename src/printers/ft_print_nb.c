/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:02 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/09 17:24:15 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_print_nb(va_list list, t_buff *buffer)
{
	int num = va_arg(list, int);
	int spaces = 0;

	if (buffer->preci && buffer->precision < buffer->spaces)
	{
		spaces = buffer->spaces - buffer->precision;
		buffer->spaces -= buffer->precision;
		if (!buffer->left)
		{
			while (spaces-- > 0)
				buffer->size += ft_putstr(" ");
		}
	}
	handle_spaces(num_len(num), buffer, 0);
	ft_putnbr(num, buffer);
	if (spaces)
	{
		while (spaces-- > 0)
			buffer->size += ft_putstr(" ");
	}
	handle_spaces(num_len(num), buffer, 1);
}
