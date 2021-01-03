class fracc{
public static void main(String[]args){
rest(1,2,3,4);}
public static void suma(int a, int b, int c, int d){
int mcd=d*b;
int n1=a*d;
int n2=b*c;
int n3=n1+n2;
System.out.println(n3+"/"+mcd);}
public static void rest(int a, int b, int c, int d){
int mcd=b*d;
int n1=a*d;
int n2=b*c;
int n3=n1-n2;
System.out.println(n3+"/"+mcd);}
public static void div(int a, int b, int c, int d){
int n1=a*d;
int n2=b*c;
System.out.println(n1+"/"+n2);}
public static void mul(int a, int b, int c, int d){
int n1=a*c;
int n2=b*d;
System.out.println(n1+"/"+n2);}
}
