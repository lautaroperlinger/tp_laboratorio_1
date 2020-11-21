#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define TAM 1000
#define nombres 51
int main()
{
    eEmployee Listado[TAM];
    int opcion;
    int auxopcion;
    int flag=0;
    int auxsector;
    int auxID;
    char auxname[nombres];
    char auxlastname[nombres];
    float auxsalary;
    float promedio;




    initEmployees(Listado,TAM);
    do
    {

    printf("MENU DE OPCIONES.\n");
    printf("1.Alta de empleado.\n");
    printf("2.Modificar empleado.\n");
    printf("3.Baja de empleado.\n");
    printf("4.Informar empleado.\n");
    printf("5.Salir.\n");
    printf("ingrese opcion.\n");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:

        pedirString("ingrese Nombre: ",auxname,nombres);
        pedirString("ingrese Apellido: ",auxlastname,nombres);
        auxsalary=pedirFlo("ingrese Salario: ");
        auxsector=pedirInt("ingrese sector: ");
        addEmployee(Listado,TAM,auxname,auxlastname,auxsalary,auxsector);
        flag=1;
            break;
    case 2:
        if(flag==1)
        {
            printf("ingrese el ID del empleado.\n");
            scanf("%d", &auxID);
            auxID=findEmployeeByID(Listado,TAM,auxID);
            mostrarEmpleado(Listado,auxID);
            auxopcion=MenuModificar("Que quiere modificar?","nombre","apellido","salario","sector");
            modificarEmpleado(Listado,auxID,auxopcion,auxname,auxlastname,auxsalary,auxsector);
        }
        else
        {
            printf("primero se tiene que agregar un empleado.\n");
            system("pause");
        }
        break;
    case 3:
        if(flag==1)
        {
            printf("ingrese el ID del empleado.\n");
            scanf("%d", &auxID);
            auxID=findEmployeeByID(Listado,TAM,auxID);
            mostrarEmpleado(Listado,auxID);
            printf("quiere dar de baja este empleado?\n 1.si\n 2.no\n");
            scanf("%d", &auxopcion);
            if(auxopcion==1)
            {
                removeEmployee(Listado,TAM,auxID);
                flag=0;
            }
        }
        else
        {
            printf("primero se tiene que agregar un empleado.\n");
            system("pause");
        }
        break;
    case 4:
        if(flag==1)
        {
            sortEmployees(Listado,TAM);
            printEmployees(Listado,TAM);
            promedio=PromedioSalario(Listado,TAM);
            printf("el promedio de salarios es: %.2f",promedio);
            system("pause");
        }
        else
        {
         printf("primero se tiene que agregaar un empleado. \n");
         system("pause");
        }

        break;
    }
    system("cls");
    }while(opcion!=5);

    return 0;
}
