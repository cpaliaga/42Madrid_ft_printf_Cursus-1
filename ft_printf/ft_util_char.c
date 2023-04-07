/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:37:36 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/28 12:41:26 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
