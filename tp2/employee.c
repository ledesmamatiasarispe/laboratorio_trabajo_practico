#include <stdio.h>
#include <string.h>
#include "employee.h"
#include "unt_ingresoDeDatos.h"



int emp_initEmployees(eEmployee* employeelist, int len)
{
    if(employeelist!=NULL&&len>0)
    {
        int i;
        for(i=0;i<len;i++)
        {
            employeelist[i].isEmpty=TRUE;
            employeelist[i].id=0;
        }
        return 0;
    }
return -1;
}



int emp_addEmployee(eEmployee employeelist[], int len)
{
    int retorno=-1;
    if(employeelist !=NULL && len>0 )//valida los datos ingresados
    {
        float salarioAuxFloat;
        int sectorAuxInt;
        int emptyIndex;
        char nombreAux[51];
        char apellidoAux[51];
        char validacionAux;
        if(getFirstEmptyIndex(employeelist,len,&emptyIndex)==0)//este if verifica si hay espacio
        {
            printf("\n Error! No hay mas lugares libres\n");


        }else//y si hay espacio este else modifica los datos
        {
            //se ingresan los datos;

            do{// aca algo estoy haciendo mal, aveces los datos validan, pero a veces deciden no valida nada .

            if(emp_SetId(employeelist,-1,emptyIndex) == -1)
            {
                break;
            }

            if(getValidNames("ingrese el nombre = ","\nError! intente nuevamente",
                          "\nError! el nombre no debe superar los 51 caracteres. ",nombreAux,51,3) == -1)
            {
                break;
            }

              if(getValidNames("ingrese el apellido = ","\nError!  intente nuevamente",
                         "\nError!el apellido no debe superar los 51 caracteres. ",apellidoAux,51,3) == -1)
            {
                break;
            }


             if(getValidFloat("ingrese el salario","error intente nuevamente",&salarioAuxFloat,3) == -1)
            {
                break;
            }

             if(getValidInt("ingrese el sector = ","\nError! intente nuevamente",&sectorAuxInt,0,10,3) == -1)
            {
                break;
            }

            validacionAux = getChar("confirmar ingreso de datos 'Y', 'N'");
            }while(validacionAux != 'Y' && validacionAux != 'y' && validacionAux != 'n' && validacionAux != 'N');

            if(validacionAux == 'Y' || validacionAux == 'y')
            {
                strcpy(employeelist[emptyIndex].lastName , apellidoAux);
                strcpy(employeelist[emptyIndex].name , nombreAux);
                employeelist[emptyIndex].sector = sectorAuxInt;
                employeelist[emptyIndex].salary = salarioAuxFloat;
                employeelist[emptyIndex].isEmpty = FALSE;
                retorno=0;
            }
         }
    }
return retorno;
}

int getFirstEmptyIndex(eEmployee* employeelist, int len,int* emptyIndex)
{

    if(employeelist != NULL&&len > 0 &&emptyIndex!=NULL )
    {
        int i;
        for(i=0;i<len;i++)
        {
            if(employeelist[i].isEmpty==TRUE)
            {
               *emptyIndex = i;
               return 1;
            }
        }
        return 0;
    }
    return -1;
}

int emp_SetId(eEmployee* empleado,int id,int index)//el primer id va a ser 0 y cada nuevo entry va a tener un id diferente.
//si falla en encontrar un id retorna -1;
{

    int retorno =-1;
    static int maxId=0;
    if(empleado != NULL)
    {
        retorno = 0;
        if(id < 0)
        {
            maxId++;
            empleado[index].id = maxId;
        }
    }

    return retorno;
}


int printEmployees(eEmployee* list, int len)
{
    if(list!=NULL&&len>0)
    {
        int i;
        system("cls");
        printf("\n%5s | %-20s | %-20s | %-10s | %-10s","ID","nombre","apellido","salario","sector");
        for(i=0; i<len && list[i].isEmpty==FALSE;i++)
        {
            printf("\n%5d | %20s | %20s | %10.2f | %10d",list[i].id ,list[i].name , list[i].lastName ,list[i].salary,list[i].sector);
        }
        return 1;
    }

return 0;
}


int findEmployeeById(eEmployee* list, int len,int id)
{
    int i;
    int returnIndex = -1;
    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(id==list[i].id&&list)
            {
                returnIndex = i;
            }
        }
    }

return returnIndex;
}


int removeEmployee(eEmployee* list, int len, int id)
{
int retorno=-1;
    if(list!=NULL && len>0 && id > 0 && id < 1000)
    {

        int index;
        index = findEmployeeById(list,len,id);

        if(index!=-1)
        {
            printf("el empleado a borrar es : \n");
             printf("\n%5s | %-20s | %-20s | %-10s | %-10s","ID","nombre","apellido","salario","sector");
            printf("\n%5d | %20s | %20s | %10.2f | %10d\n",list[index].id ,list[index].name , list[index].lastName ,list[index].salary,list[index].sector);


            if(getChar("para confirmar el borrado ingrese 'S' ") == 'S' )
            {
                list[index].isEmpty=TRUE;
                retorno=0;
            }
        }else
        {
            printf("este indice ya esta vacio \n");
        }
    }
return retorno;
}

int modificarEmployee(eEmployee list[], int len, int id)
{
int retorno=-1;
int sectorAuxInt;
float salarioAuxFloat;
    if(list!=NULL && len>0 && id > 0 && id < 1000)
    {

        char opcionesModificacion[][70]={"1- nombre","2- apellido","3- salario","4- sector","5- salir","N"};
        int index;
        index = findEmployeeById(list,len,id);

        if(index!=-1)
        {
            printf("el empleado a modificar es : \n");
             printf("\n%5s | %-20s | %-20s | %-10s | %-10s","ID","nombre","apellido","salario","sector");
            printf("\n%5d | %20s | %20s | %10.2f | %10d\n",list[index].id ,list[index].name , list[index].lastName ,list[index].salary,list[index].sector);


            if(getChar("¿Desea modificar este empleado? 'Y', 'N'") == 'Y' )
            {
                int opcionSeleccionada;
                do{
                    clearScreen();
                    menuDisplay(opcionesModificacion);

                    if(getValidInt("\nelija una opcion [_]\b\b","\nerror opcion invalida",&opcionSeleccionada,1,5,3)!=-1)
                    {
                          switch(opcionSeleccionada)
                          {
                            case 1://"1- nombre"
                                 getValidNames("ingrese el nombre = ","\nError! intente nuevamente",
                                    "\nError! el nombre no debe superar los 51 caracteres. ",list[index].name,51,3);
                                break;

                            case 2://"2- apellido"
                                getValidNames("ingrese el apellido = ","\nError!  intente nuevamente",
                                    "\nError!el apellido no debe superar los 51 caracteres. ",list[index].lastName,51,3);
                                break;

                            case 3://"3- salario"
                                getValidFloat("ingrese el salario","error intente nuevamente",&salarioAuxFloat,3);
                                list[index].salary = salarioAuxFloat;
                                break;

                            case 4://"4- sector"
                                getValidInt("ingrese el sector = ","\nError! intente nuevamente",&sectorAuxInt,0,10,3);
                                list[index].sector = sectorAuxInt;
                                break;
                         }//end swich
                    }//if(getValidInt);
                }while(opcionSeleccionada!=5);










            }
        }else
        {
            printf("No se encontro el empleado \n");
        }
    }
return retorno;
}
