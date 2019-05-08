#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "libros.h"
#include "autores.h"

void eLibro_init(eLibro libros[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        libros[i].codigo = 0;
        strcpy(libros[i].titulo, "");
        libros[i].codigoAutor = 0;
        libros[i].estado = 0;
    }
}


void eLibro_ordenPorTitulo(eLibro libros[],int tam)
{
    int i,j;
    eLibro aux;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(libros[i].titulo,libros[j].titulo)>0)
            {
                aux = libros[i];
                libros[i]= libros[j];
                libros[j]= aux;
            }
        }
    }
}

int eLibro_listar(eLibro libros[], int tam)
{
    int i;
    int flag= 0;
    eLibro_ordenPorTitulo(libros,tam);
    printf("CODIGO   TITULO     CODIGO DE AUTOR\n");
    for(i=0;i<tam;i++)
    {
        if(libros[i].estado == 1)
        {
            eLibro_mostrarUno(libros[i],tam);
            flag =1;
        }
    }
    if(flag ==0)
    {
        printf("NO HAY LIBROS");
    }
    return flag;
}

void eLibro_mostrarUno(eLibro libros, int tam)
{
    printf("%d   %s    %d\n", libros.codigo , libros.titulo , libros.codigoAutor);
}

void eLibro_alta(eLibro libros[], int tam, eAutor autores[], int tamAutores)
{
    int index;
    int indexAutor;
    int auxCodigo;
    int validar;
    char auxTitulo[51];
    int auxCodigoAutor;

    index = eLibro_buscarLibre(libros,tam);

    if(index == -1)
    {
        printf("\nNo hay libros disponibles\n");
    }
    else
    {
        auxCodigo= eLibro_siguienteId(libros,tam);
        printf("Codigo de libro: %d\n",auxCodigo);

        eAutor_listar(autores,tamAutores);
        printf("Ingrese codigo de autor: ");
        scanf("%d",&auxCodigoAutor);
        indexAutor = eAutor_buscar(autores,tamAutores,auxCodigoAutor);

        if(indexAutor==-1)
        {
            printf("No se encontro el autor\n");
        }
        else
        {
            libros[index].codigoAutor = auxCodigoAutor;

            validar = getStringLetras("Ingrese titulo: ",auxTitulo);
            while(validar == 0)
            {
                validar = getStringLetras("ERROR, ingrese solo letras: ",auxTitulo);
            }
            if(validar != 0)
            {
                strcpy(libros[index].titulo,auxTitulo);
                libros[index].estado = 1;
                libros[index].codigo = auxCodigo;
                printf("Alta de libro exitosa.\nCodigo: %d  Titulo: %s  Codigo de autor: %d\n",auxCodigo,libros[index].titulo,libros[index].codigoAutor);
                auxCodigo++;
            }
        }
    }
}

void eLibro_baja(eLibro libros[], int tam)
{
    int index;
    int codigo;
    char confirma;
    int retorno = eLibro_listar(libros,tam);
    if(retorno==0)
    {
        printf(" PARA DAR DE BAJA\n");
    }
    else
    {
        printf("Ingrese codigo: ");
        scanf("%d", &codigo);
        index = eLibro_buscar(libros,tam,codigo);

        if(index== -1)
        {
            printf("No se encontro al libro\n");
        }
        else
        {
            confirma = getChar("Desea dar de baja el libro? (S/N): ", confirma);
            confirma = toupper(confirma);
            while((confirma!= 'S') && (confirma!= 'N'))
            {
                confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                confirma = toupper(confirma);
            }
            if(confirma=='S')
            {
                libros[index].estado = 0;
                printf("Baja exitosa!\n");
            }
            else
            {
                printf("No se dio de baja al libro.\n");
            }
        }
    }
}

int eLibro_buscar(eLibro libros[], int tam,int codigo)
{
    int index = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(libros[i].codigo == codigo && libros[i].estado ==1 )
        {
            index=i;
            break;
        }
    }

    return index;
}

