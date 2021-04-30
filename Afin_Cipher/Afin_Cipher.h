//
// Created by Usuario on 24/04/2021.
//

#ifndef AFIN_CIPHER_AFIN_CIPHER_H
#define AFIN_CIPHER_AFIN_CIPHER_H

#include <string>

using namespace std;
class Afin_Cipher
{
    //Protegemos nuestra clave generada
    protected:
    private:
        int a, b;
        void KeyGenerator();
        int aleatorio();

    public:
        Afin_Cipher();
        Afin_Cipher(int x, int B);
        string alfabeto="abcdefghijklmnopqrstuvwxyz";
        string encrypt(string mensaje);
        string decrypt  (string men_cifrado);
        ~Afin_Cipher();

};
#endif //AFIN_CIPHER_AFIN_CIPHER_H
