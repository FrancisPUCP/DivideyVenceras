#include <iostream>
#include <iomanip>
using namespace std;
void merge(int arreglo[], int inicio,int medio,int fin) {
    // Complejidad: O(n) en tiempo y O(n) en espacio adicional
    int size = fin-inicio+1; // tamaño del tramo
    int auxiliar[size]; // este arreglo temporal guardará una copia del tramo que vamos a ordenar
    for (int i = 0; i < size; i++) {
        auxiliar[i] = arreglo[inicio+i];
    }
    // los siguientes indices apuntan al arreglo auxiliar
    int izquierda=0;
    int derecha= medio -inicio+1;
    for (int indice = 0; indice <size; indice++) {
        if (derecha<=fin-inicio) {// verifica derecha (si hay elementos)
            if (izquierda <= medio-inicio ) { // verifica izquierda (si hay elementos)
                if (auxiliar[izquierda]>auxiliar[derecha])
                    arreglo[inicio+indice]=auxiliar[derecha++];
                else
                    arreglo[inicio+indice]=auxiliar[izquierda++];
            }else {
                arreglo[inicio+indice]=auxiliar[derecha++];
            }
        }else {
            arreglo[inicio+indice]=auxiliar[izquierda++];
        }
        // verifica derecha
    }
}
void merge_sort(int *arreglo,int inicio, int fin) {
    // pre-condición
    if (inicio==fin) return;
    int medio=(fin+inicio)/2;
    merge_sort(arreglo,inicio,medio); // primera parte
    merge_sort(arreglo,medio+1,fin); // segunda parte
    // proceso de mezcla
    merge(arreglo, inicio,medio,fin); // combinamos
    // recordar que aca hay un return tacito
}
int main() {
    int arreglo[]={31,5,14,7,12,1,21,18};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);
    merge_sort(arreglo,0,n-1);
    for (int indice = 0; indice < n; indice++) {
        cout<<arreglo[indice]<<endl;
    }
    return 0;
}
