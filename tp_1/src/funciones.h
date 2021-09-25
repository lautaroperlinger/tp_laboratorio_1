/*
 * funciones.h
 *
 *  Created on: 21 sep. 2021
 *      Author: lauta
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/// \fn void PedirNumero(char[], int*)
/// \brief pide el ingreso de un entero
///
/// \pre
/// \post
/// \param mensaje
/// \param numero
void PedirNumero(char mensaje[],int* numero);
/// \fn int Sumar(int, int)
/// \brief suma los 2 numeros que pide
///
/// \pre
/// \post
/// \param numerouno
/// \param numerodos
/// \return retorna el total
int Sumar(int numerouno,int numerodos);
/// \fn int Restar(int, int)
/// \brief resta los 2 numeros que pide
///
/// \pre
/// \post
/// \param numerouno
/// \param numerodos
/// \return retorna la resta
int Restar(int numerouno,int numerodos);
/// \fn int Multiplicar(int, int)
/// \brief multiplica los 2 numeros que pid
///
/// \pre
/// \post
/// \param numerouno
/// \param numerodos
/// \return retorna la multiplicacion total
int Multiplicar(int numerouno,int numerodos);
/// \fn int Dividir(int, int)
/// \brief divide 2 numeros enteros
///
/// \pre
/// \post
/// \param numerouno
/// \param numerodos
/// \return retorna el total de la division
float Dividir(int numerouno,int numerodos);
/// \fn int Factorial(int)
/// \brief realiza el factorial del numero que se ingreso
///
/// \pre
/// \post
/// \param numero
/// \return retorna el total del factorial del numero
int Factorial(int numero);
/// \fn int ValidarSigno(int)
/// \brief valida el signo dependiendo si es positivo, negativo o cero
///
/// \pre
/// \post
/// \param numero
/// \return retorna 1 si es positivo, -1 si es negativo y 0 si es cero
int ValidarSigno(int numero);


#endif /* FUNCIONES_H_ */
