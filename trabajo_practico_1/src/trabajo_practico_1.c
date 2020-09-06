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

	int opcion;
	int validacion;
	float A;
	float B;
	float Respuesta = 0 ;
	A=ingresarNumero("\ningrese el primer numero\n");
	do{
		printf("%f\n",A);
	validacion = menuNumerico(&opcion,7,0,3," esta en el menu|elija una opcion.","error, opcion incorrecta",
	"| 0 menu |\n| 1 sumar |\n| 2 restar |\n|3 funcion 3|\n|4 funcion 4|\n|5 para 5|\n|6 clear|\n|7 salir|");
	if(validacion)
		{

			switch(opcion)
			{
				case 1:
					printf("suma\n");
					break;
				case 2:
					printf("resta\n");
					break;
				case 3:
					printf("la opcion selecionada es = %d\n",opcion);
					break;
				case 4:
					printf("la opcion selecionada es = %d\n",opcion);
					break;
				case 5:
					printf("la opcion selecionada es = %d\n",opcion);
					break;
				case 6:
					A=ingresarNumero("\ningrese el primer numero\n");
					break;
				case 7:
					printf("hasta la proximaaaaaaaaaaaaaaa\n");
					break;
				default:
					continue;

			}

		}
	}while(opcion!=6);
	return 0;
}
