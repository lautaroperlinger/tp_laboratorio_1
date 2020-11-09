#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "LinkedList.h"

    /****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
    *****************************************************/

int menu();
int main()
{
    LinkedList* Empleados = ll_newLinkedList();
    int seguir=1;
    do
    {
        switch(menu())
        {
        case 1:
            controller_loadFromText("data.csv",Empleados);
            printf("Carga exitosa");
            break;
        case 2:
            controller_loadFromBinary("data.dat",Empleados);

            break;
        case 3:
            controller_addEmployee(Empleados);
            printf("Empleado añadido exitosamente\n");
            break;
        case 4:
            controller_editEmployee(Empleados);
            printf("Edicion exitosa\n");
            break;
        case 5:
            controller_removeEmployee(Empleados);
            break;
        case 6:
            controller_ListEmployee(Empleados);
            break;
        case 7:
            controller_sortEmployee(Empleados);
            break;
        case 8:
            controller_saveAsText("data.csv",Empleados);
            break;
        case 9:
            controller_saveAsBinary("data.dat",Empleados);
            break;
        case 10:
            ll_deleteLinkedList(Empleados);
            seguir=0;
            break;
        default:
            printf("Opcion invalida");
            break;
        }
        system("pause");
        system("cls");
    }
    while(seguir!=0);

    return 0;
}
int menu()
{
    int opcion;
    printf("MENU DE OPCIONES:\n");
    printf("-----------------\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    return opcion;
}
