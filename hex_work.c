/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:53:50 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/23 14:18:07 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t  ft_strlen(char *str)
{
	size_t  a;
	
	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

void    ft_pchain(char *chain)
{
	if (!chain)
		write(1, "(null)", 6);
	else
		write(1, chain, ft_strlen(chain));
}

void    ft_hex(unsigned int h, char bs)
{
	char    *base;
	char    pre[25];
	int     i;
	
	if (bs == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (h == 0)
		white(1, '0', 1);
	else
	{
		while(h > 0)
		{
			printf("%u", (h%16));
			pre[i] = base[h % 16];
			h /= 16;
		}
		ft_pchain(pre,i);
	}
}
