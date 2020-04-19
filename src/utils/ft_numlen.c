/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 13:43:33 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/19 22:28:13 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	num_len(long num)
{
	unsigned int	res;

	res = 0;
	while (num > 0)
	{
		res += 1;
		num = num / 10;
	}
	if (res)
		return (res);
	return (1);
}
