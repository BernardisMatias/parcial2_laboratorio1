#include "LinkedList.h"
#ifndef editorial_H_INCLUDED
#define editorial_H_INCLUDED

typedef struct
{
    int idEditorial;
    char nombre[128];

}eEditorial;

//Reserva y asigna un espacio en memoria para el nuevo empleado generado
eEditorial* editorial_new();

//Carga los datos en el espacio asignado por editorial_new
eEditorial* editorial_newParametros(char* idEditorialStr,char* nombreStr);

//Libera la memoria reservada para el empleado
void editorial_delete(eEditorial* this);

int editorial_setId(eEditorial* this,int id);

//Obtiene el id del empleado desde su atributo ID
int editorial_getId(eEditorial* this,int* id);

int editorial_getEditorialNameById(LinkedList* pArrayEditorial, int id, char* editorialName);

//Obtiene el nombre del empleado desde su atributo Nombre
int editorial_getNombre(eEditorial* this,char* nombre);

int editorial_setNombre(eEditorial* this,char* nombre);

#endif // editorial_H_INCLUDED