void eLibro_mostrarConAutor(eLibro libros[],int tamLibros,eAutor autores[],int tamAutores)
{
    int i,auxIdAutor;
    char auxAutor[51];
    printf("CODIGO       TITULO            AUTOR");
    for(i=0;i<tamLibros;i++)
    {
        if(libros[i].codigo != 0)
        {
            auxIdAutor = eAutor_buscar(autores,tamAutores,libros[i].codigoAutor);
            if(auxIdAutor != -1)
            {
                strcpy(auxAutor,autores[auxIdAutor].apellido);
            }
            else
            {
                sprintf(auxAutor, "? (Id:%d)", libros[i].codigoAutor);
            }
            printf("\n %d     %s     %s",libros[i].codigo,libros[i].titulo,auxAutor);
        }
    }
}

int eLibro_buscarLibre(eLibro libros[],int tam)
{
    int index = -1;
    int i = 0;
    for(i=0; i<tam; i++)
    {
        if (libros[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int eLibro_siguienteId(eLibro libros[],int tam)
{
    int retorno = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(libros[i].codigo>retorno)
        {
            retorno=libros[i].codigo;
        }
    }
    return retorno+1;
}

int eLibro_menuModificacion()
{
    char opcion = '0';

    printf("\n----MODIFICACION LIBRO----\n");
    printf("1.Titulo\n");
    printf("2.Codigo de autor\n");
    printf("3.Cancelar\n");

    opcion = getOpcion("\nIngrese opcion entre 1 y 3: ", opcion,'1','3');
    return opcion;
}

void eLibro_modificarCampo(eLibro libros[], int tam,eAutor autores[],int tamAutores)
{
    int codigo;
    int index;
    int validar;
    char auxTitulo[51];
    int auxCodigoAutor;
    int indexAutor;
    int retorno = eLibro_listar(libros,tam);
    char confirma;
    if(retorno==0)
    {
        printf(" PARA MODIFICAR");
    }else
    {
        printf("Ingrese codigo del libro a modificar: ");
        scanf("%d",&codigo);
        index = eLibro_buscar(libros,tam,codigo);
        if(index==-1)
        {
            printf("No se encontro el libro\n");
        }else{
            do{
                switch(eLibro_menuModificacion())
                {
                case '1':
                    printf("El titulo actual es: %s\n",libros[index].titulo);
                    validar = getStringLetras("Ingrese nuevo titulo: ",auxTitulo);
                    while(validar == 0)
                    {
                        validar = getStringLetras("ERROR, ingrese solo letras: ",auxTitulo);
                    }
                    confirma = getChar("Seguro quiere modificarlo? (S/N):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(libros[index].titulo,auxTitulo);
                    }
                    system("pause");
                    break;

                case '2':
                    eAutor_listar(autores,tamAutores);
                    printf("Ingrese codigo del autor: ");
                    scanf("%d",&auxCodigoAutor);
                    indexAutor = eAutor_buscar(autores,tamAutores,auxCodigoAutor);

                    if(indexAutor==-1)
                    {
                        printf("No se encontro el autor\n");
                    }else
                    {
                        printf("Ingrese nuevo codigo de autor: ");
                        scanf("%d",&auxCodigoAutor);
                        confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                        confirma = toupper(confirma);
                        while((confirma!= 'S') && (confirma!= 'N'))
                        {
                            confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                            confirma = toupper(confirma);
                        }
                        if(confirma == 'S')
                        {
                            libros[index].codigoAutor = auxCodigoAutor;
                        }
                    }
                    system("pause");
                    break;
                case '3':
                    confirma = 'N';
                    break;
                default:
                    printf("Ingrese opcion correcta \n");
                    system("pause");
                }
            }while (confirma == 'S');
        }
    }
}

int menuLibros()
{
    char opcion = '.';

    printf("\n----MENU LIBROS----\n");
    printf("A.Alta\n");
    printf("B.Modificar\n");
    printf("C.Baja\n");
    printf("D.Listar libros\n");
    printf("E.Salir\n");

    opcion=getChar("Elija una opcion: \n",opcion);
    opcion = toupper(opcion);
    return opcion;
}
