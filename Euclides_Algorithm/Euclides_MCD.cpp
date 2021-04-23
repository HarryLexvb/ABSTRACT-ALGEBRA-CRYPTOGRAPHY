//
// Created by Usuario on 19/04/2021.
//
#include <iostream>
#include "Euclides_MCD.h"
using namespace std;

Euclides_MCD::Euclides_MCD(int _dividendo, int _divisor) {
    dividendo = _dividendo;
    divisor = _divisor;
}
Euclides_MCD::~Euclides_MCD() {}

int Euclides_MCD::modulo(int a, int n) {
    int q,r;
    q = a/n;
    r = a-(q*n);
    if (r < 0) {
        q = (a / n) - 1;
        r = a - (q * n);
    }
    return r;
}
void Euclides_MCD::calcular_MCD() {
    int residuo;
    residuo = modulo(dividendo, divisor);
    if(residuo == 0){
        cout << "el MCD es: " << divisor;
    }else {
        while (!residuo == 0) {
            dividendo = divisor;
            divisor = residuo;
            residuo = modulo(dividendo, divisor);
            if (modulo(dividendo, divisor) == 0) {
                cout << "el MCD es: " << divisor;
                break;
            }
        }
    }
}
