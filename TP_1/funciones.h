#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void menu (void);
void sum(int x, int y, int flag1,int flag2);
int validarUnNumero(void);
void banner(void);
void sum(int x, int y, int flag1,int flag2);
void substraction(int x, int y,int flag1,int flag2);
void division(int x, int y,int flag1,int flag2);
void multiplication(int x, int y,int flag1,int flag2);
long long int factorial( long long int opera,int flag);

#endif // FUNCIONES_H_INCLUDED










/**
*
*\brief Imprime el menu y ejecuta el switch que llama a las funciones.
*
*/

void menu (void)
{

        char continuee='s'; // opcion de corte en switch case 9
        int option; // variable que almacena loq ue viene de menu()
        int operating1; //var para guardar operando 1
        int operating2;//var ara guardar operando 2
        int flag1=0; //Bandera que indica si se cargo operando 1
        int flag2=0; //Bandera que indica si se cargo operando 2
        long long int fact,operating1b;

    banner();

    do
    {
//        if (!flag1 && !flag2)
//        {
//
//        printf("1- Ingresar 1er operando (A= No definido)\n");
//        printf("2- Ingresar 2do operando (B= No definido)\n");
//
//
//        }
//        else
//        {
            if (!flag1)
            {
                printf("1- Ingresar 1er operando (A= No definido)\n");
                //printf("2- Ingresar 2do operando (B= %d)\n",operating2);

            }
            else
            {
                printf("1- Ingresar 1er operando (A= %d)\n",operating1);

            }
            if (!flag2)
                {

                    printf("2- Ingresar 2do operando (B= No definido)\n");

                  }
                else
                {

                    printf("2- Ingresar 2do operando (B= %d)\n",operating2);

                }
           // }

       // }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");




        option=validarUnNumero();





        switch(option)
        {
            case 1:

                printf("Ingrese el primer operando: ");
                operating1=validarUnNumero();
                printf("\n");
                flag1=1;

            break;
            case 2:

                printf("Ingrese el segundo operando: ");
                operating2=validarUnNumero();
                printf("\n");
                flag2=1;
                break;
            case 3:
               sum(operating1,operating2,flag1,flag2);
                break;
            case 4:
                substraction(operating1,operating2,flag1,flag2);
                break;
            case 5:
                division(operating1,operating2,flag1,flag2);
                break;
            case 6:
                multiplication(operating1,operating2,flag1,flag2);
                break;
            case 7:
                operating1b=operating1;

                if (!flag1 || operating1<=0)
                {
                    printf("Debe ingresar el primer operando para poder sacar el factorial\n");
                    printf("Debe ser distinto de 0\n");
                }
                else
                {
                    fact=factorial(operating1b,flag1);

                    printf("Es: %lld\n\n",fact);
                }
                break;
            case 8:
//
               sum(operating1,operating2,flag1,flag2);
               substraction(operating1,operating2,flag1,flag2);
               division(operating1,operating2,flag1,flag2);
               multiplication(operating1,operating2,flag1,flag2);
               operating1b=operating1;

                if (!flag1 || operating1<=0)
                {
                    printf("No se puede sacar factorial de %d \n",operating1);
                }

                else
                {
                    fact=factorial(operating1b,flag1);

                    printf("El factorial de %d es: %lld\n\n",operating1,fact);
                }
                break;
            case 9:
                printf("Bye");
                continuee = 'n';
                break;
            default:

            printf("Error seleccione una opción valida\n\n");
            break;


        }



    }while(continuee=='s');

}



/**
*
*\brief Valida que se ingrese un numero y no una letra
*
*\return En caso de que se haya ingresado un numero devuelve un entero
*
*/

int validarUnNumero(void)
{
    int numero;  //printf("Ingrese un numero: ")
    while(scanf("%d", &numero)!= 1)
    {
        setbuf(stdin, NULL);
        printf("Ingrese un numero: ");

    }
    return numero;
}



/**
*\brief Realiza la suma de dos enteros pasados por parametros y valida que ambos
*       esten definidos.
*\param Recibe un dato del tipo int primer numero (y)
*\param Recibe un dato del tipo int Segundo numero(x)
*\param int indica si el primer numero se cargo con un flag
*\param int indica si el segundo operando se cargo con un flag
*/

void sum(int x, int y, int flag1,int flag2)
{
     int sumxy;
if (flag1 == 1 && flag2 == 1)
   {
       sumxy = x + y;
        printf("\nEl resultado de la suma de %d y %d es: %d\n\n", x, y, sumxy);
  //  printf("El resultado de la suma de %d y %d es: %d\n",x,y,suma);

    }
    else
    {
        if (!flag1)
        {
            printf("Falta definir el primer operando\n");

        }
        if (!flag2)
        {
            printf("Falta definir el segundo operando\n");

        }


    }




}




