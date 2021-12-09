/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:41:35 by jdias-mo          #+#    #+#             */
/*   Updated: 2021/11/25 16:46:03 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_var
{
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
void	ft_putnbr(int n);
void	ft_putnbr_base(unsigned long long n, int base, char *radix);

#endif
