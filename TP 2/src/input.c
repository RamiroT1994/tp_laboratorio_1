/*
 * input.c
 *
 *  Created on: 14 may. 2020
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int myGets(char* cadena, int longitud)
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin) == cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}

int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}

	}

	return retorno;
}

int esNumerica(char* cadena)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}

	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	while(reintentos > 0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(getInt(&bufferInt) == 0)
		{
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}

		printf("%s",mensajeError);
	}
	return retorno;
}



int utn_getNombre(char* pCadena,char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char buffer[64];

	if(pCadena != NULL && reintentos > 0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("%s",mensaje);
			fflush(stdin);
			gets(buffer);

			if(validarCadena(buffer) == 0)
			{
				correcionCadena(buffer);

				strcpy(pCadena,buffer);
				retorno = 0;
				break;
			}

			printf("%s",mensajeError);

		}
	}

	return retorno;
}

int validarCadena(char* pCadena)
{
	int retorno = -1;
	int lenCadena;
	int i;
	int auxFlag = 0;

	char buffer[64];

	if(pCadena != NULL)
	{
		strcpy(buffer,pCadena);
		strlwr(buffer);

		lenCadena = strlen(buffer);

		for(i=0;i<lenCadena;i++)
		{
			if( buffer[i] < 97 || buffer[i] > 122  )
			{
				if(buffer[i] != ' ')
				{
					auxFlag = -1;
					break;
				}
			}
		}

		if(auxFlag == 0)
		{
			strcpy(pCadena, buffer);
			retorno = 0;
		}


	}

	return retorno;

}

void correcionCadena(char* pCadena)
{
	int len;
	int i;

	if(pCadena != NULL)
	{
		len = strlen(pCadena);

		for(i=0;i<len;i++)
		{
			if(i == 0)
			{
				*pCadena = toupper(pCadena[i]);
				continue;
			}

			//VALIDACION PARA QUE SI EL NOMBRE TIENE "del", "de", la siguiente palabra este en mayuscula
			//EJEMPLO: Soledad del Valle
			/*if(pCadena[i] == ' ')
			{
				*pCadena = toupper(pCadena[i+1]);
			}*/
		}
	}
}

int menu()
{
	int retorno;

	printf("1-Alta empleado\n");
	printf("2-Modificar empleado\n");
	printf("3-Baja empleado\n");
	printf("4-Informes\n");
;
	printf("\n5-Salir\n");

	printf("\nSeleccione una opcion: \n");
	scanf("%d",&retorno);

	return retorno;
}
