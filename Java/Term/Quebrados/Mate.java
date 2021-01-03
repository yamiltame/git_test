import java.util.Scanner;
class Mate{
	public static void main(String[]args){
        	menu();}
public static void menu(){
	Scanner opc=new Scanner(System.in);
	System.out.println("Eliga la operación");
	System.out.println("1.Factorial  2.Potencia  3.Area círculo  4.Perímetro círculo");
	System.out.println("5.Area rectángulo  6.Perímetro rectángulo  7.Area triángulo");
	System.out.println("8.Perímetro triángulo  9.Operaciones de Fracciones");
	long resp;
	int pot,n,p;
	double a,b;
	int e=opc.nextInt();
	switch (e){
		case 1: System.out.println("Escribe el Número");
			n=opc.nextInt();
  			resp=factorial(n);
			System.out.println("respuesta = "+resp);
			break;
		
		case 2: System.out.println("Número base");
			n=opc.nextInt();
			System.out.println("Potencia");
			p=opc.nextInt();
			pot=potencia(n,p);
			System.out.println("respuesta = "+pot);
			break;

		case 3: System.out.println("radio");
			n=opc.nextInt();
			a=areacirculo(n);
			System.out.println("respuesta = "+a);
			break;

		case 4: System.out.println("radio");
			n=opc.nextInt();
			b=perimetrocirculo(n);
			System.out.println("respuesta = "+b);
			break;

		case 5:System.out.println("base");
			n=opc.nextInt();
			System.out.println("altura");
			p=opc.nextInt();
			pot=arearectangulo(n,p);
			System.out.println("respuesta = "+pot);
			break;

		case 6:System.out.println("base");
			n=opc.nextInt();
			System.out.println("altura");
			p=opc.nextInt();
			pot=perimetrorectangulo(n,p);
			System.out.println("respuesta = "+pot);
			break;

		case 7:System.out.println("base");
			n=opc.nextInt();
			System.out.println("altura");
			p=opc.nextInt();
			a=areatriangulo(n,p);
			System.out.println("respuesta = "+a);
			break;

		case 8:System.out.println("base");
			n=opc.nextInt();
			System.out.println("altura");
			p=opc.nextInt();
			a=perimetrotriangulo(n,p);
			System.out.println("respuesta = "+a);
			break;

		case 9:System.out.println("1.Suma  2.Resta  3.Multiplicación  4.División");
			n=opc.nextInt();
			quebrado q1,q2,q3;
			int n1,n2,d1,d2;
			Scanner tec=new Scanner(System.in);
			switch (n){
				case 1:System.out.println("Primer numerador");
					n1=tec.nextInt();
					System.out.println("Primer denominador");
					d1=tec.nextInt();
					System.out.println("Segundo numerador");
					n2=tec.nextInt();
					System.out.println("Segundo denominador");
					d2=tec.nextInt();
					q1=new quebrado(n1,d1);
					q2=new quebrado(n2,d2);
					q3=operacionesquebrados.suma(q1,q2);
					System.out.println(q3.dameNumerador()+"/"+q3.dameDenominador());
					break;
				case 2:System.out.println("Primer numerador");
					n1=tec.nextInt();
					System.out.println("Primer denominador");
					d1=tec.nextInt();
					System.out.println("Segundo numerador");
					n2=tec.nextInt();
					System.out.println("Segundo denominador");
					d2=tec.nextInt();
					q1=new quebrado(n1,d1);
					q2=new quebrado(n2,d2);
					q3=operacionesquebrados.resta(q1,q2);
					System.out.println(q3.dameNumerador()+"/"+q3.dameDenominador());
					break;
				case 3:System.out.println("Primer numerador");
					n1=tec.nextInt();
					System.out.println("Primer denominador");
					d1=tec.nextInt();
					System.out.println("Segundo numerador");
					n2=tec.nextInt();
					System.out.println("Segundo denominador");
					d2=tec.nextInt();
					q1=new quebrado(n1,d1);
					q2=new quebrado(n2,d2);
					q3=operacionesquebrados.multiplicacion(q1,q2);
					System.out.println(q3.dameNumerador()+"/"+q3.dameDenominador());
					break;
				case 4:System.out.println("Primer numerador");
					n1=tec.nextInt();
					System.out.println("Primer denominador");
					d1=tec.nextInt();
					System.out.println("Segundo numerador");
					n2=tec.nextInt();
					System.out.println("Segundo denominador");
					d2=tec.nextInt();
					q1=new quebrado(n1,d1);
					q2=new quebrado(n2,d2);
					q3=operacionesquebrados.division(q1,q2);
					System.out.println(q3.dameNumerador()+"/"+q3.dameDenominador());
					break;
				
				default: System.out.println("opción inválida");}
			break;
		default: System.out.println("opción inválida");}
		}
public static long factorial(long n){
      long res=1;
      int i=0;
      for(i=0;i<n;i++) {
      long x=n-i;
      res=res*x;}
      return res;}
public static int potencia(int n, int p){
      int i=0;
      int x=n;
      int res=1;
      for(i=0;i<p;i++){res=res*x;}
      return res;}
public static double areacirculo(int r){
      double res=3.1416*r*r;
      return res;}

public static double areatriangulo(int b, int h){
      int res=(b*h)/2;
      return res;}

public static int arearectangulo(int b, int h){
      int res=b*h;
      return res;}

public static int perimetrorectangulo(int b, int h){
      int res=(b*2)+(h*2);
      return res;}

public static double perimetrocirculo(int r){
      double res=2*3.1416*r;
      return res;}

public static double perimetrotriangulo(int b, int h){
      int la=((b*b)+(h*h));
      double l=Math.sqrt(la);
      double res=b+l+h;
      return res;}

}

