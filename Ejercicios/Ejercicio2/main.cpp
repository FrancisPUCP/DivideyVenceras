#include <iostream>
#include <iomanip>
using namespace std;
int contar_ceros(int *arreglo, int inicio,int fin,int contador) {
    // si es que inicio es mayor que el fin termina 
    if (inicio>fin) {
        return contador;
    }
    int medio=(inicio+fin)/2;
    if (arreglo[medio]==1) { // es una zona que no queremos
        return contar_ceros(arreglo,medio+1,fin,contador);
    }else { // si es un 0
        // sabesmo que del actual medio para adelante hasta el fin son 0
        return contar_ceros(arreglo,inicio,medio-1,contador+fin-medio+1);
    }
}
int main() {
    int arreglo[]={1,1,1,1,0,0};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);

    cout<<contar_ceros(arreglo,0,n-1,0);
    return 0;
}
