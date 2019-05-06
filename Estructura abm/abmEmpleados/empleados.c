#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "empleados.h"


void inicializarEmpleados(eEmpleado empleados[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        empleados[i].estado= 0;
    }
}

void initSectores(eSector sectores[], int cant)
{
    int i;
    eSector sec[]={{1,"RRHH"},{2,"Sistemas"},{3,"Ventas"},{4,"Compras"},{5,"Oficina"}};
    for(i=0;i<cant;i++)
    {
        sectores[i].id = sec[i].id;
        strcpy(sectores[i].desc, sec[i].desc);
    }
}

void mostrarEmpleado(eSector sectores[],int tam,eEmpleado emp)
{
    int nombreSector[20];
    int esta;
    esta = obtenerSector(sectores,tam, emp.idSector, nombreSector);

    if (!esta)
    {
        strcpy(nombreSector, "Sin definir");
    }
    printf("%5d   %5s %5s   %4c     %.2f   %s     %d/%d/%d \n",emp.legajo,emp.nombre,emp.apellido,emp.sexo,emp.sueldo,nombreSector,emp.fechaNacimiento);
}

void mostrarEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSectores)
{
    int flag =0;

    printf("LEGAJO\t  NOMBRE     SEXO\t  SUELDO\tSECTOR\tNACIMIENTO\n");
    for(int i=0; i<tam; i++)
    {
        if(empleados[i].estado == 1)
        {
            mostrarEmpleado(sectores, tamSectores,empleados[i]);
            flag =1;
        }
    }
    if(flag ==0)
    {
        printf("NO HAY DATOS QUE MOSTRAR\n");
    }
}

int buscarLibre(eEmpleado empleados[],int tam)
{
    int index = -1;

    if(tam > 0 && empleados != NULL)
    {
        index = -2;
        for(int i=0; i<tam; i++)
        {
            if (empleados[i].estado == 0)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int buscarEmpleado(eEmpleado empleados[], int tam, int legajo)
{
    int index = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(empleados[i].estado ==1 && empleados[i].legajo == legajo)
        {
            index=i;
            break;
        }
    }

    return index;
}

void altaEmpleado(eEmpleado empleados[], int tam,eSector sectores[],int tamSectores)
{
    int index;
    int legajo;
    int esta;

    index = buscarLibre(empleados, tam);

    if(index == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", legajo);
            mostrarEmpleado(sectores, tamSectores,empleados[esta]);
        }
        else
        {
            empleados[index].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(empleados[index].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &empleados[index].sexo);
            empleados[index].sexo = toupper(empleados[index].sexo);

            printf("Ingrese sueldo: ");
            scanf("%f", &empleados[index].sueldo);

            printf("Fecha de nacimiento\nDia:");
            scanf("%d",&empleados[index].fechaNacimiento.dia);

            printf("Mes:");
            scanf("%d",&empleados[index].fechaNacimiento.mes);

            printf("Anio:");
            scanf("%d",&empleados[index].fechaNacimiento.anio);

            printf("Ingrese sector (1 a 5)");
            scanf("%d",&empleados[index].idSector);

            empleados[index].estado = 1;

            printf("Alta empleado exitosa\n\n");
        }
    }
}

void bajaEmpleado(eEmpleado empleados[], int tam)
{
    int index;
    int legajo;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    index = buscarEmpleado(empleados,tam,legajo);

    if(index== -1)
    {
        printf("No se encontro al empleado\n");
    }
    else
    {
        printf("Desea dar de baja al empleado?\n");
        fflush(stdin);
        confirma = getch();

        if(tolower(confirma)=='s')
        {
            empleados[index].estado =0;
            printf("Baja exitosa\n");
        }
        else
        {
            printf("No se dio de baja al empleado\n");
        }
    }
}

void modificarEmpleado(eEmpleado empleados[], int tam)
{
    int legajo;
    int index;
    float sueldo;
    char confirma;

    printf("Ingrese legajo del empleado a modificar:\n");
    scanf("%d",&legajo);

    index = buscarEmpleado(empleados,tam,legajo);

    if(index==-1)
    {
        printf("No se encontro el empleado");
    }
    else
    {
        printf("El sueldo actual es: %.2f\n",empleados[index].sueldo);
        printf("Ingrese nuevo monto:\n");
        scanf("%f",&sueldo);

        printf("Desea modificarlo? s/n \n");
        fflush(stdin);
        confirma= getche();

        if(tolower(confirma)== 's')
        {
            empleados[index].sueldo = sueldo;
        }
    }
}

void ordenarEmpleados(eEmpleado empleados[], int tam)
{
    int i,j;
    eEmpleado aux;

    for(i=0;i<tam-1;i++)
    {
        if(empleados[i].estado==0)
        {
            continue;
        }
        for(j=i+1;j<tam;j++)
        {
            if(empleados[j].estado ==0)
            {
                continue;
            }
            if(empleados[i].legajo > empleados[j].legajo)
            {
                aux = empleados[i];
                empleados[i]= empleados[j];
                empleados[j]= aux;
            }
        }
    }
}

int obtenerSector(eSector sectores[],int tam, int idSector,int desc[])
{
    int ok=0;

    for(int i =0; i<tam;i++)
    {
        if(idSector == sectores[i].id)
        {
            strcpy(desc,sectores[i].desc);
            ok =1;
            break;
        }
    }
    return ok;
}

void mostrarSectoresConEmpleados(eEmpleado empleados[],int tam,eSector sectores[],int tamSectores)
{
    for(int i=0;i<tamSectores;i++)
    {
        printf("SECTOR: %s\n",sectores[i].desc);
        for(int j=0;j<tam;j++)
        {
            if((empleados[j].idSector == sectores[i].id) && (empleados[j].estado ==1))
            {
                mostrarEmpleado(sectores,tamSectores,empleados[j]);
            }
        }
    }
    printf("\n");
}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSectores)
{
    int contador;

    for(int i=0; i< tamSectores; i++ )
    {
        contador = 0;
        printf("\nSector: %s\n", sectores[i].desc);

        for(int j=0; j < tam; j++)
        {
            if(sectores[i].id == empleados[j].idSector && empleados[j].estado == 1)
            {
                contador++;
            }
        }

        printf("Cantidad: %d\n", contador);
    }
}
