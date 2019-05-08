#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int codigo;
    char nombre[31];
    char apellido[31];
    int estado;
}eAutor;

void eAutor_ordenPorApellido(eAutor[],int);
int eAutor_buscarLibre(eAutor [],int);
int eAutor_listar(eAutor[],int);
void eAutor_mostrarUno(eAutor , int);

int menuAutores();
int eAutor_menuModificacion();

void eAutor_init(eAutor[], int);
int eAutor_buscar(eAutor [], int ,int);

void eAutor_alta(eAutor[], int);
void eAutor_modificacion(eAutor[], int);
void eAutor_baja(eAutor[], int);
int eAutor_siguienteId(eAutor [],int );



#endif // AUTORES_H_INCLUDED
