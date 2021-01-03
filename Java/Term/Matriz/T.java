import java.util.Scanner;
class test{
public static void main(String[]args){
	for(;;){menu();}}

public static void menu(){
Scanner t=new Scanner(System.in);
int x,y,i,j;
matriz c;
System.out.println("selecciona la operación:  1.Suma  2.Multiplicación por escalar  3.SALIR");
int e=t.nextInt();
switch (e){
	case 1: System.out.println("teclea número de columnas, enter y número de filas");
		System.out.println("matriz 1");
		x=t.nextInt();
		y=t.nextInt();
		matriz mat=new matriz(x,y);
		mat.inicializar();
		System.out.println("matriz 2");
		x=t.nextInt();
		y=t.nextInt();
		matriz b=new matriz(x,y);
		b.inicializar();
		c= opmatrices.suma(mat,b);
		System.out.println("nueva matriz");
		c.imprime();
		break;

	case 2: System.out.println("número de columnas, enter y número de filas");
		x=t.nextInt();
		y=t.nextInt();
		matriz a=new matriz(x,y); a.inicializar();
		System.out.println("ingresa el escalar");
		int k=t.nextInt();
		c=opmatrices.multesc(a,k);
		System.out.println("nueva matriz");
		c.imprime();
		break;

	case 3:System.exit(0);
	default: System.out.println("opción inválida");}
}
}//FIN
