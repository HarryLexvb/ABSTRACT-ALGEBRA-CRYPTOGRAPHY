#include <iostream>
#include "Euclides_MCD.h"
using namespace std;

int main(){
    int dividendo, divisor;

    cout << "ingrese a (dividendo): "; cin >> dividendo;
    cout << "ingrese b (divisor): ";cin >> divisor;

    Euclides_MCD(dividendo, divisor).calcular_MCD();
}