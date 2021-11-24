#include "funciones.h"

float GetFlotante(float* destino, char mensaje[], float menor, float mayor, int reintentos){
	int result = -1;
	float aux;
	do{
		printf("%s", mensaje);
		scanf("%f", &aux);
		if(aux > mayor || aux < menor){
			printf("\nNumero invalido. Por favor ingrese un numero entre %.2f y %.2f", menor, mayor);
		} else {
			*destino = aux;
			result = 0;
			break;
		}
		reintentos--;
	} while(reintentos >= 0);
	return result;
}
int GetEntero(int* destino, char mensaje[], int menor, int mayor, int reintentos){
	int result = -1;
	int aux;
	do{
		fflush(stdin);
		printf("%s", mensaje);
		scanf("%d", &aux);
		if(aux > mayor || aux < menor){
			printf("\nNumero invalido. Por favor ingrese un numero entre %d y %d\n", menor, mayor);
		} else {
			*destino = aux;
			result = 0;
			break;
		}
		reintentos--;
	} while(reintentos >= 0);
	return result;
}

int GetCuit(char* cuitObjetivo, char mensaje[], int reintentos){
	int result = -1;
	char cuitAux[15];
	do{
		fflush(stdin);
		printf("%s", mensaje);
		gets(cuitAux);
		if(ValidarCuit(cuitAux) == 0){
			FormatearCuit(cuitAux);
			result = 0;
			strcpy(cuitObjetivo, cuitAux);
			break;
		}
		reintentos--;
	} while(reintentos >= 0);
	return result;
}

void FormatearCuit(char cuit[]){
	char cuitAux[15];
	cuitAux[0] = cuit[0];
	cuitAux[1] = cuit[1];
	cuitAux[2] = '-';
	cuitAux[3] = cuit[2];
	cuitAux[4] = cuit[3];
	cuitAux[5] = cuit[4];
	cuitAux[6] = cuit[5];
	cuitAux[7] = cuit[6];
	cuitAux[8] = cuit[7];
	cuitAux[9] = cuit[8];
	cuitAux[10] = cuit[9];
	cuitAux[11] = '-';
	cuitAux[12] = cuit[10];
	strcpy(cuit, cuitAux);
}

int ValidarCuit(char* cuit){
	char inicioCuit[] = "30";
	int result = -1;
	if(StringContieneLetras(cuit) == 1){
		printf("\nCUIT invalido. Por favor ingrese CUIT solo numeros.\n");
	} else if(strlen(cuit) != 11){
		printf("\nCUIT invalido. Por favor ingrese un CUIT de 11 cifras.\n");
	} else {
		if(EmpiezaCon(inicioCuit, cuit) == 1){
			result = 0;
		} else {
			printf("\nCUIT invalido. Por favor ingrese un CUIT empezado en 30.\n");
		}
	}
	return result;
}

int GetString(char cadena[], char mensaje[], char mensajeError[], int tam, int reintentos){
	char aux[tam];
	int result = -1;
	if(cadena == NULL || mensaje == NULL || tam < 0 || reintentos < 0){
		printf("\nError. Debe ingresar todos los parametros de GetString.\n");
		return result;
	}
	do{
		printf("%s",mensaje);
		fflush(stdin);
		gets(aux);
		if(strlen(aux) > tam){
			printf("\nEl texto ingresado no puede tener mas de %d caracteres.\n", tam);
			break;
		} else if(EsSring(aux) != 0){
			printf("\n");
			puts(mensajeError);
			break;
		} else{
			fflush(stdin);
			strcpy(cadena, aux);
			result = 0;
			break;
		}
		reintentos--;
	} while(reintentos >= 0);
	return result;
}

int GetChar(char* caracter, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
	int result = -1;
	char entrada;
	if(caracter != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
			fflush(stdin);
			printf("\nLLEGA HASTA ACA 1");
			printf("%s",mensaje);
			scanf("%c", &entrada);
			printf("\nLLEGA HASTA ACA 2");
			if(entrada >= minimo && entrada <= maximo){
				*caracter = entrada;
				result = 0;
				printf("\nLLEGA HASTA ACA 3");
				break;
			}
			puts(mensajeError);
			reintentos--;
		} while(reintentos >= 0);
	}
	return result;
}

int GetCharDosOpciones(char* caracter, char* mensaje, char opc1, char opc2, char reintentos){
	int result = -1;
	char entrada;
	if(caracter != NULL && mensaje != NULL && reintentos > 0){
		do{
			printf("%s",mensaje);
			scanf("%c", &entrada);
			if(entrada == opc1 || entrada == opc2){
				*caracter = entrada;
				result = 0;
				break;
			}
			puts("Error, caracter invalido. Por favor reingrese: ");
			reintentos--;
		} while(reintentos >= 0);
	}
	return result;
}

int EmpiezaCon(char* prefijo, char* cadena){
	int result = 1;
	for(int i=0;i<strlen(prefijo);i++){
		if(cadena[i] != prefijo[i]){
			result = 0;
			break;
		}
	}
	return result;
}

int StringContieneNumeros(char cadena[]){
	int length,i;
	int result = 0;
	length = strlen(cadena);
	for (i=0;i<length; i++){
		if (isdigit(cadena[i])){
			result = 1;
			break;
		}
	}
	return result;
}

int StringContieneLetras(char cadena[]){
	int length,i;
	int result = 0;
	length = strlen(cadena);
	for (i=0;i<length; i++){
		if (!isdigit(cadena[i])){
			result = 1;
			break;
		}
	}
	return result;
}

int StringEsSoloNumeros(char cadena[]){
	return !StringContieneLetras(cadena);
}

int EsSring(char cadena[]){
	return atoi(cadena);
}

int AutoIncrementarId(int* id){
	*id = *id + 1;
	return *id;
}
/*int EsEntero(char cadena[]){
	return isdigit(cadena);
}*/

