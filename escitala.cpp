#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cadena;
    cout<<"Ingresa la cadena a cifrar: ";
    getline(cin,cadena);

    int largo = cadena.length();
    int contador=0, large=0;

    for (int i = 0; i < largo; ++i){
        if(cadena[i]==' ')
            break;
        contador++;
    }
    for (int i = 0; i < largo; ++i){
        if(cadena[i]==' ')
            large++;
    }
    contador+=2;
    large+=1;
    cout<<endl<<"Largo de cadena es: "<<largo;
    cout<<endl<<"primera fila es: "<<contador;
    cout<<endl<<"arreglo es: "<<large;

    string cadenaSplit[large];
    string partidor;
    partidor.assign(" ",contador);

    int suma=0;
    while(suma<largo){
        suma = suma + contador;
    }
    cout<<"\nSuma es: "<<suma<<endl;
    suma= suma-largo;
    //cout<<endl<<"agregamos tamanio de: "<<suma;

    for (int i = 0; i < suma; ++i){
        cadena.append(" ");
    }
    string partiData;

    int iniCadena=0;
    int finCadena=contador;
    int salir=0;

    do{
        partiData=cadena.substr(iniCadena, finCadena);
        iniCadena += contador;
        cadenaSplit[salir]=partiData;
        salir++;
    }while(salir<large);

    cout<<endl;
    cout<<endl<<"\nFrase Cifrada\n";
    for (int i = 0; i < contador; ++i)
    {
        for (int j = 0; j < large; ++j)
        {
            cout<<cadenaSplit[j][i];
        }
    }
    cout<<endl<<"\nFrase decifrada";
    cout<<endl<<cadena;

    return 0;
}