//
// Created by Usuario on 6/04/2021.
//

#include "Div.h"
#include "iostream"

Div::Div(int _a, int _n) {
    a = _a;
    n = _n;
}

void Div::operacion() {

    //int a = -255, n = 11, q, r;

    q = a/n;
    r = a-(q*n);
    if (r < 0){
        q = (a/n)-1;
        r = a-(q*n);
    }
    std::cout<<"el valor para q es: "<<q<<std::endl;
    std::cout<<"el valor para r es: "<<r<<std::endl;
}

Div::~Div() {
    //destructor
}
