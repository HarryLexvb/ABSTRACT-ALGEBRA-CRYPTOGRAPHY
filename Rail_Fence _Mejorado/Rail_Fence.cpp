#include <iostream>
#include <string>
#include <cstring>
#include "cifrado.h"
using namespace std;

int main() {

    string mensaje;
    int op,k;
    cout << "ingrese una frase :";
    getline (cin, mensaje);
    do
    {
        cout<<endl;
        cout<<"Clave:";
        cin>>k;
    }while(k>=mensaje.length() || k<2);
    cifrado operacion(k, mensaje);
    cout<<"eliga una opcion:\n 1.Cifrar\n 2. decifrar"<<endl;
    cin>>op;

    if(op == 1)operacion.encriptar();
    else if(op == 2)operacion.desencriptar();



    return 0;
}