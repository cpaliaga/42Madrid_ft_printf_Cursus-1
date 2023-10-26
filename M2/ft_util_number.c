/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:37:15 by caliaga-          #+#    #+#             */
/*   Updated: 2023/10/24 12:25:27 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pnumber(int n, int *wr)
{
	if (*wr == -1)
		return ;
	if (n == -2147483648)
	{
		if (write (1, "-2147483648", 11) == -1)
			*wr = -1;
		else
			*wr += 11;
		return ;
	}
	if (n < 0)
	{
		ft_pchar('-', wr);
		ft_pnumber(n = n * -1, wr);
	}
	else
	{
		if (n > 9)
			ft_pnumber(n / 10, wr);
		if (*wr != -1)
		{
			ft_pchar(n % 10 + '0', wr);
		}
	}
}

void	ft_unsigned(unsigned int n, int *wr)
{
	if (n > 9)
		ft_unsigned(n / 10, wr);
	if (*wr != -1)
	{
		ft_pchar(n % 10 + '0', wr);
		if (*wr == -1)
			return ;
	}
}

char	*base_hex(char bs)
{
	if (bs == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

void	ft_hex(unsigned int h, char bs, int *wr)
{
	char	*base;
	char	pre[50];
	int		i;

	base = base_hex(bs);
	i = 0;
	while ((h / 16) > 0)
	{
		pre[i++] = base[(h % 16)];
		h /= 16;
	}
	pre[i] = base[(h % 16)];
	while (i >= 0)
	{
		ft_pchar(pre[i--], wr);
		if (*wr < 0)
		{
			*wr = -1;
			break ;
		}
	}
}

void	ft_point(unsigned long long p, int *wr)
{
	char	*base;
	char	pre[50];
	int		i;

	base = "0123456789abcdef";
	i = 0;
	ft_pchain("0x", wr);
	while ((p / 16) > 0)
	{
		pre[i++] = base[(p % 16)];
		p /= 16;
	}
	pre[i] = base[(p % 16)];
	while (i >= 0)
	{
		ft_pchar(pre[i--], wr);
		if (*wr < 0)
		{
			*wr = -1;
			break ;
		}
	}
}
