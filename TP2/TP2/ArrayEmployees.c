#include <stdio.h>
#include "ArrayEmployees.h"
#define VACIO 1
#define LLENO 0

//

int menu()
{

        int opcion;

        system("cls");
        printf("\n*** Bienvenido!!***\n");
        printf("\n*** Menu de opciones ***\n\n\n");
        printf("1-Alta de Empleado\n");
        printf("2-Modificar Datos\n");
        printf("3-Baja de Empleado\n");
        printf("4-Informes\n"); // en este caso, informar los 2 puntos
        printf("5-Salir\n");
        printf("\nIngrese la Opcion deseada: ");
        scanf("%d",&opcion);

        return opcion;


}



//
int initEmployees(Employee listado[], int tam) // pone en 1 las posiciones del array
{


  for(int i=0;i<tam;i++)
    {
        listado[i].isEmpty = VACIO;
    }


}

//

Employee addEmployee(int legajo)
{

    Employee empleadoLocal;

    // averiguar como poner legajo automatico
    empleadoLocal.id=legajo;

    printf("Ingrese el nombre del empleado: \n");
    fflush(stdin);
    gets(empleadoLocal.name);

    printf("Ingrese el apellido del empleado: \n");
    fflush(stdin);
    gets(empleadoLocal.lastName);

    printf("Ingrese el salario: \n"); // usar getFloat.
    scanf("%f",&empleadoLocal.salary);

    printf("Ingrese el sector: \n");
    scanf("%d",&empleadoLocal.sector);

    return empleadoLocal;

}
//

int buscarLibre(Employee listado[], int tam) // devuelve el indice vacio para poder cargar un dato.

{
    int i;
    int flag=-1; // para saber si estan todos llenos

    for(i=0; i<tam; i++)
     {
         if(listado[i].isEmpty==VACIO) // el estado esta vacio
         {
             flag=i;
             break; // para que corte al encontrar
         }


     }

    return flag;

}

//

int cargarListadoDeEmpleados(Employee listado[], int tam,int legajo)
{
    int index;

    index=buscarLibre(listado,tam); // le paso el array listado de alumnos y el tam.

    if(index!=-1)
    {
             listado[index]=addEmployee(legajo);
             listado[index].isEmpty=LLENO;
    }

    return index;

}

// mostrar todo el listado.

void mostrarListadoDeEmpleados(Employee listado[], int tam)
{
    int i;

    for(i=0;i<tam;i++) // barrido para mostrar el vector alumnos
   {
       if(listado[i].isEmpty==0) // para q no me muestre la basura
        {
         mostrarUnEmpleado(listado[i]);//puede variar el que le paso
        }

   }

}

//

void mostrarUnEmpleado (Employee empleadoAmostrar) // siemrpe le voy a pasar un alumno
{
    printf("El ID es: %d, Nombre: %s, Apellido: %s, Salario: %f, Pertenece al sector: %d,  \n",empleadoAmostrar.id,empleadoAmostrar.name,empleadoAmostrar.lastName,empleadoAmostrar.salary,empleadoAmostrar.sector);
}

// FUNCION IMPORTANTE PARA BUSCAR UN EMPLEADO EN NUESTRO SISTEMA.

int buscarUnEmployee(Employee listado[], int tam, int legajo)
{
    {
    int i;
    int indice=-1; // no esta repetido, se arranca pesimista.

    for(i=0; i<tam; i++)
     {
         if(listado[i].id==legajo && listado[i].isEmpty==0) // chequea si esta el mismo legajo
         {
             indice=i; // devuelve el indice del empleado a modficiar.
             break; // para que corte al encontrar el primero, sino devolveria el ultimo.
         }
     }

    return indice; // devuelvo el indice que esta disponible para cargar.
}

}

// Baja empleado de nuestro sistema ( encontrandolo con el valor de la funcion buscarempleado

void bajaEmployee(Employee listado[], int tam)
{

int id;
int indice;
char seguir;

    printf("Ingrese el legajo: \n");
    scanf("%d",&id);

    indice = buscarUnEmployee(listado,tam,id);
    if(indice==-1)
    {
        printf("No existe ese empleado en nuestro sistema!\n");
        system("pause");
    }
    else
    {
        mostrarUnEmpleado(listado[indice]); // le paso el array y el indice de empleado a mostrar.
        printf("Esta seguro de borrar este empleado? s/n: \n");
        fflush(stdin);
        scanf("%c",&seguir);

        if(seguir=='n')
        {
            printf("Baja cancelada!!! \n");
        }
        else
        {
            listado[indice].isEmpty=1;
            printf("Borrado Exitoso!!!\n");
        }
        system("pause");

    }


}

// Para modificar employee

void modificaEmployee(Employee listado[], int tam)
{

int id;
int indice;
char seguir;
int opcion;

    printf("Ingrese el legajo: \n");
    scanf("%d",&id);

    indice = buscarUnEmployee(listado,tam,id);
    if(indice==-1)
    {
        printf("No existe ese empleado en nuestro sistema!\n");
        system("pause");
    }
    else
    {
        mostrarUnEmpleado(listado[indice]); // le paso el array y el indice de empleado a mostrar.
        printf("Esta seguro de modificar este empleado? s/n: \n");
        fflush(stdin);
        scanf("%c",&seguir);

        if(seguir=='n')
        {
            printf("Modificacion cancelada!!! \n");
        }
        else
        {
            printf("\nIngrese opcion a modificar:\n 1.Nombre \n 2.Apellido\n 3.Salario\n 4.Sector\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {

            case 1:
            printf("Ingrese el nuevo nombre del empleado: \n");
            fflush(stdin);
            gets(listado[indice].name);
            printf("Nombre modificado con exito!!\n");
            break;

            case 2:
            printf("Ingrese el nuevo apellido del empleado: \n");
            fflush(stdin);
            gets(listado[indice].lastName);
            printf("Apellido modificado con exito!!\n");
            break;

            case 3:
            printf("Ingrese el nuevo salario del empleado: \n");
            fflush(stdin);
            scanf("%f",&listado[indice].salary);
            printf("Salario modificado con exito!!\n");
            break;

            case 4:
            printf("Ingrese el nuevo sector del empleado: \n");
            fflush(stdin);
            scanf("%d",&listado[indice].sector);
            printf("sector modificado con exito!!\n");
            break;

            }


        }
        system("pause");

    }


}

//
