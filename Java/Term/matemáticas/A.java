class cinco{
public static void main(String[]args){
int valor=potencia(7,4);
System.out.println(valor);
}
public static int potencia(int n, int p){
int res=n;
for(int i=1;i<p;i++) {
res=res*n;}
return res;}
}

