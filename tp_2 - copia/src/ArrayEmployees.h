/*
 * ArrayEmployees.h
 *
 *  Created on: 26 sep. 2021
 *      Author: lauta
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H
#include <stdio.h>
#include <string.h>
struct //estructura de empleado
{
	int id;
	char name[51];
	char lastname[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;
/// \fn int InitEmployees(Employee[], int)
/// \brief Inicializa los espacios donde se van a guardar los empleados
///
/// \pre
/// \post
/// \param listaempleados
/// \param tamanio
/// \return retorna 1 si no se pudo o 0 si se pudo
int InitEmployees(Employee listaempleados[],int tamanio);//♥
/// \fn int AddEmployees(Employee[], int, int, char[], char[], float, int, int)
/// \brief Agrega los datos que se pidieron al usuario y los añade al espacio vacio
/// donde se puede guardar al empleado
///
/// \pre
/// \post
/// \param listaempleados
/// \param tamanio
/// \param id
/// \param nombre
/// \param apellido
/// \param salary
/// \param sector
/// \param espacioLibre
/// \return retorna 0 si no se pudo o 1 si se pudo
int AddEmployees(Employee listaempleados[],int tamanio,int id,char nombre[],char apellido[],float salary,int sector,int espacioLibre);//♥
/// \fn int FindEmployeesById(Employee[], int, int, int*)
/// \brief Busca al empleado a traves de su ID y devuelve su indice en la lista
///
/// \pre
/// \post
/// \param listaempleados
/// \param tamanio
/// \param id
/// \param index
/// \return devuelve 0 si no se pudo o 0  si se pudo
int FindEmployeesById(Employee listaempleados[],int tamanio,int id,int* index);
/// \fn int ModificarEmployee(Employee[], int, int, int)
/// \brief Busca al empleado con su ID y le pregunta al usuario que quiere modificar del empleadp
/// toma sus datos y los modifica en la lista
///
/// \pre
/// \post
/// \param listaempleados
/// \param tamanio
/// \param id
/// \param tamanioCadena
/// \return devuelve 0 si no se pudo y 1 si se pudo
int ModificarEmployee(Employee listaempleados[],int tamanio,int id,int tamanioCadena);//♥
/// \fn int RemoveEmployee(Employee[], int, int)
/// \brief Busca al empleado con su ID y le da de baja logica en la lista
///
/// \pre
/// \post
/// \param listaempleados
/// \param tamanio
/// \param id
/// \return devuelve 0 si no se pudo y 1 si se pudo
int RemoveEmployee(Employee listaempleados[],int tamanio,int id);//♥
/// \fn int SortEmployee(Employee[], int, int)
/// \brief Ordena los clientes por sus nombres y sectores, les pide el orden
/// si el orden es 1 los modifica de mayor a menos y si es 2 de menor a mayor
///
/// \pre
/// \post
/// \param listaempleados
/// \param tamanio
/// \param orden
/// \return revuelve 1 si s epudo y 0 si no se pudo
int SortEmployee(Employee listaempleados[],int tamanio,int orden);
/// \fn void PrintEmployee(Employee[], int, int)
/// \brief imprime un empleado solo
///
/// \pre
/// \post
/// \param listaempleados
/// \param tamanio
/// \param index
void PrintEmployee(Employee listaempleados[],int tamanio,int index);
/// \fn void PrintAllEmployees(Employee[], int, float)
/// \brief Imprime todos los empleados en la lista, pide el promedio de salario pero
/// si le pones 0 imprime todos
///
/// \pre
/// \post
/// \param listaempleados
/// \param tamanio
/// \param promediosalario
void PrintAllEmployees(Employee listaempleados[],int tamanio,float promediosalario);//♥
/// \fn int BuscarEspacioLibre(Employee[], int, int*)
/// \brief Busca el espacio libre en la lista para agregar al empleado
///
/// \pre
/// \post
/// \param listaempleados
/// \param tamanio
/// \param index
/// \return devuelve 1 si no hay mas espacio y 0 si hay espacio
int BuscarEspacioLibre(Employee listaempleados[],int tamanio,int* index);//♥
/// \fn float CalcularSalarioProm(Employee[], int)
/// \brief calcula el promedio de los salarios de todos los empleados
///
/// \pre
/// \post
/// \param listaempleados
/// \param tamanio
/// \return retorna el promedio total de los salarios
float CalcularSalarioProm(Employee listaempleados[],int tamanio);
#endif /* ARRAYEMPLOYEES_H_ */
