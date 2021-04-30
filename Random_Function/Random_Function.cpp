//
// Created by Usuario on 24/04/2021.
//

#include "Random_Function.h"
int Random_Function::modulo(int a, int b){
    int r;
    r=a-((a/b)*b);
    if(r<0) r=b+r;
    return r;
}
int Random_Function::random(int tope){
    srand (time(NULL));
    int a = modulo(rand(), tope )+1;
    return a;
}