/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:59:30 by caliaga-          #+#    #+#             */
/*   Updated: 2023/10/11 11:22:24 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_pchain(char	*chain);
int		ft_pchar(int c);
int		ft_counter_int(int n);
int		ft_pnumber(int n);
int		ft_unsigned(unsigned int n);
void	ft_hex(unsigned int h, char bs, int *wr);
void	ft_point(unsigned long long p, int *wr);
void	analysis_one(const char *phase, va_list *args, int *wr);
void	analysis_two(const char *phase, va_list *args, int *wr);
int		ft_printf(const char *phase, ...);

#endif
