#include "control.h"

#define MostrarOpcionesExtraSI 'S'
#define MostrarOpcionesExtraNO 'N'


void menuDisplay(char lista[][70]){
    for(int i=0;lista[i][0]!= MostrarOpcionesExtraNO ; i++)
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





