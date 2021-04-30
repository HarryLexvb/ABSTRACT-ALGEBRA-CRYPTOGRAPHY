//
// Created by Usuario on 24/04/2021.
//

#ifndef RANDOM_FUNCTION_RANDOM_FUNCTION_H
#define RANDOM_FUNCTION_RANDOM_FUNCTION_H

#include <stdlib.h>
#include <time.h>
class Random_Function {
public:
     int modulo(int a, int b);
     int random(int tope=RAND_MAX);
};


#endif //RANDOM_FUNCTION_RANDOM_FUNCTION_H
