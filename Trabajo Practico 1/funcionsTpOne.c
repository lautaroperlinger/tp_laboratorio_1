
#include "funcionesTpOne.h"

//EN ESTE ARCHIVO ESTAN LOS DESARROLLOS DE CADA FUNCION

int sumar(int A, int B)//DESARROLLO DE LA FUNCION SUMA
{
    int resultado_suma;
    resultado_suma=A+B;
    return resultado_suma;
}
int restar(int A, int B)//DESARROLLO DE LA FUNCION RESTAR
{
    int resultado_resta;
    resultado_resta=A-B;
    return resultado_resta;
}
float dividir(float A, float B)//DESARROLLO DE LA FUNCION DIVIDIR
{
    float resultado_division;
    resultado_division=A/B;
    return resultado_division;
}
int multiplicar(int A, int B)//DESARROLLO DE LA FUNCION MULTIPLICAR
{
    int resultado_multiplicacion;
    resultado_multiplicacion=A*B;
    return resultado_multiplicacion;
}
int factorizar(int operando)//DESARROLLO DE LA FUNCION FACTORIZAR
{
    int resultado_factorizacion;
    if(operando==0||operando==1)
    {
        resultado_factorizacion=1;
    }
    else
    {
        resultado_factorizacion=operando*factorizar(operando-1);
    }
    return resultado_factorizacion;
}

