/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:37:36 by caliaga-          #+#    #+#             */
/*   Updated: 2023/07/14 20:12:05 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pchar(int c, int *wr)
{
	int	wr_int;

	wr_int = 0;
	wr_int += write(1, &c, 1);
	if (wr_int == -1)
		return;
	*wr = wr_int;
}

void	ft_pchain(char *chain, int *wr)
{
	size_t	a;

	a = 0;
	if (!chain)
	{
		*wr += write(1, "(null)", 6);
		return ;
	}
	else
	{
		while (chain[a] != '\0')
			a++;
		*wr += write(1, chain, a);
	}
}
