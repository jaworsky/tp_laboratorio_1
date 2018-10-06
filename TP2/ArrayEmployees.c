#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include <string.h>
#include <ctype.h>
#define VACIO 1
#define LLENO 0

//

int menu()
{
        char auxOpcion[10];
        int opcion;

        system("cls");
        printf("\n*** Bienvenido!!***\n");
        printf("\n*** Menu de opciones ***\n\n\n");
        printf("1-Alta de Empleado\n");
        printf("2-Modificar Datos\n");
        printf("3-Baja de Empleado\n");
        printf("4-Informes\n"); // en este caso, informar los 2 puntos
        printf("5-Salir\n");

        while(!function_getStringNumeros("Ingrese la opcion deseada: \n",auxOpcion))
        {

            {
            printf("Error ingrese una opcion numerica del 1 al 5\n.");
            system("pause");
            fflush(stdin);
            }
        }

            opcion=atoi(auxOpcion);

            if(opcion<1 || opcion>5)
            {
            printf("Error ingrese una opcion numerica del 1 al 5\n.");
            system("pause");
            fflush(stdin);
            }

    return opcion;

}

//

void initEmployees(Employee listado[], int tam)
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
    char auxName[21];
    char auxLastName[21];
    char auxSalary[10] ;
    char auxSector[10] ;

    empleadoLocal.id=legajo;

     while(!function_getStringLetras("Ingrese el nombre del empleado: \n",auxName))
            {
                printf("Recuerde, el nombre solo debe tener letras.\n");
            }

    while(!function_getStringLetras("Ingrese el apellido del empleado: \n",auxLastName))
            {
                printf("Recuerde, el apellido solo debe tener letras.\n");
            }

    while(!function_getStringNumeros("Ingrese el salario del empleado: \n",auxSalary))
            {
                printf("Error el salario debe ser numerico.\n");
            }

    while(!function_getStringNumeros("Ingrese el sector del empleado: \n",auxSector))
            {
                printf("Error el sector debe ser numerico.\n");
            }

    strcpy(empleadoLocal.name,auxName) ;
    strcpy(empleadoLocal.lastName,auxLastName);
    empleadoLocal.sector=atoi(auxSector);
    empleadoLocal.salary=atoi(auxSalary);

    return empleadoLocal;

}
//

int searchFreeIndex(Employee listado[], int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
     {
         if(listado[i].isEmpty==VACIO)
         {
             flag=i;
             break;
         }
     }
    return flag;
}

//

int loadListEmployee(Employee listado[], int tam,int legajo)
{
    int index;
    index=searchFreeIndex(listado,tam);

    if(index!=-1)
    {
             listado[index]=addEmployee(legajo);
             listado[index].isEmpty=LLENO;
    }
    return index;
}

//

