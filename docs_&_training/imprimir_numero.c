
#include <unistd.h>
#include <stdio.h>
#include <limits.h>


int ft_pchar(int c);
int ft_pnumber(int n);
int ft_counter_int(int n);

int ft_pchar(int c)
{
	int wr;

	wr = 0;
	if (c != '\0')
        wr = write(1, &c, 1);
	if (wr == -1)
		return (-1);
	return (wr);
}

int ft_counter_int(int n)
{
    int wr;

    wr = 0;
    if (n == -2147483648)
		wr += 11;
	else if (n == 0)
		wr += 1;
	else
	{
		if (n < 0)
			wr += 1;
        else
        {
            while (n > 9)
            {
                wr += 1;
                n = n / 10;
            }
            wr += 1;
        }
	}
    return (wr);
}

/* «int ft_counter_int(int n)» tiene {22 lineas} internas */

int ft_pnumber(int n)
{
    int wr;

    wr = 0;
    if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n == 0)
		write(1, "0", 1);
	else
	{
		if (n < 0)
		{
			wr += write(1, "-", 1);
			ft_pnumber(n = n * -1);
		}
        else
        {
            if (n > 9)
                ft_pnumber(n / 10);
            ft_pchar(n % 10 + '0');
        }
	}
    wr += ft_counter_int(n);
    return (wr);
}

/* «int ft_counter_int(int n)» tiene {23 lineas} internas */

/**
 * Se ha creado una nueva funcion «int ft_counter_int(int n)» para dar 
 * servicio a «ft_pnumber» ya que cuando realiza recursividad para 
 * dividir n la función «ft_pchar()» que contiene a la función 
 * «write()» no es capaz de devolver el número de caracteres impresos 
 * por write, es por ello que se aplica el contador «ft_counter_int(n)» 
 * fuera del bloque de recursividad. Líneas 60 a 70.
*/
int main () 
{
    printf("BATERIA DE PRUEBAS\n");
    int clon0 = ft_pnumber(-2147483648);
    printf("\t%i\n", clon0);
    
    int org0 = printf("%li", -2147483648);
    printf("\t%i\n", org0);

    int clon1 = ft_pnumber(2147483647);
    printf("\t%i\n", clon1);
    
    int org1 = printf("%i", 2147483647);
    printf("\t%i\n", org1);

    int clon2 = ft_pnumber(0);
    printf("\t%i\n", clon2);
    
    int org2 = printf("%i", 0);
    printf("\t%i\n", org2);

    int clon3 = ft_pnumber(100);
    printf("\t%i\n", clon3);
    
    int org3 = printf("%i", 100);
    printf("\t%i\n", org3);

    int clon4 = ft_pnumber(-100);
    printf("\t%i\n", clon4);
    
    int org4 = printf("%i", -100);
    printf("\t%i\n", org4);

    printf("BATERIA DE PRUEBAS\n");
    int clon5 = ft_pnumber(INT_MIN);
    printf("\t%i\n", clon5);
    
    int org5 = printf("%i", INT_MIN);
    printf("\t%i\n", org5);

    int clon6 = ft_pnumber(INT_MAX);
    printf("\t%i\n", clon6);
    
    int org6 = printf("%i", INT_MAX);
    printf("\t%i\n", org6);

return 0;
}