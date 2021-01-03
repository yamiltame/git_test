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

string rutinaC(int n){
	int A[n];
	llenar(A,n,100);
	clock_t t=clock();
	int* B=countingSort(A,100,n);
	t=clock()-t;
        string res=to_string(n)+" "+to_string((((float)t)/CLOCKS_PER_SEC)*1000000)+"\n";
        return res;
        }
	
int main(){
	ofstream C;
	C.open("counting");
        for(int n=5000;n<=100000;n+=5000){
                C<<rutinaC(n);}
	C.close();}
