#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED
#include "autores.h"

typedef struct
{
    int codigo;
    char titulo[51];
    int codigoAutor;
    int estado;
}eLibro;

int menuLibros();
int eLibro_listar(eLibro[],int);
void eLibro_init(eLibro[], int);
int eLibro_buscarLibre(eLibro[],int);
void eLibro_alta(eLibro[], int, eAutor [], int);
void eLibro_baja(eLibro[], int);
int eLibro_siguienteId(eLibro [],int );

void eLibro_mostrarUno(eLibro,int);
int eLibro_buscar(eLibro[], int,int);
void eLibro_ordenPorTitulo(eLibro[],int);
void eLibro_mostrarConAutor(eLibro[],int,eAutor[],int);

int eLibro_menuModificacion();
void eLibro_modificarCampo(eLibro [], int,eAutor [],int);


#endif // LIBROS_H_INCLUDED
