#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/**
* @brief carga un txt en la linked list
*
*
*
**/
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1 ;
    if(path!=NULL && pArrayListEmployee != NULL){

          FILE* pFile;
          retorno=1;
          /* validaron los datos*/
          if( (pFile = fopen(path,"r")) != NULL){ /* esta linea abre el archivo pasado como path */
            retorno=2;

                /* El archivo se cargo correctamente */
                /* employeeFromText parsea el archivo y guarda los datos en la linked list*/
                if(parser_EmployeeFromText(pFile,pArrayListEmployee) == 0){
                    retorno = 0;
                }
          }

    }
    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}







/// @brief añade un employee nuevo a una linkedlist
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    /*1- validar parametros DE LA FUNCION*/
    int retorno = -1;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL)
    {
        retorno = 1; /*validaron los parametros*/

         /*2- pedir un espacio en heap para 1 empleado*/

        auxEmployee =  employee_new();
       if(auxEmployee!=NULL)/*si el espacio se creo entonces 3*/
       {
        /*3- ingresar los datos para el empleado en un aux*/

         if(/*si todo esta bien entonces 4*/
                // TODO (arisp#1#): ingresar el id
                 employee_ingresarInt("ingrese el sueldo. min 18000",
                                      200000,100000,auxEmployee,employee_setSueldo)==1 &&
                 employee_ingresarInt("ingrese las horas trabajadas",
                                      48,0,auxEmployee,employee_setHorasTrabajadas)==1 &&

                 employee_ingresarString("ingrese el nombre",auxEmployee,employee_setNombre)==1
          )
          {
                  /*4- guardar ese espacio en la linked list*/
                if( ll_add(pArrayListEmployee,auxEmployee) == 0 ) //si 4 esta bien entonces 5
                {
                    retorno = 0; //5-retornar que todo salio bien
                }
          }
       }
    }
    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


/** \brief imprime una lista de todos los empleados a los que apunta LinkedList
 *
 * \param pArrayListEmployee LinkedList* el puntero a la lList de empleados
 * \return int retornara -1 caso sean invalidos las parametros actuales,
 sera 0 caso la funcion valide completamente, y >0 si haya fracasado alguna funcion interna
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1,lenLList;/*variables para la lista */
    int i;/* control del for */
    if(pArrayListEmployee != NULL)
    {

        Employee* auxPEmpleadoActual; /* puntero al empleado de la iteracion actual */
        retorno = 0;
        lenLList = ll_len(pArrayListEmployee);/* consigue el largo atual de la llist*/
        for(i=0;i<lenLList;i++){

          /* consigo el puntero al epleado de la iteracion actual, y lo casteo de *void a *Empleado */
            if((auxPEmpleadoActual = (Employee*)ll_get(pArrayListEmployee,i) ) != NULL){
                /*si el puntero existe, entonces puedo imprimir el empleado*/
                employee_PrintOnConsole(auxPEmpleadoActual);

            }

        }


    }


    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

