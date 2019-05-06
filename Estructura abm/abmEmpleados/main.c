#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#include "empleados.h"

#define TAM 12
#define TAMSEC 5

int main()
{
    int rta = 's';
    char confirma;

    eEmpleado lista[TAM] = {
        {"Xasd","AAA",'M',500,240.22,1,{19,04,1999},1},
        {"Walter","BBB",'F',900,540.22,1,{23,05,1990},2},
        {"Franco","CCCC",'M',300,740.22,1,{05,06,1989},3},
        {"Alberto","DDD",'m',400,35000,1,{23,07,1940},1},
        {"Sonia","EEE", 'f',382,39000,1,{01,02,1930},3},
        {"Miguel","FFF", 'm',585,29700,1,{04,8,1960},4},
        {"Adrian","GGG", 'm',834,43200,1,{02,9,1950},5},
        {"Lucia","HHH", 'f',142,32300,1,{9,01,1942},2},
        {"Raston","III", 'm',43,29760,1,{07,10,1978},4},
        {"Diego","JJJ", 'm',87,35000,1,{12,11,1924},5},
        {"Viviana","KKK", 'f',100,47000,1,{14,12,1931},3},
        {"Zustavo","LLL", 'm',99,25000,1,{31,03,1952},2}

        };
    eSector sectores[TAMSEC] =
        {
        {1,"AAA"},
        {2,"BBB"},
        {3,"CCC"},
        {4,"DDD"},
        {5,"EEE"}

        };
    //inicializarEmpleados(lista,TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(lista,TAM,sectores,TAMSEC);
            system("pause");
            break;
        case 2:
            bajaEmpleado(lista,TAM);
            system("pause");
            break;
        case 3:
            modificarCampo(lista,TAM);
            break;
        case 4:
            mostrarEmpleados(lista,TAM,sectores, TAMSEC);
            system("pause");
            break;
        case 5:
            ordenarEmpleados(lista,TAM);
            system("pause");
            break;
        case 6:
            mostrarSectoresConEmpleados(lista,TAM,sectores,TAMSEC);
            system("pause");
            break;
        case 7:
            mostrarCantEmpleadosXSector(lista,TAM,sectores,TAMSEC);
            system("pause");
            break;
        case 8:
            printf("Seguro desea salir? s/n \n");
            fflush(stdin);
            confirma = getch();
            if(tolower(confirma)== 's')
            {
                rta = 'n';
            }
            break;
        default:
            printf("Ingrese opcion correcta\n");
            system("pause");
        }

    }
    while(rta == 's');

    return 0;
}

int menu()
{
    int opcion = 0;

    system("cls");
    printf("---------------ABM EMPLEADOS--------------\n");
    printf("1.Alta\n");
    printf("2.Baja\n");
    printf("3.Modificacion\n");
    printf("4.Listar\n");
    printf("5.Ordenar\n");
    printf("6.Listar sectores con empleados\n");
    printf("7.Cantidad de empleados por sector\n");
    printf("8.Salir\n");

    opcion=getInt("Elija una opcion: ",opcion,1,8);

    return opcion;
}

void modificarCampo(eEmpleado empleados[], int tam)
{
    int legajo;
    int index;
    float auxSueldo;
    char auxApellido[20];
    int auxNombre[20];
    char auxSexo;
    int auxSector;
    eFecha auxFecha;

    char confirma='n';

    printf("Ingrese legajo del empleado a modificar:\n");
    scanf("%d",&legajo);

    index = buscarEmpleado(empleados,tam,legajo);

    if(index==-1)
    {
        printf("No se encontro el empleado");
    }
    else
    {
        do{
            switch(menuModificacion())
            {
            case 1:
                printf("El apellido actual es: %s\n",empleados[index].apellido);
                getStringLetras("Ingrese nuevo apellido: ",auxApellido);

                printf("Desea modificarlo? s/n \n");
                fflush(stdin);
                confirma= getche();
                if(tolower(confirma)== 's')
                {
                    strcpy(empleados[index].apellido,auxApellido);
                }
                system("pause");
                break;

            case 2:
                printf("El nombre actual es: %s\n",empleados[index].nombre);
                getStringLetras("Ingrese nuevo nombre: ",auxNombre);

                printf("Desea modificarlo? s/n \n");
                fflush(stdin);
                confirma= getche();
                if(tolower(confirma)== 's')
                {
                    strcpy(empleados[index].nombre,auxNombre);
                }
                system("pause");
                break;

            case 3:
                printf("El Sexo actual es: %c\n",empleados[index].sexo);
                getChar("Ingrese nuevo sexo (M/F): ",auxSexo);

                printf("Desea modificarlo? s/n \n");
                fflush(stdin);
                confirma= getche();
                if(tolower(confirma)== 's')
                {
                    empleados[index].sexo = toupper(auxSexo);
                }
                system("pause");
                break;

            case 4:
                printf("El sueldo actual es: %.2f\n",empleados[index].sueldo);
                getFloat("Ingrese nuevo sueldo: ",auxSueldo);
                printf("Desea modificarlo? s/n \n");
                fflush(stdin);
                confirma= getche();
                if(tolower(confirma)== 's')
                {
                    empleados[index].sueldo = auxSueldo;
                }
                system("pause");
                break;

            case 5:
                printf("La fecha de ingreso actual es: %d\n",empleados[index].fechaNacimiento);
                printf("Fecha de nacimiento:");
                scanf("%d",&empleados[index].fechaNacimiento);

                printf("Desea modificarlo? s/n \n");
                fflush(stdin);
                confirma= getche();
                if(tolower(confirma)== 's')
                {
                    empleados[index].fechaNacimiento = auxFecha;
                }
                system("pause");
                break;

            case 6:
                printf("El sector actual es: %s\n",empleados[index].idSector);
                getStringLetras("Ingrese nuevo sector:",auxSector);
                printf("Desea modificarlo? s/n \n");
                fflush(stdin);
                confirma= getche();
                if(tolower(confirma)== 's')
                {
                    empleados[index].idSector = auxSector;
                }
                system("pause");
                break;
            case 7:
                printf("Seguro desea salir? s/n \n");
                fflush(stdin);
                confirma = getch();
                if(tolower(confirma)== 's')
                {
                    confirma = 'n';
                }
                break;

            default:
                printf("Ingrese opcion correcta\n");
                system("pause");
            }
        }while (confirma == 's');
    }
}

int menuModificacion()
{
    int opcion = 0;

    printf("Modificacion\n");
    printf("1.Apellido\n");
    printf("2.Nombre\n");
    printf("2.Sexo\n");
    printf("4.Salario\n");
    printf("5.Fecha de ingreso\n");
    printf("6.Sector\n");
    printf("7.Cancelar\n");

    opcion = getInt("Ingrese Opcion:\n",opcion,1,7);
    return opcion;
}
