/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:25:05 by jdias-mo          #+#    #+#             */
/*   Updated: 2021/12/09 12:25:07 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_var
{
	int		cardinal;
	int		space;
	int		plus;
	int		zero;
	int		minus;
	int		width;
	int		precision;
	int		p_value;
	int		left;
	int		right;
	int		z_value;
	int		neg;
	int		len;
	va_list	arg;
}				t_var;

int		ft_printf(const char *format, ...);
void	ft_printf_c(t_var *var);
void	ft_printf_s(t_var *var);
void	ft_printf_p(t_var *var);
void	ft_printf_di(t_var *var);
void	ft_printf_ux(char c, int base, t_var *var);
void	ft_putchar(char c);
int		ft_nlen(int n, int base);
int		ft_unlen(unsigned long long n, int base);
void	ft_putnbr(int n, t_var *var);
void	ft_putnbr_base(unsigned long long n, int base, char *radix);

size_t	ft_strlen(const char *s);
void	ft_initialize(t_var *var);
int		ft_check_placeholder(char c, char *ph);
int		ft_getnbr(char *str);
char	*ft_flags(char *str, t_var *var);
void	ft_print_di_aux(t_var *var, int f_len, int f_len2, int n);
void	ft_print_ux_aux(t_var *var, int f_len, char c, unsigned int n);
char	*ft_flags_aux(t_var *var, char *str);

#endif
