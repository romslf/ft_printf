/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 12:01:54 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 12:02:06 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putnbr(long long n, t_buff *buffer)
{
	if (n < 0)
	{
		ft_putchar('-');
		buffer->size = buffer->size + 1;
		ft_putnbr(n * -1, buffer);
	}
	else if (n < 10)
	{
		buffer->size = buffer->size + 1;
		ft_putchar(n + 48);
	}
	else
	{
		ft_putnbr(n / 10, buffer);
		ft_putnbr(n % 10, buffer);
	}
}
