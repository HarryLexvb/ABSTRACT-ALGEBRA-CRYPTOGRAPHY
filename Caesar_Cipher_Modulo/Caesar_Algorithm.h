//
// Created by Usuario on 18/04/2021.
//

#ifndef CAESAR_CIPHER_MODULO_CAESAR_ALGORITHM_H
#define CAESAR_CIPHER_MODULO_CAESAR_ALGORITHM_H

#include <string>
using namespace std;
class Caesar_Algorithm{
public:
    Caesar_Algorithm();
    int modulo(int a, int n);
    string encrypt(string message, int key);
    string decrypted(string message, int key);
    string alfabeto;
    ~Caesar_Algorithm();
};

#endif //CAESAR_CIPHER_MODULO_CAESAR_ALGORITHM_H
