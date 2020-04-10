/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spaces_preci.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 13:20:21 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/10 20:23:14 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

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
	int lenght;

	lenght = len;
	if (buffer->precision)
		buffer->zero = 0;
	if (buffer->precision > len && buffer->spaces)
	{
		lenght = buffer->precision;
	}
	if (buffer->spaces > lenght && buffer->left == left)
	{
		buffer->spaces -= lenght;
		while (buffer->spaces > 0)
		{
			if (buffer->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			buffer->spaces -= 1;
			buffer->size += 1;
		}
	}
}

void	handle_preci(int len, t_buff *buffer, int preci_mode)
{
	if (buffer->preci && buffer->precision > len)
	{
		buffer->precision -= len;
		while (buffer->precision > 0)
		{
			if (preci_mode == 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
			buffer->precision -= 1;
			buffer->size += 1;
		}
	}
}

void	handle_spaces_preci(int len, t_buff *buffer, int left, int preci_mode)
{
	handle_spaces(len, buffer, left);
	handle_preci(len, buffer, preci_mode);
}
