#include "control.h"


void menuDisplay(void){

    char lista[5][70]={"1- ALTAS","2- MODIFICAR","3- BAJA","4- INFORMAR","5- salir"};

    for(int i=0; i<5 ; i++)
    {
        printf("\n %-70s", lista[i]);
    }
}


void pausarYBorrar(void)
{
    puts("\n");
    system("pause");
    system("cls");
}




