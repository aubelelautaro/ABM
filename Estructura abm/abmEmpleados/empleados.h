#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int dia,mes,anio;
} eFecha;

typedef struct
{
    char nombre[20];
    char apellido[20];
    char sexo;
    int legajo;
    float sueldo;
    int estado;
    eFecha fechaNacimiento;
    int idSector;

} eEmpleado;

typedef struct
{
    int id;
    char desc[51];

}eSector;

typedef struct
{
    int codigo;
    char desc[51];
    float importe;

}eMenu;

typedef struct
{
    int codigo;
    int idMenu;
    int legajoEmpleado;
    eFecha fecha;

}eAlmuerzo;

int menu();

int menuModificacion();

void inicializarEmpleados(eEmpleado empleados[],int tam);


void mostrarEmpleado(eSector sectores[],int tam,eEmpleado emp);


void mostrarEmpleados(eEmpleado empleados[],int tam,eSector sectores[],int tamSectores);


int buscarLibre(eEmpleado empleados[],int tam);


int buscarEmpleado(eEmpleado empleados[], int tam, int legajo);


void altaEmpleado(eEmpleado empleados[], int tame,eSector sectores[],int tamSectores);


void bajaEmpleado(eEmpleado empleados[], int tam);


void modificarEmpleado(eEmpleado empleados[], int tam);

void modificarCampo(eEmpleado empleados[], int tam);

void ordenarEmpleados(eEmpleado empleados[], int tam);


int obtenerSector(eSector sectores[],int tam, int id,int desc[]);


void mostrarSectoresConEmpleados(eEmpleado empleados[],int tam,eSector sectores[],int tamSectores);


void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSectores);


void initSectores(eSector sectores[], int cant);



#endif // EMPLEADOS_H_INCLUDED
