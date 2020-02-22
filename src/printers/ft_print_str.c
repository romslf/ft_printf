/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_str.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 13:51:57 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 15:23:58 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void ft_print_str(va_list list, t_buff *buffer)
{
	char *str = va_arg(list, char *);
	buffer->size = buffer->size + ft_putstr(str);
}
