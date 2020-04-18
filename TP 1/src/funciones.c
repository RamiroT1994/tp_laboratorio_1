/*
 * funciones.c
 *
 *  Created on: 18 abr. 2020
 *      Author: admin
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu(int flag1, int flag2,float num1,float num2)
{
	int opcion = -1;
    system("cls");

    printf("Elija una opcion\n\n");

    if(flag1 == 0)
    {
        printf("1-Ingresar 1er operando(A=x)\n");
    }
    else
    {
        printf("1-Ingresar 1er operando(A=%.2f)\n",num1);
    }

    if(flag2 == 0)
    {
        printf("2-Ingresar 2do operando(B=y)\n");
    }
    else
    {
        printf("2-Ingresar 2do operando(B=%.2f)\n",num2);
    }

    printf("3-Calcular todas las operaciones\n");
    printf("4-Informar resultados\n\n");
    printf("5-Salir\n\n");

    scanf("%d",&opcion);

	return opcion;
}

float sumar(float numeroUno,float numeroDos)
{
	float resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}

float restar(float numeroUno,float numeroDos)
{
	float resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}

float multiplicacion(float numeroUno,float numeroDos)
{
	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}

float division(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno / numeroDos;

	return resultado;
}

long long int funcionFactorial(int numero)
{
    long long int resultado;

    if(numero == 0)
    {
        return 1;
    }
    else
    {
    resultado = numero * funcionFactorial(numero-1);

    return resultado;

    }
}


int verificarEntero(float a)
{
    int auxiliarFact;
    int entero = 0;

    auxiliarFact = (int)a;

    if(a - auxiliarFact == 0)
    {
        entero = 1;
    }

    return entero;
}
