#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "autores.h"
#include "libros.h"

void eAutor_init(eAutor autores[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        autores[i].codigo =0;
        strcpy(autores[i].nombre, "");
        strcpy(autores[i].apellido, "");
        autores[i].estado = 0;
    }
}

void eAutor_ordenPorApellido(eAutor autores[],int tam)
{
    int i,j;
    eAutor aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(autores[i].apellido,autores[j].apellido)>0)
            {
                aux = autores[i];
                autores[i]= autores[j];
                autores[j]= aux;
            }else if(strcmp(autores[i].apellido,autores[j].apellido) == 0)
            {
                if(strcmp(autores[i].nombre,autores[j].nombre)>0)
                {
                    aux = autores[i];
                    autores[i]= autores[j];
                    autores[j]= aux;
                }
            }
        }
    }
}

void eAutor_mostrarUno(eAutor autores, int tam)
{
    printf("%d   %s    %s\n", autores.codigo , autores.nombre , autores.apellido);
}

int eAutor_listar(eAutor autores[],int tam)
{
    int i;
    int flag = 0;
    eAutor_ordenPorApellido(autores,tam);
    printf("CODIGO   NOMBRE    APELLIDO\n");
    for(i=0;i<tam;i++)
    {
        if(autores[i].estado ==1)
        {
            eAutor_mostrarUno(autores[i],tam);
            flag = 1;
        }
    }
    if(flag ==0)
    {
        printf("NO HAY AUTORES");
    }
    return flag;
}

int eAutor_buscar(eAutor autores[], int tam,int codigo)
{
    int index = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(autores[i].codigo == codigo  && autores[i].estado ==1 )
        {
            index=i;
            break;
        }
    }

    return index;
}

int eAutor_buscarLibre(eAutor autores[],int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if (autores[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void eAutor_modificacion(eAutor autores[], int tam)
{
    int codigo;
    int index;
    int validar;
    char auxApellido[31];
    char auxNombre[31];
    int retorno = eAutor_listar(autores,tam);
    char confirma='N';
    if(retorno==0)
    {
        printf(" PARA MODIFICAR");
    }else
    {
        printf("Ingrese codigo del autor a modificar: ");
        scanf("%d",&codigo);
        index = eAutor_buscar(autores,tam,codigo);
        if(index==-1)
        {
            printf("No se encontro el autor\n");
        }else{
            do{
                switch(eAutor_menuModificacion())
                {
                case '1':
                    printf("El apellido actual es: %s\n",autores[index].apellido);
                    validar = getStringLetras("Ingrese nuevo apellido: ",auxApellido);
                    while(validar == 0)
                    {
                        validar = getStringLetras("ERROR, ingrese solo letras: ",auxApellido);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(autores[index].apellido,auxApellido);
                    }
                    system("pause");
                    break;

                case '2':
                    printf("El nombre actual es: %s\n",autores[index].nombre);
                    validar = getStringLetras("Ingrese nuevo nombre: ",auxNombre);
                    while(validar == 0)
                    {
                        validar = getStringLetras("ERROR, ingrese solo letras: ",auxNombre);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(autores[index].nombre,auxNombre);
                    }
                    system("pause");
                    break;

                case '3':
                    confirma = getChar("Seguro quiere salir? (N/S): ", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        confirma = 'N';
                    }
                    break;
                default:
                    printf("Ingrese opcion correcta \n");
                    system("pause");
                }
            }while (confirma == 'S');
        }
    }
}

void eAutor_alta(eAutor autores[], int tam)
{
    int index;
    int auxCodigo;
    int validar;
    char auxNombre[51];
    char auxApellido[51];

    index = eAutor_buscarLibre(autores,tam);

    if(index == -1)
    {
        printf("\nNo hay autores disponibles\n");
    }
    else
    {
        auxCodigo= eAutor_siguienteId(autores,tam);
        printf("Codigo de autor: %d\n",auxCodigo);

        validar = getStringLetras("Ingrese nombre: ",auxNombre);
        while(validar == 0)
        {
            validar = getStringLetras("ERROR, ingrese solo letras: ",auxNombre);
        }
        validar = getStringLetras("Ingrese apellido: ",auxApellido);
        while(validar == 0)
        {
            validar = getStringLetras("ERROR, ingrese solo letras: ",auxApellido);
        }
        autores[index].codigo = auxCodigo;
        strcpy(autores[index].nombre,auxNombre);
        strcpy(autores[index].apellido,auxApellido);
        autores[index].estado = 1;
        printf("Alta de autor exitosa.\nCodigo: %d  Nombre: %s Apellido: %s\n",auxCodigo,autores[index].nombre,autores[index].apellido);
        auxCodigo++;
    }
}

int eAutor_menuModificacion()
{
    char opcion = '0';

    printf("\n----Modificacion----\n");
    printf("1.Apellido\n");
    printf("2.Nombre\n");
    printf("3.Cancelar\n");

    opcion = getOpcion("\nIngrese opcion entre 1 y 3: ", opcion,'1','3');
    return opcion;
}

void eAutor_baja(eAutor autores[], int tam)
{
    int index;
    int codigo;
    char confirma;
    int retorno = eAutor_listar(autores,tam);
    if(retorno==0)
    {
        printf(" PARA DAR DE BAJA\n");
    }
    else
    {
        printf("Ingrese codigo: ");
        scanf("%d", &codigo);
        index = eAutor_buscar(autores,tam,codigo);

        if(index== -1)
        {
            printf("No se encontro al autor\n");
        }
        else
        {
            confirma = getChar("Desea dar de baja el autor? (S/N): ", confirma);
            confirma = toupper(confirma);
            while((confirma!= 'S') && (confirma!= 'N'))
            {
                confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                confirma = toupper(confirma);
            }
            if(confirma=='S')
            {
                autores[index].estado = 0;
                printf("Baja exitosa!\n");
            }
            else
            {
                printf("No se dio de baja al autor.\n");
            }
        }
    }
}
int menuAutores()
{
    char opcion = '.';

    printf("\n----MENU AUTORES----\n");
    printf("A.Alta\n");
    printf("B.Modificar\n");
    printf("C.Baja\n");
    printf("D.Listar autores\n");
    printf("E.Salir\n");

    opcion=getChar("Elija una opcion: \n",opcion);
    opcion = toupper(opcion);
    return opcion;
}

int eAutor_siguienteId(eAutor autores[],int tam)
{
    int retorno = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(autores[i].codigo>retorno)
        {
            retorno=autores[i].codigo;
        }
    }
    return retorno+1;
}
