#include <iostream>
#include <string>

using namespace std;

/*
18.11 Escriba un programa que introduzca por separado un primer nombre y un apellido, y que concatene los dos en un
nuevo objeto string.
*/

int main(){

    string nombre, apellido;
    cout<<"ingrese nombre: "; getline(cin, nombre);
    cout<<"ingrese apellido: "; getline(cin, apellido);
    nombre.append(" ").append(apellido);
    cout<<"concatenado es: "<<nombre<<endl;

}
