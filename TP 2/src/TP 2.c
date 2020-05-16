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
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"
#include "empleado.h"

void ordenarEmpleados(eEmpleado* listaArray, int tam);
int altaEmpleado(eEmpleado* empleado, int tam, char nombre[],char apellido[],float sueldo, int sector);

int main(void) {

	setbuf(stdout, NULL);

	int auxRespuesta;
	int auxDato;
	float auxflotante;
	char auxRta;
	char auxCadena[64];
	int aux;

	char auxNombre[64];
	char auxApellido[64];
	float auxSalario;
	int auxSector;

	char seguir = 's';
	int opcion;
	eEmpleado listaEmpleados[TAME];

	inicializarArray(listaEmpleados,TAME);
	hardcodearArray(listaEmpleados,7);

	do
	{
		system("cls");
		opcion = menu();

		switch(opcion)
		{
			case 1:
				system("cls");
				printf("Ingrese nombre:");
			    fflush(stdin);
				gets(auxNombre);

				printf("Ingrese apellido:");
				fflush(stdin);
				gets(auxApellido);

				printf("Ingrese salario:");
				scanf("%f",&auxSalario);

				printf("Ingrese sector (1-4):");
				scanf("%d",&auxSector);

				while(auxSector < 1 || auxSector > 4)
				{
				    printf("Opcion invalida, reingrese opcion");
				    scanf("%d",&auxSector);
				}

				aux = altaEmpleado(listaEmpleados,TAME,auxNombre,auxApellido,auxSalario,auxSector);

				if(aux == -1)
				{
				  printf("\nNo se ha podido dar de alta al empleado\n\n");
				  system("pause");
				}

			    else if(aux == 0)
			    {
				  printf("\nAlta dada correctamente!\n\n");
				  system("pause");
				}
				break;
			case 2:
				system("cls");
				mostrarMuchosElementos(listaEmpleados,TAME);
				printf("\nIngrese ID de empleado que desea modificar: ");
				scanf("%d",&auxDato);

				auxRespuesta = buscarEmpleadoPorId(listaEmpleados,TAME,auxDato);

				if(auxRespuesta != -1)
				{
					printf("\nSe ha encontrado un empleado!\n\n");
					mostrarUnElemento(listaEmpleados[auxRespuesta]);
					printf("\nQue desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n\n5-Cancelar modificacion");
					scanf("%d",&opcion);

					switch(opcion)
					{
						case 1:
							utn_getNombre(auxCadena,"Ingrese nuevo nombre: ", "Error en el nombre ingresado.",1);

							if(auxRespuesta != -1)
							{
								strcpy(listaEmpleados[auxRespuesta].nombre,auxCadena);
								printf("\nModificacion realizada con exito!\n");
							}
							else
							{
								printf("No se ha podido realizar la modificacion");
							}

							break;
						case 2:
							utn_getNombre(auxCadena,"Ingrese nuevo apellido: ", "Error en el apellido ingresado.",1);

							if(auxRespuesta != -1)
							{
								strcpy(listaEmpleados[auxRespuesta].apellido,auxCadena);
								printf("\nModificacion realizada con exito!\n");
							}
							else
							{
								printf("\nNo se ha podido realizar la modificacion\n");
							}
							break;
						case 3:
							printf("Ingrese nuevo salario: ");
							scanf("%f",&auxflotante);

							while(auxflotante <= 0)
							{
								printf("\nError. Reingrese un valor valido: ");
								scanf("%f",&auxflotante);
							}

							printf("\n\nDesea confirmar el valor %.2f como el nuevo salario? S/N",auxflotante);
							fflush(stdin);
							scanf("%c",&auxRta);

							auxRta = toupper(auxRta);

							while(auxRta != 'S' && auxRta != 'N')
							{
								printf("\nRespues invalida!\n");
								printf("\nDesea confirmar el nuevo salario? S/N");
								fflush(stdin);
								scanf("%c",&auxRta);
							}

							if(auxRta == 'S')
							{
								listaEmpleados[auxRespuesta].salario = auxflotante;
								printf("\n\nModificacion realizada con exito\n\n");
							}
							else
							{
								printf("\nModificacion cancelada\n");
							}

							break;
						case 4:
							printf("Ingrese nuevo sector: ");
							scanf("%d",&auxDato);

							while(auxDato < 1 || auxDato > 4)
							{
								printf("\nError. Reingrese un valor valido: ");
								scanf("%d",&auxDato);
							}

							printf("\n\nDesea confirmar el cambio de sector? (1 al 4) S/N");
							fflush(stdin);
							scanf("%c",&auxRta);

							auxRta = toupper(auxRta);

							while(auxRta != 'S' && auxRta != 'N')
							{
								printf("\nRespues invalida!\n");
								printf("\nDesea confirmar el nuevo salario? S/N");
								fflush(stdin);
								scanf("%c",&auxRta);
							}

							if(auxRta == 'S')
							{
								listaEmpleados[auxRespuesta].sector = auxDato;
								printf("\n\nModificacion realizada con exito\n\n");
							}
							else
							{
								printf("\nModificacion cancelada\n");
							}
							break;
						case 5:
							printf("\nSe ha cancelado la modificacion!\n");
							break;
					}
				}
				else
				{
					printf("\nNo se ha encontrado un empleado con el ID ingresado\n\n");
				}

				system("pause");
				system("cls");

				break;
			case 3:

				system("cls");
				mostrarMuchosElementos(listaEmpleados,TAME);
				printf("\nIngrese ID de empleado que desea dar de baja: ");
				scanf("%d",&auxDato);

				auxRespuesta = buscarEmpleadoPorId(listaEmpleados,TAME,auxDato);

				if(auxRespuesta != -1)
				{
					printf("Se ha encontrado un empleado!\n");
					mostrarUnElemento(listaEmpleados[auxRespuesta]);
					printf("\nDesea confirmar la baja del empleado? S/N");
					fflush(stdin);
					scanf("%c",&auxRta);

					auxRta = toupper(auxRta);

					while(auxRta != 'S' && auxRta != 'N')
					{
						printf("\nRespues invalida!\n");
						printf("\nDesea confirmar la baja del empleado? S/N");
						fflush(stdin);
						scanf("%c",&auxRta);
					}

					if(auxRta == 'S')
					{
						auxRespuesta = bajaEmpleado(listaEmpleados,TAME,auxDato);

						if(auxRespuesta != 1)
						{
							printf("Baja realizada con exito!\n\n");
						}
						else
						{
							printf("No se ha podido realizar la baja del empleado! \n\n");
						}
					}
					else
					{

						printf("\n\nBaja Cancelada!\n\n");
					}

				}
				else
				{
					printf("No se ha encontra un empleado con el ID ingresado\n\n");
				}

				system("pause");

				system("pause");
				system("cls");

				break;
			case 4:
				system("cls");
				ordenarEmpleados(listaEmpleados, TAME);
				mostrarMuchosElementos(listaEmpleados,TAME);
				calcularPromediosYMayores(listaEmpleados, TAME);
				system("pause");
				system("cls");
				break;
			case 5:
				seguir = 'n';
				break;
			default:
				printf("Opcion invalida. Reintente.");
				break;
		}

		system("cls");
		system("pause");

	}while(seguir == 's');


	return EXIT_SUCCESS;
}

void ordenarEmpleados(eEmpleado* listaArray, int tam)
{
	int i,j;
	eEmpleado auxEmpleado;

	if(listaArray != NULL && tam > 0)
	{
		for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				if(strcmp(listaArray[i].nombre,listaArray[j].nombre) > 0 )
				{
					auxEmpleado = listaArray[i];
					listaArray[i] = listaArray[j];
					listaArray[j] = auxEmpleado;
				}
			}
		}
	}
}


int altaEmpleado(eEmpleado* empleado, int tam, char nombre[],char apellido[],float sueldo, int sector)
{
    int retorno = -1;
    int i;
    int auxId = 101;

    for(i=0;i<tam;i++)
    {
        if(empleado[i].isEmpty == 1)
        {
            strcpy(empleado[i].nombre,nombre);
            strcpy(empleado[i].apellido,apellido);
            empleado[i].salario = sueldo;
            empleado[i].sector = sector;
            empleado[i].id = auxId + i;
            empleado[i].isEmpty = 0;
            retorno = 0;
            break;
        }
    }

    return retorno;
}

