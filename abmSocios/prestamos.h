#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED
#include "socio.h"

typedef struct
{
    int codigo;
    int codigoLibro;
    int codigoSocio;
    eFecha fechaPrestamo;
    int estado;
}ePrestamo;

void ePrestamo_init(ePrestamo[],int);
void ePrestamo_alta(ePrestamo[],int,eSocio[],int,eLibro[], int);
int ePrestamo_buscarLibre(ePrestamo[],int);
int ePrestamo_buscar(ePrestamo[],int,int);
int ePrestamo_siguienteId(ePrestamo [],int);

int ePrestamo_totalGeneral(ePrestamo [], int );
int ePrestamo_promedioDiario(ePrestamo [], int );

#endif // PRESTAMOS_H_INCLUDED
