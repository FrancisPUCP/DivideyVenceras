#include <iostream>
#include <iomanip>
using namespace std;
int suma_cruzada(int *arreglo,int inicio,int medio,int fin) {
    int suma=0;
    int minima_izq =INT_MAX;
    for (int i = medio; i>=inicio; i--) {
        suma+=arreglo[i];
        if (suma<minima_izq) {
            minima_izq =suma;
        }
    }
    suma=0;
    int maxima_der =INT_MAX;
    for (int i = medio+1; i<=fin; i++) {
        suma+=arreglo[i];
        if (suma<maxima_der) {
            maxima_der =suma;
        }
    }
    return maxima_der +minima_izq ;
}
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}
int suma_negativa(int arreglo[], int inicio, int fin) {
    if (inicio==fin) return arreglo[fin];
    int medio=(inicio+fin)/2;
    int izquierda=suma_negativa(arreglo,inicio,medio);
    int derecha= suma_negativa(arreglo,medio+1,fin);
    int cruzado= suma_cruzada(arreglo,inicio,medio,fin);
    return min(izquierda,derecha,cruzado);
}

int main() {
    int arreglo[]={-4, 5, 6, -4, 3, -1, -5, 6 };
    int n = sizeof(arreglo)/sizeof(arreglo[0]);

    int max_negativa=suma_negativa(arreglo,0,n-1);
    cout<<max_negativa<<endl;
    return 0;
}
