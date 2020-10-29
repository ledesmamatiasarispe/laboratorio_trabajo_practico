#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
/****************************************************
    Menu:
    * 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
    * 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
    * 3. Alta de empleado
    * 4. Modificar datos de empleado
    * 5. Baja de empleado
    * 6. Listar empleados
     7. Ordenar empleados
    * 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
    * 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    * 10. Salir
*****************************************************/


int main()
{
    LinkedList* listaDeEmpleados;
    listaDeEmpleados = ll_newLinkedList();
    int opcionIngresada, ListLen;

    do{

    ListLen = ll_len(listaDeEmpleados);
    clearScreen();
    // imprimir menu

    getValidInt("\ningrese una opcion de la lista [ ]\b\b","\n error! opcion fuera de rango",
                &opcionIngresada,0,10,3);
        switch(opcionIngresada){

            case 1: /* cargar del texto */
                if(ListLen == 0)
                {
                  if(controller_loadFromText("data.csv",listaDeEmpleados) == 0)
                  {
                      printf("data.csv se cargo correctamente");
                      pause();
                  }
                }else{
                     printf("\nya hay un archivo cargado\n");
                     pause();
                 }

                break;
            case 2: /* cargar del binario */
                if(ListLen == 0)
                {
                  if(controller_loadFromBinary("data.bin",listaDeEmpleados) == 0)
                  {
                      printf("data.bin se cargo correctamente");
                      pause();
                  }
                }else{
                     printf("\nya hay un archivo cargado\n");
                     pause();
                 }

                break;
            case 3: /* dar de alta */
                 if(ListLen == 0)
                {
                    printf("\n la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
                     pause();
                }else{
                    controller_addEmployee(listaDeEmpleados);
                    pause();
                }
                break;
            case 4: /* dar de alta */
                 if(ListLen == 0)
                {
                    printf("\n la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
                     pause();
                }else{
                    controller_editEmployee(listaDeEmpleados);
                    pause();
                }
                break;
            case 5: /* dar de alta */
                 if(ListLen == 0)
                {
                    printf("\n la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
                     pause();
                }else{
                    controller_removeEmployee(listaDeEmpleados);
                    pause();
                }
                break;

            case 6: /* listar empleados */
                if(ListLen == 0)
                {
                    printf("\n la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
                     pause();
                }else{
                    controller_ListEmployee(listaDeEmpleados);
                     pause();
                }
                break;
            case 8: /* guardar como txt */
                if(ListLen == 0)
                {
                    printf("\n no se puede guardar el archivo\n "
                           "la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
                     pause();
                }else{
                    controller_saveAsText("data.csv",listaDeEmpleados);
                    printf("\n el archivo se guardo correctamente");
                     pause();
                }
                break;
            case 9: /* guardar en bin */
                if(ListLen == 0)
                {
                    printf("\n no se puede guardar el archivo\n "
                           "la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
                     pause();
                }else{
                    controller_saveAsBinary("data.bin",listaDeEmpleados);
                     printf("\n el archivo se guardo correctamente");
                     pause();
                }
                break;
        }




    } while(opcionIngresada!=10);









    return 0;
}


/* no tocar, peligroso!
int i=33;
while(i<255){
    if( !((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) )
    {
        printf("%c",186);
        printf(" El \\%-3d es = %3c ",i,i);
        if(i%4==0){
        printf("\n");
        }
    }

    i++;
}
*/
