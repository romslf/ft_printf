/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:51:57 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/10 20:18:15 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	handle_case(char *str, t_buff *buffer)
{
	int	len;

	if (buffer->preci && buffer->precision < ft_strlen(str))
		len = buffer->precision;
	else
		len = ft_strlen(str);
	
	if (buffer->spaces > len)
		handle_spaces_preci(len, buffer, 0, 1);
	write(1, str, len);
	buffer->size += len;
	if (buffer->spaces > len)
		handle_spaces_preci(len, buffer, 1, 1);
}

void	ft_print_str(va_list list, t_buff *buffer)
{
	char	*str;
	int		len;

	str = va_arg(list, char *);
	len = ft_strlen(str);
	
	if (!str)
		handle_case("(null)", buffer);
	else 
		handle_case(str, buffer);
	reset_buffer(buffer);
}