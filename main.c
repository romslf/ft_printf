/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 15:55:34 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 17:11:58 by rolaforg    ###    #+. /#+    ###.fr     */
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

int		ft_verif_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[i] != base[j] && base[j])
			j++;
		if (base[i] == base[j])
			return (0);
		else if (!(base[i] >= '!' && base[i] <= '~') ||
				(base[i] == '+' || base[i] == '-'))
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(long nb, char *base)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	if (ft_verif_base(base))
	{
		while (base[size])
			size++;
		if (nb < 0)
		{
			ft_putchar('-');
			ft_putnbr_base(nb * -1, base);
		}
		else if (nb < size)
			ft_putchar(base[nb]);
		else
		{
			ft_putnbr_base(nb / size, base);
			ft_putnbr_base(nb % size, base);
		}
	}
}
/////////////////////////////
/////////////////////////////
/////////////////////////////

void	ft_print_str(va_list list)
{
	char *str = va_arg(list, char *);
	ft_putstr(str);
}

void	ft_print_char(va_list list)
{
	char c = va_arg(list, int);
	ft_putchar(c);
}

void	ft_print_nb(va_list list)
{
	int num = va_arg(list, int);
	ft_putnbr(num);
}

void	ft_printf_hex(va_list list)
{
	int	num = va_arg(list, int);
	ft_putnbr_base(num, "0123456789abcdef");
}

void	ft_printf_hexa(va_list list)
{
	int	num = va_arg(list, int);
	ft_putnbr_base(num, "0123456789ABCDEF");
}

void	ft_print_address(va_list list)
{
	char **str = va_arg(list, char **);
	ft_putstr(&str);
}

int		findIndex(char *flags, char element)
{
	int	i;

	i = 0;
	while (flags[i])
	{
		if(flags[i] == element)
			return (i);
		i++;
	}
	printf("%c\n", flags[i]);
	printf("%c\n", element);
	return (-1);
}

int		ft_printf(const char *str, ...)
{
	void	(*functions[7]) (va_list) = {ft_print_str, ft_print_char, ft_print_nb, ft_print_nb, ft_printf_hex, ft_printf_hexa, ft_print_address};
	char	flags[8] = {'s', 'c', 'd', 'i', 'x', 'X', 'p', 0};
	va_list	list;
	int		tmp;
	int		i;
	int		x = 0;

	tmp = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (i != 0 && str[i - 1] == '%')
		{
			tmp = findIndex(flags, str[i]);
			if (tmp != -1)
				(*functions[tmp]) (list);
			x++;
		} else if (str[i] != '%')
			ft_putchar(str[i]);
		i++;
	}
	return (i - x);
}

void	test(int one, int two)
{
	if (one == two)
		printf(" ✅\n");
	else
	{
		printf("\n");
		//printf("Expected: %d, got: %d\n", one, two);
	}
	printf("------------------------------\n");
}

int		main(void)
{
	char *str = "test";
	char **ptr = &str;

	test(printf("'%d'", 4), ft_printf("'%d'", 4));
	test(printf("'%d'", 42), ft_printf("'%d'", 42));
	test(printf("'%d'", 420), ft_printf("'%d'", 420));
	test(printf("'%i'", 4), ft_printf("'%i'", 4));
	test(printf("'%i'", 42), ft_printf("'%i'", 42));
	test(printf("'%i'", 420), ft_printf("'%i'", 420));
	test(printf("'%c'", '!'), ft_printf("'%c'", '!'));
	test(printf("'%c, %c'", '!', '?'), ft_printf("'%c, %c'", '!', '?'));
	test(printf("'%s'", "I"),	ft_printf("'%s'", "I"));
	test(printf("'%s'", "Im"),	ft_printf("'%s'", "Im"));
	test(printf("I"), ft_printf("I"));
	test(printf("'Im a str'"), ft_printf("'Im a str'"));
	test(printf("'%x'", 4),	ft_printf("'%x'", 4));
	test(printf("'%x'", 42),	ft_printf("'%x'", 42));
	test(printf("'%x'", 420),	ft_printf("'%x'", 420));
	test(printf("'%X'", 4), ft_printf("'%X'", 4));
	test(printf("'%X'", 42), ft_printf("'%X'", 42));
	test(printf("'%X'", 420), ft_printf("'%X'", 420));
	test(printf("'%p'", ptr), ft_printf("'%p'", ptr));
	return (0);
}