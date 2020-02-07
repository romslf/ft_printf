/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_unsigned.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 13:55:47 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 13:55:55 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../ft_printf.h"

void ft_print_unsigned(va_list list)
{
	int num = va_arg(list, unsigned);
	ft_putnbr(num);
}
