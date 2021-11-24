#include "LinkedList.h"
#ifndef libros_H_INCLUDED
#define libros_H_INCLUDED

typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    float precio;
    int idEditorial;
}eLibro;

eLibro* libro_new();
eLibro* libro_newParametros(char* idStr,char* titulo,char* autor, char* precio, char* idEditorial);

void libro_delete(eLibro* this);
int libro_setId(eLibro* this,int id);
int libro_setIdEditorial(eLibro* this,int idEditorial);
int libro_getId(eLibro* this,int* id);
int libro_getIdEditorial(eLibro* this, int* idEditorial);
int libro_setAutor(eLibro* this,char* autor);
int libro_getAutor(eLibro* this,char* autor);
int libro_setTitulo(eLibro* this,char* titulo);
int libro_getTitulo(eLibro* this,char* titulo);
int libro_setPrecio(eLibro* this,float precio);
int libro_getPrecio(eLibro* this,float* precio);
int libro_sortList(LinkedList* pArrayBook, LinkedList* pArrayEditorial);
int libro_sortByAutor(void* firstBook, void* secondBook);
int libro_checkAddElementToArray(void* auxElement);
#endif
