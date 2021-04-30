#include <iostream>
#include "Afin_Cipher.h"
using namespace std;
int main() {

    cout << "\n\t\t\t\tAFIN CIPHER"<<endl;

    Afin_Cipher emisor;
    cout << "mensaje encriptado: " << emisor.encrypt("its cool") << endl;
    //cout << "mensaje encriptado: " <<emisor.encrypt("wolfpack") << endl;

    Afin_Cipher receptor(5,8);
    cout<< "mensaje desencriptado: " << receptor.decrypt("wzu saal");
    //Afin_Cipher receptor(7,18);
    //cout<< "mensaje desencriptado: " << receptor.decrypt("ymcfvsw");
}
