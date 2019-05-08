int mostrarProductoBuscarProv( eProductos prodVar, eProveedores provs[], int provTam)
{
    int i;
    int verify = 0;
    for( i = 0 ; i < provTam ; i++)
    {
        if( provs[i].estado == OCUPADO && provs[i].codigoProveedor == prodVar.codigoProveedor)
        {
            xlkSortPrintf(3,"%s,%d,%s,%f,%d",5,provs[i].descripcion,prodVar.codigoProduto,prodVar.descripcion, prodVar.importe, prodVar.cantidad);
            verify = 1;
        }
    }
    return verify;
}

void prodMostrarImportesMenoresAlPromedio(eProductos prod[], int prodTam, eProveedores prov[], int provTam)
{
    system("cls");
    float promedio ;
    float acumulador = 0;
    int contador = 0;
    int contadorProdsMenosPromedio = 0;
    int i;
    int flag = 0;

    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].estado == 1)
        {
            acumulador += prod[i].importe ;
            contador++;
        }
    }
    promedio = acumulador / contador ;

    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].importe < promedio)
        {
            contadorProdsMenosPromedio++;
            flag = 1;
        }
    }
    if( !flag )
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        xlkCenterPrintf("DATOS DE IMPORTES",1);
        xlkSortPrintf(1,"%s,%s",2,"SUMA DE IMPORTES:","PROMEDIO DE IMPORTES:");
        xlkSortPrintf(3,"%f,%f",2,acumulador,promedio);
        printf("\n* Hay %d productos que no superan el promedio de importes.\n\n",contadorProdsMenosPromedio);
    }

}

void prodMostrarStocksMayor10(eProductos prod[], int prodTam, eProveedores prov[], int provTam)
{
    system("cls");
    int contadorStock = 0;
    int i;
    xlkCenterPrintf("INFORME DEL STOCK DE PRODUCTOS",2);
    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].cantidad > 10)
        {
            contadorStock++;
        }
    }
    printf("\n* Hay %d productos con stock mayor a 10.\n\n",contadorStock);
}


//FUNCIONES MENU LISTAR:

void ListarProdsCantMenorIgualA10(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int i;
    int flag = 0;

    xlkCenterPrintf("PRODUCTOS CON STOCK MENOR O IGUAL A 10",1);
    xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");
    for (i = 0 ; i < prodTam ; i++)
    {
        if( prod[i].estado == OCUPADO && prod[i].cantidad <= 10)
        {
            flag = 1;
            mostrarProductoBuscarProv(prod[i],prov,provTam);
        }
    }
    if(!flag )
    {
        system("cls");
        printf("** No hay productos que cumplan lo solicitado.\n\n");
    }

}

void ListarProdsImportesMayoresAlPromedio(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    float promedio ;
    float acumulador = 0;
    int contador = 0;
    int i;
    int flag = 0;

    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].estado == OCUPADO)
        {
            acumulador += prod[i].importe ;
            contador++;
            flag = 1;
        }
    }
    if( !flag)
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        flag = 0;
        promedio = acumulador / contador ;
        xlkCenterPrintf("DATOS DE IMPORTES",1);
        xlkSortPrintf(1,"%s,%s",2,"SUMA DE IMPORTES:","PROMEDIO DE IMPORTES:");
        xlkSortPrintf(3,"%f,%f",2,acumulador,promedio);
        printf("\n");
        xlkCenterPrintf("PRODUCTOS QUE SUPERAN EL PROMEDIO DE LOS IMPORTES:",1);
        xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");

        for (i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].importe > promedio )
            {
                flag = 1;
                mostrarProductoBuscarProv(prod[i],prov,provTam);
            }
        }
        if(!flag)
        {
            system("cls");
            printf("**No hay productos que cumplan lo solicitado.\n\n");
        }
    }

}

