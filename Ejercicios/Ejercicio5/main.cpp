#include <iostream>
#include <iostream>
using namespace std;
int encontrar_maximo(int *arreglo,int inicio,int fin) {
    if (inicio==fin) {
        return arreglo[inicio];
    }
    int medio=(inicio+fin)/2;

    if (arreglo[medio]<arreglo[medio+1]) {
        return encontrar_maximo(arreglo,medio+1,fin);
    }else {
        return encontrar_maximo(arreglo,inicio,medio);
    }
}

int main() {
    int arreglo[]={1,12,20,28,11,10,6};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);

    cout<<"Maximo es:"<<encontrar_maximo(arreglo,0,n-1);

    return 0;
}
