
#include <unistd.h>
#include <stdio.h>
#include <limits.h> // Constantes de Valores máximos

int	ft_pchain(char *chain);
int ft_pchar(int c);

int ft_pchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
    else
        return (1);
}

int	ft_pchain(char *chain)
{
	size_t	len;

    len = 0;
	if (!chain)
        chain = "(null)";
    while (chain[len] != '\0')
    {
        if (ft_pchar(chain[len]) == -1)
            return (-1);
    	len++;
    }
    return (len);
}

int main (void)
{
    printf("Prueba CHAR \n");
    int cc0 = ft_pchar(42+'0');
    printf("\t%i", cc0);
    int oo0 = printf("%c", 42+'0');
    printf("\t%i", oo0);
    printf("\n");

/*     printf("Prueba CHAR warning: multi-character character constant [-Wmultichar]\n");
    int cc1 = ft_pchar('→');
    printf("\t%i", cc1);
    int oo1 = printf("%c", '→');
    printf("\t%i", oo1);
    printf("\n"); */

/*     printf("Prueba CHAR error: empty character constant\n");
    int cc2 = ft_pchar('');
    printf("\t%i", cc2);
    int oo2 = printf("%c", '');
    printf("\t%i", oo2);
    printf("\n"); */

/*     printf("Prueba CHAR warning: multi-character character constant [-Wmultichar] \n");
    int cc3 = ft_pchar('ñ');
    printf("\t%i", cc3);
    int oo3 = printf("%c", 'ñ');
    printf("\t%i", oo3);
    printf("\n"); */

    printf("04 Prueba CHAR no imprimible \n");
    int cc4 = ft_pchar('\n');
    printf("\t%i", cc4);
    int oo4 = printf("%c", '\n');
    printf("\t%i", oo4);
    printf("\n");

    printf("05 Prueba CHAR ASCII no imprimible \n");
    int cc5 = ft_pchar('\0');
    printf("\t%i", cc5);
    int oo5 = printf("%c", '\0');
    printf("\t%i", oo5);
    printf("\n");

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

    printf("Prueba de Flags \n");
    int wf3 = ft_pchain("%%c");
    printf("\t%i", wf3);
    int f3 = printf("%%c");
    printf("\t%i", f3);
    printf("\n");
/** spurious trailing ‘%’ in format [-Wformat=] int f3 = printf("%%%%%");*/
  
    return (0);
}
