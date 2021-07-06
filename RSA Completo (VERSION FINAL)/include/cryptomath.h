#ifndef CRYPTOMATH_H
#define CRYPTOMATH_H

#include <iostream>
#include <NTL/ZZ.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace NTL;

ZZ inversa(ZZ a, ZZ b);
bool Existe_Inversa(ZZ x, ZZ y);
bool even(ZZ a);
ZZ valAbs(ZZ a);
ZZ modulo(ZZ a, ZZ b);
ZZ Power_mod(ZZ base, ZZ exp, ZZ n);
int modint(int a,int n);

#endif // CRYPTOMATH_H
