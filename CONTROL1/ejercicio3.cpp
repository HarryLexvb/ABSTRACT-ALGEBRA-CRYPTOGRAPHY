#include <iostream>
#include <string>

using namespace std;
int main() {
    int entero;
    cout<<"ingrese un numero: "; cin>>entero;

    string cadena = "";
    cadena = to_string(entero);
    cout << "covertido a string:"<< cadena;

}
