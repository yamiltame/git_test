#include<iostream>
#include<string>

using namespace std;

float ask(){
	float a;
	while(!(cin>>a)||a<0){
                cout<<"Numero invalido!!\n";
                cin.clear();
                cin.ignore(100,'\n');}
        return a;}
	
int pedir(){
	int a;
	while(!(cin>>a)||a<0){
                cout<<"Numero invalido!!\n";
                cin.clear();
                cin.ignore(100,'\n');}
        return a;}


float promedio(int m){
	float i,s=0,t;
	for(i=0;i<m;i++){
		cout<<"Ingrese la calificacion de la "<<i+1<<" Materia: ";
		t=ask();
		s=s+t;}
	return s/m;}

void ingresarAl(string Al[], int Mat[], float Prom[], int l){
	int i;
	for(i=0;i<l;i++){
		cout<<"\nNombre del "<<i+1<<" Alumno: ";
		cin>>Al[i];
		cout<<"Cantidad de materias: ";
		Mat[i]=pedir();
		Prom[i]=promedio(Mat[i]);}
	}

void imprimir(string Al[],float Prom[],int l){
	int i;
	for(i=0;i<l;i++){
		cout<<"El promedio de "<<Al[i]<<" es "<<Prom[i]<<endl;}
	}

main(){
	cout<<"Cuantos alumnos deseas ingresar?\n";
	int a=pedir();
	string A[a];
	int M[a];
	float P[a];
	ingresarAl(A,M,P,a);
	cout<<"\n";
	imprimir(A,P,a);}
