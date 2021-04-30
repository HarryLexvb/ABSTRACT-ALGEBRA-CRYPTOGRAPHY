//
// Created by Usuario on 24/04/2021.
//

//FUNCIONES MATEMATICAS
#include "Crypto_Math.h"
#include <iostream>
using namespace std;
Crypto_Math::Crypto_Math() {}
int Crypto_Math::modulo(int a, int q){
    int r;
    r = a - (q * (a / q));
    if(r<0) r= q + r;
    return r;
}
int Crypto_Math::change(int b){
    if(b<0){
        int x=-1;
        return b*x;
    }
    return b;
}
int Crypto_Math::Euclides(int a, int b){
    int z=1, x=2, t;
    while (modulo(a, x) == 0 and modulo(b, x) == 0){
        a = a >>= 1;
        b = b >>= 1;
        z = 2 * z;
    }
    while(a!=0){
        while(modulo(a, x) == 0) a >>= 1;
        while(modulo(b, x) == 0)b >>= 1;
        t=((change(a - b)) >> 1);
        if(a>=b)a=t;
        else b=t;
    }
    return z * b;
}
int Crypto_Math::EuclidExtended(int a, int n){
    int s, s1 = 1, s2 = 0;
    while(n>0){
        int  q=a/n;
        int r=a-q*n;
        a=n;
        n=r;
        s = s1 - q*s2;
        s1 = s2;
        s2 = s;
    }
    return s1;
}
int Crypto_Math:: InversaMultiplicativa(int a, int n){
    int x=1, inversa;
    if(Euclides(a, n) == x){
        inversa = EuclidExtended(a, n);
        if (inversa<0) inversa += n;
        return inversa;
    }
    cout<<"ups! lamento decirte que no tiene inversa"<<endl;
}
Crypto_Math::~Crypto_Math() {}