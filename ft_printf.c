/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:59:13 by caliaga-          #+#    #+#             */
/*   Updated: 2023/02/20 17:59:16 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>  /* va_list */


int	print (const char* phase, ...)
{
    va_list args;
    va_start(args, phase);
    while (*phase) {
        if (*phase == '%') {
            if (*(phase + 1) == 's')
            {
                /*EL ARGUMENTO ES UNA CADENA*/
                char *flag_char = va_arg(args, char*);
                int len_flag_char = 0;
                int i;
                while(*flag_char)
                {
                    write(1,flag_char,1);
                    flag_char++;
                }
                /* ****** ***** ****** */
                phase++;
            }
            else if (* (phase + 1) == 'i') 
            {
                /*EL ARGUMENTO ES UN ENTERO*/
            
                printf("%d", va_arg(args, int));
                phase++;
            }
        }
        else
        {
            write(1,phase,1);
        }
        phase++;
    }
    va_end(args);
}

int main(void)
{
    print("Hola bienvenido a %s, estamos en %i\n", "hardfloat.es", 2021);
    return 0;
    return (0);
}
