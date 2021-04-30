//
// Created by Usuario on 24/04/2021.
//
#include "Afin_Cipher.h"
#include "Crypto_Math.h"
#include <iostream>
#include <time.h>
#include <string>
using namespace std;
Crypto_Math operation;
Afin_Cipher::Afin_Cipher(){
    KeyGenerator();
}
Afin_Cipher::Afin_Cipher(int x,int B){
    a = operation.InversaMultiplicativa(x, alfabeto.size());
    b = B;
}
int Afin_Cipher::aleatorio(){
    srand (time(NULL));
    return operation.modulo(rand(),alfabeto.size()-2)+1;
}
void Afin_Cipher::KeyGenerator(){

    int aa;
    do{
       aa = operation.modulo(aleatorio(), alfabeto.size());
    }while(operation.Euclides(aa, alfabeto.size()) != 1);
    a = aa;
    b = operation.modulo(aleatorio(), alfabeto.size());
    cout << "\n";
    cout << "clave de a: " << a << "\nclave de b: " << b << endl;
}
string Afin_Cipher::encrypt(string mensaje){
    string cifrado = "";
    for(int i=0;i<mensaje.size();++i){
        unsigned int m=alfabeto.find(mensaje.at(i));
        if(m!=string::npos){
            int posc= operation.modulo(a * m + b, alfabeto.size());
            cifrado += alfabeto.at(posc);
        }else cifrado += " ";

    }
    return cifrado;
}
string Afin_Cipher::decrypt(string men_cifrado){
    string descifrado = "";
    for(int i=0; i < men_cifrado.size(); i++){
        unsigned  int m=alfabeto.find(men_cifrado.at(i));
        if(m!=string::npos){
            int posc= operation.modulo(a * (m - b), alfabeto.size());
            descifrado += alfabeto.at(posc);
        }else descifrado += " ";
    }
    return descifrado;
}
Afin_Cipher::~Afin_Cipher(){}