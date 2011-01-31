
# include "estructuras.h"



struct Lista * crearLista()
{
  struct Lista *l=(struct Lista *) malloc(sizeof(struct Lista));
// Verificar que dio el espacio
  if(l ==NULL){
  printf("no hay suficiente memoria");
  return NULL;
  }
 
 
  l->next=NULL;
  l->nodo=NULL;
  l->raiz=0;
  return l;
 
}
struct Node * crearNodo(int elemento)
{
  struct Node *n=(struct Node *) malloc(sizeof(struct Node));
// Verificar que dio el espacio
   if(n==NULL){
  printf("no hay suficiente memoria");
  return NULL;
  }
  

  n->padre=NULL;
  n->element= elemento;
  n->hijo=0;
  n->visitado=0;
  return n;
}
