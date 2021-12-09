/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:27:01 by jdias-mo          #+#    #+#             */
/*   Updated: 2021/12/09 12:27:03 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_printf_c(t_var *var)
{
	char	c;

	c = va_arg(var->arg, int);
	if (var->width && !var->minus)
		var->left = var->width - 1;
	else if (var->width && var->minus)
		var->right = var->width - 1;
	while (var->left--)
		ft_putchar(' ');
	write(1, &c, 1);
	var->len++;
	while (var->right--)
		ft_putchar(' ');
	if (var->width)
		var->len += var->width - 1;
}

void	ft_printf_s(t_var *var)
{
	char	*str;
	int		f_len;

	str = va_arg(var->arg, char *);
	if (!str)
		str = "(null)";
	f_len = ft_strlen(str);
	if (var->precision == 1 && var->p_value < f_len)
		f_len = var->p_value;
	if (var->width && !var->minus && var->width >= f_len)
		var->left = var->width - f_len;
	else if (var->width && var->minus && var->width >= f_len)
		var->right = var->width - f_len;
	var->len += f_len + var->right + var->left;
	while (var->left--)
		ft_putchar(' ');
	while (*str && f_len)
	{
		write(1, str, 1);
		str++;
		f_len--;
	}
	while (var->right--)
		ft_putchar(' ');
}

void	ft_printf_p(t_var *var)
{
	long long	n;
	int			f_len;

	n = va_arg(var->arg, long long);
	f_len = ft_unlen(n, 16) + 2;
	if (!n)
		f_len = 3;
	if (var->width && !var->minus && var->width >= f_len)
		var->left = var->width - f_len;
	else if (var->width && var->minus && var->width >= f_len)
		var->right = var->width - f_len;
	var->len += f_len + var->right + var->left;
	while (var->left--)
		ft_putchar(' ');
	if (!n)
		write (1, "0x0", 3);
	else
	{
		write(1, "0x", 2);
		ft_putnbr_base(n, 16, "0123456789abcdef");
	}
	while (var->right--)
		ft_putchar(' ');
}

void	ft_printf_di(t_var *var)
{
	int	n;
	int	f_len;
	int	f_len2;

	n = va_arg(var->arg, int);
	f_len = ft_nlen(n, 10);
	f_len2 = f_len;
	if (n < 0)
	{
		var->neg = 1;
		f_len2--;
	}
	ft_print_di_aux(var, f_len, f_len2, n);
	while (var->left--)
		ft_putchar(' ');
	if (var->plus && n >= 0)
		ft_putchar('+');
	if (var->neg)
		ft_putchar('-');
	while (var->z_value--)
		ft_putchar('0');
	ft_putnbr(n, var);
	while (var->right--)
		ft_putchar(' ');
}

void	ft_printf_ux(char c, int base, t_var *var)
{
	unsigned int	n;
	unsigned int	f_len;

	n = va_arg(var->arg, unsigned int);
	f_len = ft_unlen(n, base);
	ft_print_ux_aux(var, f_len, c, n);
	while (var->left--)
		ft_putchar(' ');
	while (var->z_value--)
		ft_putchar('0');
	if (!n)
	{
		write(1, "0", 1);
		while (var->right--)
			ft_putchar(' ');
		return ;
	}
	if (c == 'X')
		ft_putnbr_base(n, base, "0123456789ABCDEF");
	else
		ft_putnbr_base(n, base, "0123456789abcdef");
	while (var->right--)
		ft_putchar(' ');
}
