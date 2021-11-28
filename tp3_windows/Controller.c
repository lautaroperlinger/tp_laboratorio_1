#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int dato;
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivo;
	if(path!=NULL&&pArrayListEmployee!=NULL)
	{
		archivo=fopen(path,"r");
		dato=parser_EmployeeFromText(archivo, pArrayListEmployee);
		printf("el dato es:%d",dato);
		if(archivo!=NULL&&dato==0)
		{
			puts("se cargo el archivo en texto.\n");
			fclose(archivo);
		}
		else
		{
			puts("intente en binario, por favor.\n");
		}
	}
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivo;
	if(path!=NULL&&pArrayListEmployee!=NULL)
	{
		//controller_loadFromText(path, pArrayListEmployee);
		//controller_saveAsBinary(path, pArrayListEmployee);
		archivo=fopen(path,"rb");
		parser_EmployeeFromBinary(archivo, pArrayListEmployee);
		fclose(archivo);
	}
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* empleado;
	int id;
	char nombre[128];
	int sueldo;
	int horas;
	retorno=0;
	if(pArrayListEmployee!=NULL)
	{

		id=ll_len(pArrayListEmployee)+1;
		puts("Ingrese el nombre del empleado:");
		scanf("%s",nombre);
		puts("Ingrese las horas trabajadas:");
		scanf("%d",&horas);
		while(horas<0)
		{
			puts("No se puede ingresar menos de 0 horas");
			scanf("%d",&horas);
		}
		puts("Ingrese las sueldo del empleado:");
		scanf("%d",&sueldo);
		while(sueldo<0)
		{
			puts("No se puede ingresar un sueldo menos a 0:");
			scanf("%d",&sueldo);
		}
		retorno=1;
	}
	empleado=employee_new();
	ll_add(pArrayListEmployee, empleado);
	employee_setId(empleado, id);
	employee_setNombre(empleado, nombre);
	employee_setHorasTrabajadas(empleado, horas);
	employee_setSueldo(empleado, sueldo);
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int opcion;
	int idaux;
	Employee* empleado;
	retorno=0;
	puts("Ingrese el id del cliente a moficar:");
	scanf("%d",&idaux);

	if(pArrayListEmployee!=NULL)
	{
		puts("entro aca");
		do
		{
			puts("Ingrese una opcion\n1.Nombre\n2.Sueldo\n3.Horas trabajadas\n4.Salir");
			scanf("%d",&opcion);
			switch(opcion)
			{
			case 1:
				puts("Ingrese el nuevo nombre:");
				scanf("%c",empleado->nombre);
				break;
			case 2:
				puts("Ingrese el nuevo sueldo:");
				scanf("%d",&(empleado->sueldo));
				break;
			case 3:
				puts("Ingrese el nuevo total de horas trabajadas:");
				scanf("%d",&(empleado->horasTrabajadas));
				break;
			}
		}while(opcion!=4);
		retorno=1;
	}
	ll_set(pArrayListEmployee, idaux, empleado);
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int id;
	Employee* aux;
	retorno=0;
	if(pArrayListEmployee!=NULL)
	{
		puts("Ingrese el id a eliminar:");
		scanf("%d",&id);

		if(id>0&&id<=ll_len(pArrayListEmployee))
		{
			ll_remove(pArrayListEmployee,id);
			retorno=1;
		}
		else
		{
			puts("Id no valido\n");
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	Employee* aux;
	if(pArrayListEmployee!=NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux=ll_get(pArrayListEmployee, i);
			printf("%d   %s %d %d\n\n\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
		}
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	puts("entro aca");
	int (*pFunc)(void*,void*);
	pFunc=&employee_Compare;
	ll_sort(pArrayListEmployee,pFunc,1);
	puts("Entro aca despues");

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	Employee* aux;
	FILE* miArchivo;
	if(path!=NULL)
	{
		miArchivo=fopen(path,"w");
		fprintf(miArchivo,"id,nombre,horasTrabajadas,sueldo\n");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux=ll_get(pArrayListEmployee, i);
			fprintf(miArchivo,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
		}
		fclose(miArchivo);
	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	Employee* aux;
	FILE* miArchivo;
	if(path!=NULL)
	{
		miArchivo=fopen(path,"wb");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux=ll_get(pArrayListEmployee, i);
			fwrite(aux,sizeof(Employee),1,miArchivo);
		}
		fclose(miArchivo);
	}
    return 1;
}

