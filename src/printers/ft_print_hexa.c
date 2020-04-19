/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:58:10 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 22:56:26 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_hexa(va_list list, t_buff *buffer)
{
	long long int	num;
	int				len;
	char			*str;

	num = (unsigned int)va_arg(list, int);
	str = ft_ulltoa_base(num, "0123456789ABCDEF");
	len = ft_strlen(str);
	if (!num && buffer->preci && !buffer->precision && !buffer->spaces)
		return ;
	else if (!num && buffer->preci && !buffer->precision && buffer->spaces)
	{
		handle_s_and_p(0, buffer, buffer->left, 0);
	}
	else
	{
		handle_s_and_p(len, buffer, 0, 0);
		buffer->size += ft_putstr(str);
		handle_s_and_p(len, buffer, 1, 0);
	}
}
