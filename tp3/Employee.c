#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include "utn.h"
#include <stdio.h>
#include "display.h"
#include "LinkedList.h"
#include <ctype.h>


///@brief crea un nuevo eempleado en heap y devuelve su &mdir. Siendo todos los miembros, valores por defecto .
Employee* employee_new()
{
    Employee* auxEmployee = NULL;

    auxEmployee = (Employee*) malloc(sizeof(Employee));

    return auxEmployee;
}

///@brief crea un nuevo eempleado en heap y devuelve su &mdir ,
///al mismo tiempo asignandole valores a cada miembro
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* auxEmployee = NULL;
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        if((auxEmployee = employee_new())!= NULL)
        {
            if(auxEmployee!=NULL)
            {
                if
                (
                    employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr)) != 0 ||
                    employee_setId(auxEmployee,atoi(idStr)) != 0 ||
                    employee_setNombre(auxEmployee,nombreStr) != 0 ||
                    employee_setSueldo(auxEmployee,atoi(sueldoStr)) != 0
                )
                {

                     free(auxEmployee);
                     auxEmployee = NULL;
                }
            }
        }
    }
    return auxEmployee;
}

int employee_delete(Employee* this){

int retorno=-1;
 if(this != NULL)
 {
     free(this);
     retorno = 0;
 }
 return retorno;
}


int employee_ingresarString(char mensaje[],Employee* this,employee_setString punteroSet)
{
    int retorno = -1;
    if(this!=NULL && punteroSet != NULL )
    {
        char auxInput[1024];
        retorno = 0;
        if
        (
            getValidString(mensaje,"Error! reintente nuevamente",
                           "Error! limite de caracteres superado",auxInput,40,3)==0 &&
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
    if(this!=NULL && punteroSet != NULL )
    {
        int auxInput;
        retorno = 0;
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
        employee_nombreAformatoCorrecto(nombre);
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
    int id1,id2,retorno;
    employee_getId(e2,&id2);
    employee_getId(e1,&id1);
        if(id1 < id2)
        {
            retorno = -1;
        }else
         {
            retorno = 1 ;
         }
    return retorno;
}



int getMaxIdFromBIN(char patch[] , int *maxId)
{
    int retorno = -1;
    FILE* pfile;
        if((pfile = fopen(patch,"rb")) != NULL)
        {
            if(fread(maxId,sizeof(int),1,pfile) == 1)
            {
                retorno = 0;
            }
        }
        fclose(pfile);
    return retorno;
}

int saveMaxIdtoBin(char patch[] , int maxId)
{
    int retorno = -1;
    FILE* pfile;
        if((pfile = fopen(patch,"wb")) != NULL)
        {
            if(fwrite(&maxId,sizeof(int),1,pfile) != 1)
            {
                retorno = 2;
            }
        }
      fclose(pfile);
    return retorno;
}




int employee_setNewId(Employee* this,int id)
{

    int retorno = -1 ;
    int maxId = 0;
    if(this!=NULL)
    {
        pause();
        FILE* pfile;
       if( getMaxIdFromBIN("maxID.bin", &maxId) == 0)
       {
            retorno = 1;
            if(id<=maxId)
            {
                maxId++;
                employee_setId(this,maxId);
                retorno = 0;

            }else{
                maxId = id;
                employee_setId(this,maxId);
                retorno = 0;
            }
        }
        saveMaxIdtoBin("maxID.bin" , maxId);
        /*
        if((pfile = fopen("maxID.bin","wb")) != NULL)
        {
            if(fwrite(&maxId,sizeof(int),1,pfile) != 1)
            {
                printf("no guardo");
                retorno = 2;
            }

        }


      fclose(pfile);


      */
    }

return retorno;
}




Employee* employee_getById(LinkedList* pListaDeEmpleados,int id)
{
    Employee* retorno = NULL;

    if(pListaDeEmpleados != NULL && id >= 0)
    {
        int i,len,idActual;
        len = ll_len(pListaDeEmpleados);
        for(i=0;i<len;i++)
        {
           if(( retorno = (Employee*)ll_get(pListaDeEmpleados,i)) != NULL)
           {
                employee_getId(retorno,&idActual);
                if(idActual == id)
                {
                    break;
                }
            }
            retorno = NULL;
        }
    }
    return retorno;
}

int employee_getIndexById(LinkedList* pListaDeEmpleados,int id)
{

    int retorno = -1;
    if(pListaDeEmpleados!=NULL)
    {
        Employee* auxEmployee;
        int i,len,idActual;
        len = ll_len(pListaDeEmpleados);

        for(i=0;i<len;i++)
        {
            if((auxEmployee = (Employee*)ll_get(pListaDeEmpleados,i)) != NULL)
            {
                if( employee_getId(auxEmployee,&idActual) == 0)
                {
                    if(idActual == id)
                    {
                        retorno = i;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}



int employee_imprimirUnaTablaDe1(Employee* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        employee_imprimirLaCabezeraDeLista();
        display_PrintEmployeeOnConsole(this);
        display_imprimirElFinalDeTabla();
    }
return retorno;
}


int Employee_swapContents(Employee* element1,Employee* element2)
{
    int retorno= -1 ;
    if(element2 != NULL && element1 != NULL)
    {
        retorno = 0;
        Employee aux;
        aux = *element1;
        *element1 = *element2 ;
        *element2 = aux;
    }
return retorno;
}



int employee_nombreAformatoCorrecto(char* this)
{
    if(this != NULL)
    {
        int i;
        for(i=0; *(this+i) != '\0';i++)
        {
            if(i == 0)/* la primer letra la transformo en mayuscula */
            {
               *this = toupper(*this);
            }else
             {
                *(this+i) = tolower(*(this+i));/* en el caso contrario la transformo en minuscula*/
             }


            if( *(this + i) != ' ' && (*(this + i) <'a' || *(this + i) > 'z') && (*(this + i) <'A' || *(this + i) > 'Z'))
            {
                *(this+i) = ' ';/* si hay un caracter raro lo transformo en espacio*/
            }

            if( *(this+i-1) == ' ')
            {
                *(this+i) =toupper(*(this+i)); /* si antes hay un espacio lo transformo en mayuscula */
            }
        }
    }
return 0;
}
