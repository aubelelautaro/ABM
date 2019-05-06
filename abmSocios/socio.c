#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "socio.h"

void initLibros(eLibro libros[], int tam)
{
    int i;
    eLibro lib[]={{1,"libroUno",2},{2,"libroDos",3},{3,"libroTres",1},{4,"libroCuatro",5},{5,"libroCinco",4}};
    for(i=0;i<tam;i++)
    {
        libros[i].codigo = lib[i].codigo;
        strcpy(libros[i].titulo, lib[i].titulo);
        libros[i].codigoAutor = lib[i].codigoAutor;
    }
}

void initAutores(eAutor autores[], int tam)
{
    int i;
    eAutor aut[]={{1,"AAA","AAA"},{2,"DDD","DDD"},{3,"BBB","BBB"},{4,"CCC","CCC"},{5,"DDD","DDD"}};
    for(i=0;i<tam;i++)
    {
        autores[i].codigo = aut[i].codigo;
        strcpy(autores[i].nombre, aut[i].nombre);
        strcpy(autores[i].apellido, aut[i].apellido);
    }
}

void mostrarSocio(eSocio socios, int tam)
{
    if(socios.estado ==1 )
    {
        printf("%d  %5s %5s  %c   %s    %s  %d/%d/%d\n",socios.codigo,socios.apellido,socios.nombre,socios.sexo,socios.telefono,socios.eMail,socios.fechaAsociado);
    }
}

void mostrarSocios(eSocio socios[], int tam)
{
    int flag =0;

    printf("CODIGO DE SOCIO  APELLIDO\t  NOMBRE  SEXO\t  TELEFONO \t  EMAIL \t FECHA ASOCIADO\n");
    for(int i=0; i<tam; i++)
    {
        if(socios[i].estado == 1)
        {
            mostrarSocio(socios[i],tam);
            flag =1;
        }
    }
    if(flag ==0)
    {
        printf("NO HAY DATOS QUE MOSTRAR\n");
    }
}

int buscarLibre(eSocio socios[],int tam)
{
    int index = -1;

    if(tam > 0 && socios != NULL)
    {
        index = -2;
        for(int i=0; i<tam; i++)
        {
            if (socios[i].estado == 0)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int buscarSocio(eSocio socios[], int tam, int codigo)
{
    int index = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(socios[i].codigo == codigo)
        {
            index=i;
            break;
        }
    }

    return index;
}

void altaSocio(eSocio socios[], int tam)
{
    int index;
    int auxCodigo=0;
    char auxNombre[31];
    char auxApellido[31];
    char auxSexo;
    char auxTelefono[16];
    char auxMail[31];

    index = buscarLibre(socios, tam);

    if(index == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        socios[index].codigo = auxCodigo+1;

        if (!getStringLetras("Ingrese apellido: ",auxApellido))
        {
            printf ("El apellido debe estar compuesto solo por letras\n");
        }
        if (!getStringLetras("Ingrese el nombre: ",auxNombre))
        {
            printf ("El nombre debe estar compuesta solo por letras\n");
        }

        getChar("Ingrese sexo (M/F): ",auxSexo);

        getStringLetras("Ingrese telefono: ",auxTelefono);
        while(!esTelefono(auxTelefono))
        {
            printf("Ingrese un telefono valido (1234-5678)\n");
            fflush(stdin);
            gets(auxTelefono);
        }
        getStringLetras("Ingrese mail: ",auxMail);
        if(!esMail(auxMail))
        {
            printf("Ingrese un mail valido\n");
            fflush(stdin);
            gets(auxMail);
        }

        printf("Fecha de asociado\nDia:");
        scanf("%d",&socios[index].fechaAsociado.dia);
        if(socios[index].fechaAsociado.dia > 31 || socios[index].fechaAsociado.dia < 1)
        {
            printf("Error, ingrese dia valido");
        }

        printf("Mes:");
        scanf("%d",&socios[index].fechaAsociado.mes);
        if(socios[index].fechaAsociado.mes > 12 || socios[index].fechaAsociado.mes < 1)
        {
            printf("Error, ingrese mes valido");
        }

        printf("Anio:");
        scanf("%d",&socios[index].fechaAsociado.anio);
        if(socios[index].fechaAsociado.anio > 2019 || socios[index].fechaAsociado.anio < 1850)
        {
            printf("Error, ingrese anio valido");
        }

        strcpy(socios[index].apellido,auxApellido);
        strcpy(socios[index].nombre,auxNombre);
        strcpy(socios[index].telefono,auxTelefono);
        strcpy(socios[index].eMail,auxMail);
        socios[index].sexo = toupper(socios[index].sexo);
        socios[index].estado = 1;

        printf("Alta socios exitosa\n\n");
    }
}

void bajaSocio(eSocio socios[], int tam)
{
    int index;
    int codigo;
    char confirma;

    printf("Ingrese codigo: ");
    scanf("%d", &codigo);
    index = buscarSocio(socios,tam,codigo);

    if(index== -1)
    {
        printf("No se encontro al socios\n");
    }
    else
    {
        printf("Desea dar de baja al socios?\n");
        fflush(stdin);
        confirma = getch();

        if(tolower(confirma)=='s')
        {
            socios[index].estado =0;
            printf("Baja exitosa\n");
        }
        else
        {
            printf("No se dio de baja al socios\n");
        }
    }
}

void listarSocios(eSocio socios[],int tam)
{
    int i,j;
    eSocio aux;

     printf("\n****** LISTADO DE SOCIOS POR APELLIDO ******\n\n");
    for(i=0;i<tam-1;i++)
    {
        if(socios[i].estado == 1)
        {
            continue;
        }
        for(j=i+1;j<tam;j++)
        {
            if(socios[j].estado == 1)
            {
                continue;
            }
            if(strcmp(socios[i].apellido,socios[j].apellido)>0)
            {
                aux = socios[i];
                socios[i]= socios[j];
                socios[j]= aux;
                mostrarSocio(socios[i],tam);
            }
        }
    }
}

void listarLibros(eLibro libros[],int tam)
{
    int i,j;
    eLibro aux;

    printf("\n****** LISTADO DE LIBROS POR TITULO ******\n\n");
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(libros[i].titulo,libros[j].titulo)>0)
            {
                aux = libros[i];
                libros[i]= libros[j];
                libros[j]= aux;

                printf("%d   %s    %d", libros[i].codigo , libros[i].titulo , libros[i].codigoAutor);
            }
        }
    }
}

