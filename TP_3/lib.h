#ifndef __EMOVIE
#define __EMOVIE
typedef struct
{
    char title[50];
    char genre[16];
    int duration;
    char description[4096];
    int score;
    char link[150];
    int isEmpty;

} EMovie;
#endif // __EMOVIE

#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
int initializeStruct(EMovie* movie,int cant );
int findEmpty(EMovie* struc,int cant, int value,int printFull);
int mainMenu(void);
int addMovie(EMovie* movie,int cant);
void showMovie(EMovie movie);
void showMovies(EMovie* movie,int cant);
int checkByString(EMovie* struc,int cant,char* strToCheck );
int deletItemString(EMovie* struc,int cant);
int firstUpper(EMovie* movie, int cant);
int createHtml(EMovie* movies,int cant);
int saveToFile(EMovie *movies,int cant);
int loadFile(EMovie* movies,int cant);
int modifyMovie(EMovie* movie,int cant);
void testcase(EMovie* movies,int cant);



#endif // LIB_H_INCLUDED
