//
// Created by Usuario on 24/04/2021.
//

#ifndef INVERSA_MULTIPLICATIVA_INVERSA_MULTIPLICATIVA_H
#define INVERSA_MULTIPLICATIVA_INVERSA_MULTIPLICATIVA_H

#include <iostream>


class Inversa_Multiplicativa {

public:
    Inversa_Multiplicativa();
    ~Inversa_Multiplicativa();
    int modulo(int a, int q);
    int Cambio(int b);
    int Euclides_Algorithm(int a, int b);
    int Euclides_Extend(int a, int n);
    int multiplicativa(int a,int n);

};


#endif //INVERSA_MULTIPLICATIVA_INVERSA_MULTIPLICATIVA_H
