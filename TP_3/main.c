#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"claretlib.h"
#include"lib.h"
#define TAM 5
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
            deletItemString(movies,TAM);
            break;
        case 3:
            modifyMovie(movies,TAM);

            break;

        case 4:
            createHtml(movies,TAM);
            //showMovies(movies,TAM);
            break;
        }
    }while (option!=5);
    saveToFile(movies,TAM);
    return 0;
}






























