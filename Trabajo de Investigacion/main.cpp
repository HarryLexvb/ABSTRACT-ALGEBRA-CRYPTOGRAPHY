#include <iostream>
#include <NTL/ZZ.h>
#include <chrono>
using namespace NTL;
using namespace std;

//OPERACIONES
ZZ mod(ZZ a,ZZ b){
    ZZ r=a-(b*(a/b));
    if(r<0)r=b-r;
    return r;
}
bool even(ZZ a){
    if(mod(a,ZZ(2))==0) return 1;
    return 0;
}
ZZ ValAbs(ZZ a){
    if (a<0) return (a*-1);
    return a;
}

//ALGORITMOS PARA HALLAR EL GCD
ZZ Euclides_Clasico(ZZ x, ZZ y){

    ZZ r;
    int loop=0;
	if(x == ZZ(0)) return y; //cout << "\ngcd: " << y << endl;
	else{
		while(y != ZZ(0)){
			r = mod(x,y);
			x = y;
			y = r;
			loop++;
			//cout << " x: "<<x<<" y: "<<y<<" r: "<<r<<endl;
		}
	}
	//cout << "\nloop: " << loop << endl;
	return x;
	//cout << "\ngcd: " << x << endl;
}
ZZ Bishop_GCD(ZZ x, ZZ y){
    //int loop=0;
    ZZ temp;
        while (x != y){
            if(x > y)
                x = x - y;
            else{
                temp = y;
                y = x;
                x = temp;
            }
            //loop++;
            //cout << " x: "<<x<<" y: "<<y<<" temp: "<<temp<<endl;
        }
        //cout << "loop: "<< loop << endl;
    return x;
}
ZZ Euclides_Menor_Resto(ZZ x, ZZ y){
    ZZ c,d, r;
    //int loop=0;
      if(x==0){
        c=y;
      }
      else{
        c=x;d=y;
        while(d!=0){
          float aux1=0,aux2=0;
          conv(aux1, c);conv(aux2, d);
          float aux=aux1/aux2+0.5;
          r=c-(d*ZZ(aux));
          //cout<<c<<"="<<d<<"*"<<ZZ(aux)<<"+("<<r<<")"<<endl;
          c=d;
          d=abs(r);
          //loop++;
        }
      }
      //cout << "loop: " << loop << endl;
    return abs(c);
}
ZZ GCD_Binario(ZZ x, ZZ y){
    ZZ g=ZZ(1);
    int loop1=0, loop2=0;
    while(even(x)&&even(y)){
        x=x/2;
        y=y/2;
        g=2*g;
        //cout<<"x: "<<x<<" y: "<<y<<" g: "<<g<<endl;
        loop1++;
    }
    while(x!=0){
        while(even(x)){
            x/=2;
            //cout<<"x: "<<x<<endl;
        }
        while(even(y)){
            y/=2;
           // cout<<"y: "<<y<<endl;
        }
        ZZ t=ValAbs((x-y))/2;
        //cout<<"t: "<<t<<endl;
        if(x>=y) x=t;
        else y=t;
        loop2++;
        //cout<<"x: "<<x<<" y: "<<y<<endl;
    }
    cout << "\nloop: "<<loop1+loop2;
    //return (g*y);
}
ZZ GCD_Lehmer(ZZ x, ZZ y){
    ZZ A = ZZ(1), B = ZZ(0), C = ZZ(0), D = ZZ(1);
	ZZ q;
	int loop=0;
	while(y+C != ZZ(0) and y+D != ZZ(0)){
		q = (x+A) / (y+C);
		if(q != (x+B) / (y+D)) break;
		ZZ t = A - q*C;

		A = C;
		C = t;
		t = B-q*D;
		B = D;
		D = t;
		t = x-q*y;
		x = y;
		y = t;
		//cout << "[" << A << "," << B << "," << C << "," << D << "]" << endl;
		loop++;
	}
	if(B == ZZ(0))
	{
		ZZ t = mod(x,y);
		x = y;
		y = t;
	}
	else
	{
		ZZ t = A*x + B*y;
		ZZ u = C*x + D*y;
		x = t;
		y = u;
	}
	cout << "\nloop: "<<loop;
	return ValAbs(Euclides_Clasico(x,y));

}

