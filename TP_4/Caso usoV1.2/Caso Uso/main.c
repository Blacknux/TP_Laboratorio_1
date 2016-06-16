#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "claretlib.h"
#include "ArrayList.h"
#include "Employee.h"



eEmployee* loadEmployee(int id);


int main()
{
    ArrayList* arrayListC=al_newArrayList();
    ArrayList* DeleteHistory=al_newArrayList();
    ArrayList* Backup=al_newArrayList();
    int id=0;
    int option;
    char continueDo='s';
    loadCant(arrayListC);
//    loadFile(arrayListC,arrayListC->size);

    loader(arrayListC);
    do
    {
        getInt(&option,"######CASO DE USO ARRAYLIST###\n\n1-Agregar un empleado\n2-Print Lista de empleados\n3-Eliminar empleado"
               "\n4-Ver empleados borrados\n5-Backup Nomina\n6-Mostrar Empleados acomodados por sueldo"
               "\n10-Salir\noption:","Opcion no valida\n",1,10);
        switch(option)
        {
        case 1:
            id++;
            al_add(arrayListC,(void*)loadEmployee(id));

//           acomodarIndices(arrayListC);


            break;
        case 2:
            PrintEmployees(arrayListC);
            break;
        case 3:
            deleteEmployee(arrayListC,DeleteHistory);

//        acomodarIndices(arrayListC);
            break;
        case 4:
            printf("\n\n@@@@@@@@ HISTORIAL @@@@@@@\n\n");
            PrintEmployees(DeleteHistory);
//           acomodarIndices(arrayListC);

            break;
        case 5:
            do
            {
                getInt(&option,"1-Backup Nomina\n2-Restore Ultimo Backup\n3-Salir\nOpcion:","opcion no valida",1,3);
                switch(option)
                {
                case 1:
//                    BackupNomina(arrayListC,Backup,0);
                    break;
                case 2:
//                    BackupNomina(arrayListC,Backup,1);
                    break;
                default:
                    break;

                }

            }
            while(option!=3);
//        insertEmployee(arrayListC,&id);
            break;
                case 6:
                    mostrarEmpPorSueldo(arrayListC);
                    break;



        case 10:
            continueDo='n';
            break;
        default:
            break;
        }


    }
    while(continueDo!='n');
    saveCant(arrayListC);
    //saveToFile(arrayListC,arrayListC->size);

    return 0;
}

