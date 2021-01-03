import java.util.Scanner;
class pila{

int tope,i;
int[] A;
Scanner r=new Scanner(System.in);

pila(){
	System.out.println("de qué tamagno quieres la pila");
	int t=r.nextInt();
	A=new int[t];
	tope=-1;}

boolean Vacia(){
	return tope==-1;}
	
void Vaciar(){
	tope=-1;}

int Top(){
	error();
	return A[tope];}

void pop(){
	error();
	tope--;}

int topypop(){
	error();
	int a=Top();
	pop();
	return a;}

void push(){
	if(tope==A.length-1){duplica();}
	tope++;
	System.out.println("ingresa el dato");
	int a=r.nextInt();
	A[tope]=a;
	}

void duplica(){
	int[] N=new int[A.length*2];
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
