#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
*
*\brief Inicializa el flag de estado de la estructura para saber si el lugar esta vacio o no.
*\param person array a inicializar con valor 1 en campo estado.
*\param Recibe el largo de la array de estructuras.
*\return Si se pudo realizar devuelve 0 si no -1.
*/

int initializeStruct(EPersona* person,int cant )
{
    int i;
    int retorno=-1;
    if(person!=NULL&&cant>0)
    {
        for (i=0;i<cant;i++)
            {
                person[i].estado=1;
                retorno=0;

            }
    }
    return retorno;
}



/**
*\brief Ordena la array por el campo .nombre de manera alfabetica.
*\param person el array se pasa como parametro.
*\param cant Tamaño del Array.
*\return Si se pudo realizar devuelve 0 si no -1.
*/

int sortByName(EPersona person[],int cant)
{
    EPersona auxstruc;
    int i,j;
    int retorno=-1;
    firstUpper(person,cant);
    if(person!=NULL&&cant>0)
    {
        for (i=0;i<cant-1;i++)
        {
            for(j=i+1;j<cant;j++)
            {
                if(strcmp(person[i].nombre,person[j].nombre)>0)
                {
                    auxstruc=person[i];
                    person[i]=person[j];
                    person[j]=auxstruc;
                }

            }

        }
        retorno=0;
    }
    return retorno;

}


/**
*\brief busca por DNI una persona y hace un borrado logico
*\param Dato EPersona por parametro
*\param int Largo del array
*\return Devuelve 0 si termino OK o -1 si no pudo realizar la tarea.
*/


int deletePerson(EPersona* person,int cant)
{
    int i;
    int aux; // Variable auxiliar para no usar el puntero directamente
    int retorno;
    if(person!= NULL && cant>0)
    {
        getInt(&aux,"Ingrese el DNI de la persona a borrar: ","Error el rango valido es entre 10000000 y 99999999",10000000,99999999);
        for(i=0;i<cant;i++)
        {
            if (aux==person[i].dni)
            {
                person[i].estado= 1;
                break;
            }
        }
        retorno=0;
    }
    return retorno;




}


/**
*\brief Convierte en mayuscula la primera letra de cada nombre incluyendo nombre compuestos.
*\param person array a utilizar
*\param Largo del array
*\return Devuelve 0 si termino OK o -1 si no pudo realizar la tarea.
*/

int firstUpper(EPersona* person, int cant)
{
    int i;
    int j;
    int retorno = -1;


    if(person != NULL && cant > 0 )
    {
        for (i=0;i<cant;i++)
        {
            for(j=0;j<strlen(person[i].nombre);j++)
            {
                if(0 == j || person[i].nombre[j]==' ')
                {
                    person[i].nombre[j]=toupper(person[i].nombre[j]);

                }
                if(person[i].nombre[j]==' ')
                {
                    person[i].nombre[j+1]=toupper(person[i].nombre[j+1]);

                }


            }
        }
        retorno=0;
    }
    return retorno;

}


/**
 * Obtiene el primer indice libre del array.
 * \param person el array se pasa como parametro.
 * \param cant Tamaño del Array.
 * \return el primer indice disponible o -1 si la array esta llena
 */

int findFree(EPersona* person,int cant)
{
    int i;
    int retorno=-1;
    if(person!=NULL&&cant>0)
    {
        for(i=0;i<cant;i++)
        {
            if(person[i].estado==1)
            {
                retorno=i;
                break;
            }

        }
    }
    return retorno;

}

/**
*\brief Busca el dni que se pasa por parametro dentro de la array
*\param int DNI a buscar
*\param Recibe una estructura EPerson por parametro
*\param Recibe el largo del array
*\return OK = 0 , Error = -1
*/


int findDni(int dni,EPersona person[], int cant)
{
    int i;
    int retorno=-1;
//    int flag=0;

     if(person!=NULL&&cant>0)
    {
        for(i=0;i<cant;i++)
        {
            if(dni==person[i].dni)
            {
                //printf("%s\n",message);
                retorno=0;
                break;
            }


        }
    }
    return retorno;
}


/**
*
*\brief Carga una nueva persona, validando los datos ingresados
*\param Recibe estructura EPersona
*\param char [] Recibe un msj por si el array esta lleno
*\param Recibe el largo del array
*\return OK = 0 ERROR = -1
*/

