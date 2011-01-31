# include <stdio.h>
# include <stdlib.h>
# include "estructuras.h"

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
  // Inicializar variables. 1 es "true"
  int esArbol=1;
  int nodoInicial,nodoFinal;
  struct Lista *listNodos= NULL; // Lista que contiene a los nodos 
  int numNodos=0; // numero de nodos en la lista
  int Caso= 1;

	// Leer todos los pares de nodos 
  while((fscanf(fp,"%d%d",&nodoInicial,&nodoFinal))!=-1 && (nodoFinal!=-1))
    {
      
      if (nodoInicial!= 0 && nodoFinal!=0){ 
	if (nodoInicial== nodoFinal){
	//No es un arbol
	  esArbol=0;
	}
	if(esArbol!=0){
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
	  numNodos= numNodos + 2;
	}else { 
	  // Sino, buscarlos en la lista para ver si ya existen
	  struct Lista *al= listNodos;
	  struct Lista *al2= NULL;
	  // Buscar nodoFinal
	  while(((al->nodo->element)!=nodoFinal) && (al->next != NULL))
	    { 
		// Si encuentra nodoInicial guardar
	      if (al->nodo->element== nodoInicial) al2= al;
		// Seguir recorriendo lista de nodos 
	      al= al->next;
	    }
		if (al->nodo->element== nodoInicial) al2= al;

	   // Si ya existe, modificar nodo.
	  if ((al->nodo->element) == nodoFinal){ 	

	    if (al->nodo->padre != NULL){  // Si ya tiene otro padre no es arbol
	      esArbol=0; 
	    }else{ 			// Ya existe pero no tenia padre 
	      al->raiz=0;	
	    }
	  }else{ 	// Si no existe, agregar en la lista y en el arbol
	    al->next= crearLista();
	    al= al->next;
	    al->nodo= crearNodo(nodoFinal);
	    numNodos++;
	  }
	  if(esArbol!=0){
	  // Buscar nodoInicial
	  if (al2== NULL){
	    al2= al;
	    while(((al2->nodo->element)!=nodoInicial) && (al2->next != NULL))
	      {
		al2= al2->next;
	      }
	  } 
	// Si no existe crearlo.
	  if ((al2->nodo->element)!= nodoInicial){
	    al2->next= crearLista();
	    al2=al2->next;
	    al2->nodo=crearNodo(nodoInicial);
	    numNodos++;
	    al2->raiz=1;
	  }
	  // Crear vinvulo entre nodoInicial y nodoFinal
	  al->nodo->padre= al2->nodo;
	  (al2->nodo->hijo)++;
	  }   
	}
	}
      }else{ 
	//*********FIN DEL CASO*********// Verificar si es arbol

 	// ver si existe una raiz y solo una
      struct Lista *primer;
      primer= listNodos;
      int unaRaiz;
      unaRaiz=0;
	   
       while(primer!=NULL && esArbol!=0)
	{
	if (primer->raiz==1)
	  {
	    unaRaiz= unaRaiz +1;
	    if (unaRaiz==2){
	      esArbol=0;
	    }
	  }
	    primer=primer->next;
	}


      
  	// Recorrer el arbol en busca de ciclos 
       primer= listNodos;
       int numVisita=0;
       int contRecorrido=0;
       if (esArbol!=0){
       while(primer!=NULL)
	 { // Se comienza a recorrer el arbol por los nodos sin hijos 
	   if (primer->nodo->hijo==0)
	     { 
	       contRecorrido++;
	       struct Node *nodoV = primer->nodo;
	       numVisita++;
	       nodoV->visitado= numVisita; 
		// Iniciar recorrido
	       while(nodoV->padre!=NULL && esArbol==1)
		 {
	   	
		   if (nodoV->padre->visitado==0)
		     { // marcar el nodo como visitado y contar los que visito
		       contRecorrido++;
		       nodoV->padre->visitado=numVisita;
		     }
		   else if(nodoV->visitado==nodoV->padre->visitado)
		     { /* Si el numero de la visita del nodo es igual a la 
			 del recorrido Hay un ciclo */
		       esArbol=0;
		     }
	
		   else
		     {
		  // Si ya esta visitado seguir con el prox hijo
		       break;
		     }
		 
		   nodoV= nodoV->padre;
		 }
	     }
		   primer = primer->next;
	     
	 }
       
       if (contRecorrido!=numNodos)
	 {
	  esArbol=0;
         }
       }
       if (esArbol==0){
	   printf("Caso %d es un arbol.\n",Caso);
	 }else{
	 printf("Caso %d no es un arbol.\n",Caso);
       }
		
	// Liberar memoria
	// Inicializar variables para el proximo caso 
	Caso++;
	esArbol=1;
  	listNodos= NULL;
  	numNodos=0;
      }
    }
      fclose(fp);
     
  
}

