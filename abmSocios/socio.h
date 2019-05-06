#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int dia,mes,anio;
} eFecha;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char eMail[31];
    eFecha fechaAsociado;
    int estado;

}eSocio;

typedef struct
{
    int codigo;
    int codigoLibro;
    int codigoSocio;
    eFecha fechaPrestamo;

}ePrestamo;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];

}eAutor;

typedef struct
{
    int codigo;
    char titulo[51];
    int codigoAutor;

}eLibro;

int menu();

int menuModificacion();

void mostrarSocio(eSocio socios,int tam);

void mostrarSocios(eSocio socios[],int tam);

int buscarLibre(eSocio socios[],int tam);

int buscarSocio(eSocio socios[], int tam, int codigo);

void altaSocio(eSocio socios[], int tam);
void listarSocios(eSocio socios[],int tam);
void bajaSocio(eSocio socios[], int tam);
void listarLibros(eLibro libros[],int tam);
void modificarCampo(eSocio socios[], int tam);
void listarAutores(eAutor autores[],int tam);
void initLibros(eLibro libros[], int tam);
void initAutores(eAutor autores[], int tam);
void altaPrestamo(ePrestamo prestamos[], int tam);

#endif // EMPLEADOS_H_INCLUDED

