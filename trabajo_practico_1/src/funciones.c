
#include <stdio.h>
#include "funciones.h"

int menuNumerico(int* pValorIngresado,int max,int min,int reintentos,char mensaje [],char mensajeError[],char opciones[])
{
	int devolucion=-1;
	int numeroIngresado;
	if(pValorIngresado!=NULL && max >= min && reintentos !=NULL && mensaje != NULL
		&& mensajeError != NULL  )
	{
		printf("%s", opciones);

		for(int i = reintentos;i>=0;i--)
		{
			devolucion=0;
			numeroIngresado = ingresarNumero(mensaje);
			if(numeroIngresado>=min && numeroIngresado<=max)
			{
				devolucion = 1;
				*pValorIngresado = numeroIngresado;
				break;
			}else
			{
				if(i == 1)
				{
					printf("se ha quedado sin reintentos");
					break;
				}else{
					printf("%s valor maximo %d y valor minimo %d",mensajeError,max,min);
				}
			}
		}
	}
	return devolucion;
}

int ingresarNumero(char mensaje[])
{
	int numeroIngresado;
	printf("%s",mensaje);
	scanf("%d",&numeroIngresado);
	return numeroIngresado;
}










