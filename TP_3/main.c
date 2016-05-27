#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"claretlib.h"
#include"lib.h"
#define TAM 100
#define CLEAR "clear"
/*Título
Género
Duración
Descripción
Puntaje
Link de imagen*/

int main(void)
{
    int option;
    EMovie movies[TAM];
    initializeStruct(movies,TAM);
    loadFile(movies,TAM);
    int noMovies=1;
    //testcase(movies);
    do
    {
        system(CLEAR);
        firstUpper(movies,TAM);
        option=mainMenu();
        switch(option)
        {
        case 1:
           addMovie(movies,TAM);

            break;
        case 2:
            if(checkEmptyArray(movies,TAM)==-1)
            {
                printf("No hay peliculas registradas\n");
                getchar();
                break;
            }
            deletItemString(movies,TAM);
            getchar();
            break;
        case 3:
            if(checkEmptyArray(movies,TAM)==-1)
            {
                printf("No hay peliculas registradas\n");
                getchar();
                break;
            }
            modifyMovie(movies,TAM);
            break;

        case 4:
            if(checkEmptyArray(movies,TAM)==-1)
            {
                printf("No hay peliculas registradas\n");
                getchar();
                break;
            }
            createHtml(movies,TAM);

            //showMovies(movies,TAM);
            break;
        }
    }
    while (option!=5);
    saveToFile(movies,TAM);
    return 0;
}































