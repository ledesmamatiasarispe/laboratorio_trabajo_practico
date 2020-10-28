#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include "utn.h"
#include <stdio.h>
///@brief crea un nuevo eempleado en heap y devuelve su &mdir. Siendo todos los miembros, valores por defecto .
Employee* employee_new()
{
    Employee* auxEmployee = NULL;//creo el aux que va contener el puntero localmente

   auxEmployee = (Employee*) malloc(sizeof(Employee)); // le pido a malloc que reserve una porcion de heap y me diga donde la consiguio
    if(auxEmployee!=NULL)//asigno valores por defectos para no tener basura y asi no mostrarla
    {
        employee_setHorasTrabajadas(auxEmployee,24);
        employee_setId(auxEmployee,0);
        employee_setNombre(auxEmployee,"nombre");
        employee_setSueldo(auxEmployee,18000);
    }

    return auxEmployee;//retorno la direccion de memoria
}

///@brief crea un nuevo eempleado en heap y devuelve su &mdir ,
///al mismo tiempo asignandole valores a cada miembro
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* auxEmployee = NULL;
   auxEmployee = (Employee*)malloc(sizeof(Employee));
    if(auxEmployee!=NULL)//asigno valores
    {
        employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr));
        employee_setId(auxEmployee,atoi(idStr));
        employee_setNombre(auxEmployee,nombreStr);
        employee_setSueldo(auxEmployee,atoi(sueldoStr));
    }
    return auxEmployee;
}




/** \brief muestra un mensaje para ingresar por consola un nombre, apellido ,etc.
 *
 * \param mensaje[] char un mensaje que se va a mostrar al momento de ingresar el valor
 * \param this Employee* el puntero donde se encuentra la estructura
 * \param punteroSet employee_setString es un funcion que asinga el dato en el un miembro de ka estructura
 * \return int -1 fallo de parametros. 0 parametros validaron. 1 se pudo asignar el dato correctamente.
 *
 */
int employee_ingresarString(char mensaje[],Employee* this,employee_setString punteroSet)
{
    int retorno = -1;
    char auxInput[1024];
    if(this!=NULL && punteroSet != NULL )//validar parametros
    {
        retorno = 0;//validaron los parametros
        if(
            getValidString(mensaje,"Error! reintente nuevamente",
                           "Error! limite de caracteres superado",auxInput,strlen(auxInput),3)==0 &&
            punteroSet(this,auxInput) == 0
        )
        {
          retorno = 1;
        }

    }
    return retorno;
}


int employee_ingresarInt(char mensaje[],int max,int min,Employee* this,employee_setInt punteroSet)
{
    int retorno = -1;
    int auxInput;
    if(this!=NULL && punteroSet != NULL )//validar parametros
    {
        retorno = 0;//validaron los parametros
        if(
            getValidInt(mensaje,"Error! reintente nuevamente",&auxInput,min,max,3)==0 &&
            punteroSet(this,auxInput) == 0
        )
        {
          retorno = 1;
        }

    }
    return retorno;
}


int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this!=NULL && id >= 0)
    {
        retorno = 0;
        this->id = id;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this!=NULL && id != NULL)
    {
        retorno = 0;
       *id = this->id  ;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre != NULL)
    {
        retorno = 0;
        strncpy(this->nombre,nombre,40);
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre != NULL)
    {
        retorno = 0;
        strncpy(nombre,this->nombre,40);
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this!=NULL && horasTrabajadas >= 0)
    {
        retorno = 0;
        this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this!=NULL && horasTrabajadas != NULL)
    {
        retorno = 0;
       *horasTrabajadas = this->horasTrabajadas  ;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this!=NULL && sueldo >= 0)
    {
        retorno = 0;
        this->sueldo = sueldo;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this!=NULL && sueldo != NULL)
    {
        retorno = 0;
       *sueldo = this->sueldo  ;
    }
    return retorno;
}

int employee_CompareByName(Employee* e1, Employee* e2)
{
    char name1[1024],name2[1024];
    employee_getNombre(e1,name1);
    employee_getNombre(e2,name2);

    return strcmp(name1,name2);
}
int employee_CompareById(Employee* e1, Employee* e2)
{

    int id1,id2,comparacion,retorno;
    employee_getId(e1,&id1);
    employee_getId(e2,&id2);
    comparacion = id1 - id2;
    if(comparacion > 0)
    {
        retorno = 1;
    }else
     {
         if(comparacion < 0)
         {
             retorno = -1;
         }else
          {
              retorno = 0;
          }
     }

    return retorno;
}

int employee_PrintOnConsole(Employee* this)
{
    int retorno = -1 ;/* retorno de la funcion*/
    if(this != NULL){

        int auxId,auxSueldo,auxHorasTrabajadas;
        char auxNombre[50];

        employee_getId(this,&auxId);
        employee_getNombre(this,auxNombre);
        employee_getSueldo(this,&auxSueldo);
        employee_getHorasTrabajadas(this,&auxHorasTrabajadas);
        printf("%10d %20s %10d %10d \n",auxId,auxNombre,auxSueldo,auxHorasTrabajadas);


    }
return retorno;
}
