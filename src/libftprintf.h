#ifndef FT_LIBFTPRINTF_H
#define FT_LIBFTPRINTF_H

#include <stdarg.h>
// @ts-ignore
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_buff
{
 	int	size;
	int spaces;
	int zero;
	int left;
	int preci;
	int precision;
}				t_buff;

void	ft_print_char_b(char c, t_buff *buffer);
int		handle_minus(va_list list, const char *str, t_buff *buffer);
int		handle_point(va_list list, const char *str, t_buff *buffer);
void	reset_buffer(t_buff *buffer);
int		ft_printf(const char *, ...);
void	handle_spaces(int len, t_buff *buffer, int left, int preciMode);
int		ft_strlen(char *str);
int		num_len(int num);
char	*ft_strrev(char *str);
int		ft_ullintlen(unsigned long long nbr, char *base);
char	*ft_ulltoa_base(unsigned long long int nbr, char *base);
int		ft_verif_base(char *base);
int		ft_isdigit(char c);
void	ft_putchar(char c);
long	ft_putstr(char *s);
void	ft_putnbr(long long n, t_buff *buffer);
void	ft_putnbr_base(unsigned int nb, char *base, t_buff *buffer);
void	ft_putnbr_base_pref(long nb, char *base, t_buff *buffer);
void	ft_print_str(va_list list, t_buff *buffer);
void	ft_print_char(va_list list, t_buff *buffer);
void	ft_print_nb(va_list list, t_buff *buffer);
void	ft_print_unsigned(va_list list, t_buff *buffer);
void	ft_print_hex(va_list list, t_buff *buffer);
void	ft_print_hexa(va_list list, t_buff *buffer);
void	ft_print_address(va_list list, t_buff *buffer);

#endif
