/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:38:16 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/23 19:38:27 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *p =  "hola";

	print("Hola bienvenido a %s, %% estamos en %i - %u \n", "hardfloat.es", 2021, 1234567891);
	printf("Hola bienvenido a %s, %% estamos en %i - %u \n", "hardfloat.es", 2021, 1234567891);
	print("hexadecimal %x - HEXADECIMAL %X \n", 32, 64);
	printf("hexadecimal %x - HEXADECIMAL %X \n", 32, 64);
	print("Puntero %p \n", p);
	printf("Puntero %p \n", p);
	print("Puntero %s \n", p);
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
