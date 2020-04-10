/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:47 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/10 20:04:40 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_print_unsigned(va_list list, t_buff *buffer)
{
	unsigned long num = va_arg(list, unsigned);
	handle_spaces(num_len(num), buffer, 0, 0);
	ft_putnbr(num, buffer);
	handle_spaces(num_len(num), buffer, 1, 0);
}