//ALGORITMOS EXTENDIDOS PARA HALLAR LOS COEFICIENTES DE BEZOUT
ZZ Extendido_Euclides_clasico(ZZ a,ZZ b){
    ZZ x,y;
    ZZ q=a/b;
	ZZ x1=ZZ(1);ZZ x2=ZZ(0);ZZ y1=ZZ(0);ZZ y2=ZZ(1);
    ZZ r=a-(q*b);x=x1-(q*x2);
	y=y1-(q*y2);
	int loop = 0;
	while(r>0){
        q=a/b;
		r=a-(q*b);
		x=x1-(q*x2);
		y=y1-(q*y2);
		a=b;
		b=r;
		x1=x2;
		x2=x;
		y1=y2;
		y2=y;
		loop++;
		//cout<<"x:"<<x<<"  y:"<<y<<endl;
	}
	ZZ d=a;x=x1;y=y1;
	cout << "loop: " << loop << endl;
	return d;
}
ZZ Binario_Extendido(ZZ x, ZZ y){
    ZZ g=ZZ(1); ZZ a, b;
    //int loop1 = 0, loop2 = 0, loop3=0;
    while(x == y){
        x = x/2;
        y = y/2;
        g = g*2;
    }
    ZZ u=x, v=y,A=ZZ(1), B=ZZ(0), C=ZZ(0), D=ZZ(1);
    //cout<< "\tu: " << u << "\tv:"  << v << "\tA: " << A << "\tB: " << B << "\tC: " << C << "\tD: " << D <<endl;
    while(u!=0){
        while(even(u)){
          u = u/2;
          if(even(A) and even(B)){
            A = A/2;
            B = B/2;
          }else{
            A = (A+y)/2;
            B = (B-x)/2;
          }
          //loop1++;
         // cout<< "\tu: " << u << "\tv:"  << v << "\tA: " << A << "\tB: " << B << "\tC: " << C << "\tD: " << D <<endl;
        }
        while(even(v)){
          v = v/2;
          if(even(C) and even(D)){
            C = C/2;
            D = D/2;
          //  cout<< "\tu: " << u << "\tv:"  << v << "\tA: " << A << "\tB: " << B << "\tC: " << C << "\tD: " << D <<endl;
          }else{
            C = (C+y)/2;
            D = (D-x)/2;
           // cout<< "\tu: " << u << "\tv:"  << v << "\tA: " << A << "\tB: " << B << "\tC: " << C << "\tD: " << D <<endl;
          }
         // loop2++;
        }
        if(u >= v){
          u=u-v;
          A = A-C;
          B = B-D;
         // cout<< "\tu: " << u << "\tv:"  << v << "\tA: " << A << "\tB: " << B << "\tC: " << C << "\tD: " << D <<endl;
        }else{
          v= v-u;
          C = C-A;
          D = D-B;
         // cout<< "\tu: " << u << "\tv:"  << v << "\tA: " << A << "\tB: " << B << "\tC: " << C << "\tD: " << D <<endl;
        }
        if(u==0){
          a = C;
          b = D;
          cout<< "\tu: " << u << "\tv:"  << v << "\tA: " << A << "\tB: " << B << "\tC: " << C << "\tD: " << D <<endl;
        }
        //loop3++;
    }
    //cout<<"\n\t"<<x<<"("<<a<<")"<<"+"<<y<<"(" <<b<<")"<<"="<<v<<endl;
    //cout<<"\n\tGCD: "<< v <<endl;
    //cout<<"\tinversa: "<< a <<endl;
    //cout<<"\tloops: "<<loop1+loop2+loop3<<endl;
}
ZZ Extendido_Euclides_clasico_Recursivo(ZZ a, ZZ b, ZZ &x, ZZ &y, int &loop){
    //int loop=0;
     if(b == 0) {
     	x = ZZ(1);
        y = ZZ(0);
        //cout << a << endl;
        return a;
     }
     ZZ x1, y1, gcd = Extendido_Euclides_clasico_Recursivo(b, mod(a, b), x1, y1, loop);
     x = y1;
     y = x1 - (a/b) * y1;
     //cout << a << "(" << x << ") + " << b << "(" << y << ")" << "=" << gcd << endl;
     loop++;
     cout << "loop: " << loop << endl;
     return gcd;
}


