/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <caliaga-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:38:16 by caliaga-          #+#    #+#             */
/*   Updated: 2023/10/23 18:46:38 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../M/ft_printf.h"
#include <stdio.h>
#include <limits.h>
/*
void    leaks(void)
{
    system("leaks m_test");
}
*/

int	main(void)
{
    printf("00 Prueba CHAR - ASCII no imprimible \\n \n");
    int cc0 = ft_printf("%c", '\n');
    printf("\t%i", cc0);
    printf(" -» ");
    int oo0 = printf("%c", '\n');
    printf("\t%i", oo0);
    printf("\n");

    printf("01 Prueba CHAR - ASCII no imprimible \\0 \n");
    int cc1 = ft_printf("%c", '\0');
    printf("\t%i", cc1);
    printf(" -» ");
    int oo1 = printf("%c", '\0');
    printf("\t%i", oo1);
    printf("\n");

    printf("02 Prueba CHAR - ASCII no imprimible \\t \n");
    int cc2 = ft_printf("%c", '\t');
    printf("\t%i", cc2);
    printf(" -» ");
    int oo2 = printf("%c", '\t');
    printf("\t%i", oo2);
    printf("\n");
    
    printf("03 Prueba CHAR - ASCII imprimible \n");
    int cc3 = ft_printf("%c", '%');
    printf("\t%i", cc3);
    printf(" -» ");
    int oo3 = printf("%c", '%');
    printf("\t%i", oo3);
    printf("\n");

    printf("04 Prueba CHAR - ASCII imprimible 42+'\\0' \n");
	int cc4 = ft_printf("%c", 42+'\0');
    printf("\t%i", cc4);
    printf(" -» ");
    int oo4 = printf("%c", 42+'\0');
    printf("\t%i", oo4);
    printf("\n");

    printf("05 Prueba CHAR - ASCII imprimible 134+'\\0' \n");
	int cc5 = ft_printf("%c", 134+'\0');
    printf("\t%i", cc5);
    printf(" -» ");
    int oo5 = printf("%c", 134+'\0');
    printf("\t%i", oo5);
    printf("\n");

/*     printf("07 Prueba CHAR → ñ warning: multi-character character constant [-Wmultichar]\n");
    int cc7 = ft_pchar('→');
    printf("\t%i", cc7);
    int oo7 = printf("%c", '→');
    printf("\t%i", oo7);
    printf("\n"); */

/*     printf("06 Prueba CHAR error: empty character constant\n");
    int cc6 = ft_pchar('');
    printf("\t%i", cc6);
    int oo6 = printf("%c", '');
    printf("\t%i", oo6);
    printf("\n"); */

    printf("08 Prueba SIN flags - ASCII imprimible '%%%%%%' \n");
	int cc8 = ft_printf("%%%%%%");
    printf("\t%i", cc8);
    printf(" -» ");
    int oo8 = printf("%%%%%%");
    printf("\t%i", oo8);
    printf("\n");

    printf("09 Prueba SIN flags - ASCII imprimible '%%\\0%%' error: embedded ‘\\0’ in format [-Werror=format-contains-nul] \n");
	int cc9 = ft_printf("%%\0%%");
    printf("\t%i", cc9);
    printf(" -» ");
/*     int oo9 = printf("%%\0%%");
    printf("\t%i", oo9); */
    printf("\n");

    printf("20 Prueba INT - \n");
	int cc20 = ft_printf("%i", -2147483647);
    printf("\t%i", cc20);
    printf(" -» ");
    int oo20 = printf("%i", -2147483647);
    printf("\t%i", oo20);
    printf("\n");

    printf("21 Prueba UINT - \n");
	int cc21 = ft_printf("%u", -2147483647);
    printf("\t%i", cc21);
    printf(" -» ");
    int oo21 = printf("%u", -2147483647);
    printf("\t%i", oo21);
    printf("\n");

/*     printf("22 Prueba SIN Flags - \n");
	int cc22 = ft_printf("%%c");
    printf("\t%i", cc212);
    printf(" -» ");
    int oo22 = printf("%%c");
    printf("\t%i", oo22);
    printf("\n"); */

    printf("23 Prueba UINT - \n");
	int cc23 = ft_printf("%d", INT_MIN);
    printf("\t%i", cc23);
    printf(" -» ");
    int oo23 = printf("%d", INT_MIN);
    printf("\t%i", oo23);
    printf("\n");

    printf("24 Prueba puntero '""' - \n");
	int cc24 = ft_printf("%p", "");
    printf("\t%i", cc24);
    printf(" -» ");
    int oo24 = printf("%p", "");
    printf("\t%i", oo24);
    printf("\n");

 /**
  *   TEST(23, print(" %d ", INT_MIN));
53:     TEST(29, print(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
ft_printf("%p", ""):

 */
	/*int wd5 = ft_printf("%%%");
    printf("\t%i", wd5);
    printf(" -» ");
    int or5 = printf("%%%"); error: spurious trailing ‘%’ in format [-Werror=format=]
    printf("\t%i", or5);
    printf("\n");*/

/* 	int wd6 = ft_printf("%%c");
    printf("\t%i", wd6);
    printf(" -» ");
    int or6 = printf("%%c");
    printf("\t%i", or6);
    printf("\n"); */

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