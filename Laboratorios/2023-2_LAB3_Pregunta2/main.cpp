#include <iostream>
#include <iomanip>
using namespace std;
#define m 8
#define n 11
char encontrar_extra(char *arreglo,int inicio,int fin) {
    if (inicio == fin) return arreglo[fin];

    int medio=(inicio+fin)/2;
    if (medio%2==1) {
        medio=medio-1;
    }

    if (arreglo[medio]==arreglo[medio+1]) {
        // a la derecha
        return encontrar_extra(arreglo,medio+2,fin);
    }else {
        // a la izquierda
        return encontrar_extra(arreglo,inicio,medio);
    }
}
void     determinar_extra(char matriz[m][n]) {
    for (int i = 0; i < m; i++) {
        if (matriz[i][n-1]==' ') continue;
        char extra=encontrar_extra(matriz[i],0,n-1);
        cout<<"La fila "<<i+1<<" tiene un "<<extra<<" adicional"<<endl;
    }
}

int encontrar_mayor(int *arreglo,int inicio,int fin) {
    if (inicio == fin) return fin;

    int medio=(inicio+fin)/2;
    if (arreglo[inicio]>=arreglo[medio]) {
        // vamos a la izquierda
        return encontrar_mayor(arreglo,inicio,medio);

    }else {
        if (arreglo[medio-1]>arreglo[medio] and arreglo[medio]<=arreglo[medio+1]) {
            return encontrar_mayor(arreglo,inicio,medio);
        }else {
            return encontrar_mayor(arreglo,medio,fin);
        }
    }
}
void     determinar_mayor(int  precios[8][5]) {
    for (int i = 0; i < m; i++) {
        int mayor=encontrar_mayor(precios[i],0,5-1);
        cout<<"En la fila "<<i+1<<", el pasajero del asiento "<<mayor+1<<" tiene el bocadito mas caro que sus 2 vecinos "<<endl;
    }

}
int main() {
    char matriz[m][n]={{'O', 'O', 'C', 'C', 'A', 'A', 'E', 'E', 'R', 'R', 'R'},
                    {'C', 'C', 'A', 'A', 'R', 'R', 'E', 'E', 'B', 'B', ' '},
                    {'R', 'R', 'E', 'E', 'C', 'C', 'F', 'F', 'A', 'A', ' '},
                    {'E', 'E', 'F', 'F', 'A', 'A', 'A', 'B', 'B', 'R', 'R'},
                    {'C', 'C', 'C', 'A', 'A', 'R', 'R', 'O', 'O', 'E', 'E'},
                    {'O', 'O', 'C', 'C', 'A', 'A', 'R', 'R', 'E', 'E', ' '},
                    {'A', 'A', 'F', 'F', 'R', 'R', 'E', 'E', 'O', 'O', ' '},
                    {'E', 'E', 'A', 'A', 'O', 'O', 'B', 'B', 'F', 'F', ' '}
    };
    // cout<<encontrar_extra(matriz[4],0,n-1);
    determinar_extra(matriz);

    int precios[8][5] = {
        {1, 2, 3, 2, 1},
        {2, 3, 2, 2, 1},
        {1, 2, 2, 5, 3},
        {2, 5, 3, 3, 1},
        {2, 2, 3, 2, 1},
        {1, 2, 3, 2, 1},
        {3, 5, 2, 1, 1},
        {2, 3, 2, 1, 1}
    };

    determinar_mayor(precios);
    return 0;
}
