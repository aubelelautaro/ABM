#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#define OCUPADO 0
#define LIBRE 1
#define BORRADO -5

int eUser_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;

        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idUsuario>retorno)
                    {
                         retorno=listado[i].idUsuario;
                    }

            }
        }

    return retorno+1;
}

int eUser_mostrarListadoConBorrados(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eUser_mostrarUno(listado[i]);
        }
    }
    return retorno;
}

int validarNombre(char nombre[])
{
    int retorno=1;

    int i;
    for(i=0; i<strlen(nombre); i++)
    {
        if(!(isalpha(nombre[i])))
        {
            retorno=0;
            printf("Error, ingrese solo caracteres. \n");
            break;
        }
    }

    return retorno;
}

int validarNumero(char numero[])
{
    int retorno=1;

    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            retorno=0;
            printf("Error, ingrese solo numeros. \n");
            break;
        }
    }

    return retorno;
}

int eProducto_altaPublicacion(eUsuario listadoUsuarios[], eProducto listadoProductos[], int largoProductos, int largoUsuarios)
{
    int idUsuario, indiceVacio=-1, idProducto, retorno=-1;

    eUser_mostrarListado(listadoUsuarios,largoUsuarios);

    printf("\nIngrese ID de usuario que publica: ");
    scanf("%d",&idUsuario);

    if(largoProductos > 0 && listadoProductos != NULL)
    {
        retorno=-2;
        indiceVacio=eProducto_buscarLugarLibre(listadoProductos,largoProductos);

    if(indiceVacio >= 0)
        {
            retorno = -3;

            idProducto=eProducto_siguienteId(listadoProductos,largoProductos);
            listadoProductos[indiceVacio].idProducto=idProducto;
            listadoProductos[indiceVacio].idUsuario=idUsuario;

            retorno=0;

            printf("\nIngrese nombre de producto: ");
            fflush(stdin);
            gets(listadoProductos[indiceVacio].nombre);

            printf("\nIngrese precio del producto: ");
            scanf("%f",&listadoProductos[indiceVacio].precio);

            printf("\nIngrese stock del producto: ");
            scanf("%d",&listadoProductos[indiceVacio].stock);

            listadoProductos[indiceVacio].idUsuario=idUsuario;
            listadoProductos[indiceVacio].estado=OCUPADO;
        }


    }

    return retorno;
}

int eProducto_modificarPublicacion(eUsuario listadoUsuarios[], eProducto listadoProductos[], int largoProductos, int largoUsuarios)
{
    int idUsuario, indiceProducto=-1, idProducto;

    eUser_mostrarListado(listadoUsuarios,largoUsuarios);

    printf("\nIngrese ID de usuario cuya publicacion quiera modificar: ");
    scanf("%d",&idUsuario);

    eProducto_mostrarProductosPorIdUsuario(listadoProductos, listadoUsuarios, largoProductos, largoUsuarios, idUsuario);

    printf("\nIngrese ID de producto a modificar: ");
    scanf("%d",&idProducto);

    indiceProducto=eProducto_buscarPorId(listadoProductos,  largoProductos, idProducto);

    if(indiceProducto>=0)
    {
        eProducto_mostrarUno(listadoProductos[indiceProducto]);

        printf("\nIngrese nuevo precio: ");
        scanf("%f", &listadoProductos[indiceProducto].precio);

        printf("\nIngrese stock: ");
        scanf("%d", &listadoProductos[indiceProducto].stock);


        eProducto_mostrarUno(listadoProductos[indiceProducto]);
    }

    return indiceProducto;
}

void eProducto_mostrarProductosPorIdUsuario(eProducto listadoProductos[],eUsuario listadoUsuarios[], int largoProductos, int largoUsuarios, int id)
{
    int i;

    if(largoProductos > 0 && listadoProductos != NULL)
    {
        for(i=0;i<largoProductos;i++)
        {
            if(listadoProductos[i].estado == OCUPADO && listadoProductos[i].idUsuario == id)
            {
                printf("\n Nombre: %s - ID producto: - %d Precio: %.2f - Stock: %d - Vendidos: %d\n", listadoProductos[i].nombre, listadoProductos[i].idProducto, listadoProductos[i].precio, listadoProductos[i].stock, listadoProductos[i].cantidadVentas);
            }
        }
    }
}

void eProducto_borrarProductosPorIdUsuario(eProducto listadoProductos[],eUsuario listadoUsuarios[], int largoProductos, int largoUsuarios, int id)
{
    int i;

    if(largoProductos > 0 && listadoProductos != NULL)
    {
        for(i=0;i<largoProductos;i++)
        {
            if(listadoProductos[i].estado == OCUPADO && listadoProductos[i].idUsuario == id)
            {
                listadoProductos[i].estado = BORRADO;
            }
        }
    }
}

