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
	int flagdatos;
	LinkedList* listaempleados;
	listaempleados=ll_newLinkedList();
	flagdatos=0;
	do
	{
			printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir.");
			scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				//puts("entro aca.\n");
				if(flagdatos==0)
				{
					//puts("entro aca.\n");
					controller_loadFromText("data.csv", listaempleados);
					flagdatos=1;
				}
				else
				{
					puts("No se puede cargar los datos por que ya se cargaron.\n");
				}
						break;
			case 2:
				if(flagdatos==0)
				{
					controller_loadFromBinary("data.csv", listaempleados);
					flagdatos=1;
				}
				else
				{
					puts("No se puede cargar los datos por que ya se cargaron.\n");
				}
						break;
			case 3:
				if(flagdatos==1)
				{
					if(controller_addEmployee(listaempleados)==1)
					{
						puts("se ingreso el empleado exitosamente.\n");
					}
					else
					{
						puts("no se pudo ingresar el empleado.\n");
					}
							break;
				}
				else
				{
					puts("Primero se tiene que cargar los empleados.\n");
				}
			case 4:
				if(flagdatos==1)
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
				if(flagdatos==1)
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
				if(flagdatos==1)
				{
					controller_ListEmployee(listaempleados);
				}
				else
				{
					puts("Se tiene que ingresar un empleado primero.\n");
				}
						break;
			case 7:
				if(flagdatos==1)
				{
					controller_sortEmployee(listaempleados);
				}
				else
				{
					puts("Se tiene que ingresar un empleado primero.\n");
				}
						break;
			case 8:
				if(flagdatos==1)
				{
					controller_saveAsText("data.csv", listaempleados);
					flagdatos=0;
				}
						break;
			case 9:
				if(flagdatos==1)
				{
					controller_saveAsBinary("data.csv", listaempleados);
				}
						break;
		}
	}while(opcion!=10);

    return 0;
}

