#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#define TRUE 1
#define FALSE 0
#define lenght 999//len of the eEmployee list aray



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

int emp_initEmployees(eEmployee* employeelist, int len);
int emp_addEmployee(eEmployee employeelist[], int len);
int getFirstEmptyIndex(eEmployee* employeelist, int len,int* emptyIndex);
int emp_SetId(eEmployee* empleado,int id,int index);
int findEmployeeById(eEmployee* list, int len,int id);
int removeEmployee(eEmployee* list, int len, int id);
int sortEmployees(eEmployee lista[], int len, int order);
int printEmployees(eEmployee* list, int len);
int modificarEmployee(eEmployee list[], int len, int id);
void intercambiarLugaesEempleados(eEmployee* lista,int empleadoA,int empleadoB );
void hardcodearEmpleados(eEmployee lista[],int len);
int promedioSueldos(eEmployee lista[],int len);

#endif // EMPLOYEE_H_INCLUDED


