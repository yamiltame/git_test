import java.util.Random;

class test{
	static double[] A;
        static bucket B;
        static Random rnd=new Random();

public static void main(String[]args){
	for(int n=5000;n<=100000;n+=5000){
		rutinaB(n);}
        }

static void llenar(int n){
        A=new double[n];
	A[0]=0.9;
        for(int i=1;i<n;i++){
                A[i]=A[i-1]-0.000000001;}
        }

static void rutinaB(int n){
	long ti,tf,t;
	llenar(n);
	B=new bucket(n);
	ti=System.nanoTime();
	B.bucketsort(A);
	tf=System.nanoTime();
	t=(tf-ti)/1000;
	System.out.println(n+" "+t);
	}

}//Fin class test
