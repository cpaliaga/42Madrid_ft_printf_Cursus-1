/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:59:13 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/23 19:50:51 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(const char *phase, ...)
{
	va_list	args;

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
}
