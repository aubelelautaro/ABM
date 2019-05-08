#include <stdio.h>
#include <ctype.h>
#include <conio.h>
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

char getOpcion(char mensaje[],char caracter,char minimo, char maximo)
{
    printf("%s", mensaje);
    fflush(stdin);
    caracter = getch();
    while(caracter < minimo && caracter > maximo)
    {
        printf("\nIngrese una opcion correcta entre %c y %c:",minimo,maximo);
        caracter = getch();
        fflush(stdin);
    }

    return caracter;
}

char getChar(char mensaje[],char caracter)
{
    printf("%s", mensaje);
    fflush(stdin);
    caracter = getch();

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

    for(i=0;i<strlen(str);i++)
    {
        if(!(isdigit(str[i])))
        {
            flag = 0;
            printf("Error! Ingrese solo numeros\n");
            break;
        }
    }

    return flag;
}

int esSoloLetras(char str[])
{
    int i=0;
    int flag = 1;

    for(i=0;i<strlen(str);i++)
    {
        if((str[i] != ' ') && !(isalpha(str[i])))
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int esMail(char str[])
{
    int i=0;
    int flag = 1;
    int contadorDeArrobas=0;

    for(i=0;i<strlen(str);i++)
    {
        if((str[i] != '@') && (str[i] != '.') && !(isalpha(str[i])) && !(isdigit(str[i])))
        {
            flag = 0;
            break;
        }
        if(str[i] == '@')
        {
            contadorDeArrobas++;
        }
    }
    if(contadorDeArrobas != 1)
    {
        flag = 0;
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
    int flag =0;

    for(i=0;i<strlen(str);i++)
    {
        if((str[i] != '-') && !(isdigit(str[i])))
        {
            flag = 0;
            break;
        }
        if(str[i] == '-')
        {
            contadorGuiones++;
            if(contadorGuiones ==1)
            {
                flag = 1;
            }
        }
    }
    return flag;
}

void getString(char mensaje[], char cadena[])
{
    printf(mensaje);
    fflush(stdin);
    gets(cadena);
    fflush(stdin);
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

int getStringTelefono(char mensaje[],char cadena[])
{
    char aux[256];
    int flag =0;
    getString(mensaje,aux);
    if(esTelefono(aux))
    {
        strcpy(cadena,aux);
        flag=1;
    }
    return flag;
}

int getStringMail(char mensaje[],char cadena[])
{
    char aux[256];
    int flag =0;
    getString(mensaje,aux);
    if(esMail(aux))
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
