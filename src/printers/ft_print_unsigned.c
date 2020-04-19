/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:47 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 13:53:06 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_unsigned(va_list list, t_buff *buffer)
{
	unsigned long num;

	num = va_arg(list, unsigned);
	if (!num && buffer->preci && !buffer->precision && !buffer->spaces)
		return ;
	else if (!num && buffer->preci && !buffer->precision && buffer->spaces)
	{
		handle_s_and_p(0, buffer, buffer->left, 0);
	}
	else
	{
		handle_s_and_p(num_len(num), buffer, 0, 0);
		ft_putnbr(num, buffer);
		handle_s_and_p(num_len(num), buffer, 1, 0);
	}
}
