#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int c=0;

double getdouble(string mess){
	cout<<mess;
        double num;
        while(!(cin>>num)){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

int getnum(string mess){
	cout<<mess;
        int num;
        while(!(cin>>num)||num<0){
                cout<<"numero invalido\n";
                cin.clear(); cin.ignore(100,'\n');}
        return num;
        }

double Funcion(double x,double r){
	return x+(r*x)/(1+x*x);}

double derivada(double x,double r){
	return 1+(r*(1-x*x))/((1+x*x)*(1+x*x));}

void DiagBif(double initcond){
	double N;
	ofstream D;
	D.open("Bifurcacion");
	for(double R=2;R<=5;R+=0.001){
		N=0.2;
		for(int i=0;i<2000;i++){
			N=Funcion(N,R);
			if(i>=1900){ D<<R<<" "<<N<<endl;}
			}
		}
	D.close();
	D.open("diag.gp");
	D<<"plot [2.8:4][0:1] 'Bifurcacion' w p pt 7 ps 0.4";
	D.close();
	system("gnuplot -p diag.gp");
	}
	
void mapeo(double N,int n,double R,string name){
	ofstream f;
	f.open(name.c_str());
	int i;
	for(i=0;i<=n;i++){
		f <<i<<" "<<N<<endl;
		N=Funcion(N,R);}
	f.close();
	}

void graficar(){
	ofstream f;
	f.open("graf.gp");
	f<<"plot [][0:1]";
	for(int i=0; i<c;i++){
		f<<"'mapeo_"<<i<<"' w p pt 5 ps 0.8,";}
	f.close();
	string cmd="gnuplot -p  ";
	cmd=cmd+"graf.gp";
	system(cmd.c_str());
	}

void cobweb(double N,double R,int k){
	ofstream f;
	string name="cobweb_"+to_string(R);
	f.open(name.c_str());
	for(int i=0;i<=k;i++){
		f<<N<<" "<<N<<endl;
		f<<N<<" "<<Funcion(N,R)<<endl;
		N=Funcion(N,R);}
	f.close();
	f.open("cobweb.gp");
	f<<"set title 'COBWEB PLOT R="<<R<<"'"<<endl;
	f<<"plot [0:1][0:1] (x*x)+"<<R<<",x,"<<"'"<<name<<"'"<<"w lines";
	f.close();
	system("gnuplot -p cobweb.gp");
	}
 	
void menu(){
	ofstream f;
	int k;
	string name, cmd;
	double N,R;
        cout<<"Que deseas hacer?\n 1.Nuevo mapeo   2.Graficar mapeos   3.Cobweb   4.Borrar   5.DiagramadeBifurcacion   6.Salir\n";
        int opc=getnum("");
        switch(opc){
                case 1:
			N=getdouble("Población inicial: ");
			R=getdouble("Parámetro R: ");
			k=getnum("Número de iteraciones: ");
			name="mapeo_"+to_string(c++);
			mapeo(N,k,R,name);
			break;
		case 2:
			graficar();
			break;
		case 3:
			cobweb(N,R,k);
			break;
		case 4:
			system("rm mapeo_*");
			system("rm cobweb*");
			system("rm graf.gp");
			system("rm diag.gp");
			system("rm Bifur*");
			c=0;
			break;
		case 5: 
			DiagBif(0.12);
			break;
		case 6:
			exit(0);break;
                default: cout<<"Opcion inválida\n";break;
                }
        }

int main(){
	for(;;){menu();}	
	}