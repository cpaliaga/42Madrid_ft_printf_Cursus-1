#include <stdio.h>
#include <string.h> 
/*<string.h> Funcion de error char *strerror(int errnum);
Convierte el número de error en errnum a un mensaje 
de error (una cadena de caracteres). Valor de retorno:
La función retorna la cadena de caracteres conteniendo el 
mensaje asociado con el número de error. Esta conversión y 
el contenido del mensaje dependen de la implementación. 
La cadena no será modificada por el programa, pero sí puede 
ser sobrescrito con otra llamada a la misma función.
*/ 

void lista_errores();

void lista_errores()
{
    int i = 0;
    while (i < 134)
        printf("%i - %s\n", i, strerror(i++));
    
}

int main (void)
{
    printf("Lista de 134 números de error convertidos a texto:\n");
   
    lista_errores();
    return (0);
}
