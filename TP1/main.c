#include <stdio.h>
#include <stdlib.h>
#include "funcionesmatematicas.h" // mi libreria con las funciones agregados.

int main()
{

int opcion=0;
float numero1=0;
float numero2=0;
int bandera;
float resultadosuma=0;
float resultadoresta=0;
float resultadodeladivision=0;
float resultadodelamultiplicacion=0;
float resultadofactorialop1=0;
float resultadofactorialop2=0;

do
{

printf("\nBienvenido a la calculadora \n");
printf("\nMENU DE OPCIONES\n");
printf("\n1 : Ingresar primer operando A=%.2f",numero1);
printf("\n2 : Ingresar segundo operando B=%.2f",numero2);
printf("\n3 : CALCULAR TODAS LAS OPERACIONES");
printf("\n4 : INFORMAR RESULTADOS");
printf("\n5 : SALIR");
printf("\n \nIngrese la opercion deseada: ");

scanf("%d",&opcion);

switch(opcion) // opcion elegida del menu.
{
case 1:
    printf("\nIngrese el primer operando: ");
    scanf("%f",&numero1);
    break;

case 2:
    printf("\nIngrese el segundo operando: ");
    scanf("%f",&numero2);

    if(numero2==0) //advierto sobre la division por cero al usuario.
    {
    printf("Recuerde: no se puede dividir por cero..");
    system("pause");
    }
    break;

case 3: // hago las cuentas, llamando a las funciones

    printf("\nCALCULANDO LAS OPERACIONES..\n\n");
    resultadosuma = funcionsuma(numero1,numero2);
    resultadoresta = funcionresta(numero1,numero2);
    resultadodeladivision = funciondivision(numero1,numero2);
    resultadodelamultiplicacion = funcionmultiplicacion(numero1,numero2);
    resultadofactorialop1=factorialnumero1(numero1);
    resultadofactorialop2=factorialnumero2(numero2);
    system("pause");
    break;

case 4: // muestro los resultados, ojo division por cero.

    printf("\nINFORMANDO RESULTADOS...\n");
    printf("\nEL RESULTADO DE A + B ES: %.2f",resultadosuma);
    printf("\nEL RESULTADO DE A - B ES: %.2f",resultadoresta);
    if(numero2==0)
    {
        printf("\nEL RESULTADO DE A / B ES: NO SE PUEDE DIVIDIR POR CERO");
    }
    else
    {
        printf("\nEL RESULTADO DE A / B ES: %.2f",resultadodeladivision);
    }

    printf("\nEL RESULTADO DE A * B ES: %.2f\n",resultadodelamultiplicacion);
    printf("\nEL RESULTADO DEL FACTORIAL DEL OPERANDO 1 ES: %.2f\n",resultadofactorialop1);
    printf("\nEL RESULTADO DEL FACTORIAL DEL OPERANDO 2 ES: %.2f\n",resultadofactorialop2);

    system("pause");

    break;

case 5:
    bandera=0;
    break;

default:
    printf("Ingrese una opcion valida!\n");
    system("pause");
}

system("cls");

}while(bandera!=0);

    return 0;
}

