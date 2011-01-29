# include <stdio.h>
# include <stdlib.h>
//# include "estucturas.h" IMPORTANTE pasar las estructuras a un .h

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
	// Verificar que dio el espacio
	l->next=NULL;
	l->nodo=NULL;
	l->raiz=0;
	return l;
   }
struct Node * crearNodo(int elemento)
  {
	struct Node *n=(struct Node *) malloc(sizeof(struct Node));
	// Verificar que dio el espacio
	n->element= elemento;
	n->hijo=0;
	n->visitado=0;
	return n;
   }


main(int argc, char *argv[]){

	FILE *fp;

  	if (argc==1){
    		printf("No existen archivos para leer \n");
   	 	return -1;
  	}

  	fp=fopen(*++argv,"r");
  	if (fp==NULL){
      		printf("no existe el archivo \n ");
      		return -1;
    	}

	int nodoInicial,nodoFinal;
	struct Lista *listNodos= NULL; // Lista que contiene a los nodos 
	int numNodos=0; // numero de nodos en la lista

	while((fscanf(fp,"%d%d",&nodoInicial,&nodoFinal))!=-1 && (nodoFinal!=-1))
	{
		
	    if (nodoInicial!= 0 && nodoFinal!=0){ 
		
		if (nodoInicial== nodoFinal){ printf("hoal");}
			//printf("no es un arbol")
			//terminar()

		if (listNodos==NULL){
			// Si no hay ningun nodo en la lista crear los 2 primeros
			listNodos= crearLista();	
			listNodos->nodo= crearNodo(nodoFinal);
			listNodos->next= crearLista();
			struct Lista *al= listNodos->next;
			al->nodo= crearNodo(nodoInicial);
			(al->nodo->hijo)++;
			al->raiz= 1;
			listNodos->nodo->padre= al->nodo;
			numNodos + = 2;
		}else{ 
			// Sino, buscarlos en la lista para ver si ya existen
			struct Lista *al= listNodos;
			struct Lista *al2= NULL;
			// Buscar nodoFinal
			while(((al->nodo->element)!=nodoFinal) && (al->next != NULL))
			{
			  if (al->nodo->element== nodoInicial) al2= al; // Si encuentra nodoInicial guardar
			  al= al->next;
			}
			
			if ((al->nodo->element) == nodoFinal){ 	// Si ya existe, modificar nodo.

				if (al->nodo->padre != NULL){ 	// Si ya tiene otro padre no es arbol.
					printf("No es arbol");
					// Terminar 
				}else{ 				// Ya existe pero no tenia padre 
					al->raiz=0;	
				}
			}else{ 		// Si no existe, agregar en la lista y en el arbol
				al->next= crearLista();
				al= al->next;
				al->nodo= crearNodo(nodoFinal);
				numNodos++;
			}
			// Buscar nodoInicial
			if (al2== NULL){
			    al2= al;
			    while(((al2->nodo->element)!=nodoInicial) && (al2->next != NULL))
			    {
			      al2= al2->next;
			    }
			} 
			if ((al2->nodo->element)!= nodoInicial){
			      al2->next= crearLista();
			      al2=al2->next;
			      al2->nodo=crearNodo(nodoInicial);
			      numNodos++;
			      al2->raiz=1;
			}
			al->nodo->padre= al2->nodo;
			(al2->nodo->hijo)++;
			// hacerle las modificaciones  , hijos++   
		}
	     }else{ 
		// Se termino la lectura del primer caso ahora hay que buscar si hay solo una raiz 
		// Recorrer el arbol desde los hijos contando los nodos. al final comparar
		// Sin embargo en cada recorrido desde cada hoja hay q asignar un numero de visita.
		// Si llegas a un nodo que ya esta visitado con el mismo numero que estas asignando entonces eso es un ciclo
		// pero si tiene un numero diferente no hay problema pero no seguir visitando porq ya estan visitados
		// Liberar memoria 
	}
	fclose(fp);
}