void printListEmployee(Employee listado[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
   {
       if(listado[i].isEmpty==0)
        {
         printEmployee(listado[i]);
        }
   }
}

//

void printEmployee (Employee empleadoAmostrar)
{
    printf("El ID es: %d, Nombre: %s, Apellido: %s, Salario: %.2f, Pertenece al sector: %d,  \n",empleadoAmostrar.id,empleadoAmostrar.name,empleadoAmostrar.lastName,empleadoAmostrar.salary,empleadoAmostrar.sector);
}

//

int SearchEmployee(Employee listado[], int tam, int legajo)
{
    {
    int i;
    int indice=-1;
    for(i=0; i<tam; i++)
        {
         if(listado[i].id==legajo && listado[i].isEmpty==0)
            {
             indice=i;
             break;
            }
        }
    return indice;
    }
}

// Baja empleado de nuestro sistema ( encontrandolo con el valor de la funcion buscarempleado

void lowEmployee(Employee listado[], int tam)
{

int id;
char auxId[10];
int indice;
char seguir;

   while(!function_getStringNumeros("Ingrese el ID: ",auxId))
    {
        printf("Error ingrese un ID numerico\n.");
        break;
    }

    id=atoi(auxId);

    indice = SearchEmployee(listado,tam,id);

    if(indice==-1)
    {
        printf("No existe ese empleado en nuestro sistema!\n");
        system("pause");
    }
    else
    {
        printEmployee(listado[indice]);
        seguir=function_getChar("Esta seguro de borrar este empleado? s/n: \n");

        if(seguir=='s')
        {
            listado[indice].isEmpty=1;
            printf("Borrado Exitoso!!!\n");

        }
        else
        {
            printf("Baja cancelada, recuerde ingresar 's' para borrar el empleado! \n");
        }
        system("pause");
    }
}

//

void modificaEmployee(Employee listado[], int tam)
{

int id;
char auxId[10];
int indice;
char seguir;
int opcion;
char auxOpcion[10];
//variables para empleado.
char auxName[21];
char auxLastName[21];
char auxSalary[10] ;
char auxSector[10] ;

 while(!function_getStringNumeros("Ingrese el ID: ",auxId))
    {
        printf("Error ingrese un ID numerico\n.");
        break;
    }

    id=atoi(auxId);

    indice = SearchEmployee(listado,tam,id);
    if(indice==-1)
    {
        printf("No existe ese empleado en nuestro sistema!\n");
        system("pause");
    }
    else
    {
        printEmployee(listado[indice]);
        seguir=function_getChar("Esta seguro que desea modificar este empleado? s/n: \n");
        fflush(stdin);
        if(seguir=='s')
        {
            while(!function_getStringNumeros("\nIngrese opcion a modificar:\n 1.Nombre \n 2.Apellido\n 3.Salario\n 4.Sector\n",auxOpcion))//valido legajo siempre.
            {
                {
                printf("Error ingrese una opcion numerica del 1 al 4\n.");
                system("pause");
                fflush(stdin);
                }
            }

            opcion=atoi(auxOpcion);

            if(opcion<1 || opcion>5)
            {
            printf("Error ingrese una opcion numerica del 1 al 4\n.");
            fflush(stdin);
            }

            switch(opcion)
            {

            case 1:
            while(!function_getStringLetras("Ingrese el nuevo nombre del empleado: \n",auxName))
            {
                printf("Recuerde, el nombre solo debe tener letras.\n");
            }

            strcpy(listado[indice].name,auxName);

            printf("Nombre modificado con exito!!\n");
            break;

            case 2:
            while(!function_getStringLetras("Ingrese el nuevo apellido del empleado: \n",auxLastName))
            {
                printf("Recuerde, el apellido solo debe tener letras.\n");
            }

            strcpy(listado[indice].lastName,auxLastName);
            printf("Apellido modificado con exito!!\n");

            break;

            case 3:
            while(!function_getStringNumeros("Ingrese el nuevo salario del empleado: \n",auxSalary))
            {
                printf("Error el salario debe ser numerico.\n");
            }

            listado[indice].salary=atoi(auxSalary);

            printf("Salario modificado con exito!!\n");
            break;

            case 4:
            while(!function_getStringNumeros("Ingrese el nuevo sector del empleado: \n",auxSector))
            {
                printf("Error el sector debe ser numerico.\n");
            }
            listado[indice].sector=atoi(auxSector);
            printf("sector modificado con exito!!\n");
            break;
            }
        }
        else
        {
             printf("Modificacion cancelada, recuerde ingresar 's' para continuar con la modificacion!!! \n");
        }
      system("pause");
    }
}

//

void sortEmployees(Employee listado[], int tam)
{
    Employee auxEmployee;
    int opcion;
    char auxOpcion[10];
    printf("\nIngrese opcion: \n");

        while(!function_getStringNumeros("1.Listado de empleados ordenados ascendentemente\n2.Listado de empleados ordenados descendentemente\n3.Total y promedio de empleados y cuantos empleados superan el salario promedio\n4.Salir\n",auxOpcion))
        {

            {
            printf("Error ingrese una opcion numerica del 1 al 4\n.");
            system("pause");
            fflush(stdin);
            }
        }

            opcion=atoi(auxOpcion);
            if(opcion<1 || opcion>5)
            {
            printf("Error ingrese una opcion numerica del 1 al 4\n.");
            fflush(stdin);
            }

    switch(opcion)
    {

    case 1:
        for(int i = 0; i < tam-1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if(strcmp(listado[j].lastName, listado[i].lastName) > 0 && listado[j].isEmpty == 0 && listado[i].isEmpty == 0) // y estan ocupados
                {
                    auxEmployee = listado[i];
                    listado[i] = listado[j];
                    listado[j] = auxEmployee;
                }
                else if(strcmp(listado[j].lastName, listado[i].lastName) == 0 && listado[j].sector > listado[i].sector  && listado[j].isEmpty == 0 && listado[i].isEmpty == 0)
                {
                    auxEmployee = listado[i];
                    listado[i] = listado[j];
                    listado[j] = auxEmployee;
                }
            }
        }
        printf("\n\nEl ordenado ascendente se ha realizado con exito.\n");

        break;
    case 2:
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(strcmp(listado[j].lastName, listado[i].lastName) < 0  && listado[j].isEmpty == 0 && listado[i].isEmpty == 0)
                {
                    auxEmployee = listado[i];
                    listado[i] = listado[j];
                    listado[j] = auxEmployee;
                }
                else if(strcmp(listado[j].lastName, listado[i].lastName) == 0 && listado[j].sector < listado[i].sector  && listado[j].isEmpty == 0 && listado[i].isEmpty == 0)
                {
                    auxEmployee = listado[i];
                    listado[i] = listado[j];
                    listado[j] = auxEmployee;
                }
            }
        }
        printf("\n\nEl ordenado descendente se ha realizado con exito.\n");

        break;

    case 3:

        salaryAndAverage(listado,tam);

    case 4:

        break;
    }
}

