#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "display.h"
#include "utn.h"



/** \brief realiza la carga de texto desde el archivo "data.csv"
 *
 * \param path char* la direccion de directorio del archivo
 * \param pArrayListEmployee LinkedList* es la lista donde se guardara toda la
 informacion leida en el archivo
 * \return int int -1 parametros invalidos, 1 parametros validados, 0 funciono todo correctamente
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief realiza la carga de los empleados guardados en forma de texto desde el archivo "data.bin"
 *
 * \param path char* la direccion de directorio del archivo
 * \param pArrayListEmployee LinkedList* es la lista donde se guardara toda la
 informacion leida en el archivo
 * \return int int -1 parametros invalidos, 1 parametros validados, 0 funciono todo correctamente
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief añade un empleado a la linked list,
pidiendo el ingreso de todos los miembros de la estructura por consola
 *
 * \param pArrayListEmployee LinkedList*  es la lista donde se guardara el nuevo empleado
 * \return int  -1 parametros invalidos, 1 parametros validados, 0 funciono todo correctamente
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief permite la modificacion de los miembros de un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * * \return int -1 parametros invalidos, 1 parametros validados, 0 funciono todo correctamente
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief imprime una lista de todos los empleados a los que apunta LinkedList
 *
 * \param pArrayListEmployee LinkedList* el puntero a la lList de empleados
 * \return int retornara -1 caso sean invalidos las parametros actuales,
 sera 0 caso la funcion valide completamente, y >0 si haya fracasado alguna funcion interna
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief imprime un listado de todos los empleados que esten en una linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \param employee_CompareBy
 * \return int -1 parametros invalidos, 1 parametros validados, 0 funciono todo correctamente
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee,employee_CompareBy);


/** \brief
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief
 *
 * \param list LinkedList*
 * \return int
 *
 */
int controler_vaciarLinkedList(LinkedList* list);



#endif // CONTROLLER_H_INCLUDED
