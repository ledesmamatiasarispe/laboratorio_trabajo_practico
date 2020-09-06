/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : Matias Arispe Ledesma
 Version     :
 Copyright   : Your copyright notice
 Description : Calculadora de consola.
 ============================================================================
 */
#include "funciones.c"


int main(void) {
	int opcion;
	int validacion;
	float A;
	float B = 0;
	float respuesta = 0 ;
	do{

	validacion = menuNumerico(&opcion,7,1,3,"elija una opcion.","error, opcion incorrecta",
    "________________________\n|  1 -> suma           |\n| "
    " 2 -> resta          |\n|  3 -> division       |\n| "
    " 4 -> multiplicacion |\n|  5 -> factorial      |\n| "
    " 6 -> salir          |\n________________________");
	if(validacion)
		{

			switch(opcion)
			{
					break;
				case 1:// suma
					A=ingresarNumeroFloat("\ningrese A\n");
					system("cls");
					printf("%f +",A);
					B=ingresarNumeroFloat("\ningrese B\n");
					system("cls");
					respuesta=sumar(A,B);
					printf("%f + %f = %f \n",A,B,respuesta);
					system("pause");
					break;
				case 2://resta
					A=ingresarNumeroFloat("\ningrese A\n");
					system("cls");
					printf("%f -",A);
					B=ingresarNumeroFloat("\ningrese B\n");
					system("cls");
					respuesta=restar(A,B);
					printf("%f - %f = %f \n",A,B,respuesta);
					system("pause");
					break;
				case 3://division
					A=ingresarNumeroFloat("\ningrese A\n");
					system("cls");
					printf("%f -",A);
					B=ingresarNumeroFloat("\ningrese B\n");
					if(B==0)
						{
							printf("Error!!,no se puede dividir por 0");
						}else
							{
							system("cls");
							respuesta=dividir(A,B);
							printf("%f / %f = %f \n",A,B,respuesta);
							}
					system("pause");
					break;
				case 4://multiplicacion
					A=ingresarNumeroFloat("\ningrese A\n");
					system("cls");
					printf("%f -",A);
					B=ingresarNumeroFloat("\ningrese B\n");
					system("cls");
					respuesta=multiplicar(A,B);
					printf("%f - %f = %f \n",A,B,respuesta);
					system("pause");
					break;
				case 5:
					A=ingresarNumeroInt("\ningrese A\n");
					system("cls");
					printf("%d -",A);
					respuesta=factorial(A);
					printf("%d = %d \n",A,respuesta);
					system("pause");
					break;
				default:
					printf("hasta la proximaaaaaaaaaaaaaaa\n");
					break;

			}

		}
	}while(opcion<6);
	return 0;
}
