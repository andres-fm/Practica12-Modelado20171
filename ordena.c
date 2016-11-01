//para utilizar la funcion print en el main
#include <stdio.h>
//para generar numeros pseudoaleatorios con srand y rand para probar bubblesort
#include <stdlib.h>
//para poder crear la semilla usando la funcion time (necesaria para los numeros aleatorios)
#include <time.h>

//ordena el arreglo al que apunta el apuntador 
//recibe un apuntador al arreglo y el tamaño del mismo
void bubble_sort(int (*A)[], int tamanio){
		//declaro la bandera swaps para saber si en la iteracion no hubo intercambios y entonces parar,
		//en el mejor de los casos es lineal, en el caso promedio (y peor de los casos) es cuadratico
        int swaps;
        //declaro el entero i para iterar sobre el arreglo
        int i;
        //bucle do while, itera mientras haya al menos un intercambio durante la iteracion
        do{
        	//inicialmente no hay intercambios
        	swaps = 0;
        	//bucle for para iterar sobre el arreglo
        	for(i = 0; i < tamanio-1; i++){
        		//si  el elemento siguiente al que apunta el indice actual es mayor, intercambio los elementos
        		if ((*A)[i] > (*A)[i+1]){
        			//asigno a un entero auxiliar el valor a intercambiar
        			int aux = (*A)[i];
        			//asigno el valor del elementos siguiente al elemento actual
        			(*A)[i] = (*A)[i+1];
        			//al elemento siguiente le asigno el valor que originalmente tenia el elem actual
        			(*A)[i+1] = aux;
        			//como si hubo intercambio, la bandera es verdadera
        			swaps = 1;
        		} 
        	}
        }while(swaps);
}

//regresa 1 si si esta ordenado, 0 en otro caso. Lo utilizo para test_bubble_sort
int esta_ordenado(int (*A)[], int tamanio){
	//declaro un entero para iterar sobre el arreglo
	int i;
	//itero el arreglo
	for(i = 0; i < tamanio-1; i++){
		//si el siguiente elemento al actual es mayor, entonces no esta ordenado
		if ((*A)[i] > (*A)[i+1]){
			//regreso el equivalente a falso
			return 0;
		}
	}
	//si el codigo no ha terminado hasta este punto, entonces si esta ordenado, regreso el equiv a true
	return 1;
}

//funcion para probar bubble_sort
int test_bubble_sort(){
	//inicializo el generador num aleatorios
	srand(time(NULL));
	//el numero aleatorio de veces que se probara el correcto ordenamiento
	//(hago modulo 100 para que este entre 0 y 99) y sumo 5 para que al menos haga 5 pruebas
	int num_pruebas = (rand() % 100) + 5;
	while(num_pruebas--){
		//el tamaño (aleatorio entre 0 y 99) que tendra el arreglo 
		int tamanio = rand() % 100;
		//declaro el arreglo A
		int A[tamanio];
		//declaro un indice para iterar
		int i;
		//lleno el arreglo con numeros aleatorios
		for(i = 0; i < tamanio; i++){
	    //La función rand regresa un numero aleatorio (hago modulo 100 para que este entre 0 y 99)
	    	A[i] = rand() % 100;
	  	} 
	  	//imprimo el arreglo antes de ordenarlo
	  	printf("desordenado\n");
		//itero sobre el arreglo 
		for(i = 0; i < tamanio; i++){
			//imprimo sus elementos
			printf("%d, ", A[i]);
		}
		//ordeno el arreglo usando bubble_sort
	  	bubble_sort(&A, tamanio);
	  	//imprimo el arreglo despues de ordenarlo
	  	printf("\nordenado\n");
		//itero sobre el arreglo ordenado 
		for(i = 0; i < tamanio; i++){
			//imprimo sus elementos
			printf("%d, ", A[i]);
		}
		//verifico que si este ordenado, si no esta ordenado regreso false
	  	if(!esta_ordenado(&A, tamanio)){
	  		return 0;
	  	}
	  	printf("\n");

	}
	//llegar a este punto del codigo quiere decir que ningun arreglo no estuvo ordenado
	//es decir que bubble sort ordeno correctamente los casos de prueba
	return 1; 
}

int main(){
	//pruebo la funcion de ordenamiento bubble_sort
	printf((test_bubble_sort()) ? "Jala chido\n" : "No funciona :(\n");
	return 0;
}

