

int calculadoraMenuNumerico(int* ,int ,int ,int ,char  [],char [],char[]);

int ingresarNumeroInt(char[]);

float ingresarNumeroFloat(char[]);

float sumar(float , float);

float restar(float ,float );

float multiplicar(float ,float );

float dividir(float ,float );

int factorial(int );

void barraDeProgresoTotalmenteInnecesaria(void);

void barraDeProgresoTotalmenteInnecesaria2(void);

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


void ERROR1(void)
{
	system("color 17");
printf(
	"\n Error el numero ingresado es mas de lo que la calculadora puede manejar"
	"\n"
"\n                      II$$$$$$$:?ZZ$$$$OO8"
"\n                   ~I$II7$$$$$$ZZZZ$$$$7ZO , "
"\n                  7?I7Z$O888 R  OZ R $$$$77$D  "
"\n                 O=7IZ8888 E 8OO I $$$$7777$+  "
"\n                 ?INZO8D B D88 A ZZZ$$$$$7$7M  "
"\n                 7INZO U NNN H 8OOZZZ$$$$$$7O?"
"\n                 MZN7ODDNN C NND8OOOZZZZ8MD?NN "
"\n                 :DODODNNNNNMMND888NMI      :Z "
"\n                  I7MNMMMMMMD7,              ?8 "
"\n                   8                          Z: "
"\n                   OZ                         DD "
"\n                    Z                         ,M"
"\n                    MO                         IO"
"\n                    ~D                          $  "
"\n                     N?                         D= "
"\n                      8                          $"
"\n                      MD                         MD"
"\n                      ~N           ,+$O88OZZOO8O=7O"
"\n                       D7    ,$8OOOOOOOZOO8OOOOZOZZO"
"\n                        Z,$O88OOOOOOOOOOOOZZZZZZZZZZZ$$O"
"\n                        MO8OOOOOOZZZZZZZZZZ$$$$ZZZZ$$$Z$$$Z"
"\n                        +ZZ$$$$$Z$$$$$$$$$$$$$$$$$$$$$$$ZZOI"
"\n                         MMM77$$$$$$$$$$$$$$$$$$$$$$ZZZZONM"
"\n                         OD   =7ZOZO$$$$$$$$$Z$$ZZONMD8M  "
"\n                          M:        7MMMMMMNMMN7     OM "
"\n                          7M        +DM+,           DMO"
"\n                           M      ,8M:            ~M,,M$"
"\n                           MZ    NM              NM   DI"
"\n                           ,D  7M              ~M ,    M"
"\n                            M8M7              NM       ?Z"
"\n                           :OM              NM          M "
"\n                          +M MZ            MZ           ZD"
"\n                         NM  :O,          $M             8+"
"\n                       ~M     M8         ?M         ,7MNMMO"
"\n                      DM      $D       ~MMM     OMMM~    ,M"
"\n                     +M        M7 ,DMM8~,+INMMNI,         OD"
"\n                    :M+      =MN$$~=I7N8D8                 8"
"\n                    MM:7MMM+,:I?M+=8                       D8"
"\n                   MM           ZZ                          8"
"\n                                 N7                         M"
"\n                                 MO                         8M "
"\n                                 :M    "
"\n                                  DD  "
"\n                                   D  "
"\n                                   M8"
"\n                                   Z8"



	);





}


