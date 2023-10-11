/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:37:36 by caliaga-          #+#    #+#             */
/*   Updated: 2023/10/11 11:37:04 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pchar(int c)
{
	int	wr;

	wr = write(1, &c, 1);
	if (wr == -1)
		return (-1);
	return (wr);
}

int	ft_pchain(char *chain)
{
	int		wr;
	size_t	len;

	wr = 0;
	len = 0;
	if (!chain)
	{	
		wr = write(1, "(null)", 6);
		if (wr == -1)
			return (-1);
		return (wr);
	}
	else
	{
		while (chain[len] != '\0')
			len++;
		wr = write(1, chain, len);
		if (wr == -1)
			return (-1);
		return (wr);
	}
}

int	ft_counter_int(int n)
{
	int	wr;

	wr = 0;
	if (n == -2147483648)
		wr += 11;
	else if (n == 0)
		wr += 1;
	else
	{
		if (n < 0)
			wr += 1;
		else
		{
			while (n > 9)
			{
				wr += 1;
				n = n / 10;
			}
			wr += 1;
		}
	}
	return (wr);
}
