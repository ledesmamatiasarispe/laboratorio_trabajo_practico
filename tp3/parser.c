#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* AuxEmployee;
    int datosEscaneados;
    char auxId[50] , auxNombre[50] ,auxHoras[50],auxSueldo[50];
    //recibe el pfile ya abierto y lo carga en un  liked list al final
    if(pFile!=NULL && pArrayListEmployee != NULL){
        retorno = 1;
        while(feof(pFile)){
            /* el fscanf separa los datos y los asigna a las variables correctas */
            datosEscaneados = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);
            if(datosEscaneados=4){
                retorno = 0;
                /*TODO : verificar si los dos siguientes funciones funcionaron correctamente*/
                    /*  employee crea un nuevo empleado en heap y luego le asigna los valores
                    tomados por el fscanf. luego ll_add añade ese *empleado a la llist  */
                    AuxEmployee = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
                    ll_add(pArrayListEmployee,AuxEmployee);

            }
        }
    }
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
