#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int m[][];
int s[][];

int pedirnum(string mensaje){
        cout<<mensaje<<endl;
        int num;
        while(!(cin>>num)||num<0){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

void printoptimal(int s[][],int i,int j){
	if(i==j){
		cout<<"A"<<i;}
	else{
		cout<<"(";
		printoptimal(s,i,s[i][j]);
		printoptimal(s,s[i][j]+1,j);
		cout<<")";}
	}

void Matrixchainorder(int p[],int n){
	int i,l,j,k;
	for(i=0;i<n;i++){
		m[i][i]=0;}
	for(l=1;l<n;l++){
		for(i=0;i<(n-l+1);i++){
			j=i+l-1;
			m[i][j]=1000000000;
			for(k=i;k<(j-1);k++){
				int q=m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
					}
				}
			}
		}
	}

int main(){
	int i;
	int n=pedirnum("ingresa el número de matrices a multiplicar: ");
	int p[n+1];
	bool compatible=1;
	m=new int[n][n];
	s=new int[n][n];
	int dimensiones[2*n];
	for(i=0;i<(2*n);i+=2){
		cout<<"Matriz A"<<i/2;
		dimensiones[i]=pedirnum("filas: ");
		dimensiones[i+1]=pedirnum("columnas: ");}
	for(i=1;i<((2*n)-1);i+=2){
		if(dimensiones[i]!=dimensiones[i+1]){
			compatible=0;
			break;}
		}
	if(compatible){
		p[0]=dimensiones[0];
		for(i=1;i<n;i++){
			p[i]=dimensiones[2*i-1];}
		Matrixchainorder(p,n);}
	else{ cout<<"matrices incompatibles"<<endl;}
	
}
