

int calculadoraMenuNumerico(int* ,int ,int ,int ,char  [],char [],char[]);

int ingresarNumeroInt(char[]);

float ingresarNumeroFloat(char[]);

float sumar(float , float);

float restar(float ,float );

float multiplicar(float ,float );

float dividir(float ,float );

int factorial(int );

void barraDeProgresoTotalmenteInnecesaria(void);


/*
		menu mal hecho, pense que habia que dar a elegir una opcion y
		luego dar su resultado automaticamente pero creo que esta no es la forma correcta --->

				case 1:// suma
					numero_uno = ingresarNumeroFloat("\ningrese A\n");
					system("cls");
					printf("%f +" , numero_uno);
					Numero_dos  = ingresarNumeroFloat("\ningrese B\n");
					system("cls");
					respuesta=sumar( numero_uno , Numero_dos );
					printf("El resultado de %f + %f es = %f \n" , numero_uno , Numero_dos , respuesta);
					system("pause");
					break;
				case 2://resta
					numero_uno = ingresarNumeroFloat("\ningrese A\n");
					system("cls");
					printf("%f -" , numero_uno);
					Numero_dos = ingresarNumeroFloat("\ningrese B\n");
					system("cls");
					respuesta = restar(numero_uno , Numero_dos);
					printf("El resultado de %f - %f  es = %f \n" , numero_uno , Numero_dos , respuesta);
					system("pause");
					break;
				case 3://division
					numero_uno = ingresarNumeroFloat("\ningrese A\n");
					system("cls");
					printf("%f -" , numero_uno);
					Numero_dos = ingresarNumeroFloat("\ningrese B\n");
					if(Numero_dos==0)
						{
							printf("Error!!,no se puede dividir por 0");
						}
						else
							{
							system("cls");
							respuesta = dividir(numero_uno , Numero_dos);
							printf("El resultado de %f / %f es = %f \n", numero_uno , Numero_dos , respuesta);
							}
					system("pause");
					break;
				case 4://multiplicacion
					numero_uno = ingresarNumeroFloat("\ningrese A\n");
					system("cls");
					printf("%f -" , numero_uno);
					Numero_dos = ingresarNumeroFloat("\ningrese B\n");
					system("cls");
					respuesta = multiplicar( numero_uno , Numero_dos);
					printf("El resultado de %f - %f es = %f \n",numero_uno , Numero_dos , respuesta);
					system("pause");
					break;
				case 5://factorial
					factorialValorNumeroA  = ingresarNumeroInt("\ningrese A\n");
					factorialValorNumeroB  = ingresarNumeroInt("\ningrese B\n");
					printf("%d\n%d" , factorialValorNumeroA,factorialValorNumeroB);

					system("cls");
					factorialRespuestaA = factorial( factorialValorNumeroA );
					factorialRespuestaB = factorial( factorialValorNumeroB );
					printf("El factorial de %d! es = %d \n" , factorialValorNumeroA , factorialRespuestaA);
					system("pause");
					break;
*/






