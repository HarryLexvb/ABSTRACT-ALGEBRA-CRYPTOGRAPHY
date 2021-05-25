#include <iostream>
#include "RSA_Cipher.h"
#include <lib>

using namespace std;
int main() {
    int numero, op;
    RSA_Cipher emisor, receptor;

    cout << "ingrese un numero: "; cin >> numero;
    cout << "seleccione \n1. Cifrar \n2. decifrar:\n "; cin >> op;

    switch (op) {
        case 1:
            emisor.cifrado(numero);
            break;
        case 2:
            int p,q,e;
            cout << "ingrese p: "; cin >> p;
            cout << "ingrese q: "; cin >> q;
            cout << "ingrese e: "; cin >> e;
            receptor.descifrado(numero, p , q , e);
            break;
    }


    return 0;
}
