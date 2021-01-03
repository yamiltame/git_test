#include<iostream>
#include <ctime>
#include<cstdlib>
using namespace std;

int pedirnum(){
        int num;
        while(!(cin>>num)||num<0){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

void Maxheapify(int A[],int heapsize, int i){
	int mayor,t,d,z;
	z=2*i;
	d=2*i+1;
	if ((z<=heapsize) && (A[z]>A[i])){
		mayor=z;}
	else{
		mayor=i;}
	if((d<=heapsize) && (A[d]>A[mayor])){
		mayor=d;}
	if(mayor!=i){
		t=A[i];
		A[i]=A[mayor];
		A[mayor]=t;
		Maxheapify(A,heapsize,mayor);}
	}

void BuildHeap(int A[],int hs){
	for(int i=(hs/2);i>=1;i--){
		Maxheapify(A,hs,i);}
	}

void Heapsort(int A[], int n){
	int t,i;
	int hs=n;
	for(i=n;i>=2;i--){
		t=A[i];
		A[i]=A[1];
		A[1]=t;
		Maxheapify(A,--hs,1);}
	}

void llenar(int A[], int n){
	srand(time(NULL));
	for(int i=1; i<=n;i++){
		A[i]=rand()%101;}
	}

void Imprimir(int A[], int n){
	for(int i=1;i<=n;i++){
		cout<<A[i]<<" ";}
	cout<<"\n";}

int main(){
	cout<<"Ingresa el número de elementos: "<<endl;
	int n=pedirnum();
	int A[n];
	llenar(A,n);
	cout<<"Arreglo Aleatorio\n";
	Imprimir(A,n);
	BuildHeap(A,n);
	Heapsort(A,n);
	cout<<"Arreglo Ordenado\n";
	Imprimir(A,n);}
	
