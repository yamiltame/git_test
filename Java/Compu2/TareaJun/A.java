import java.util.Arrays;
import java.io.*;
import java.util.Scanner;

class aplicacion implements KeyListener{
	static int i,j;
	static File f;
	static Scanner r;

public static void main(String[]args){
	insPila("lista").imprimir();
	insFila("lista").imprimir();
	}

static pilaTexto insPila(String archivo){
	f=new File(archivo);
	pilaTexto P=new pilaTexto(10);
	String palabra;
	try{
		r=new Scanner(f);
		while(r.hasNext()){
			palabra=r.next();
			P.push(palabra);}
		}
	catch(IOException e){e.printStackTrace();}
	return P;}

static fila insFila(String archivo){
	f=new File(archivo);
	fila F=new fila(10);
	String palabra;
	try{
		r=new Scanner(f);
		while(r.hasNext()){
			palabra=r.next();
			F.ins(palabra);}
		}
	catch(IOException e){e.printStackTrace();}
	return F;}

}//FIN CLASE	
/*
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
*/

