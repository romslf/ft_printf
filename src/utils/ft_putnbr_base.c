/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 12:00:15 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 12:01:06 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_verif_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[i] != base[j] && base[j])
			j++;
		if (base[i] == base[j])
			return (0);
		else if (!(base[i] >= '!' && base[i] <= '~') ||
			(base[i] == '+' || base[i] == '-'))
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(unsigned int nb, char *base, t_buff *buffer)
{
	long size;

	size = 0;
	if (ft_verif_base(base))
	{
		while (base[size])
			size++;
		if (nb < size)
		{
			buffer->size = buffer->size + 1;
			ft_putchar(base[nb]);
		}
		else
		{
			ft_putnbr_base(nb / size, base, buffer);
			ft_putnbr_base(nb % size, base, buffer);
		}
	}
}

void	ft_putnbr_base_pref(long nb, char *base, t_buff *buffer)
{
	long size;

	size = 0;
	if (ft_verif_base(base))
	{
		while (base[size])
			size++;
		if (nb < size)
		{
			buffer->size = buffer->size + 1;
			ft_putchar(base[nb]);
		}
		else
		{
			ft_putnbr_base_pref(nb / size, base, buffer);
			ft_putnbr_base_pref(nb % size, base, buffer);
		}
	}
}
