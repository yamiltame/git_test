#include<string>
#include<iostream>
#include<fstream>
#include <math.h>
using namespace std;

double getdouble(string mess){    //metodo para obtener un numero doble del usuario
	cout<<mess;
        double num;
        while(!(cin>>num)){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

int getnum(string mess){	//metodo para obtener entero del usuario
	cout<<mess;
        int num;
        while(!(cin>>num)||num<0){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

double absolut(double x){
	if(x>=0){return x;}
	else{return -x;}
	}

//Declarar la funcion
double Funcion(double x,double r){
	return x+(r*x)/(1+x*x);}

//la derivada de la funcion
double derivada(double x,double r){
	return 1+(r*(1-x*x))/((1+x*x)*(1+x*x));}

//Newton-Raphson
double Newton(int Nmax,double tol,double xinit,double r){
	int i=0;
	double temp,deri,fx,x;
	temp=xinit;
	fx=Funcion(xinit,r);
	if(absolut(fx)<tol){
		printf("la propuesta %e es la raiz con tolerancia %e\n",xinit,tol);
		return xinit;}
	for(i=0;i<Nmax;i++){
		deri=derivada(temp,r);
		if(absolut(deri)<1.0e-8){
			cout<<"la derivada se anula, no se puede usar Newton\n";
			return 0;}
		x=temp-(fx/deri);
		fx=Funcion(x,r);
		if(absolut(fx)<tol){break;} //si la aproximacion corresponde a la tolerancia
		temp=x;}
	return x;
	}

void DiagBif(){ //metodo para crear el diagrama puntos fijos vs r
	double aprox,x;
	ofstream Diagrama;
	Diagrama.open("Bifurcacion.dat");
	for(double R=-5;R<0;R+=0.1){ 
		aprox=sqrt(absolut(R)); //la aproximacion de la raiz 
		x=Newton(1000,1.0e-8,aprox,R); //raiz positiva
		Diagrama<<R<<" "<<x<<endl;
		x=Newton(1000,1.0e-8,-aprox,R); //raiz negativa
		Diagrama<<R<<" "<<x<<endl;
		}
	Diagrama.close();
	Diagrama.open("diag.gp");	//crear archivo para ejecutar en gnuplot
	Diagrama<<"set terminal latex\n";
	Diagrama<<"set output 'diagrama.tex'\n";
	Diagrama<<"set size 1,1\n";
	Diagrama<<"set xlabel '$r$'\n";
	Diagrama<<"set ylabel '$x_f$'\n";
	Diagrama<<"set key noautotitle\n";
	Diagrama<<"plot [-5:0][-3:3] 'Bifurcacion.dat' w p pt 7 ps 0.4"; //comandos del archivo
	Diagrama.close();
	system("gnuplot -p diag.gp");	//ejecutar el archivo .gp
	}
	
int main(){
	cout<<"programa que genera diagrama de bifurcacion\n";
	DiagBif();
	}
