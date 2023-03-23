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

/*
void	ft_phex(char *pre, int i)
{

}
*/

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
		write(1, "0", 1);
	else
	{
		while( (h/16) > 0)
		{
			pre[i++] = base[(h % 16)];
			h /= 16;
		}
		pre[i] = base[(h % 16)];
		while (i >= 0)
			write(1, &pre[i--], 1);
	}
}

int	main()
{
	unsigned int a = 23454;

	printf("%X numero \n", a);	
	ft_hex(a, 'X');
	printf("\n");	

	return (0);
}