#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
typedef struct
{
    char nombre[50];
    int idUsuario;
    int estado;
    int calificacion;
}eUsuario;

typedef struct
{
    char nombre[50];
    int idProducto;
    int idUsuario;
    char nombreProducto[50];
    float precio;
    int stock;
    int cantidadVentas;
    int cantidadVentasPromedio;
    int estado;
}eProducto;

#endif // ESTRUCTURAGENERICA_H_INCLUDED

/** \brief Recorre el vector de usuarios buscando el ultimo que tenga estado ocupado y devuelve el ID del siguiente.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param limite int El largo del array que contiene los usuarios.
 * \return int El ID del usuario siguiente al ultimo ocupado, si no devuelve 0.
 *
 */
int eUser_siguienteId(eUsuario[] ,int limite);

/** \brief Permite el alta de usuarios.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param limite int El largo del array que contiene los usuarios.
 * \return int En caso de haber lugar para usuarios nuevos devuelve 0 y de no haber devuelve -2 o -3.
 *
 */
int eUser_alta(eUsuario[] ,int limite);

/** \brief Valida que solo se ingresen letras.
 *
 * \param nombre Una copia del nombre ingresado por el usuario.
 * \return int Devuelve 0 en caso de error y un 1 si esta bien.
 *
 */
int validarNombre(char nombre[]);

/** \brief Valida que solo se ingresen numeros
 *
 * \param numero int Una copia del numero ingresado por el usuario.
 * \return int Devuelve 0 en caso de error y un 1 si esta bien.
 *
 */
int validarNumero(char numero[]);

int eProducto_modificarPublicacion(eUsuario [], eProducto [], int , int );

int eProducto_altaPublicacion(eUsuario[], eProducto[], int, int);

void eProducto_mostrarProductosPorIdUsuario(eProducto[], eUsuario[], int, int, int);

void eProducto_borrarProductosPorIdUsuario(eProducto[], eUsuario[], int, int, int);


int eProducto_cancelarPublicacion(eUsuario[], eProducto[], int, int);

int eProducto_comprarProducto(eUsuario[], eProducto[], int, int);

int eUser_listarPublicacionesUsuario(eUsuario[],int,eProducto[],int);

float promedioCalificaciones(eUsuario[], int, eProducto[], int);
