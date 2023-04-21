/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:37:36 by caliaga-          #+#    #+#             */
/*   Updated: 2023/04/13 19:12:00 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pchar(int c, int *wr)
{
	*wr += write(1, &c, 1);
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
