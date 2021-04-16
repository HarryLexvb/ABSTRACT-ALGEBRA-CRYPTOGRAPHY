/*
 18.27 Escriba una versión de la rutina de ordenamiento por selección (fi gura 8.28) que ordene objetos string. Use la función
swap en su solución.

Escriba 1 para orden ascendente,
Escriba 2 para orden descendente: 1
Elementos de datos en el orden original
 2 6 4 8 10 12 89 68 45 37
Elementos de datos en orden ascendente
 2 4 6 8 10 12 37 45 68 89

Escriba 1 para orden ascendente,
Escriba 2 para orden descendente: 2
Elementos de datos en el orden original
 2 6 4 8 10 12 89 68 45 37
Elementos de datos en orden descendente
 89 68 45 37 12 10 8 6 4 2

Figura 8.28 | Programa de ordenamiento multipropósito mediante el uso de apuntadores a funciones. (Parte 3 de 3).
 */

#include <iostream>
#include <string>

using namespace std;

void swap(string * const ptr1, string* const ptr2){
    string aux = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = aux;
}

int modulo(int a, int n){
    int q, r;
    q = a/n;
    r = a-(q*n);
    if (r < 0){
        q = (a/n)-1;
        r = a-(q*n);
    }
    return r;
}

void imrpimir(const string* ani, const int longitud){
    for (int i = 0; i < longitud; i++) {
        cout << (modulo(i,10) ? ' ' : '\n') << ani[i];  // condition ? consequent : alternative
                                                           // is this condition true ? yes : no
    }
    cout<<endl;
}

void ordenamiento(string *animal, const int tam){
    int smallest;
    for (int i = 0; i < tam - 1; i++) {
        smallest = i;
        for (int indice = i + 1; indice < tam; ++indice) { 
            if (animal[smallest]>animal[indice]){
                smallest = indice;
            }
            swap( &animal[ smallest ], &animal[ i ] );
        }
    }
}

int main() {
    const int tamanio= 10;
    string animal[tamanio] = {"bueno", "barco", "arma", "aeronauta", "calle", "cementerio", "cebolla"};

    cout<<"original: ";
    imrpimir(animal, tamanio);
    ordenamiento(animal, tamanio);
    cout<<"\n ordenado: ";
    imrpimir(animal, tamanio);
    return 0;
}