eEmployee* newEmployee(int id, char name[],char lastName[],float salary)
{
    eEmployee* returnAux = NULL;
    eEmployee* pEmployee = malloc(sizeof(eEmployee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
    }

    return returnAux;

}


eEmployee* loadEmployee(int id)
{
    eEmployee* returnAux=NULL;
    char name[20];
    char lastName[20];
    float salary;
//    int a=*(id);

    if(getString(name,"Ingrese el nombre:",1,20)!=-1&&getString(lastName,"Ingrese apellido: ",1,20)!=-1)
    {
        printf("Ingrese el sueldo: ");
        scanf("%f",&salary);
        returnAux=newEmployee(id,name,lastName,salary);

    }
    return returnAux;

}

void printEmployee(eEmployee* employee)
{
    printf("\nNumero de empleado:%d\nNombre:%s\nApellido:%s\nSueldo:%2.f\n\n\n",employee->id,employee->name,employee->lastName,employee->salary);
}

void PrintEmployees(ArrayList* list)
{
    int i;
    for(i=0; i<list->size; i++)
    {
        printEmployee(*((list->pElements)+i));
    }
}

int deleteEmployee(ArrayList* pList,ArrayList* historyDel)
{
    int option;
    char continueDo='s';
    int indexAux;
    eEmployee* mostrar=NULL;
    system("cls");

    getInt(&indexAux,"ingrese el legajo del usuario a eliminar","Error usuario no existente",0,pList->size);
    mostrar=(eEmployee*)pList->pop(pList,indexAux-1);
    al_add(historyDel,((void*) mostrar));
    printf("Usuario eliminado");
//            printEmployee(mostrar);

    system("pause");


}

//void acomodarIndices(ArrayList* pList)
//{
//    int i;
//    eEmployee* aux;
//    for (i=0;i<pList->size;i++)
//        {
//            aux=*((pList->pElements)+i);
//            aux->id=i+1;
//        }
//}


//int compareEmployee(void* pEmployeeA,void* pEmployeeB)
//{
//
//    if(((eEmployee*)pEmployeeA)->salary > ((eEmployee*)pEmployeeB)->salary)
//    {
//        return 1;
//    }
//    if(((eEmployee*)pEmployeeA)->salary < ((eEmployee*)pEmployeeB)->salary)
//    {
//        return -1;
//    }
//    return 0;
//
//
//}

//void insertEmployee(ArrayList* pList,int* id)
//{
//    int indexAux;
//
//    getInt(&indexAux,"Ingrese el id con el que quiere forzar el ingreso del empleado: ","Error",0,pList->size);
//    pList->push(pList,indexAux-1,loadEmployee(&id));
//
//
//}

void loader(ArrayList* pList)
{
    pList->add(pList,newEmployee(1,"nahuel","Claret",234.5));
    pList->add(pList,newEmployee(2,"Sheldom","Cooper",2342.5));
    pList->add(pList,newEmployee(3,"Barney","Stinson",23442.5));
    pList->add(pList,newEmployee(4,"Pedro","Picapiedra",24342.5));

}

//int BackupNomina(ArrayList* origen, ArrayList* destino)
//{
//    int returnAux=-1;
//
//    if(origen!=NULL && destino!=NULL&& )
//    {
//
//        destino=origen->clone(origen);
//        printf("Se realizo el backup de la nomina: \n");
//        PrintEmployees(destino);
//        break;
//        returnAux=0;
//    }
//    return returnAux;
//
//}


int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((eEmployee*)pEmployeeA)->salary > ((eEmployee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((eEmployee*)pEmployeeA)->salary < ((eEmployee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;
}

void mostrarEmpPorSueldo(ArrayList* pList)
{
    ArrayList* aux=pList->clone(pList);
    aux->sort((void*)aux,compareEmployee,0);
    PrintEmployees(aux);
    free(aux);


}

int loadFile(ArrayList* pList,int cant)
{
    FILE* bin;
    int retorno=-1;
    bin=fopen("bin.dat","rb");
    if(bin==NULL)
    {
        printf("Error en la apertura del archivo\nPresione una tecla para continuar....\n");
        getchar();
    }
    else
    {
        if (fread(pList,sizeof(pList),cant,bin))
        {
            retorno=0;
            fclose(bin);
        }
    }
    return retorno;
}

int saveToFile(ArrayList *pList,int cant)
{
    FILE* bin;
    int retorno=-1;
    bin=fopen("bin.dat","r+b");
    if(bin==NULL)
    {
        bin=fopen("bin.dat","wb");
        if(bin==NULL)
        {
            exit(1);
        }
    }
    fwrite(pList,sizeof(ArrayList),cant,bin);
    retorno=0;
    fclose(bin);
    printf("Guardado OK\n");
    return retorno;
}

int saveCant(ArrayList* pList)
{
    FILE* txt=fopen("Cantidad","w");
    int retorno = -1;
    if(txt!=NULL)
    {

        fprintf(txt,"%d",pList->size);
         retorno=0;
    }
   fclose(txt);
   return retorno;
}

int loadCant(ArrayList* pList)
{
    FILE* txt=fopen("Cantidad","r");
    int returnAux=-1;
    int aux;
    char auxiliar;
    if(txt!=NULL)
    {
        fscanf(txt,"%d",&aux);
//        aux=atoi(auxiliar);

        pList->size=aux;
         returnAux=0;
    }
   fclose(txt);
   return returnAux;

}
