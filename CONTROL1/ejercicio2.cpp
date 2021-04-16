
#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string cadena = "";
    cout<<"ingrese numero string: "; cin>>cadena;
    string::size_type TAM = 0;
    while (!cadena.empty()) {
        long long numero = std::stoll (cadena, &TAM, 0);
        std::cout << cadena.substr(0, TAM) << " convertido a entero es: " << numero << endl;
        cadena = cadena.substr(TAM);
    }

    return 0;
}