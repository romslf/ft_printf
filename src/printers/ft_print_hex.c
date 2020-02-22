/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_hex.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 13:56:38 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 15:23:58 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_print_hex(va_list list, t_buff *buffer)
{
	int num = va_arg(list, int);
	ft_putnbr_base(num, "0123456789abcdef", buffer);
}
