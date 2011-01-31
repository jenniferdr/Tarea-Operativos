# include <stdio.h>
# include <stdlib.h>
struct Node
{
  int element;
  int hijo;  
  struct Node * padre;
  int visitado;
};
   
struct Lista
{

  struct Lista *next;
  struct Node *nodo;
  int raiz;
};


extern struct Lista * crearLista();
extern struct Node * crearNodo(int elemento);


