#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

/*estos dos typedef representan a los setters  */
typedef int (*employee_setString)(Employee*,char*);
typedef int (*employee_setInt)(Employee*,int);
/*y este a la comparacion de nombre y id */
typedef int (*employee_CompareBy)(Employee*, Employee*);


/** \brief
 *
 * \param mensaje[] char un mensaje que se muestra en
  pantalla antes de pedir el ingreso de un int
 * \param max int el limite maximo por el cual validar el valor ingresado
 * \param min int el limite maximo por el cual validar el valor ingresado
 * \param this Employee* es el puntero al empleado donde se prodiciran los cambios
 * \param punteroSet employee_setInt es el puntero a un setter cualesquiera que permita
  modificar un miembro de la funcion que sea un entero
 * \return int retorna -1 no validaron los parametros, 0 validaron los parametros, 1 todo funciono correctamente.
 *
 */
int employee_ingresarInt(char mensaje[],int max,int min,Employee* this,employee_setInt punteroSet);

/** \brief
 *
 * \param mensaje[] char
 * \param this Employee*
 * \param punteroSet employee_setString
 * \return int
 *
 */
int employee_ingresarString(char mensaje[],Employee* this,employee_setString punteroSet);

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);


int employee_setNewId(Employee* this,int id);

Employee* employee_getById(LinkedList* pListaDeEmpleados,int id);
int employee_getIndexById(LinkedList* pListaDeEmpleados,int id);

#endif // employee_H_INCLUDED
