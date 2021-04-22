//
// Created by Usuario on 18/04/2021.
//


#include "Caesar_Algorithm.h"

Caesar_Algorithm::Caesar_Algorithm(){
    alfabeto="abcdefghijklmnopqrstuvwxyz";
}
int Caesar_Algorithm::modulo(int a, int n) {
    int q,r;
    q = a/n;
    r = a-(q*n);
    if (r < 0){
        q = (a/n)-1;
        r = a-(q*n);
    }
    return r;
}

string Caesar_Algorithm::encrypt(string message, int key){
    string encrypted = "";
    key =  modulo(key, 26);
    for(int i=0; i < message.size(); i++){
        unsigned int a = alfabeto.find(message.at(i));
        if(a!=string::npos){
            if(a>=alfabeto.size() - key) a -= alfabeto.size() - key;
            else a += key;
            encrypted += alfabeto.at(a);
        }
        else encrypted += " ";
    }
    return encrypted;
}

string Caesar_Algorithm::decrypted(string message, int key){
    string decrypted = "";
    key =  modulo(key, 26);
    for(int i=0; i < message.size(); i++){
        unsigned int a = alfabeto.find(message.at(i));
        if(a!=string::npos){
            if(a < key) a += alfabeto.size() - key;
            else a -= key;
            decrypted += alfabeto.at(a);
        }
        else decrypted += " ";
    }
    return decrypted;
}
Caesar_Algorithm::~Caesar_Algorithm(){}
