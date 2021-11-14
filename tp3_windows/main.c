#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
	int opcion;
	int flagempleado;
	int flagdatos;
	LinkedList* listaempleados;
	listaempleados=ll_newLinkedList();
	flagempleado=0;
	flagdatos=0;
	do
	{
			printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir.");
			scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				if(flagdatos==0)
				{
					controller_loadFromText("data.csv", listaempleados);
					flagdatos=1;
				}
						break;
			case 2:
						break;
			case 3:
				if(controller_addEmployee(listaempleados)==1)
				{
					puts("se ingreso el empleado exitosamente.\n");
					flagempleado=1;
				}
				else
				{
					puts("no se pudo ingresar el empleado.\n");
				}
						break;
			case 4:
				if(flagempleado==1)
				{
					controller_ListEmployee(listaempleados);
					if(controller_editEmployee(listaempleados)==1)
					{
						puts("Se modifico correctamente.\n");
					}
					else
					{
						puts("No se pudo modificar.\n");
					}
				}
				else
				{
					puts("Primero se tiene que ingresar un empleado.\n");
				}
						break;
			case 5:
				if(flagempleado==1)
				{
					controller_ListEmployee(listaempleados);
					if(controller_removeEmployee(listaempleados)==1)
					{
						puts("El empleado se elimino con exito.\n");
					}
					else
					{
						puts("No se pudo eliminar.\n");
					}
				}
				else
				{
					puts("Primero se tiene que ingresar un empleado.\n");
				}
						break;
			case 6:
				if(flagempleado==1||flagdatos==1)
				{
					controller_ListEmployee(listaempleados);
				}
				else
				{
					puts("Se tiene que ingresar un empleado primero.\n");
				}
						break;
			case 7:
				if(flagempleado==1)
				{
					controller_sortEmployee(listaempleados);
				}
				else
				{
					puts("Se tiene que ingresar un empleado primero.\n");
				}
						break;
			case 8:
						break;
			case 9:
						break;
		}
	}while(opcion!=10);

    return 0;
}

