#include <iostream>
#include <string>

/*
 18.22 Escriba un programa que introduzca una línea de texto y la imprima al revés. Use iteradores en su solución.
*/
using namespace std;
int main() {
    string mensaje;
    cout << "ingrese una linea de texto: ";
    getline(cin, mensaje);

    reverse_iterator voltear = mensaje.rbegin();
    //reverse_iterator Esta clase invierte la dirección en la que un iterador bidireccional o de acceso aleatorio itera a través de un rango.
    //Devuelve un iterador inverso que apunta al último carácter de la cadena (es decir, su comienzo inverso).
    // Los iteradores inversos iteran hacia atrás: aumentarlos los mueve hacia el comienzo de la cadena.
    while (voltear != mensaje.rend()) {
        //rend Devuelve un iterador inverso que apunta al elemento teórico que precede al primer carácter de la cadena
        // (que se considera su extremo inverso).
        //El rango entre string :: rbegin y string :: rend contiene todos los caracteres de la cadena (en orden inverso).
        cout << *voltear;
        ++voltear;
    }
    cout<<endl;
    
}
