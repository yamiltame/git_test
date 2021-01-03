import java.util.Scanner;
import java.awt.*;
import java.io.*; 
import java.awt.event.*;
import javax.swing.*;
 
public class app extends Frame implements KeyListener{  
	File f;
	TextField t1;
	Label l1;
	pilaTexto P; fila F;
	Scanner r;
	int a;

public app(String s ) {
  super(s); 
  insFile();  
  Panel p =new Panel();
  l1 = new Label ("Sobre la ventana pulsa espacio para ir vaciando la estructura o x para meter otro archivo" ) ;
  p.add(l1);  
  add(p);
  addKeyListener ( this ) ; 
  setSize ( 1000,1000 );
  setVisible(true);
  addWindowListener(new WindowAdapter(){
 				public void windowClosing(WindowEvent e){
 					 System.exit(0);}});
  }  


public void keyTyped ( KeyEvent e ){  
	if(e.getKeyCode()==KeyEvent.VK_SPACE&&a==1){l1.setText(P.topypop());}
	if(e.getKeyCode()==KeyEvent.VK_SPACE&&a==2){l1.setText(F.sacar());}
	if(e.getKeyCode()==KeyEvent.VK_X){insFile();}
	}
  
public void keyPressed ( KeyEvent e){  
	if(e.getKeyCode()==KeyEvent.VK_SPACE&&a==1){l1.setText(P.topypop());}
	if(e.getKeyCode()==KeyEvent.VK_SPACE&&a==2){l1.setText(F.sacar());}
	if(e.getKeyCode()==KeyEvent.VK_X){insFile();}
	}

public void keyReleased ( KeyEvent e ){  
	if(e.getKeyCode()==KeyEvent.VK_SPACE&&a==1){l1.setText(P.topypop());}
	if(e.getKeyCode()==KeyEvent.VK_SPACE&&a==2){l1.setText(F.sacar());}
	if(e.getKeyCode()==KeyEvent.VK_X){insFile();}
	}  

public static void main (String[]args ){  
	new app ( "" ) ; 
	}  
    

void insFile(){
	System.out.println("Escribe el nombre del arcivo");
	r=new Scanner(System.in);
	String arch=r.next();
	f=new File(arch);
	System.out.println("1.Pila   2.Fila");
	a=r.nextInt();
	switch(a){
		case 1: insPila();break;
		case 2: insFila();break;}
	}

void insPila(){
        P=new pilaTexto(10);
        String palabra;
        try{
                r=new Scanner(f);
                while(r.hasNext()){
                        palabra=r.next();
                        P.push(palabra);}
                }
        catch(IOException e){e.printStackTrace();}
        }

void insFila(){
        fila F=new fila(10);
        String palabra;
        try{
                r=new Scanner(f);
                while(r.hasNext()){
                        palabra=r.next();
                        F.ins(palabra);}
                }
        catch(IOException e){e.printStackTrace();}
        }
}
