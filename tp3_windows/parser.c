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
	char id[128];
	char nombre[128];
	char horas[128];
	char sueldo[128];
	int cant;
	Employee* aux;
	if(pFile!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
			fflush(NULL);
			aux=employee_newParametros(id, nombre, horas, sueldo);
			if(aux!=NULL)
			{
				cant=ll_add(pArrayListEmployee,aux);
				if(cant!=0)
				{
					employee_delete(aux);
					break;
				}
				puts("entro aca");
			}else
			{
				puts("cargo.\n");
			}
		}

		puts("salio.");
	}

    return 1;
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

    return 1;
}
