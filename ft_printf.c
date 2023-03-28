/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:59:13 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/28 11:18:34 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_one(const char *phase, va_list args, int *wr)
{

			if (*(phase + 1) == 'c')
			{
				ft_pchar(va_arg(args, int), int *wr);
				phase++;
			}
			else if (*(phase + 1) == '%')
			{
				ft_pchar('%', int *wr);
				phase++;
			}
			else if (*(phase + 1) == 's')
			{
				ft_pchain(va_arg (args, char *), int *wr);
				phase++;
			}
}

void	conversion_two()
{}




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
			if (*(phase + 1) == 'c')
			{
				ft_pchar(va_arg(args, int));
				phase++;
			}
			else if (*(phase + 1) == '%')
			{
				ft_pchar('%');
				phase++;
			}
			else if (*(phase + 1) == 's')
			{
				ft_pchain(va_arg (args, char *));
				phase++;
			}
			else if (*(phase + 1) == 'd' || *(phase + 1) == 'i')
			{
				ft_pnumber(va_arg(args, int));
				phase++;
			}
			else if (*(phase + 1) == 'u')
			{
				ft_unsigned(va_arg(args, unsigned int));
				phase++;
			}
			else if (*(phase + 1) == 'x' || *(phase + 1) == 'X')
			{
				ft_hex(va_arg(args, unsigned int), *(phase + 1));
				phase++;
			}
			else if (*(phase + 1) == 'p')
			{
				ft_point(va_arg(args, unsigned long long));
				phase++;
			}
		}
		else
		{
			write(1, phase, 1);
		}
		phase++;
	}
	va_end(args);
	return (wr);
}
