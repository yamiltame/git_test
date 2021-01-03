#include<string>
#include<iostream>
#include<fstream>
using namespace std;

double T[]={550,575,600,625,647,670,690,725,750,775};

void graficar(){
	ofstream f;
	f.open("graf.gp");
	f<<"plot [0:0.5][0:600] ";
	for(int i=0; i<10;i++){
		if(i!=9){f<<"(0.082057*"<<T[i]<<")/(x - 0.03183) - 0.1360086/x**2 title 'T="<<T[i]<<"',";}
		else{ f<<"(0.082057*"<<T[i]<<")/(x - 0.03183) - 0.1360086/x**2 title 'T="<<T[i]<<"'";}}
	f.close();
	string cmd="gnuplot -p  ";
	cmd=cmd+"graf.gp";
	system(cmd.c_str());
	}

/*void cobweb(double N,double R,int k){
	ofstream f;
	string name="cobweb_"+to_string(R);
	f.open(name.c_str());
	for(int i=0;i<=k;i++){
		f<<N<<" "<<N<<endl;
		f<<N<<" "<<iteracionmapcua(N,R)<<endl;
		N=iteracionmapcua(N,R);}
	f.close();
	f.open("cobweb.gp");
	f<<"set title 'COBWEB PLOT R="<<R<<"'"<<endl;
	f<<"plot [0:1][0:1] (x*x)+"<<R<<",x,"<<"'"<<name<<"'"<<"w lines";
	f.close();
	system("gnuplot -p cobweb.gp");
	}*/
 	
int main(){
	graficar();	
	}
