#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
void     merge(int *arreglo,int inicio,int medio,int fin) {
    int n=fin-inicio+1;
    int auxiliar[n];
    for(int i=0;i<n;i++) {
        auxiliar[i]=arreglo[inicio+i];
    }
    int izquierda=0;
    int derecha=medio-inicio+1;
    for (int indice=0;indice<n;indice++) {
        if (derecha<=fin-inicio) { // verificar espacios en derecha
            if (izquierda<=medio-inicio) { // verificar espacios en izquierda
                if (auxiliar[izquierda]>auxiliar[derecha]) {
                    arreglo[inicio+indice]=auxiliar[derecha++];
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
}
void merge_sort(int arreglo[],int inicio,int fin) {
    if (inicio==fin) return;

    int medio=(inicio+fin)/2;
    merge_sort(arreglo,inicio,medio); // izquierda
    merge_sort(arreglo,medio+1,fin); // derecha
    merge(arreglo,inicio,medio,fin);

}
int     busca_solo(int arreglo[],int inicio,int fin) {
    if (inicio==fin) return arreglo[inicio];
    int medio=(inicio+fin)/2;
    if (medio%2==1) {
        medio--; // lo volvemos par
    }
    if (arreglo[medio]==arreglo[medio+1]) {
        // significa que estamos en la zona correcta, vamos a la derecha
        return busca_solo(arreglo,medio+2,fin); // avanzamos 2 casillas
    }else {
        // sino vamos a la izquierda hasta encontrarlo
        return busca_solo(arreglo,inicio,medio);
    }
}
int encontrar_empleado(int arreglo[],int inicio,int fin) {
    merge_sort(arreglo,inicio,fin);
    return busca_solo(arreglo,inicio,fin);
}
int main() {
    int arreglo[]={1,1,2,2,3,3,5,5,5};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);
    cout<<"Empleado que ingreso y no salio:"<<encontrar_empleado(arreglo,0,n-1)<<endl;
    for(int i=0;i<n;i++) {
        cout<<arreglo[i]<<" ";
    }
    return 0;
}
