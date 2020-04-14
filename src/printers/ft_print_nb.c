/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:02 by rolaforg          #+#    #+#             */
/*   Updated: 2020/04/14 11:15:57 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_nb(va_list list, t_buff *buffer)
{
	long long	num = 0;
	int	len = 0;

	num = (long long)va_arg(list, int);
	if (buffer->left && buffer->zero)
		buffer->zero = 0;
	if (num < 0 && buffer->spaces && buffer->precision)
	{
		num *= -1;
		len = num_len(num);
		if (buffer->precision > len)
		{
			handle_spaces(buffer->precision + 1, buffer, buffer->left);
		}
		else
			handle_spaces(len + 1, buffer, buffer->left);

		
		ft_putchar('-');
		buffer->size += 1;
		handle_preci(len, buffer, 0);
		ft_putnbr(num, buffer);
		handle_spaces_preci(len, buffer, 1, 0);
	}
	else if ((num < 0 && buffer->precision > len))
	{
		num *= -1;
		len = num_len(num);
		ft_putchar('-');
		buffer->size += 1;
		handle_spaces_preci(len, buffer, 0, 0);
		ft_putnbr(num, buffer);
		handle_spaces_preci(len, buffer, 1, 0);
	}
	else if (num < 0 && buffer->spaces > len && buffer->zero)
	{
		num *= -1;
		len = num_len(num) + 1;
		ft_putchar('-');
		buffer->size += 1;
		handle_spaces_preci(len, buffer, 0, 0);
		ft_putnbr(num, buffer);
		handle_spaces_preci(len, buffer, 1, 0);
	}
	else if (num < 0)
	{
		num *= -1;
		len = num_len(num) + 1;
		handle_spaces_preci(len, buffer, 0, 0);
		ft_putchar('-');
		buffer->size += 1;
		ft_putnbr(num, buffer);
		handle_spaces_preci(len, buffer, 1, 0);
	}
	else
	{
		len = num_len(num);
		handle_spaces_preci(len, buffer, 0, 0);
		ft_putnbr(num, buffer);
		handle_spaces_preci(len, buffer, 1, 0);
	}
}
