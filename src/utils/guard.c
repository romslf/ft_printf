/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guard.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 16:54:33 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/17 16:54:50 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		guard(const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((char *)str);
	if (str[i] == '%')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '-' || str[i] == '.' || str[i] == '*')
			i++;
		else
			break ;
	}
	if (i == len)
		return (0);
	return (1);
}