#include<string>
#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;

int pedirnum(string mensaje){
        cout<<mensaje<<endl;
        int num;
        while(!(cin>>num)||num<0){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;}

void llenar(int A[], int n){
        srand(time(NULL));
        for(int i=1; i<=n;i++){
                A[i]=rand()%1001;}}

void cambiar(int A[],int a, int b){
        int temp=A[a];
        A[a]=A[b];
        A[b]=temp;}


void Imprimir(int A[], int n){
        for(int i=1;i<=n;i++){
                cout<<A[i]<<" ";}
        cout<<"\n";}

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

string rutinaQ(int n){
        int A[n];
        llenar(A,n);
        clock_t t=clock();
        Quicksort(A,1,n);
        t= clock()-t;
        string res=to_string(n)+" "+to_string((((float)t)/CLOCKS_PER_SEC)*1000000)+"\n";
	return res;
	}

string rutinaH(int n){
        int A[n];
        llenar(A,n);
        clock_t t=clock();
        Heapsort(A,n);
        t= clock()-t;
	string res=to_string(n)+" "+to_string((((float)t)/CLOCKS_PER_SEC)*1000000)+"\n";
	return res;
	}

int main(){
	ofstream H,Q;
	H.open("Heap");
	Q.open("Quick");
	for(int n=5000;n<=100000;n+=5000){
		H<<rutinaH(n);}
	for(int n=5000;n<=100000;n+=5000){
		Q<<rutinaQ(n);}
	Q.close();
	H.close();
	}
