#include <stdio.h>

/* Declaración de funciones */
//Declara una función que regresa un entero; recibe como parámetros un apuntador a una funcion 
//(dicha funcion regresa un entero y recibe como parametro un entero) y un entero
int misterio1(int (*fun) (int), int);
//Declara una función que regresa nada; recibe como parámetros un apuntador a una funcion 
//(dicha funcion regresa nada y recibe como parametro un entero) y un entero
void misterio2(void (*fun) (int), int);
//declara una funcion que regresa un entero y recibe como parametro un entero
int cuadrado_num(int);
//declara una funcion que no regresa nada y recibe como parametro un entero
void imprime_num(int);

//la función main
int main(){
  //declara un apuntador a una funcion que regresa un entero y recibe como parametro un entero
  int (*fun1) (int);
  //declara un apuntador a una funcion que regresa nada y recibe como parametro un entero
  void (*fun2) (int);

  //al apuntador de funcion fun1 se le asigna como valor la direccion de memoria de la funcion cuadrado_num,
  //esto hara que cuando se pida el valor del apuntador fun1 se regrese la funcion cuadrado_num
  fun1 = &cuadrado_num;
  //al apuntador de funcion fun2 se le asigna como valor la direccion de memoria de la funcion imprime_num
  //esto hara que cuando se pida el valor del apuntador fun2 se regrese la funcion imprime_num
  fun2 = &imprime_num;
  //en la variable de tipo entero var se asigna el valor devuelto de la funcion misterio1 despues de recibir
  //el apuntador a funcion fun1 y el entero 3; 
  ///var = misterio1(fun1,3) = fun1(3) = cuadrado_num(3) = 9, i.e var = 9
  int var = misterio1(fun1, 3);
  //se ejecuta la funcion misterio2(fun2, var) 
  //a su vez tenemos que misterio2(fun2,var) = fun2(misterio1(fun1, 3)) = fun2(fun1(3)) = fun2(cuadrado_num(3))
  // = fun2(9) = imprime_num(9), que imprime 'Tada: 9'
  misterio2(fun2, var);
}

//funcion que regresa un entero y recibe como parametros un apuntador a una funcion 
//(que regresa un entero y recibe como parametro otro entero) y un entero
int misterio1(int (*fun) (int), int num){
    //regresa el entero que se obtiene al aplicarle la funcion (a la cual apunta el apuntador fun) el entero num
    return fun(num);
}
//funcion que regresa nada y recibe como parametros un apuntador a una funcion 
//(que regresa nada y recibe como parametro otro entero) y un entero
void misterio2(void (*fun) (int), int num){
    //aplica la funcion (a la cual apunta el apuntador fun) el entero num
    fun(num);
}

//funcion que regresa un entero y recibe un entero
int cuadrado_num(int num){
    //regresa el cuadrado del entero recibido
    return num * num;
}
//funcion que regresa nada y recibe un entero
void imprime_num(int num){
    // imprime 'Tada: ' seguido del valor del entero recibido
    printf("Tada: %d\n", num);
}
