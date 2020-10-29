#include <stdio.h>
#include <stdlib.h>
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
    printf("opciones :  \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
     "\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)."
     "\n3. Alta de empleado"
     "\n4. Modificar datos de empleado"
     "\n5. Baja de empleado"
     "\n6. Listar empleados"
     "\n7. Ordenar empleados"
     "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
     "\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario)."
     "\n10 vaciar la lista"
     "\n11. Salir");

    getValidInt("\ningrese una opcion de la lista [ ]\b\b","\n error! opcion fuera de rango",
                &opcionIngresada,0,10,3);
        switch(opcionIngresada){
            clearScreen();
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
                    printf("se esta cargando un nuevo empleado\n\n");
                    controller_addEmployee(listaDeEmpleados);
                    pause();
                }
                break;

            case 4: /* modificar */
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

                case 7: /* ordenar */
                if(ListLen == 0)
                {
                    printf("\n no se puede ordenar\n "
                           "la lista esta vacia! cargue un archivo.\1\n");
                     pause();
                }else{
                    printf("opciones :  \n1. ordenar por nombre de a-z"
                                        "\n2. ordenar por id ");
                     getValidInt("\ningrese una opcion de la lista [ ]\b\b","\n error! opcion fuera de rango",
                                    &opcionIngresada,1,2,3);
                     clearScreen();
                    switch(opcionIngresada){

                    case 1:
                        controller_sortEmployee(listaDeEmpleados,employee_CompareByName);
                        printf("\n el archivo se  ordeno por nombre");
                        pause();
                    break;
                     case 2:
                        controller_sortEmployee(listaDeEmpleados,employee_CompareById);
                        printf("\n el archivo se  ordeno por id");
                        pause();
                    break;

                    }
                }
                break;
            case 8: /* guardar como txt */
                if(ListLen == 0)
                {
                    printf("\n no se puede guardar el archivo\n "
                           "la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
                     pause();
                }else{
                    controller_sortEmployee(listaDeEmpleados,employee_CompareById);
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
                     controller_sortEmployee(listaDeEmpleados,employee_CompareById);
                     controller_saveAsBinary("data.bin",listaDeEmpleados);
                     printf("\n el archivo se guardo correctamente");



                     pause();
                }
                break;
            case 10: /* borrar todo */
                if(ListLen == 0)
                {
                    printf("la lista ya esta vacia.\1\n");
                        pause();
                }else{
                    if(controler_LinkedListBorradoCompleto(listaDeEmpleados) == 0)
                    {
                        printf("\n se borro todo");
                        pause();
                    }
                }
                break;
        }/* switch*/




    } while(opcionIngresada!=11);









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
