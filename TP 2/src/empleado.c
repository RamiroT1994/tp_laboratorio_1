/*
 * empleado.c
 *
 *  Created on: 15 may. 2020
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

int inicializarArray(eEmpleado* array, int tam)
{
	int retorno = -1;
	int i;

	if(array != NULL)
	{
		for(i=0;i<tam;i++)
		{
			array[i].isEmpty = 1;
		}

		retorno = 0;
	}

	return retorno;

}

void hardcodearArray(eEmpleado* array, int tam)
{
	int i;

	int auxId[7] = {101,102,103,104,105,106,107};
	char auxNombre[7][50] = {"Carlos", "Maria", "Pedro", "Javier", "Patricio", "Juan", "Miguel"};
	char auxApellido[7][50] = {"Tapia","Gomez","Saavedra","Franco","Lopez","Milito","Etcheverria"};
	float auxSalario[7] = {21351.12,23721.10,15780.21,48572.12,78500.87,54123.48,12547.12};
	int auxSector[7] = {1,4,2,3,3,3,4};

	for(i=0;i<tam;i++)
	{
		array[i].id = auxId[i];
		strcpy(array[i].nombre, auxNombre[i]);
		strcpy(array[i].apellido, auxApellido[i]);
		array[i].salario = auxSalario[i];
		array[i].sector = auxSector[i];
		array[i].isEmpty = 0;
	}
}



int mostrarMuchosElementos(eEmpleado* arrayEmpleados, int tam)
{
	int retorno = -1;
	int auxCabeceras = -1;
	int i;

	char auxHeader0 [20] = {"ID EMPLEADO"};
	char auxHeader1 [20] = {"NOMBRE"};
	char auxHeader2 [20] = {"APELLIDO"};
	char auxHeader3 [20] = {"SALARIO"};
	char auxHeader4 [20] = {"SECTOR"};

	if(arrayEmpleados != NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(arrayEmpleados[i].isEmpty == 0)
			{
				auxCabeceras = 0;
				break;
			}
		}

		if(auxCabeceras == 0)
		{
			printf("%-10s %10s %14s %16s %13s\n",auxHeader0,auxHeader1,auxHeader2,auxHeader3,auxHeader4);

		}



		for(i=0;i<tam;i++)
		{
			if(arrayEmpleados[i].isEmpty == 0)
			{

				mostrarUnElemento(arrayEmpleados[i]);
			}
		}
	}
	return retorno;

}


int mostrarUnElemento(eEmpleado unEmpleado)
{
	int retorno = -1;

		printf("%-10d %11s %14s %16.2f %11d\n",unEmpleado.id,unEmpleado.nombre,unEmpleado.apellido,unEmpleado.salario,unEmpleado.sector);

	retorno = 0;

	return retorno;
}


int buscarLugarLibre(eEmpleado* listaEmpleados,int tam)
{
	int retorno = -1;
	int i;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaEmpleados[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int buscarEmpleadoPorId(eEmpleado* listaEmpleados, int tam, int id)
{
	int retorno = -1;
	int i;

	if(listaEmpleados != NULL && tam > 0 && id > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaEmpleados[i].isEmpty == 0 && listaEmpleados[i].id == id )
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int bajaEmpleado(eEmpleado* listaEmpleados, int tam, int id)
{
	int auxRetorno;
	int retorno = -1;

	if(listaEmpleados != NULL && tam > 0 && id > 0)
	{
		auxRetorno = buscarEmpleadoPorId(listaEmpleados,tam,id);

		if(auxRetorno != -1)
		{
			listaEmpleados[auxRetorno].isEmpty = 1;
			retorno = 0;
		}
	}

	return retorno;
}


void calcularPromediosYMayores(eEmpleado* listaEmpleados, int tam)
{
	int i;
	float acumulador = 0;
	float promedio;
	int cantidad = 0;
	int cantidadMayor = 0;

	if(listaEmpleados != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(listaEmpleados[i].isEmpty != 1)
			{
				cantidad++;
				acumulador = acumulador + listaEmpleados[i].salario;
			}
		}

		promedio = acumulador / cantidad;

		for(i=0;i<tam;i++)
		{
			if(listaEmpleados[i].isEmpty != 1 && listaEmpleados[i].salario > promedio)
			{
				cantidadMayor++;
			}
		}
	}

	printf("\n\nEl total de los salarios es %.2f\n", acumulador);
	printf("El promedio de los salarios es %.2f\n",promedio);
	printf("La cantidad de personas que cobran mas que el promedio es %d\n",cantidadMayor);

}
