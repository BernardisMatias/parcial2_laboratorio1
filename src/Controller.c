#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libros.h"
#include "Editorial.h"
#include "funciones.h"
#include "parser.h"

/** \brief Carga libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_loadLibrosFromText(char* path , LinkedList* pArrayListBook){
	FILE* fileAux;
	int result = -1;
	fileAux = fopen(path, "r");
	if(fileAux != NULL){
		result = parser_LibroFromText(fileAux, pArrayListBook);
	} else{
		printf("\nError abriendo el archivo");
	}
	fclose(fileAux);
    return result;
}

/** \brief Carga editoriales desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_loadEditorialsFromText(char* path , LinkedList* pArrayListEditorial){
	FILE* fileAux;
	int result = -1;
	fileAux = fopen(path, "r");
	if(fileAux != NULL){
		result = parser_EditorialFromText(fileAux, pArrayListEditorial);
	} else {
		printf("\nError abriendo");
	}
	fclose(fileAux);
    return result;
}


int controller_loadLibrosFromFile(LinkedList* pArrayListBook ,char* fileName){
	int result = -1;
	ll_clear(pArrayListBook);
	char fullFileName[] = "src/";
	char extension[] = ".csv";
	strcat(fullFileName, fileName);
	strcat(fullFileName, extension);
	if(controller_loadLibrosFromText(fullFileName, pArrayListBook) == 0){
		result = 0;
	}
	return result;
}

int controller_loadEditorialsFromFile(LinkedList* listaEditoriales, char* fileName)
{
	int result = -1;
	char fullFileName[] = "src/";
	char extension[] = ".csv";
	strcat(fullFileName, fileName);
	strcat(fullFileName, extension);
	ll_clear(listaEditoriales);
	if(controller_loadEditorialsFromText("src/lista_editoriales.csv", listaEditoriales) == 0){
		result = 0;
	}
	return result;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_addLibro(LinkedList* pArrayListBook)
{
	eLibro* aux;
	int retorno = -1;
	int id;
	char titulo[255];
	char autor[255];
	float precio;
	int idEditorial;

	aux = libro_new();
	id = controller_obtenerLibroId(pArrayListBook);

	if(pArrayListBook != NULL){
		GetString(titulo, "Ingrese el titulo del libro: ", "Error. Titulo invalido. Reingrese", 255, 5);
		GetString(autor, "Ingrese nombre del autor: ", "Error. Nombre de autor invalido. Reingrese", 255, 5);
		GetFlotante(&precio, "Ingrese el precio del libro", 50, 100000, 5);
		GetEntero(&idEditorial, "Ingrese la editorial del libro", 1, 20, 5);
		if(aux != NULL){
			id++;
			libro_setTitulo(aux, titulo);
			libro_setAutor(aux, autor);
			libro_setPrecio(aux, precio);
			libro_setId(aux, id);
			libro_setIdEditorial(aux, idEditorial);
			ll_add(pArrayListBook, aux);
			controller_saveLastBookAsText("libro_lastId.csv", id);
			retorno = 0;
		}
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_listLibros(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial){
	eLibro* aux;
    int retorno = -1;
    int idLibro;
    char autor[255];
    char titulo[255];
    float precio;
    int idEditorial;
    char editorial[128];
    if(pArrayListBook != NULL){
        puts("ID\t\t\t\tTITULO\t\t\t\tAUTOR\t\tPRECIO\t\t\tEDITORIAL");
        retorno = 0;
        for(int i = 0; i< ll_len(pArrayListBook); i++){
        	aux = ll_get(pArrayListBook, i);
        	if(aux != NULL){
            	libro_getId(aux, &idLibro);
            	libro_getTitulo(aux, titulo);
            	libro_getAutor(aux, autor);
            	libro_getPrecio(aux, &precio);
            	libro_getIdEditorial(aux, &idEditorial);
            	editorial_getEditorialNameById(pArrayListEditorial, idEditorial, editorial);

            	printf("%2d %35s %30s %15.2f$ %26s\n", idLibro, titulo, autor, precio, editorial);
        	}

        }
    }

    return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_sortBooks(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial)
{
    int retorno = -1;

    if(pArrayListBook != NULL){
    	retorno = libro_sortList(pArrayListBook, pArrayListEditorial);
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_saveBookAsText(char* path , LinkedList* pArrayListBook)
{
    FILE* pFile;
    eLibro* aux;
    int retorno = -1;
    int i;
    int id;
    char titulo[255];
    char autor[255];
    float precio;
    int idEditorial;

    if(pArrayListBook != NULL && path != NULL && ll_isEmpty(pArrayListBook) == 0){
    	retorno = 0;
        pFile = fopen(path,"w");
        fprintf(pFile,"idLibro,titulo,autor,precio,idEditorial\n");
        for(i=0; i< ll_len(pArrayListBook);i++){
        	aux = (eLibro*) ll_get(pArrayListBook, i);

        	libro_getId(aux, &id);
        	libro_getTitulo(aux, titulo);
        	libro_getAutor(aux, autor);
        	libro_getPrecio(aux, &precio);
        	libro_getIdEditorial(aux, &idEditorial);

        	fprintf(pFile,"%d,%s,%s,%f,%d\n",id,titulo,autor,precio,idEditorial);
        }
    	fclose(pFile);
    	if(ll_len(pArrayListBook) == i ){
    	  retorno = 0;
    	}
    }
    return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
int controller_loadLastBookIdFromText(char* path){
	FILE* pFile;
	int retorno = -1;
	pFile = fopen(path, "r");
	if(pFile != NULL){
		retorno = parser_leerIdLibro(pFile);
	}
	fclose(pFile);
    return retorno;
}

int controller_saveLastBookAsText(char* path, int id){
	FILE* pFile;
	int retorno = -1;

	   if(path != NULL){
	    	retorno = 0;
	        pFile = fopen(path,"w");

				fprintf(pFile,"idLastBook\n");
				fprintf(pFile,"%d\n",id);

	    	fclose(pFile);

	    }
	return retorno;
}

int controller_obtenerLibroId(LinkedList* pArrayListBook){
	eLibro* book;
	int idLibro;
	int idMax = -1;
	int flagFirstBook = 1;
	int foundedId;
	if(pArrayListBook != NULL){
		if(ll_len(pArrayListBook) > 0){
			for(int i = 0; i < ll_len(pArrayListBook);i++){
				book = (eLibro*) ll_get(pArrayListBook, i);
				if(book != NULL){
					libro_getId(book, &idLibro);

					if(flagFirstBook == 1 || idLibro > idMax){
						idMax = idLibro;
						flagFirstBook = 0;
					}
				}
			}
		}
	}
	foundedId = controller_loadLastBookIdFromText("ultimoIdLibros.csv");

	if(idMax < foundedId){
		idMax = foundedId;
	}
	return idMax;
}

int controller_listarLibrosMinotauro(LinkedList* listaLibros, LinkedList* pArrayEditorial){

	int result = -1;
	LinkedList* listaAux;

	listaAux = ll_newLinkedList();
	listaAux = ll_filter(listaLibros, libro_elementIsMinotauro);
	if(listaAux != NULL){
		result = controller_listLibros(listaAux, pArrayEditorial);
	}
	return result;
}

int controller_aplicarDescuento(LinkedList* listaLibros, LinkedList* pArrayEditorial){
	int result = -1;
	LinkedList* listaAux;
	listaAux = ll_newLinkedList();
	listaAux = ll_map(listaLibros, libro_elementIsPlanetaOrXXI);

	if(listaAux != NULL){
		result = controller_listLibros(listaAux, pArrayEditorial);
		parser_saveNewList(listaLibros, pArrayEditorial);
	}
	return result;
}
