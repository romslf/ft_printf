/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 15:55:34 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 21:59:48 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
/////////////////////////////
/////////	LIBFT	/////////
/////////////////////////////

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
/////////////////////////////
/////////////////////////////
/////////////////////////////

void	ft_print_str(va_list *list)
{
	char *str = va_arg(*list, char *);
	ft_putstr(str);
}

void	ft_print_char(va_list *list)
{
	char c = va_arg(*list, int);
	ft_putchar(c);
}

void	ft_print_nb(va_list *list)
{
	int num = va_arg(*list, int);
	ft_putnbr(num);
}

int		findIndex(char *flags, char element)
{
	int	i;

	i = 0;
	while (flags[i++])
		if(flags[i] == element)
			return (i);
	return (-1);
}

int		ft_printf(const char *str, ...)
{
	void	(*functions[3]) (va_list *) = {ft_print_str, ft_print_char, ft_print_nb};
	char	flags[4] = {'s', 'c', 'd', 0};
	va_list	list;
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	va_start(list, str);
	while (str[i++])
	{
		if (i != 0 && str[i - 1] == '%')
		{
			tmp = findIndex(flags, str[i]);
			if (tmp != -1)
				(*functions[tmp]) (&list);
		} else if (str[i] != '%')
			ft_putchar(str[i]);
	}

	return (1);
}

int		main(int ac, char const **argv)
{
	ft_printf("%d\n", 42);
	ft_printf("%c\n", '!');
	ft_printf("%s\n", "Im a string !");
	return (0);
}