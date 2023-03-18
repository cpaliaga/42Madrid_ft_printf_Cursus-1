/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:59:13 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/18 17:18:54 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> /* printf() */
#include <stdarg.h>  /* va_list */
#include <stdint.h> /* uint */

void	ft_pchar(int c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

void	ft_pchain(char *chain)
{
	if (!chain)
		write(1, "(null)", 6);
	else
		write(1, chain, ft_strlen(chain));
}

size_t	ft_reverse(unsigned int nb)
{
	size_t	rev;

	rev = 0;
	while (nb > 9)
	{
		rev += nb % 10;
		rev *= 10;
		nb /= 10;
	}
	rev += nb % 10;
	return (rev);
}

void	ft_pnumber(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_pnumber(n = n * -1);
			ft_pchar('-');
		}
		else
		{
			n = ft_reverse(n);
			while (n > 0)
			{
				ft_pchar(n % 10 + '0');
				n /= 10;
			}
		}
	}
}

void	ft_unsigned(unsigned int nb)
{
	nb = ft_reverse(nb);
	while (nb > 0)
	{
		ft_pchar(nb % 10 + '0');
		nb /= 10;
	}
}

void	ft_hex(unsigned int h, char bs)
{
	char	*base;

	if (bs == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
}
/**/
/*void ft_pnt(){}*/

void	print(const char *phase, ...)
{
	va_list	args;

	va_start (args, phase);
	while (*phase)
	{
		if (*phase == '%')
		{
			if (*(phase + 1) == 'c') // EL ARGUMENTO ES UN CARACTER
			{
				ft_pchar(va_arg(args, int));
				phase++;
			}
			else if (*(phase + 1) == '%') // EL ARGUMENTO ES UN PORCENTAJE
			{
				ft_pchar('%');
				phase++;
			}
			else if (*(phase + 1) == 's') // EL ARGUMENTO ES UNA CADENA
			{
				ft_pchain(va_arg (args, char *));
				phase++;
			}
			else if (*(phase + 1) == 'd' || *(phase + 1) == 'i') //EL ARGUMENTO ES UN ENTERO 
			{
				ft_pnumber(va_arg(args, int));
				phase++;
			}
			else if (*(phase + 1) == 'u') //EL ARGUMENTO ES UN ENTERO SIN SIGNO
			{
				ft_unsigned(va_arg(args, unsigned int));
				phase++;
			}
			else if (*(phase + 1) == 'x' || *(phase + 1) == 'X') //EL ARGUMENTO ES UN HEXADECIMAL
			{
				ft_hex(va_arg(args, unsigned int), *(phase + 1));
				phase++;
			}
			else if (*(phase + 1) == 'p') //EL ARGUMENTO ES UN PUNTERO
			{
				ft_pnt(va_arg(args, unsigned int));
				phase++;
			}
		}
		else
		{
			write(1, phase, 1);
		}
		phase++;
	}
	va_end(args);
}

int	main(void)
{
	print("Hola bienvenido a %s, %% estamos en %i - %u \n", "hardfloat.es", 2021, 1234567891);
	print("Hola bienvenido a hexadecimal %x en HEXADECIMAL %X \n", 3456, 2021);
	return (0);
}

/* Deberás implementar las siguientes conversiones: cspdiuxX % */
/* %c Imprime un solo carácter.*/
/* %s Imprime una string */
/* %% para imprimir el símbolo del porcentaje. */
/* %d Imprime un número decimal (base 10).*/
/* %i Imprime un entero en base 10.*/
/* %u Imprime un número decimal (base 10) sin signo. */
/* %x Imprime un número hexadecimal (base 16) en minúsculas. */
/* %X Imprime un número hexadecimal (base 16) en mayúsculas.*/
/* %p El puntero void * dado como argumento se imprime en formato hexadecimal. */
/**http://agora.pucp.edu.pe/inf2170681/3.htm*/
/**https://entredesarrolladores.com/3248/c%C3%B3mo-dividir-un-int-en-dos-bytes-en-c*/
/**http://www.lcc.uma.es/~tutor-fi/ejercicios5.html*/
