#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int dia,mes,anio;
}eFecha;

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

int menu();
void eSocio_init(eSocio[],int);
int eSocio_menuModificacion();

void eSocio_mostrarUno(eSocio,int);
int eSocio_mostrarTodos(eSocio[],int);

void eSocio_alta(eSocio[], int);
void eSocio_baja(eSocio[], int);
void eSocio_modificarCampo(eSocio[], int);

int eSocio_buscarLibre(eSocio[],int);
int eSocio_buscar(eSocio[], int, int);
void eSocio_listar(eSocio[],int);
void eSocio_ordenarPorApellido(eSocio[],int);

#endif // EMPLEADOS_H_INCLUDED

