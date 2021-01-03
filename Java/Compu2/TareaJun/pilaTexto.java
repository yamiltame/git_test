import java.util.Scanner;
class pilaTexto{

int tope,i;
String[] A;
Scanner r=new Scanner(System.in);

pilaTexto(int t){
	A=new String[t];
	tope=-1;}

boolean Vacia(){
	return tope==-1;}
	
void Vaciar(){
	tope=-1;}

String Top(){
	error();
	return A[tope];}

void pop(){
	error();
	tope--;}

String topypop(){
	error();
	String a=Top();
	pop();
	return a;}

void push(String a){
	if(tope==A.length-1){duplica();}
	tope++;
	A[tope]=a;
	}

void duplica(){
	String[] N=new String[A.length*2];
	for(i=0;i<A.length;i++){
		N[i]=A[i];}
	A=N;}

void error(){
	if(Vacia()){
		System.out.println("Error: está vacía");
		System.exit(0);}
	else{}}

void imprimir(){
	error();
	for(i=tope;i>=0;i--){
		System.out.println("{"+A[i]+"}");}
	}
}
