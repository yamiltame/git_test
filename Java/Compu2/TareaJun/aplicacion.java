import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;
import java.util.Scanner;

public class aplicacion extends JFrame implements KeyListener{
	JLabel jl1=new JLabel("");	
	JLabel jl2=new JLabel("");	
	File f;
	pilaTexto P; fila F;
	int a;
	Scanner r;

public static void main(String[]args){
	aplicacion A=new aplicacion();
	A.setDefaultCloseOperation(EXIT_ON_CLOSE);
	A.setSize(400,200);
	A.setVisible(true);}

public aplicacion(){
	insFile();
	add(jl1,BorderLayout.NORTH);
	add(jl2,BorderLayout.SOUTH);
	addKeyListener(this);}

public void KeyTyped(KeyEvent e){}

public void KeyPressed(KeyEvent e){
	if(e.getKeyCode()==KeyEvent.VK_SPACE&&a==1){jl1.setText(P.topypop());}
        if(e.getKeyCode()==KeyEvent.VK_SPACE&&a==2){jl1.setText(F.sacar());}
        if(e.getKeyCode()==KeyEvent.VK_X){insFile();}
	}

public void KeyReleased(KeyEvent e){}

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
