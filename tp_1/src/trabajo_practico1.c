/*
 ============================================================================
 Name        : trabajo_practico1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main(void) {
	setbuf(stdout,NULL);
	int numeroA;
	int numeroB;
	int suma;
	int resta;
	int multiplicacion;
	float division;
	int factorialA;
	int factorialB;
	int opcion;
	int flagA;
	int flagB;
	int I;
	flagA=0;
	flagB=0;
	I=0;

	do{
		printf("\n=====MENU DE OPCIONES=====\n\n");
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
		case 3:
			if(flagA==1&&flagB==1)
			{
				suma=Sumar(numeroA,numeroB);
				resta=Restar(numeroA,numeroB);
				multiplicacion=Multiplicar(numeroA,numeroB);
				division=Dividir(numeroA,numeroB);
				if(ValidarSigno(numeroA)!=-1)
				{
					factorialA=Factorial(numeroA);
				}
				if(ValidarSigno(numeroB)!=-1)
				{
					factorialB=Factorial(numeroB);
				}
				puts("se calcularon todas las operaciones.\n");
				system("pause");
			}
			else
			{
				puts("tiene que ingresar primero un dato.\n");
				system("pause");
			}
				break;
		case 4:
			if(flagA==1&&flagB==1)
			{
			printf("la suma de %d + %d es: %d\n",numeroA,numeroB,suma);
			printf("la resta de %d - %d es: %d\n",numeroA,numeroB,resta);
			printf("la multiplicacion de %d * %d es: %d\n",numeroA,numeroB,multiplicacion);
			if(ValidarSigno(numeroB)==0)
				{
				puts("no se puede dividir por 0.\n");
				}
			else
				{
				printf("la division de %d y %d es :%f\n",numeroA,numeroB,division);
				}
			if(ValidarSigno(numeroA)==-1)
			{
				puts("no se puede calcular el factorial de un negativo\n");
			}
			else
			{
				printf("el factorial del numero A es: %d.\n",factorialA);
			}
			if(ValidarSigno(numeroB)==-1)
			{
				puts("no se puede calcular el factorial de un negativo\n");
			}
			else
			{
				printf("el factorial del numero B es: %d\n",factorialB);
			}
			system("pause");
			}
			else
			{
				puts("primero tiene que ingresar un dato.\n");
				system("pause");
			}
				break;
		case 5:
			I=1;
				break;
		default:
			puts("Error, ingrese otra opcion:");
		}
	}while(I==0);
	return EXIT_SUCCESS;
}
