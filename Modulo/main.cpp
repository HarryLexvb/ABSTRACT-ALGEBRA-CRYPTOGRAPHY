#include <iostream>
#include "Div.h"
using namespace std;
int main(){
    int a,q;
    cout<<"ingrese a: "; cin>>a;
    cout<<"ingrese n: "; cin>>q;
    Div objeto(a,q);
    objeto.operacion();
}