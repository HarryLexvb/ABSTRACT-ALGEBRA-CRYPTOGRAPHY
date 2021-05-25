//
// Created by Usuario on 19/05/2021.
//

#ifndef RSA_VERSION_0_RSA_CIPHER_H
#define RSA_VERSION_0_RSA_CIPHER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Crypto_Math.h"

using namespace std;

class RSA_Cipher {
     public:
        RSA_Cipher();
        void cifrado(int mensaje);
        void descifrado(int mensaje, int a, int b, int c);
        int n,e;
    private:
        int d, p, q;
};


#endif //RSA_VERSION_0_RSA_CIPHER_H
