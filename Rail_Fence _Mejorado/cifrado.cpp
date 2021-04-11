//
// Created by Usuario on 11/04/2021.
//

#include "cifrado.h"

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

void cifrado::desencriptar() {
    char char_mensaje[mensaje.length()+1];
    strcpy(char_mensaje, mensaje.c_str());

    int A = -1, fila = 0, col = 0, m = 0;
    char ordenar[k][strlen(char_mensaje)];

    for(int i = 0; i < k; ++i)
        for(int j = 0; j < strlen(char_mensaje); ++j)
            ordenar[i][j] = '\n';

    for(int i = 0; i < strlen(char_mensaje); ++i){
        ordenar[fila][col++] = '*';

        if(fila == 0 || fila == k - 1)
            A= A * (-1);

        fila = fila + A;
    }

    for(int i = 0; i < k; ++i)
        for(int j = 0; j < strlen(char_mensaje); ++j)
            if(ordenar[i][j] == '*')
                ordenar[i][j] = mensaje[m++];

    fila = col = 0;
    A = -1;

    cout<<"\nDecrypted Message: "<<endl;

    for(int i = 0; i < strlen(char_mensaje); ++i){
        cout<<ordenar[fila][col++];

        if(fila == 0 || fila == k - 1)
            A= A * (-1);

        fila = fila + A;
    }
}

cifrado::~cifrado() {
    //destructor
}
