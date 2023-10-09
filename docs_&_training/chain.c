
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_pchain(char *chain);
int ft_pchar(int c);

int ft_pchar(int c)
{
	int wr;

    wr = write(1, &c, 1);
	if (wr == -1)
		return (-1);
	return (wr);
}

int	ft_pchain(char *chain)
{
    int     wr;
	size_t	len;

	wr = 0;
    len = 0;
	if (!chain)
		return (write(1, "(null)", 6));
    else{
        while (chain[len] != '\0')
            len++;
        return (write(1, chain, len));
    }
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
    int cad1 = ft_pchain("ñoño");
    printf("\t%i", cad1);
    int ori1 = printf("%s", "ñoño");
    printf("\t%i", ori1);
    printf("\n");

    int cad2 = ft_pchain("hélade");
    printf("\t%i", cad2);
    int ori2 = printf("%s", "hélade");
    printf("\t%i", ori2);
    printf("\n");

    printf("Prueba de Caracteres ASCII NO IMPRIMIBLES \n");
    int cad3 = ft_pchain("hola   ñ");
    printf("\t%i", cad3);
    int ori3 = printf("%s", "hola    ñ");
    printf("\t%i", ori3);
    printf("\n");

    int cad4 = ft_pchain("\thola \nlolo\0%%");
    printf("\t%i", cad4);
    int ori4 = printf("%s", "\thola \nlolo\0%%");
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

    int wd1 = ft_pchar(42+'0');
    printf("\t%i", wd1);
    printf(" -» ");
    int or1 = printf("%c", 42+'0');
    printf("\t%i", or1);
    printf("\n");

    int wd2 = ft_pchar(' ');
    printf("\t%i", wd2);
    printf(" -» ");
    int or2 = printf("%c", ' ');
    printf("\t%i", or2);
    printf("\n");

    int wd3 = ft_pchar( 42+'\0');
    printf("\t%i", wd3);
    printf(" -» ");
    int or3 = printf("%c", 42+'\0');
    printf("\t%i", or3);
    printf("\n");

    return (0);
}