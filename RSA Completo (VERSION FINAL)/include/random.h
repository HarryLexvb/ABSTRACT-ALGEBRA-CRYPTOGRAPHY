#ifndef RANDOM_H
#define RANDOM_H

#include <bits/stdc++.h>
#include <windows.h>
#include <chrono>
#include <psapi.h>
#include <bitset>
#include "cryptomath.h"
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

bool Miller_Rabin(ZZ d, ZZ n);
bool isPrime(ZZ n);
ZZ gen_prime(ZZ n);

class random {
public:
public:
    ZZ generate_random(int bits);
private:
    string processInfo;//guarda informacion de los procesos en una string
    void fillWithMemoryInfo();
    vector<int> generateSeed();
    vector<bool> RC4(vector<int> semilla);
    void izqRotate(vector<bool> &vec, int times);
    vector<bool> DES(int bits=1024);
    ZZ Random_Number(vector<bool> vec);

    int contador=0;
    int PC_1[56]={56,48,40,32,24,16,8,0,57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,60,52,44,36,28,20,12,4,27,19,11,3};
    int PC_2[48]={13,16,10,23,0,4,2,27,14,5,20,9,22,18,11,3,25,7,15,6,26,19,12,1,40,51,30,36,46,54,29,39,50,44,32,47,43,48,38,55,33,52,45,41,49,35,28,31};
    int rotaciones[22]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1,1,1,2,2,2,2};
};

#endif // RANDOM_H
