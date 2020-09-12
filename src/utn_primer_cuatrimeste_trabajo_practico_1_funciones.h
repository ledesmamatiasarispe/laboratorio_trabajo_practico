
/**
*@brief muestra un menu con opciones, luego toma un numero que verifica que este dentro de un rango
		y devuelve (0) si no valido o (1) si valido,
		ese numero lo guarda en un na variable especificada por un puntero.
*@param int*	es el puntero de donde se guarda el numero selecionado
*@param	int es el valor maximo admitido en el menu
*@param	int es el valor minimo admitido en el menu
*@param	int la cantidad de reintentos que permite ingresar el numero
*@param	char  [] es el mensaje con el que pide el ingreso de el numero
*@param	char  [] es el mensaje que muestra cuando el numero no valida
*@param	char  [] son las opciones que ve el usuario antes de ingresar el numero
*@return devuelve (0) si no valido o (1) si valido y guarda el numero validado a travez de un *puntero
*
*/
int calculadoraMenuNumerico(int* ,int ,int ,int ,char  [],char [],char[]);

/**
*brief pide un numero y lo retorna
*param char[] es el mensaje que muestra al pedir el numero
*return un int que se pide por scanf
*/
int ingresarNumeroInt(char[]);

/**
*brief pide un numero y lo retorna
*param char[] es el mensaje que muestra al pedir el numero
*return un float que se pide por scanf
*/
float ingresarNumeroFloat(char[]);

/**
*brief suma dos float y devuelve el resultado
*param float un numero
*return el resultado de la suma
*/
float sumar(float , float);

/**
*brief resta dos float y devuelve el resultado
*param float un numero
*return el resultado de la resta
*/
float restar(float ,float );

/**
*brief multiplica dos float y devuelve el resultado
*param float un numero
*return el resultado de la multiplicacion
*/
float multiplicar(float ,float );

/**
*brief divide dos float y devuelve el resultado
*param float un numero
*return el resultado de la divicion
*/
float dividir(float ,float );

/**
*brief toma un numero y calcula su factorial
*param un numero int
*return devuelve el factorial de el numero
*/
int factorial(int X);



/**
*brief es una barra de progreso que esta solo para molestar
*/
void barraDeProgresoTotalmenteInnecesaria(void);

void barraDeProgresoTotalmenteInnecesaria2(void);

/**
*no ingresen el numero 666
*/

void ERROR1(void)
{
	system("color 17");
printf(
	"\n usted ha usado todos los reintentos, !!!sillaso en la espalda!!!!"
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
"\n                                   Z8\n"



	);





}


