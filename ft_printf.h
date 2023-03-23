/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:59:30 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/23 19:49:08 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

void	ft_pchar(int c);
void	ft_pchain(char *chain);
size_t	ft_reverse(unsigned int nb);
void	ft_pnumber(int n);
void	ft_unsigned(unsigned int nb);
void    ft_hex(unsigned int h, char bs);
void	ft_point(unsigned long long p);
void	print(const char *phase, ...);

#endif
