#include <iostream>
#include <iomanip>
using namespace std;
#define N 10
#define m 10
int buscar_maximo(int arreglo[],int inicio,int fin) {
    if (inicio==fin) return arreglo[fin];
    int medio=(inicio+fin)/2;
    int izquierda=buscar_maximo(arreglo,inicio,medio);
    int derecha = buscar_maximo(arreglo,medio+1,fin);
    return max(izquierda,derecha);
}
void  buscar_maxima_produccion(int pedidos[N][10],int n) {

    for (int i = 0; i < n; i++) {

        int maximo=buscar_maximo(pedidos[i],0,m-1);
        cout<<"Empresa 1: "<<maximo<<endl;
    }

}
int main() {
    int n=3;
    int pedidos[N][10] = {
        {15, 12, 10, 17, 15, 18, 18, 18, 12, 16}, // Empresa 1
        {14, 17, 17, 17, 17, 12, 14, 14, 12, 12}, // Empresa 2
        {16, 18, 20, 20, 15, 18, 16, 18, 18, 16}  // Empresa 3
        };
    buscar_maxima_produccion(pedidos,n);
    return 0;
}