void ListarProdsImportesMenoresAlPromedio(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    float promedio ;
    float acumulador = 0;
    int contador = 0;
    int i;
    int flag = 0;

    for(i = 0 ; i < prodTam ; i++ )
    {
        if( prod[i].estado == OCUPADO)
        {
            acumulador += prod[i].importe ;
            contador++;
            flag = 1;
        }
    }
    if( !flag)
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        flag = 0;
        promedio = acumulador / contador ;
        xlkCenterPrintf("DATOS DE IMPORTES",1);
        xlkSortPrintf(1,"%s,%s",2,"SUMA DE IMPORTES:","PROMEDIO DE IMPORTES:");
        xlkSortPrintf(3,"%f,%f",2,acumulador,promedio);
        printf("\n");
        xlkCenterPrintf("PRODUCTOS QUE NO SUPERAN EL PROMEDIO DE LOS IMPORTES:",1);
        xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","CODIGO DE PRODUCTO:","DESCRICPION:","IMPORTE:","CANTIDAD:");
        for (i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].importe < promedio)
            {
                flag = 1;
                mostrarProductoBuscarProv(prod[i],prov,provTam);
            }
        }
         if(!flag)
        {
            system("cls");
            printf("**No hay productos que cumplan lo solicitado.\n\n");
        }
    }
}

void ListarProvsCantidadProdMenorIgualA10(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int i;
    int j;
    int flag = 0;
    int acumulador = 0;
    xlkCenterPrintf("PROVEEDORES CON 10 O MENOS PRODUCTOS EN EL SISTEMA",1);
    for( i = 0 ; i < provTam ; i++)
    {
        if( prov[i].estado == OCUPADO )
        {
            for( j = 0 ; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor )
                {
                    acumulador += prod[j].cantidad;
                }
                if( j == (prodTam - 1) )
                {
                    if( acumulador <= 10 && prov[i].codigoProveedor > 0)
                    {
                        flag = 1;
                        xlkSortPrintf(1,"%s,%s,%s",3,"PROVEEDOR:","CANTIDAD DE PRODUCTOS QUE PROVEE:","ID DE PROVEEDOR:");
                        xlkSortPrintf(3,"%s,%d,%d",3,prov[i].descripcion,acumulador,prov[i].codigoProveedor);
                    }
                    acumulador = 0;
                }
            }
        }
    }
    if( flag == 0)
    {
        system("cls");
        printf("** No hay proveedores que provean 10 o menos productos.\n\n");
    }
}

void ListarProductorPorProveedor(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int i;
    int j;
    int flag = 0;
    int flag2 = 0; //Revisa si se leyo algun producto.

    xlkCenterPrintf("LISTADO DE PRODUCTOS",1);
    for(i = 0 ; i < provTam; i++)
    {
        if(prov[i].estado == OCUPADO)
        {
            for(j = 0; j < prodTam ; j++)
            {
                if(prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor && prov[i].codigoProveedor > 0)
                {
                    flag2=1;
                    if( flag == 0)
                    {
                        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR--->",prov[i].descripcion);
                        xlkSortPrintf(1,"%s,%s,%s,%s",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");
                        flag=1;
                    }
                    mostrarProducto(prod[j],prov[i]);
                }

            }
            flag = 0;
        }
    }
    if(!flag2 )
    {
        system("cls");
        printf("** No hay productos cargados o no se registro un proveedor.\n\n");
    }
}

void ListarProductosDeUnProveedor(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    int buscarCodigo;
    int provIndex;
    int i;
    int flag = 0;

    if( mostrarProveedores(prov,provTam) )
    {
        if( getConditionedInt(&buscarCodigo,1,1,"\n* Ingrese el codigo de proveedor para mostrar sus productos: ","\n** El codigo de proveedor es invalido.\n\n") )
        {
            if( ( provIndex = buscarProveedor(prov,provTam,buscarCodigo)) > -1 )
            {
                system("cls");
                xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR--->",prov[provIndex].descripcion);
                xlkSortPrintf(1,"%s,%s,%s,%a",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

                for( i = 0; i < prodTam ; i++ )
                {
                    if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor )
                    {
                        mostrarProducto(prod[i], prov[provIndex]);
                        flag = 1;
                    }
                }
                if(flag == 0)
                {
                    system("cls");
                    printf("** El proveedor no provee ningun producto.\n\n");
                }
            }
            else
            {
                printf("\n** No se pudo encontrar el proveedor especificado.\n\n");
            }
        }
    }
    else
    {
        system("cls");
        printf("** No hay proveedores cargados.\n\n");
    }
}

void ListarProveedorMasProductos(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    int i;
    int j;
    int flag = 0;

    int cantidadProductos1 = 0;
    int cantidadProductos2;
    int provIndex = -1;

    system("cls");
    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor)
                {
                    cantidadProductos1++;
                }
                if( (j == (prodTam - 1) && flag == 0) || (j == (prodTam -1) && cantidadProductos1 > cantidadProductos2 ))
                {
                    flag = 1;
                    cantidadProductos2 = cantidadProductos1;
                    if( cantidadProductos2 > 0)
                    {
                        provIndex = i;
                    }
                }
                if( j == prodTam - 1)
                {
                    cantidadProductos1 = 0;
                }
            }
        }
    }
    if(provIndex > -1 && prov[provIndex].codigoProveedor > 0 )
    {
        xlkCenterPrintf("PROVEEDOR QUE PROVEE MAS PRODUCTOS Y SUS PRODUCTOS",1);
        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR--->",prov[provIndex].descripcion);
        xlkSortPrintf(1,"%s,%s,%s,%s,%s",5,"PROVEEDOR:","DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

        for( i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor)
            {
                mostrarProducto(prod[i], prov[provIndex]);
            }
        }
    }
    else
    {
        system("cls");
        printf("** No hay productos que esten asociados a algun proveedor.\n\n");
    }
}

