
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menuNumerico(int* pValorIngresado,int max,int min,int reintentos,char mensaje [],char mensajeError[],char opciones[])
{
	int devolucion=-1;
	int numeroIngresado;
	if(pValorIngresado!=NULL && max >= min && reintentos !=0 && mensaje != NULL
		&& mensajeError != NULL  )
	{
		for(int i = reintentos;i>=0;i--)
		{
			devolucion=0;
			printf("%s\n", opciones);
			numeroIngresado = ingresarNumeroInt(mensaje);

			system("cls");

			if(numeroIngresado>=min && numeroIngresado<=max)
			{
				devolucion = 1;
				*pValorIngresado = numeroIngresado;
				break;
			}else
			{
				if(i == 1)
				{
					printf("se ha quedado sin reintentos\n");
					break;
				}else{
					printf("%s valor maximo %d y valor minimo %d\n",mensajeError,max,min);
				}
			}
		}
	}
	return devolucion;
}

int ingresarNumeroInt(char mensaje[])
{
	int numeroIngresado;
	printf("%s",mensaje);
	scanf("%d",&numeroIngresado);
	return numeroIngresado;
}

float ingresarNumeroFloat(char mensaje[])
{
	float numeroIngresado;
	printf("%s",mensaje);
	scanf("%f",&numeroIngresado);
	return numeroIngresado;
}

float sumar(float X,float Y)
{
	float resultado;
	resultado = X + Y;
	return resultado;
}
float restar(float X,float Y)
{
	float resultado;
	resultado = X - Y;
	return resultado;
}
float multiplicar(float X,float Y)
{
	float resultado;
	resultado = X * Y;
	return resultado;
}


float dividir(float X,float Y)
{
	float resultado;
	resultado = X / Y;
	return resultado;
}

int factorial(int X)
{
	//x*(x-1) => X==0
	int long unsigned respuesta=1;
	for(;X >=0 ;X--)
	{
	respuesta *= X;
	}
	return respuesta;
}





