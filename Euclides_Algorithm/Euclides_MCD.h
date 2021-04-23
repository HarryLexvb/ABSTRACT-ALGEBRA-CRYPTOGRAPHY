//
// Created by Usuario on 19/04/2021.
//

#ifndef EUCLIDES_ALGORITHM_EUCLIDES_MCD_H
#define EUCLIDES_ALGORITHM_EUCLIDES_MCD_H


class Euclides_MCD{
private:
    int dividendo, divisor ;
public:
    Euclides_MCD(int _dividendo, int _divisor);
    int modulo(int a, int n);
    void calcular_MCD();
    ~Euclides_MCD();
};


#endif //EUCLIDES_ALGORITHM_EUCLIDES_MCD_H
