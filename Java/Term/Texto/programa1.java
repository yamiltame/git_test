import java.io.*;
class voltear {
public static void main (String [] args) throws IOException {
String palabra;
BufferedReader Teclado= new BufferedReader(new InputStreamReader(System.in));
System.out.println("Ingrese la palabra: ");
palabra= Teclado.readLine();
int len = palabra.length();
char[] linea = new char[len];
char[] linea1 = new char[len];
for (int i = 0; i < len; i++) {
linea[i] =palabra.charAt(i);
}
for (int j = 0; j < len; j++) {
linea1[j] = linea[len - 1 - j];
}
String palabraalreves = new String(linea1);
System.out.println(palabraalreves);
}
}


