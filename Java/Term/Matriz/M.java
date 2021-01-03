import java.util.Scanner;
class matriz{
private int[][] M;
private int x,y;
matriz(int a,int b){
	x=a;
	y=b;
	M=new int[x][y];}

public void setvalue(int cx, int cy, int v){
	M[cx][cy]=v;}

public void inicializar(){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){Scanner r=new Scanner(System.in);
				 System.out.println("valor de "+i+","+j);
				int v=r.nextInt();
				M[i][j]=v;}}}

public int damevalor(int cx, int cy){
	return M[cx][cy];}

public  int damex(){
	return x;}
public int damey(){
	return y;}
public void imprime(){
int i,j;
for(i=0;i<x;i++){
	for(j=0;j<y;j++){System.out.println("valor en "+i+","+j+" ="+M[i][j]);}}}

}//FIN 
