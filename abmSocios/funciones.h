#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Pide un entero
 * \param char mensaje a mostrar
 * \param int numero que se ingresa
 * \param int minimo
 * \param int maximo
 * \return Devuelve el numero ingresado
 */

int getInt(char [],int ,int ,int );

/** \brief Pide un flotante
 * \param char mensaje a mostrar
 * \param float numero que se ingresa
 * \return Devuelve el numero flotante ingresado
 */

char getOpcion(char [],char ,char , char);

float getFloat(char [],float );

/** \brief Pide un caracter
 * \param char mensaje a mostrar
 * \param char caracter que se ingresa
 * \return Devuelve el char ingresado
 */

char getChar(char [],char );

/** \brief Pide una cadena de caracteres
 * \param char mensaje a mostrar
 * \param char cadena que se ingresa
 * \return void
 */

void getString(char [],char []);

/** \brief Pide una cadena de caracteres y lo devuelve
 * \param char mensaje a mostrar
 * \param char cadena que se ingresa
 * \return 1 si el texto contiene solo letras
 */

int getStringLetras(char [],char []);

/** \brief Pide una cadena de caracteres y lo devuelve
 * \param char mensaje a mostrar
 * \param char cadena que se ingresa
 * \return 1 si el texto contiene solo numeros
 */

int getStringNumeros(char [],char []);

/** \brief Valida un numero entre un minimo y un maximo
 * \param int dato que se le pasa
 * \param int minimo del dato
 * \param int maximo del dato
 * \return Devuelve el numero validado entre el rango de min y max
 */

int validarEntero(int , int , int , char  []);

/** \brief Verifica si el valor recibido es numero
 * \param str Array a ser analizado
 * \return 1 si es numero, 0 si no lo es
 */

int esNumerico(char []);

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */

int esFlotante(char []);

/** \brief Verifica si el valor recibido es solo letras
 * \param str Array a ser analizado
 * \return 1 si son solo letras y espacios y 0 si no lo es
 */

int esSoloLetras(char []);

/** \brief Verifica si el valor recibido es alfa numerico
 * \param str Array a ser analizado
 * \return 1 si contiene solo caracteres para mail y 0 si no lo es
 */

int esMail(char []);

/** \brief Verifica si el valor recibido es un telefono
 * \param str Array a ser analizado
 * \return 1 si contiene numeros y 0 si no lo es
 */

int esTelefono(char []);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char [],char []);

/** \brief Pide una cadena de caracteres y lo devuelve
 * \param char mensaje a mostrar
 * \param char cadena que se ingresa
 * \return 1 si el texto contiene numeros y guion xxxx-xxxx y 0 si no
 */
int getStringTelefono(char [],char []);

/** \brief Pide una cadena de caracteres y lo devuelve
 * \param char mensaje a mostrar
 * \param char cadena que se ingresa
 * \return 1 si el texto contiene @ y letras,numeros 0 si no
 */
int getStringMail(char [],char []);
#endif // FUNCIONES_H_INCLUDED
