class nodo{
	nodo der,izq,ant;
        int val;

public nodo(){ }

public nodo(int v){
        izq=null;
        der=null;
        ant=null;
        val=v;
        }
}

class arbol{
	nodo raiz=new nodo();

arbol(){
	raiz=null;}

void inorder(nodo R){
	if(R!=null){
		inorder(R.izq);
		System.out.println(R.val);
		inorder(R.der);}
	}

nodo minimo(nodo r){
	nodo t=r;
	while(t.izq!=null){
		t=t.izq;}
	return t;
	}

nodo buscar(nodo n, int k){
	if(n==null || n.val==k){
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

void borrar(nodo z){
	nodo y,x;
	if(z.izq==null || z.der==null){
		y=z;}
	else{
		y=sucesor(z);}
	if(y.izq!=null){
		x=y.izq;}
	else{
		x=y.der;}
	if(x!=null){
		x.ant=y.ant;}
	if(y.ant==null){
		raiz=x;}
	else{
		if(y==y.ant.izq){
			y.ant.izq=x;}
		else{ y.ant.der=x;}
		}
	if(y!=z){
		z.val=y.val;}
	}
		
void insertar(int v){
	nodo n=new nodo(v);
	nodo y=null;
	nodo x=raiz;
	while(x!=null){
		y=x;
		if(n.val<x.val){
			x=x.izq;}
		else{
			x=x.der;}
		}
	n.ant=y;
	if(y==null){
		raiz=n;}
	else{
		if(n.val<y.val){y.izq=n;}
		else{y.der=n;}	
		}
	}
	
}//FIN
				
