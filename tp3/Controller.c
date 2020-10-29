#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "display.h"
#include "utn.h"
#include "Controller.h"
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

        fclose(pFile);
    }

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1 ;
    if(path!=NULL && pArrayListEmployee != NULL){

          FILE* pFile;
          retorno=1;
          /* validaron los datos*/
          if( (pFile = fopen(path,"rb")) != NULL){ /* esta linea abre el archivo pasado como path */
            retorno=2;

                /* El archivo se cargo correctamente */
                /* employeeFromText parsea el archivo y guarda los datos en la linked list*/
                if(parser_EmployeeFromBinary(pFile,pArrayListEmployee) == 0){
                    retorno = 0;
                }
          }

        fclose(pFile);
    }
    return retorno;
}







/// @brief añade un employee nuevo a una linkedlist
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    /*1- validar parametros DE LA FUNCION*/
    int retorno = -1;
    int id;
    Employee* auxEmployee;

    if(pArrayListEmployee!=NULL){
        retorno = 1; /*validaron los parametros*/

        auxEmployee =  employee_new();/*2- pedir un espacio en heap para 1 empleado*/
       if(auxEmployee!=NULL)/*si el espacio se creo entonces 3*/
       {
        /*3- ingresar los datos para el empleado en un aux*/
         employee_getId(auxEmployee,&id);
         if(/*si todo esta bien entonces 4*/
                 employee_setNewId(auxEmployee,id) == 0 &&
                 employee_ingresarInt("\ningrese el sueldo.[_______]\b\b\b\b\b\b\b\b",
                                      200000,18000,auxEmployee,employee_setSueldo)==1 &&
                 employee_ingresarInt("\ningrese las horas trabajadas [___]\b\b\b\b",
                                      200,0,auxEmployee,employee_setHorasTrabajadas)==1 &&

                 employee_ingresarString("\ningrese el nombre : ",auxEmployee,employee_setNombre)==1
          ){
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

    /*1- validar parametros DE LA FUNCION*/
    int retorno = -1;
    int id,opcionIngresada;
    char confirmarModificacion= '\0';
    Employee* auxEmployee;
    Employee employeeActual;
    if(pArrayListEmployee!=NULL){
        retorno = 1; /*validaron los parametros*/
                    do{
                        controller_ListEmployee(pArrayListEmployee);
                        if(getValidInt("\ningrese el ID del usuario a modificar : ",
                                       "\nerror!, el valor ingresado esta fuera de rango o no es un entero valido\n",
                                       &id,1,32767,3) == 0){ /* ingreso el id de el usuario a modificar*/
                            printf("llego");
                            if((auxEmployee = employee_getById(pArrayListEmployee,id)) != NULL){/*consigo el usuario con
                                 el id que se ingreso y verifico si es valido el puntero que consegui*/

                                controler_imprimirUnaTablaDe1(auxEmployee);/* imprime el empleado que se consiguio */
                                confirmarModificacion = getChar("¿desea modificar este empleado? (S/n)");
                                confirmarModificacion = tolower(confirmarModificacion);

                                if(auxEmployee!=NULL && confirmarModificacion != 'n' ){

                                    employeeActual = *auxEmployee; /* guardo los valores del empleado en una variable local para no
                                    perder los datos anteriores en caso de que se arrepientan a ultimo momento de lo que se ingreso */

                                    printf("modificar :\n1-nombre\n-2-sueldo\n-3-horas\n-4-Salir ");/* imprime el menu*/
                                    getValidInt("\ningrese una opcion de la lista [ ]\b\b","\n error! opcion fuera de rango",
                                    &opcionIngresada,1,4,3);/* ingresa la opcion del menu */

                                    switch(opcionIngresada){

                                         case 1:/*nombre*/
                                            employee_ingresarString("\ningrese el nombre : ",&employeeActual,employee_setNombre);

                                            break;
                                        case 2:/*sueldo*/
                                            employee_ingresarInt("\ningrese el sueldo.[_______]\b\b\b\b\b\b\b\b",
                                                             200000,18000, &employeeActual,employee_setSueldo);
                                            break;
                                        case 3:/*horas*/
                                            employee_ingresarInt("\ningrese las horas trabajadas [___]\b\b\b\b",
                                                           200,0, &employeeActual,employee_setHorasTrabajadas);
                                            break;
                                    }
                                    controler_imprimirUnaTablaDe1(&employeeActual); /*  imprimo el empleado con las modificaciones    */
                                    confirmarModificacion = getChar("¿desea guardar la modificacion? (S/n)");
                                    confirmarModificacion = tolower(confirmarModificacion);
                                    if(confirmarModificacion != 'n'){
                                          *auxEmployee = employeeActual; /* si el usuario confirmo la modificacion
                                          guardo los valores modificados el espacio de memoria original */
                                          retorno=0;
                                    }
                            }
                       }
                }

        }while(opcionIngresada != 4 && confirmarModificacion !='n');
    }
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
      int retorno = -1;
      int LinkedListIndex,id;
      char confirmarModificacion= '\0';
      Employee* auxEmployee;

      controller_ListEmployee(pArrayListEmployee);
      if(getValidInt("\ningrese el ID del usuario a eliminar : ",
                    "\nerror!, el valor ingresado esta fuera de rango o no es un entero valido\n",
                    &id,1,32767,3) == 0){ /* ingreso el id de el usuario a modificar*/

            if((auxEmployee = employee_getById(pArrayListEmployee,id))!=NULL){/*consigo el usuario con
                                 el id que se ingreso y verifico si es valido el puntero que consegui*/
                LinkedListIndex = employee_getIndexById(pArrayListEmployee,id);

                controler_imprimirUnaTablaDe1(auxEmployee);/* imprime el empleado que se consiguio */
                confirmarModificacion = getChar("¿desea eliminar este empleado? (s/N)");
                confirmarModificacion = tolower(confirmarModificacion);

                if(auxEmployee!=NULL && confirmarModificacion == 's' ){

                    ll_remove(pArrayListEmployee,LinkedListIndex);
                    free(auxEmployee);

                }
            }
      }



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
                if(i==0){ /* este if imprime la cabezera de la lista que nombra cada columna */
                    employee_cabezeraDeLista();
                }
                display_PrintEmployeeOnConsole(auxPEmpleadoActual);

                if(i==(lenLList-1)){ /* este if imprime los char que cierrar el marco de la lista al final */
                   display_bottomTabla();
                }

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
    int retorno = -1;
    FILE* Parch;
    Employee* auxPEmpleadoActual;
    char auxNombre[128];
    int auxId,auxSueldo,auxHorasTrabajadas,i,lenLList;
    if(path != NULL && pArrayListEmployee != NULL){
        retorno = 1;
            if((Parch = fopen(path,"w")) !=NULL){


                lenLList = ll_len(pArrayListEmployee);
                fprintf(Parch,"id,nombre,horasTrabajadas,sueldo\n");
                for(i=0;i<lenLList;i++){ /* es casi lo mismo que el listemployee */

                  /* consigo el puntero al empleado de la iteracion actual, y lo casteo de *void a *Empleado */
                    if((auxPEmpleadoActual = (Employee*)ll_get(pArrayListEmployee,i) ) != NULL){
                        /*si el puntero existe, entonces puedo imprimir el empleado*/

                        employee_getId(auxPEmpleadoActual,&auxId);
                        employee_getNombre(auxPEmpleadoActual,auxNombre);
                        employee_getSueldo(auxPEmpleadoActual,&auxSueldo);
                        employee_getHorasTrabajadas(auxPEmpleadoActual,&auxHorasTrabajadas);
                        /*recupero los datos de de cada estructura*/
                        retorno = 0;
                        fprintf(Parch,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                        /* y las imprimo usando un fprintf , para porder acomodarlo en el formato del csv = "dato,dato,dato,ultimodato\n"*/
                    }
                }
            }
    }
    fclose(Parch);
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
        int retorno = -1;
    FILE* Parch;
    Employee* auxPEmpleadoActual;
    int i,lenLList;
    if(path != NULL && pArrayListEmployee != NULL){
        retorno = 1;
            if((Parch = fopen(path,"wb")) !=NULL){

                lenLList = ll_len(pArrayListEmployee);
                for(i=0;i<lenLList;i++){ /* es casi lo mismo que el listemployee */

                  /* consigo el puntero al empleado de la iteracion actual, y lo casteo de *void a *Empleado */
                    if((auxPEmpleadoActual = (Employee*)ll_get(pArrayListEmployee,i) ) != NULL){
                        /*si el puntero existe, entonces puedo imprimir el empleado*/


                        retorno = 0;
                        fwrite(auxPEmpleadoActual,sizeof(Employee),1,Parch);
                        /* y las imprimo usando un fprintf , para porder acomodarlo en el formato del csv = "dato,dato,dato,ultimodato\n"*/
                    }
                }
            }fclose(Parch);
    }

    return retorno;
}


int controler_imprimirUnaTablaDe1(Employee* this)
                    {
                        int retorno = -1;
                        if(this!=NULL){
                            retorno = 0;
                            employee_cabezeraDeLista();
                            display_PrintEmployeeOnConsole(this);
                            display_bottomTabla();
                        }
                          return retorno;
                    }
