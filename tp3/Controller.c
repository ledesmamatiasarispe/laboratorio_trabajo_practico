#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    //1- validar parametros DE LA FUNCION
    int retorno = -1;
    if(pArrayListEmployee!=NULL)
    {
        retorno = 0; //validaron los parametros

            //2- ingresar los datos para el empleado en un aux
        // si todo esta bien entonces 3

        //3- pedir un espacio en heap para 1 empleado
        //si el espacio se creo entonces 4

        //4- guardar ese espacio en la linked list
        //si 4 esta bien entonces 5

        //5-
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


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
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

