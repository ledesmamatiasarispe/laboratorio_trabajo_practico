/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



#include "funciones.c"

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	char  opcionesDelMenu[] = "ingrese 1 para funcion 1\ningrese 2 para funcion 2\ningrese 3 para funcion 3\ningrese 4 para funcion 4\ningrese 5 para funcion 5\n";






	printf("%s", opcionesDelMenu);
	int opcion;
	int validacion;
	validacion = pedirNumero(&opcion,6,1,4,"ingrese un numero","error, reintente nuevamente");
	if(validacion)
	{
		printf("valido");
	}
	return 0;
}
