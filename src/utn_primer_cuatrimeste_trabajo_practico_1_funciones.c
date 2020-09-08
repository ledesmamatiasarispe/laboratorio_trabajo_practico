
#include <stdio.h>
#include <stdlib.h>
#include "utn_primer_cuatrimeste_trabajo_practico_1_funciones.h"
int calculadoraMenuNumerico(int* pValorIngresado,int max,int min,int reintentos,char mensaje [],char mensajeError[],char opciones[])
{
	int funcionRegresa=-1;
	int numeroIngresado;
	if(pValorIngresado!=NULL && max >= min && reintentos !=0 && mensaje != NULL
		&& mensajeError != NULL  )
	{
		for(int i = reintentos;i>=0;i--)
		{
			funcionRegresa=0;
			printf("%s\n", opciones);
			numeroIngresado = ingresarNumeroInt(mensaje);

			system("cls");

			if(numeroIngresado>=min && numeroIngresado<=max)
			{
				funcionRegresa = 1;
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
	return funcionRegresa;
}

int ingresarNumeroInt(char mensaje[])
{
	int numeroIngresado;
	printf("%s\n",mensaje);
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
	unsigned long int respuesta;

	for(respuesta = 1 ; X > 0 ;X--)
	{
	respuesta *= X;
	}
	return respuesta;
}

void barraDeProgresoTotalmenteInnecesaria(void)

{
						printf("\n calculando!_                            _");
						system("cls");
						printf("\n calculando!___                          _");
						system("cls");
						printf("\n calculando!_____                        _");
						system("cls");
						printf("\n calculando!_______                      _");
						system("cls");
						printf("\n calculando!_________                    _");
						system("cls");
						printf("\n calculando!___________                  _");
						system("cls");
						printf("\n calculando!________________             _");
						system("cls");
						printf("\n calculando!____________________         _");
						system("cls");
						printf("\n calculando!_______________________      _");
						system("cls");
						printf("\n calculando!_________________________    _");
						system("cls");
						printf("\n completado!______________________________");
						system("pause");
}

void barraDeProgresoTotalmenteInnecesaria2(void)

{
						printf("\n cargando!~                            ~");
						system("cls");
						printf("\n cargando!~~~                          ~");
						system("cls");
						printf("\n cargando!~~~~~                        ~");
						system("cls");
						printf("\n cargando!~~~~~~~                      ~");
						system("cls");
						printf("\n cargando!~~~~~~~~~                    ~");
						system("cls");
						printf("\n cargando!~~~~~~~~~~~                  ~");
						system("cls");
						printf("\n cargando!~~~~~~~~~~~~~~~~             ~");
						system("cls");
						printf("\n cargando!~~~~~~~~~~~~~~~~~~~~         ~");
						system("cls");
						printf("\n cargando!~~~~~~~~~~~~~~~~~~~~~~~      ~");
						system("cls");
						printf("\n cargando!~~~~~~~~~~~~~~~~~~~~~~~~~    ~");
						system("cls");
						printf("\n completado!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						system("pause");
}
