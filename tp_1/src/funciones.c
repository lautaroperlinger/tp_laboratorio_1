/*
 * funciones.c
 *
 *  Created on: 21 sep. 2021
 *      Author: lauta
 */

#include "funciones.h"

void PedirNumero(char mensaje[],int* numero)
{
	int auxnumero;
	printf("%s",mensaje);
	scanf("%d",&auxnumero);

	*numero=auxnumero;
}

int Sumar(int numerouno,int numerodos)
{
	int resultado;
		resultado=numerouno+numerodos;
		return resultado;
}
int Restar(int numerouno,int numerodos)
{
	int resultado;
		resultado=numerouno-numerodos;
		return resultado;
}
int Multiplicar(int numerouno,int numerodos)
{
	int resultado;
		resultado=numerouno*numerodos;
		return resultado;
}
int Dividir(int numerouno,int numerodos)
{
	int resultado;
		resultado=numerouno/numerodos;
	return resultado;

}
int Factorial(int numero)
{
	int resultado;

		if(numero==0)
		{
			resultado=1;
		}
		else
		{
			resultado=numero*Factorial(numero-1);
		}
		return resultado;
}
int ValidarSigno(int numero)
{
	int resultado;
	resultado=0;
	if(numero>0)
	{
		resultado=1;
	}
	else
	{
		if(numero<0)
		{
			resultado=-1;
		}
	}
	return resultado;
}
