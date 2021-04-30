#include <iostream>
#include "Inversa_Multiplicativa.h"
using namespace std;


int main(){
    int a,b;
    cout <<"\t\t\t\t\tINVRESA MULTIPLICATIVA\n";
    cout << "ingrese a: "; cin >> a;
    cout << "ingrese b: "; cin >> b;
    Inversa_Multiplicativa Operation;
    cout << "el modulo de " << a << " y " << b << " es: " << Operation.modulo(a, b);
    cout << "\nEl GCD de " << a << " y " << b << " es: " << Operation.Euclides_Algorithm(a, b);
    cout << "\nCoeficiente para número entero menor de " << a << " y " << b << " es: " << Operation.Euclides_Extend(a, b);
    cout << "\nla inversa multiplicativa de " << a << " y " << b << " es: " << Operation.multiplicativa(a, b);
}