import java.util.Scanner;
import java.util.Random;

class test{
	
	static arbolrn A=new arbolrn();
	static Random rnd= new Random();
	static Scanner r=new Scanner(System.in);
	static Scanner opc= new Scanner(System.in);

public static void main(String[]args){
	llenar(pedirnum("Ingresa número de datos: "));
	menu();
	}

static void llenar(int n){
	for(int i=0;i<n;i++){
		A.insertar(rnd.nextInt()%101);}
	}

static int pedirnum(String mess){
	int s=0;
	boolean E=true;
	do{
		try{
			System.out.print(mess);
			s=r.nextInt();
			E=false;}
		catch(java.util.InputMismatchException e){
			System.out.println("Error! Ingresa números Enteros");
			r=new Scanner(System.in);}
	}while(E);
	return s;
	}

static void menu(){
	int s,num;
	System.out.println("El Arbol fue llenado aleatoriamente");
	System.out.println("Ingresa la opción");
for(;;){System.out.println("1.Ingresar dato   2.Ver arbol in-order  3.buscar dato  4.Salir");
        System.out.print("Opción: ");
	s=pedirnum("");
	System.out.println("---------");
	while(s!=1 && s!=2 && s!=3 && s!=4){
		System.out.println("Opción inválida. Ingresa una opción válida");
		s=pedirnum("");}
        switch (s){
                case 1: A.insertar(pedirnum("Dato a insertar: "));
			System.out.println("----------"); 
			break;
                case 2: A.inorder(A.raiz); 
			System.out.println("----------"); 
			break;
                case 3: num=pedirnum("Dato a buscar: ");
			if(A.buscar(A.raiz,num)==A.N){
				System.out.println("No existe el dato");}
			else{
				System.out.println("Sí está el dato");}
			System.out.println("----------"); 
				
			break;
                case 4: System.exit(0);
                }
        }
	}
}//FIN
	
