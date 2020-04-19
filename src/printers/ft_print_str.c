/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:51:57 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 18:23:10 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	handle_case(char *str, t_buff *buffer)
{
	int	len;

	len = ft_strlen(str);
	if (buffer->preci && buffer->precision < len)
		len = buffer->precision;
	if (buffer->spaces > len)
		handle_s_and_p(len, buffer, 0, 1);
	write(1, str, len);
	buffer->size += len;
	if (buffer->spaces > len)
		handle_s_and_p(len, buffer, 1, 1);
}

void	ft_print_str(va_list list, t_buff *buffer)
{
	char	*str;
	int		len;

	str = va_arg(list, char *);
	len = ft_strlen(str);
	if (!str && buffer->precision > 6)
	{
		buffer->precision = 0;
		buffer->preci = 0;
		buffer->tmp = 0;
	}
	else if (str && buffer->precision > len)
	{
		buffer->precision = 0;
		buffer->preci = 0;
		buffer->tmp = 0;
	}
	if (!str)
		handle_case("(null)", buffer);
	else
		handle_case(str, buffer);
}
