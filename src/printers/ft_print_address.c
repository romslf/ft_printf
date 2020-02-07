/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_address.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 13:58:46 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 14:00:09 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../ft_printf.h"

void ft_print_address(va_list list)
{
	long add = (long)va_arg(list, char **);
	ft_putnbr_base_pref(add, "0123456789abcdef");
}
