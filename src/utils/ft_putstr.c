/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 12:03:18 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 12:03:20 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

long	ft_putstr(char *s)
{
	long	size;

	size = ft_strlen(s);
	write(1, s, size);
	return (size);
}
