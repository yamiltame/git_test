#include<fstream>
#include<iostream>
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

string rutinaRa(int n){
	int A[n];
	llenar(A,n,100);
	clock_t t=clock();
	radixsort(A,n);
	t=clock()-t;
        string res=to_string(n)+" "+to_string((((float)t)/CLOCKS_PER_SEC)*1000000)+"\n";
        return res;
        }
	
int main(){
	ofstream R;
	R.open("Radix");
	for(int n=5000;n<=100000;n+=5000){
		R<<rutinaRa(n);}
	R.close();
	}
