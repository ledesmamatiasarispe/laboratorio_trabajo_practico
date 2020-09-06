
#include <stdio.h>
#include "funciones.h"

int pedirNumero(int* pRespuesta,int max,int min,int reintentos,char mensaje [],char mensajeError[])
{
	int devolucion=-1;
	int numeroIngresado;
	if(pRespuesta!=NULL&& max != NULL && min != NULL && reintentos !=NULL && mensaje != NULL
		&& mensajeError != NULL  )
	{
		for(int i = reintentos;i>0;i--)
		{

			printf(" \n%s\n ",mensaje);
			scanf("%d",&numeroIngresado);
			printf("\n el numero ingresado es %d \n",numeroIngresado);

			if(numeroIngresado>=min && numeroIngresado<=max)
			{

			}


		}
	}
	return devolucion;
}

