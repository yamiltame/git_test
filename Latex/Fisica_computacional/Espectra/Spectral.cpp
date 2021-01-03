#include<sstream>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#define PI (acos(-1.0))
using namespace std;

//vector para calcular los polinomios de Chebyshev
double T[3];
int N,Pasostiempo;
double *A,*A1,*A2;

//funcion inicial
double finit(double x){
	return 0.5*(-(x*x) + 1.0);
	}

//Funcion que calcula el polinomio de Chebyshev de grado n en x
double Cheby(int n, double x){
	if (n==0){ return 1;}
	if (n==1){ return x;}
	T[0]=1.0;
	T[1]=x;
	for(int i=2;i<n;i++){
		T[2]=2*x*T[1]-T[0];
		T[0]=T[1];
		T[1]=T[2];
		}
	return 2*x*T[1]-T[0];
	}

//funcion para coef a(0)
double funcion(int k, double x){
	cout<<x<<"\t"<<k<<"\t"<<0.5*Cheby(k,x)*sqrt(1-x*x)<<endl;;
	return 0.5*Cheby(k,x)*sqrt(1-(x*x));
	}

//Funcion para calcular integrales
double integraltrape(int n,int k,double a, double b){
    double h=(b-a)/n;
    double s=0.0;
	double x;
    for(int i=0;i<n;i++){
        x=a + h*i;
        s+=(h/2)*(funcion(k,x)+funcion(k,x+h));}
    return s;
	}

//calcular coeficientes a(0)
void coefiniciales(){
	int i;
	A[0]=(1.0/PI)*integraltrape(20000,0,-1.0,1.0);
	for(i=1;i<=N;i++){
		A[i]=(2.0/PI)*integraltrape(20000,i,-1.0,1.0);}
	}

void coeficientes(double y[]){
	int i;
	A1[N]=0;
	A1[N-1]=2*N*y[N];
	for(i=N-2;i>0;i--){
		A1[i]=A1[i+2] + 2*(i+1)*y[i+1];}
	A1[0]=(0.5)*(A1[2]+2*y[1]);
	A2[N]=0; A2[N-1]=0; 
	for(i=N-2;i>0;i--){
		A2[i]=A2[i+2] + 2*(i+1)*A1[i+1];}
	A2[0]=(0.5)*(A2[2] + 2*A1[1]);
	}

double sumapares(double C[]){
	double y=0.0;
	int i;
	if(N%2==0){
		for(i=0;i<=(N-2)/2;i++){
			y+=C[2*i];}
		}
	else{
		for(i=0;i<=(N-3)/2;i++){
			y+=C[2*i];}
		}
	return y;
	}

double sumaimpares(double C[]){
	double y=0.0;
	int i;
	if(N%2==0){
		for(i=1;i<=(N-2)/2;i++){
			y+=C[2*i-1];}
		}
	else{
		for(i=0;i<=(N-3)/2;i++){
			y+=C[2*i+1];}
		}
	return y;
	}
	
void derivadas(double t, double y[], double f[]){
	for(int i=N-2;i>=0;i--){
		f[i]=A2[i];}
	}

void Rk4(double y[],int n, double h, double yout[],double t,void 
(*derivadas)(double t, double y[],double f[])){
	double *k1,*k2,*k3,*k4;
	double *ytemp,*f;
	int j;
	k1=new double[n+1];
	k2=new double[n+1];
	k3=new double[n+1];
	k4=new double[n+1];
	f=new double[n+1];
	ytemp=new double[n+1];
	derivadas(t,y,f);
	for(j=0;j<n+1;j++){
		k1[j]=h*f[j];
		ytemp[j]=y[j] + 0.5*k1[j];}
	derivadas(t+0.5*h,ytemp,f);
	for(j=0;j<n+1;j++){
		k2[j]=h*f[j];
		ytemp[j]=y[j]+0.5*k2[j];}
	derivadas(t+0.5*h,ytemp,f);
	for(j=0;j<n+1;j++){
		k3[j]=h*f[j];
		ytemp[j]=y[j]+k3[j];}
	derivadas(t+h,ytemp,f);
	for(j=0;j<n+1;j++){
		k4[j]=h*f[j];}
	for(j=0;j<n+1;j++){
		yout[j]=y[j]+(1.0/6.0)*(k1[j]+2.0*k2[j]+2.0*k3[j]+k4[j]);}
	delete[] k1;	
	delete[] k2;	
	delete[] k3;	
	delete[] k4;	
	delete[] ytemp;	
	delete[] f;
	}
	
