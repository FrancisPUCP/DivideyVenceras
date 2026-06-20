#include <iostream>
#include <iomanip>
using namespace std;
int suma_cruzada(int *arreglo,int inicio,int medio,int fin) {
    // suma desde el medio hacia la izquierda, la mejor

    int suma=0;
    int suma_izquierda=-999;
    // suma desde el medio hacia la derecha
    for (int indice=medio;indice>=inicio;indice--) {
        suma+=arreglo[indice];
        if (suma>suma_izquierda) {
            suma_izquierda=suma;
        }
    }
    suma=0;
    int suma_derecha=-999;
    for (int indice=medio+1;indice<=fin;indice++) {
        suma+=arreglo[indice];
        if (suma>suma_derecha) {
            suma_derecha=suma;
        }
    }
    return suma_derecha+suma_izquierda;
}
int    maximo(int a,int b,int c) {
    if (a>=b && a>=c) {
        return a;
    }else if (b>=a && b>=c) {
        return b;
    }else if (c>=a && c>=b) {
        return c;
    }
}
int suma_maxima(int *arreglo,int inicio,int fin) {
    if (inicio == fin) return arreglo[inicio];

    int medio=(inicio+fin)/2;

    int izquierda= suma_maxima(arreglo,inicio,medio);
    int derecha= suma_maxima(arreglo,medio+1,fin);
    int cruzada = suma_cruzada(arreglo,inicio,medio,fin);

    return maximo(izquierda,derecha,cruzada);

}
int main() {
    int arreglo[]={-2,-5,6,-2,-3,1,5,-6};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);
    int suma=suma_maxima(arreglo,0,n-1);
    cout<<suma<<endl;
    return 0;
}
