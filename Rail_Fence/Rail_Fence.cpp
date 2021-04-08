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
    ~cifrado();

};
cifrado::cifrado(int _k, string _mensaje) {
    k = _k;
    mensaje = _mensaje;
}
void cifrado::encriptar() {

    char char_mensaje[mensaje.length()+1];
    strcpy(char_mensaje, mensaje.c_str());

    string encriptado = "";

    for(int i = 0; i<k;i++){
        for(int j = i;j<mensaje.length();j+=2*i){
            if( j == 0 ) {
                encriptado += char_mensaje[j];
            }
            if(2*i !=0 ) {
                encriptado += char_mensaje[j];
            }
            j += 2*(k-i-1);
            if(2*(k-i-1) != 0 && j<mensaje.length()) {
                encriptado += mensaje[j];
            }
            //cout<<encriptado<<"-"<<i<<"-"<<j<<endl;
        }
    }
    cout<<endl;
    cout<<"Mensaje cifrado:"<<encriptado<<endl;

}

cifrado::~cifrado() {
    //destructor
}

int main() {

    string mensaje;
    cout << "Mensaje a cifrar:";
    getline (cin, mensaje);
    int k;
    do
    {
        cout<<endl;
        cout<<"Clave:";
        cin>>k;
    }while(k>=mensaje.length() || k<2);

    cifrado operacion(k, mensaje);
    operacion.encriptar();

    return 0;
}