//funcion para transformar un double a string
string tostring(double i){
	stringstream s;
	s << i;
	return s.str();
	}

double funcionu(double C[],double x){
	double y=0.0;
	int i;
	for(i=0;i<=N;i++){
		y+=C[i]*Cheby(i,x);}
	return y;
	}


void puntosCheby(double C[],string name){
	int i,j;
	double t=0.0;
	double *yout;
	yout=new double[N+1];
	ofstream f;
	f.open(name.c_str());
	double y,x,dx=0.002;
	for(x=-1.0;x<=1.0;x+=dx){
		f<<x<<" "<<funcionu(C,x)<<endl;}
	delete[] yout;
	f.close();
	}

void imprimir(double y[],string mensaje){
	cout<<mensaje<<endl;
	for(int i=0;i<N+1;i++){
		cout<<y[i]<<endl;}
	}

void printrk4(string name){
	double *yout;
	yout=new double[N+1];
	ofstream f;
	f.open(name.c_str());
	coefiniciales();
	imprimir(A,"coeficientes iniciales");
	coeficientes(A);
	imprimir(A2,"A2 iniciales");
	double t=0.0;
	for(t=0.0;t<=4;t+=0.02){
		Rk4(A,N-2,0.02,yout,t,derivadas);
		if(N%2==0){ 
			yout[N]=(-1.0)*sumapares(yout);
			yout[N-1]=(-1.0)*sumaimpares(yout);}
		else{
			yout[N]=(-1.0)*sumaimpares(yout);
			yout[N-1]=(-1.0)*sumapares(yout);}
		A=yout;
		f<<t<<"\t";
		for(int i=0;i<N+1;i++){ f<<A[i]<<"\t";}
		f<<"\n";
		coeficientes(A);
		}
	}

void evolcoef(){
	int i;
	double *yout;
	yout=new double[N+1];
	double t=0.0;
	coefiniciales();
	puntosCheby(A,"inicio");
	for(i=0;i<=20;i++){
		coeficientes(A);
		Rk4(A,N-2,0.02,yout,t,derivadas);
		if(N%2==0){ 
			yout[N]=(-1.0)*sumapares(yout);
			yout[N-1]=(-1.0)*sumaimpares(yout);}
		else{
			yout[N]=(-1.0)*sumaimpares(yout);
			yout[N-1]=(-1.0)*sumapares(yout);}
		A=yout;
		if(i%5==0){
			puntosCheby(A,tostring(t));}
		t+=0.2;
		}
	delete[] yout;
	}

void derivaditas(){
	int i;
	double *yout;
	yout=new double[N+1];
	ofstream f;
	f.open("Derivs");
	double t=0.0;
	coefiniciales();
	coeficientes(A);
	for(i=0;i<N+1;i++){ f<<A2[i]<<"\t";}
	f<<"\n";
	derivadas(t,A,yout);	
	for(i=0;i<N+1;i++){ f<<A2[i]<<"\t";}
	f<<"\n";
	f.close();
	}
	
int main(){
	//printf("ingresa N: ");
	//scanf("%d",&N);
	N=5;
	int i;
	double p,im,k;
	double *pito;
	pito =new double[N+1];
	A=new double[N+1];
	A1=new double[N+1];
	A2=new double[N+1];
	p=integraltrape(2000,3,-1.0,1.0);
//	p=funcion(2,1);
	cout<<"suma pares: "<<p<<endl;
	delete[] A;
	delete[] A1;
	delete[] A2;
	}


