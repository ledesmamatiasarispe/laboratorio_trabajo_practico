/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : Matias Arispe Ledesma
 Version     :
 Copyright   : Your copyright notice
 Description : Calculadora de consola.
 ============================================================================
 */
#include "utn_primer_cuatrimeste_trabajo_practico_1_funciones.c"


int main(void) {
	int menuOpcionSeleccionada;
	int menuValido;
	float numero_A = 0;
	float numero_B = 0;

	float respuestaSuma;
	float respuestaResta;
	float respuestaDivision;
	float respuestaMultiplicacion;
	float  factorialValorNumeroA;
	float  factorialValorNumeroB;

	system("color 02");
	barraDeProgresoTotalmenteInnecesaria2();
	system("cls");
	do{
	printf("\n  A = %f   |   B = %f  ",numero_A,numero_B);
	menuValido = calculadoraMenuNumerico(&menuOpcionSeleccionada,5,1,3,"elija una opcion.","error, opcion incorrecta",
	"\n ______________________________"
    "\n|1 -> ingresar A               |"
    "\n|2 -> ingresar B               |"
    "\n|3 -> calcular las operaciones |"
    "\n|4 -> informar los resultados  |"
    "\n|5 -> salir                    |"
    "\n|______________________________|");
	if(menuValido)
		{
			switch(menuOpcionSeleccionada)
			{
				case 1:
						numero_A=ingresarNumeroFloat("ingrese A = ");
					break;
				case 2:
						numero_B=ingresarNumeroFloat("ingrese B = ");
					break;
				case 3:
						respuestaSuma = sumar(numero_A,numero_B);
						respuestaResta = restar(numero_A,numero_B);
						respuestaDivision = dividir(numero_A,numero_B);
						respuestaMultiplicacion = multiplicar(numero_A,numero_B);
					    factorialValorNumeroA = factorial(numero_A);
						factorialValorNumeroB = factorial(numero_B);//sera legal hacer esto?
						barraDeProgresoTotalmenteInnecesaria();
					break;
				case 4:
					printf("\n  A = %f   |   B = %f  ",numero_A,numero_B);
					printf("\n ______________________________");
					printf("\n| A+b = %f",respuestaSuma);
					printf("\n| A-B = %f",respuestaResta);
					if(numero_B==0)
					{
						printf("\n| A/B = NO se puede dividir por cero");
					}else{
							printf("\n| A/B = %f",respuestaDivision);
					}
					printf("\n| A*B = %f",respuestaMultiplicacion);


					printf("\n| A! =  %f",factorialValorNumeroA);
					printf("\n| B! =  %f",factorialValorNumeroB);


					printf("\n|______________________________\n");
					system("pause");
					break;
				case 5:
					("hasta la proximaaaaaaaaaaaaaaa\n");
			}
		system("cls");
		}else
		{
			system("cls");
			ERROR1();
				system("pause");
				system("cls");
			system("color 02");
		}
	}while(menuOpcionSeleccionada!=5);
	return 1;
}
