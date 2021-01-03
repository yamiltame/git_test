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

void llenar(int A[], int n){
        srand(time(NULL));
        for(int i=1; i<=n;i++){
                A[i]=rand()%1001;}
        }

void Imprimir(int A[], int n){
        for(int i=1;i<=n;i++){
                cout<<A[i]<<" ";}
        cout<<"\n";}

void cambiar(int A[],int a, int b){
	int temp=A[a];
	A[a]=A[b];
	A[b]=temp;}

int partir(int A[],int p, int r){
	int x=A[r];
	int i=p-1;
	for (int j=p;j<r;j++){
		if(A[j]<=x){
			i=i+1;
			cambiar(A,i,j);}
		}
	cambiar(A,i+1,r);
	return i+1;
	}

void Quicksort(int A[], int p, int r){
	int q;
	if(p<r){
		q=partir(A,p,r);
		Quicksort(A,p,q-1);
		Quicksort(A,q+1,r);}
	}

int main(){
        cout<<"Ingresa el número de elementos: "<<endl;
        int n=pedirnum();
        int A[n];
        llenar(A,n);
        cout<<"Arreglo Aleatorio\n";
        Imprimir(A,n);
	Quicksort(A,1,n);
        cout<<"Arreglo Ordenado\n";
        Imprimir(A,n);}
			
