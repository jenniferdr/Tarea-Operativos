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


struct Lista * crearLista()
{
  struct Lista *l=(struct Lista *) malloc(sizeof(struct Lista));
  // if(l=NULL){
  // printf("no hay suficiente memoria");
  //  }
 // Ver si podemos hacer que el usuario decida
 // else{
  l->next=NULL;
  l->nodo=NULL;
  l->raiz=0;
  return l;
  // }
}
struct Node * crearNodo(int elemento)
{
  struct Node *n=(struct Node *) malloc(sizeof(struct Node));
  // if(n=NULL){
  // printf("no hay suficiente memoria");
  //  }
  
// Verificar que dio el espacio
  n->padre=NULL;
  n->element= elemento;
  n->hijo=0;
  n->visitado=0;
  return n;
}