//

void salaryAndAverage(Employee listado[], int tam)
{
float acumSalarioTotal;
int salarioPromedio;
int cantidadDeEmpleados=0;
int cantidadDeEmpleadosQueSuperanSalario=0;

for(int i=0;i<tam;i++)
{
    if(listado[i].isEmpty==0)
    {
          acumSalarioTotal=acumSalarioTotal+listado[i].salary;
          cantidadDeEmpleados++;
    }
}

salarioPromedio=acumSalarioTotal/cantidadDeEmpleados;

for(int i=0;i<tam;i++)
{
    if(listado[i].salary>salarioPromedio && listado[i].isEmpty==0)// y esta ocupado
    {
        cantidadDeEmpleadosQueSuperanSalario++;
    }
}

printf("El salario total de los empleados es de: %.2f\n, el salario promedio es: %d\n y la cantidad de empleados que superan el salario promedio es de: %d\n",acumSalarioTotal,salarioPromedio,cantidadDeEmpleadosQueSuperanSalario);

}
//

float getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    scanf("%f",&aux);
    return aux;
}
//

int function_getInt(char msj[] )
{
    int resultado;
    printf("%s",msj);
    scanf("%d",&resultado);
    return resultado;
}
//
char function_getChar(char msj[])
{
    char aux;
    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}
//
int function_esNum(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] < '0' || str[i] > '9')&&(str[i]!='.')&&(str[i]!=',')&&(str[i]!=NULL)&&(str[i]!=' '))
           return 0;
       i++;
   }
   return 1;
}
//
int function_esSoloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else{
        while(str[i] != '\0')
        {
            if(  (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
//
void function_getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}
//
int function_getStringLetras(char msj[],char input[])
{
    char aux[256];
    function_getString(msj,aux);
    if(function_esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0 ;
}
//
int function_getStringNumeros(char msj[],char input[])
{
    char aux[256];
    function_getString(msj,aux);
    if(function_esNum(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
//