void ListarProveedorMenosProductos(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    int i;
    int j;
    int flag = 0;

    int cantidadProductos1 = 0;
    int cantidadProductos2 = 0;
    int provIndex;

    system("cls");
    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor)
                {
                    cantidadProductos1++;
                }
                if( (j == (prodTam - 1) && flag == 0) || (j == (prodTam -1) && cantidadProductos1 < cantidadProductos2 ))
                {
                    if( cantidadProductos1 > 0)
                    {
                        flag = 1;
                        cantidadProductos2 = cantidadProductos1;
                        provIndex = i;
                        cantidadProductos1 = 0;
                    }
                }
                if( j == prodTam - 1)
                {
                    cantidadProductos1 = 0;
                }

            }
        }
    }
    if(cantidadProductos2 > 0 && prov[provIndex].codigoProveedor > 0 )
    {
        xlkCenterPrintf("PROVEEDOR QUE PROVEE MENOS PRODUCTOS Y SUS PRODUCTOS",1);
        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR--->",prov[provIndex].descripcion);
        xlkSortPrintf(1,"%s,%s,%s,%s",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");
        for( i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor)
            {
                mostrarProducto(prod[i], prov[provIndex]);
            }
        }
    }
    else
    {
        printf("** Los proveedores cargados no proveen ningun producto.\n\n");
    }
}

void ListarProveedorProductoMasCaro(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    float importeMasAlto = -1;
    int provIndex;
    int flag = 0;
    int flag2 = 0; //Verifica si leyo algun dato.
    int i;
    int j;

    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor && prod[j].codigoProveedor)
                {
                    flag2 = 1;
                    if( flag == 0)
                    {
                        importeMasAlto = prod[j].importe;
                        provIndex = i;
                        flag = 1;
                    }
                    if( prod[j].importe > importeMasAlto)
                    {
                        importeMasAlto = prod[j].importe;
                        provIndex = i;
                    }
                }

            }
        }
    }
    if( !flag2 )
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        xlkCenterPrintf("PROVEEDOR QUE PROVEE PRODUCTO MAS CARO",1);
        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR->",prov[provIndex].descripcion);
        xlkSortPrintf(1,"%s,%s,%s,%s",4,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");

        for(i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor && prov[provIndex].codigoProveedor > 0)
            {
                xlkSortPrintf(3,"%s,%d,%f,%d",4,prod[i].descripcion,prod[i].codigoProduto,prod[i].importe, prod[i].cantidad);
            }
        }
    }
}


