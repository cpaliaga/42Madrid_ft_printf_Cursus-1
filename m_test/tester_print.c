/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:38:16 by caliaga-          #+#    #+#             */
/*   Updated: 2023/03/28 12:34:52 by caliaga-         ###   ########.fr       */
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
	
	int M1 = ft_printf("M Caracter %% y %c \n", 'D');
	printf("M se han impreso %d caracteres \n",M1);
	int O1 = printf("O Caracter %% y %c \n", 'D');
	printf("O se han impreso %d caracteres \n",O1);


	int M2 = ft_printf("M '%s' \n", "'Soy una cadena'");
	printf("M se han impreso %d caracteres \n",M2);
	int O2 = printf("O '%s' \n", "'Soy una cadena'");
	printf("O se han impreso %d caracteres \n",O2);
	
	ft_printf("M integer %i - unsigned %u \n", 2021, 1234567891);
	printf("O integer %i - unsigned %u \n", 2021, 1234567891);
	ft_printf("M hexadecimal %x - HEXADECIMAL %X \n", 32, 64);
	printf("O hexadecimal %x - HEXADECIMAL %X \n", 32, 64);

	char *p =  "hola";
	ft_printf("M Puntero %p \n", p);
	printf("O Puntero %p \n", p);
	ft_printf("M Puntero cadena  %s \n", p);
	printf("O Puntero cadena  %s \n", p);

	//atexit(leaks);
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
