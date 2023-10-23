/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:37:36 by caliaga-          #+#    #+#             */
/*   Updated: 2023/10/23 17:46:16 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pchar(int c,	int	*wr)
{
	if (write (1, &c, 1) == -1)
	{
		*wr = -1;
	}
	else
	{
		*wr += 1;
	}
}

void	ft_pchain(char *chain, int *wr)
{
	size_t	len;

	len = 0;
	if (!chain)
	{
		ft_pchain("(null)", wr);
		return ;
	}
	while (chain[len] != '\0')
	{
		ft_pchar(chain[len], wr);
		if (*wr == -1)
			return ;
		len++;
	}
}
