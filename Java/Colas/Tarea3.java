//Mauricio Yamil Tame Soria 1231314F
//mytame
//Tarea 3


import java.util.Random;
class tarea3{

public static void main(String[]args){
	int i;
	int[] M=new int[10];
	for(i=0;i<10;i++){
		M[i]=(int)(Math.random()*10);}
	System.out.println("arreglo no ordenado");
		for(i=0;i<10;i++){
		System.out.print(M[i]+", ");}

	ColaPrioridad C=new ColaPrioridad();
	for(i=0;i<10;i++){
		C.insertar(M[i]);}
	for(i=9;i>=0;i--){
		M[i]=C.borrar();}
	System.out.println();	
	System.out.println("arreglo ordenado");
		for(i=0;i<10;i++){
		System.out.print(M[i]+", ");}
	System.out.println();
	}

}//FIN
