#include "unt_ingresoDeDatos.h"
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "control.h"
#define TRUE 1
#define FALSE 0
#define lenght 30//len of the eEmployee list aray


char opciones[][70]={"1- ALTAS","2- MODIFICAR","3- BAJA","4- INFORMAR","5- salir","N"};


int main()
{
    int aux;
    eEmployee employeeList[lenght];
    emp_initEmployees(employeeList,lenght);
    int opcionSeleccionada;
    do{
       clearScreen();
        menuDisplay(opciones);

        if(getValidInt("\nelija una opcion [_]\b\b","\nerror opcion invalida",&opcionSeleccionada,1,5,3)!=-1)
        {
              switch(opcionSeleccionada)
            {
                case 1://"1- ALTAS"
                emp_addEmployee(employeeList,lenght);
                //funciona mal, solo la funcion getalgo que esta primera valida y las otras no validan nada

                    break;
                case 2://"2- MODIFICAR"
                    getValidInt("ingrese id del empleado a modificar","error ingrese nuevamente",&aux,0,1001,3);
                    modificarEmployee(employeeList,lenght,aux);
                      pausarYBorrar();
                    break;
                case 3://"3- BAJA"
                    getValidInt("ingrese id del empleado a borrar","error ingrese nuevamente",&aux,0,1001,3);
                    removeEmployee(employeeList,lenght,aux);
                    pausarYBorrar();
                    break;

                case 4://"4- INFORMAR"

                    printEmployees(employeeList,lenght);
                    pausarYBorrar();
                    break;
            }
        }
        }while(opcionSeleccionada!=5);


    printf("adios!\n");
    return 0;
}
