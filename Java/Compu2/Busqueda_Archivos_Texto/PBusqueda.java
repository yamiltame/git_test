import java.util.Scanner;
class prueba{

public static void main(String[]args){menu();}


static void menu(){
	busqueda B=new busqueda();
	int e;
	String a;
	Scanner r=new Scanner(System.in);
	B.insFile();
for(;;){
	System.out.println();
	System.out.println("Teclea el número de la operación deseada");
	System.out.println("1.Insertar otro archivo   2.Buscar palabra    3.Ver archivo   4.Salir");
	e=r.nextInt();
	switch(e){
		case 1: B.insFile(); break;
		case 2: System.out.println("Inserta la palabra que deseas buscar");
			a=r.next();
			B.buscar(a);
			break;
		case 3: B.Ver(); break;
		case 4:System.exit(0);}
	}
}
}//FIN
	
