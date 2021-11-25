#include "Libros.h"
#include "controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eLibro* libro_new(){
	eLibro* nuevoLibro;
	nuevoLibro = (eLibro*)malloc(sizeof(eLibro));
	return nuevoLibro;
}

eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* idEditorialStr){
	eLibro* nuevoLibro;
	nuevoLibro = libro_new();

	int idAux;
	float precioAux;
	int idEditorialAux;

	idAux = atoi(idStr);
	precioAux = atof(precioStr);
	idEditorialAux = atoi(idEditorialStr);

	if(nuevoLibro != NULL && idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL){
		libro_setId(nuevoLibro, idAux);
		libro_setTitulo(nuevoLibro, tituloStr);
		libro_setAutor(nuevoLibro, autorStr);
		libro_setPrecio(nuevoLibro, precioAux);
		libro_setIdEditorial(nuevoLibro, idEditorialAux);
	}

	return nuevoLibro;
}



void libro_delete(eLibro* this){
	if(this != NULL){
		free(this);
	}
}

int libro_setId(eLibro* this,int id){
	int retorno = -1;

	if(this != NULL){
		if(id >= 0){
			this -> id = id;
			retorno = 0;
		}
	}

	return retorno;
}


int libro_getId(eLibro* this, int* id){
	int retorno = -1;

	if(this != NULL && id != NULL){
		*id = this -> id;
		retorno = 0;
	}
	return retorno;
}


int libro_setIdEditorial(eLibro* this,int idEditorial){
	int retorno = -1;

	if(this != NULL){
		if(idEditorial >= 0){
			this -> idEditorial = idEditorial;
			retorno = 0;
		}
	}

	return retorno;
}

int libro_getIdEditorial(eLibro* this, int* idEditorial){
	int retorno = -1;

	if(this != NULL && idEditorial != NULL){
		*idEditorial = this -> idEditorial;
		retorno = 0;
	}
	return retorno;
}



int libro_setAutor(eLibro* this,char* autor){
	int retorno = -1;

	if(this != NULL && autor != NULL){
		strcpy(this -> autor, autor);
		retorno = 0;
	}
	return retorno;
}

int libro_getAutor(eLibro* this,char* autor){
	int retorno = -1;

	if(this != NULL && autor != NULL){
		strcpy(autor, this -> autor);
		retorno = 0;
	}

	return retorno;
}

int libro_setTitulo(eLibro* this,char* titulo){
	int retorno = -1;

	if(this != NULL && titulo != NULL){
		strcpy(this -> titulo, titulo);
		retorno = 0;
	}
	return retorno;
}

int libro_getTitulo(eLibro* this,char* titulo){
	int retorno = -1;

	if(this != NULL && titulo != NULL){
		strcpy(titulo, this -> titulo);
		retorno = 0;
	}

	return retorno;
}
int libro_setPrecio(eLibro* this,float precio){
	int retorno = -1;

	if(this != NULL){
		if(precio >= 0){
			this -> precio = precio;
			retorno = 0;
		}
	}

	return retorno;
}

int libro_getPrecio(eLibro* this,float* precio){
	int retorno = -1;

	if(this != NULL){
		if(precio >= 0){
			*precio = this -> precio;
			retorno = 0;
		}
	}

	return retorno;
}


int libro_sortList(LinkedList* pArrayBook, LinkedList* pArrayEditorial){
	int retorno = -1;
	if(pArrayBook != NULL){
		if(ll_sort(pArrayBook, libro_sortByAutor, 1)==0){
			if(controller_listLibros(pArrayBook, pArrayEditorial) == 0){
				printf("\nLista Ordenada con exito por AUTOR");
				retorno = 0;
			}
		}
	}
	return retorno;
}



int libro_sortByAutor(void* firstBook, void* secondBook){
	int result = 0;
	char autor1[50];
	char autor2[50];
	if(libro_getAutor(firstBook, autor1)==0
			&& libro_getAutor(secondBook, autor2)){
		if(strcmp(autor1,autor2) > 0){
			result = 1;
		}
		if(strcmp(autor1,autor2) < 0){
			result = -1;
		}
	}
	return result;
}

int libro_discountPlaneta(void* auxElement){
	int result = -1;
	eLibro* aux = auxElement;
	if(aux->idEditorial == 1){
		if(aux->precio >= 300){
			aux->precio = aux->precio*0.8;
			result = 0;
		}
	}
	return result;
}

int libro_discountXXI(void* auxElement){
	int result = -1;
	eLibro* aux = auxElement;
	if(aux->idEditorial == 2){
		if(aux->precio <= 200){
			aux->precio = aux->precio*0.9;
			result = 0;
		}
	}
	return result;
}

int libro_elementIsPlanetaOrXXI(void* auxElement){
	int result = -1;
	eLibro* aux = auxElement;
	if(aux->idEditorial == 1){
		libro_discountXXI(auxElement);
		result = 1;
	} else if(aux->idEditorial == 2){
		libro_discountPlaneta(auxElement);
		result = 2;
	}
	return result;
}

int libro_elementIsMinotauro(void* auxElement){
	int result = -1;
	eLibro* aux = auxElement;
	if(aux->idEditorial == 4){
		result = 0;
	}
	return result;
}
