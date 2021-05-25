//
// Created by Usuario on 19/05/2021.
//

#ifndef RSA_VERSION_0_CRYPTO_MATH_H
#define RSA_VERSION_0_CRYPTO_MATH_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Crypto_Math {
    public:
        static int modulo(int a, int b);
        static bool even(int a);
        static int valAbs(int a);
        static bool VerificarInversa(int x, int y);
        static int inversa(int a, int b);
        static int NumerosAleatorios(int limite=int(1000));
        static int ExpModular(int base, int exp, int n);
        static bool isprime(int n);
        static int primoAleatorioP();
        static int primoAleatorioQ();
};


#endif //RSA_VERSION_0_CRYPTO_MATH_H
