#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define VACIO 1
#define LLENO 0
#define SIZE 1000

int main()
{

Employee listEmployee[SIZE];
int opcion;
int indice;
int autoLeg=1;
int flagempelado=0;

initEmployees(listEmployee,SIZE);

        do
        {

        switch(menu())
        {
        case 1: // Alta de empleado.
        indice=loadListEmployee(listEmployee,SIZE,autoLeg);

                   if(indice!=-1)
            {
                printf("Carga exitosa!!! \n");
                autoLeg++;
                flagempelado=1;
                system("pause");
            }
            else
            {
                printf("No hay mas espacio en el sistema!!! \n");
                system("pause");
            }

        break;

        case 2: // modificar.

        if(flagempelado==0)
        {
            printf("Error, primero cargue un empleado!\n");
            system("pause");
            break;
        }

        modificaEmployee(listEmployee, SIZE);

        break;

        case 3: // Baja de empleado

         if(flagempelado==0)
        {
            printf("Error, primero cargue un empleado!\n");
            system("pause");
            break;
        }

        lowEmployee(listEmployee,SIZE);

        break;

        case 4: // informar.

         if(flagempelado==0)
        {
            printf("Error, primero cargue un empleado!\n");
            system("pause");
            break;
        }

        printf("\nInformando listado de empleados: \n");
        printListEmployee(listEmployee,SIZE);
        sortEmployees(listEmployee,SIZE);
        system("pause"); // para que me lo permita ver.
        break;

        case 5: // ingresa 5 para salir.
        opcion=5;
        break;
        }

        }while(opcion!=5);

    return 0;
}
