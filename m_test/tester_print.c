/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:38:16 by caliaga-          #+#    #+#             */
/*   Updated: 2023/07/14 20:44:23 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
/*
void    leaks(void)
{
    system("leaks m_test");
}
*/

int	main(void)
{
	//char *p =  "hola";

	int M = ft_printf("%d", -10);
	int O = printf("%d", -10);
	printf("\n%d %d", M, O);
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

/**
 * 
 * ft_printf("O se han impreso %d caracteres \n",O1);
	ft_printf("M integer %i - unsigned %u \n", 2021, 1234567891);
	printf("O integer %i - unsigned %u \n", 2021, 1234567891);
	ft_printf("M hexadecimal %x - HEXADECIMAL %X \n", 32, 64);
	printf("O hexadecimal %x - HEXADECIMAL %X \n", 32, 64);
	ft_printf("M Puntero %p \n", p);
	printf("O Puntero %p \n", p);
	ft_printf("M Puntero cadena  %s \n", p);
	printf("O Puntero cadena  %s \n", p);
	ft_printf("");
	printf("");
	//ft_printf(34);
	//printf(34);

	//atexit(leaks);
*/