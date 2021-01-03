import java.util.Scanner;
class prueba{
	static Scanner r= new Scanner(System.in);

public static void main(String[]args){
	menu();}

public static void menu(){
	System.out.println("escribe el tamaño de la cola");
	int l=r.nextInt();
        cola fila=new cola(l);	
	int e,a,b;
	for(;;){System.out.println("1. Insertar dato   2. Conocer mayor   3. Eliminar mayor   4. Ver cola   5. Salir");
		e=r.nextInt();
		switch (e){
			case 1: System.out.println("escribe el dato");
				a=r.nextInt();
				fila.insertar(a);
				break;
			case 2: fila.vermayor();
				break;
			case 3: fila.borrarmayor();
				break;
			case 4: fila.imprime();
				break;
			case 5: System.exit(0);
			}}
}		
}//Fin
		
