/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_char.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 13:53:24 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 22:51:12 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../ft_printf.h"

void ft_print_char(va_list list, t_buff *buffer)
{
	char c = va_arg(list, int);
	buffer->size = buffer->size + 1;
	ft_putchar(c);
}
