/*
 ============================================================================
 Name        : tp_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Funciones.h"
#define LETRAS 50
#define TAM 5
int main(void) {
	setbuf(stdout,NULL);
	Employee Listaempleados[TAM];
	int respuesta;
	int espacio;
	int id;
	int flag;
	int respuestaID;
	int auxiliarSector;
	float auxiliarSalario;
	char auxiliarNombre[LETRAS];
	char auxiliarApellido[LETRAS];
	flag=0;
	id=500;

	if(InitEmployees(Listaempleados,TAM)==0)
	{
		printf("Inicializado con exito!\n");
	}
	else
	{
		printf("Error en la inicializacion!\n");
	}
	do
	{
		Menu(&respuesta, "MENU DE OPCIONES\n\n\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-SALIR", "Opcion erronea,ingrese de nuevo:\n", 5, 1);
		switch(respuesta)
		{
			case 1:
					if(BuscarEspacioLibre(Listaempleados,TAM,&espacio)==0)
					{
						PedirCadena(auxiliarNombre, "Ingrese el nombre del empleado:", LETRAS);
						PedirCadena(auxiliarApellido, "Ingrese el apellido del empleado:", LETRAS);
						PedirFlotante("Ingrese el salario del empleado:", &auxiliarSalario, 0);
						PedirEntero(&auxiliarSector,"Ingrese el sector del empleado:", 0,10);
						if(AddEmployees(Listaempleados, TAM, id, auxiliarNombre,auxiliarApellido,auxiliarSalario,auxiliarSector, espacio)==1)
						{
							printf("El empleado se ingreso con exito!\n");
							id++;
						}
						else
						{
							printf("no se pudo ingresar el empleado D:\n");
						}
					}
					else
					{
						printf("no hay memoria jejox.\n");
					}
					flag=1;
					break;
			case 2:
				if(flag==1)
				{
					PrintAllEmployees(Listaempleados, TAM,0);
					PedirEntero(&respuestaID, "Ingrese el ID a modificar", 500, 1500);
					if(ModificarEmployee(Listaempleados, TAM, respuestaID, LETRAS)==1)
					{
						printf("El empleado se modifico correctament!\n");
					}
					else
					{
						printf("No se pudo modificar\n");
					}
				}
				break;
			case 3:
				if(flag==1)
				{
					PrintAllEmployees(Listaempleados, TAM,0);
					printf("Ingrese el ID a eliminar:");
					scanf("%d",&respuestaID);
					if(RemoveEmployee(Listaempleados, TAM, respuestaID)==1)
					{
						printf("El usuario fue eliminado correctamente!\n");
					}
					else
					{
						printf("No se pudo eliminar el usuario.\n");
					}
				}
					break;
			case 4:
				if(flag==1)
				{
					Menu(&respuesta, "SUBMENU\n1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n", "Opcion no valida", 2, 1);
					switch(respuesta)
					{
						case 1:
							SortEmployee(Listaempleados, TAM, 1);
							PrintAllEmployees(Listaempleados, TAM,0);
							break;
						case 2:
							auxiliarSalario=CalcularSalarioProm(Listaempleados, auxiliarSector);
							printf("El salario promedio es: %2.f\n",auxiliarSalario);
							PrintAllEmployees(Listaempleados, auxiliarSector, auxiliarSalario);
							break;
					}
				}
				system("pause");
					break;
		}
	}while(respuesta!=5);




	return EXIT_SUCCESS;
}
