//MAURICIO YAMIL TAME SORIA

#include<math.h>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

//Método para obtener valores double
double getdouble(string mess){
    cout<<mess;
        double num;
        while(!(cin>>num)){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

//método para obtener valores enteros
int getnum(string mess){
    cout<<mess;
        int num;
        while(!(cin>>num)||num<0){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

//En este arreglo se guarda la información de la tarea
double Tarea[15]={5,10,15,20,25,0,0,0,0,0,0,0,0,0,0};

//Definición de la función y su segunda derivada
double funcion(double x){
	return x*exp((-1)*pow(x,2));}

double segundaderivada(double x){
	return funcion(x)*(4.0*x*x-6.0);}

//Función para calcular error
double error(int n,double a,double b){
	double s=0,h=(b-a)/n,x,xp;
	for(int i=0;i<n;i++){
		x=a + h*i;
		xp=x+(h/2);
		s=s+(-1)*(pow(h,3)/12)*segundaderivada(xp);}
	return s;}

//Función para calcular integral
double integraltrape(int n, double a, double b){
	double h=(b-a)/n;
	double s=0,x;
	for(int i=1;i<n-1;i++){
		x=a + h*i;
		s=s+funcion(x);}
	return (h/2)*(funcion(a)+funcion(b)+2*s);}

int main(){
	int i;
	double a=getdouble("Ingresa la cota inferior: ");
	double b=getdouble("Ingresa la cota superior: ");
	int n=getnum("Ingresa el número de divisiones: ");
	double T[3];
	T[0]=n;
	T[1]=integraltrape(n,a,b);
	T[2]=error(n,a,b);
	cout<<"Numero \t\t Trapecio \t\t error \n";
	cout<<T[0]<<"\t\t"<<T[1]<<"\t\t"<<T[2]<<"\n\n";
	cout<<"Tarea3 \n";
	for(i=0;i<5;i++){
		Tarea[i+5]=integraltrape(Tarea[i],0,1);
		Tarea[i+10]=error(Tarea[i],0,1);}
	cout<<"Numero \t Trapecio \t error \n";
	for(i=0;i<5;i++){
		cout<<Tarea[i]<<"\t"<<Tarea[i+5]<<"\t"<<Tarea[i+10]<<"\n";}	
	}//Fin main