/**
*\brief Realiza la resta de dos enteros pasados por parametros y valida que ambos
*       esten definidos.
*\param Recibe un dato del tipo int primer numero (y)
*\param Recibe un dato del tipo int Segundo numero(x)
*\param int indica si el primer numero se cargo con un flag
*\param int indica si el segundo operando se cargo con un flag
*/
void substraction(int x, int y,int flag1,int flag2)
{
     int substractionxy;

   if (flag1 == 1 && flag2 == 1)
   {
        substractionxy = x - y;
        printf("\nEl resultado de la resta de %d y %d es: %d\n\n", x, y, substractionxy);
  //  printf("El resultado de la suma de %d y %d es: %d\n",x,y,suma);

    }
    else
    {
        if (!flag1)
        {
            printf("Falta definir el primer operando\n");

        }
        if (!flag2)
        {
            printf("Falta definir el segundo operando\n");

        }


    }


}





/**
*\brief Realiza la división de dos enteros pasados por parametros, validando que el segundo no sea 0 y valida que ambos
*       esten definidos.
*\param Recibe un dato del tipo int primer numero (y)
*\param Recibe un dato del tipo int Segundo numero(x)
*\param int indica si el primer numero se cargo con un flag
*\param int indica si el segundo operando se cargo con un flag
*
*/

void division(int x, int y,int flag1,int flag2)
{
     float divisionxy;

   if (flag1 == 1 && flag2 == 1)
   {
        if (0 == y)
        {
            printf("División por 0 no definida\n\n");
        }
        else
       {
            divisionxy = (float) x / y;
            printf("\nEl resultado de la división de %d y %d es: %.2f\n\n", x, y, divisionxy);
        }
    }
    else
    {
        if (!flag1)
        {
            printf("Falta definir el primer operando\n");

        }
        if (!flag2)
        {
            printf("Falta definir el segundo operando\n");

        }


    }


}

/**
*\brief Realiza la multiplicacion de dos numeros pasados por parametros y valida que ambos
*       esten definidos.
*\param Recibe un dato del tipo int primer numero (y)
*\param Recibe un dato del tipo int Segundo numero(x)
*\param int indica si el primer numero se cargo con un flag
*\param int indica si el segundo operando se cargo con un flag
*/

void multiplication(int x, int y,int flag1,int flag2)
{
        int multiplicationxy;

   if (flag1 == 1 && flag2 == 1)
   {
         multiplicationxy = x * y;
            printf("\nEl resultado de la multiplicación de %d y %d es: %d\n\n", x, y, multiplicationxy);
  //  printf("El resultado de la suma de %d y %d es: %d\n",x,y,suma);

    }
    else
    {
        if (!flag1)
        {
            printf("Falta definir el primer operando\n");

        }
        if (!flag2)
        {
            printf("Falta definir el segundo operando\n");

        }


    }











}

/**
*
*\brief calcula el factorial de un entero pasado por parametro e informa el
*       resultado, Valida que el .
*
*\param Recibe un dato de tipo long long int (Numero a factorear)
*\param Recibe un int que se usa como flag para ver si se ingreso el operando necesario
*
*\return Retorna un dato ong long int (producto del factorial del numero ingresado)
*
*/

 long long int factorial( long long int aux,int flag)
{



            if (aux==1)
            {

                return 1;
            }
            aux =aux*factorial(aux-1,flag);




        return aux;

}

/**
*
*\brief Muestra el dibujo de una calculadora con los dates del autor
*
*/


void banner(void)
{
    printf(""" """

  """\n _____________________ \n"""
	"""|  _________________  |\n"""
    """| | NC           0. | |\n"""
    """| |_________________| |\n"""
    """|  ___ ___ ___   ___  |\n"""
    """| | 7 | 8 | 9 | | + | |\n"""
    """| |___|___|___| |___| |\n"""
    """| | 4 | 5 | 6 | | - | |\n"""
    """| |___|___|___| |___| |\n"""
    """| | 1 | 2 | 3 | | x | |\n"""
    """| |___|___|___| |___| |\n"""
    """| | . | 0 | = | | / | |\n"""
    """| |___|___|___| |___| |\n"""
    """|_____________________|\n"""
    """|Autor: Nahuel Claret |\n"""
    """|_____________________|\n"""
    """Presione una tecla para continuar"""


    );
    getchar();
    //system("clear");
    setbuf(stdout,NULL);

}

