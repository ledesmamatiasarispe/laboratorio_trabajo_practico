#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1 ;
    if(path!=NULL && pArrayListEmployee != NULL)
    {
        FILE* pFile;
        retorno=1;

        if( (pFile = fopen(path,"r")) != NULL)
        {
            retorno=2;

            if(parser_EmployeeFromText(pFile,pArrayListEmployee) == 0)
            {
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
    if(path!=NULL && pArrayListEmployee != NULL)
    {
        FILE* pFile;
        retorno=1;

        if( (pFile = fopen(path,"rb")) != NULL)
        {

            retorno=2;

            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee) == 0)
            {
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
    int retorno = -1;

    if(pArrayListEmployee!=NULL)
    {
        retorno = 1;
        int id = 0;
        Employee* auxEmployee;


        auxEmployee =  employee_new();
        if(auxEmployee!=NULL)
        {
            employee_getId(auxEmployee,&id);
            if
            (
                employee_setNewId(auxEmployee,id) == 0 &&
                employee_ingresarInt("\ningrese el sueldo.[_______]\b\b\b\b\b\b\b\b",
                                    200000,1,auxEmployee,employee_setSueldo) == 1 &&

                employee_ingresarInt("\ningrese las horas trabajadas [___]\b\b\b\b",
                                    200,0,auxEmployee,employee_setHorasTrabajadas) == 1 &&

                employee_ingresarString("\ningrese el nombre : ",auxEmployee,employee_setNombre) == 1
            )
            {
                if( ll_add(pArrayListEmployee,auxEmployee) == 0 )
                {
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee!=NULL)
    {
        int id,opcionIngresada;
        char confirmarModificacion= '\0';

        Employee* auxEmployee;
        Employee employeeActual;

        retorno = 1;
        do{
            controller_ListEmployee(pArrayListEmployee);
            if
            (
                getValidInt("\ningrese el ID del usuario a modificar : ",
                            "\nerror!, el valor ingresado esta fuera de rango o no es un entero valido\n",&id,1,32767,3) == 0
            )
            {
                if((auxEmployee = employee_getById(pArrayListEmployee,id)) != NULL)
                {

                    employee_imprimirUnaTablaDe1(auxEmployee);
                    confirmarModificacion = getChar("¿desea modificar este empleado? (S/n)");
                    confirmarModificacion = tolower(confirmarModificacion);

                    if(auxEmployee!=NULL && confirmarModificacion != 'n' )
                    {
                        employeeActual = *auxEmployee;

                        printf("modificar :\n1-nombre\n-2-sueldo\n-3-horas\n-4-Salir ");
                        getValidInt("\ningrese una opcion de la lista [ ]\b\b","\n error! opcion fuera de rango",
                        &opcionIngresada,1,4,3);

                        switch(opcionIngresada)
                        {

                            case 1:
                                employee_ingresarString("\ningrese el nombre : ",&employeeActual,employee_setNombre);

                                break;
                            case 2:
                                employee_ingresarInt("\ningrese el sueldo.[_______]\b\b\b\b\b\b\b\b",
                                                    200000,1, &employeeActual,employee_setSueldo);
                                break;
                            case 3:
                                    employee_ingresarInt("\ningrese las horas trabajadas [___]\b\b\b\b",
                                                        200,0, &employeeActual,employee_setHorasTrabajadas);
                                    break;
                        }
                        employee_imprimirUnaTablaDe1(&employeeActual);
                        confirmarModificacion = getChar("¿desea guardar la modificacion? (S/n)");
                        confirmarModificacion = tolower(confirmarModificacion);
                        if(confirmarModificacion != 'n')
                        {
                            *auxEmployee = employeeActual;
                            retorno=0;
                        }
                    }
                }else
                 {
                    retorno = 2;
                    break;
                 }
            }

        }while(opcionIngresada != 4 && confirmarModificacion !='n');
    }
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        retorno = 1;
        int LinkedListIndex,id;
        char confirmarModificacion= '\0';
        Employee* auxEmployee;

        controller_ListEmployee(pArrayListEmployee);
        if
        (
            getValidInt("\ningrese el ID del usuario a eliminar : ",
                        "\nerror!, el valor ingresado esta fuera de rango o no es un entero valido\n",
                        &id,1,32767,3) == 0
        )
        {
            if((auxEmployee = employee_getById(pArrayListEmployee,id))!=NULL)
            {
                LinkedListIndex = employee_getIndexById(pArrayListEmployee,id);

                employee_imprimirUnaTablaDe1(auxEmployee);

                confirmarModificacion = getChar("¿desea eliminar este empleado? (s/N)");
                confirmarModificacion = tolower(confirmarModificacion);

                if(auxEmployee!=NULL && confirmarModificacion == 's' )
                {
                    ll_remove(pArrayListEmployee,LinkedListIndex);
                    employee_delete(auxEmployee);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}



int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1,lenLList;
    int i;
    if(pArrayListEmployee != NULL)
    {
        Employee* auxPEmpleadoActual;
        retorno = 1;
        lenLList = ll_len(pArrayListEmployee);
        employee_imprimirLaCabezeraDeLista();
        for(i=0;i<lenLList;i++)
        {
            if((auxPEmpleadoActual = (Employee*)ll_get(pArrayListEmployee,i) ) != NULL)
            {
                display_PrintEmployeeOnConsole(auxPEmpleadoActual);
            }
        }
        display_imprimirElFinalDeTabla();
    }
    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee,employee_CompareBy pcompare)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        retorno = 1;
        int len , i , j , auxProgressbar,auxProgres ;

        Employee* element1;
        Employee* element2;
        len = ll_len(pArrayListEmployee);
       //auxProgressbar = len / 20;
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if
                (
                    (element1 = (Employee*)ll_get(pArrayListEmployee,i))!=NULL &&
                    (element2 = (Employee*)ll_get(pArrayListEmployee,j))!=NULL
                )
                {

                    if(pcompare(element1,element2) > 0)
                    {
                        Employee_swapContents(element1,element2);
                    }
                }else
                 {
                     return 2;
                 }
            }
            barraDeProgreso(i,len);

            /*
            if( i % auxProgressbar == 0 || i == len-2)
            {
                clearScreen();
                auxProgres = (i*100)/len+1;
                printf(" %d %c  ",auxProgres,37);
                display_imprimirUnCharVariasVeces(220,auxProgres);
                display_imprimirUnCharVariasVeces(32,(100-auxProgres));
                display_imprimirUnCharVariasVeces(219,1);
            }
            */
        }
        retorno=0;
    }
    return retorno;
}






int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* Parch;
        Employee* auxPEmpleadoActual;
        char auxNombre[128];
        int auxId,auxSueldo,auxHorasTrabajadas,i,lenLList;

        retorno = 1;

        if((Parch = fopen(path,"w")) !=NULL)
        {
            lenLList = ll_len(pArrayListEmployee);
            fprintf(Parch,"id,nombre,horasTrabajadas,sueldo\n");
            for(i=0;i<lenLList;i++)/* es casi lo mismo que el listemployee */
            {
                /* consigo el puntero al empleado de la iteracion actual, y lo casteo de *void a *Empleado */
                if((auxPEmpleadoActual = (Employee*)ll_get(pArrayListEmployee,i) ) != NULL)
                {
                    /*si el puntero existe, entonces puedo imprimir el empleado*/
                    if
                    (
                        employee_getId(auxPEmpleadoActual,&auxId) == 0 &&
                        employee_getNombre(auxPEmpleadoActual,auxNombre) == 0 &&
                        employee_getSueldo(auxPEmpleadoActual,&auxSueldo) == 0 &&
                        employee_getHorasTrabajadas(auxPEmpleadoActual,&auxHorasTrabajadas) == 0
                    )
                    {
                        /*recupero los datos de de cada estructura*/
                        retorno = 0;
                        fprintf(Parch,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                        /* y las imprimo usando un fprintf , para porder acomodarlo en el formato del csv = "dato,dato,dato,ultimodato\n"*/
                    }
                }
            }
        }
        fclose(Parch);
    }
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* Parch;
        Employee* auxPEmpleadoActual;
        int i,lenLList;

        retorno = 1;
        if((Parch = fopen(path,"wb")) !=NULL)
        {
            lenLList = ll_len(pArrayListEmployee);
            for(i=0;i<lenLList;i++)
            { /* es casi lo mismo que el listemployee */
                /* consigo el puntero al empleado de la iteracion actual, y lo casteo de *void a *Empleado */
                if((auxPEmpleadoActual = (Employee*)ll_get(pArrayListEmployee,i) ) != NULL)
                {
                    /*si el puntero existe, entonces puedo imprimir el empleado*/
                    retorno = 0;
                    fwrite(auxPEmpleadoActual,sizeof(Employee),1,Parch);
                    /* y las imprimo usando un fprintf , para porder acomodarlo en el formato del csv = "dato,dato,dato,ultimodato\n"*/
                }
            }
        }
        fclose(Parch);
    }
    return retorno;
}




int controler_vaciarLinkedList(LinkedList* list)
{
int retorno = -1;
    if(list != NULL)
    {
        retorno = 1;
        int i,len;
        Employee* element;
        len = ll_len(list);

        for(i=0;i<len;i++)
        {
            if((element = (Employee*)ll_get(list,i)) !=NULL)
            {
                retorno = 0;
                free(element);
            }else
             {
                 retorno =2;
                 break;
             }
        }
        ll_clear(list);
        employee_setNewId(NULL,-1);
    }
return retorno;
}





