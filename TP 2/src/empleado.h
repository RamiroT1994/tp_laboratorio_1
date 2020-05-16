/*
 * empleado.h
 *
 *  Created on: 15 may. 2020
 *      Author: admin
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_



#endif /* EMPLEADO_H_ */

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;

	int isEmpty;

}eEmpleado;

#define TAME 10

int inicializarArray(eEmpleado* array,int tam);
void hardcodearArray(eEmpleado* array, int tam);
int mostrarUnElemento(eEmpleado unElemento);
int mostrarMuchosElementos(eEmpleado* arrayEmpleados, int tam);
int bajaEmpleado(eEmpleado* listaEmpleados, int tam, int id);
int buscarLugarLibre(eEmpleado* listaEmpleados,int tam);
int buscarEmpleadoPorId(eEmpleado* listaEmpleados, int tam, int id);
void calcularPromediosYMayores(eEmpleado* listaEmpleados, int tam);
