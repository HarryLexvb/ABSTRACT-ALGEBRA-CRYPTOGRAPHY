#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string mensaje = "";
  int n;
  cout << "Ingrese por teclado una cadena de caracteres:"<<endl;
  getline(cin, mensaje);
  cout << "ingrese por teclado el numero de caracteres que tendra cada bloque:"<<endl;
  cin>>n;
  cout<<mensaje<<endl;
  string mensajefinal ="";
  int bloques  = mensaje.size()/n;
  string vstring[bloques+1];
  int k = 0;
  for(int i = 0;i<mensaje.size();i=i+n)
  {
  	
  	if(mensaje.substr(i,n).size() != n )
  	{
  		string m = mensaje.substr(i,n);
  		for (int j = 0; j<n-mensaje.substr(i,n).size();j++)
  		{
  			m += 'X';
  		}
  		cout<<m<<endl;
  		vstring[k] = m;
  		k++;
  		mensajefinal = mensajefinal+m;
  	}
  	else{
  		cout<<mensaje.substr(i,n)<<endl;
  		vstring[k] = mensaje.substr(i,n);
  		k++;
  		mensajefinal = mensajefinal+mensaje.substr(i,n)+'*';
  	}
  }
  cout <<mensajefinal<<endl;
  for (int i = 0 ; i< bloques+1 ; i++){
  	cout<<vstring[i]<<"|";
  }

  return 0;
}