import java.util.Arrays;
import java.io.*;
import java.util.Scanner;
class busqueda{
	String[] A;
	int k,i,j;

busqueda(){
	}

void buscar(String p){
	for(k=0;k<A.length;k++){
		if(A[k].compareToIgnoreCase(p)==0){A[k]=A[k].toUpperCase();}
		else{}}
	Ver();
	}

void insFile(){
	System.out.println("Escribe el nombre del archivo, DEBE ESTAR EN EL DIRECTORIO");
	Scanner r=new Scanner(System.in);
	String arch=r.next();
	i=0;
	j=0;
	try{
		File f=new File(arch);
		r=new Scanner(f);
		while(r.hasNext()){
			r.next();
			i++;}
		A=new String[i];
		r=new Scanner(f);
		while(r.hasNext()){
			String word=r.next();
			A[j]=word; j++;}
		}
	catch(IOException e){e.printStackTrace();}

	}

void Ver(){
System.out.println();
System.out.println("ARCHIVO DE TEXTO:");
System.out.println();
	for(k=0;k<A.length;k++){
		System.out.print(A[k]+" ");}
	System.out.println();}

void quicksort(){
	Arrays.sort(A);}

void selection(){
	for(i=0;i<A.length-1;i++){
		int min=i;
		for(j=i+1;j<A.length;j++){
			if(A[j].compareTo(A[min])<0){
				min=j;}
			}
	if(i!=min){swap(i,min);}

		}	
	}

void swap(int i, int min){
	String t=A[i];
	A[i]=A[min];
	A[min]=t;}

void insertion(){
	for(i=1;i<A.length;i++){
		String t=A[i];
		for(j=i-1;j>=0&&A[i].compareTo(t)<0;j--){
			A[j+1]=A[j];}
	A[j+1]=t;}
	}


}//FIN

