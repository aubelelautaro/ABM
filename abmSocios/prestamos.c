#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "libros.h"
#include "prestamos.h"

void ePrestamo_alta(ePrestamo prestamos[], int tam,eSocio socios[],int tamSocios,eLibro libros[], int tamLibros)
{
    int index;
    int indexSocio;
    int indexLibro;
    int auxCodigo;
    int dia,mes,anio;
    char confirma;
    char auxDia[3],auxMes[3],auxAnio[5];
    int auxCodigoLibro,auxCodigoSocio;


    index = ePrestamo_buscarLibre(prestamos,tam);

    if(index == -1)
    {
        printf("\nNo hay prestamos disponibles\n");
    }
    else
    {
        auxCodigo= ePrestamo_siguienteId(prestamos,tam);
        printf("Codigo de prestamo: %d\n",auxCodigo);

        eLibro_listar(libros,tamLibros);
        printf("Ingrese codigo del libro: ");
        scanf("%d",&auxCodigoLibro);
        indexLibro = eLibro_buscar(libros,tamLibros,auxCodigoLibro);

        if(indexLibro==-1)
        {
            printf("No se encontro el libro\n");
        }
        else
        {
            eSocio_mostrarTodos(socios,tamSocios);
            printf("Ingrese codigo del socio: ");
            scanf("%d",&auxCodigoSocio);
            indexSocio = eSocio_buscar(socios,tamSocios,auxCodigoSocio);

            if(indexSocio==-1)
            {
                printf("No se encontro el socio\n");
            }else
            {
                do
                {
                    getStringNumeros("Ingrese dia entre 1 y 31: ",auxDia);
                    dia =atoi(auxDia);
                }while(dia>31 || dia <1);
                prestamos[index].fechaPrestamo.dia = dia;

                do
                {
                    getStringNumeros("Ingrese mes entre 1 y 12: ",auxMes);
                    mes =atoi(auxMes);
                }while(mes>12 || mes <1);
                prestamos[index].fechaPrestamo.mes = mes;

                do
                {
                    getStringNumeros("Ingrese anio entre 1900 y 2020: ",auxAnio);
                    anio =atoi(auxAnio);
                }while(anio>2020 || anio <1900);

                prestamos[index].codigo = auxCodigo;
                prestamos[index].codigoSocio = auxCodigoSocio;
                prestamos[index].codigoLibro = auxCodigoLibro;
                prestamos[index].fechaPrestamo.anio = anio;
                prestamos[index].estado = 1;
                printf("Alta de prestamo exitosa.\nCodigo: %d  Codigo de Socio: %d  Codigo de libro: %d  Fecha de prestamo: %d/%d/%d\n",auxCodigo,prestamos[index].codigoSocio,prestamos[index].codigoLibro,prestamos[index].fechaPrestamo);
                auxCodigo++;
            }
        }
    }
}

int ePrestamo_buscarLibre(ePrestamo prestamos[],int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if (prestamos[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int ePrestamo_siguienteId(ePrestamo prestamos[],int tam)
{
    int retorno = 0;
    int i;

        for(i=0; i<tam; i++)
        {
            if(prestamos[i].codigo>retorno)
            {
                 retorno=prestamos[i].codigo;
            }
        }

    return retorno+1;
}

void ePrestamo_init(ePrestamo prestamos[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        prestamos[i].codigo = 0;
        prestamos[i].estado = 0;
    }
}
