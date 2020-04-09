/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 13:20:21 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/07 19:47:34 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	reset_buffer(t_buff *buffer)
{
	buffer->spaces = 0;
	buffer->left = 0;
	buffer->preci = 0;
	buffer->precision = 0;
	buffer->zero = 0;
}

void	handle_spaces(int len, t_buff *buffer, int left)
{
	if (buffer->spaces && (buffer->spaces > len) && buffer->left == left)
	{
		buffer->spaces -= len;
		while (buffer->spaces > 0)
		{
			if (buffer->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			buffer->spaces -= 1;
			buffer->size += 1;
		}
		reset_buffer(buffer);
	}
	if (buffer->preci && (buffer->precision > len))
	{
		buffer->precision -= len;
		while (buffer->precision > 0)
		{
			ft_putchar('0');
			buffer->precision -= 1;
			buffer->size += 1;
		}
		reset_buffer(buffer);
	}
	if (!buffer->left)
		reset_buffer(buffer);
}