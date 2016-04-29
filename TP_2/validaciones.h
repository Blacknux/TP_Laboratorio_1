#ifndef SCANFETA_H_INCLUDED
#define SCANFETA_H_INCLUDED
int getInt(int* input,char message[], char errorMessage[],int lowLimitRange,int hiLimitRange);
int getFloat(float *input,char message[],char eMessage[],float lowLimit,float hiLimit);
int getChar(char *input,char message[],char eMessage[],char lowLimit,char hiLimit);
int getString(char input[],char message[],char eMessage[],int lowLimit,int hiLimit);
#endif // SCANFETA_H_INCLUDED
