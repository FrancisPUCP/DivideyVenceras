#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int     encontrar_elemento(int *arreglo,int inicio,int final) {
    if (inicio==final) {
        return arreglo[inicio];
    }
    int medio=(inicio+final)/2;
    // hacemos que medio sea par
    if (medio%2==1) { // si medio es impar, lo volvemos par
        medio--;
    }
    if (arreglo[medio]==arreglo[medio+1]) { // significa que esta en orden
        return encontrar_elemento(arreglo,medio+2,final);
    }else { // sino
        // si la pareja no esta bien formada, el unico esta a la izquiero o es medio
        return encontrar_elemento(arreglo,inicio,medio);
    }


}
int main() {
    int arreglo[]={1,1,3,3,4,5,5,7,7,8,8};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);
    int elemento= encontrar_elemento(arreglo,0,n-1);
    cout<<"elemento: "<<elemento<<endl;
    return 0;
}
