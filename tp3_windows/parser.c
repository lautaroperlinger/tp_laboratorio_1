#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	char id[256];
	char nombre[256];
	char horas[256];
	char sueldo[256];
	int tam;
	Employee* aux;
	retorno=-1;
	if(pFile!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
		do
		{
			tam=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
			aux=employee_newParametros(id,nombre,horas,sueldo);
			if(tam==4)
			{
				ll_add(pArrayListEmployee,aux);
				retorno=0;
			}
			else
			{
				employee_delete(aux);
				retorno=1;
				break;
			}
		}while(!feof(pFile));
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* aux;
	if(pFile!=NULL&&pArrayListEmployee!=NULL)
	{
		while(!feof(pFile)-1)
		{
			aux=employee_new();
			fread(aux,sizeof(Employee),1,pFile);
			ll_add(pArrayListEmployee, aux);
		}
	}

    return 1;
}
