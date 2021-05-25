//
// Created by Usuario on 19/05/2021.
//

#include "Crypto_Math.h"

int Crypto_Math::modulo(int a, int b){
    int q = a/b;
    if(q<0) q--;
    return a-q * b;
}

bool Crypto_Math::even(int a){
    int r=(a>>1)<<1;
    if(r<0) r=int(2)+r;
    return r==a;
}

int Crypto_Math::valAbs(int a){
    if (a<0) return (a*-1);
    return a;
}
///evalua si mcd es 1
bool Crypto_Math::VerificarInversa(int x, int y){
    if(even(x)&&even(y)) return 0;
    while(x!=0){
        while(even(x)) x=x>>1;
        while(even(y)) y=y>>1;
        int t=valAbs((x-y))>>1;
        if(x>=y) x=t;
        else y=t;
    }
    return y==int(1);
}
int Crypto_Math::inversa(int a, int b){
    int s1=1, s2=0;
    if (VerificarInversa(a, b)){
        while (b > 0){
            int q= a / b;
            int r= a - q * b;
            a=b;
            b=r;
            int s=s1-q*s2;
            s1=s2;
            s2=s;
        }
        if(s1 < 0){
        	return s1+b;
        }
        return s1;
    }
    else cout<<"No tiene inversa"<<endl;
    return int(0);
}

int Crypto_Math::NumerosAleatorios(int limite){
    srand (time(NULL));
    return modulo(int(rand()), limite - 1) + 1;
}

int Crypto_Math::ExpModular(int base, int exp, int n){
    int salida=int(1);
    do{
        if(!even(exp))
            salida= modulo(salida * base, n);
        base= modulo(base * base, n);
        exp>>=1;
    }while(exp!=int(0));
    return salida;
}

bool Crypto_Math::isprime(int n) {
    for(int i=2;i*i<=n;i++){
        if(modulo(n, i) == 0){
            return false;
        }
    }
    return true;
}

int Crypto_Math::primoAleatorioP() {
    int n = NumerosAleatorios(100);
    while(1){
        if(isprime(n)){
            //cout << n <<endl;
            return n;
            //break;
        }
        n+=1;
    }
}
int Crypto_Math::primoAleatorioQ() {
    int n = NumerosAleatorios(200);
    while(1){
        if(isprime(n)){
            //cout << n <<endl;
            return n;
            //break;
        }
        n+=1;
    }
}