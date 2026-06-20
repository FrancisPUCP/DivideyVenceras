#include <iostream>
#include <iomanip>
using namespace std;
int calcular_empieza(int arreglo[],int inicio,int fin) {
    if (inicio==fin) return fin;
    int medio=(inicio+fin)/2;

    if (arreglo[medio]==0 or arreglo[medio]==-1) {
        // nos vamos a la derehca
        return calcular_empieza(arreglo,medio+1,fin);
    }else {
        // nos vamos a la izquierda
        return calcular_empieza(arreglo,inicio,medio);
    }
}
int calcular_maximo(int arreglo[],int inicio,int fin) {
    if (inicio==fin) return arreglo[inicio];
    int medio=(inicio+fin)/2;
    if (arreglo[inicio]<arreglo[medio]) {
        // vamos a la derecha
        return calcular_maximo(arreglo,medio,fin);
    }else {
        // vamos a la izquierda
        return calcular_maximo(arreglo,inicio,medio);
    }
}
void     determinar_resultados(int arreglo[],int n) {

    int empieza=calcular_empieza(arreglo,0,n-1);
    cout<<"El resultado sera: La radiacion empieza a "<<empieza<<" km"<<endl;
    int potencia_maxima=calcular_maximo(arreglo,empieza,n-1);
    cout<<"Potencia maxima "<<potencia_maxima<<" megatones."<<endl;

}
int main() {
    int arreglo[]={0,-1,0,-1,0,1,1,2,2,3,3,4,3,3,2,2,1,1};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);
    determinar_resultados(arreglo,n);
    return 0;
}
