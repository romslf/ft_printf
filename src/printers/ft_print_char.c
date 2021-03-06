/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:53:24 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 13:53:06 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_char(va_list list, t_buff *buffer)
{
	char c;

	c = va_arg(list, int);
	if (!buffer->preci)
		handle_s_and_p(1, buffer, 0, 1);
	ft_putchar(c);
	buffer->size = buffer->size + 1;
	if (!buffer->preci)
		handle_s_and_p(1, buffer, 1, 1);
}

void	ft_print_char_b(char c, t_buff *buffer)
{
	if (!buffer->preci)
		handle_s_and_p(1, buffer, 0, 1);
	ft_putchar(c);
	buffer->size = buffer->size + 1;
	if (!buffer->preci)
		handle_s_and_p(1, buffer, 1, 1);
}
