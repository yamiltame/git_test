#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int gato[9];

void inicializar(int a[]){
	for(int i=0;i<9;i++){
		a[i]=0;}
	}

void instrucciones(){
	cout<<"-------------------------------\nLas posiciones del Gato son: \n";
	cout<<" "<<0<<" | "<<1<<" | "<<2<<endl;
	cout<<"-----------\n";
	cout<<" "<<3<<" | "<<4<<" | "<<5<<endl;
	cout<<"-----------\n";
	cout<<" "<<6<<" | "<<7<<" | "<<8<<endl;
	}

bool opcVacia(int opc){
	bool p=true;
	if(gato[opc]!=0){p=false;}
	return p;}

int pedirOpcion(){
	int opc;
	while(!(cin>>opc)||opc>9||opc<0){
		cout<<"Opcion invalida\n";
		cin.clear(); cin.ignore(100,'\n');}
	return opc;}

void tiraHm(){
	cout<<"\n¿En donde quieres tirar?\n";
	int tiro=pedirOpcion();
	while(!opcVacia(tiro)){
		cout<<"Casilla ocupada\n Elige otra!\n";
		tiro=pedirOpcion();}
	gato[tiro]=1;
	}

void tiraCp(){
	srand(time(NULL));
	int tiro=(rand()%9);
	while(!opcVacia(tiro)){
		tiro=(rand()%9);}
	gato[tiro]=2;
	}

int HayGanador(){
	int g=0,i;
	if(gato[0]==gato[4]&&gato[4]==gato[8]){return gato[0];}
	if(gato[2]==gato[4]&&gato[4]==gato[6]){return gato[2];}
	if(gato[0]==gato[1]&&gato[1]==gato[2]){return gato[0];}
	if(gato[3]==gato[4]&&gato[4]==gato[5]){return gato[3];}
	if(gato[6]==gato[7]&&gato[7]==gato[8]){return gato[6];}
	if(gato[0]==gato[3]&&gato[3]==gato[6]){return gato[0];}
	if(gato[1]==gato[4]&&gato[4]==gato[7]){return gato[1];}
	if(gato[2]==gato[5]&&gato[5]==gato[8]){return gato[2];}
	return g;}

char EnteroADibujo(int x)
{
    if (x == 0)
        return ' ';
    if (x == 1)
        return 'o';
    return 'x';
}

void imprimir(){
	cout<<"-------------------------------\n El Gato se encuentra Asi\n";
	cout<<" "<<EnteroADibujo(gato[0])<<" | "<<EnteroADibujo(gato[1])<<" | "<<EnteroADibujo(gato[2])<<endl;
	cout<<"-----------\n";
	cout<<" "<<EnteroADibujo(gato[3])<<" | "<<EnteroADibujo(gato[4])<<" | "<<EnteroADibujo(gato[5])<<endl;
	cout<<"-----------\n";
	cout<<" "<<EnteroADibujo(gato[6])<<" | "<<EnteroADibujo(gato[7])<<" | "<<EnteroADibujo(gato[8])<<endl;
	}
		
void menu(){
	cout<<"Que deseas hacer?\n 1.Jugar   2.Salir\n";
	int opc=pedirOpcion();
	int Win,tiros;
	switch(opc){
		case 1: 	
			instrucciones();
			inicializar(gato);
			Win=HayGanador();
			tiros=0;
			while(Win==0 && tiros<9){
				if(tiros%2==0){tiraHm();Win=HayGanador();}
				else{tiraCp();imprimir();Win=HayGanador();}
				tiros++;
				}
			imprimir();
			if(Win==0){cout<<"Empate!!\n";}
			if(Win==1){cout<<"Tu Ganaste!!\n";}
			if(Win==2){cout<<"Gano la Compu :( \n";}
			break;
		case 2:exit(0);break;
		default: cout<<"Opcion invalida\n";break;
		}
	}
	

int main(){
	for(;;){menu();}
	}

