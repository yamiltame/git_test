import java.util.Scanner;
import java.util.Random;

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
