class nodo{
        nodo sig,ant;
        double val;

nodo(){}

nodo(double v){
        sig=null;
        ant=null;
        val=v;}

}//FIN class nodo

class lista{
        nodo I;
        nodo t;
        int elementos=0;

lista(){
        I=null;}

void insertar(nodo x){
        if(elementos==0 || I==null){
                I=x;
                ++elementos;}
        else{
		if(x.val>I.val){ 
			double temp=x.val;
			x.val=I.val;
			I.val=temp;}
                x.sig=I;
                if(I!=null){ I.ant=x;}
                I=x;
                x.ant=null;
                ++elementos;}
        }

void print(){
        t=I;
        if(elementos==0){
                System.out.println(".");}
        else{
                while(t!=null){
                        if(t.sig==null){System.out.print(t.val);}
                        else{System.out.print(t.val+",");}
                        t=t.sig;
                        }
                System.out.println("");}
        }

}//FIN class lista

class bucket{
	lista[] B;

bucket(int n){
	B=new lista[n];
	for(int i=0;i<B.length;i++){
		B[i]=new lista();}
	}

void insertar(double[] A){
	int j=0;
	for(int k=0;k<B.length;k++){
			nodo t=B[k].I;
		for(int i=0;i<B[k].elementos;i++){
			while(t!=null){
				A[j]=t.val;
				j=j+1;
				t=t.sig;}
			}
	}
	}

void bucketsort(double[] A){
	int i;
	for(i=0;i<A.length;i++){
		B[(int)Math.floor(A.length*A[i])].insertar(new nodo(A[i]));}
	insertar(A);
	}
		
}//FIN class bucket

