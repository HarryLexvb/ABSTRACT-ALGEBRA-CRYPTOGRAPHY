//
// Created by Usuario on 11/04/2021.
//

#ifndef RAIL_FENCE_CIFRADO_H
#define RAIL_FENCE_CIFRADO_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class cifrado{
private:
    int k;
    string mensaje;
public:
    cifrado(int _k, string _mensaje);
    void encriptar();
    void desencriptar();
    ~cifrado();

};


#endif //RAIL_FENCE_CIFRADO_H
