#include<iostream>
using namespace std;
struct nodo{
	int dato;
	nodo *sig;
}*primero, *ultimo;
nodo *nuevo;
int  encontro;
void mostrarlista();
void mostrarlista(){
nodo *actual=NULL;
actual=primero;
while(actual!=NULL){
cout<<actual->dato<<"\n";
actual=actual->sig;
}
}
void ingresarlista(int dato);
void ingresarlista(int dato){
nuevo=new nodo();
nuevo->dato=dato;
if(primero==NULL){
primero=nuevo;
ultimo=primero;
}
else{
ultimo->sig=nuevo;
ultimo=nuevo;
}

}
void buscareingresar(int dato);
void buscareingresar(int dato){
nodo *actual;
actual=primero;
encontro = -1;
while(actual!=NULL){
if(actual->dato==dato){
encontro = 1;
break;
}
actual=actual->sig;
}
if(encontro==1){
cout<<"no lo puedo ingresar"<<"\n";
}	
else{
cout<<"lo voy a ingresar"<<"\n";
ingresarlista(dato);
}
}
int main (){
	int num,dato;
	cout<<"ingrese el tamaño de la lista";
	cin>>num;
for(int i=0;i<num;i++){
cout<<"ingrese"<<"\n";
cin>>dato;		
buscareingresar(dato);
}
cout<<"elementos de la lista"<<"\n";
mostrarlista();
return 0;
}
