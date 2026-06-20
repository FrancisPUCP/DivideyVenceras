#include <iostream>
#include <iomanip>

using namespace std;

void merge(int *arreglo, int inicio,int medio,int fin) {
    int n=fin-inicio+1;
    int auxiliar[n]; // hacemos la copia en un auxiliar
    for (int i=0;i<n;i++) {
        auxiliar[i]=arreglo[inicio+i];
    }
    // ahora indicamos los indices del arreglo
    int izquierda=0;
    int derecha=medio-inicio+1;
    for (int indice=0;indice<n;indice++) {
        if (derecha<=fin-inicio) { // si hay en la derecha
            if (izquierda<=medio-inicio) { // si hay en la izquierda
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
void merge_sort(int *arreglo,int inicio,int fin) {
    if (inicio>=fin) return;

    int medio=(inicio+fin)/2;
    merge_sort(arreglo,inicio,medio);
    merge_sort(arreglo,medio+1,fin);
    merge(arreglo,inicio,medio,fin);
}
int  buscar_faltante(int *arreglo,int inicio,int fin) {
    if (inicio==fin) return arreglo[inicio];

    int medio=(inicio+fin)/2;
    if (medio%2==1) {
        medio--;
    }
    if (arreglo[medio]==arreglo[medio+1]) {
        return buscar_faltante(arreglo,medio+2,fin);
    }else {
        return buscar_faltante(arreglo,inicio,medio);
    }
}
void mutaciones_faltantes(int caja[6][6],int *mutaciones,int n) {
    // ordenar
    for (int i=0;i<n;i++) {
        int fila[n];
        int cantidad=0;
        // copiar solo los elementos distintos de 0
        for (int j=0;j<n;j++) {
            if (caja[i][j]!=0) {
                fila[cantidad]=caja[i][j];
                cantidad++;
            }
        }
        if (cantidad%2==0) {
            cout<<"Sin faltante"<<endl;
        }else {
            merge_sort(fila,0,cantidad-1); // ordena
            cout<<buscar_faltante(fila,0,cantidad-1)<<endl;
        }
    }
}
int main() {
    int mutaciones[]={0,1,2,3,4,5,6,7};

    int caja[6][6]={{0,3,7,2,2,7},
                {5,0,3,1,5,3},
                {7,7,3,6,6,3},
                {7,4,0,7,2,4},
                {5,1,2,5,1,2},
                {6,0,7,4,7,4}
                 };
    int n=6;
    mutaciones_faltantes(caja,mutaciones,n);
    

    return 0;
}
