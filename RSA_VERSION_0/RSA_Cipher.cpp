//
// Created by Usuario on 19/05/2021.
//

#include "RSA_Cipher.h"

RSA_Cipher::RSA_Cipher()
{
    p=Crypto_Math::primoAleatorioP(), q=Crypto_Math::primoAleatorioQ();
    //p = 7, q = 13;
    n=p*q;

    int fiN=(p-1)*(q-1);

    do{
        e= Crypto_Math::NumerosAleatorios(n * n);
        //e = 131;
    }while(!Crypto_Math::VerificarInversa(e, fiN));
    d=Crypto_Math::inversa(e,fiN);

}

void RSA_Cipher::cifrado(int mensaje){
    int encrypt = Crypto_Math::ExpModular(mensaje, e, n);
    cout << "clave p: " << p;
    cout << "\nclave q: " << q;
    cout << "\nn = p*q: " << n;
    cout << "\nclave aleatoria e: " << e;
    cout << "\nclave pulica" << "(" <<e << "," << n << ")";
    cout << "\nmensaje encriptado: " << encrypt;
}

void RSA_Cipher::descifrado(int mensaje, int a, int b, int c){

    cout << "clave p: " << a;
    cout << "\nclave q: " << b;
    n = a*b;
    cout << "\nn = p*q: " << n;
    cout << "\nclave aleatoria e: " << c;
    int fiN=(a-1)*(b-1);
    d=Crypto_Math::inversa(c,fiN);
    cout << "\ninversa(" << c << "," << fiN << ")";
    cout << "\nclave pulica" << "(" <<c << "," << n << ")";
    cout << "\nclave privada" << "(" <<d << "," << n << ")";
    int decrypt = Crypto_Math::ExpModular(mensaje, d, n);
    cout << "\nmensaje desencriptado: " << decrypt;
}

