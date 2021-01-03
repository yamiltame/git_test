#include<sstream>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#define pi (acos(-1.0))
using namespace std;

//vector de soluciones, 0 para y, 1 para dy, 2 para z y 3 para dz
double sol[4];

//valores y condiciones de frontera
int Limit=100;
double a=1.0,b=2.0,alf=2.0,bet=2.5,h,tol;

//funcion para transformar un double a string
string tostring(double i){
	stringstream s;
	s << i;
	return s.str();
	}

//funcion para pedir numero double
double getdouble(string mess){
    cout<<mess;
        double num;
        while(!(cin>>num)){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

//funcion para obtener numero entero
int getnum(string mess){
    cout<<mess;
        int num;
        while(!(cin>>num)||num<0){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

//Valor absoluto
double absolut(double x){
	if(x>=0.0){	return x;}
	else{ return -x;}
	}

//solucion exacta
double solexact(double x){
	return 1.0/x + x;}

//la funcion para y''
double f(double x, double y){
	return 2*pow(y,3)-6*y-2*pow(x,3);}

//la funcion para z''
double g(double y,double z){
	return (6*y*y -6)*z;}

//Runge Kutta orden 4
void rk4(double x,double y,double dy,double z, double dz,double h){
	//las l son del cambio en dy, las k en y, las r en z y las m en dz
	double k1,k2,k3,k4,l1,l2,l3,l4,m1,m2,m3,m4,r1,r2,r3,r4;
	l1=h*f(x,y);
	k1=h*dy;
	l2=h*f(x+0.5*h,y+0.5*k1);	
	k2=h*(dy+0.5*l1);
	l3=h*f(x+0.5*h,y+0.5*k2);
	k3=h*(dy+0.5*l2);
	l4=h*f(x+h,y+k3);
	k4=h*(dy+l3);
	r1=h*dz;
	m1=h*g(y,z);
	m2=h*g(y+0.5*k1,z+0.5*r1);
	r2=h*(dz+0.5*m1);
	r3=h*(dz+0.5*m2);
	m3=h*g(y+0.5*k2,z+0.5*r2);
	r4=h*(dz+m3);	
	m4=h*g(y+k3,z+r3);
	//los valores de las variables en x+h
	sol[0]=y+(1.0/6)*(k1+2*k2+2*k3+k4); 
	sol[1]=dy+(1.0/6)*(l1+2*l2+2*l3+l4);
	sol[2]=z+(1.0/6)*(r1+2*r2+2*r3+r4);
	sol[3]=dz+(1.0/6)*(m1+2*m2+2*m3+m4);
	}

//funcion para calcular error
double error(double x){
	return absolut(sol[0]-solexact(x));}

//funcion que ingresa los valores de la solucion en un archivo llamado name
void imprimir_solucion(double tk,double h,string name){
	int n=(int) floor((b-a)/h);
	sol[0]=alf;
	sol[1]=tk;
	sol[2]=0;
	sol[3]=1;
	//abrir un archivo con el nombre "name" para meter los valores que se mandan al graficador
	ofstream f;
	f.open(name.c_str());
	double x;
	//se hace la iteacion para encontrar los valores
	for(int i=0;i<=n;i++){
		x=a+i*h;
		rk4(x,sol[0],sol[1],sol[2],sol[3],h);
		f<<x<<" "<<sol[0]<<endl;//aqui se guardan los valores en el archivo
		}
	f.close();
	}

//funcion que hace el archivo de comandos para el graficador Gnuplot
void graficar_sol(string name){
	ofstream f;
	string graf=name+".gp";
	f.open(graf.c_str());
	f<<"set terminal latex\n";
	f<<"set output '"+name+".tex'\n";
	f<<"set size 1,1\n";
	f<<"set key noautotitle\n";
	f<<"set xlabel '$x$'\n";
	f<<"set ylabel '$y$'\n";
	f<<"plot [1:2][2:2.5] '"+name+"' w p pt 7 ps 0.4";
	f.close();
	}

//funcion que genera comandos para graficar el archivo generado por imprimir_error llamado name
void graficar_error(string name){
	ofstream f;
	string graf=name+".gp";
	f.open(graf.c_str());
	f<<"set terminal latex\n";
	f<<"set output '"+name+".tex'\n";
	f<<"set size 1,1\n ";
	f<<"set key noautotitle\n";
	f<<"set xlabel '$x$'\n";
	f<<"set ylabel 'error'\n";
	f<<"plot [1:2][0:0.02] '"+name+"' w p pt 7 ps 0.4";
	f.close();
	}

//funcion que mete valores del error en archivos llamados name
void imprimir_error(double tk,double h,string name){
	ofstream f;
	int n=(int)floor((b-a)/h);
	f.open(name.c_str());
	double x;
	sol[0]=alf; sol[1]=tk; sol[2]=0; sol[3]=1;
	for(int i=0;i<=n;i++){
		x=a+i*h;
		f<<x<<" "<<error(x)<<endl;
		rk4(x,sol[0],sol[1],sol[2],sol[3],h);}
	f.close();
	}

//funcion del disparo
void Disparo(double h,double tol,int Limit){
	int k,N=(int) floor((b-a)/h);
	string name;
	double x,tk,dtheta;
//se proponen 10 angulos de disparo que van desde pi/4 hasta -pi/4 
	dtheta=pi/(2*10);
//Ciclo de los angulos de disparo
	for(double theta=pi/4;theta>=-pi/4;theta-=dtheta){
		tk=tan(theta); //la pendiente es la tangente del angulo
		k=1;
		cout<<"******valor inicial tk="<<tk<<"******"<<endl;
		//ciclo para el metodo del disparo
		while(k<=Limit){
			//valores iniciales
			sol[0]=alf;	sol[1]=tk;	sol[2]=0;	sol[3]=1;
			x=a;
			//ciclo de Rk4
			for(int i=0;i<=N;i++){
				x=a+i*h;
				rk4(x,sol[0],sol[1],sol[2],sol[3],h);
				}
			//verificar si la solucion con el parametro tk esta cerca de la cond de frontera
			if(absolut(sol[0]-bet)<tol){
			//definir la etiqueta del nombre con los valores de h y de tol
			//despues se llaman las funciones para imprimir valores y para generar las graficas
				name="_tol"+tostring(tol)+"_h"+tostring(h);
				imprimir_solucion(tk,h,"solucion"+name);
				imprimir_error(tk,h,"error"+name);
				graficar_error("error"+name);
				graficar_sol("solucion"+name);
				cout<<"Se encontro solucion usando tk="<<tk<<endl;
				break;
				}
			//checar que no se anule la derivada de la solucion respecto al tiempo.
			if(absolut(sol[3])<=1.0e-20){
				cout<<"la derivada de y respecto al parametro t es cero :( \n";
				break;
				}
			k+=1;
			//Newton raphson para el valor de tk
			tk=tk-(sol[0]-bet)/sol[2];
			}
		//salir si ya encontro la solucion
		if(absolut(sol[0]-bet)<tol){ break;}
		}
	//no se encuenta solucion con la tolerancia
	if(absolut(sol[0]-bet)>tol){
		cout<<"se excedio el limite de iteraciones y no hay t entre (pi/4,-pi/4) :("<<endl;
		}
	}

//menu que utilice para hacer las diferentes pruebas
void menu(){
	int opc;
	cout<<"****El intervalo es de 1 a 2 y las cond de frontera son y(1)=2 y y(2)=5/2 para la ecuacion y''=2y^3-6y-2x^3****\n";
	cout<<"opciones\n";
	cout<<"1.Fijar intervalo y Cond de frontera  2.Nuevo disparo  3.ver archivos 4.Generar graficas 5.borrar archivos 6.Salir\n";
	opc=getnum("");
	switch(opc){
		case 1:
			a=getdouble("ingresa inicio de intervalo: ");
			b=getdouble("ingresa fin de intervalo: ");
			alf=getdouble("ingresa condicion frontera 1: ");
			bet=getdouble("ingresa condicion frontera 2: ");
			Limit=getnum("Maximo de iteraciones: ");
			break;
		case 2:
			h=getdouble("ingresa el paso en x: ");
			tol=getdouble("ingresa tolerancia: ");
			Disparo(h,tol,Limit);
			break;
		case 3:
			system("ls error*");
			system("ls solucion*");
			break;
		case 4:
			system("gnuplot *.gp");
			break;
		case 5:
			system("rm error*");
			system("rm solucion*");
			break;
		case 6:
			exit(1);
		default:
			cout<<"opcion invalida\n";
			break;
		}
	}

int main(){
	//lamada al menu
	for(;;){menu();}}


