#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() 
{
   List* L = create_list();
   int control;
   for (control = 1; control <= 10; control++)
   {
      int *dato = (int *) malloc(sizeof(int));
      *dato = control;
      pushBack(L, dato);

   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) 
{
   List *valor = first(L);

   int suma = 0;
   while(valor != NULL)
   {
      suma += (*(int*)(valor));
      valor = next(L);
   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem) 
{
   List *valor = first(L);

   while(valor != NULL)
   {
      if(*(int*)(valor) == elem) popCurrent(L);
      valor = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
   Stack *pilaAux = create_stack();

   Stack *lastValor;

   while (top(P1) != NULL)
   {
      lastValor = pop(P1);
      push(pilaAux, lastValor);  
   }

   while (top(pilaAux) != NULL)
   {
      lastValor = pop(pilaAux);
      push(P1, lastValor);
      push(P2, lastValor); 
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena)
{
   Stack *pila1 = create_stack();
   Stack *pila2 = create_stack();

   size_t talla = strlen(cadena);
   size_t control, control2, balanceado = 0;

   if(talla % 2 != 0) return 0;

   for (control = 0, control2 = talla-1; control < talla; control++, control2--)
   {
      char *dato1 = (char *) malloc(sizeof(char));
      char *dato2 = (char *) malloc(sizeof(char));

      *dato1 = cadena[control];
      *dato2 = cadena[control2];

      push(pila1, dato1);
      push(pila2, dato2);
   }
   while (top(pila1) != NULL)
   {
      char *lastValor1 = pop(pila1);
      char *lastValor2 = pop(pila2);

      if (lastValor1 == '(' && lastValor2 == ')') balanceado++;
      else if (lastValor1 == '[' && lastValor2 == ']') balanceado++;
      else if (lastValor1 == '{' && lastValor2 == '}') balanceado++;
   }
   if (balanceado == (talla/2))return 1;
   
   return 0;
}