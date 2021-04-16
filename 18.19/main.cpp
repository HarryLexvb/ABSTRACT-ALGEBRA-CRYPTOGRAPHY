#include <iostream>
#include <string>
using namespace std;
/*
 18.19 Escriba un programa que inserte los caracteres "******" en la mitad exacta de un objeto string.
 */

int main() {
    string mensaje;
    int mitad;
    cout<<"ingrese mensaje: "; getline(cin, mensaje);

    mitad = mensaje.length()/2;
    cout<<mensaje.substr(0,mitad).append("******").append(mensaje.substr(mitad, mensaje.length()));

}
