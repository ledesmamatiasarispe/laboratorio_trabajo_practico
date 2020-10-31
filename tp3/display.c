#include <stdio.h>
#include "display.h"



/** \brief
 *
 * \param this void*
 * \return int int -1 parametros invalidos, 1 validaron los parametros , 0 funciono todo correctamente.
 *
 */
int display_PrintEmployeeOnConsole(void* this)
{

    int retorno = -1 ;/* retorno de la funcion*/
    if(this != NULL){
        int ll = 186;/*chars que voy a usar en el printf*/
        retorno = 1;
        int auxId,auxSueldo,auxHorasTrabajadas;
        char auxNombre[50];
        if
        (
            employee_getId(this,&auxId) == 0 &&
            employee_getNombre(this,auxNombre)== 0 &&
            employee_getSueldo(this,&auxSueldo)== 0 &&
            employee_getHorasTrabajadas(this,&auxHorasTrabajadas) == 0
        )
        {
            printf("%c %10d %c %20s %c %10d %c %20d %c  \n",ll,auxId,ll,auxNombre,ll,auxSueldo,ll,auxHorasTrabajadas,ll);
            retorno = 0;
        }
    }
    return retorno;
}

void employee_imprimirLaCabezeraDeLista()
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

void display_imprimirElFinalDeTabla(void)
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


void imprimirOpciones(char opciones[])
{

    printf("\n %s \n " , opciones);

}

void barraDeProgreso(int progresoActual,int cantidadTotal)
{
    if( progresoActual % (cantidadTotal/20) == 0 || progresoActual == cantidadTotal-2)
    {
        clearScreen();
        int porcentajeDeProgreso = (progresoActual*100)/cantidadTotal+1;

        printf(" %d %c  ",porcentajeDeProgreso,37);
        display_imprimirUnCharVariasVeces(220,porcentajeDeProgreso);
        display_imprimirUnCharVariasVeces(32,(100-porcentajeDeProgreso));
        display_imprimirUnCharVariasVeces(219,1);
    }
}










