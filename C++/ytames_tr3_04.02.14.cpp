#include<iostream>
#include<string>
using namespace std;

const int Currency[10] = {1000,500,200,100,50,20,10,5,2,1};

int ingresarCant(){
	int a;
	cout<<"ingresa la cantidad que quieres cambiar\n";
	while(!(cin>>a)||a<1){
		cout<<"Cantidad Incangeable!!\n";
		cin.clear();
		cin.ignore(100,'\n');}
	return a;
	}
int valores(int a){
    int j;
    for(j=0; a<=Currency[j];j++){}
    return j;}

bool verificar_MB(int v,int res){
	if((res/v)==0){return false;}
	else{
		string T, mob;
		if(v>19){
			mob="Billetes de ";}
		else{ mob="Monedas de ";}
		cout<<"deseas cambio con "<<mob<<v<<" ?\n";
		cout<<"ingresa la letra  s  si deseas y la letra  n  si no.\n";
		while((cin>>T)&&(T!="s"&&T!="n")){
        	    cout<<"Ingresa s o n!!\n";
        	    cin.clear(); cin.ignore(100,'\n');}
		if(T=="s"){ return true;}
		else{ return false;}
		}
	}

void ini(int a[]){
	for(int i=0;i<10;i++){
		a[i]=0;}}

main(){
	int resto=ingresarCant(), i=valores(resto);
	int Dineros[10];
	ini(Dineros);
	string mob;
	for(i;i<10;i++){
		if(i==9){
			Dineros[i]=resto;}
		else{
			if(verificar_MB(Currency[i],resto)){
				Dineros[i]=resto/Currency[i];
				resto=resto%Currency[i];}}
		}
	cout<<"Su cambio es: \n";
	for(i=0;i<10;i++){
		if(i<6){if(Dineros[i]==1){mob=" Billete de ";}
			else{mob=" Billetes de ";}}
		else{if(Dineros[i]==1){mob=" Moneda de ";}
		     else{mob=" Monedas de ";}}
		if(Dineros[i]!=0){ cout<<Dineros[i]<<mob<<Currency[i]<<endl;}
		}
	}


