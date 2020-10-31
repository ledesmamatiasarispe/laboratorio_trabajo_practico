#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int retorno = -1;

    //recibe el pfile ya abierto y lo carga en un  liked list al final
    if(pFile!=NULL && pArrayListEmployee != NULL)
    {
        Employee* AuxEmployee;
        int datosEscaneados;
        char auxId[50] , auxNombre[50] ,auxHoras[50],auxSueldo[50];
        retorno = 1;
        /*la lista tiene una cabezera en el primer renglon. Este fscanf la "lee"
         y deja el puntero al principo del primer empleado,
         el cual es un dato valido */

        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo)==4)
        {///esto podria estar en una funcion
            /* en este  if verifico si lo leido es numerico, para poder evitar leer el
            primer renglon en caso de ser una cabezera. pero tambien evito saltarme un empleado
            en caso de que el primer renglon contenga un dato valido*/
            if
            (
                esNumerico(auxId) == 1 &&
                esNumerico(auxHoras) == 1 &&
                esNumerico(auxSueldo) == 1
            )
            {
                printf("hizo rewind");
                pause();
                rewind(pFile);
            }
        }
        while(!feof(pFile))
        {
            /* el fscanf separa los datos y los asigna a las variables correctas */
            datosEscaneados = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);
            if(datosEscaneados=4)
            {
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

    if(pFile!=NULL && pArrayListEmployee != NULL)//recibe el pfile ya abierto y lo carga en un  liked list al final
    {
        Employee* AuxEmployee;
        int datosEscaneados;

        retorno = 1;

        while(!feof(pFile))/* este while va a iterar hasta que el puntero se encuentre en el final del archivo*/
        {
            AuxEmployee = employee_new();/* creo un espacio para un empleado en heap */
            /* el fread lee una porcion de datos de tamaño x
            especificada en el segundo parametro, una cantidad n de veces especificada en el tercer parametro */
            if(fread(AuxEmployee,sizeof(Employee),1,pFile))
            {
                retorno = 0;
                ll_add(pArrayListEmployee,AuxEmployee);
                /* al final añado el empleado leido a la lista y retorno 0 para avisar que todo salio bien*/
            }
        }
    }
    return retorno;
}







