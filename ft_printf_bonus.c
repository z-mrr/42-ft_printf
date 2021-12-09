/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:24:23 by jdias-mo          #+#    #+#             */
/*   Updated: 2021/12/09 12:24:47 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_conversion(char *str, t_var *var)
{
	if (!ft_check_placeholder(*str, "cspdiuxX"))
		str = ft_flags(str, var);
	if (*str == 'c')
		ft_printf_c(var);
	else if (*str == 's')
		ft_printf_s(var);
	else if (*str == 'p')
		ft_printf_p(var);
	else if (*str == 'd' || *str == 'i')
		ft_printf_di(var);
	else if (*str == 'u')
		ft_printf_ux(*str, 10, var);
	else if (*str == 'x' || *str == 'X')
		ft_printf_ux(*str, 16, var);
	else if (*str == '%')
	{
		write(1, str, 1);
		var->len++;
	}
	return (str + 1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	t_var	var;

	va_start(var.arg, format);
	var.len = 0;
	ft_initialize (&var);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_conversion((char *)format + 1, &var);
			ft_initialize(&var);
		}
		else if (*format)
		{
			write(1, format, 1);
			format++;
			len++;
		}
	}
	va_end(var.arg);
	return (len + var.len);
}
/*
#include <stdio.h>

int	main(void)
{
	int		a, b, d = 500;
	int	*c = &d;

	a =    printf(".%#X.\n", 0);
	b = ft_printf(".%#X.\n", 0);
	printf("%d\n", a);
	printf("%d\n", b);

	return (0);
}*/
