/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:26:02 by jdias-mo          #+#    #+#             */
/*   Updated: 2021/12/09 12:26:06 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

void	ft_initialize(t_var *var)
{
	var->cardinal = 0;
	var->space = 0;
	var->plus = 0;
	var->zero = 0;
	var->minus = 0;
	var->width = 0;
	var->precision = 0;
	var->p_value = 0;
	var->left = 0;
	var->right = 0;
	var->z_value = 0;
	var->neg = 0;
}

int	ft_check_placeholder(char c, char *ph)
{
	while (*ph)
	{
		if (c == *ph || c == '%')
			return (1);
	ph++;
	}
	return (0);
}

int	ft_getnbr(char *str)
{
	int	n;

	n = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n);
}

char	*ft_flags(char *str, t_var *var)
{
	while (*str && !ft_check_placeholder(*str, "cspdiuxX"))
	{
		str = ft_flags_aux(var, str);
		str++;
	}
	return (str);
}
