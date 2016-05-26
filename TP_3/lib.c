#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"claretlib.h"
#include"lib.h"

/**
*
*\brief Inicializa el flag de estado de la estructura para saber si el lugar esta vacio o no.
*\param person array a inicializar con valor 1 en campo estado.
*\param Recibe el largo de la array de estructuras.
*\return Si se pudo realizar devuelve 0 si no -1.
*/
int initializeStruct(EMovie* movie,int cant )
{
    int i;
    int retorno=-1;
    if(movie!=NULL&&cant>0)
    {
        for (i=0; i<cant; i++)
        {
            (movie+i)->isEmpty =1;
            retorno=0;
            //printf("Movie nª %d isEmpty=%d",i,(movie+i)->isEmpty);

        }
    }
    return retorno;
}


/**
*\brief Busca un lugar vacio en uan arrays de estructuras con  el valor que se le pase
*\param EAvion* struc Array de estructura donde buscar
*\param int cant Tamaño del array
*\param int value Valor a buscar
*\param int printFull Parametro que se debe pasar en 1 si queremos que imprima cartel de esta lleno u otro valor si no
*\return indice de lugar vacio si todo OK y -1 si algo salio mal
*/
int findEmpty(EMovie* struc,int cant, int value,int printFull)
{
    int i;
    int retorno=-1;
    if(struc!=NULL && cant>0)
    {
        for (i=0; i<cant; i++)
        {
            if(struc[i].isEmpty==value)
            {
                retorno=i;
                break;
            }
        }
        if (retorno==-1 && printFull==1)
            printf("No hay lugar");
    }
    return retorno;

}

/**
*
*\brief imprime el menu y captura la opcion.
*\param VOID
*\return Si se pudo realizar devuelve 0 si no -1.
*/
int mainMenu(void)
{
    int retorno=-1;

    getInt(&retorno,"-_-_-_-_-_MENU-_-_-_-_-_\n1-Agregar pelicula\n2-Borrar pelicula\n3-Modificar pelicula\n4-Generar pagina web\n5-salir\nopcion: ",
           "Error opcion no valida\n",1,5);
    return retorno;
}

/**
*
*\brief Agrega una nueva pelicula a la videoteca
*\param movie recibe un puntero a una array de estructuras
*\param cant Tamaño del array
*\return Si se pudo realizar devuelve 0 si no -1.
*/
int addMovie(EMovie* movie,int cant)
{
    int retorno=-1;
    int indice;
    char auxChar[4096];

    if(movie!=NULL&&cant>0)
    {
        indice=findEmpty(movie,cant,1,1);
        if(indice!=-1&&getString(auxChar,"Ingrese el titulo de la pelicula:",1,4095)!=-1)
        {
            if( checkByString(movie,cant,auxChar)==-1||(checkByString(movie,cant,auxChar)!=-1&&movie[checkByString(movie,cant,auxChar)].isEmpty==1))
            {
                if(getString(movie[indice].genre,"Genero:",4,16)!=-1&&
                        getInt(&movie[indice].duration,"Duracion:","Error no puede poner tiempo negativos",0,10000)!=-1&&
                        getString(movie[indice].description,"Descripcion:",0,4096)!=-1&&
                        getInt(&movie[indice].score,"Puntaje:","Solo de 1 a 10",1,10)!=-1&&
                        getString(movie[indice].link,"Link imagen:",10,150)!=-1)
                {
                    movie[indice].isEmpty=0;
                    retorno=0;
                    printf("Carga OK\n");
                    strcpy(movie[indice].title,auxChar);
                }
            }
            else
            {
                printf("Pelicula ya cargada\n");
                getchar();
            }
        }
    }
    return retorno;
}

/**
*\brief Muestar la informacion de una pelicula
*\param Recibe una estructura para mostrar
*\return void
*/
void showMovie(EMovie movie)
{
    printf("Title:%s\nGenero:%s\nDuracion:%d\nDescripcion:%s\nPuntaje:%d\nLink imagen:%s\n\n\n",movie.title,movie.genre,movie.duration,movie.description,movie.score,movie.link);
}

/**
*\brief Muestar la informacion de una pelicula
*\param movie Recibe una array de estructuras para mostrar
*\param cant tamaño de la array
*\return void
*/
void showMovies(EMovie* movie,int cant)
{
    int i;

    if(movie!=NULL&&cant>0)
    {

        for(i=0; i<cant; i++)
        {
            if(movie[i].isEmpty==0)
                showMovie(movie[i]);
        }
        getchar();
    }
}

/**
*\brief Busca si una cadena existe en una arrays de estructuras con  el valor que se le pase
*\param EArray* struc Array de estructura donde buscar
*\param int cant Tamaño del array
*\param ichar* strToCheck string a buscar
*\return indice de lugar  si todo OK y -1 si algo salio mal
*/
int checkByString(EMovie* struc,int cant,char* strToCheck )
{
    int i;
    int retorno=-1;
    if(struc!=NULL && cant>0)
    {
        for (i=0; i<cant; i++)
        {
            if(struc[i].isEmpty==0)
            {
                if(strcmp(struc[i].title,strToCheck)==0 )
                {
                    retorno=i;
                    break;
                }
            }
        }
    }
    return retorno;
}

