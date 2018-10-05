#ifndef FUNCIONESMATEMATICAS_C_INCLUDED
#define FUNCIONESMATEMATICAS_C_INCLUDED
#include <stdio.h>
#include "funcionesmatematicas.h"

/** \brief calcula el factorial del operando 1, ingresado por el usuario.
 *
 * \param op1=numero1, el numero ingresado al cual se le calculara su factorial.
 * \return devuelve el resultado del factorial del operando 1.
 *
 */

float factorialnumero1(float op1)
{
    int local;
    int factorial=1;
    for(local=op1;local>1;local--)
    {
        factorial=factorial*local;
    }
    return factorial;

}

/** \brief calcula el factorial del operando 2, ingresado por el usuario.
 *
 * \param op2=numero2, el numero ingresado al cual se le calculara su factorial.
 * \return devuelve el resultado del factorial del operando 2.
 *
 */

float factorialnumero2(float op2)
{
    int local;
    int factorial=1;
    for(local=op2;local>1;local--)
    {
        factorial=factorial*local;
    }
    return factorial;

}

/** \brief esta funcion se encarga de realizar la multiplicacion de los operando 1 y operando 2.
 *
 * \param op1=numero1, operando 1 ingresado por el usuario en la opcion 1.
 * \param op2=numero2, operando 2 ingresado por el usuario en la opcion 2.
 * \return devuelve el resultado de la multiplicacion del operando 1 por el operando 2.
 *
 */

float funcionmultiplicacion(float op1, float op2)
{
    float resultadomultiplicacion;
    resultadomultiplicacion=op1*op2;
    return resultadomultiplicacion;
}

/** \brief esta funcion se encarga de realizar la division de los numeros 1 y numero 2.
 *
 * \param op1=numero1, ingresa el dividendo.
 * \param op2=numero2, ingresa el divisor.
 * \return devuelve el resultado de la division del dividendo y el divisor.
 *
 */

float funciondivision(float op1, float op2)
{
    float resultadodivision;
    resultadodivision=op1/op2;
    return resultadodivision;
}

/** \brief esta funcion se encarga de restar el operando 1 menos el operando 2.
 *
 * \param op1=numero1, operando 1 ingresado por el usuario.
 * \param op2=numero2, operando 2 ingresado por el usuario.
 * \return devuelve el resultado de la resta del operando 1 menos el operando 2.
 *
 */

float funcionresta(float op1, float op2)
{
    float resultadoresta;
    resultadoresta=op1-op2;
    return resultadoresta;
}

/** \brief esta funcion realiza la suma del operando 1 mas el operando 2.
 *
 * \param op1=numero1, operando 1 ingresado por el usuario.
 * \param op2=numero2, operando 2 ingresado por el usuario.
 * \return devuelve el resultado de la suma del operando 1 mas el operando 2.
 *
 */

float funcionsuma(float op1, float op2)
{
    float resultadodelasuma;
    resultadodelasuma=op1+op2;
    return resultadodelasuma;
}

#endif // FUNCIONESMATEMATICAS_C_INCLUDED
