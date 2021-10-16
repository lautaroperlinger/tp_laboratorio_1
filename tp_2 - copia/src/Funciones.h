/*
 * Funciones.h
 *
 *  Created on: 5 oct. 2021
 *      Author: lauta
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/// \fn void Menu(int*, char[], char[], int, int)
/// \brief Menu de opciones que devuelve la respuesta
///
/// \pre
/// \post
/// \param opcion
/// \param mensaje
/// \param mensajeError
/// \param maximo
/// \param minimo
void Menu(int* opcion,char mensaje[],char mensajeError[],int maximo,int minimo);
/// \fn int ValidarCadena(char[])
/// \brief Valida que la cadena de caracteres que se ingrese sea solo caracteres
///
/// \pre
/// \post
/// \param cadena
/// \return devuelve 1 si es cadena o 0 si es numero
int ValidarCadena(char cadena[]);
/// \fn void PedirCadena(char[], char[], int)
/// \brief Pide al usuario una cadena y la valida
///
/// \pre
/// \post
/// \param cadena
/// \param mensaje
/// \param tamanio
void PedirCadena(char cadena[],char mensaje[],int tamanio);
/// \fn int ValidarEntero(int*)
/// \brief Valida el entero para que no sean caracteres
///
/// \pre
/// \post
/// \param entero
/// \return retorno 1 si es cadena o 0 si es numerio
int ValidarEntero(int* entero);
/// \fn void PedirEntero(int*, char[], int, int)
/// \brief Pide el entero al usuario y lo valida
///
/// \pre
/// \post
/// \param entero
/// \param mensaje
/// \param minimo
/// \param maximo
void PedirEntero(int* entero,char mensaje[],int minimo,int maximo);
/// \fn void PedirFlotante(char[], float*, float)
/// \brief Pide un flotante al usuario
///
/// \pre
/// \post
/// \param mensaje
/// \param flotante
/// \param tamanioMinimo
void PedirFlotante(char mensaje[],float* flotante,float tamanioMinimo);

#endif /* FUNCIONES_H_ */
