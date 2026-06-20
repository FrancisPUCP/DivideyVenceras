#include <iostream>
#include <iomanip>
using namespace std;
int busca_inicio(int arreglo[], int inicio, int fin) {
    if (inicio==fin) return inicio;

    int medio = (inicio+fin)/2;
    if (arreglo[medio]>0) {
        // vamos a la izquierda
        return busca_inicio(arreglo,inicio,medio);
    }else {
        // vamos a la derecha
        return busca_inicio(arreglo,medio+1,fin);
    }
}
int busca_potencia(int arreglo[], int inicio, int fin) {
    if (inicio==fin) return inicio;
    int medio = (inicio+fin)/2;
    if (arreglo[medio]>arreglo[medio-1] and arreglo[medio]>arreglo[medio+1]) {
        return medio;
    }

}
int main() {
    int arreglo[]={0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2,1,1};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);

    int inicio=busca_inicio(arreglo,0,n-1);
    cout<<inicio<<endl;
    int potencia=busca_potencia(arreglo,inicio,n-1);
    cout<<arreglo[potencia]<<endl;
    return 0;
}

