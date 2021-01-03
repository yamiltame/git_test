#include<iostream>
#include<string>
using namespace std;


void Ini(int O[],int A[], int D[],int size){		//Método para inicializar las agujas
	for(int i=0;i<size;i++){
		O[i]=i+1;
		A[i]=0;
		D[i]=0;}
	}

void Mover(int O[], int D[], int size){		//Método para mover disco de una aguja a otra
	for(int i=0;i<size;i++){
		if(O[i]!=0){
			for(int j=size-1;j>=0;j--){
				if(D[j]==0){
					D[j]=O[i];
					O[i]=0;
					break;}
				}
			break;}
		}
	}

void enteroadisco(int d){
	for(int j=0;j<2*d;j++){
		cout<<"-";}
	}

void space(int d, int n){
	for(int i=0;i<n-d;i++){
		cout<<" ";}
	}

void imprimirtorres(int O[],int A[],int D[],int n){
	for(int i=0;i<n;i++){
		cout<<"    ";
		space(O[i],n); enteroadisco(O[i]); space(O[i],n);cout<<"    ";
		space(A[i],n); enteroadisco(A[i]); space(A[i],n);cout<<"    ";
		space(D[i],n); enteroadisco(D[i]); cout<<"\n";}
	}

void Print(int O[], int A[],int D[],int n){		//Método para imprimir las agujas de manera ordenada
	if(O[n]==10 && A[n]==11 && D[n]==12){
		imprimirtorres(O,A,D,n);
		}
	if(O[n]==10 && A[n]==12 && D[n]==11){
		imprimirtorres(O,D,A,n);
		}
	if(O[n]==11 && A[n]==10 && D[n]==12){
		imprimirtorres(A,O,D,n);
		}
	if(O[n]==11 && A[n]==12 && D[n]==10){
		imprimirtorres(D,O,A,n);
		}
	if(O[n]==12 && A[n]==10 && D[n]==11){
		imprimirtorres(A,D,O,n);
		}
	if(O[n]==12 && A[n]==11 && D[n]==10){
		imprimirtorres(D,A,O,n);
		}
	cout<<"    ";space(2,n);cout<<"Orig";space(2,n);cout<<"    ";space(2,n);cout<<"Auxi";space(2,n);cout<<"    ";space(2,n);cout<<"Dest\n"<<endl;
	}

void TH(int n, int O[], int A[], int D[],int c){		//Método recursivo de las torres de hanoi
	if(n==1){
		Mover(O,D,c);
		Print(O,A,D,c);
		cout<<"\n";
		}
	else{
		TH(n-1,O,D,A,c);
		Mover(O,D,c);
		Print(O,A,D,c);
		cout<<"\n";
		TH(n-1,A,O,D,c);
		}
		
	}

int pedirnum(){	
        int num;
        while(!(cin>>num)||num<0){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
	}

int main(){
	cout<<"Número de Discos"<<endl;
	int n=pedirnum();
	int O[n+1];
	int D[n+1];
	int A[n+1];
	O[n]=10; //etiqueta de aguja para el método imprimir
	D[n]=12;
	A[n]=11;
	Ini(O,A,D,n);
	cout<<"\n       TORRES DE HANOI\n \n"<<endl;
	Print(O,A,D,n);
	TH(n,O,A,D,n);
	}
