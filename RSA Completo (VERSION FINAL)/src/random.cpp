#include "random.h"

void random::fillWithMemoryInfo(){
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    if (EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        cProcesses = cbNeeded / sizeof(DWORD);
        for (int i = 100; i < cProcesses; i++){
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, aProcesses[i]);
            if (NULL != hProcess){
                PROCESS_MEMORY_COUNTERS pmc;
                if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
                    processInfo+=(to_string(pmc.PageFaultCount)+to_string(pmc.WorkingSetSize)+
                                  to_string(pmc.QuotaPagedPoolUsage)+to_string(pmc.QuotaNonPagedPoolUsage)+to_string(pmc.PeakPagefileUsage));
                }
            }
            CloseHandle(hProcess);
        }
    }
}
vector<int> random::generateSeed(){
    if((processInfo.size()<contador+15)||processInfo.empty()){
        processInfo.clear();
        fillWithMemoryInfo();
        contador=0;
    }
    vector<int> k;
    for(int i=0, j=contador;i<5;i++,j+=3){
        int n=stoi(processInfo.substr(j,3));
        while(n>255) n>>=1;
        while(n<128) n<<=1;
        k.push_back(n);
    }
    contador+=15;
    return k;
}
vector<bool> random::RC4(vector<int> semilla){
    vector<int> Or;
    {//permite que s solo pertenezca a este scope
        vector<int> S;
        for(int i=0;i<256;i++) S.push_back(i);
        {//permite que k solo exista en este scope, optimiza memoria
            vector<int> K;
            for(int i=0,k=0;i<=51;i++)
                for(int j=0;j<5;j++,k++)
                    K.push_back(semilla[j]);
            for(int i=0,f=0;i<256;i++){
                f=modint(f+S[i]+K[i], 256);
                swap(S[i],S[f]);
            }
        }
        for(int i=0,f=0,k=0;k<8;k++){
            i=modint(i + 1, 256);
            f=modint(f+S.at(i), 256);
            swap(S.at(i),S.at(f));
            Or.push_back(S.at(modint(S.at(i) + S.at(f), 256)));//t
        }
    }
    vector<bool> out;
    for(int i=0;i<8;i++){
        bitset<8> aux(Or[i]);
        for(int j=0;j<8;j++)
            out.push_back(aux[j]);
    }
    return out;
}
void random::izqRotate(vector<bool> &vec, int times){
    vec.insert(vec.end(),vec.begin(),vec.begin()+times);
    vec.erase(vec.begin(),vec.begin()+times);
}
vector<bool> random::DES(int bits){
    vector<bool> K;//para guardar todas las k
    {
        vector<bool>k=RC4(generateSeed());
        int nBits=bits/48+1;
        vector<bool> c; vector<bool> d;
        for(int i=0;i<28;i++) c.push_back(k.at(PC_1[i]));
        for(int i=28;i<56;i++) d.push_back(k.at(PC_1[i]));
        for(int i=0;i<nBits;i++){
            izqRotate(c,rotaciones[i]);
            izqRotate(d,rotaciones[i]);
            vector<bool> both(c.begin(),c.end());
            both.insert(both.end(),d.begin(),d.end());
            for(int i=0;i<48;i++) K.push_back(both.at(PC_2[i]));
        }
    }
    K.resize(bits);//elimina valores extra del vector de bool
    K[0]=1; K[bits-1]=1;//asegura que el numero que retorna sea impar y de n bits
    return K;
}
ZZ random::Random_Number(vector<bool> vec){
    ZZ salida(0);
    ZZ i(1);
    for(vector<bool>::reverse_iterator it=vec.rbegin();it!=vec.rend();++it){
        if(*it) salida+=i;
        i<<=1;
    }
    return salida;
}//convierte un vector booleano a ZZ tomandolo como numero binario
ZZ random::generate_random(int bits){
    return Random_Number(DES(bits));
}
bool Miller_Rabin(ZZ d, ZZ n){
    ZZ a; a=2;
    ZZ x = Power_mod(a, d, n);
    if (x == 1  || x == n-1)return true;
    while (d != n-1){

        x = modulo((x * x), n);
        d *= 2;
        if (x == 1)return false;
        if (x == n-1)return true;
    }

    return false;
}
bool isPrime(ZZ n){
    ZZ k; k=0;
    if (n <= 1 or n == 4)return false;
    if (n <= 3)return true;

    ZZ d = n - 1;
    while (even(d)){
        //d /= 2;
        d >>= 1;
        k++;
    }
    for (int i = 0; i < k+1; i++)
        if (!Miller_Rabin(d, n))
            return false;

    return true;
}
ZZ gen_prime(ZZ n){//encuentra el primo mas cercano a un numero aleatorio
    //ZZ n= op.generate_random(bits);
    ZZ a= modulo(n, ZZ(6));
    n-=a+ZZ(5); //para obtener la forma 6n+5
    //los numeros primos tienen la forma de 6n+1 y 6n+5, no necesariamente todos los numeros obtenidos con esa
    if(isPrime(n)) return n;//si es primo retorna ese valor
    else{//caso contrario busca los siguientes numeros de la forma 6n+1 y 6n+5 hasta encontrar un primo
        while(true){
            n+=2;
            if(isPrime(n)) return n;
            n+=4;
            if(isPrime(n)) return n;
        }
    }
}
