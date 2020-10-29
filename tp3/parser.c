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
        /*la lista tiene una cabecera en el primer renglon. Este fscanf la "lee"
         y deja el puntero al principo del primer empleado,
         el cual si es un dato valido */
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);

        while(!feof(pFile)){
            /* el fscanf separa los datos y los asigna a las variables correctas */
            datosEscaneados = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);
            if(datosEscaneados=4){

                    /*  employee crea un nuevo empleado en heap y luego le asigna los valores
                    tomados por el fscanf. luego ll_add añade ese *empleado a la llist  */
                    if((AuxEmployee = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo))!=NULL)
                    {

                         ll_add(pArrayListEmployee,AuxEmployee);
                          retorno = 0;
                    }
            }
        }
    }
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    Employee* AuxEmployee;
    int datosEscaneados;
    //recibe el pfile ya abierto y lo carga en un  liked list al final
    if(pFile!=NULL && pArrayListEmployee != NULL){
        retorno = 1;

        while(!feof(pFile)){ /* este while va a iterar hasta que el puntero se encuentre en
                el final del archivo*/

                AuxEmployee = employee_new();/* creo un espacio para un empleado en heap */

            /* el fread lee una porcion de datos de tamaño x
            especificada en el segundo parametro, una cantidad n de veces especificada en el tercer parametro */
            if(fread(AuxEmployee,sizeof(Employee),1,pFile)){
                retorno = 0;

                ll_add(pArrayListEmployee,AuxEmployee);

            }
        }
    }
    return retorno;
}
