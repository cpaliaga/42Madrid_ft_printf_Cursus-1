/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:53:50 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/23 15:27:40 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_pchain(char *chain)
{
	int	len;

	len = 0;
	if (!chain)
		write(1, "(null)", 6);
	else
		while(chain[len] != '\0')
			len++;
		write(1, chain, len);
}

void    ft_hex(unsigned int h, char bs)
{
	char    *base;
	char    pre[25];
	int     i;
	unsigned int	z;
	
	z = 0;
	if (bs == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (h == 0)
		write(1, "0", 1);
	else
	{
		while( (h/16) > 0)
		{
			z = h % 16;
			printf("%u \n", z);
			//write(1, base[z], 1);
			//pre[i] = base[z];
			h /= 16;
		}
		//ft_pchain(pre);
	}
}

int	main()
{
	unsigned int a = 23454;

	printf("%X \n", a);	
	ft_hex(a, 'X');

	return (0);
}
