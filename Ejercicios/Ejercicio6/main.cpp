#include <iostream>
#include <iomanip>
using namespace std;
int cruzandoentre_cruce(int *arreglo,int inicio,int medio,int fin) {
    int n=fin-inicio+1;
    int auxiliar[n];
    for(int i=0;i<n;i++) {
        auxiliar[i]=arreglo[inicio+i];
    }
    int izquierda=0;
    int derecha=medio-inicio+1;
    int contador=0;
    for(int indice=0;indice<n;indice++) {
        if (derecha<=fin-inicio) {
            if (izquierda<=medio-inicio) { // verificar si esta vacio
                if (auxiliar[izquierda]>auxiliar[derecha]) {
                    arreglo[inicio+indice]=auxiliar[derecha++];
                    contador+= (medio-inicio)-izquierda+1;
                }else {
                    arreglo[inicio+indice]=auxiliar[izquierda++];
                }
            }else {
                arreglo[inicio+indice]=auxiliar[derecha++];
            }
        }else {
            arreglo[inicio+indice]=auxiliar[izquierda++];
        }
    }
    return contador;
}

int numero_inversiones(int *arreglo,int inicio,int fin) {

    if (inicio==fin) {
        return 0;
    }
    int medio=(inicio+fin)/2;
    int izquierda=numero_inversiones(arreglo,inicio,medio);
    int derecha=numero_inversiones(arreglo,medio+1,fin);
    int cruzado=cruzandoentre_cruce(arreglo,inicio,medio,fin);
    return izquierda+derecha+cruzado;
}
int main() {

    int arreglo[]={2,4,1,3,5};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);
    cout<<numero_inversiones(arreglo,0,n-1);
    return 0;
}
