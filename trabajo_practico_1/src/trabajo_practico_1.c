/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#include "funciones.h"

int main(void) {
	int opcion;
	int validacion;
	validacion = pedirNumero(&opcion,5,1,4,"ingrese un numero","error, reintente nuevamente");
	if(!validacion)
	{
		puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	}
	return 0;
}