void ListarProveedorProductoMasBarato(eProductos prod[], int prodTam,eProveedores prov[], int provTam)
{
    system("cls");
    float importeMasBajo = -1;
    int provIndex;
    int flag = 0;
    int flag2 = 0; //Verifica si se leyo algun dato.
    int i;
    int j;


    for(i = 0 ; i < provTam ; i++ )
    {
        if( prov[i].estado == OCUPADO)
        {
            for( j = 0; j < prodTam ; j++)
            {
                if( prod[j].estado == OCUPADO && prod[j].codigoProveedor == prov[i].codigoProveedor && prod[j].codigoProveedor > 0 )
                {
                    flag2 = 1;
                    if( flag == 0)
                    {
                        importeMasBajo = prod[j].importe;
                        provIndex = i;

                        flag = 1;
                    }
                    if( prod[j].importe < importeMasBajo)
                    {
                        importeMasBajo = prod[j].importe;
                        provIndex = i;
                    }
                }

            }
        }
    }
    if( !flag2 )
    {
        printf("** No hay productos cargados en el sistema.\n\n");
    }
    else
    {
        xlkCenterPrintf("PROVEEDOR QUE PROVEE PRODUCTO MAS BARATO",1);
        xlkSortPrintf(1,"%s,%s",2,"PRODUCTOS DEL PROVEEDOR--->",prov[provIndex].descripcion);
        xlkSortPrintf(1,"%s,%s,%s,%s",3,"DESCRICPION:","CODIGO DE PRODUCTO:","IMPORTE:","CANTIDAD:");
        for(i = 0 ; i < prodTam ; i++)
        {
            if( prod[i].estado == OCUPADO && prod[i].codigoProveedor == prov[provIndex].codigoProveedor && prov[provIndex].codigoProveedor > 0)
            {
                xlkSortPrintf(3,"%s,%d,%f,%d",3,prod[i].descripcion,prod[i].codigoProduto,prod[i].importe, prod[i].cantidad);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void eAuto_mostrarEgresos(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios)
{
    int i, j;
    char marca[20];

    printf("Nombre propietario    Patente     Marca           Valor de estadia\n");

    for(i=0;i<largoAutos;i++)
    {
        if(listadoAutos[i].estado==EGRESADO)
        {

            for(j=0;j<largoPropietarios;j++)
            {
                if(listadoAutos[i].idPropietario==listadoPropietarios[j].idPropietario)
                {
                   break;
                }
            }

        if(listadoAutos[i].marca==1)
        {
            strcpy(marca,"ALPHA_ROMEO");
        }

        if(listadoAutos[i].marca==2)
        {
            strcpy(marca,"FERRARI    ");
        }

        if(listadoAutos[i].marca==3)
        {
            strcpy(marca,"AUDI       ");
        }

        if(listadoAutos[i].marca==4)
        {
            strcpy(marca,"OTROS      ");
        }

        printf("%s                   %s        %s       %.2f\n", listadoPropietarios[j].nombreApellido, listadoAutos[i].patente, marca, listadoAutos[i].importe);

        }

    }

}

void eAuto_recaudacionTotal(eAuto listadoAutos[], int largoAutos)
{
    int i;
    float acumuladorImportes=0;

    for(i=0;i<largoAutos;i++)
    {
        acumuladorImportes+=listadoAutos[i].importe;
    }

    printf("La recaudacion total del estacionamiento es de: %.2f\n", acumuladorImportes);
}

void eAuto_recaudacionPorMarca(eAuto listadoAutos[], int largoAutos)
{
    int i;
    float acumuladorAlpha=0, acumuladorFerrari=0, acumuladorAudi=0, acumuladorOtros=0;

    for(i=0;i<largoAutos;i++)
    {
        if(listadoAutos[i].marca==1)
        {
             acumuladorAlpha+=listadoAutos[i].importe;
        }

        if(listadoAutos[i].marca==2)
        {
            acumuladorFerrari+=listadoAutos[i].importe;
        }

        if(listadoAutos[i].marca==3)
        {
            acumuladorAudi+=listadoAutos[i].importe;
        }

        if(listadoAutos[i].marca==4)
        {
            acumuladorOtros+=listadoAutos[i].importe;
        }
    }

    printf("Recaudacion total Alpha Romeo: %.2f\nRecaudacion total Ferrari: %.2f\nRecaudacion total Audi: %.2f\nRecaudacion total Otros: %.2f\n",acumuladorAlpha,acumuladorFerrari,acumuladorAudi,acumuladorOtros);
}

void eAuto_buscarPorIdPropietario(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios)
{
    int id, indicePropietario, i;
    char marca[20];

    ePropietario_mostrarListado(listadoPropietarios,largoPropietarios);

    printf("Ingrese ID del propietario: ");
    scanf("%d", &id);

    indicePropietario=ePropietario_buscarPorId(listadoPropietarios,largoPropietarios, id);

    if(indicePropietario>=0)
    {
        printf("Nombre propietario          Patente          Marca\n");

       for(i=0;i<largoAutos;i++)
        {
            if(listadoPropietarios[indicePropietario].idPropietario==listadoAutos[i].idPropietario && listadoAutos[i].estado==OCUPADO)
            {
                if(listadoAutos[i].marca==1)
                    {
                        strcpy(marca,"ALPHA_ROMEO");
                    }

                if(listadoAutos[i].marca==2)
                    {
                        strcpy(marca,"FERRARI    ");
                    }

                if(listadoAutos[i].marca==3)
                    {
                        strcpy(marca,"AUDI       ");
                    }

                if(listadoAutos[i].marca==4)
                    {
                        strcpy(marca,"OTROS      ");
                    }
                printf("%s                          %s          %s\n", listadoPropietarios[indicePropietario].nombreApellido, listadoAutos[i].patente, marca);
            }
        }
    }
    else
        printf("El propietario ingresado no existe.\n");
}

void eAuto_datosAudi(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios)
{
    int i, j;

    printf("ID prop.      ID auto      Nombre          Direccion          Tarjeta\n");

    for(i=0;i<largoAutos;i++)
    {
        if(listadoAutos[i].marca==3 && listadoAutos[i].estado==OCUPADO)
        {
            for(j=0;j<largoPropietarios;j++)
            {
                if(listadoAutos[i].idPropietario == listadoPropietarios[j].idPropietario)
                {
                   printf("\%d             %d             %s             %s             %s \n",listadoPropietarios[j].idPropietario,listadoAutos[i].idAuto,listadoPropietarios[j].nombreApellido,listadoPropietarios[j].direccion,listadoPropietarios[j].tarjetaCredito);
                }
            }
        }
    }
}

void eAuto_estacionadosPorPatente(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios)
{
    int i,j,k, ultimoOcupado, auxi, indicePropietario,idProp;
    char aux[50], marca[20], variableNombre[20][100], direccion[20][100];

    printf("Patente    ID Auto          Marca              ID Prop           Nombre prop.          Direccion \n");

    ultimoOcupado=eAuto_buscarLugarLibre(listadoAutos,largoAutos);
    if(ultimoOcupado==-2)
    ultimoOcupado=20;

    for(i=0;i<ultimoOcupado-1;i++)
    {
        for(j=i+1;j<ultimoOcupado;j++)
        {
            if(stricmp(listadoAutos[j].patente,listadoAutos[i].patente)==-1)
            {
                strcpy(aux, listadoAutos[j].patente);
                strcpy(listadoAutos[j].patente, listadoAutos[i].patente);
                strcpy(listadoAutos[i].patente, aux);

                auxi=listadoAutos[j].marca;
                listadoAutos[j].marca=listadoAutos[i].marca;
                listadoAutos[i].marca=auxi;

                auxi=listadoAutos[j].idAuto;
                listadoAutos[j].idAuto=listadoAutos[i].idAuto;
                listadoAutos[i].idAuto=auxi;

                auxi=listadoAutos[j].idPropietario;
                listadoAutos[j].idPropietario=listadoAutos[i].idPropietario;
                listadoAutos[i].idPropietario=auxi;
            }
        }
    }

    for(i=0;i<ultimoOcupado;i++)
    {
        indicePropietario=ePropietario_buscarPorId(listadoPropietarios,largoPropietarios, listadoAutos[i].idPropietario);
        strcpy(variableNombre[i], listadoPropietarios[indicePropietario].nombreApellido);
        strcpy(direccion[i], listadoPropietarios[indicePropietario].direccion);
        idProp=listadoPropietarios[indicePropietario].idPropietario;

    if(listadoAutos[i].estado==OCUPADO)
        {

            if(listadoAutos[i].marca==1)
                    {
                        strcpy(marca,"ALPHA_ROMEO");
                    }

                if(listadoAutos[i].marca==2)
                    {
                        strcpy(marca,"FERRARI    ");
                    }

                if(listadoAutos[i].marca==3)
                    {
                        strcpy(marca,"AUDI       ");
                    }

                if(listadoAutos[i].marca==4)
                    {
                        strcpy(marca,"OTROS      ");
                    }

            printf("%s        %d             %s           %d                %s               %s\n",listadoAutos[i].patente, listadoAutos[i].idAuto, marca,idProp, variableNombre[i], direccion[i]);
        }
    }
}

void listarPropietariosEstacionadosNombreDescendente(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios)
{
    int i,j,k, ultimoOcupado, auxi, indiceAuto,idAuto,idPropietario;
    char aux[50], marca[20], variableNombre[20][100], patente[20][100], nombre[20][50];
    float importe;

    printf("Nombre     Direccion          ID Prop         Tarjeta           Marca          ID Auto       Importe \n");

    ultimoOcupado=eAuto_buscarLugarLibre(listadoAutos,largoAutos);
    if(ultimoOcupado==-2)
    ultimoOcupado=20;

    for(k=0;k<ultimoOcupado-1;k++)
    {
        if(listadoAutos[i].estado==OCUPADO)
        {
            for(l=0;l<ultimoOcupado-1;l++)
            {
                if(listadoAutos[i].idPropietario==listadoPropietarios[l].idPropietario)
                {
                    nombre[i]=listadoPropietarios[l].nombreApellido;
                    //Copiate todos los datos de los propietarios a strings nuevos
                    //EJ: direccion[i]=listadoPropietarios[l].dureccuib
                    //Despues ordena estos strings que creaste ordenando tambien los datos de los autos
                }
            }

        for(i=0;i<ultimoOcupado-2;i++)
    {
        for(j=i+1;j<ultimoOcupado-1;j++)
        {
            if(stricmp(listadoPropietarios[j].nombreApellido,listadoPropietarios[i].nombreApellido)==-1)
            {
                strcpy(aux, listadoPropietarios[j].nombreApellido);
                strcpy(listadoPropietarios[j].nombreApellido, listadoPropietarios[i].nombreApellido);
                strcpy(listadoPropietarios[i].nombreApellido, aux);

                strcpy(aux, listadoPropietarios[j].direccion);
                strcpy(listadoPropietarios[j].direccion, listadoPropietarios[i].direccion);
                strcpy(listadoPropietarios[i].direccion, aux);

                auxi=listadoPropietarios[j].idPropietario;
                listadoPropietarios[j].idPropietario=listadoPropietarios[i].idPropietario;
                listadoPropietarios[i].idPropietario=auxi;

                strcpy(aux, listadoPropietarios[j].tarjetaCredito);
                strcpy(listadoPropietarios[j].tarjetaCredito, listadoPropietarios[i].tarjetaCredito);
                strcpy(listadoPropietarios[i].tarjetaCredito, aux);
            }
        }
    }

        }

    }

    for(i=0;i<ultimoOcupado;i++)
    {
        indiceAuto=eAuto_buscarPorId(listadoAutos,largoAutos,listadoAutos[i].idPropietario);
        strcpy(patente[i], listadoAutos[indiceAuto].patente);
        idAuto=listadoAutos[indiceAuto].idAuto;
        importe=listadoAutos[indiceAuto].importe;


    if(listadoAutos[indiceAuto].estado==OCUPADO)
        {

            if(listadoAutos[indiceAuto].marca==1)
                    {
                        strcpy(marca,"ALPHA_ROMEO");
                    }

                if(listadoAutos[indiceAuto].marca==2)
                    {
                        strcpy(marca,"FERRARI    ");
                    }

                if(listadoAutos[indiceAuto].marca==3)
                    {
                        strcpy(marca,"AUDI       ");
                    }

                if(listadoAutos[indiceAuto].marca==4)
                    {
                        strcpy(marca,"OTROS      ");
                    }

            printf("%s        %s             %d           %s                %s               %d            %f\n",listadoPropietarios[i].nombreApellido, listadoPropietarios[i].direccion, listadoPropietarios[i].idPropietario, listadoPropietarios[i].tarjetaCredito, marca,idAuto,importe);
        }
    }
}
void listadoEmpleadoPorSector (eEmpleado empleados[], eSector sectores[], int cantEmp, int cantSector)
{
    int i, j;

    printf("\n****** LISTADO DE EMPLEADOS ******\n\n");


  for( i = 0; i < cantSector; i++)
  {
        for( j = 0; j<cantEmp; j++ ) // recorro los empleados
        {

         if( empleados[j].isEmpty == 0 && sectores[i].id == empleados[j].sectorId )  // busco la interseccion
         {
			printf("%d %s %s", empleados[j].legajo, empleados[j].nombre, sectores[i].descripcion );
         }
        } //Cierre 2do for
  } // cierre 1er for
}


//

void listadoMenuPorEmpleado ( eEmpleado empleados[], eMenu menues[], eAlmuerzo almuerzos[], int cantEmp, int cantMenu )
{
    int i, j, k;

    printf("\n****** LISTADO DE MENU POR EMPLEADOS ******\n\n");


  for( i = 0; i < cantMenu; i++)
  {
        for( j = 0; j < (cantEmp * cantMenu); j++ ) // recorro los almuerzos
        {
         if( menues[i].id == almuerzos[j].menuId )  // busco la interseccion
         {
			for( k = 0; k < cantEmp; k++ ){ // recorro los empleados
				if( empleados[k].isEmpty == 0 && almuerzos[j].empleadoLegajo == empleados[k].legajo ){
					printf("%d %s %s", empleados[k].legajo, empleados[k].nombre, menues[i].descripcion );
				}

			}
         }
        } //Cierre 2do for
  } // cierre 1er for

}


float masBarato(producto lista[], int tam)
{
    int i;
    float masBarato = -1;

	for (i=0;i<tam;i++)
	{
	  if(lista[i].estado == 1)
	    {
	     masbarato = lista[i].precio;
	     brea;
	    }

	}

	if (masbarato == -1) //si se cumple no existen productos activos en el array
	{
          printf("No hay productos en el sistema todavia");
	  masbarato = -1;
	}


	for(i=0; i<tam;i++)
	{
		if(masbarato > lista[i].precio && lista[i].estado == 1)
		{
		 preciomasbarato = lista[i].precio;
		}
	}
	return masbarato;
}

float promedioPrecio(producto lista[],int tam)
{
    int i;
    float preciototal = 0;
    int productosactivos =0;
    int preciopromedio = 0;
	for (i=0;i<tam;i++)
	{
	  if(lista[i].estado == 1)
	    {
	     preciototal = preciototal + lista[i].precio;
	     productosactivos++;
	    }

	}

	if (productosactivos == 0) //si se cumple no existen productos activos en el array
	{
	  printf("No hay productos en el sistema todavia");
	  preciopromedio = -1;
	}else
	{
	 preciopromedio = (preciototal / (float)productosactivos);
	}

	return preciopromedio;
}

void ordenarPorDescripcion(eProducto listado[],int tam)
{
    eProducto auxProducto;
    int i,j;
    for(i=0; i < clientes - 1; i++)
    {
        if(listado[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j < clientes; j++)
        {
            if(listado[j].estado == 0)
            {
                continue;
            }
            if(strcmp(listado[j].descripcion,listado[i].descripcion) > 0)
            {
                auxProducto = listado[j];
                listado[j] = listado[i];
                listado[i] = auxProducto;
            }
            else if (strcmp(listado[j].descripcion,listado[i].descripcion) == 0)
            {
                if (listado[i].cant > listado[j].cant)
                {
                    auxProducto = listado[j];
                    listado[j] = listado[i];
                    listado[i] = auxProducto;
                }
            }
        }
    }
}
