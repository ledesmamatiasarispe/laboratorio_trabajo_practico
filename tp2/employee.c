#include "employee.h"
#include "unt_ingresoDeDatos.h"
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
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


/*2.2 Función addEmployees
Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre.*/

/*sin el uso de punteros esta funcion es imposible, ya que no puedo usarla solo para asignar los valores
cual creo que seria su funcion ideal. por lo tanto tengo que hacer toda la logica adentro de la misma.
*/
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 4
Programación I – Laboratorio I

*/
int emp_addEmployee(eEmployee employeelist[], int len)
{
    int retorno=-1;
    if(employeelist !=NULL && len>0 )//valida los datos ingresados
    {
        float salarioAuxFloat;
        int sectorAuxInt;
        int emptyIndex;
        int reintentos=3;
        if(getFirstEmptyIndex(employeelist,len,&emptyIndex)==0)//este if verifica si hay espacio
        {
            printf("\n Error! No hay mas lugares libres\n");


        }else//y si hay espacio este else modifica los datos
        {
            //se ingresan los datos;
            emp_SetId(employeelist,-1,emptyIndex);

            getValidNames("ingrese el nombre = ","\nError! intente nuevamente",
                          "\nError! the name must not exceed 51 characters ",employeelist[emptyIndex].name,51,reintentos);
            getValidNames("ingrese el apellido = ","\nError!  intente nuevamente",
                          "\nError!last name must not exceed 51 characters ",employeelist[emptyIndex].lastName,51,reintentos);
            getValidFloat("ingrese el salario","error intente nuevamente",&salarioAuxFloat,reintentos);
            getValidInt("ingrese el sector = ","\nError! intente nuevamente",&sectorAuxInt,0,10,reintentos);


            employeelist[emptyIndex].sector = sectorAuxInt;
            employeelist[emptyIndex].salary = salarioAuxFloat;
            employeelist[emptyIndex].isEmpty = FALSE;
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

//2.6 Función printEmployees
//Imprime el array de empleados de forma encolumnada.
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(eEmployee* list, int len)
{
    if(list!=NULL&&len>0)
    {
        int i;
        system("cls");
        printf("\n%5s | %-20s | %-20s | %-10s | %-10s","ID","name","lastname","salary","sector");
        for(i=0; i<len && list[i].isEmpty==FALSE;i++)
        {
            printf("\n%5d | %20s | %20s | %10.2f | %10d",list[i].id ,list[i].name , list[i].lastName ,list[i].salary,list[i].sector);
        }
        return 1;
    }

return 0;
}

//2.3 Función findEmployeeById
//Busca un empleado recibiendo como parámetro de búsqueda su Id.
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
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
/**
*2.4 Función removeEmployee
*\brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmployee* list, int len, int id)
{
int retorno=-1;
int index;

index = findEmployeeById(list,len,id);

    if(list!=NULL && len>0 && id > 0 && id < 1000)
    {




       list[index].isEmpty=TRUE;
    }
return retorno;
}
