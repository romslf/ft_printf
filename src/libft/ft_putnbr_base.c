/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 17:32:53 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:32:53 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../ft_printf.h"


int ft_verif_base(char *base)
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

void ft_putnbr_base(long nb, char *base)
{
	long size;

	size = 0;
	if (ft_verif_base(base))
	{
		while (base[size])
			size++;
		if (nb < 0)
		{
			ft_putchar('-');
			ft_putnbr_base(nb * -1, base);
		}
		else if (nb < size)
			ft_putchar(base[nb]);
		else
		{
			ft_putnbr_base(nb / size, base);
			ft_putnbr_base(nb % size, base);
		}
	}
}

void ft_putnbr_base_pref(long nb, char *base)
{
	long size;

	size = 0;
	if (ft_verif_base(base))
	{
		while (base[size])
			size++;
		if (nb < 0)
		{
			ft_putstr("-0x");
			ft_putnbr_base(nb * -1, base);
		}
		else if (nb < size)
		{
			ft_putstr("0x");
			ft_putchar(base[nb]);
		}
		else
		{
			ft_putstr("0x");
			ft_putnbr_base(nb / size, base);
			ft_putnbr_base(nb % size, base);
		}
	}
}
