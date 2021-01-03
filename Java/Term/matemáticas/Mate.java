import java.util.Scanner;
class Mate{
	public static void main(String[]args){
		Scanner R= new Scanner(System.in);
        	menu();}
	public static void menu(){
		Scanner opc=new Scanner(System.in);
	System.out.println("Eliga la operación");
	System.out.println("1.Factorial");
	System.out.println("2.Potencia");
	System.out.println("3.Area círculo");
	System.out.println("4.Perímetro círculo");
	long resp;
	int pot,n,p;
	double a,b;
	int e=opc.nextInt();
	switch (e){
		case 1: System.out.println("Escribe el número");
		n=opc.nextInt();
  		resp=factorial(n);
		System.out.println("respuesta = "+resp);
		break;
		case 2: System.out.println("Escribe la base");
		n=opc.nextInt();
		System.out.println("La potencia");
		p=opc.nextInt();
		pot=potencia(n,p);
		System.out.println("respuesta = "+pot);
		break;
		case 3: System.out.println("Escribe el radio");
		n=opc.nextInt();
		a=area_circulo(n);
		System.out.println("respuesta = "+a);
		break;
		case 4: System.out.println("Escribe el radio");
		n=opc.nextInt();
		b=perimetro_circulo(n);
		System.out.println("respuesta = "+b);
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
public static double area_circulo(int r){
      double res=3.1416*r*r;
      return res;}

public static double area_triangulo(int b, int h){
      int res=(b*h)/2;
      return res;}

public static int area_rectangulo(int b, int h){
      int res=b*h;
      return res;}

public static int perimetro_rectangulo(int b, int h){
      int res=(b*2)+(h*2);
      return res;}

public static double perimetro_circulo(int r){
      double res=2*3.1416*r;
      return res;}

public static double perimetro_triangulo(int b, int h){
      int la=((b*b/4)+(h*h));
      double l=Math.sqrt(la);
      double res=b+(2*l);
      return res;}
}