void listarAutores(eAutor autores[],int tam)
{
    int i,j;
    eAutor aux;

     printf("\n****** LISTADO DE AUTORES POR APELLIDO ******\n\n");
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(autores[i].apellido,autores[j].apellido)>0)
            {
                aux = autores[i];
                autores[i]= autores[j];
                autores[j]= aux;

                printf("%d   %s    %s", autores[i].codigo , autores[i].nombre , autores[i].apellido);
            }
        }
    }
}

void altaPrestamo(ePrestamo prestamos[], int tam)
{
    int index;
    int auxCodigo=0;
    int auxCodigoLibro,auxCodigoSocio;
    char auxCodigoLibroStr[15];
    char auxCodigoSocioStr[15];
    char confirma = 'n';

    printf("Seguro quiere dar de alta un prestamo? (s/n)");
    fflush(stdin);
    confirma = getche();
    if(tolower(confirma)=='s')
    {
        prestamos[index].codigo = auxCodigo+1;
    }
        if(!getStringNumeros("Ingrese codigo de libro: ",auxCodigoLibro))
        {
            printf ("El codigo debe estar compuesto solo por numeros\n");
        }
        auxCodigoLibro = atoi(auxCodigoLibroStr);

        if(!getStringNumeros("Ingrese codigo de socio: ",auxCodigoSocio))
        {
            printf ("El codigo debe estar compuesto solo por numeros\n");
        }
        auxCodigoSocio = atoi(auxCodigoSocioStr);

        printf("Fecha de prestamo\nDia:");
        scanf("%d",&prestamos[index].fechaPrestamo.dia);
        if(prestamos[index].fechaPrestamo.dia > 31 || prestamos[index].fechaPrestamo.dia < 1)
        {
            printf("Error, ingrese dia valido");
        }

        printf("Mes:");
        scanf("%d",&prestamos[index].fechaPrestamo.mes);
        if(prestamos[index].fechaPrestamo.mes > 12 || prestamos[index].fechaPrestamo.mes < 1)
        {
            printf("Error, ingrese mes valido");
        }

        printf("Anio:");
        scanf("%d",&prestamos[index].fechaPrestamo.anio);
        if(prestamos[index].fechaPrestamo.anio > 2019 || prestamos[index].fechaPrestamo.anio < 1850)
        {
            printf("Error, ingrese anio valido");
        }
        printf("Alta prestamo exitosa\n\n");
}
