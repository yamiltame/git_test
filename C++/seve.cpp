#include<iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

string productos[5]={"Tacos","Quesadillas","Quesataco","Aguas","Refrescos"};
int mapa[5][5]={0};
int precios[5]={12,11,15,10,12};

int pedirmesa(){
	cout<<"ingresa el numero de mesa: ";
        int opc;
        while(!(cin>>opc)||opc<0||opc>3){
                cout<<"numero invalido\n Ingresa el numero de mesa: ";
                cin.clear(); cin.ignore(100,'\n');}
        return opc;}

int pedirnum(){
	int num;
	while(!(cin>>num)||num<0){
		cout<<"numero invalido\n";
		cin.clear(); cin.ignore(100,'\n');}
	return num;}

void ingresar(int m){
	int i;
	for(i=0;i<5;i++){
		cout<<productos[i]<<": ";
		int n=pedirnum();
		mapa[m][i]=mapa[m][i] + n;
		mapa[4][i]=mapa[4][i] + n;}
	}

void borrar(int m){
	int i;
	for(i=0;i<5;i++){
		mapa[m][i]=0;}
	}

int cuenta(int m){
	int i,c=0;
	for(i=0;i<5;i++){
		c=c + mapa[m][i]*precios[i];}
	return c;}

void imprimir(int m){
	if(m==4){cout<<"TOTAL\n";}
	if(m==3){cout<<"PEDIDO\n";}
	if(m!=3 && m!=4){cout<<"MESA "<<m+1<<endl;}
	int i;
	for(i=0;i<5;i++){
		cout<<productos[i]<<": "<<mapa[m][i]<<"\n";}
	cout<<"la cuenta es "<<cuenta(m)<<"$"<<endl;
	}

void menu(){
	cout<<"\nQue deseas hacer?\n 1.Ingresar orden   2.Ver cuenta   3.Cuenta Final   4.Pa' llevar    5.Ver Total   6.Salir"<<endl;
	int opc=pedirnum(),m;
	switch(opc){
		case 1: 
			m=pedirmesa();
			ingresar(m-1);
			break;
		case 2:
			m=pedirmesa();
			imprimir(m-1);
			break;
		case 3:
			m=pedirmesa();
			imprimir(m-1);
			borrar(m-1);
			break;
		case 4:
			ingresar(3);
			cout<<"la cuenta para llevar es: "<<cuenta(3)<<"$"<<endl;
			break;
		case 5:
			imprimir(4);
			break;
		case 6: 
			exit(0);break;
		default: 
			cout<<"opcion invalida"<<endl;
			break;
		}
	}
			
int main(){
	for(;;){menu();}
	}
