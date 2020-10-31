#ifndef MENUOPTIONS_H_INCLUDED
#define MENUOPTIONS_H_INCLUDED

#include <stdio.h>
#include "Controller.h"
#include "Employee.h"
#include "utn.h"


int opcion_cargarEmpleadosDesdeCsv(char path[], LinkedList* list);
int opcion_cargarEmpleadosDesdeBin(char path[] , LinkedList* list);

int opcion_darDeAltaAEmpleado(LinkedList* list);
int opcion_editarEmpleado(LinkedList* list);
int opcion_darDeBajaEmpleado(LinkedList* list);

int opcion_listarEmpleados(LinkedList* list);
int opcion_ordenarEmpleados(LinkedList* list);

int opcion_save(char path[],LinkedList* list,controller_saveAs pSaveAs );
int opcion_vaciarLinkedlist(LinkedList* list);












#endif // MENUOPTIONS_H_INCLUDED
