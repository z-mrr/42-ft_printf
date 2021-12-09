/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_aux_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:25:39 by jdias-mo          #+#    #+#             */
/*   Updated: 2021/12/09 12:25:42 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_di_aux(t_var *var, int f_len, int f_len2, int n)
{
	if (var->width && !var->minus && var->width >= f_len
		&& var->width > var->p_value)
		var->left = var->width - f_len - var->p_value;
	else if (var->width && var->minus
		&& var->width >= f_len && var->width > var->p_value)
		var->right = var->width - f_len - var->p_value;
	if (var->zero && !var->minus)
	{
		var->z_value += var->left;
		var->left = 0;
	}
	if (var->p_value >= f_len2)
		var->z_value += var->p_value - f_len2;
	if (var->space && !var->neg)
		var->left++;
	if (n < 0)
		var->plus = 0;
	var->len += var->left + var->right + var->z_value + var->plus + f_len;
}

void	ft_print_ux_aux(t_var *var, int f_len, char c, unsigned int n)
{
	if (var->cardinal && n)
	{
		ft_putchar('0');
		if (c == 'x')
			ft_putchar('x');
		else
			ft_putchar('X');
	}
	else
		var->cardinal = 0;
	if (var->width && !var->minus && var->width >= f_len
		&& var->width > var->p_value)
		var->left = var->width - f_len - var->p_value;
	else if (var->width && var->minus
		&& var->width >= f_len && var->width > var->p_value)
		var->right = var->width - f_len - var->p_value;
	if (var->zero && !var->minus)
	{
		var->z_value += var->left;
		var->left = 0;
	}
	if (var->p_value >= f_len)
		var->z_value += var->p_value - f_len;
	var->len += f_len + (var->cardinal * 2)
		+ var->left + var->right + var->z_value;
}

char	*ft_flags_aux(t_var *var, char *str)
{
	if (*str == '#')
		var->cardinal = 1;
	else if (*str == ' ')
		var->space = 1;
	else if (*str == '+')
		var->plus = 1;
	else if (*str == '-')
		var->minus = 1;
	else if (*str == '0')
		var->zero = 1;
	else if (*str >= '0' && *str <= '9')
	{
		var->width = ft_getnbr(str);
		str = str + (ft_nlen(var->width, 10) - 1);
	}
	else if (*str == '.')
	{
		var->p_value = ft_getnbr(str + 1);
		var->precision = 1;
		if (var->p_value)
			str = str + ft_nlen(var->p_value, 10);
	}
	return (str);
}
