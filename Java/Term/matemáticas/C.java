import java.lang.Math;
import java.util.Scanner;
class matematicas {
public static void main(String [] args) {
		Scanner R= new Scanner(System.in); 
		menu();}

public static void menu() { 
		Scanner opcion = new Scanner (System.in); 
		System.out.println("Elige una opcion"); 
		System.out.println("1) Potencia"); 
		System.out.println("2) Factorial"); 
		System.out.println("3) Area de un circulo"); 
		int op = opcion.nextInt(); int a, b, resultado; 
		double x, res; 
		switch(op) { case 1:  System.out.println("Dame la base: "); 
				a = opcion.nextInt(); 
				System.out.println("Dame la potencia: "); 
				b = opcion.nextInt(); 
				resultado = potencia (a, b); 
				System.out.println(resultado); 
				break; 
			     case 2: System.out.println("Dame el numero a sacar el factorial:"); 
				a = opcion.nextInt(); 
				res = factorial(a); 
				System.out.println(res); 
				break;
			     case 3: System.out.println("Dame el radio"); 
				x = opcion.nextDouble(); 
				res = area_circulo(x); 
				System.out.println(res); 
				break; 
				default: System.out.println("Opcion invalida");
} 
}

public static double potencia(double a, double b) { return Math.pow(a,b); }
public static double factorial(int a){
	int i=0; int r=1; 
	for(i=0;i<a;i++){int x=a-i; r=r*x;}
	return r;}
public static int potencia(int x, int n) { int resultado = 1, i; for (i=0; i<n; i++) { resultado = resultado * x; } return resultado;
}
public static double area_circulo(double r) { return 3.1416 * r *r; }
public static double area_circulo_PI (double r) { return Math.PI * r *r; }
}
