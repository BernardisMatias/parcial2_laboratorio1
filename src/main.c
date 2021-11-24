#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libros.h"
#include "controller.h"
#include "editorial.h"
#include "LinkedList.h"
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int cargoLibros = 0;
	int cargoEditoriales = 0;
	char fileName[255];
	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();
	do{
		printf("\n -- SISTEMA DE REGISTRO DE LIBROS --");
		printf("\n 1. Cargar datos de LIBROS desde archivo .csv");
		printf("\n 2. Cargar datos de EDITORIALES desde archivo .csv");
		printf("\n 3. Ordenar lista de LIBROS por AUTOR");
		printf("\n 4. Imprimir lista de LIBROS");
		printf("\n 5. Mostrar Libros con editorial MINOTAURO");
		printf("\n 6. Salir\n");
		GetEntero(&opcion, "Ingrese una opcion: ", 1, 6, 20);
		switch(opcion){
			case 1:
				if(GetString(fileName, "Ingrese el nombre del archivo .csv: ", "Error. Libro invalido.", 255, 5) == 0){
					if(controller_loadBooksFromFile(listaLibros, fileName) == 0){
						cargoLibros = 1;
						printf("\nLista de LIBROS cargada con exito.");
					}
				} else {
					printf("\nError cargando LIBROS.");
				}
			break;
			case 2:
				if(GetString(fileName, "Ingrese el nombre del archivo .csv: ", "Error. Editorial invalida.", 255, 5) == 0){
					if(controller_loadEditorialsFromFile(listaEditoriales, fileName) == 0){
						cargoEditoriales = 1;
						printf("\nLista de EDITORIALES cargada con exito.");
					}
				} else {
					printf("\nError cargando EDITORIALES.");
				}
			break;
			case 3:
				if(cargoLibros == 1){
					if(controller_sortBooks(listaLibros, listaEditoriales)==0){
						printf("\nLista ordenada con exito.");
					}else{
						printf("\nError ordenando la lista.");
					}
				}else{
					printf("\nError. Debe cargar archivo libros antes de ordenar.");
				}
			break;
			case 4:
				if(cargoLibros == 1){
						if(cargoEditoriales == 1){
							if(controller_ListBooks(listaLibros, listaEditoriales) != 0){
								printf("\nError ordenando lista de libros.");
							}
						}else{
							printf("\nError. Debe cargar archivo editoriales para listar.");
						}
				}else{
					printf("\nError. Debe cargar archivo libros para listar.");
				}
			break;
			case 5:
				if(controller_listBooksFromEditorialMinotauro(listaLibros, listaEditoriales)!=0){
					printf("\nOcurrio un error al filtrar por editorial MINOTAURO.");
				}
			break;
			default:
				printf("\nError. Opcion ingresada invalida");
				break;
		}

	}while(opcion != 6 && opcion != -1);
}