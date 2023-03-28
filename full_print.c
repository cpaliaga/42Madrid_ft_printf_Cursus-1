/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:56:55 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/28 12:59:10 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

void	ft_pchar(int c, int *wr)
{
	wr += write(1, &c, 1);
}

void	ft_pchain(char *chain, int *wr)
{
	size_t	a;

	a = 0;
	while (chain[a] != '\0')
		a++;
	if (!chain)
		wr += write(1, "(null)", 6);
	else
		wr += write(1, chain, a);
}

void	conversion_one(const char *phase, va_list *args, int *wr)
{
	if (*(phase + 1) == 'c')
	{
		ft_pchar(va_arg(*args, int), &wr);
		phase++;
	}
	else if (*(phase + 1) == '%')
	{
		ft_pchar('%', &wr);
		phase++;
	}
	else if (*(phase + 1) == 's')
	{
		ft_pchain(va_arg (*args, char *), &wr);
		phase++;
	}
}

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

void	conversion_two(const char *phase, va_list *args, int *wr)
{
	if (*(phase + 1) == 'd' || *(phase + 1) == 'i')
	{
		ft_pnumber(va_arg(args, int), &wr);
		phase++;
	}
	else if (*(phase + 1) == 'u')
	{
		ft_unsigned(va_arg(args, unsigned int), &wr);
		phase++;
	}
	else if (*(phase + 1) == 'x' || *(phase + 1) == 'X')
	{
		ft_hex(va_arg(args, unsigned int), *(phase + 1), &wr);
		phase++;
	}
	else if (*(phase + 1) == 'p')
	{
		ft_point(va_arg(args, unsigned long long), &wr);
		phase++;
	}
}

int	print(const char *phase, ...)
{
	int		wr;
	va_list	args;

	wr = 0;
	va_start (args, phase);
	while (*phase)
	{
		if (*phase == '%')
		{
			conversion_one(phase, &args, &wr);
			conversion_two(phase, &args, &wr);
		}
		else
		{
			wr += write(1, phase, 1);
		}
		phase++;
	}
	va_end(args);
	return (wr);
}
