#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED



#define TRUE 1
#define FALSE 0

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef eEmployee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int emp_initEmployees(eEmployee* employeelist, int len);


/*2.2 Función addEmployees
Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre.*/

/*sin el uso de punteros esta funcion es imposible, ya que no puedo usarla solo para asignar los valores
cual creo que seria su funcion ideal. por lo tanto tengo que hacer toda la logica adentro de la misma.
*/
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee[] it's the array of the eEmplyee structure
* \param len int the lenght of the eEmployee Array
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 4
Programación I – Laboratorio I

*/
int emp_addEmployee(eEmployee employeelist[], int len);


/** \brief searches for a isEmpty with a true value and returns its index number
* \param list employee[] it's the array of the eEmplyee structure
* \param len int the lenght of the eEmployee Array
* \param *emptyIndex its the pointer to where the empty index value will be stored
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int getFirstEmptyIndex(eEmployee* employeelist, int len,int* emptyIndex);

//2.6 Función printEmployees
//Imprime el array de empleados de forma encolumnada.
/** \brief print the content of employees array
*
* \param list Employee* the pointer to the eEmployee array that will be printed in console
* \param length int lenght of the array
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printEmployees(eEmployee* list, int length);


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
int findEmployeeById(eEmployee* list, int len,int id);


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
int removeEmployee(eEmployee* list, int len, int id);



int emp_SetId(eEmployee* empleado,int id,int index);

int modificarEmployee(eEmployee list[], int len, int id);


#endif // EMPLOYEE_H_INCLUDED


