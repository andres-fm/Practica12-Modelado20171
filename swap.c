//para poder utilizar la funcion print
#include <stdio.h>
//para generar numeros pseudoaleatorios con srand y rand para probar swap
#include <stdlib.h>
//para poder crear la semilla usando la funcion time (necesaria para los numeros aleatorios)
#include <time.h>

//funcion que intercambia el valor de dos enteros
//recibe un apuntador de tipo entero del primer entero, y otro del segundo entero (pass by pointer)
void swap(int* a, int* b){
	//guardo el valor del lugar al que esta apuntando el apuntador a para despues hacer el intercambio
	int auxiliar = *a;
	//a la direccion de memoria al que apunta a le asigno el valor de b
	*a = *b;
	//a la direccion de memoria a la que apunta b le asigno el valor del auxiliar, que es el valor original de a
	*b = auxiliar;
}

int test_swap(){
	srand(time(NULL));
	//el numero aleatorio de veces que se probara el correcto funcionamiento de swap
	//(hago modulo 100 para que este entre 0 y 99) y sumo 5 para que al menos haga 5 pruebas
	int num_pruebas = (rand() % 100) + 5;
	while(num_pruebas--){
		//asigno un valor aleatorio a la variable a
		int a = rand() % 100;
		//asigno un valor aleatorio a la variable b
		int b = rand() % 100;
		//para poder comparar y ver si swap fue correcto
		int a_original = a;
		int b_original = b;
		//imprimo valores de a y b antes de hacer swap
		printf("Antes de hacer swap: valor de a es %d, valor de b es %d \n",a,b);
		//llamo a la funcion swap con la direccion de memoria de a y b
		swap(&a, &b);
		//imprimo los nuevos valores de a y b
		printf("Despues de hacer swap: valor de a es %d, valor de b es %d \n\n",a,b);
		//si los valores no se intercambiaron correctamente entonces swap es incorrecto
		if (b != a_original || a != b_original){
			return 0;
		}
	}
	//si se llega a este punto ent swap funciono correctamente
	return 1;
}

int main(){
	printf((test_swap()) ? "Jala chido\n" : "No funciona :(\n");
	return 0;
}