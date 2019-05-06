#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int getInt(char mensaje[],int numero, int min, int max)
{
    int dato;

    printf("%s", mensaje);
    scanf("%d",&numero);

    dato = validarEntero(numero,min,max,mensaje);

    return dato;
}

float getFloat(char mensaje[],float numero)
{
    printf("%s", mensaje);
    scanf("%f",&numero);

    return numero;
}

char getChar(char mensaje[],char caracter)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &caracter);

    return caracter;
}

int validarEntero(int dato, int min, int max, char mensaje [])
{

    while (dato<min || dato>max)
    {
        printf("Error, reingrese numero entre %d y %d \n%s",min,max, mensaje);
        scanf("%d", &dato);
    }
    return dato;
}


int esNumerico(char str[])
{
    int i=0;
    int flag = 1;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i]>'9')
        {
            flag = 0;
        }
        i++;
    }

    return flag;
}

int esSoloLetras(char str[])
{
    int i=0;
    int flag = 1;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i]<'a' || str[i]> 'z') &&(str[i]<'A' || str[i]> 'Z'))
        {
            flag = 0;
        }
        i++;
    }

    return flag;
}

int esMail(char str[])
{
    int i=0;
    int flag = 1;

    while(str[i] != '\0')
    {
        if((str[i] != '@') && (str[i] != '.') && (str[i]<'a' || str[i]> 'z') &&(str[i]<'A' || str[i]> 'Z') && (str[i] < '0' || str[i]>'9'))
        {
            flag = 0;
        }
        i++;
    }

    return flag;

}

int esFlotante(char str[])
 {
   int i = 0;
   int flag = 1;
   int cantComas = 0;
   while(str[i] !='\0')
   {
       if (i ==0 && str[i] =='-')
       {
           i++;
           continue;
       }
       if (str[i] =='.' && cantComas ==0)
       {
           cantComas++;
           i++;
           continue;
       }
       if(str[i] <'0' || str[i] >'9')
       {
           flag = 0;
           break;
       }
       i++;
   }
   return flag;
}

int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    int flag =1;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i]>'9'))
        {
            flag = 0;
        }
        if(str[i] == '-')
        {
            contadorGuiones++;
        }
        i++;
    }

    return flag;
}

void getString(char mensaje[], char cadena[])
{
    printf(mensaje);
    scanf("%s",cadena);
}

int getStringLetras(char mensaje[],char cadena[])
{
    char aux[256];
    int flag =0;
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(cadena,aux);
        flag=1;
    }
    return flag;
}

int getStringNumeros(char mensaje[],char cadena[])
{
    char aux[256];
    int flag =0;
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(cadena,aux);
        flag=1;
    }
    return flag;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    int flag = 0;
    getString(mensaje,aux);
    if(esFlotante(aux))
    {
        strcpy(input,aux);
        flag = 1;
    }
    return flag;
}
