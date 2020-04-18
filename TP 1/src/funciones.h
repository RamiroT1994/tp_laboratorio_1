/*
 * funciones.h
 *
 *  Created on: 18 abr. 2020
 *      Author: admin
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


/**
 * \brief Muestra un menu por pantalla
 * \param Variable auxiliar para utilizacion posterior
 * \param Variable auxiliar para utilizacion posterior
 * \param Numero ingresado que reemplazara valor dentro del menu
 * \param Numero ingresado que reemplazara valor dentro del menu
 * \return Retorna la opcion de menu seleccionada
 *
 */

int menu(int flag1,int flag2,float num1,float num2);


/**
 * \brief Funcion que realiza una suma
 * \param Primer operando de la operacion
 * \param Segundo operando de la operacion
 * \return Resultado de la suma
 *
 */
float sumar(float,float);

/**
 * \brief Funcion que realiza una resta
 * \param Primer operando de la operacion
 * \param Segundo operando de la operacion
 * \return Resutlado de la resta
 *
 */
float restar(float, float);


/**
 * \brief Funcion que realiza una multiplicaicon
 * \param Primer operando de la operacion
 * \param Segundo operando de la operacion
 * \return Resultado de la multiplicacion
 *
 */
float multiplicacion(float, float);

/**
 * \brief Funcion que realiza una division
 * \param Primer valor a dividir
 * \param Segundo valor a dividir
 * \return
 *
 */
float division(float, float);


/**
 * \brief Funcion que calcular el factorial de un numero
 * \param Numero del que se calculara el factorial
 * \return Retorna el factorial o un valor establecido como error en caso de no poder calcularlo
 *
 */
long long int funcionFactorial(int);


/**
 * \brief Verifica que el numero ingresado sea un entero
 * \param Numero a calcular si es un entero o no
 * \return Retorna 0 si es entero, 1 si no es entero
 *
 */
int verificarEntero(float);


#endif /* FUNCIONES_H_ */
