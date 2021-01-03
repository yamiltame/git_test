#include<iostream>
#include<time.h>
using namespace std;

int pedirnum(){
        int num;
        while(!(cin>>num)||num<0){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

void insertion(int A[],int n){
	int j,k,i;
	for(j=1;j<n;j++){
		k=A[j];
		for(i=j-1;(i>=0)&&(A[i]<k);i--){
			A[i+1]=A[i];}
		A[i+1]=k;}
	}
void Ini(int A[],int n){
	for(int i=0;i<n;i++){
		A[i]=i+1;}
	}
void rutina(int n){
	int A[n];
	Ini(A,n);
	clock_t t=clock();
	insertion(A,n);	
	t= clock()-t;
	cout<<" Ordenados "<<n<<" elementos"<<endl;
	cout<<"tiempo de ejecucion: "<<((float)t)/CLOCKS_PER_SEC<<endl;}
	

int main(){
	rutina(32);
	rutina(64);
	rutina(128);
	rutina(256);
	rutina(512);
	rutina(1024);
	rutina(2048);
	rutina(4096);
	rutina(8192);
	rutina(16384);
	rutina(32768);
	}