int eProducto_cancelarPublicacion(eUsuario listadoUsuarios[], eProducto listadoProductos[], int largoProductos, int largoUsuarios)
{
    int idUsuario, indiceProducto=-1, idProducto;

    eUser_mostrarListado(listadoUsuarios,largoUsuarios);

    printf("\nIngrese ID de usuario cuya publicacion quiera cancelar: ");
    scanf("%d",&idUsuario);

    eProducto_mostrarProductosPorIdUsuario(listadoProductos, listadoUsuarios, largoProductos, largoUsuarios, idUsuario);

    printf("\nIngrese ID de producto a cancelar: ");
    scanf("%d",&idProducto);

    indiceProducto=eProducto_buscarPorId(listadoProductos,  largoProductos, idProducto);

    listadoProductos[indiceProducto].estado=BORRADO;

    if(indiceProducto>=0)
    {
        eProducto_mostrarUno(listadoProductos[indiceProducto]);
    }

    return indiceProducto;
}

int eProducto_comprarProducto(eUsuario listadoUsuarios[], eProducto listadoProductos[], int largoProductos, int largoUsuarios)
{
    int idComprar, indiceProducto, cantidadCompra, indiceUsuario;

    eProducto_mostrarListado(listadoProductos, largoProductos);

    printf("Ingrese ID del producto a comprar: ");
    scanf("%d", &idComprar);

    indiceProducto=eProducto_buscarPorId(listadoProductos,  largoProductos, idComprar);

    if(listadoProductos[indiceProducto].stock>0)
    {
        do{
            printf("Ingrese cantidad a comprar (Stock: %d): ", listadoProductos[indiceProducto].stock);
            scanf("%d", &cantidadCompra);
        }while(cantidadCompra>=listadoProductos[indiceProducto].stock);


        listadoProductos[indiceProducto].stock-=cantidadCompra;
        listadoProductos[indiceProducto].cantidadVentas+=cantidadCompra;
        listadoProductos[indiceProducto].cantidadVentasPromedio+=1;

        indiceUsuario=eUser_buscarPorId(listadoUsuarios ,largoUsuarios, listadoProductos[indiceProducto].idUsuario);

        do{
            printf("Ingrese calificacion (del 1 al 10):");
            scanf("%d", &listadoUsuarios[indiceUsuario].calificacion);
        }while(listadoUsuarios[indiceUsuario].calificacion<1 || listadoUsuarios[indiceUsuario].calificacion>10);

    }
}

int eUser_listarPublicacionesUsuario(eUsuario listadoUsuarios[], int largoUsuarios, eProducto listadoProductos[], int largoProductos)
{
    int id, retorno=-1;

    eUser_mostrarListado(listadoUsuarios,largoUsuarios);

    printf("Ingrese ID de usuario: ");
    scanf("%d", &id);

    eProducto_mostrarProductosPorIdUsuario(listadoProductos,listadoUsuarios, largoProductos, largoUsuarios,id);

    return retorno;
}

int eUser_listarCalificaciones(eUsuario listadoUsuarios[],int largoUsuarios, eProducto listadoProductos[], int largoProductos)
{
    int i;
    float promedio;

    promedio=promedioCalificaciones(listadoUsuarios,largoUsuarios, listadoProductos, largoProductos);

    for(i=0;i<largoUsuarios;i++)
    {
        if(listadoUsuarios[i].estado==OCUPADO)
        {
            printf("Nombre: %s - Calificacion promedio: %.2f\n", listadoUsuarios[i].nombre, promedio);
        }
    }
}

float promedioCalificaciones(eUsuario listadoUsuarios[], int largoUsuarios, eProducto listadoProductos[], int largoProductos)
{
    int i, calificacionesAcumulador, cantidadVentasPromedio;
    float promedio=-1;

    for(i=0;i<largoUsuarios;i++)
    {
        if(listadoUsuarios[i].estado==OCUPADO)
        {
            calificacionesAcumulador+=listadoUsuarios[i].calificacion;
            printf("%d\n", calificacionesAcumulador);
        }
    }

    for(i=0;i<largoProductos;i++)
    {
        if(listadoProductos[i].estado==OCUPADO)
        {
            cantidadVentasPromedio+=listadoProductos[i].cantidadVentasPromedio;
            printf("%d\n", cantidadVentasPromedio);
        }
    }

    promedio=calificacionesAcumulador/cantidadVentasPromedio;

    return promedio;
}
