#include <iostream>
#include <iomanip>
using namespace std;
int encontrar_minimo(int *arreglo,int inicio,int fin) {
    if (inicio==fin) {
        return arreglo[inicio];
    }
    int medio=(inicio+fin)/2;
    // if (arreglo[medio]<arreglo[medio-1]) {
    //     return arreglo[medio];
    // }

    if (arreglo[medio]<arreglo[fin]) { // es decir esta en subida
        return encontrar_minimo(arreglo,inicio,medio); // esta recursividad va a ir hasta el valor menor de la subida
    }else { //
        return encontrar_minimo(arreglo,medio+1,fin); // cuando no esta en subida
    }
}
int main() {
    int arreglo[] = {5, 6,1,2,3,4};
    int n = sizeof(arreglo)/sizeof(arreglo[0]);

    cout<<encontrar_minimo(arreglo,0,n-1)<<endl;
    return 0;
}
