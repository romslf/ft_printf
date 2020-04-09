/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:56:38 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/09 17:30:35 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_print_hex(va_list list, t_buff *buffer)
{
	int num = va_arg(list, int);
	int len = ft_ullintlen(num, "0123456789abcdef");
	int spaces = 0;
	if (buffer->preci && buffer->precision < buffer->spaces)
	{
		buffer->zero = 1;
		spaces = buffer->spaces - buffer->precision;
		buffer->spaces = buffer->precision;
		if (!buffer->left)
		{
			while (spaces-- > 0)
				buffer->size += ft_putstr(" ");
		}
	}
	handle_spaces(len, buffer, 0);
	ft_putnbr_base(num, "0123456789abcdef", buffer);
	handle_spaces(len, buffer, 1);
}
