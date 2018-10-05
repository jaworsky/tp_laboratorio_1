typedef struct // Estructura de empleado.
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
} Employee;

//Funciones del programa.

/** \brief Abre un menu de opciones para el usuario.
 *
 * \param
 * \param
 * \return Devuelve la opcion elegida.
 *
 */

int menu();

/** \brief Recorre el array de empleados, y coloca en 1 las posiciones del array (isEmpty=1).
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \return no devuelve.
 *
 */

void initEmployees(Employee listado[], int tam);

/** \brief Carga un empleado al array.
 *
 * \param le paso como dato el legajo, para que lo asigne como id al empleado.
 * \param
 * \return no devuelve.
 *
 */

Employee addEmployee(int legajo);

/** \brief Recorre el array y encuentra una posicion libre para cargar.
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \return devuelve el indice a donde cargar el empleado.
 *
 */

int searchFreeIndex(Employee listado[], int tam);

/** \brief Recorre el array y muestra empleado por empleado.
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \return no devuelve.
 *
 */

void printListEmployee(Employee listado[], int tam);

/** \brief Muestra 1 solo empleado.
 *
 * \param le paso 1 empleado a mostrar.
 * \param
 * \return no devuelve.
 *
 */

void printEmployee (Employee empleadoAmostrar);

/** \brief si encuentra un indice libre, lo carga llamando a la funcion addEmployee y luego pone el indice como LLENO (0).
 *
 * \param Array de empleados
 * \param Tamaño del array.
 * \param Legajo del empleado.
 * \return Devuelve el valor del indice, si es -1 No hay mas espacio en el sistema.
 *
 */

int loadListEmployee(Employee listado[], int tam,int legajo);

/** \brief Se encarga de buscar un empleado en nuestro sistema, con el numero de ID.
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \param Legajo del emplado a buscar.
 * \return devuelve el indice del empleado que encontro, si devuelve -1, No lo encontro.
 *
 */

int SearchEmployee(Employee listado[], int tam, int legajo);

/** \brief Busca un empleado en el sistema, y lo elimina de este si el usuario asi lo desea.
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \return No devuelve.
 *
 */

void lowEmployee(Employee listado[], int tam);

/** \brief Busca un empleado en nuestro sistema, y permite modificar su nombre,apellido,salario y sector.
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \return No devuelve.
 *
 */

void modificaEmployee(Employee listado[], int tam);

/** \brief Abre un menu de opciones para ordenar los empleados alfabeticamente por apellido y sector, y muestra los promedios totales de los empleados.
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \return No devuelve.
 *
 */

void sortEmployees(Employee listado[], int len);

/** \brief Calcula el salario total, salario promedio, cantidad de empleados y cantidad de empleados que superan el salario.
 *
 * \param Array de empleados.
 * \param Tamaño del array.
 * \return No devuelve.
 *
 */

void salaryAndAverage(Employee listado[], int tam);

//Validaciones:

/** \brief Pide un flotante y lo guarda.
 *
 * \param mensaje para el usuario.
 * \param
 * \return devuelve el flotante.
 *
 */

float getFloat(char msj[]);

/** \brief Pide un entero y lo devuelve.
 *
 * \param mensaje para el usuario.
 * \param
 * \return devuelve el numero entero.
 *
 */

int function_getInt(char msj[] );

/** \brief Pide un caracter y lo devuelve.
 *
 * \param mensaje para el usuario.
 * \param
 * \return Devuelve el caracter ingresado.
 *
 */

char function_getChar(char msj[]);

/** \brief Verifica que todos los valores de la string sean numericos.
 *
 * \param string a verificar.
 * \param
 * \return devuelve 1 si verifica, sino 0.
 *
 */

int function_esNum(char str[]);

/** \brief Verifica que la string ingresada contenga solo letras.
 *
 * \param String a verificar.
 * \param
 * \return Devuelve 1 si verifica, sino 0.
 *
 */

int function_esSoloLetras(char str[]);

/** \brief Verifica si la string es alfanumerica.
 *
 * \param String a verificar.
 * \param
 * \return Devuelve 1 si verifica, sino 0.
 *
 */

int function_esAlfaNumerico(char str[]);

/** \brief Pide una cadena de caracteres.
 *
 * \param mensaje para el usuario.
 * \param lo que ingresa el usuario.
 * \return No devuelve.
 *
 */

void function_getString (char msj[],char input[]);

/** \brief Verifica que la string ingresada sean solo letras y la devuelve (la copia a input).
 *
 * \param mensaje para el usuario.
 * \param lo que ingresa el usuario.
 * \return 1 si verifica, sino 0.
 *
 */

int function_getStringLetras(char msj[],char input[]);

/** \brief Verifica que la string contenga solo numeros y la devuelve (la copia a input).
 *
 * \param mensaje para el usuario.
 * \param lo que ingresa el usuario.
 * \return 1 si verifica, sino 0.
 *
 */

int function_getStringNumeros(char msj[],char input[]);





