#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"
#include "Editorial.h"

/** \brief Parsea datos los LIBRO archivo data.csv
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListBook)
{
	eLibro* aux;
	char id[128];
	char titulo[128];
	char autor[128];
	char precio[128];
	char idEditorial[128];
	int result = -1;
	if(pFile != NULL && pArrayListBook != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio,idEditorial);
		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio,idEditorial);
			aux = libro_newParametros(id, titulo, autor, precio, idEditorial);
			if(aux != NULL){
				result = ll_add(pArrayListBook, aux);
			}
		}
	}
    return result;
}

/** \brief Parsea datos los EDITORIAL archivo data.csv
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial){
	eEditorial* aux;
	char id[255];
	char nombre[255];
	int result = -1;
	if(pArrayListEditorial != NULL && pFile != NULL){
		fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);
		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);
			aux = editorial_newParametros(id, nombre);
			if(aux != NULL){
				ll_add(pArrayListEditorial, aux);
				result = 0;
			}
		}
	}
    return result;
}


int parser_leerIdLibro(FILE* pFile)
{
	char idBook[128];
	int retorno = -1;
	if(pFile != NULL){
		fscanf(pFile, "%[^\n]\n", idBook);
		while(!feof(pFile)){
			fscanf(pFile, "%[^\n]\n", idBook);
			retorno = atoi(idBook);
		}
	}
    return retorno;
}


void parser_saveNewList(LinkedList* pListaLibros, LinkedList* pArrayListEditorial){
	FILE* pFile;
	eLibro* aux;
	 int idLibro;
	char autor[255];
	char titulo[255];
	float precio;
	int idEditorial;
	char editorial[128];
	pFile = fopen("lista_actualizada.csv", "w");
	if(pFile != NULL){
		for(int i=0;i<ll_len(pListaLibros);i++){
			aux = ll_get(pListaLibros, i);
			if(ll_get(pListaLibros, i) != NULL){
				libro_getId(aux, &idLibro);
				libro_getTitulo(aux, titulo);
				libro_getAutor(aux, autor);
				libro_getPrecio(aux, &precio);
				libro_getIdEditorial(aux, &idEditorial);
				editorial_getEditorialNameById(pArrayListEditorial, idEditorial, editorial);
				fprintf(pFile, "%d, %s, %s, %f, %s\n", idLibro, titulo, autor, precio, editorial);
			}
		}

	}
	fclose(pFile);
}


int parser_OneEditorialFromText(FILE* pFile)
{
	char idEditorial[128];
	int retorno = -1;

	if(pFile != NULL){
		fscanf(pFile, "%[^\n]\n", idEditorial);
		while(!feof(pFile)){
			fscanf(pFile, "%[^\n]\n", idEditorial);
			retorno = atoi(idEditorial);
		}
	}

    return retorno;
}
