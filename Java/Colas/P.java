class puntuaciones{
	int i,j;
	jugador[] M;
	jugador t;

puntuaciones(int n){
	M=new jugador[n];
	i=0;}

void evaluar(){
	for(j=i;j>0;j--){
			if(M[j].puntos()>M[j-1].puntos()){
				t=M[j-1]; M[j-1]=M[j]; M[j]=t;}
		else{break;}}}

void borrar(int b){
	for(j=b-1;j<i;j++){
		M[j]=M[j+1]; M[j+1]=null;}}

void ver(){
	for(j=0;j<M.length;j++){
		if(M[j]==null){ System.out.println( (j+1)+".     = 0");}
		else{ System.out.println((j+1)+"."+M[j].imprimir());}}}

void insertar(jugador a){
	if(i==M.length-1){if(M[M.length-1]==null){ 
				M[i]=a; evaluar();}
			else{ if(a.puntos()>M[M.length-1].puntos()){
				M[i]=a; evaluar();}
				else{}}}
	else{M[i]=a; evaluar(); i++;}}
}//FIN