int main(){

    ZZ x, y, a, b;
    int loop;
    /*cout << "ingrese x: "; cin >> x;
    cout << "ingrese y: "; cin >> y;*/

    /*x = conv<ZZ>("55079");
    y = conv<ZZ>("      ");// */

    /*x = conv<ZZ>("2405004167");
    y = conv<ZZ>("4081426379");// */

    /*x = conv<ZZ>("13899400287462393527");
    y = conv<ZZ>("13035181278446413343");// */

    /*x = conv<ZZ>("265733069836953021104589357293605940039");
    y = conv<ZZ>("332093142905007608776794843088220507747");// */

    /*x = conv<ZZ>("105418067230565229302401311614871856367337516926256261485610678970677326732123");
    y = conv<ZZ>("109042293343390780898239761338683269501466118148801677941583896581390895389239");// */

    /*x = conv<ZZ>("11067322688211763879127710781245770200266306579753149074670002771714059738841730056577765602839652195914873916936503030794140872851579504321364488742771259");
    y = conv<ZZ>("11413516010680777814127384311343725781113107913880221060918602136572207390773303280373413580351741864077594704984792022532979242718201697029247306420150367");// */

    /*x = conv<ZZ>("176656997303223902095560256491598180971380732993768921435351520271158961476748001277698565063028402764520109441247809203999420881922890353371040260979842426191177375275250990256146658405602103682083965762652790303682088948560995391904786385195323037525430801172918718937212475657313929650740839978361468109599");
    y = conv<ZZ>("115070940564609423248950030308388484379204458289391497531947979334249712955615806939521605721699749247585667798917677595682175003116940937714937814558746224442425625787010823518213049307194832092930084692458264138375677683938736736248673533557569390517618829849378633863611659739654707321890843736110745090553");// */

    /*x = conv<ZZ>("176656997303223902095560256491598180971380732993768921435351520271158961476748001277698565063028402764520109441247809203999420881922890353371040260979842426191177375275250990256146658405602103682083911507094056460942324895003030838848437920445828939149753194797933424971295561580693952160572169974924758566779891767759568217500311694093771493781455874622444242562578701082351821304930719483209293008469245826413837567768393873673624867353355756939051761882984937863386361165973965470732189084373611074509055365762652790303682088948560995391904786385195323037525430801172918718937212475657313929650740839978361468109599");
    y = conv<ZZ>("115070940564609423248950030308388484379204458289391497531947979334249712955615806939521605721699749247585667798917677595682175003116940937714937814558746224442425625787010823518213049307194832092930084692458264131766569973032239020955602564915981809713807329937689214353515202711589614767480012776985650630284027645201094412478092039994208819228903533710402609798424261911773752752509902561466584056021036820839657626527903036820889485609953919047863851953230375254308011729187189372124756573139296507408399783614681095998375677683938736736248673533557569390517618829849378633863611659739654707321890843736110745090553");// */

    //cout << "Euclides Clasico (GCD): " << Euclides_Clasico(x,y) << endl;
    //cout << "Bishop's algorithm GCD: " << Bishop_GCD(x, y) << endl;
    //cout << "Euclides con el menor resto (GCD): " << Euclides_Menor_Resto(x,y) << endl;
    //cout << "Binario GCD: " << GCD_Binario(x,y) << endl;
    //cout << "Lehmer GCD: " << GCD_Lehmer(x,y) << endl;


    //cout << "Euclides extendido clasico: " << Extendido_Euclides_clasico(x,y) << endl;
    //cout << "Binario extendido: " << Binario_Extendido(x,y) << endl;
    //cout<<"euclides extendido recursivo clasico";
    //Extendido_Euclides_clasico_Recursivo(x,y,a,b,loop);
    return 0;
}

