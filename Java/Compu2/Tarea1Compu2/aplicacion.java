import java.util.Scanner;
class aplicacion{
	static Scanner r=new Scanner(System.in);

public static void main(String[]args){
	for(;;){menu();}}

public static void menu(){
	int a;
	System.out.println("Escribe la operación que deseas hacer");
	System.out.println("1.Sucesión fibonacci   2.Factorial recursivo   3.Factorial no recursivo   4.Suma de los primeros n números enteros   5.Salir");
	int e=r.nextInt();
	switch(e){
		case 1:System.out.println("¿Qué número de la sucesión deseas conocer?");
			a=r.nextInt();
			System.out.println(funciones.fib(a));
			break;
		case 2:System.out.println("Escribe el número");
			a=r.nextInt();
			System.out.println(funciones.factR(a));
			break;
		case 3:System.out.println("Escribe el número");
			a=r.nextInt();
			System.out.println(funciones.factNR(a));
			break;
		case 4:System.out.println("¿Hasta dónde deseas sumar?");
			a=r.nextInt();
			System.out.println(funciones.sumatoria(a));
			break;
		case 5:System.exit(0);}
	}
}//FIN
