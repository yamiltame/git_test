import java.util.Scanner;
class aplicacion{
	static puntuaciones l;
	static Scanner r= new Scanner(System.in);
	static int e,p,n,k;
	static String nom;

public static void main(String[]args){
	menu();}

static void menu(){
	System.out.println("Cuántas puntuaciones deseas albergar?");
	n=r.nextInt();
	l=new puntuaciones(n);
	for(;;){
		System.out.println("1. Insertar jugador   2. Borrar puntuación   3. Ver puntuaciones   4. Salir");
		e=r.nextInt();
		switch (e){
			case 1: System.out.println("Ingresa el nombre");
				nom=r.next();
				System.out.println("Ingresa el puntaje");
				p=r.nextInt();
				l.insertar(Ins(nom, p));
				break;
			case 2: System.out.println("Qué número de jugador deseas borrar?");
				k=r.nextInt();
				if(k>n && k<1){System.out.println("número de jugador inválido");}
				else{l.borrar(k);}
				break;
			case 3: l.ver(); break;
			case 4: System.exit(0);
			}}
	}

static jugador Ins(String n, int p){
	jugador a=new jugador(n,p); return a;}
}//FIN