int cargaPersona(EPersona* person,char messageFull[],int cant)

{

    int auxInt;
    int retorno=-1;
    int indice,indicedni;
    int flagGetStringNombre=-1;
    int flagGetintEdad=-1;
    int flagDNI;




    if(person!=NULL && cant>0 )
    {
       indice=findFree(person,cant);
       if( indice!= -1)
       {
        flagDNI=getInt(&auxInt,"Ingrese el DNI: ","DNI no valido\n",1000000,99999999);
        indicedni=findDni(auxInt,person,cant);
            if(indicedni != -1 )
            {
                if(person[indicedni].estado==1)
                {
                    person[indice].dni=auxInt;
                    flagGetStringNombre=getString(person[indice].nombre,"Ingrese el nombre: ", "Error nombre no valido debe tener menos de 49 caracteres\n",1,50);
                    flagGetintEdad=getInt(&person[indice].edad,"Ingrese la edad 1-99: ","Error edad no valida\n",1,99);

                    if(flagDNI == 0 && flagGetintEdad == 0 && flagGetStringNombre == 0)
                    {
                        person[indice].estado = 0;
                        retorno=0;
                        printf("Se realizo la carga correctamente!\n");
                    }

                }
                else
                {
                    printf("Ya esta registrado\n");
                }
            }
            else
            {
                person[indice].dni=auxInt;
                flagGetStringNombre=getString(person[indice].nombre,"Ingrese el nombre: ", "Error nombre no valido debe tener menos de 49 caracteres\n",1,50);
                flagGetintEdad=getInt(&person[indice].edad,"Ingrese la edad 1-99: ","Error edad no valida\n",1,99);

                if(flagDNI == 0 && flagGetintEdad == 0 && flagGetStringNombre == 0)
                {
                    person[indice].estado = 0;
                    retorno=0;
                    //printf(" CArga OK");

                }

            }


       }
       else
       {
        printf("Esta lleno");
       }
    }
    return retorno;


}


/**
*\brief Se realiza un grafico mostrando cuantos menores de 18 hay cuantos mayores de 35 y cuantos en el rango medio
*\param Array de la cual sacará los datos para hacer el grafico
*\param Largo del array
*\return void
*/

void rangoEdades(EPersona person[],int cant)
{
    int i,j;
    int men18=0;
    int may35=0;
    int medio=0;
    int max=20;
    char dibujo[max][3];
    int vecDibujo[3];



    for(i=0;i<cant;i++)
    {
        if(person[i].edad<=18 && person[i].estado==0)
        {
            men18++;

        }
        else if(person[i].edad<35 && person[i].edad>18 && person[i].estado==0)
        {
            medio++;

        }
        else if(person[i].edad>=35 && person[i].estado==0)
             {
                may35++;
             }

    }
    vecDibujo[0]=men18;
    vecDibujo[1]=medio;
    vecDibujo[2]=may35;



    for(j=0;j<max;j++)
    {
        for(i=0;i<3;i++)
        {
            if(vecDibujo[i]>j)
            {
                dibujo[j][i]='*';
            }
            else
            {
                dibujo[j][i]=' ';
            }
        }
    }
    for(j=max-1;j>=0;j--)
    {
        printf("%c\t  %c\t %c \n",dibujo[j][0],dibujo[j][1],dibujo[j][2]);
    }
    printf("<18\t19-35\t>35 ");

}


/**
*
*\brief imprime los valores e las personas en la array
*\param Recibe estructura EPersona para mostrar persona
*\param Recibe el largo del array
*\return OK = 0 ERROR = -1
*/

int printPerson(EPersona* person,int cant)
{
    int i;
    int retorno=-1;

    sortByName(person,cant);
    if(person!=NULL&&cant>0)
    {
        for (i=0;i<cant;i++)
        {
            if(person[i].estado==0)
            {
            printf("Nombre: %s ",person[i].nombre);
            printf(" \nEdad: %d ",person[i].edad);
            printf(" \nDNI: %d\n",person[i].dni);
            //printf("Estado: %d\n",persona[i].estado);
            }

        }
        retorno=0;
    }
    return retorno;
}



