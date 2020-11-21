#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#define nombres 51

#endif // ARRAYEMPLOYEES_H_INCLUDED

//DOXYGEM Y PROTOTIPOS DE LAS FUNCIONES DE ARRAY EMPLOYEES Y OTRAS FUNCIONES
typedef struct //estructura para empleados
{
    int ID;
    char Name[nombres];
    char LastName[nombres];
    float Salary;
    int Sector;
    int isEmpty;
}eEmployee;

/** \brief to indicate that all position in the array are empty, this function put the flasg(isEmmpty) in false in all position of the array
 *
 * \param List[] eEmployee pointer to array of employees
 * \param len int array length
 * \return int
 *
 */
int initEmployees(eEmployee List[],int len);//1

/** \brief add in a existing list of employees the values received as
            parameters in the first empt position
 *
 * \param List[] eEmployee
 * \param len int
 * \param name[] char
 * \param lastname[] char
 * \param salary float
 * \param sector int
 * \return int return -1 if error.
 *
 */
int addEmployee(eEmployee List[],int len,char name[],char lastname[],float salary,int sector);//1

/** \brief find an Employee by ID en returns the index position
            in array
 *
 * \param List[] eEmployee
 * \param len int
 * \param id int
 * \return int
 *
 */
int findEmployeeByID(eEmployee List[],int len, int id);//1

/** \brief remove a Employee by ID(put isEmpty Flag in false)
 *
 * \param List[] eEmployee
 * \param len int
 * \param id int
 * \return int
 *
 */
int removeEmployee(eEmployee List[],int len,int id);

/** \brief sort the elements in the array of employees the argument

 *
 * \param List[] eEmployee
 * \param len int
 * \return int
 *
 */
int sortEmployees(eEmployee List[],int len);

/** \brief print the content of employees array
 *
 * \param List[] eEmployee
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee List[],int length);

/** \brief genera el ID del empleado
 *
 * \param List[] eEmployee
 * \param len int
 * \return int
 *
 */
int freeSite(eEmployee List[],int len);
/** \brief pide un numero entero
 *
 * \param mensaje[] char
 * \return int
 *
 */
int pedirInt(char mensaje[]);
/** \brief pide un numero flotante
 *
 * \param mensaje[] char
 * \return float
 *
 */
float pedirFlo(char mensaje[]);
/** \brief pide una cadena de texto y la verifica
 *
 * \param mensaje[] char
 * \param palabra[] char
 * \param len int
 * \return void
 *
 */
void pedirString(char mensaje[],char palabra[],int len);
/** \brief verifica una cadena de texto
 *
 * \param palabra[] char
 * \param len int
 * \return void
 *
 */
void verificacionNombre(char palabra[],int len);
/** \brief  muestra un empleado por su id
 *
 * \param List[] eEmployee
 * \param posicion int
 * \return void
 *
 */
void mostrarEmpleado(eEmployee List[],int posicion);
/** \brief modifica un empleado por su id
 *
 * \param List[] eEmployee
 * \param id int
 * \param opcion int
 * \param name[] char
 * \param lastname[] char
 * \param salary float
 * \param sector int
 * \return void
 *
 */
void modificarEmpleado(eEmployee List[],int id,int opcion,char name[],char lastname[],float salary,int sector);
/** \brief menu de opciones para modificar al empleado
 *
 * \param mensaje[] char
 * \param opcion1[] char
 * \param opcion2[] char
 * \param opcion3[] char
 * \param opcion4[] char
 * \return int
 *
 */
int MenuModificar(char mensaje[], char opcion1[], char opcion2[],char opcion3[],char opcion4[]);
/** \brief saca el promedio de salario de los empleados
 *
 * \param List[] eEmployee
 * \param len int
 * \return float
 *
 */
float PromedioSalario(eEmployee List[],int len);

