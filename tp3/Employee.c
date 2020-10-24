#include <stdlib.h>
#include "Employee.h"
#include <string.h>


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
        strncpy(this->nombre,nombre,strlen(this->nombre));
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre != NULL)
    {
        retorno = 0;
        strncpy(nombre,this->nombre,strlen(nombre));
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
