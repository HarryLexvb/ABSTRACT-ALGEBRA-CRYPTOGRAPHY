//
// Created by Usuario on 24/04/2021.
//

#include "Inversa_Multiplicativa.h"
#include <iostream>
using namespace std;

Inversa_Multiplicativa::Inversa_Multiplicativa(){}
Inversa_Multiplicativa::~Inversa_Multiplicativa(){}

int Inversa_Multiplicativa::modulo(int a, int q){
    int r;
    r=a-((a / q) * q);
    if(r<0) r= q - r;
    return r;
}
int Inversa_Multiplicativa::Cambio(int b){
    if(b<0){
        int x=-1;
        return b*x;
    }
    return b;
}

int Inversa_Multiplicativa::Euclides_Algorithm(int a, int b){
    int g=1, x=2, t;
    while (modulo(a, x) == 0 and modulo(b, x) == 0){
        a >>= 1;
        b >>= 1;
        g =2 * g;
    }
    while(a!=0){
        while(modulo(a, x) == 0) a >>= 1; // >>= es un operador de asignación de turno de izquierda a derecha.
        while(modulo(b, x) == 0) b >>= 1;
        t=((Cambio(a - b)) >> 1);
        if(a >= b) a = t;
        else b = t;
    }
    return g*b;
}

int Inversa_Multiplicativa::Euclides_Extend(int a, int n){
    int s1=1;int s2=0;
    while(n>0){
        int  q=a/n;
        int r=a-q*n;
        a=n; n=r;
        int s=s1-q*s2;
        s1=s2; s2=s;
    }
    return s1;
}

int Inversa_Multiplicativa::multiplicativa(int a,int n){
    int z=1;
    if(Euclides_Algorithm(a, n) == z){
        int inversa = Euclides_Extend(a, n);
        if (inversa<0)
            inversa+=n;
        return inversa;
    }
    else cout << "ups! NO EXISTE LA INVERSA MULTIPLICATIVA DE LOS NUMEROS INGRESADOS";
}