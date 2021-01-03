class cola{
	int i,j,a;
	int[] M;

cola(int t){
	M=new int[t];}

void insertar(int n){
	if (M[M.length-1]==0){
		M[M.length-1]=n;
		for(j=M.length-1;j>0;j--){if(M[j]>M[j-1]){ a=M[j-1];
						M[j-1]=M[j]; 
						M[j]=a;}
					else{break;}}
			}
	else{System.out.println("cola de prioridad llena");}
	}

void borrarmayor(){
	for(j=0;j<(M.length-1);j++){M[j]=M[j+1]; M[j+1]=0;}
	}

void vermayor(){
	System.out.println(M[0]);}

void imprime(){
	for(j=0;j<M.length;j++){System.out.print(M[j]+", ");} System.out.println();
	}
}//Fin
