/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 19:37:43 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/14 17:54:23 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		handle_point(va_list list, const char *str, t_buff *buffer)
{
        int i;

        i = 1;
		buffer->preci = 1;
		if (str[i] == '*')
		{
			buffer->precision = va_arg(list, int);
			if (buffer->precision < 0)
				buffer->preci = 0;
			i++;
			return (i);
		}
		while (str[i] >= '0' && str[i] <= '9')
			buffer->precision = (buffer->precision * 10) + (str[i++] - '0');
        return (i);
}
