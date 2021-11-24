#include "Editorial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eEditorial* editorial_new(){
	eEditorial* nuevaEditorial;
	nuevaEditorial = (eEditorial*)malloc(sizeof(eEditorial));
	return nuevaEditorial;
}

eEditorial* editorial_newParametros(char* idEditorialStr,char* nombreStr){
	int idEditorialAux;
	eEditorial* editorial = editorial_new();
	idEditorialAux = atoi(idEditorialStr);
	if(editorial != NULL && idEditorialStr != NULL && nombreStr != NULL){
		editorial_setId(editorial, idEditorialAux);
		editorial_setNombre(editorial, nombreStr);
	}
	return editorial;
}

void editorial_delete(eEditorial* this){
	if(this != NULL){
		free(this);
	}
}

int editorial_setId(eEditorial* this,int id){
	int retorno = -1;
	if(this != NULL){
		if(id >= 0){
			this -> idEditorial = id;
			retorno = 0;
		}
	}
	return retorno;
}

int editorial_getId(eEditorial* this,int* id){
	int retorno = -1;
	if(this != NULL && id != NULL){
		*id = this -> idEditorial;
		retorno = 0;
	}
	return retorno;
}

int editorial_getEditorialNameById(LinkedList* pArrayEditorial, int id, char* editorialName){
	eEditorial* pEditorial;
	int retorno = -1;

	for(int i = 0; i< ll_len(pArrayEditorial); i++){
		pEditorial = ll_get(pArrayEditorial, i);

		if(pEditorial ->idEditorial == id){
			strcpy(editorialName, pEditorial ->nombre);
			retorno = 0;
		}
	}
	return retorno;
}

int editorial_setNombre(eEditorial* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		strcpy(this -> nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int editorial_getNombre(eEditorial* this,char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this -> nombre);
		retorno = 0;
	}

	return retorno;
}
