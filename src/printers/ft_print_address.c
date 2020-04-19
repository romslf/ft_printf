/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:58:46 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 13:53:06 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_address(va_list list, t_buff *buffer)
{
	unsigned long long int	add;
	char					*str;
	int						len;

	add = (unsigned long long int)va_arg(list, char **);
	str = ft_ulltoa_base(add, "0123456789abcdef");
	if (add)
		len = ft_strlen(str) + 2;
	else if (!add && !buffer->preci)
		len = 3;
	else
		len = 2;
	if ((buffer->spaces > len) && !buffer->left)
		handle_s_and_p(len, buffer, 0, 0);
	buffer->size += ft_putstr("0x");
	if (buffer->precision)
		handle_s_and_p(len - 2, buffer, 0, 0);
	if (add || (!add && !buffer->preci))
		buffer->size += ft_putstr(str);
	handle_s_and_p(len, buffer, 1, 0);
}
