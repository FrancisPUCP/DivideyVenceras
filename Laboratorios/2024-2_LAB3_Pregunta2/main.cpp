#include <iostream>
#include <iomanip>
using namespace std;
#define N 10
int contar_minerales(int *arreglo,int inicio,int fin) {
    if (inicio==fin) {
        if (arreglo[fin]==0) {
            return 0;
        }else {
            return 1;
        }
    }else if (inicio>fin){
        return 0;
    }
    int medio=(inicio+fin)/2;
   if (arreglo[medio]!=0) {
       if (arreglo[fin]!=0) {
           return fin-medio+1 +contar_minerales(arreglo,inicio,medio-1);
       }else {
           // si no es diferente de 0, nos comemos la izquierda, y vamosa la derecha
           return medio-inicio+1 +contar_minerales(arreglo,medio+1,fin);
       }
   }else {
       if (arreglo[fin]==0) {
           // vamos a la izquierda
           return contar_minerales(arreglo,inicio,medio-1);
       }else {
           return contar_minerales(arreglo,medio+1,fin);

       }
   }

}
void     obtener_muestras_mayores(int matriz[N][N]) {
    int mayor_cantidad=-999;
    int mayores[N];
    int indice=0;
    for (int i = 0; i < N; i++) {
        int cantidad_minerales=contar_minerales(matriz[i],0,N-1);
        if (cantidad_minerales>=mayor_cantidad) {
            mayor_cantidad=cantidad_minerales;
        }
    }
    // ya tenemos la mayor cantidad, ahora recorremmos quienes son iguales
    int contador=0;
    for (int i = 0; i < N; i++) {
        int cantidad_minerales=contar_minerales(matriz[i],0,N-1);
        if (cantidad_minerales==mayor_cantidad) {
           mayores[contador]=i;
           contador++;
        }
    }
    cout<<"Las muestras con mayor cantidad de niveles con minerales son: ";
    for (int i = 0; i < contador; i++) {
        cout<<mayores[i]+1<<",";
    }
    cout<<" ambos con "<<mayor_cantidad<<" estratos de minerales."<<endl;
}
int calcular_mayor_pureza(int arreglo[],int inicio,int fin) {
    if (inicio == fin) return fin;
    int medio=(inicio+fin)/2;
    if (arreglo[medio]<arreglo[medio+1]) {
        // vamos a la derecha, estamos en la zona de ascenso
        return calcular_mayor_pureza(arreglo,medio+1,fin);
    }else {
        if (arreglo[medio]==0 and arreglo[medio+1]==0) {
            // vamos a la derecha, porque estamos en una zona de ceros
            if (arreglo[inicio]<=arreglo[medio]) {
                // vamos a la derecha
                return calcular_mayor_pureza(arreglo,medio+1,fin);
            }else {
                // vamos a la izquierda
                return calcular_mayor_pureza(arreglo,inicio,medio);
            }
        }else {
            if (arreglo[inicio]<arreglo[medio]) {
                if (arreglo[medio]<arreglo[fin]) {
                    // vamos a la derecha
                    return calcular_mayor_pureza(arreglo,medio+1,fin);
                }else {
                    // vamos a la izquierda
                    return calcular_mayor_pureza(arreglo,inicio,medio);
                }
            }else {
                // sino izquierda
                return calcular_mayor_pureza(arreglo,inicio,medio);
            }
        }
    }
}
void obtener_maxima_pureza(int matriz[N][N]) {
    int mayor_pureza=-999;
    int muestra;
    int estrato;
    for (int i = 0; i < N; i++) {
        int indice=calcular_mayor_pureza(matriz[i],0,N-1);
        if (matriz[i][indice]>mayor_pureza) {
            mayor_pureza=matriz[i][indice];
            muestra=i;
            estrato=indice;
        }
    }
    cout <<"La máxima pureza de las muestras es: "<<mayor_pureza<<
        "(encontrado en la muestra "<<muestra+1<<", en el estrato "<<estrato+1<<")"<< endl;

}
int main() {
    int matriz[10][10] = {
        {0, 0, 0, 3, 3, 7, 5, 5, 1, 1},
        {8, 8, 10, 9, 9, 5, 4, 4, 2, 0},
        {3, 5, 8, 9, 7, 6, 4, 2, 0, 0},
        {9, 7, 7, 4, 4, 4, 2, 0, 0, 0},
        {0, 2, 2, 3, 3, 4, 4, 5, 3, 3},
        {0, 0, 0, 0, 0, 0, 2, 3, 4, 5},
        {1, 2, 2, 3, 3, 4, 3, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 5, 5, 7},
        {6, 5, 5, 2, 2, 1, 0, 0, 0, 0},
        {3, 2, 2, 0, 0, 0, 0, 0, 0, 0}
    };
    // cout<<matriz[5][calcular_mayor_pureza(matriz[5],0,N-1)]<<endl;
    obtener_maxima_pureza(matriz);
    // for (int i = 0; i < 10; i++) {
    //     cout<<matriz[i][calcular_mayor_pureza(matriz[i],0,N-1)]<<endl;
    // }
    obtener_muestras_mayores(matriz);
    // cout<<contar_minerales(matriz[9],0,N-1)<<endl;
    return 0;
}
