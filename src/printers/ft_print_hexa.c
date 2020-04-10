/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:58:10 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/10 20:18:15 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_print_hexa(va_list list, t_buff *buffer)
{
	int num = va_arg(list, int);
	int len = ft_ullintlen(num, "0123456789ABCDEF");
	handle_spaces_preci(len, buffer, 0, 0);
	ft_putnbr_base(num, "0123456789ABCDEF", buffer);
	handle_spaces_preci(len, buffer, 1, 0);
}
