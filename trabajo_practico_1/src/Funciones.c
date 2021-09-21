/*
 * Funciones.c
 *
 *  Created on: 19 sep. 2021
 *      Author: lauta
 */

#include "Funciones.h"

void PedirNumero(char mensaje[],int* numero)
{
	int auxnumero;
	printf("%s",mensaje);
	scanf("%d",&auxnumero);

	*numero=auxnumero;
}
