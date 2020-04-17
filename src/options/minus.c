/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 19:26:26 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/17 16:33:45 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	handle_minus(va_list list, const char *str, t_buff *buffer)
{
	int	i;

	i = 1;
	buffer->left = 1;
	if (str[i] == '*')
	{
		buffer->spaces = va_arg(list, int);
		if (buffer->spaces < 0)
			buffer->spaces *= -1;
		i++;
		return (i);
	}
	while (str[i] >= '0' && str[i] <= '9')
		buffer->spaces = (buffer->spaces * 10) + (str[i++] - '0');
	return (i);
}
