#include<iostream>
#include <ctime>
#include<cstdlib>
#include<string>
using namespace std;

int pedirnum(string mensaje){
        cout<<mensaje<<endl;
        int num;
        while(!(cin>>num)||num<0){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;}

void llenar(int A[], int n,int k){
        srand(time(NULL));
        for(int i=0; i<n;i++){
                A[i]=rand()%(k+1);}}

void Imprimir(int A[], int n){
        for(int i=0;i<n;i++){
                cout<<A[i]<<" ";}
        cout<<"\n";}

int maximo(int A[], int n){
	int m=0;
	for(int i=0;i<n;i++){
		if(A[i]>m){
			m=A[i];}
		}
	return m;}

void countingSort(int A[],int n, int k){
        int i;
	int B[n];
        int C[10]={0};
        for(i=0;i<n;i++){
                C[(A[i]/k)%10]++;}
        for(i=1;i<10;i++){
                C[i]=C[i]+C[i-1];}
        for(i=n-1;i>=0;i--){
                B[C[(A[i]/k)%10]-1]=A[i];
                C[(A[i]/k)%10]--;}
	
	for(i=0;i<n;i++){
		A[i]=B[i];}
        }

void radixsort(int A[], int n){
	int m=maximo(A,n);
	for(int k=1;(m/k)>0;k*=10){
		countingSort(A,n,k);}
	}

int main(){
	int n=pedirnum("Ingresa número de elementos: ");
	int A[n];
	llenar(A,10,10000);
	cout<<"Arreglo aleatorio"<<endl;
	Imprimir(A,n);
	radixsort(A,n);
	cout<<"Arreglo ordenado"<<endl;
	Imprimir(A,n);
	}
