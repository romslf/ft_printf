/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:58:46 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/10 15:06:49 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_print_address(va_list list, t_buff *buffer)
{
	unsigned long long int add;
	char	*str;
	int		len;

	add = (unsigned long long int)va_arg(list, char **);
	str = ft_ulltoa_base(add, "0123456789abcdef");
	len = ft_strlen(str) + 2;
	if (buffer->preci)
	{
		buffer->zero = 1;
		ft_putstr("0x");
		handle_spaces(len - 2, buffer, 0, 0);
	}	
	else if (buffer->zero || buffer->left) {
		ft_putstr("0x");
		handle_spaces(len, buffer, 0, 0);
	}
	else if (!buffer->zero && !buffer->left) {
		handle_spaces(len, buffer, 0, 0);
		ft_putstr("0x");
	}
	// if (add)		
	buffer->size += ft_putstr(str) + 2;
	// else
	// 	buffer->size += 2;
	handle_spaces(len, buffer, 1, 0);
}
