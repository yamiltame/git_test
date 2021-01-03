#include <iostream>
using namespace std;
#include<time.h>

void Ini(int A[],int n){
        for(int i=0;i<n;i++){
                A[i]=i+1;}
        }

void merge(int *,int, int , int, int);
void mergesort(int *a, int low, int high,int n){
    int mid;
    if (low < high){
        mid=(low+high)/2;
        mergesort(a,low,mid,n);
        mergesort(a,mid+1,high,n);
        merge(a,low,high,mid,n);}
    return;
	}
void merge(int *a, int low, int high, int mid,int n){
    int i, j, k, c[n];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high){
        if (a[i] < a[j]){
            c[k] = a[i];
            k++;
            i++;}
        else{
            c[k] = a[j];
            k++;
            j++;}
    	}
    while (i <= mid){
        c[k] = a[i];
        k++;
        i++;}
    while (j <= high){
        c[k] = a[j];
        k++;
        j++;}
    for (i = low; i < k; i++){
        a[i] = c[i];}
	}

void rutina(int n){
        int A[n];
        Ini(A,n);
        clock_t t=clock();
        mergesort(A,0,n-1,n);
        t= clock()-t;
        cout<<" Ordenados "<<n<<" elementos"<<endl;
        cout<<"tiempo de ejecucion: "<<(((float)t)/CLOCKS_PER_SEC)*1000000<<endl;}

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
