/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:56:38 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/17 16:20:50 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_hex(va_list list, t_buff *buffer)
{
	int num;
	int len;

	num = va_arg(list, int);
	len = ft_ullintlen(num, "0123456789abcdef");
	if (!num && buffer->preci && !buffer->precision && !buffer->spaces)
		return ;
	else if (!num && buffer->preci && !buffer->precision && buffer->spaces)
	{
		handle_spaces_preci(0, buffer, buffer->left, 0);
	}
	else
	{
		handle_spaces_preci(len, buffer, 0, 0);
		ft_putnbr_base(num, "0123456789abcdef", buffer);
		handle_spaces_preci(len, buffer, 1, 0);
	}
}
