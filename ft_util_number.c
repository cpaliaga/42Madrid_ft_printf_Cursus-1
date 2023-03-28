/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:37:15 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/28 12:31:30 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_reverse(unsigned int nb)
{
	size_t	rev;

	rev = 0;
	while (nb > 9)
	{
		rev += nb % 10;
		rev *= 10;
		nb /= 10;
	}
	rev += nb % 10;
	return (rev);
}

void	ft_pnumber(int n, int *wr)
{
	if (n == -2147483648)
	{
		wr += write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			ft_pnumber(n = n * -1, &wr);
			wr += write(1, "-", 1);
		}
		else
		{
			n = ft_reverse(n);
			while (n > 0)
			{
				ft_pchar(n % 10 + '0', &wr);
				n /= 10;
			}
		}
	}
}

void	ft_unsigned(unsigned int nb, int *wr)
{
	nb = ft_reverse(nb);
	while (nb > 0)
	{
		ft_pchar(nb % 10 + '0', &wr);
		nb /= 10;
	}
}

void	ft_hex(unsigned int h, char bs, int *wr)
{
	char	*base;
	char	pre[50];
	int		i;

	if (bs == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (h == 0)
		wr += write(1, "0", 1);
	else
	{
		while ((h / 16) > 0)
		{
			pre[i++] = base[(h % 16)];
			h /= 16;
		}
		pre[i] = base[(h % 16)];
		while (i >= 0)
			wr += write(1, &pre[i--], 1);
	}
}

void	ft_point(unsigned long long p, int *wr)
{
	char	*base;
	char	pre[50];
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (p == 0)
		wr += write(1, "0", 1);
	else
	{
		while ((p / 16) > 0)
		{
			pre[i++] = base[(p % 16)];
			p /= 16;
		}
		pre[i] = base[(p % 16)];
		wr += write(1, "0x", 2);
		while (i >= 0)
			wr += write(1, &pre[i--], 1);
	}
}
