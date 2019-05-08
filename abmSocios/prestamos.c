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
    int i;
    for(i=0; i<tam; i++)
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

int menuListar()
{
    char opcion = '.';

    printf("\n----MENU LISTAR----\n");
    printf("A.Total general y promedio diario\n");
    printf("B.Cantidad de dias que no superan el promedio del item anterior\n");
    printf("C.Socios que solicitaron un prestamo de un libro determinado\n");
    printf("D.Libros que solicitados a prestamo por un socio determinado\n");
    printf("E.Libros menos solicitados en prestamo\n");
    printf("F.Socio(s) que realizaron mas solicitudes a prestamo\n");
    printf("G.Libros solicitados a prestamo en una fecha determinada\n");
    printf("H.Socios que realizaron al menos una solicitud a prestamo en una fecha determinada\n");
    printf("I.Libros ordenados por titulo \n");
    printf("J.Socios ordenados por apellido\n");
    printf("K.Salir\n");

    opcion=getChar("Elija una opcion: \n",opcion);
    opcion = toupper(opcion);

    return opcion;
}

int ePrestamo_totalGeneral(ePrestamo prestamos[], int tam)
{
    int i=0;
    float acumuladorPrestamo=0;

    for(i=0;i<tam;i++)
    {
        if(prestamos[i].estado == 1)
        {
            acumuladorPrestamo++;
        }
    }
    if(acumuladorPrestamo == 0)
    {
        printf("No hay datos cargados\n");
    }

     return acumuladorPrestamo;
}

int ePrestamo_promedioDiario(ePrestamo prestamos[], int tam)
{
    int i;
    float acumDias = 0;
    int prestamosActivos =0;
    float prestamoPromedio = 0;
	for (i=0;i<tam;i++)
	{
        if( prestamos[i].estado == 1)
        {
            prestamosActivos++;
            if(prestamos[i].fechaPrestamo.dia == prestamos[i].fechaPrestamo.dia)
            {
                acumDias++;
            }
        }
    }
    if (prestamosActivos == 0) //si se cumple no existen prestamos activos en el array
	{
	  prestamoPromedio = -1;
	}else
	{
        prestamoPromedio = (prestamosActivos / (float)acumDias);
	}

	return prestamoPromedio;
}

void ePrestamo_listarTotalYPromedio(ePrestamo prestamos[], int tam)
{
    float promedio = ePrestamo_promedioDiario(prestamos,tam);
    int total = ePrestamo_totalGeneral(prestamos,tam);
    if(promedio==-1)
    {
        printf("No hay prestamos en el sistema");
    }
    else
    {
        printf("Promedio: %.2f ", promedio);
    }

    if(total==0)
    {
        printf("No hay prestamos en el sistema");
    }
    else
    {
        printf("total: %2.f ", total);
    }

}

void ePrestamo_listarCantidadDiasNoSuperanPromedio(ePrestamo prestamos[], int tam)
{
    float promedio;
    int contador = 0;
    int dias =0;
    int i;
    int flag= 0;


    printf("\n");
    printf("DIAS QUE NO SUPERAN EL PROMEDIO DE LOS PRESTAMOS: ");
    for (i = 0 ; i < tam ; i++)
    {
        if(prestamos[i].estado == 1 && contador < promedio)
        {
            flag = 1;
            dias++;
        }
    }
     if(!flag)
    {
        system("cls");
        printf("**No hay cant de dias que cumplan lo solicitado.\n\n");
    }
}

