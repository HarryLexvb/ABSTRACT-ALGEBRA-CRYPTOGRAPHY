#include "rsa_bloques.h"
random op;
rsa_bloques::rsa_bloques(int bits){///Receptor
  //  /* Facilita probar los codigos mas rapido
    //p=conv<ZZ>("108776036190683125259463315757430245625525312593546616668643598590932771108650796945581974872535570332057355593826090881253878928018114750565789605068898232690842555075116446815818897787183885828920819037890482111477651155264381473788132512875594040823847775896835568222497449478860229556510185019295768539319");
    //q=conv<ZZ>("111865624863031611994490063878968580065071539940086595658104065283585135372559071988047118201657245668913010399160074981863053503890491251214931099083738308245216199415497469023772910080463512725105033694564784810696391221560679781496366785039775869202698291877451783276076780104602636543374079304028450952933");
    //e=conv<ZZ>("102218363580183243384579267083585257899720518442722532426853795928225678165982017328810556452659264551773048164374948847617516079105144944698161665571968445484599365282052626874100374175050978020718756342386026933740585325906160670741666221454325280467817822456036299247619786019917474276214257367099988838885");
    p=conv<ZZ>("103767481798130426943995805599796394847063847823750403647868852813510902073395587637756632063374877087499410609518952666037266661355260367558734312382007064218293165948804640577762154701319376528625284091993157404525619248415131538936565661587816874185087165074020260271251970314274017524130706107570158569711");
    q=conv<ZZ>("139929917759681976362895984899789603471939859059225217369641719257072901229826441583161882480672513028228015646811229759646049992631111945532603760585138667730781783727210827035746041333166145404995197315842885558301228766310430485416829503136276781097647666421240826023957296196096850534489114872366109766213");
    e=conv<ZZ>("97363372599778328111187566118117123485958166734803945806560215965410447596406657422747119993278739180835811617344475023867117085039066988721524576471243749007185932080581196081686829444016103745089837896867228555676290171578386142767649559548866631357066645949924167715763474536721681069466103303011219605363");
    //*/
    /*
    p=gen_prime(op.generate_random(bits));
    q=gen_prime(op.generate_random(bits));//*/
    n=p*q;
    PhiN=(p-1)*(q-1);
    /*
    do{
        e=op.generate_random(bits);
    }while(!Existe_Inversa(e,PhiN));//*/
    d=inversa(e,PhiN);
    cout<<"VALORES \nn "<<n<<"\ne "<<e<<endl;
    cout<<"p "<<p<<"\nq "<<q<<"\nfiN "<<PhiN<<"\nd "<<d<<endl;
}
rsa_bloques::rsa_bloques(ZZ n,ZZ e){
    this->n=n;
    this->e=e;
    cout<<"VALORES \nn "<<n<<"\ne "<<e<<endl;
}
string rsa_bloques::completarCeros(string mensaje,ZZ Nr ){
    int digit =ZZtoStr(Nr).size()-1;
    int c = modint(mensaje.size(),digit);//las letras que no llegan a completar un bloque
    string cero(digit-c,'0');//la cantidad de 0s que faltan
    //cout << "\ncero: \n" << cero << "\n" << endl;
    return cero+mensaje;
}
string rsa_bloques::dividirBloques(string mensaje){
    int digit=to_string(alfabeto.size()).size();//numero de digitos del alfabeto
    string str;
    {
        string cero(digit,'0');//string hecha de 0 para completar
        for(int i=0;i<mensaje.size();i++){
            size_t pos=alfabeto.find(mensaje.at(i));
            int len=to_string(pos).size();//la longitud del numero
            if(len<digit) str+=cero.substr(0,digit-len);//completa los 0
            str+=to_string(pos);
        }
    }
    digit=ZZtoStr(n).size()-1;
    while(modint(str.size(),digit)) str+="22";//W
    return str;
}
string rsa_bloques::encrypt(string mensaje, ZZ Nr, ZZ Er){
    int digit=ZZtoStr(Nr).size()-1;
    string out;
    for(int i=0; i < mensaje.size(); i+=digit){
        ZZ p(conv<ZZ>(mensaje.substr(i, digit).c_str()));//Selecciona cada x digitos
        p=Power_mod(p,Er,Nr);//Con los valores de la segunda persona
        string ceros((digit+1-ZZtoStr(p).size()),'0');
        out+=ceros+ZZtoStr(p);
    }
    return out;
}
string rsa_bloques::encryptD(string mensajeNo){
    int digit=ZZtoStr(n).size()-1;
    string out;
    for(int i=0;i<mensajeNo.size();i+=digit){
        ZZ c(conv<ZZ>(mensajeNo.substr(i,digit).c_str()));
        c=TRC(c);//Se realiza una segunda version para optimizar con el TRC y mayor velocidad
        string ceros((digit+1-ZZtoStr(c).size()),'0');
        out=out+ceros+ZZtoStr(c);
        //cout << "\nel valor de c es: \n" << c << "\n" << endl;
    }
    return out;
}
string rsa_bloques::decrypt(string mensaje){
    string salida;
    int digitN=ZZtoStr(n).size();
    int digit=digitN-1;
    for(int i=0;i<mensaje.size();i+=digitN){
        ZZ c(conv<ZZ>(mensaje.substr(i,digitN).c_str()));
        c=TRC(c);
        string ceros((digit-ZZtoStr(c).size()),'0');
        salida+=ceros+ZZtoStr(c);
    }
    return salida;
/*
    digit=to_string(alfabeto.size()).size();
    string outLetters;
    for(int i=0;i<salida.size();i+=digit){
        outLetters+=alfabeto.at(stoi(salida.substr(i,digit)));
    }
    return outLetters; //*/
}
string rsa_bloques::decryptE(string mensajeNo, ZZ Ne, ZZ Ee){
    int a= modint(mensajeNo.size(), ZZtoStr(Ne).size());
    mensajeNo = mensajeNo.substr(a);//Ya que en el encrypt se aumentan 0s, se retiran los ceros de adelante para retornar a bloques de Ne
    string salida;
    int digit=ZZtoStr(Ne).size()-1;
    {int digitN=digit+1;//Evitar hacer la suma en cada iteracion
        for(int i=0; i < mensajeNo.size(); i+=digitN){
            ZZ c(conv<ZZ>(mensajeNo.substr(i, digitN).c_str()));
            c=Power_mod(c,Ee,Ne);
            string ceros((digit-ZZtoStr(c).size()),'0');
            salida+=ceros+ZZtoStr(c);
        }}
    digit=to_string(alfabeto.size()).size();//Retorna los numeros nuevamente a las letras
    string outLetters;
    for(int i=0;i<salida.size();i+=digit){
        outLetters+=alfabeto.at(stoi(salida.substr(i,digit)));
    }
    return outLetters;
}
string rsa_bloques::ZZtoStr(ZZ z){
    stringstream ss;
    ss<<z;
    return ss.str();
}
ZZ rsa_bloques::TRC(ZZ M){
    ZZ q1= inversa(modulo(q, p), p);
    ZZ a1= Power_mod(modulo(M, p), modulo(d, p - 1), p);//Dp,dp,p
    ZZ q2= inversa(modulo(p, q), q);
    ZZ a2= Power_mod(modulo(M, q), modulo(d, q - 1), q);
    return modulo(modulo(a1 * q * q1, n) + modulo(a2 * p * q2, n), n);
}
string rsa_bloques::sign_encrypt(string mensajeL, ZZ Nr, ZZ Er){
    string aux = encryptD(dividirBloques(mensajeL));///rubrica
    //cout << "\n\ncomplatar 0: "<<encrypt(completarCeros(aux, Nr), Nr, Er) << "\n" << endl;
    return encrypt(completarCeros(aux, Nr), Nr, Er);///Completa 0s para convertir en bloques del receptor
}
string rsa_bloques::remove_sign(string mensaje, ZZ Ne, ZZ Ee){
    //Accion opuesta a la firma y encrypt
    return decryptE(decrypt(mensaje), Ne, Ee);
}
