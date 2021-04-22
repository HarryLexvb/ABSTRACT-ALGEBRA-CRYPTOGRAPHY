#include <iostream>
#include <string>
#include "Caesar_Algorithm.h"

using namespace std;
int main(){
    string message;
    int op, key;
    cout << "Ingrese su message: "; getline(cin, message);
    cout << "Ingrese la clave: "; cin >> key;

    cout<<"Desea cifrar o decifrar?\n1.Cifrar\n2.Decifrar"<<endl; cin>>op;
    Caesar_Algorithm emisor, receptor;

    switch (op) {
        case 1:
            cout << "El message encriptado es: " << emisor.encrypt(message, key);
            break;
        case 2:
            cout << "El message desencriptado es: " << receptor.decrypted(message, key);
            break;
        default:
            cout << "ups! el dato ingresado no esta entre las opciones" << endl;
    }
}