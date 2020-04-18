/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(void) {

	setbuf(stdout, NULL);

/******************* VARIABLES AUXILIARES *****************/

	int opcion;
	char seguir = 's';
	int flag1 = 0;
	int flag2 = 0;
	int auxCalculos = 0;
	int auxEnteros;

	float resultadoSuma;
	float resultadoResta;
	float producto;
	float cociente;
	long long int factorial;
	long long int factorial2;

/*********************************************************/

	float numero_uno;
	float numero_dos;

	while(seguir == 's')
	{
		opcion = menu(flag1,flag2,numero_uno,numero_dos);

		switch(opcion)
		{
		case 1:
			printf("Ingrese valor para primer numero:");
			scanf("%f",&numero_uno);
			flag1 = 1;
			break;
		case 2:
			printf("Ingrese valor para segundo numero:");
			scanf("%f",&numero_dos);
			flag2 = 1;
			break;
		case 3:

			if(flag1 == 1 && flag2 == 1)
			{
				resultadoSuma = sumar(numero_uno,numero_dos);
				resultadoResta = restar(numero_uno,numero_dos);
				producto = multiplicacion(numero_uno,numero_dos);
				cociente = division(numero_uno,numero_dos);


				auxEnteros = verificarEntero(numero_uno);

				if(auxEnteros == 1)
				{
					if(numero_uno >= 0 && numero_uno <= 20)
					{
						factorial = funcionFactorial(numero_uno);
					}
					else
					{
						factorial = -1;
					}
				}
				else
				{
					factorial = -2;
				}

				auxEnteros = verificarEntero(numero_dos);

				if(auxEnteros == 1)
				{
					if(numero_dos >= 0 && numero_dos <= 20)
					{
						factorial2 = funcionFactorial(numero_dos);
					}
					else
					{
						factorial2 = -1;
					}
				}
				else
				{
					factorial2 = -2;
				}




				auxCalculos = 1;
			}
			else
			{
				printf("\nNo se han podido realizar los calculos porque falta por lo menos un valor.\n\n");
			}
			system("pause");
			break;
		case 4:
			system("cls");
			if(auxCalculos == 1)
			{
				printf("El resultado de la suma es %.2f\n",resultadoSuma);
				printf("El resultado de la resta es %.2f\n",resultadoResta);
				printf("El resultado de la multiplicacion es %.2f\n",producto);
				printf("El resultado de la division es %.2f\n",cociente);

				if(factorial != -1 && factorial != -2)
				{
					printf("El factorial del primero numero es %lld\n",factorial);
				}
				else
				{
					if(factorial == -1)
					{
						printf("No se puede mostrar el factorial del primer valor\nSolo se puede mostrar el factorial de un numero entre 0 y 20\n");
					}

					if(factorial == -2)
					{
						printf("No se puede mostrar el factorial del primer valor porque no es un numero entero\n");
					}

				}

				if(factorial2 != -1 && factorial2 != -2)
				{
					printf("El factorial del segundo numero es %lld\n",factorial2);
				}
				else
				{
					if(factorial2 == -1)
					{
						printf("No se puede mostrar el factorial del segundo valor\nSolo se puede mostrar el factorial de un numero entre 0 y 20\n");
					}
					if(factorial2 == -2)
					{
						printf("No se puede mostrar el factorial del segundo valor porque no es un numero entero\n");
					}

				}

			}
			else
			{
				printf("\nNo se han podido mostrar los resultados.\n\n");

			}
			system("pause");
			system("cls");

			break;
		case 5:
			seguir = 'n';
			system("cls");
			printf("Adios!\n\n");
			system("pause");
			system("cls");
			break;
		default:
			break;

		}
	}

	return EXIT_SUCCESS;
}


