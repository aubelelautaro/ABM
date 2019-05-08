#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#include "socio.h"
#include "autores.h"
#include "libros.h"
#include "prestamos.h"

#define TAMSOCIOS 4
#define TAMLIBROS 5
#define TAMAUTORES 5
#define TAMPRESTAMOS 10

int main()
{
    char rta = 'S';
    char rtaLibros = 'S';
    char rtaAutores = 'S';
    char rtaModificacion = 'S';
    char confirma;
    char confirmaLib;
    char confirmaAut;

    eSocio listaSocios[TAMSOCIOS] ={
    {1,"AUBELE","LAUTARO",'F',"111-123","ASD@GMAIL.COM",{1,12,1999},1},
    {4,"AUBELE","FEDERICO",'M',"415-123","BBB@GMAIL.COM",{4,6,1949},1},
    {6,"AUBELE","EANDREA",'F',"711-823","CCC@GMAIL.COM",{7,9,1979},1}};

    eLibro listaLibros[TAMLIBROS]={
    {1,"libroUno",2,1},
    {2,"libroDos",3,1},
    {3,"libroTres",1,1},
    {4,"libroCuatro",5,1}
    ,{5,"libroCinco",4,1}};

    eAutor listaAut[TAMAUTORES]={
    {1,"Juan","Lopez",1},
    {2,"Agustin","Lopez",1},
    {3,"BBB","AAA",1},
    {4,"ACC","AA",1},
    {5,"AAlol","Lopez",1}};

    ePrestamo listaPrest[TAMPRESTAMOS] ={
    {1,1,6,{1,12,1999},1},
    {2,1,4,{1,12,1999},1},
    {1,3,1,{1,12,1999},1},
    {2,4,1,{1,12,1999},1},
    {3,4,6,{1,9,1979},0}};

    //eLibro_init(listaLibros,TAMLIBROS);
    //eAutor_init(listaAut,TAMAUTORES);
    //ePrestamo_init(listaPrest,TAMPRESTAMOS);
    //eSocio_init(listaSocios,TAMSOCIOS);

    do
    {
        switch(menu())
        {
        case 'A':
            eSocio_alta(listaSocios,TAMSOCIOS);
            system("pause");
            break;
        case 'B':
            eSocio_modificarCampo(listaSocios,TAMSOCIOS);
            system("pause");
            break;
        case 'C':
            eSocio_baja(listaSocios,TAMSOCIOS);
            system("pause");
            break;
        case 'D':
            eSocio_listar(listaSocios,TAMSOCIOS);
            system("pause");
            break;
        case 'E':
            do
            {
                switch(menuLibros())
                {
                case 'A':
                    eLibro_alta(listaLibros,TAMLIBROS,listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'B':
                    eLibro_modificarCampo(listaLibros,TAMLIBROS,listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'C':
                    eLibro_baja(listaLibros,TAMLIBROS);
                    system("pause");
                    break;
                case 'D':
                    eLibro_listar(listaLibros,TAMLIBROS);
                    system("pause");
                    break;
                case 'E':
                    confirmaLib=getChar("Desea salir (S/N)?: ", confirmaLib);
                    if(toupper(confirmaLib)== 'S')
                    {
                        rtaLibros = 'N';
                    }
                default:
                    printf("Ingrese opcion correcta\n");
                    system("pause");
                }
            }while(rtaLibros == 'S');
            system("pause");
            break;
        case 'F':
            do
            {
                switch(menuAutores())
                {
                case 'A':
                    eAutor_alta(listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'B':
                    eAutor_modificacion(listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'C':
                    eAutor_baja(listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'D':
                    eAutor_listar(listaAut,TAMAUTORES);
                    system("pause");
                    break;
                case 'E':
                    confirmaAut=getChar("Desea salir (S/N)?: ", confirmaAut);
                    if(toupper(confirmaAut)== 'S')
                    {
                        rtaAutores = 'N';
                    }
                    break;
                default:
                    printf("Ingrese opcion correcta\n");
                    system("pause");
                }
            }while(rtaAutores == 'S');
            break;
        case 'G':
            ePrestamo_alta(listaPrest,TAMPRESTAMOS,listaSocios,TAMSOCIOS,listaLibros,TAMLIBROS);
            system("pause");
            break;
        case 'H':
            do
            {
                switch(menuListar())
                {
                case 'A':
                    ePrestamo_listarTotalYPromedio(listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'B':
                    ePrestamo_listarCantidadDiasNoSuperanPromedio(listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'C':
                    eSocio_solicitaronUnLibro(listaSocios,TAMSOCIOS,listaLibros,TAMLIBROS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'D':
                    eLibro_solicitarUnSocio(listaSocios,TAMSOCIOS,listaLibros,TAMLIBROS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'E':
                    //eLibro_menosSolicitado(listaLibros,TAMLIBROS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'F':
                    eSocio_socioConMasPrestamos(listaSocios,TAMSOCIOS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'G':
                    eLibro_fechaDeterminada(listaLibros,TAMLIBROS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'H':
                    eSocio_socioConAlgunPrestamo(listaSocios,TAMSOCIOS,listaPrest,TAMPRESTAMOS);
                    system("pause");
                    break;
                case 'I':
                    eLibro_listar(listaLibros,TAMLIBROS);
                    system("pause");
                    break;
                case 'J':
                    eSocio_listarPorInsercion(listaSocios,TAMSOCIOS);
                    system("pause");
                    break;
                case 'K':
                    confirmaAut=getChar("Desea salir (S/N)?: ", confirmaAut);
                    if(toupper(confirmaAut)== 'S')
                    {
                        rtaModificacion = 'N';
                    }
                    break;
                default:
                    printf("Ingrese opcion correcta\n");
                    system("pause");
                }
            }while(rtaModificacion == 'S');
            break;
        case 'I':
            confirma = getChar("Seguro desea salir del programa?: ",confirma);
            if(toupper(confirma)== 'S')
            {
                rta = 'N';
            }
            break;
        default:
            printf("Ingrese opcion correcta\n");
            system("pause");
        }

    }while(rta == 'S');

    return 0;
}
