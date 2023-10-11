/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:37:15 by caliaga-          #+#    #+#             */
/*   Updated: 2023/10/11 11:42:06 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pnumber(int n)
{
	int	wr;

	wr = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n == 0)
		return (write(1, "0", 1));
	else
	{
		if (n < 0)
		{
			wr += write(1, "-", 1);
			ft_pnumber(n = n * -1);
		}
		else
		{
			if (n > 9)
				ft_pnumber(n / 10);
			ft_pchar(n % 10 + '0');
		}
	}
	wr += ft_counter_int(n);
	return (wr);
}

int	ft_unsigned(unsigned int n)
{
	int				wr;
	unsigned int	nn;

	wr = 0;
	nn = n;
	while (nn > 9)
	{
		wr += 1;
		nn = nn / 10;
	}
	wr += 1;
	if (n > 9)
		ft_unsigned(n / 10);
	ft_pchar(n % 10 + '0');
	return (wr);
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
		*wr += write(1, "0", 1);
	else
	{
		while ((h / 16) > 0)
		{
			pre[i++] = base[(h % 16)];
			h /= 16;
		}
		pre[i] = base[(h % 16)];
		while (i >= 0)
			*wr += write(1, &pre[i--], 1);
	}
}

void	ft_point(unsigned long long p, int *wr)
{
	char	*base;
	char	pre[50];
	int		i;

	base = "0123456789abcdef";
	i = 0;
	*wr += write(1, "0x", 2);
	if (p == 0)
		*wr += write(1, "0", 1);
	else
	{
		while ((p / 16) > 0)
		{
			pre[i++] = base[(p % 16)];
			p /= 16;
		}
		pre[i] = base[(p % 16)];
		while (i >= 0)
			*wr += write(1, &pre[i--], 1);
	}
}
