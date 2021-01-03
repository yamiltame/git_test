#include <iostream>
#include <ctime>
#include<cstdlib>
using namespace std;

void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}
void heapsort(int *a, int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}
void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}
void Imprimir(int A[], int n){
        for(int i=1;i<=n;i++){
                cout<<A[i]<<" ";}
        cout<<"\n";}

void llenar(int A[], int n){
        srand(time(NULL));
        for(int i=1; i<=n;i++){
                A[i]=rand()%21;}
        }

int main()
{
    srand(time(NULL));
    int n, i, x;
    cout<<"Enter no of elements of arrayn";
    cin>>n;
    int a[n];
    llenar(a,n);
    Imprimir(a,n);
    build_maxheap(a,n);
    heapsort(a, n);
    cout<<"nnSorted Array\n";
    Imprimir(a,n);
    return 0;
}
