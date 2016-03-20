#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int x=0;
    int y=0;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A= %i)\n"),x;
        printf("2- Ingresar 2do operando (B= %i)\n"),y;
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el 1er operando: ");
                scanf("%d",&x);
                printf("\n\n");
                break;
            case 2:
                printf("Ingrese el 2do operando: ");
                scanf("%d",&y);
                printf("\n\n");
                break;
            case 3:
                sumar(x,y);
                printf("\n\n");
                break;
            case 4:
                restar(x,y);
                printf("\n\n");
                break;
            case 5:
                dividir(x,y);
                printf("\n\n");
                break;
            case 6:
                multiplicar(x,y);
                printf("\n\n");
                break;
            case 7:
                break;
            case 8:
                sumar(x,y);
                printf("\n\n");
                restar(x,y);
                printf("\n\n");
                multiplicar(x,y);
                printf("\n\n");
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }


    return 0;
}
