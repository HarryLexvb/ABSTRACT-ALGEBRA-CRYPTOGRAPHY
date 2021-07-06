#include <iostream>
#include "cryptomath.h"
#include "random.h"
#include <NTL/ZZ.h>

using namespace std;
using namespace std;
random op;
int main(){
    ZZ p, q, e;
    /*for(int i=0; i < 10; i++){
        p=gen_prime(op.generate_random(64));
        cout << "p: " << p <<endl;
        if(isPrime(p)) cout << "primo"<<endl;
        else cout << "no primo" << endl;
    }*/
    p=gen_prime(op.generate_random(1024));
    q=gen_prime(op.generate_random(1024));
    e=op.generate_random(64);
    cout << "p: " << p <<endl;
    cout << "q: " << q <<endl;
    cout << "e: " << e <<endl;

}
