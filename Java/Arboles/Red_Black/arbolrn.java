class nodo{
        nodo der,izq,ant;
        int val,color;

public nodo(){}

public nodo(int v){
        val=v;
        color=1;}

}//FIN nodo

class arbolrn{
	nodo raiz=new nodo();
	nodo N=new nodo();

arbolrn(){
	raiz=N;
	raiz.ant=N;
	raiz.der=N;
	raiz.izq=N;}

void inorder(nodo R){
	if(R!=N){
		inorder(R.izq);
		System.out.println(R.val);
		inorder(R.der);}
	}

void rotarizq(nodo x){
	if(x.der!=null){
	nodo y=x.der;
	x.der=y.izq;
	y.izq.ant=x;
	y.ant=x.ant;
	if(x.ant==N){raiz=y;}
	else{ if(x==x.ant.izq){ x.ant.izq=y;}
		else{x.ant.der=y;}
		}
	y.izq=x;
	x.ant=y;}
	else{System.out.println("No es posible rotar");}
	}

void rotarder(nodo x){
	if(x.izq!=null){
	nodo y=x.izq;
	x.izq=y.der;
	y.der.ant=x;
	y.ant=x.ant;
	if(x.ant==N){ raiz=y;}
	else{ if(x==x.ant.der){ x.ant.der=y;}
		else{ x.ant.izq=y;}
		}
	y.der=x;
	x.ant=y;}
	else{System.out.println("No es posible rotar");}
	}
	
nodo minimo(nodo r){
	nodo t=r;
	while(t.izq!=null){
		t=t.izq;}
	return t;
	}

nodo buscar(nodo n, int k){
	if(n==N || n.val==k){
		return n;}
	if(k<n.val){
		return buscar(n.izq,k);}
	else{
		return buscar(n.der,k);}
	}

nodo sucesor(nodo n){
	if(n.der!=null){
		return minimo(n.der);}
	nodo y=n.ant;
	while(y!=null && n==y.der){
		n=y;
		y=y.ant;}
	return y;
	}

void insertar(int v){
	nodo z=new nodo(v);
	nodo y=N;
	nodo x=raiz;
	while(x!=N){
		y=x;
		if(z.val<x.val){ x=x.izq;}
		else{ x=x.der;}
		}
	z.ant=y;
	if(y==N){ raiz=z;}
	else{ if(z.val<y.val){ y.izq=z;}
		else{ y.der=z;}
		}
	z.izq=N;
	z.der=N;
	z.color=1;
	arreglarinsercion(z);
	}

void arreglarinsercion(nodo z){
	nodo y;
	while(z.ant.color==1){
		if(z.ant==z.ant.ant.izq){
			y=z.ant.ant.der;
			if(y.color==1){
				z.ant.color=0;
				y.color=0;
				z.ant.ant.color=1;
				z=z.ant.ant;
				}
			else{ 
				if(z==z.ant.der){ 
					z=z.ant;
					rotarizq(z);}
				z.ant.color=0;
				z.ant.ant.color=1;
				rotarder(z.ant.ant);
				}
			}
		else{
			y=z.ant.ant.izq;
			if(y.color==1){
				z.ant.color=0;
				y.color=0;
				z.ant.ant.color=1;
				z=z.ant.ant;
				}
			else{ 
				if(z==z.ant.izq){
					z=z.ant;
					rotarder(z);}
				z.ant.color=0;
				z.ant.ant.color=1;
				rotarizq(z.ant.ant);
				}
			}
		}	
	raiz.color=0;
	}



}//FIN
				
