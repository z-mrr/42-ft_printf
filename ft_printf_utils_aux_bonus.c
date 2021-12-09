/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_aux_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:26:44 by jdias-mo          #+#    #+#             */
/*   Updated: 2021/12/09 12:26:46 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_nlen(int n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n && ++i)
		n /= base;
	return (i);
}

int	ft_unlen(unsigned long long n, int base)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n && ++i)
		n /= base;
	return (i);
}

void	ft_putnbr(int n, t_var *var)
{
	int		i;
	int		nbr[11];

	if (n < 0)
		var->neg = 1;
	if (n == -2147483648 || n == 0)
	{
		if (n == -2147483648)
			write(1, "2147483648", 10);
		else if (n == 0)
			ft_putchar('0');
		return ;
	}
	if (n < 0)
		n = -n;
	i = 0;
	while (n > 0)
	{
		nbr[i] = n % 10;
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbr[i] + '0');
}

void	ft_putnbr_base(unsigned long long n, int base, char *radix)
{
	int		i;
	int		tab[21];

	i = 0;
	while (n)
	{
		tab[i] = n % base;
		n /= base;
		i++;
	}
	while (--i >= 0)
		ft_putchar(radix[tab[i]]);
}
