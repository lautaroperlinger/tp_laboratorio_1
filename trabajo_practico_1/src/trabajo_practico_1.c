/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
int main(void) {
	setbuf(stdout,NULL);
	int numeroA;
	int numeroB;
	/*int suma;
	int resta;
	int multiplicacion;
	int division;
	int factorialA;
	int factorialB;*/
	int opcion;
	int flagA;
	int flagB;
	int I;
	flagA=0;
	flagB=0;
	I=0;
	while(I==0)
	{
		printf("=====MENU DE OPCIONES=====\n\n");
		if(flagA==1){
			printf("1.Ingresar el primer operando.(A=%d)\n",numeroA);
		}
		else
		{
			printf("1.Ingresar el primer operando.(A=x)\n");
		}

		if(flagB==1){
			printf("1.Ingresar el primer operando.(B=%d)\n",numeroB);
			}
		else
		{
			printf("2.Ingresar el segundo operando.(B=y)\n");
		}

		printf("3.Calcular todas las operaciones.\n");
		printf("4.Informar resultado.\n");
		printf("5.Salir.\n");
		printf("seleccione una opcion:");
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			PedirNumero("Ingresar el operando A:",&numeroA);
			flagA=1;
			break;
		case 2:
			PedirNumero("Ingresar el operando B:",&numeroB);
			flagB=1;
				break;
		/*case 3:

				break;
		case 4:
				break;*/
		case 5:
			I=1;
				break;
		default:
			printf("Error, ingrese otra opcion:");
			scanf("%d",&opcion);
				break;

		}
		break;
	}



	return EXIT_SUCCESS;
}
