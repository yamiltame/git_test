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
        return num;
        }

int* countingSort(int A[],int k, int n){
	int i,j;
	int C[k];
	int* B=new int[n];
	for(i=0;i<=k;i++){
		C[i]=0;}
	for(j=1;j<=n;j++){
		++C[A[j]];}
	for(i=1;i<=k;i++){
		C[i]=C[i]+C[i-1];}
	for(j=n;j>=1;j--){
		B[C[A[j]]]=A[j];
		--C[A[j]];}
	return B;
	}

void llenar(int A[], int n,int k){
        srand(time(NULL));
        for(int i=1; i<=n;i++){
                A[i]=rand()%(k+1);}
        }

void Imprimir(int A[], int n){
        for(int i=1;i<=n;i++){
                cout<<A[i]<<" ";}
        cout<<"\n";}

int main(){
	int k=pedirnum("Ingresa el rango de valores; de 0 hasta:");
        int n=pedirnum("Ingresa número de elementos");
        int A[n];
        llenar(A,n,k);
        cout<<"Arreglo Aleatorio\n";
        Imprimir(A,n);
        cout<<"Arreglo Ordenado\n";
        Imprimir(countingSort(A,k,n),n);
	}

