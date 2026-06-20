#include <iostream>
#include "Bibliotecas/Utils.hpp"
int    busqueda_binaria(int arreglo[],int inicio,int fin,int valor) {
    // caso base
    if (inicio>fin) return -1;
    int medio=(inicio+fin)/2; // con esto tenemos la mitad
    if (arreglo[medio]==valor) return medio; // caso exitoso
    // caso recursivo 
    if (arreglo[medio]>valor) { // si el valor del medio es mayor al que buscamos, entonces, esta a la izquierda
        // buscamos a la izquierda
        return busqueda_binaria(arreglo,inicio,medio-1,valor);
    }else {
        // si el valor del medio es menor, significa que se encuentra a la derecha
        return busqueda_binaria(arreglo,medio+1,fin,valor);
    }
}
int main() {
    int arreglo[]={1,5,7,12,14,18,21,31};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);
    cout<<n<<endl;
    int indice=busqueda_binaria(arreglo,0,n-1,90);
    cout<<indice;

    return 0;
}
