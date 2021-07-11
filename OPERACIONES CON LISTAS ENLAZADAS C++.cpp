# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
struct nodo{
    int dato;
    nodo* siguiente;
} *primero, *ultimo;
void insertarNodo();
void buscarNodo();
void desplegarlista();
void modificarNodo();
void ordenarlista();
void eliminarNodo();
void repetidosenlalista();
void mayormenor();
void parimpar();
int main(){
	int opcion=0;
	do{
	printf("\n|********************************|");
    printf("\n|         Lista Simple           |");
	printf("\n| 1. Insertar     |  4. Eliminar |");
	printf("\n| 2. Buscar       |  5. Desplegar|");
	printf("\n| 3. Modificar    |  6. Ordenar  |");
	printf("\n| 8. mayor y menor|  7. repetidos|");
	printf("\n| 10. salir       |  9. par impar|");
	printf("\n|********************************|");
	printf("\n ingrese el numero de la opcion que desee realizar") ;
	scanf("%d" , & opcion); 	
switch(opcion){
		case 1: printf("\n Insertar Nodo en la Lista");
		insertarNodo();
		break;
		case 2: printf("\n Buscar un Nodo en la Lista");
        buscarNodo();
		break;
		case 3: printf("\n Modificar un Nodo en la Lista");
	    modificarNodo();
		break;
		case 4: printf("\n Eliminar un Nodo en la Lista ");
		eliminarNodo();
		break;
		case 5: printf("\n Desplegar Lista de los Nodos ");
		desplegarlista();	
		break;
		case 6: printf("\n Ordenar ");
		ordenarlista();	
		break;
		case 7: printf("\n repetitivos ");
		repetidosenlalista();
		break;
		case 8: printf("\n mayor y menor ");
		mayormenor();
		break;
		case 9: printf("\n numeros pares y impares ");
		parimpar();
		break;
		case 10: printf("\n Programa Finalizado ");
		break;
		default:
			    printf("\n opcion no valida ");
	}
}
while (opcion!=10);	
	return 0;
}
void insertarNodo(){
nodo* nuevo = new nodo();
    printf("\n ingrese el dato que tendra el nuevo nodo ");
    scanf("%d" , & nuevo->dato); 
if(primero==NULL){
	primero=nuevo;
	primero->siguiente=NULL;
	ultimo=nuevo;
}
else{
ultimo->siguiente = nuevo;
nuevo->siguiente = NULL;
ultimo = nuevo;
}
    printf("\n nodo ingresado ");
}
void desplegarlista(){
nodo* actual=new nodo();
actual=primero;
if(primero!=NULL){
	while(actual!=NULL){
	printf("\n%d\n", actual->dato);
	actual=actual->siguiente;
	}
}
else{
	printf("\n lista vacia ");
}
}

void buscarNodo(){
nodo* actual=new nodo();
actual=primero;
int nodoBuscado=0, encontrado=0;
printf("\n ingrese el dato del nodo a buscar ");
scanf("%d" , & nodoBuscado);
if(primero!=NULL){
	while(actual!=NULL && encontrado!=1){
	if(actual->dato==nodoBuscado){
	printf("\n el nodo con el dato (%d) encontrado ", nodoBuscado);
	encontrado=1;
	}
	actual=actual->siguiente;
}   
  if(encontrado==0){
  	printf("\n nodo no encontrado ");
  }
else{
	printf("\n lista vacia ");
}
}
}
void modificarNodo(){
	nodo* actual=new nodo();
actual=primero;
int nodoBuscado=0, encontrado=0;
printf("\n ingrese el dato del nodo a buscar ");
scanf("%d" , & nodoBuscado);
if(primero!=NULL){
	while(actual!=NULL && encontrado!=1){
	if(actual->dato==nodoBuscado){
	printf("\n el nodo con el dato (%d) encontrado ", nodoBuscado);
	printf ("ingrese el nuevo dato para este nodo");
	scanf("%d", & actual->dato);
	printf("\n%d\n", actual->dato);
	encontrado=1;
	}
	actual=actual->siguiente;
}   
  if(encontrado==0){
  	printf("\n nodo no encontrado ");
  }
else{
	printf("\n lista vacia ");
}
}
}
void eliminarNodo(){
nodo* actual=new nodo();
actual=primero;
nodo* anterior = new nodo();
int nodoBuscado=0, encontrado=0;
printf("\n ingrese el dato del nodo a buscar ");
scanf("%d" , & nodoBuscado);
if(primero!=NULL){
	while(actual!=NULL && encontrado!=1){
	if(actual->dato==nodoBuscado){
	if(actual==primero){
	primero = primero->siguiente;
	}
    else if(actual==ultimo){
    anterior->siguiente = NULL;
    ultimo = anterior;
	}
	else{
	anterior->siguiente = actual->siguiente;
	}
	printf("nodo eliminado con exito");
	encontrado=1;
	}
	anterior=actual;
	actual=actual->siguiente;
}   
  if(encontrado==0){
  	printf("\n nodo no encontrado ");
  }
else{
free(anterior);
}
}
else {
	printf("\n lista vacia ");	
}
	}	

void ordenarlista(){
nodo* actual=new nodo();
actual = primero;
while(actual!=NULL ){
nodo* j = actual->siguiente;
while(j!=NULL){
	if(j->dato<actual->dato){
	int aux =j->dato;
	j->dato=actual->dato;
	actual->dato=aux;	
}
	j=j->siguiente;
}
actual=actual->siguiente;
}
}

void repetidosenlalista(){
nodo* actual=new nodo();
actual = primero;
while(actual!=NULL ){
nodo* j = actual->siguiente;
while(j!=NULL){
	if(j->dato==actual->dato){
	printf ("los numeros repetidos son %d\n", j->dato);
}
else{
}
	j=j->siguiente;
}
actual=actual->siguiente;
}
}
void mayormenor(){
nodo* actual=new nodo();
int mayor=0, menor=99999;
actual=primero;
	while(actual!=NULL){
	if((actual->dato)>mayor){
	mayor=actual->dato;
	}
	if((actual->dato)<menor){
	menor=actual->dato;
	}
	actual=actual->siguiente; 
}
printf ("el nodo mayor de la lista es %d\n", mayor);
printf ("el nodo menor de la lista es %d\n", menor);
}	
void parimpar(){
nodo* actual=new nodo();
int cp=0, ci=0;
actual=primero;
	while(actual!=NULL){
	if(actual->dato%2==0){
	cp++;
	}
	else{
	ci++;	
	}
	actual=actual->siguiente; 
	}
printf ("hay cuantos pares %d\n", cp);
printf ("hay cuantos impares %d\n", ci);	
}

