#include <stdio.h>
#include <stdlib.h>
#include "funcionesTpOne.h"
#include <ctype.h>
int main()
{
    int num_A;
    int num_B;
    int banderaA;
    int banderaB;
    int bandera_error;
    int suma;
    int resta;
    int multiplicacion;
    int factorizacionA;
    int factorizacionB;
    int opcion;
    int confirmacion;
    float division;
    banderaA=0;
    banderaB=0;
    bandera_error=0;
    while(opcion!=5)
    {
        printf("MENU DE LA CALCULADORA:\n");
        if(banderaA==0)
        {
            printf("1. ingrese el primer operando. (A=x)\n");
        }
        else
        {
            printf("1. ingrese el primer operando. (A=%d)\n",num_A);
        }
        if(banderaB==0)
        {
            printf("2. ingrese el segundo operando. (B=y)\n");
        }
        else
        {
            printf("2. ingrese el segundo operando. (B=%d)\n",num_B);
        }
        printf("3. calcular todas las operaciones.\n");
        printf("4. mostrar resultados.\n");
        printf("5. SALIR.\n");

        printf("INGRESE UNA OPCION:\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("ingrese el primer operando:\n");
                scanf("%d", &num_A);
                banderaA=1;
                break;
            case 2:
                printf("ingrese el segundo operando:\n");
                scanf("%d", &num_B);
                banderaB=1;
                break;
            case 3:
                printf("Calculando resultados.\n");
                suma=sumar(num_A,num_B);
                resta=restar(num_A,num_B);
                division=dividir(num_A,num_B);
                multiplicacion=multiplicar(num_A,num_B);
                factorizacionA=factorizar(num_A);
                factorizacionB=factorizar(num_B);
                if(num_A==0||num_B==0)
                {
                    bandera_error=1;
                }
                system("pause");
                break;
            case 4:
                printf("El resultado de %d+%d es: %d\n",num_A,num_B,suma);
                printf("El resultado de %d-%d es: %d\n",num_A,num_B,resta);
                if(bandera_error==1)
                {
                    printf("No es posible dividir por cero.\n");
                }
                else
                {
                    printf("El resultado de %d/%d es: %f\n",num_A,num_B,division);
                }
                printf("El resultado de %d*%d es: %d\n",num_A,num_B,multiplicacion);
                if(num_A>=12&&num_B>=12)
                {
                    printf("un numero no se puede factorizar.");
                }
                else
                {
                    printf("El factorial de %d es: %d y El factorial de %lld es: %lld\n",num_A,factorizacionA,num_B,factorizacionB);
                }
                system("pause");
                break;
            case 5:
                break;
        }
        system("cls");
    }
    return 0;
}


