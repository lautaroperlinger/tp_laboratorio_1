#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pnt_ArrayEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pnt_ArrayEmployee)
{
    char id[100],nombre[100], horasTrabajadas[100], sueldo[100];
    Employee* aux;
    if(pFile!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,horasTrabajadas,sueldo);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,horasTrabajadas,sueldo);

            aux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

            ll_add(pnt_ArrayEmployee,aux);
        }
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pnt_ArrayEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pnt_ArrayEmployee)
{

    if(pFile != NULL && pnt_ArrayEmployee != NULL)
    {
        while(!feof(pFile)-1)
        {
            Employee* aux = employee_new();
            fread(aux, sizeof(Employee), 1, pFile);
            ll_add(pnt_ArrayEmployee,aux);
        }
    }

    return 1;
}
