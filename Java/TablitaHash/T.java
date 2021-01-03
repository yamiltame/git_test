cd /Users/Yamil/Terminal/Dynamic ;
import java.util.Scanner;
import java.util.Random;

class test{
	static TablaHash T=new TablaHash(15);
	static Random rnd=new Random();
	static Scanner opc=new Scanner(System.in);

public static void main(String[]args){
        llenar(pedirnum("Ingresa número de datos: "));
        menu();
        }

static int pedirnum(String mess){
        int s=0;
        boolean E=true;
        do{
                try{
                        System.out.print(mess);
                        s=opc.nextInt();
                        E=false;}
                catch(java.util.InputMismatchException e){
                        System.out.println("Error! Ingresa números Enteros");
                        opc=new Scanner(System.in);}
        }while(E);
        return s;
        }

static void llenar(int n){
        for(int i=0;i<n;i++){
                T.insertar(new nodo(rnd.nextInt()%101));}
        }

static boolean siesta(nodo n){
        if(n==null){
                return false;}
        else{ return true;}
        }

static void menu(){
        int s,num;
        System.out.println("La tabla fue llenada aleatoriamente con enteros del -100 al 100");
        System.out.println("Ingresa la opción");
for(;;){System.out.println("1.Ingresar dato   2.buscar y borrar dato   3.Ver tabla   4.Salir");
        System.out.print("Opción: ");
        s=pedirnum("");
        System.out.println("---------");
        while(s!=1 && s!=2 && s!=3 && s!=4 && s!=5){
                System.out.println("Opción inválida. Ingresa una opción válida");
                s=pedirnum("");}
        switch (s){
                case 1: T.insertar(new nodo(pedirnum("Dato a insertar: ")));
                        System.out.println("----------");
                        break;
		case 2: num=pedirnum("Dato a buscar: ");
			if(T.buscar(num)==null){
                                System.out.println("No existe el dato");}
                        else{
                                System.out.println("Dato encontrado, ingresa 1 para borrar ó 0 para cancelar");
                                s=pedirnum("");
                                while(s!=1 && s!=0){
                                        System.out.println("opción inválida");
                                        s=pedirnum("");}
                                if(s==1){T.borrar(T.buscar(num));}
                                }
                        System.out.println("----------");
                        break;
		case 3: T.imprimir();
			break;
                case 4: System.exit(0);
                	}
        	}
	}
}//FIN
