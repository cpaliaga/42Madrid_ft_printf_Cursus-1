
#include <unistd.h>
#include <stdio.h>

int	ft_pchain(char *chain);

int	ft_pchain(char *chain)
{
    int     wr;
	size_t	a;

	wr = 0;
    a = 0;
	if (!chain)
	{
		wr += write(1, "(null)", 6);
		return (0);
	}
    else{
        while (chain[a] != '\0')
        {
            if (chain[a] == '\t')
                wr += 1;
            wr += write(1, &chain[a], sizeof(chain[a]));
            a++;
        }
		//wr += write(1, chain, a);
    }
   
    
    return (wr);
}

int main (void)
{  
    printf("Prueba de Caracteres ASCII IMPRIMIBLE \n");
    int cad0 = ft_pchain(" hola*");
    printf("\t%i", cad0);
    int ori0 = printf("%s", " hola*");
    printf("\t%i", ori0);
    printf("\n");

    printf("Prueba de Caracteres ASCII EXTENDIDO \n");
    int cad1 = ft_pchain(" hola ñoño");
    printf("\t%i", cad1);
    int ori1 = printf("%s", " hola ñoño");
    printf("\t%i", ori1);
    printf("\n");

    int cad2 = ft_pchain("hélade");
    printf("\t%i", cad2);
    int ori2 = printf("%s", "hélade");
    printf("\t%i", ori2);
    printf("\n");

    printf("Prueba de Caracteres ASCII NO IMPRIMIBLES \n");
    int cad3 = ft_pchain(" %hola lolo   ñ");
    printf("\t%i", cad3);
    int ori3 = printf("%s", " %hola lolo    ñ");
    printf("\t%i", ori3);
    printf("\n");

    int cad4 = ft_pchain(" %hola lolo\0%%");
    printf("\t%i", cad4);
    int ori4 = printf("%s", " %hola lolo\0%%");
    printf("\t%i", ori4);
    printf("\n");

    printf("Prueba de Tipo Incompatible Char \n");
    //int cad5 = ft_pchain('0');
    //printf("\t%i", cad5);
    //int ori5 = printf("%s", '0');
    //printf("\t%i", ori5);
    //printf("\n");

    printf("Prueba de Tipo Incompatible Int \n");
    int cad6 = ft_pchain(0);
    printf("\t%i", cad6);
    //int ori6 = printf("%s", 0);
    //printf("\t%i", ori6);
    printf("\n");

    return (0);
}