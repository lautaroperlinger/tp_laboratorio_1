  /*
 * ArrayEmployees.c
 *
 *  Created on: 26 sep. 2021
 *      Author: lauta
 */


#include "ArrayEmployees.h"
#include "Funciones.h"
int InitEmployees(Employee listaempleados[],int tamanio)
{
	int retorno;
	int I;
	retorno=1;
	if(listaempleados!=0&&tamanio>0)
	{
		for(I=0;I<tamanio;I++)
		{
			listaempleados[I].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
int AddEmployees(Employee listaempleados[],int tamanio,int id,char nombre[],char apellido[],float salary,int sector,int espacioLibre)
{
	int retorno;
	retorno=0;
	if(listaempleados!=0&&tamanio>0&&id>0&&nombre!=0&&apellido!=0&&salary!=0&&sector>0&&espacioLibre>=0)
	{
		listaempleados[espacioLibre].id=id;
		strcpy(listaempleados[espacioLibre].name,nombre);
		strcpy(listaempleados[espacioLibre].lastname,apellido);
		listaempleados[espacioLibre].salary=salary;
		listaempleados[espacioLibre].sector=sector;
		listaempleados[espacioLibre].isEmpty=0;
		retorno=1;
	}
	return retorno;
}
int FindEmployeesById(Employee listaempleados[],int tamanio,int id,int* index)
{
	int retorno;
	int I;
	retorno=0;
	if(listaempleados!=0&&tamanio>0&&id>=0)
	{
		for(I=0;I<tamanio;I++)
		{
			if(listaempleados[I].isEmpty==0&&listaempleados[I].id==id)
			{
				*index=I;
				retorno=1;
				break;
			}
		}
	}
	return retorno;;
}
 int ModificarEmployee(Employee listaempleados[],int tamanio,int id,int tamanioCadena)
{
	int retorno;
	int respuesta;
	int index;
	retorno=0;
	if(listaempleados!=0&&tamanio>0&&id>0&&tamanioCadena>0)
	{
			if(FindEmployeesById(listaempleados, tamanio, id, &index)==1)
			{
				Menu(&respuesta, "SUBMENU:\n1-modificar nombre\n2-modificar apellido\n3-modificar salario\n4-modificar sector\n5-salir", "opcion no valida", 5, 1);
				switch(respuesta)
				{
					case 1:
						PedirCadena(listaempleados[index].name, "Ingrese el nuevo nombre", tamanioCadena);
						retorno=1;
					break;
					case 2:
						PedirCadena(listaempleados[index].lastname, "Ingrese el nuevo apellido", tamanioCadena);
						retorno=1;
						break;
					case 3:
						PedirFlotante("Ingrese el nuevo salario", &listaempleados[index].salary, 0);
						retorno=1;
						break;
					case 4:
						PedirEntero( &listaempleados[index].sector,"Ingrese el nuevo sector:",0,10);
						retorno=1;
						break;
				}
			}
	}
	return retorno;
}
 int RemoveEmployee(Employee listaempleados[],int tamanio,int id)
 {
	 int retorno;
	 int I;
	 retorno=0;
	 if(listaempleados!=0&&tamanio>0&&id>=500)
	 {
		for(I=0;I<tamanio;I++)
		{
			if(listaempleados[I].isEmpty==0&&listaempleados[I].id==id)
			{
				listaempleados[I].isEmpty=1;
				retorno=1;
				break;
			}
		}
	 }
	 return retorno;
 }
 int SortEmployee(Employee listaempleados[],int tamanio,int orden)
 {
	 int retorno;
	 int I;
	 int J;
	 int auxiliarEntero;
	 float auxiliarFlotante;
	 char auxiliarCadena[51];
	 retorno=0;
	 if(listaempleados!=0&&tamanio>0&&orden!=0)
	 {
		 switch(orden)
		 {
		 case 1:
			 for(I=0;I<tamanio-1;I++)
			 {
			 	for(J=I;J<tamanio;J++)
			 	{
			 		if(listaempleados[I].isEmpty==0&&listaempleados[J].isEmpty==0&&(strcmp(listaempleados[0].lastname,listaempleados[0].lastname)==0))
			 		{
			 			auxiliarEntero=listaempleados[I].id;
			 			listaempleados[I].id=listaempleados[J].id;
			 			listaempleados[J].id=auxiliarEntero;
			 			//
			 			strcpy(auxiliarCadena,listaempleados[I].name);
			 			strcpy(listaempleados[I].name,listaempleados[J].name);
			 			strcpy(listaempleados[J].name,auxiliarCadena);
			 			//
			 			strcpy(auxiliarCadena,listaempleados[I].lastname);
			 			strcpy(listaempleados[I].lastname,listaempleados[J].lastname);
			 			strcpy(listaempleados[J].lastname,auxiliarCadena);
			 			//
			 			auxiliarFlotante=listaempleados[I].salary;
			 			listaempleados[I].salary=listaempleados[J].salary;
			 			listaempleados[J].salary=auxiliarFlotante;
			 			//
			 			auxiliarEntero=listaempleados[I].sector;
						listaempleados[I].sector=listaempleados[J].sector;
						listaempleados[J].sector=auxiliarEntero;
			 			retorno=1;
			 		 }
			 	 }
			 }
			 break;
		 case 2:
			 for(I=0;I<tamanio-1;I++)
			 {
			 	 for(J=I;J<tamanio;J++)
			 	 {
			 		if(listaempleados[I].isEmpty==0&&listaempleados[J].isEmpty==0&&(strcmp(listaempleados[I].lastname,listaempleados[J].lastname)==0))
			 		 {
			 				auxiliarEntero=listaempleados[I].id;
			 			 	 listaempleados[I].id=listaempleados[J].id;
			 			 	 listaempleados[J].id=auxiliarEntero;
			 			 	 //
			 			 	 strcpy(auxiliarCadena,listaempleados[I].name);
			 			 	 strcpy(listaempleados[I].name,listaempleados[J].name);
			 			 	 strcpy(listaempleados[J].name,auxiliarCadena);
			 			 	 //
			 			 	 strcpy(auxiliarCadena,listaempleados[I].lastname);
			 			 	 strcpy(listaempleados[I].lastname,listaempleados[J].lastname);
			 			 	 strcpy(listaempleados[J].lastname,auxiliarCadena);
						    //
			 			 	 auxiliarFlotante=listaempleados[I].salary;
						 	 listaempleados[I].salary=listaempleados[J].salary;
						 	 listaempleados[J].salary=auxiliarFlotante;
						 	 //
						 	auxiliarEntero=listaempleados[I].sector;
							listaempleados[I].sector=listaempleados[J].sector;
							listaempleados[J].sector=auxiliarEntero;
						 	retorno=1;
			 		 }
			 	 }
			 }
			 break;
		 }
	 }
	 return retorno;
 }
void PrintEmployee(Employee listaempleados[],int tamanio,int index)
{
	if(listaempleados!=0&&tamanio>0&&index>=0)
	{
		printf("%d %18s %18s %5.2f %4d\n",listaempleados[index].id,listaempleados[index].name,listaempleados[index].lastname,listaempleados[index].salary,listaempleados[index].sector);
	}

}
int BuscarEspacioLibre(Employee listaempleados[],int tamanio,int* index)
{
	int retorno;
	int I;
	retorno=1;
	if(listaempleados!=0&&tamanio>0)
	{
		for(I=0;I<=tamanio;I++)
		{
			if(listaempleados[I].isEmpty==1)
			{
				*index=I;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
void PrintAllEmployees(Employee listaempleados[],int tamanio,float promediosalario)
{
	int I;
	if(listaempleados!=0&&tamanio>0)
	{
		printf("-------------------LISTADO DE EMPLEADOS-----------------\n");
		printf("--------------------------------------------------------\n");
		printf("ID           NOMBRE         APELLIDO      SALARIO   SECTOR\n");
		for(I=0;I<=tamanio;I++)
		{

			if(listaempleados[I].isEmpty==0)
			{
				if(promediosalario!=0&&listaempleados[I].salary>=promediosalario)
				{
					PrintEmployee(listaempleados, tamanio,I);
				}
				else
				{
					if(promediosalario==0)
					{
						PrintEmployee(listaempleados, tamanio, I);
					}
				}

			}

		}
	}
}
float CalcularSalarioProm(Employee listaempleados[],int tamanio)
{
	float promedio;
	float sumatoria;
	int contador;
	contador=0;
	sumatoria=0;
	int i;
	if(listaempleados!=0&&tamanio>0)
	{
		for(i=0;i<tamanio;i++)
		{
			if(listaempleados[i].isEmpty==0)
			{
				contador++;
				sumatoria=sumatoria+listaempleados[i].salary;
			}
		}
		printf("%d\n",contador);
		printf("%f",sumatoria);
		promedio=sumatoria/contador;
		printf("%2.f\n",promedio);
	}
	return promedio;
}
