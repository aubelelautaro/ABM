#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#include "socio.h"

#define TAM 10
#define TAMLIBROS 5
#define TAMAUTORES 3
#define TAMPRESTAMOS 5
int main()
{
    int rta = 's';
    char confirma;

    eSocio lista[TAM];
    eLibro listaL[TAMLIBROS];
    eAutor listaAut[TAMAUTORES];
    ePrestamo listaPrest[TAMPRESTAMOS];

    initLibros(listaL,TAMLIBROS);
    initAutores(listaAut,TAMAUTORES);
    do
    {
        switch(menu())
        {
        case 'A':
            altaSocio(lista,TAM);
            system("pause");
            break;
        case 'B':
            modificarCampo(lista,TAM);
            break;
        case 'C':
            bajaSocio(lista,TAM);
            system("pause");
            break;
        case 'D':
            listarSocios(lista,TAM);
            system("pause");
            break;
        case 'E':
            listarLibros(listaL,TAMLIBROS);
            system("pause");
            break;
        case 'F':
            listarAutores(listaAut,TAMAUTORES);
            system("pause");
            break;
        case 'G':
            altaPrestamo(listaPrest,TAMPRESTAMOS);
            system("pause");
            break;
        case 'H':
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

    }while(rta == 's');

    return 0;
}

int menu()
{
    char opcion = '.';

    system("cls");
    printf("A.Alta\n");
    printf("B.Modificar\n");
    printf("C.Baja\n");
    printf("D.Listar socios por Apellido\n");
    printf("E.Listar libros\n");
    printf("F.Listar autores\n");
    printf("G.Alta prestamo\n");
    printf("H.Salir\n");

    opcion=getChar("Elija una opcion: ",opcion);
    opcion = toupper(opcion);

    return opcion;
}

void modificarCampo(eSocio socios[], int tam)
{
    int codigo;
    int index;
    char auxApellido[31];
    int auxNombre[31];
    char auxSexo;
    char auxTelefono[16];
    char auxMail[31];

    char confirma='n';

    printf("Ingrese codigo del socio a modificar:\n");
    scanf("%d",&codigo);

    index = buscarSocio(socios,tam,codigo);

    if(index==-1)
    {
        printf("No se encontro el socio");
    }
    else
    {
        do{
            switch(menuModificacion())
            {
            case 1:
                printf("El apellido actual es: %s\n",socios[index].apellido);
                getStringLetras("Ingrese nuevo apellido: ",auxApellido);

                printf("Desea modificarlo? s/n \n");
                fflush(stdin);
                confirma= getche();
                if(tolower(confirma)== 's')
                {
                    strcpy(socios[index].apellido,auxApellido);
                }
                system("pause");
                break;

            case 2:
                printf("El nombre actual es: %s\n",socios[index].nombre);
                getStringLetras("Ingrese nuevo nombre: ",auxNombre);

                printf("Desea modificarlo? s/n \n");
                fflush(stdin);
                confirma= getche();
                if(tolower(confirma)== 's')
                {
                    strcpy(socios[index].nombre,auxNombre);
                }
                system("pause");
                break;

            case 3:
                printf("El Sexo actual es: %c\n",socios[index].sexo);
                getChar("Ingrese nuevo sexo (M/F): ",auxSexo);

                printf("Desea modificarlo? s/n \n");
                fflush(stdin);
                confirma= getche();
                if(tolower(confirma)== 's')
                {
                    socios[index].sexo = toupper(auxSexo);
                }
                system("pause");
                break;

            case 4:
                printf("El telefono actual es: %s\n",socios[index].telefono);
                getStringLetras("Ingrese nuevo telefono: ",auxTelefono);
                if(!esTelefono(auxTelefono))
                {
                    printf("Ingrese un telefono valido\n");
                }else
                {
                    printf("Desea modificarlo? s/n \n");
                    fflush(stdin);
                    confirma= getche();
                    if(tolower(confirma)== 's')
                    {
                        strcpy(socios[index].telefono,auxTelefono);
                    }
                }
                system("pause");
                break;

            case 5:
                printf("El eMail actual es: %s\n",socios[index].eMail);
                getStringLetras("Ingrese nuevo eMail: ",auxMail);
                if(!esMail(auxMail))
                {
                    printf("Ingrese un eMail valido\n");
                }else
                {
                    printf("Desea modificarlo? s/n \n");
                    fflush(stdin);
                    confirma= getche();
                    if(tolower(confirma)== 's')
                    {
                        strcpy(socios[index].eMail,auxMail);
                    }
                }
                system("pause");
                break;
            case 6:
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
    printf("4.Telefono\n");
    printf("5.eMail\n");
    printf("6.Cancelar\n");

    opcion = getInt("Ingrese Opcion:\n",opcion,1,6);
    return opcion;
}
