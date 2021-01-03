class fact{
public static void main(String[]args){
long valor=factorial(5);
System.out.println(valor);
}
public static long factorial(long n){
long res=1;
int i=0;
for(i=0;i<n;i++) {
long x=n-i;
res=res*x;}
return res;}
}

