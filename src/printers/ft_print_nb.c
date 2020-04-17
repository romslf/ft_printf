/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:02 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/17 16:27:28 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	handle_neg(long long num, t_buff *buffer)
{
	int	len;
	int	tmp;

	num *= -1;
	len = num_len(num);
	if (buffer->precision > len)
		tmp = buffer->precision;
	else
		tmp = len;
	if (buffer->zero)
	{
		ft_putchar('-');
		buffer->size += 1;
	}
	if (!buffer->left)
		handle_spaces(tmp + 1, buffer, 0);
	if (!buffer->zero)
	{
		ft_putchar('-');
		buffer->size += 1;
	}
	handle_preci(len, buffer, 0);
	ft_putnbr(num, buffer);
	if (buffer->left)
		handle_spaces(tmp + 1, buffer, 1);
}

void	ft_print_nb(va_list list, t_buff *buffer)
{
	long long	num;
	int			len;

	num = (long long)va_arg(list, int);
	if (!num && buffer->preci && !buffer->precision && !buffer->spaces)
		return ;
	if ((buffer->left && buffer->zero) || (buffer->zero && buffer->precision))
		buffer->zero = 0;
	if (num < 0)
	{
		handle_neg(num, buffer);
	}
	else if (!num && buffer->preci && !buffer->precision && buffer->spaces)
	{
		handle_spaces_preci(0, buffer, buffer->left, 0);
	}
	else
	{
		len = num_len(num);
		handle_spaces_preci(len, buffer, 0, 0);
		ft_putnbr(num, buffer);
		handle_spaces_preci(len, buffer, 1, 0);
	}
}
