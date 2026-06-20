#include <iostream>
#include <iomanip>
using namespace std;
int suma_entrecruzada(int arreglo[],int inicio,int medio,int fin) {
    // mejor suma de la izquierda
    int mejor_suma_negativa_izq=9999;
    int suma=0;
    for(int i=medio;i>=inicio;i--) {
        suma+=arreglo[i];
        if (suma<mejor_suma_negativa_izq) {
            mejor_suma_negativa_izq=suma;
        }
    }
    // mejor suma de la derecha
    int mejor_suma_negativa_der=9999;
    suma=0;
    for(int i=medio+1;i<=fin;i++) {
        suma+=arreglo[i];
        if (suma<mejor_suma_negativa_der) {
            mejor_suma_negativa_der=suma;
        }
    }
    return mejor_suma_negativa_der+mejor_suma_negativa_izq;
}
int maximo_negativo(int a,int b,int c) {
    if (a<=b && a<=c) return a;
    if (b<=c && b<=a) return b;
    return c;
}
int acumulacion_negativa_alta(int *arreglo, int inicio,int fin) {
    if (inicio==fin) {
        return arreglo[fin];
    }

    int medio=(inicio+fin)/2;
    int izquierdo=acumulacion_negativa_alta(arreglo,inicio,medio);
    int derecho=acumulacion_negativa_alta(arreglo,medio+1,fin);
    int entre_cruzado=suma_entrecruzada(arreglo,inicio,medio,fin);
    return maximo_negativo(izquierdo,derecho,entre_cruzado);
}
int main() {
    int arreglo[]={-4, 5, 6, -4, 3, -1, -5, 6};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);

    int negativa_alta=acumulacion_negativa_alta(arreglo,0,n-1);
    cout<<negativa_alta<<endl;
    return 0;
}
