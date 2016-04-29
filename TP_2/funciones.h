#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;



/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
//int buscarPorDni(EPersona lista[], int dni);



int firstUpper(EPersona* person, int cant);
int initializeStruct(EPersona* person,int cant );
int sortByName(EPersona person[],int cant);
int printPerson(EPersona* person,int cant);
int deletePerson(EPersona* person,int cant);

int findFree(EPersona* person,int cant);
int findDni(int dni,EPersona person[], int cant);
int cargaPersona(EPersona* person,char messageFull[],int cant);
void rangoEdades(EPersona person[],int cant);

#endif // FUNCIONES_H_INCLUDED

