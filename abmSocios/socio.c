#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "libros.h"
#include "prestamos.h"
#include "autores.h"
#include "socio.h"

void eSocio_init(eSocio socios[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        socios[i].codigo = 0;
        socios[i].estado = 0;
    }
}


void eSocio_mostrarUno(eSocio socios, int tam)
{
    if(socios.estado == 1)
    {
        printf("%d  %s %s  %c   %s    %s  %d/%d/%d\n",socios.codigo,socios.apellido,socios.nombre,socios.sexo,socios.telefono,socios.eMail,socios.fechaAsociado.dia,socios.fechaAsociado.mes,socios.fechaAsociado.anio);
    }
}

int eSocio_mostrarTodos(eSocio socios[], int tam)
{
    int flag =0;

    printf("CODIGO  APELLIDO\t   NOMBRE     SEXO TELEFONO \t EMAIL\tFECHA ASOCIADO\n");
    for(int i=0; i<tam; i++)
    {
        if(socios[i].estado == 1)
        {
            eSocio_mostrarUno(socios[i],tam);
            flag =1;
        }
    }
    if(flag ==0)
    {
        printf("NO HAY SOCIOS");
    }
    return flag;
}

int eSocio_buscarLibre(eSocio socios[],int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if (socios[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int eSocio_buscar(eSocio socios[], int tam, int codigo)
{
    int index = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(socios[i].codigo == codigo && socios[i].estado ==1)
        {
            index=i;
            break;
        }
    }

    return index;
}

int eSocio_siguienteId(eSocio socios[],int tam)
{
    int retorno = 0;
    int i;

        for(i=0; i<tam; i++)
        {
            if(socios[i].codigo>retorno)
            {
                 retorno=socios[i].codigo;
            }
        }

    return retorno+1;
}

void eSocio_alta(eSocio socios[], int tam)
{
    int index;
    int auxCodigo;
    int validar,dia,mes,anio;
    char auxDia[3],auxMes[3],auxAnio[5];
    char auxNombre[31];
    char auxApellido[31];
    char auxSexo;
    char auxTelefono[16];
    char auxMail[31];

    index = eSocio_buscarLibre(socios, tam);

    if(index == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        auxCodigo = eSocio_siguienteId(socios,tam);
        printf("Codigo de socio: %d\n",auxCodigo);

        validar = getStringLetras("Ingrese apellido: ",auxApellido);
        while(validar == 0)
        {
            validar = getStringLetras("ERROR, ingrese solo letras: ",auxApellido);
        }
        strcpy(socios[index].apellido,auxApellido);

        validar = getStringLetras("Ingrese nombre: ",auxNombre);
        while(validar == 0)
        {
            validar = getStringLetras("ERROR, ingrese solo letras: ",auxNombre);
        }
        strcpy(socios[index].nombre,auxNombre);

        auxSexo = getChar("Ingrese sexo (M/F):", auxSexo);
        auxSexo = toupper(auxSexo);
        while((auxSexo!= 'F') && (auxSexo!= 'M'))
        {
            auxSexo = getChar("\nError, ingrese F o M solamente",auxSexo);
            auxSexo = toupper(auxSexo);
        }
        socios[index].sexo = auxSexo;

        getStringTelefono("\nIngrese telefono: ",auxTelefono);
        while(!esTelefono(auxTelefono))
        {
            printf("Ingrese un telefono valido (1234-5678): ");
            fflush(stdin);
            gets(auxTelefono);
        }
        strcpy(socios[index].telefono,auxTelefono);

        getStringMail("Ingrese mail: ",auxMail);
        while(!esMail(auxMail))
        {
            printf("Ingrese un mail valido (asd.123@xxxxx.com) :");
            fflush(stdin);
            gets(auxMail);
        }
        strcpy(socios[index].eMail,auxMail);

        do
        {
            getStringNumeros("Ingrese dia entre 1 y 31: ",auxDia);
            dia =atoi(auxDia);
        }while(dia>31 || dia <1);
        socios[index].fechaAsociado.dia = dia;

        do
        {
            getStringNumeros("Ingrese mes entre 1 y 12: ",auxMes);
            mes =atoi(auxMes);
        }while(mes>12 || mes <1);
        socios[index].fechaAsociado.mes = mes;

        do
        {
            getStringNumeros("Ingrese anio entre 1900 y 2020: ",auxAnio);
            anio =atoi(auxAnio);
        }while(anio>2020 || anio <1900);
        socios[index].fechaAsociado.anio = anio;
        socios[index].estado = 1;
        socios[index].codigo = auxCodigo;
        auxCodigo++;
        printf("ALTA EXITOSA!\n\n");
    }
}

void eSocio_baja(eSocio socios[], int tam)
{
    int index;
    int codigo;
    char confirma;
    int retorno = eSocio_mostrarTodos(socios,tam);
    if(retorno==0)
    {
        printf(" PARA DAR DE BAJA\n");
    }
    else
    {
        printf("Ingrese codigo: ");
        scanf("%d", &codigo);
        index = eSocio_buscar(socios,tam,codigo);

        if(index== -1)
        {
            printf("No se encontro al socio\n");
        }
        else
        {
            confirma = getChar("Desea dar de baja el socio? (S/N): ", confirma);
            confirma = toupper(confirma);
            while((confirma!= 'S') && (confirma!= 'N'))
            {
                confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                confirma = toupper(confirma);
            }
            if(confirma=='S')
            {
                socios[index].estado =0;
                printf("Baja exitosa!\n");
            }
            else
            {
                printf("No se dio de baja al socio.\n");
            }
        }
    }
}

void eSocio_listar(eSocio socios[],int tam)
{
    eSocio_ordenarPorApellido(socios,tam);
    eSocio_mostrarTodos(socios,tam);
}

void eSocio_ordenarPorApellido(eSocio socios[],int tam)
{
    int i,j;
    eSocio aux;

    for(i=0;i<tam-1;i++)
    {

        for(j=i+1;j<tam;j++)
        {
            if(strcmp(socios[j].apellido,socios[i].apellido)>0)
            {
                aux = socios[j];
                socios[j]= socios[i];
                socios[i]= aux;
            }
            else if(strcmp(socios[i].apellido,socios[j].apellido) == 0)
            {
                if(strcmp(socios[i].nombre,socios[j].nombre)>0)
                {
                    aux = socios[j];
                    socios[j]= socios[i];
                    socios[i]= aux;
                }
            }
        }
    }
}

int eSocio_menuModificacion()
{
    char opcion = '0';

    printf("\n----Modificacion----\n");
    printf("1.Apellido\n");
    printf("2.Nombre\n");
    printf("3.Sexo\n");
    printf("4.Telefono\n");
    printf("5.eMail\n");
    printf("6.Cancelar\n");

    opcion = getOpcion("\nIngrese opcion entre 1 y 6: ", opcion,'1','6');
    return opcion;
}

void eSocio_modificarCampo(eSocio socios[], int tam)
{
    int codigo;
    int index;
    int validar;
    char auxApellido[31];
    char auxNombre[31];
    char auxSexo;
    char auxTelefono[16];
    char auxMail[31];
    int retorno = eSocio_mostrarTodos(socios,tam);
    char confirma='N';
    if(retorno==0)
    {
        printf(" PARA MODIFICAR");
    }else
    {
        printf("Ingrese codigo del socio a modificar: ");
        scanf("%d",&codigo);
        index = eSocio_buscar(socios,tam,codigo);
        if(index==-1)
        {
            printf("No se encontro el socio\n");
        }else{
            do{
                switch(eSocio_menuModificacion())
                {
                case '1':
                    printf("El apellido actual es: %s\n",socios[index].apellido);
                    validar = getStringLetras("Ingrese nuevo apellido: ",auxApellido);
                    while(validar == 0)
                    {
                        validar = getStringLetras("ERROR, ingrese solo letras: ",auxApellido);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(socios[index].apellido,auxApellido);
                    }
                    system("pause");
                    break;

                case '2':
                    printf("El nombre actual es: %s\n",socios[index].nombre);
                    validar = getStringLetras("Ingrese nuevo nombre: ",auxNombre);
                    while(validar == 0)
                    {
                        validar = getStringLetras("ERROR, ingrese solo letras: ",auxNombre);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(socios[index].nombre,auxNombre);
                    }
                    system("pause");
                    break;

                case '3':
                    printf("El Sexo actual es: %c\n",socios[index].sexo);

                    auxSexo = getChar("Ingrese sexo (M/F):", auxSexo);
                    auxSexo = toupper(auxSexo);
                    while((auxSexo!= 'F') && (auxSexo!= 'M'))
                    {
                        auxSexo = getChar("\nError, ingrese F o M solamente: ",auxSexo);
                        auxSexo = toupper(auxSexo);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                       socios[index].sexo = auxSexo;
                    }
                    system("pause");
                    break;

                case '4':
                    printf("El telefono actual es: %s\n",socios[index].telefono);
                    validar = getStringTelefono("Ingrese nuevo telefono: ",auxTelefono);
                    while(validar == 0)
                    {
                        validar = getStringTelefono("ERROR, ingrese solo Telefono (4xxx-xxxx): ",auxTelefono);
                    }

                    confirma = getChar("\nSeguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("Error, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(socios[index].telefono,auxTelefono);
                    }
                    system("pause");
                    break;

                case '5':
                    printf("El eMail actual es: %s\n",socios[index].eMail);
                    validar = getStringMail("Ingrese nuevo eMail: ",auxMail);
                    while(validar == 0)
                    {
                        validar = getStringMail("ERROR, ingrese mail valido (asda@xxxx.com): ",auxMail);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S): ", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(socios[index].eMail,auxMail);
                    }
                    system("pause");
                    break;
                case '6':
                    confirma = getChar("Seguro quiere salir? (N/S): ", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        confirma = 'N';
                    }
                    break;

                default:
                    printf("Ingrese opcion correcta \n");
                    system("pause");
                }
            }while (confirma == 'S');
        }
    }
}

int menu()
{
    char opcion = '.';

    printf("\n----MENU----\n");
    printf("A.Alta\n");
    printf("B.Modificar\n");
    printf("C.Baja\n");
    printf("D.Listar socios por Apellido\n");
    printf("E.Menu libros\n");
    printf("F.Menu autores\n");
    printf("G.Alta prestamo\n");
    printf("H.Salir\n");

    opcion=getChar("Elija una opcion: \n",opcion);
    opcion = toupper(opcion);

    return opcion;
}
