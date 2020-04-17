/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 16:44:15 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/17 19:15:51 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	handle_wild(va_list list, t_buff *buffer)
{
	buffer->spaces = va_arg(list, int);
	if (buffer->spaces < 0)
	{
		buffer->spaces *= -1;
		buffer->left = 1;
	}
}
