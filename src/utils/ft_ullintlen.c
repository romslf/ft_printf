/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 17:08:40 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/05 18:02:48 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_strrev(char *str)
{
	char	temp;
	int		x;
	int		y;

	y = ft_strlen(str) - 1;
	x = 0;
	while (x < ft_strlen(str) / 2)
	{
		temp = str[y];
		str[y] = str[x];
		str[x] = temp;
		y--;
		x++;
	}
	return (str);
}

int	ft_ullintlen(unsigned long long nbr, char *base)
{
	int lenbase;
	int x;

	x = 0;
	if (nbr == 0)
		return (1);

	lenbase = ft_strlen(base);
	while (nbr > 0)
	{
		nbr = nbr / lenbase;
		x++;
	}
	return (x);
}

char		*ft_ulltoa_base(unsigned long long int nbr, char *base)
{
	int		x;
	int		m;
	char	*str;
	int		lenbase;

	x = 0;
	if (nbr == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	lenbase = ft_strlen(base);
	m = ft_ullintlen(nbr, base);
	str = malloc((m + 1) * sizeof(char));
	while (nbr > 0)
	{
		str[x] = base[nbr % lenbase];
		nbr = nbr / lenbase;
		x++;
	}
	str[x] = '\0';
	ft_strrev(str);
	return (str);
}