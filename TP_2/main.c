#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "validaciones.h"

#define TAM 3





int main()
{
    char seguir='s';
    int opcion=0;
    EPersona persona[TAM];



    initializeStruct(persona,TAM);




    do
    {
        printf("\n\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                cargaPersona(persona,"No hay mas lugar",TAM);

                break;
            case 2:
                deletePerson(persona,TAM);


                break;
            case 3:

                printPerson(persona,TAM);

                break;
            case 4:
                rangoEdades(persona,TAM);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Opcion no valida!!\n");
                break;

        }
    }while(seguir=='s');

    return 0;
}






// PASAR Y NO TOCAR













