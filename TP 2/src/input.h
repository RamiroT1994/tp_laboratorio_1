/*
 * input.h
 *
 *  Created on: 14 may. 2020
 *      Author: admin
 */

#ifndef INPUT_H_
#define INPUT_H_



#endif /* INPUT_H_ */

int esNumerica(char* cadena);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int utn_getNumero(int* pResultado,char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getNombre(char* pCadena,char* mensaje,char* mensajeError, int reintentos);
int validarCadena(char* pCadena);
void correcionCadena(char* pCadena);

int menu();
