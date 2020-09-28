#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

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

int printEmployees(eEmployee* list, int length);

int findEmployeeById(eEmployee* list, int len,int id);

#endif // EMPLOYEE_H_INCLUDED

