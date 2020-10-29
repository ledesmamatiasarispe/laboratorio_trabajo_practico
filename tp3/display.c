#include <stdio.h>
#include "display.h"



int display_PrintEmployeeOnConsole(void* this)
{
    int ll = 186;/*chars locos que voy a usar en el printf*/
    int retorno = -1 ;/* retorno de la funcion*/
    if(this != NULL){

        int auxId,auxSueldo,auxHorasTrabajadas;
        char auxNombre[50];

        employee_getId(this,&auxId);
        employee_getNombre(this,auxNombre);
        employee_getSueldo(this,&auxSueldo);
        employee_getHorasTrabajadas(this,&auxHorasTrabajadas);
        printf("%c %10d %c %20s %c %10d %c %20d %c  \n",ll,auxId,ll,auxNombre,ll,auxSueldo,ll,auxHorasTrabajadas,ll);

    }
return retorno;

}

void employee_cabezeraDeLista()
{
      int ll = 186;/*chars locos que voy a usar en el printf*/
        display_topTabla();
        printf("%c %-10s %c %-20s %c %-10s %c %-20s %c \n",ll,"ID",ll,"Nombre",ll,"Sueldo",ll,"Horas Trabajadas",ll);
        display_divisorCabezera();
}

void display_divisorCabezera(void)
{
display_imprimirUnCharVariasVeces(204,1);
display_imprimirUnCharVariasVeces(205,12);/*primer int */
display_imprimirUnCharVariasVeces(206,1);
display_imprimirUnCharVariasVeces(205,22);/*nombre */
display_imprimirUnCharVariasVeces(206,1);
display_imprimirUnCharVariasVeces(205,12);/*segundo int */
display_imprimirUnCharVariasVeces(206,1);
display_imprimirUnCharVariasVeces(205,22);/*tercer int */
display_imprimirUnCharVariasVeces(185,1);

display_imprimirUnCharVariasVeces(10,1);
}

void display_bottomTabla(void)
{
display_imprimirUnCharVariasVeces(200,1);
display_imprimirUnCharVariasVeces(205,12);/*primer int */
display_imprimirUnCharVariasVeces(202,1);
display_imprimirUnCharVariasVeces(205,22);/*nombre */
display_imprimirUnCharVariasVeces(202,1);
display_imprimirUnCharVariasVeces(205,12);/*segundo int */
display_imprimirUnCharVariasVeces(202,1);
display_imprimirUnCharVariasVeces(205,22);/*tercer int */
display_imprimirUnCharVariasVeces(188,1);

display_imprimirUnCharVariasVeces(10,1);
}

void display_topTabla(void)
{
display_imprimirUnCharVariasVeces(10,1);
display_imprimirUnCharVariasVeces(201,1);
display_imprimirUnCharVariasVeces(205,12);/*primer int */
display_imprimirUnCharVariasVeces(203,1);
display_imprimirUnCharVariasVeces(205,22);/*nombre */
display_imprimirUnCharVariasVeces(203,1);
display_imprimirUnCharVariasVeces(205,12);/*segundo int */
display_imprimirUnCharVariasVeces(203,1);
display_imprimirUnCharVariasVeces(205,22);/*tercer int */
display_imprimirUnCharVariasVeces(187,1);

display_imprimirUnCharVariasVeces(10,1);
}

void display_imprimirUnCharVariasVeces(int caracter, int cantidad)
{
    int i=0;
    for(;i < cantidad;i++){
        printf("%c",caracter);
    }
}


