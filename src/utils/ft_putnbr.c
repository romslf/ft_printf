/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 17:32:18 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:32:18 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"


void ft_putnbr(long long n, t_buff *buffer)
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