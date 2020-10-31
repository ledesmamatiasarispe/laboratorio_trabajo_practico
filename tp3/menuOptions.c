#include "menuOptions.h"


int opcion_cargarEmpleadosDesdeCsv(char path[], LinkedList* list)
{
    int retorno = -1;
    if(path != NULL && list != NULL)
    {
        int ListLen = ll_len(list);
        retorno = 1;
        if(ListLen == 0)
        {
            if(controller_loadFromText(path,list) == 0)
            {
                printf("data.csv se cargo correctamente");
                pause();
                retorno = 0;
            }
        }else{
            printf("\nya hay un archivo cargado\n");
            pause();
            retorno = 2;
        }
    }
    return retorno;
}

int opcion_cargarEmpleadosDesdeBin(char path[] , LinkedList* list)
{
    int retorno = -1;
    if(path != NULL && list != NULL)
    {
        int ListLen = ll_len(list);
        retorno = 1;
        if(ListLen == 0)
        {
            if(controller_loadFromBinary(path,list) == 0)
            {
                printf("data.bin se cargo correctamente");
                pause();
                retorno = 0;
            }
        }else{
            printf("\nya hay un archivo cargado\n");
            pause();
            retorno = 2;
        }
    }
    return retorno;
}


int opcion_darDeAltaAEmpleado(LinkedList* list)
{
    int retorno = -1;
    if(list != NULL)
    {
        retorno = 1;

        int ListLen = ll_len(list);
        char opcionIngresada;

        if(ListLen == 0)
        {
            printf("\n la lista esta vacia!\n");
            opcionIngresada = getChar("¿desea agregar un empleado igualmente? (s/N)");
            opcionIngresada = tolower(opcionIngresada);

            retorno = 2;
        }
        if(ListLen > 0 ||  opcionIngresada == 's' )
        {
            printf("se esta cargando un nuevo empleado\n\n");
            controller_addEmployee(list);
            retorno = 0;
        }
    }
    return retorno;
}

int opcion_editarEmpleado(LinkedList* list)
{
    int retorno = -1;
    if(list != NULL)
    {
        retorno = 1;
        int ListLen = ll_len(list);
        if(ListLen == 0)
        {
            printf("\n la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
            pause();
            }else
             {

                retorno = controller_editEmployee(list);
                if(retorno = 0)
                {
                    printf("\n el empleado se modifico exitosamente\n");

                }else if(retorno = 2)
                 {
                    printf("\n el empleado no existe\n");
                 }
             }
    }
    return retorno;
}


int opcion_darDeBajaEmpleado(LinkedList* list)
{
    int retorno = -1;
    if(list != NULL)
    {
        int ListLen = ll_len(list);

        if(ListLen == 0)
        {
            printf("\n la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
            pause();
            }else
             {
               retorno = controller_removeEmployee(list);
                pause();
             }
    }
    return retorno;
}

int opcion_listarEmpleados(LinkedList* list)
{
    int retorno = -1;
    if(list != NULL)
    {
        int ListLen = ll_len(list);

        if(ListLen == 0)
        {
            printf("\n la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
            pause();
        }else
         {
            controller_ListEmployee(list);
            pause();
         }
    }
    return retorno;
}

int opcion_ordenarEmpleados(LinkedList* list)
{
    int retorno = -1;
    if(list != NULL)
    {
        int ListLen = ll_len(list);
        int opcionIngresada;
        if(ListLen == 0)
        {
            printf("\n no se puede ordenar\n la lista esta vacia! cargue un archivo.\1\n");
            pause();
        }else
        {
            imprimirOpciones("opciones :  \n1. ordenar por nombre de a-z"
                             "\n2. ordenar por id ");

            getValidInt("\ningrese una opcion de la lista [ ]\b\b","\n error! opcion fuera de rango",
                                    &opcionIngresada,1,2,3);

            clearScreen();
            switch(opcionIngresada)
            {
                case 1:
                    controller_sortEmployee(list,employee_CompareByName);
                    printf("\n el archivo se  ordeno por nombre");
                    pause();
                    break;
                case 2:
                    controller_sortEmployee(list,employee_CompareById);
                    printf("\n el archivo se  ordeno por id");
                    pause();
                    break;
            }
        }
    }
    return retorno;
}

int opcion_save(char path[],LinkedList* list,controller_saveAs pSaveAs )
{
    int retorno = -1 ;
    if(path != NULL && list != NULL && pSaveAs != NULL)

    {
       retorno = 1;
       int ListLen = ll_len(list);
        if(ListLen == 0)
        {
            printf("\n no se puede guardar el archivo\n "
                    "la lista esta vacia! de alta a un empleado o cargue un archivo.\1\n");
            pause();
        }else
        {
            retorno = 0;
            controller_sortEmployee(list,employee_CompareById);
            pSaveAs(path,list);
            printf("\n el archivo se guardo correctamente");
            pause();
        }
    }
    return retorno;
}



int opcion_vaciarLinkedlist(LinkedList* list)
{
    int retorno = -1;
    if(list != NULL)
    {
        retorno = 1;
        int ListLen = ll_len(list);
        if(ListLen == 0)
        {
            printf("la lista ya esta vacia.\1\n");
            pause();
        }else
        {
            if(controler_vaciarLinkedList(list) == 0)
            {
                printf("\n se borro todo");
                pause();
                retorno = 0;
            }
        }
    }
return retorno ;
}




















