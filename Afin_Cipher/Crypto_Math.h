//
// Created by Usuario on 24/04/2021.
//

#ifndef AFIN_CIPHER_CRYPTO_MATH_H
#define AFIN_CIPHER_CRYPTO_MATH_H

class Crypto_Math
{
    public:
        Crypto_Math();
        int modulo(int a, int q);
        int Euclides(int a, int b);
        int EuclidExtended(int a, int n);
        int InversaMultiplicativa(int a, int n);
        int change(int b);
        ~Crypto_Math();
};
#endif //AFIN_CIPHER_CRYPTO_MATH_H
