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

#include "../libftprintf.h"

int len_nbr_base(unsigned int nb, char *base)
{
	long size;
	int	 len;

	size = 0;
	len = 0;
	if (ft_verif_base(base))
	{
		while (base[size])
			size++;
		if (nb < size)
			return (1);
		else
		{
			while (nb % size)
			{
				len += 1;
				nb /= size;
			}
		}
	}
	return (len + 2);
}

int len_nbr_base_pref(unsigned int nb, char *base)
{
	return (len_nbr_base(nb, base) + 2);
}
