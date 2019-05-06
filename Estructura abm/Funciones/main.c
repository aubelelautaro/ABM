#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 10
#define clientes 20

int main()
{
    eProducto listado[clientes];
    eProducto auxProd;

    char auxDescripcion[51];
    int auxCodigo;
    int auxCant;
    float auxPrecio;

    char codigoAuxStr[50];
    char cantAuxStr[50];
    char precioAuxStr[50];

    int indexLugarLibre;
    int indexEncontrado;
    int opcion = 0;

    int i,j;

    while(opcion != 7)
    {
        opcion = getInt("\n1. Alta\n2. Modificar\n3 .Baja\n4. Listar\n5. Informar\n6. Salir\n");
        switch(opcion)
        {

            case 1:
                printf("\nALTA\n");
                indexLugarLibre = buscarLugarLibre(listado,clientes);
                if(indexLugarLibre == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }

                printf("\nALTA\n");

                if (!getStringNumeros("Ingrese el codigo: ",codigoAuxStr))
                {
                    printf ("El codigo debe ser numerico\n");
                    break;
                }
                auxCodigo = atoi(codigoAuxStr);

                if(buscarProductoPorCodigo(listado,clientes,auxCodigo) != -1)
                {
                    printf("\n\nEL CODIGO YA EXISTE!!!\n");
                    break;
                }


                if (!getStringLetras("Ingrese la descripcion: ",auxDescripcion))
                {
                    printf ("La descripcion debe estar compuesta solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingrese la cantidad: ",cantAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                auxCant = atoi(cantAuxStr);

                if (!getStringNumerosFlotantes("Ingrese el valor: ",precioAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                auxPrecio = atof(precioAuxStr);

                listado[indexLugarLibre].codigo = auxCodigo;
                strcpy(listado[indexLugarLibre].descripcion,auxDescripcion);
                listado[indexLugarLibre].precio = auxPrecio;
                listado[indexLugarLibre].cant = auxCant;
                listado[indexLugarLibre].estado = 1;
                break;
            case 2:
                printf("\nMODIFICACION\n");
                if (!getStringNumeros("Ingrese el codigo de producto a modificar: ",codigoAuxStr))
                {
                    printf ("El codigo de producto debe ser numerico\n");
                    break;
                }
                auxCodigo = atoi(codigoAuxStr);
                indexEncontrado = buscarProductoPorCodigo(listado,clientes,auxCodigo);
                if(indexEncontrado == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    break;
                }



               if (!getStringLetras("Ingrese la descripcion: ",auxDescripcion))
                {
                    printf ("La descripcion debe estar compuesta solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingrese la cantidad: ",cantAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                auxCant = atoi(cantAuxStr);

                if (!getStringNumerosFlotantes("Ingrese el valor: ",precioAuxStr))
                {
                    printf ("La cantidad debe ser numerica\n");
                    break;
                }
                auxPrecio = atof(precioAuxStr);

                strcpy(listado[indexEncontrado].descripcion,auxDescripcion);
                listado[indexEncontrado].precio = auxPrecio;
                listado[indexEncontrado].cant = auxCant;
                listado[indexEncontrado].estado = 1;

                break;
            case 3:
                printf("\nBAJA\n");
                if (!getStringNumeros("Ingrese el codigo: ",codigoAuxStr))
                {
                    printf ("El codigo debe ser numerico\n");
                    break;
                }
                indexEncontrado = buscarPrimerOcurrencia(listado,clientes,atoi(codigoAuxStr));

                if(indexEncontrado == -1)
                {
                    printf("\n\nNo se encuentra ese codigo");
                    break;
                }
                listado[indexEncontrado].estado= 0;

                break;
            case 4:
                printf("\nLISTAR\n");
                ordenarPorDescripcion(listado,clientes);
                for(i=0;i < clientes; i++)
                {
                    if(listado[i].estado != 0)
                    {
                        printf("\n%d - %s - %d - %.2f",listado[i].codigo,listado[i].descripcion,listado[i].cant,listado[i].precio);
                    }
                }
                break;
            case 5:
                printf("\nINFORMAR\n");
                auxPrecio = buscarMenorPrecio(listado,clientes);
                if (auxPrecio == -1)
                {
                    printf("\nNo hay productos\n");
                    break;
                }
                for(i=0;i < clientes; i++)
                {
                    if(listado[i].precio == auxPrecio && listado[i].estado == 1)
                    {
                        printf("\nProductos mas baratos: %d - %s - %d - %.2f",listado[i].codigo,listado[i].descripcion,listado[i].cant,listado[i].precio);
                    }
                }
                printf("\nINFORMAR PRODUCTOS POR ENCIMA DEL PROMEDIO\n");
                auxPrecio = promedioPrecio(listado,clientes);
                if(auxPrecio == -1)
                {
                     printf("\nNo hay productos\n");
                     break;
                }
                for(i=0;i < clientes; i++)
                {
                    if(listado[i].precio > auxPrecio && listado[i].estado == 1)
                    {
                        printf("\nProductos por encima del promedio: %d - %s - %d - %.2f",listado[i].codigo,listado[i].descripcion,listado[i].cant,listado[i].precio);
                    }
                }
                break;
            default:
                printf("Opcion incorrecta\n");
                break;
        }
    }
    return 0;
}



/**
{
    ePersona listado[clientes];
    ePersona auxCliente;

    char auxNomStr[50];
    char auxApeStr[50];
    char auxLegStr[50];
    int auxLegajo;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion = 0;

    int i,j;

    inicializarPersona(listado,clientes,-1); //se indica con -1 que esa posicion esta vacia

    while(opcion != 6)
    {
        opcion = getInt("\n1. Alta\n2. Modificar\n3 .Baja\n4. Ordenar\n5. Listar\n6. Salir\n");
        switch(opcion)
        {
            case 1:
                indiceLugarLibre = buscarPrimerOcurrencia(listado,clientes,-1);
                if(indiceLugarLibre == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }
                printf("\nALTA\n");
                if (!getStringLetras("Ingrese el nombre: ",auxNomStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringLetras("Ingrese el apellido: ",auxApeStr))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingrese el legajo: ",auxLegStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }
                auxLegajo = atoi(auxLegStr);

                if(buscarPrimerOcurrencia(listado,clientes,auxLegajo) != -1)
                {
                    printf("\n\nEL LEGAJO YA EXISTE!!!\n");
                    break;
                }


                strcpy(listado[indiceLugarLibre].nombre,auxNomStr);
                strcpy(listado[indiceLugarLibre].apellido,auxApeStr);
                listado[indiceLugarLibre].legajo = auxLegajo;
                break;
            case 2:
                printf("\nMODIFICACION\n");
                if (!getStringNumeros("Ingrese el legajo a modificar: ",auxLegStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }

                indiceResultadoBusqueda = buscarPrimerOcurrencia(listado,clientes,atoi(auxLegStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE LEGAJO\n");
                    break;
                }

                if (!getStringLetras("Ingrese el nombre: ",auxNomStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringLetras("Ingrese el apellido: ",auxApeStr))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }

                strcpy(listado[indiceResultadoBusqueda].nombre,auxNomStr);
                strcpy(listado[indiceResultadoBusqueda].apellido,auxApeStr);

                break;
            case 3:
                printf("\nBAJA\n");
                if (!getStringNumeros("Ingrese el legajo: ",auxLegStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }
                indiceResultadoBusqueda = buscarPrimerOcurrencia(listado,clientes,atoi(auxLegStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNo se encuentra ese legajo");
                    break;
                }
                listado[indiceResultadoBusqueda].legajo= -1;

                break;
            case 4:
                printf("\nORDENAR\n");
                for(i=0; i < clientes - 1; i++)
                {
                    if(listado[i].legajo == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < clientes; j++)
                    {
                        if(listado[j].legajo == -1)
                        {
                            continue;
                        }
                        if(strcmp(listado[i].apellido,listado[j].apellido) > 0)
                        {
                            auxCliente = listado[j];
                            listado[j] = listado[i];
                            listado[i] = auxCliente;
                        }
                    }
                }
                break;
            case 5:
                printf("\nLISTAR\n");
                for(i=0;i < clientes; i++)
                {
                    if(listado[i].legajo != -1)
                    {
                        printf("\n%s %s %d",listado[i].nombre,listado[i].apellido,listado[i].legajo);
                    }
                }
                break;
            case 6:
                printf("\nLISTAR\n");
                for(i=0;i < clientes; i++)
                {
                    if(listado[i].legajo != -1)
                    {
                        printf("\n%s %s %d",listado[i].nombre,listado[i].apellido,listado[i].legajo);
                    }
                }
                break;
            default:
                printf("\nOpcion Incorrecta\n");
                break;
        }
    }
    return 0;
}
*/

/**
    char seguir='s';
    int opcion, retorno;
    char opcionString[2];

    eUsuario listaUsuarios[CANTIDADUSUARIOS];
    eProducto listaProductos[CANTIDADPRODUCTOS];

    eUser_init(listaUsuarios,CANTIDADUSUARIOS);
    eProducto_init(listaProductos,CANTIDADPRODUCTOS);

    while(seguir=='s')
    {
        printf("1- Alta de usuario\n");
        printf("2- Modificar datos de usuario\n");
        printf("3- Baja de usuario\n");
        printf("4- Publicar\n");
        printf("5- Modificar publicacion\n");
        printf("6- Cancelar publicacion\n");
        printf("7- Comprar producto\n");
        printf("8- Listar publicaciones de usuario\n");
        printf("9- Listar publicaciones\n");
        printf("10- Listar usuarios\n");
        printf("11- Salir\n");

        do{
            fflush(stdin);
            scanf("%d",&opcion);
            itoa(opcion, opcionString, 2);
        }while(opcion<1 || opcion>11 || validarNumero(opcionString)==0);

        system("cls");

        switch(opcion)
        {
            case 1:
                {
                  retorno=eUser_alta(listaUsuarios,CANTIDADUSUARIOS);
                  if(retorno!=0)
                  printf("Error, no se pudo hacer la alta del usuario. ");
                  if(retorno<0)
                  printf("No hay mas lugar libre.\n");
                }
                break;
            case 2:
                eUser_modificacion(listaUsuarios,CANTIDADUSUARIOS);
                break;
            case 3:
                eUser_baja(listaUsuarios,CANTIDADUSUARIOS, listaProductos, CANTIDADPRODUCTOS);
                break;
            case 4:
                eProducto_altaPublicacion(listaUsuarios, listaProductos, CANTIDADPRODUCTOS, CANTIDADUSUARIOS);
                break;
            case 5:
                eProducto_modificarPublicacion(listaUsuarios,listaProductos, CANTIDADPRODUCTOS, CANTIDADUSUARIOS);
                break;
            case 6:
                eProducto_cancelarPublicacion(listaUsuarios,listaProductos, CANTIDADPRODUCTOS, CANTIDADUSUARIOS);
                break;
            case 7:
                eProducto_comprarProducto(listaUsuarios,listaProductos, CANTIDADPRODUCTOS, CANTIDADUSUARIOS);
                break;
            case 8:
                eUser_listarPublicacionesUsuario(listaUsuarios,CANTIDADUSUARIOS, listaProductos,CANTIDADPRODUCTOS);
                 break;
            case 9:
                eProducto_mostrarListado(listaProductos,CANTIDADPRODUCTOS);
                break;
            case 10:
                eUser_listarCalificaciones(listaUsuarios,CANTIDADUSUARIOS, listaProductos,CANTIDADPRODUCTOS);
                break;
            case 11:
                seguir = 'n';int eProducto_modificarPublicacion(eUsuario listadoUsuarios[], eProducto listadoProductos[], int largoProductos, int largoUsuarios)
                break;
        }
    }
*/
