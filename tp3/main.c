#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "menuOptions.h"
/****************************************************
*Arispe Matias
    Menu:
    * 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
    * 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
    * 3. Alta de empleado
    * 4. Modificar datos de empleado
    * 5. Baja de empleado
    * 6. Listar empleados
    * 7. Ordenar empleados
    * 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
    * 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    * 10. Salir
*****************************************************/




int main()
{

    LinkedList* listaDeEmpleados;
    listaDeEmpleados = ll_newLinkedList();
    int opcionIngresada;

    do{
    clearScreen();
    imprimirOpciones("opciones :  \n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
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
                &opcionIngresada,0,11,3);
                //clearScreen();
        switch(opcionIngresada){
            case 1:
                opcion_cargarEmpleadosDesdeCsv("data.csv",listaDeEmpleados);
                break;

            case 2:
                opcion_cargarEmpleadosDesdeBin("data.bin",listaDeEmpleados);
                break;

            case 3:
                opcion_darDeAltaAEmpleado(listaDeEmpleados);
                break;

            case 4:
                 opcion_editarEmpleado(listaDeEmpleados);
                break;

            case 5:
                opcion_darDeBajaEmpleado(listaDeEmpleados);
                break;

            case 6:
                opcion_listarEmpleados(listaDeEmpleados);
                break;

            case 7:
               opcion_ordenarEmpleados(listaDeEmpleados);
                break;
            case 8:
                opcion_save("data.csv",listaDeEmpleados,controller_saveAsText);
                break;
            case 9:
                 opcion_save("data.bin",listaDeEmpleados,controller_saveAsBinary);

                break;
            case 10: /* borrar todo */
                opcion_vaciarLinkedlist(listaDeEmpleados);
                break;
        }
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
