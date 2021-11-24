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


int parser_OneBookFromText(FILE* pFile)
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
