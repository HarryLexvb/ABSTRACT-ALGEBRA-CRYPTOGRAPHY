#include "cryptomath.h"

ZZ modulo(ZZ a, ZZ b){
    ZZ q= a / b;
    if(q<0) q--;
    return a-(b * q);
}

bool even(ZZ a){
    ZZ r=(a>>1)<<1;
    if(r<0) r=ZZ(2)+r;
    return r==a;
}

ZZ valAbs(ZZ a){
    if (a<0) return (a*-1);
    return a;
}

ZZ inversa(ZZ r1, ZZ r2){
    ZZ s1=ZZ(1), s2=ZZ(0), b=ZZ(r2);
    if (Existe_Inversa(r1, r2)){
        while (r2>0){
            ZZ q=r1/r2;
            ZZ r=r1-q*r2;
            r1=r2;
            r2=r;
            ZZ s=s1-q*s2;
            s1=s2;
            s2=s;
        }
        if(s1<0) return s1+=b;
        return s1;
    }
    else cout<<"No tiene inversa"<<endl;
    return ZZ(0);
}

///evalua si mcd es 1
bool Existe_Inversa(ZZ x, ZZ y){
    if(even(x)&&even(y)) return 0;
    while(x!=0){
        while(even(x)) x=x>>1;
        while(even(y)) y=y>>1;
        ZZ t=valAbs((x-y))>>1;
        if(x>=y) x=t;
        else y=t;
    }
    return y==ZZ(1);
}

ZZ Power_mod(ZZ base, ZZ exp, ZZ n){
    ZZ salida(1);
    do{
        if(!even(exp))
            salida= modulo(salida * base, n);
        base= modulo(base * base, n);
        exp>>=1;
    }while(exp!=ZZ(0));
    return salida;
}

int modint(int a,int n){
    int q=a/n;
    if(q<0) q--;
    return a-(n*q);
}


