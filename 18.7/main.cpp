#include <iostream>
#include <string>

using namespace std;

/*
18.7 (Cifrado simple) Cierta información en Internet se puede cifrar con un algoritmo simple conocido como “rot13”, el
cual rota cada carácter 13 posiciones en el alfabeto. Así, 'a' corresponde a 'n', y- 'x' corresponde a 'k'. rot13 es un ejemplo
del cifrado de clave simétrica. Con este tipo de cifrado, tanto el que cifra como el que descifra utilizan la misma clave.

a) Escriba un programa que cifre un mensaje usando rot13.
b) Escriba un mensaje que descifre el mensaje codificado usando 13 como la clave.
c) Después de escribir los programas de los incisos (a) y (b), responda brevemente a la siguiente pregunta: si no conociera la
clave para el inciso (b), ¿qué tan difícil cree usted que sería quebrantar el código? ¿Qué pasaría si tuviera
acceso a un poder de cómputo considerable ( por ejemplo, supercomputadoras)? En el ejercicio 18.26 le pediremos
que escriba un programa para lograr esto.
*/

class Rot3
{
public:
    Rot3();
    string cifrado(string mensaje);
    string descifrado(string ciphermessage);
    string alfabeto;
    virtual ~Rot3();

private:
    int clave;
};

Rot3::Rot3()
{
    clave=13;
    alfabeto="abcdefghijklmnopqrstuvwxyz";
}

string Rot3::cifrado(string mensaje){
    string ciphermessage;
    for(int i=0; i<mensaje.size();i++){
        unsigned int a=alfabeto.find(mensaje.at(i));
        if(a!=string::npos){
            int comp=alfabeto.size()-clave;
            if(a>=comp)a=a-comp;
            else a+=clave;
            ciphermessage+=alfabeto.at(a);
        }
        else ciphermessage += " ";
    }
    return ciphermessage;
}

string Rot3::descifrado(string ciphermessage){
    string decrypted;
    for(int i=0; i<ciphermessage.size();i++){
        unsigned int a=alfabeto.find(ciphermessage.at(i));
        if(a!=string::npos){
            if(a<clave) a=a+alfabeto.size()-clave;
            else a-=clave;
            decrypted+=alfabeto.at(a);
        }
        else decrypted += " ";
    }
    return decrypted;
}

Rot3::~Rot3(){/*destructor*/}

int main(){
    string mensaje;
    cout<<"Ingrese una frase: ";
    getline(cin,mensaje);

    Rot3 emisor,receptor;

    cout<<emisor.cifrado(mensaje)<<endl;
    cout<<receptor.descifrado(emisor.cifrado(mensaje));
}