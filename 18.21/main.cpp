#include <iostream>
#include <string>

#include <string.h>

/*
18.21 Escriba un programa que introduzca una línea de texto, reemplace todos los signos de puntuación con espacios y utilice
la función strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).

 */

using namespace std;

int main() {
    string mensaje;
    cout<<"ingrese una linea de tecto: "; getline(cin, mensaje);

    string MensajeCambiado = "";

    for(int i = 0; i < mensaje.length(); i++){
        if(!ispunct(mensaje[i])){  // ispunct Compruebe si el carácter es un carácter de puntuación
            MensajeCambiado += mensaje[i];
        }
    }
    cout<<"mensaje con espacios reemplazados: "<<MensajeCambiado;

    cout<<"\nmensaje usando strok: \n";
    char char_mensaje[MensajeCambiado.length()+1];
    strcpy(char_mensaje, MensajeCambiado.c_str());

    char *ptr = strtok(char_mensaje," ");
    while(ptr != NULL)
    {
        cout << "\n" <<ptr << endl;
        ptr = strtok(NULL, " ");
    }
}
