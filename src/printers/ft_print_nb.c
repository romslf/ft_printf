/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_nb.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 13:55:02 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 15:23:58 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_print_nb(va_list list, t_buff *buffer)
{
	int num = va_arg(list, int);
	ft_putnbr(num, buffer);
}
