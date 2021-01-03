import java.util.Scanner;
class prueba{

static pila P=new pila();
static Scanner r=new Scanner(System.in);

public static void main(String[]args){
	menu();}

static void menu(){
	System.out.println("ingresa el número de lo que deseas hacer");
	
for(;;){System.out.println("1.Ingresar dato   2.Vaciar   3.Ver tope   4.Borrar el tope   5.Ver y Borrar tope  8.Ver pila   9.Salir"); 
	int s=r.nextInt();
	switch (s){
		case 1: P.push(); break;
		case 2: P.Vaciar(); break;
		case 3: System.out.println("{"+P.Top()+"}"); break;
		case 4: P.pop(); break;
		case 5: System.out.println("{"+P.topypop()+"}"); break;
		case 6: if(P.Vacia()){System.out.println("sí está vacía");}
			else{System.out.println("no está vacía");}
			break;
		case 7: P.duplica(); break;
		case 8: P.imprimir(); break;
		case 9: System.exit(0);
		}
	}
}
}
