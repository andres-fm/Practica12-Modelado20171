//para poder hacer uso de la funcion printf
#include <stdio.h>

int main(){
	//declaro una variable de tipo char
	char ch;
	//declaro una variable de tipo short
	short sh;
	//declaro una variable de tipo unsigned int
	unsigned int ui;
	//declaro una variable de tipo apuntador a int
	int * ap_int;
	//declaro una variable de tipo int
	int i;
	//declaro una variable de tipo float
	float f;
	//declaro una variable de tipo double
	double d;

	//utilizo la funcion sizeof para obtener la cantidad de memoria que utiliza el tip int
	printf("El tipo int tiene tamaño %lu \n", sizeof(i));
	//utilizo la funcion sizeof para obtener la cantidad de memoria que utiliza el tipo char
	printf("El tipo char tiene tamaño %lu \n", sizeof(ch));
	//utilizo la funcion sizeof para obtener la cantidad de memoria que utiliza el tipo short
	printf("El tipo short tiene tamaño %lu \n", sizeof(sh));
	//utilizo la funcion sizeof para obtener la cantidad de memoria que utiliza el tipo unsigned int
	printf("El tipo unsigned int tiene tamaño %lu \n", sizeof(ui));
	//utilizo la funcion sizeof para obtener la cantidad de memoria que utiliza el tipo apuntador a int
	printf("El tipo apuntador a int tiene tamaño %lu \n", sizeof(ap_int));
	//utilizo la funcion sizeof para obtener la cantidad de memoria que utiliza el tipo float
	printf("El tipo float tiene tamaño %lu \n", sizeof(f));
	//utilizo la funcion sizeof para obtener la cantidad de memoria que utiliza el tipo double
	printf("El tipo double tiene tamaño %lu \n", sizeof(d));
	
	return 0;

}