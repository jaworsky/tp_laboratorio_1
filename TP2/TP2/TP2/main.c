#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define VACIO 1
#define LLENO 0
#define SIZE 4


int main()
{

Employee listadoEmployee[SIZE]; //defino la lista.
int opcion;
int auxInt;
int indice;
int autoLeg=1;
int flagempelado=0; // tener en cuenta para los case, no poder entrar if flgag==0

initEmployees(listadoEmployee,SIZE);

        do
        {
        switch(menu())
        {
        case 1: // Alta de empleado.
        indice=cargarListadoDeEmpleados(listadoEmployee,SIZE,autoLeg);

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
            }
        break;

        case 2: // modificar.

        if(flagempelado==0)
        {
            printf("Error, primero cargue un empleado!\n");
            system("pause");
            break;
        }

        modificaEmployee(listadoEmployee, SIZE);

        break;

        case 3: // Baja de empleado

         if(flagempelado==0)
        {
            printf("Error, primero cargue un empleado!\n");
            system("pause");
            break;
        }

        bajaEmployee(listadoEmployee,SIZE);

        break;

        case 4: // informar.

         if(flagempelado==0)
        {
            printf("Error, primero cargue un empleado!\n");
            system("pause");
            break;
        }

        mostrarListadoDeEmpleados(listadoEmployee,SIZE);
        system("pause"); // para que me lo permita ver.

        break;

        case 5: // ingresa 5 para salir.
        opcion=5;
        break;
        }

        }while(opcion!=5);

    return 0;
}
