class fila{

int F,A,E;
String[] M;

fila(int n){
	M=new String[n];
	F=0; A=-1; E=0;}			


boolean vacia(){
	return E==0;}

void vaciar(){
	E=0; A=F-1;}

void ins(String a){
	if(E==M.length){duplica();}
	A=(++A)%(M.length);
	M[A]=a;
	E++;}

public String sacar(){
	error();
	E--;
	String t=M[F];
	F=(++F)%(M.length);
	return t;}

public String verF(){
	error();
	return M[F];}

void error(){
	if(vacia()){System.out.println("La fila está vacía"); System.exit(0);}
	else{}}

void imprimir(){
	int c=E;
	for(int i=F;c>0;c--){
		System.out.println(M[(i%M.length)]);
		i++;}
	}

void duplica(){
	String[] N=new String[M.length*2];
	int i,j,c;
	for(i=0,j=F,c=E;c>0;c--,j++,i++){
		N[i]=M[j%M.length];}
	M=N;
	F=0; A=E-1;}	

}
