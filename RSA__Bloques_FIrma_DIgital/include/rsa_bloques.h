#ifndef RSA_BLOQUES_H
#define RSA_BLOQUES_H

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <NTL/ZZ.h>
#include "cryptomath.h"
#include "random.h"
using namespace std;
using namespace NTL;

class rsa_bloques{
public:
    /*rsa_bloques(int bits);
    rsa_bloques(ZZ n,ZZ e);
    string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
    string encrypt(string mensaje);
    string decrypt(string mensaje);
    ZZ n, e;*/

    rsa_bloques(int bits);
    rsa_bloques(ZZ n,ZZ e);
    string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890[]";
    string encrypt(string mensaje, ZZ Nr, ZZ Er);
    string decrypt(string mensaje);
    string dividirBloques(string mensaje);
    string completarCeros(string mensaje,ZZ Nr);
    string ZZtoStr(ZZ z);
    string encryptD(string mensajeNo);
    string decryptE(string mensajeNo, ZZ Ne, ZZ Ee);
    string sign_encrypt(string mensajeL, ZZ Nr, ZZ Er);
    string remove_sign(string mensaje, ZZ Ne, ZZ Ee);
    ZZ n, e;

private:
    ZZ d, PhiN, p, q;
    //string ZZtoStr(ZZ z);
    ZZ TRC(ZZ M);
};
#endif // RSA_BLOQUES_H