/**
*\brief Hace un borrado logico de un item a travès de un campo *Char
*\param * struc, puntero a array de estructuras donde se va a cargar el nuevo ITEM
*\param int cant, Tamaño de la array
*\param char* strToDel Cadena que se utilizara para buscar el item a borrar
*\return
*/
int deletItemString(EMovie* struc,int cant)
{
    int retorno=-1;
    int indexToDelete;
    char strToDel[50];
    getString(strToDel,"Ingrese el titulo de la pelicula a borrar: ",1,50);
    firstUpperString(strToDel,strlen(strToDel));
    if(struc!=NULL&& cant >0)
    {
        indexToDelete=checkByString(struc,cant,strToDel);
        if(indexToDelete!=-1&&struc[indexToDelete].isEmpty==0)
        {
            struc[indexToDelete].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

/**
*\brief Convierte en mayuscula la primera letra de cada title incluyendo title compuestos.
*\param movie array a utilizar
*\param Largo del array
*\return Devuelve 0 si termino OK o -1 si no pudo realizar la tarea.
*/
int firstUpper(EMovie* movie, int cant)
{
    int i;
    int j;
    int retorno = -1;

    if(movie != NULL && cant > 0 )
    {
        for (i=0; i<cant; i++)
        {
            for(j=0; j<strlen(movie[i].title); j++)
            {
                if(0 == j )
                {
                    movie[i].title[j]=toupper(movie[i].title[j]);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

/**
*\brief Genera un archivo html con la videoteca.
*\param movie array a utilizar
*\param Largo del array
*\return Devuelve 0 si termino OK o -1 si no pudo realizar la tarea.
*/
int createHtml(EMovie* movies,int cant)
{
    FILE* html;
    html=fopen("Movies.html","w");
    int i;
    int retorno=-1;

    if(html!=NULL)
    {
        fprintf(html,"\n<!DOCTYPE html>");
        fprintf(html,"\n<!-- Template by Quackit.com -->");
        fprintf(html,"\n<html lang='en'>");
        fprintf(html,"\n<head>");
        fprintf(html,"\n    <meta charset='utf-8'>");
        fprintf(html,"\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>");
        fprintf(html,"\n    <meta name='viewport' content='width=device-width, initial-scale=1'>");
        fprintf(html,"\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->");
        fprintf(html,"\n    <title>Lista peliculas</title>");
        fprintf(html,"\n    <!-- Bootstrap Core CSS -->");
        fprintf(html,"\n    <link href='css/bootstrap.min.css' rel='stylesheet'>");
        fprintf(html,"\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->");
        fprintf(html,"\n    <link href='css/custom.css' rel='stylesheet'>");
        fprintf(html,"\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->");
        fprintf(html,"\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->");
        fprintf(html,"\n    <!--[if lt IE 9]>");
        fprintf(html,"\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>");
        fprintf(html,"\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>");
        fprintf(html,"\n    <![endif]-->");
        fprintf(html,"\n</head>");
        fprintf(html,"\n<body>");
        fprintf(html,"\n    <div class='container'>");
        fprintf(html,"\n        <div class='row'>");
        for(i=0; i<cant; i++)
        {
            if(movies[i].isEmpty==0)
            {
                fprintf(html,"\n			<!-- Repetir esto para cada pelicula -->");
                fprintf(html,"\n            <article class='col-md-4 article-intro'>");
                fprintf(html,"\n                <a href='#'>");
                fprintf(html,"\n                    <img class='img-responsive img-rounded' src='%s' alt=''>",movies[i].link);
                fprintf(html,"\n                </a>");
                fprintf(html,"\n                <h3>");
                fprintf(html,"\n                    <a href='#'>%s</a>",movies[i].title);
                fprintf(html,"\n                </h3>");
                fprintf(html,"\n				<ul>");
                fprintf(html,"\n					<li>Género:%s</li>",movies[i].genre);
                fprintf(html,"\n					<li>Puntaje:%d</li>",movies[i].score);
                fprintf(html,"\n					<li>Duración:%d</li>	",movies[i].duration);
                fprintf(html,"\n				</ul>");
                fprintf(html,"\n                <p>%s</p>",movies[i].description);
                fprintf(html," \n          </article>");
                fprintf(html,"	\n		<!-- Repetir esto para cada pelicula -->");
            }
        }
        fprintf(html,"    </div>");
        fprintf(html,"        <!-- /.row -->");
        fprintf(html,"    </div>");
        fprintf(html,"    <!-- /.container -->");
        fprintf(html,"    <!-- jQuery -->");
        fprintf(html,"    <script src='js/jquery-1.11.3.min.js'></script>");
        fprintf(html,"    <!-- Bootstrap Core JavaScript -->");
        fprintf(html,"    <script src='js/bootstrap.min.js'></script>");
        fprintf(html,"	<!-- IE10 viewport bug workaround -->");
        fprintf(html,"	<script src='js/ie10-viewport-bug-workaround.js'></script>");
        fprintf(html,"	<!-- Placeholder Images -->");
        fprintf(html,"	<script src='js/holder.min.js'></script>");
        fprintf(html,"</body>");
        fprintf(html,"</html>");
        retorno=0;
    }
    fclose(html);
    return retorno;
}

/**
*\brief Genera un archivo .dat guardando fubcionando como base de datos para luego ser recuperada
*\param movie array a utilizar
*\param Largo del array
*\return Devuelve 0 si termino OK o -1 si no pudo realizar la tarea.
*/
int saveToFile(EMovie *movies,int cant)
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
    fwrite(movies,sizeof(EMovie),cant,bin);
    retorno=0;
    fclose(bin);
    printf("Guardado OK\n");
    return retorno;
}

/**
*\brief carga un archivo .dat guardando el cual es usado  como base de datos para ser recuperada la informacion
*\param movie array a utilizar
*\param Largo del array
*\return Devuelve 0 si termino OK o -1 si no pudo realizar la tarea.
*/
int loadFile(EMovie* movies,int cant)
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
        if (fread(movies,sizeof(EMovie),cant,bin))
        {
            retorno=0;
            fclose(bin);
        }
    }
    return retorno;
}

/**
*\brief busca una pelicula por nombre para modificarla
*\param movie array a utilizar
*\param Largo del array
*\return -1 si fallo algo 0=OK.
*/
int modifyMovie(EMovie* movie,int cant)
{
    int retorno=-1;
    int option;
    int indexTochange;
    char auxChar[50];

    if(movie!=NULL&& cant >0)
    {
        getString(auxChar,"Ingrese el titulo a modificar:",1,50);
        indexTochange=checkByString(movie,cant,auxChar);
        if(indexTochange!=-1)
        {
            do
            {
                getInt(&option,"^^^^^Modificaciones^^^^^^^\n1-Titulo\n2-Genero\n3-Duracion\n4-Descripcion\n5-Puntaje\n6-Imagen\n7-SALIR\nOpcion:","Opcion no valida 1-7\n",1,7);
                switch(option)
                {
                case 1:
                    printf("Titulo actual: %s\n",movie[indexTochange].title);
                    getString(movie[indexTochange].title,"Nuevo titulo:",1,50);
                    break;
                case 2:
                    printf("Genero actual: %s\n",movie[indexTochange].genre);
                    getString(movie[indexTochange].genre,"Nuevo genero:",1,16);
                    break;
                case 3:
                    printf("Duracion actual:%d\n",movie[indexTochange].duration);
                    getInt(&movie[indexTochange].duration,"Nueva duracion:","1-10000",1,10000);
                    break;
                case 4:
                    printf("Genero actual: %s\n",movie[indexTochange].genre);
                    getString(movie[indexTochange].description,"Nueva descripcion:",1,4096);
                    break;
                case 5:
                    printf("Duracion actual:%d\n",movie[indexTochange].score);
                    getInt(&movie[indexTochange].score,"Nuevo puntaje:","1-10",1,10);
                    break;
                case 6:
                    printf("Genero actual: %s\n",movie[indexTochange].link);
                    getString(movie[indexTochange].link,"Nueva Imagen(Link):",1,150);
                    break;
                }
            }
            while(option!=7);
        }
        else
        {
            printf("No esta registrada esa pelicula\n");
        }
    }
    return retorno;
}

/**
*\brief carga 3 peliculas para pruebas
*\param movie array a utilizar
*\param Largo del array
*\return void.
*/
void testcase(EMovie* movies,int cant)
{
    EMovie prueba[3]= {{"Loco por mary","Comedia",60,"Ted (Ben Stiller), un torpe y timido adolescente, tiene una cita de graduacion con la chica de sus suenios,",10,"http://www.escribiendocine.com/images/presets/600_450/3/2fe085dadb419808ab51a79b12436ad2.jpg",0},{"El padrino","Accion",120," narra la vida de Don Vito Corleone",8,"http://www.escribiendocine.com/images/presets/170x230/0/9246fb3510f38ad76412bf229513b585.jpg",0},{"Star Wars","CIFI",150,"comienza con Luke desaparecido, y el Imperio le esta dando caza. Un pequenio droide abandonado en el desierto contiene el secreto de su paradero.",7,"http://www.escribiendocine.com/images/presets/170x230/30/cb009c2f18df52160bcaac84d07a76b6.jpg",0}};
    int i;
    for (i=0; i<3; i++)
    {
        movies[i]=prueba[i];
    }
}


