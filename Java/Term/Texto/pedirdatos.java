import java.io.*;
class nombre {
  public static void main (String [] args) throws IOException {
    String Nombre;
    BufferedReader Teclado= new BufferedReader 
           (new InputStreamReader(System.in));
    System.out.println("Ingrese su nombre: ");
    Nombre= Teclado.readLine();
    System.out.println("Hola "+Nombre);
  }
}
