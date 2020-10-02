
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "control.h"

int main()
{
    int aux;
    eEmployee employeeList[lenght];
    emp_initEmployees(employeeList,lenght);
    hardcodearEmpleados(employeeList,lenght);
    int opcionSeleccionada;
    int condicionDeOrdenamiento;
    do{
       clearScreen();
        menuDisplay();
        if(getValidInt("\nelija una opcion [_]\b\b","\nerror opcion invalida",&opcionSeleccionada,1,5,3)!=-1)
        {
              switch(opcionSeleccionada)
            {
                case 1://"1- ALTAS"
                emp_addEmployee(employeeList,lenght);
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

                    getValidInt("ingrese '1' para = 1-10,a-z \0 '0' para = 10-1,z-a ","error, valor invalido o fuera de rango",
                                &condicionDeOrdenamiento,0,1,3);

                    sortEmployees(employeeList,lenght,condicionDeOrdenamiento);
                    printEmployees(employeeList,lenght);
                    promedioSueldos(employeeList,lenght);

                    pausarYBorrar();
                    break;
            }
        }
        }while(opcionSeleccionada!=5);


    printf("adios!\n");
    return 0;
}
