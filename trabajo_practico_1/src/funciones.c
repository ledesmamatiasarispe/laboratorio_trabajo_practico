#include <stdlib.h>
#include "funciones.h"

int pedirNumero(int* pRespuesta,int max,int min,int reintentos,char mensaje [],char mensajeError[])
{
	int devolucion=0;
	int numeroIngresado;
	if(pRespuesta!=NULL && max != NULL && min != NULL && reintentos != mensaje && mensajeError != NULL  )
	{


		printf(" \n%s\n ",mensaje);
		scanf("%d",&numeroIngresado);
		printf("\n %d el numero ingresado es \n",numeroIngresado);





	}
	return devolucion;
}

