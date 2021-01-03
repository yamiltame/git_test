import java.util.Scanner;
import java.util.Random;

class nodo{
        nodo sig,ant;
        float val;

nodo(){}

nodo(float v){
        sig=null;
        ant=null;
        val=v;}

}//FIN class nodo

class lista{
        nodo I;
        nodo t;
        int elementos=0;

lista(){
        I=null;}

void insertar(nodo x){
        if(elementos==0 || I==null){
                I=x;
                ++elementos;}
        else{
		if(x.val>I.val){ 
			float temp=x.val;
			x.val=I.val;
			I.val=temp;}
                x.sig=I;
                if(I!=null){ I.ant=x;}
                I=x;
                x.ant=null;
                ++elementos;}
        }

void print(){
        t=I;
        if(elementos==0){
                System.out.println(".");}
        else{
                while(t!=null){
                        if(t.sig==null){System.out.print(t.val);}
                        else{System.out.print(t.val+",");}
                        t=t.sig;
                        }
                System.out.println("");}
        }

}//FIN class lista

class bucket{
	lista[] B;

bucket(int n){
	B=new lista[n];
	for(int i=0;i<B.length;i++){
		B[i]=new lista();}
	}

void insertar(float[] A){
	int j=0;
	for(int k=0;k<B.length;k++){
			nodo t=B[k].I;
		for(int i=0;i<B[k].elementos;i++){
			while(t!=null){
				A[j]=t.val;
				j=j+1;
				t=t.sig;}
			}
	}
	}

void bucketsort(float[] A){
	int i;
	for(i=0;i<A.length;i++){
		B[(int)Math.floor(A.length*A[i])].insertar(new nodo(A[i]));}
	insertar(A);
	}
		
}//FIN class bucket
class test{
	static float[] A;
	static bucket B;
	static Random rnd=new Random();
	static Scanner opc=new Scanner(System.in);

public static void main(String[]args){
	llenar(pedirnum("Ingresa el número de Datos: "));
	B=new bucket(A.length);
	imprimir();
	B.bucketsort(A);
	System.out.println("BUCKET SORT");
	imprimir();
	}
	
static int pedirnum(String mess){
        int s=0;
        boolean E=true;
        do{
                try{
                        System.out.print(mess);
                        s=opc.nextInt();
                        E=false;}
                catch(java.util.InputMismatchException e){
                        System.out.println("Error! Ingresa números enteros");
                        opc=new Scanner(System.in);}
        }while(E);
        return s;
        }

static void llenar(int n){
	A=new float[n];
        for(int i=0;i<n;i++){
                A[i]=rnd.nextFloat();}
        }

static void imprimir(){
	System.out.println("Arreglo");
	for(int i=0;i<A.length;i++){
		System.out.print(A[i]+", ");}
	System.out.println("\n");
	}
}//Fin class test
