/*
  Author: Fran Espino Mostacero
  Tema: Listas enlazadas de números aleatorios.
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include<iostream>
using namespace std;
int aleatorio,i=0,temp,op;

struct Nodo{
    int dato;
    Nodo * sgt;
};

int Aleatorio(){
    srand(time(NULL));
    aleatorio = 1 + rand() % (10- 1);
    return aleatorio;
}

void agregarElemento(Nodo *&pI){

    fflush(stdin);
    cout<<"Desea ingresar mas datos (1/0): ";
    cin>>op;
    do{
        Nodo *nuevoN = new (Nodo);
        nuevoN->dato=Aleatorio();
        cout<<"Dato agregado : "<<nuevoN->dato<<endl;
        nuevoN->sgt=pI;
        pI=nuevoN;
        fflush(stdin);
        cout<<"Desea ingresar mas datos (1/0): ";
        cin>>op;

    }while(op==1);

}

void mostrarDatos(Nodo *&pI){

    while(pI!=NULL){
        cout<<pI->dato<<" ";
        pI=pI->sgt;
    }
}


int main()
{

    //vamos a generar el primer nodo de la lista por defecto
    Nodo *pI = new (Nodo);
    pI->dato = Aleatorio();
    pI->sgt=NULL;
    cout<<"Dato agregado : "<<pI->dato<<endl;
    agregarElemento(pI);
    mostrarDatos(pI);

    return 0;
}
