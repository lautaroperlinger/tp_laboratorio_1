#include "ArrayEmployees.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define True 1
#define False 0

//DESARROLLO DE FUNCIONES DE LA BIBLIOTECA ARRAYEMPLOYEES Y OTRAS.
int initEmployees(eEmployee List[],int len)
{
    for(int i=0; i<len; i++)
    {
        List[i].isEmpty = False;
    }
    return 0;
}

int addEmployee(eEmployee List[],int len,char name[],char lastname[],float salary,int sector)
{
    int i;
    int error=0;
    i=freeSite(List,len);
    if(i!=-1)
        {
            List[i].ID=i;
            strcpy(List[i].Name,name);
            strcpy(List[i].LastName,lastname);
            List[i].Salary=salary;
            List[i].Sector=sector;
            List[i].isEmpty=True;
            error=-1;
            mostrarEmpleado(List,List[i].ID);
            system("pause");
        }
    else
        {
            error=1;
            printf("no hay memoria.");
        }
    return error;
}

int findEmployeeByID(eEmployee List[],int len, int id)
{
    int empleado=-1;
       for(int i=0;i<len;i++)
        {
            if(List[id].isEmpty==True)
            {
                if(List[i].ID==id)
                {
                    empleado=i;
                }
            }

        }



    return empleado;
}

int removeEmployee(eEmployee List[],int len,int id)
{
    int error=0;
    if(List[id].isEmpty!=-1)
    {
        List[id].isEmpty=False;
    }
    else
    {
        printf("no existe ese empleado.");
        error=1;
    }
    return error;

}

int sortEmployees(eEmployee List[],int len)
{
    int error=0;
    char auxcadena[nombres];
    int auxint;
    float auxfloat;

    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(List[i].isEmpty==True&&List[j].isEmpty==True)
            {
                if(strcmp(List[i].LastName,List[j].LastName)>0&&List[i].Sector>List[j].Sector)
                {
                    strcpy(auxcadena, List[i].LastName);
                    strcpy(List[i].LastName, List[j].LastName);
                    strcpy(List[j].LastName, auxcadena);

                    auxint = List[i].Sector;
                    List[i].Sector = List[j].Sector;
                    List[j].Sector = auxint;

                    strcpy(auxcadena, List[i].Name);
                    strcpy(List[i].Name, List[j].Name);
                    strcpy(List[j].Name, auxcadena);

                    auxint = List[i].ID;
                    List[i].ID = List[j].ID;
                    List[j].ID = auxint;

                    auxfloat = List[i].Salary;
                    List[i].Salary = List[j].Salary;
                    List[j].Salary = auxfloat;
                }
                else
                {
                    error=1;
                }
            }
            else
            {
                error=1;
            }
        }
    }
    return error;
}

int printEmployees(eEmployee List[],int length)
{
    for(int i=0;i<length;i++)
    {
        if(List[i].isEmpty!=False)
        {
            mostrarEmpleado(List,List[i].ID);
        }
    }
    return 0;
}
int freeSite(eEmployee List[],int len)//pone true en la bandera isEmpty
{
    int ver=-1;

    for(int i=0;i<len;i++)
    {
        if(List[i].isEmpty==False)
        {
            ver=i;
        }
    }
    return ver;
}

int pedirInt(char mensaje[])
{
    int entero;
    printf("%s*",mensaje);
    scanf("%d", &entero);

    return entero;
}
float pedirFlo(char mensaje[])
{
    float flo;
    printf("%s*",mensaje);
    scanf("%f", &flo);
    return flo;
}
void pedirString(char mensaje[],char palabra[],int len)
{
    printf("%s*",mensaje);
    fflush(stdin);
    gets(palabra);
    verificacionNombre(palabra,len);
}
void verificacionNombre(char palabra[],int len)
{
    while(strlen(palabra)>len)
    {
        printf("el nombre es demasiado largo. reingrese nombre:\n");
        fflush(stdin);
        gets(palabra);
    }

}
void mostrarEmpleado(eEmployee List[],int posicion)
{
    printf("ID: %d \n Nombre: %s* \n Apellido: %s*\n Salario: %2.f\n Sector: %d\n", List[posicion].ID,List[posicion].Name,List[posicion].LastName,List[posicion].Salary,List[posicion].Sector);
}
void modificarEmpleado(eEmployee List[],int id,int opcion,char name[],char lastname[],float salary,int sector)
{
    if(List[id].isEmpty==True)
    {
        switch(opcion)
        {
        case 1:
            pedirString("Nombre: \n",name,nombres);
            fflush(stdin);
            strcpy(List[id].Name,name);
            break;
        case 2:
            pedirString("Apellido: ",lastname,nombres);
            fflush(stdin);
            strcpy(List[id].LastName,lastname);
            break;
        case 3:
            List[id].Salary=pedirFlo("Salario: \n");
            break;
        case 4:
            List[id].Sector=pedirInt("Sector: \n");
            break;
        default:
            printf("opcion incorrecta.");
            break;
        }
    }

}
int MenuModificar(char mensaje[], char opcion1[], char opcion2[],char opcion3[],char opcion4[])
{
    int opcion;
    printf("%s*\n",mensaje);
    printf("1.%s*.\n",opcion1);
    printf("2.%s*.\n",opcion2);
    printf("3.%s*.\n",opcion3);
    printf("4.%s*.\n",opcion4);
    scanf("%d", &opcion);
    return opcion;
}
float PromedioSalario(eEmployee List[],int len)
{
    float promediogeneral;
    int contador=0;

    for(int i=0;i<len;i++)
    {
        if(List[i].isEmpty==True)
        {
        promediogeneral+=List[i].Salary;
        contador++;
        }
    }
    promediogeneral=promediogeneral/contador;
    return promediogeneral;
}
