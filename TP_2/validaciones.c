#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//int getInt2(int *input,char message[],char eMessage[],int lowLimit,int hiLimit)
//{
//    int retorno=-1;
//    int aux;
//    printf("%s",message);
//    if(scanf("%d",&aux)!=1)
//    {
//         printf("%s",eMessage);
//
//    }
//    else
//    {
//        if (aux >= lowLimit && aux <= hiLimit)
//        {
//            *input=aux;
//            retorno = 0;
//        }
//        else
//        {
//            printf("%s",eMessage);
//        }
//    }
//    return retorno;
//}







int getFloat(float *input,char message[],char eMessage[],float lowLimit,float hiLimit)
{
    int retorno=-1;
    float aux;
    printf("%s",message);
    if(scanf("%f",&aux)!=1)
    {
         printf("%s",eMessage);

    }
    else
    {
        if (aux >= lowLimit && aux <= hiLimit)
        {
            *input=aux;
            retorno = 0;
        }
        else
        {
            printf("%s",eMessage);
        }


    }

    return retorno;

}


int getChar(char *input,char message[],char eMessage[],char lowLimit,char hiLimit)
{
    int retorno=-1;
    char aux;
    printf("%s",message);
    if(scanf("%c",&aux)!=1)
    {
         printf("%s",eMessage);

    }
    else
    {
        if (aux >= lowLimit && aux <= hiLimit)
        {
            *input=aux;
            retorno = 0;
        }
        else
        {
            printf("%s",eMessage);
        }


    }

    return retorno;

}


int getString(char input[],char message[],char eMessage[],int lowLimit,int hiLimit)
{
    int retorno=-1;
    char aux[4096];
    printf("%s",message);
    setbuf(stdin,NULL);
    gets(aux);
    if (strlen(aux) >= lowLimit && strlen(aux) <= hiLimit)
    {
        strcpy(input,aux);
        retorno = 0;
    }
    else
    {
        printf("%s",eMessage);
    }
    return retorno;

}

int getInt(int* input,char message[], char errorMessage[],int lowLimitRange,int hiLimitRange)
{
    char aux[4096];
    int retorno=-1;
    int intAux;

    printf("%s", message);
    setbuf(stdin,NULL);
    gets(aux);

    if ( strcmp(aux,"0\0")==0)
    {
        intAux = atoi(aux);
        retorno = 0;
        *input = intAux;

    }
    else
    {
        intAux = atoi(aux);
        if(intAux != 0)
        {
            if(intAux > lowLimitRange && intAux < hiLimitRange )
            {
                retorno = 0;
                *input = intAux;
            }
            else
            {
                printf("%s", errorMessage);
            }
        }
        else
        {
            printf("%s", errorMessage);
        }

    }



    return retorno;

}

