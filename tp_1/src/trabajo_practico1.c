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
	int flagOpcion3;
	int I;
	flagA=0;
	flagB=0;
	flagOpcion3=0;
	I=0;

	do{
		//empieza el menu de opciones
		printf("\n=====MENU DE OPCIONES=====\n\n");
		if(flagA==1){
			printf("1.Ingresar el primer operando.(A=%d)\n",numeroA);// mmuestra el cambio de valor de la variable
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
		scanf("%d",&opcion);// ingresa la opcion que selecciono el usuario

		switch(opcion)
		{
		case 1:
			PedirNumero("Ingresar el operando A:",&numeroA);//pide el primer numero
			flagA=1;// bandera que ayuda a mostrar la variable en el menu
			break;
		case 2:
			PedirNumero("Ingresar el operando B:",&numeroB);// pide el segundo numero
			flagB=1;// bandera que ayuda a mostrar la variable en el menu
				break;
		case 3:
			if(flagA==1&&flagB==1)// este if sirve para mostrarle al usuario si se puede usar la opcion 3
			{
				//realiza las operaciones
				suma=Sumar(numeroA,numeroB);
				resta=Restar(numeroA,numeroB);
				multiplicacion=Multiplicar(numeroA,numeroB);
				division=Dividir(numeroA,numeroB);
				if(ValidarSigno(numeroA)!=-1)// valida el numero por que no se puede hacer el factorial de un negativo
				{
					factorialA=Factorial(numeroA);
				}
				if(ValidarSigno(numeroB)!=-1)
				{
					factorialB=Factorial(numeroB);
				}
				flagOpcion3=1;
				puts("se calcularon todas las operaciones.\n");
				system("pause");
			}
			else// si no se ingresaron valores de los operando muestra que no se puede usar la opcion 3
			{
				puts("tiene que ingresar primero un dato.\n");
				system("pause");
			}
				break;
		case 4:
			if(flagA==1&&flagB==1&&flagOpcion3==1)// verifica que se haya ingresado los operandos y se realizo el calculo de operaciones
			{
			printf("la suma de %d + %d es: %d\n",numeroA,numeroB,suma);
			printf("la resta de %d - %d es: %d\n",numeroA,numeroB,resta);
			printf("la multiplicacion de %d * %d es: %d\n",numeroA,numeroB,multiplicacion);
			if(ValidarSigno(numeroB)==0)// si el divisior en 0 no realiza la division
				{
				puts("no se puede dividir por 0.\n");
				}
			else
				{
				printf("la division de %d y %d es :%f\n",numeroA,numeroB,division);
				}
			if(ValidarSigno(numeroA)==-1)// si el numero es negativo no se puede calcular el factorial.
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
				puts("primero tiene que ingresar un dato y realizar el calculo de operaciones.\n");
				system("pause");
			}
				break;
		case 5: // paara salir cambia el valor de la variable de la estructura repetitiva
			I=1;
				break;
		default://si ingresa un numero diferente pide que se ingrese de nuevo.
			puts("Error, ingrese otra opcion:");
		}
	}while(I==0);
	return EXIT_SUCCESS;
}
