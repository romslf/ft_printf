/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:02 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/10 15:08:07 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_nb(va_list list, t_buff *buffer)
{
	int	num = 0;
	int	len = 0;

	num = va_arg(list, int);
	len = num_len(num);
	handle_spaces(len, buffer, 0, 0);
	ft_putnbr(num, buffer);
	handle_spaces(len, buffer, 1, 0);
}
