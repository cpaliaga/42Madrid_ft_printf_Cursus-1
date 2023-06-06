/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:59:13 by caliaga-          #+#    #+#             */
/*   Updated: 2023/06/06 12:56:38 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	analysis_one(const char *phase, va_list *args, int *wr)
{
	if (*(phase + 1) == 'c')
	{
		*wr += ft_pchar(va_arg(*args, int), wr);
		phase++;
	}
	else if (*(phase + 1) == '%')
	{
		*wr += ft_pchar('%', wr);
		phase++;
	}
	else if (*(phase + 1) == 's')
	{
		ft_pchain(va_arg (*args, char *), wr);
		phase++;
	}
}

void	analysis_two(const char *phase, va_list *args, int *wr)
{
	if (*(phase + 1) == 'd' || *(phase + 1) == 'i')
	{
		ft_pnumber(va_arg(*args, int), wr);
		phase++;
	}
	else if (*(phase + 1) == 'u')
	{
		ft_unsigned(va_arg(*args, unsigned int), wr);
		phase++;
	}
	else if (*(phase + 1) == 'x' || *(phase + 1) == 'X')
	{
		ft_hex(va_arg(*args, unsigned int), *(phase + 1), wr);
		phase++;
	}
	else if (*(phase + 1) == 'p')
	{
		ft_point(va_arg(*args, unsigned long long), wr);
		phase++;
	}
}

int	ft_printf(const char *phase, ...)
{
	int		wr;
	va_list	args;

	wr = 0;
	va_start (args, phase);
	while (*phase)
	{
		if (*phase == '%' && *(phase + 1))
		{
			analysis_one(phase, &args, &wr);
			analysis_two(phase, &args, &wr);
			phase++;
		}
		else
		{
			wr += write(1, phase, 1);
			if (wr == -1)
				return (0);
		}
		phase++;
	}
	va_end(args);
	return (wr);
}
