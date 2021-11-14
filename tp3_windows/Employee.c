#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
Employee* employee_new()
{
	Employee* empleado;
	empleado= (Employee*)malloc(sizeof(empleado));
	return empleado;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* empleado;
	empleado=employee_new();
	int id;
	int horas;
	int sueldo;
	id=atoi(idStr);
	horas=atoi(horasTrabajadasStr);
	sueldo=atoi(sueldoStr);
	employee_setId(empleado, id);
	employee_setNombre(empleado, nombreStr);
	employee_setHorasTrabajadas(empleado, horas);
	employee_setSueldo(empleado, sueldo);
	return empleado;
}
void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}
int employee_setId(Employee* this,int id)//ingresan la info
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id)//trae la info
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		*id=this->id;
	}
	return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=1;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=1;
	}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=1;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}
	return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		this->sueldo=sueldo;
		retorno=1;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}
int employee_Compare(void* empleado1,void* empleado2)
{
	int retorno;
	Employee* empleadouno;
	Employee* empleadodos;
	empleadouno=(Employee*)empleado1;
	empleadodos=(Employee*)empleado2;
	retorno=strcmp(empleadouno->nombre,empleadodos->nombre);

	return retorno;
}
