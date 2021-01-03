class nodo{
        nodo sig,ant;
        int val;

nodo(){}

nodo(int v){
        sig=null;
        ant=null;
	val=v;}

}//FIN class nodo

class lista{
	nodo I= new nodo();
	nodo t;
	int elementos=0;

lista(){
	I=new nodo();}

nodo buscar(int k){
	if(elementos==0){
		System.out.println("Lista vacía");
		return null;}
	else{
		nodo x=I;
		while(x!=null && x.val!= k){
			x=x.sig;}
		return x;}
	}

void borrar(nodo x){
	if(x==null){
		System.out.println("El elemento no existe");}
	else{
		if(x.ant!=null){
			x.ant.sig=x.sig;}
		else{
			I=x.sig;}
		if(x.sig!=null){
			x.sig.ant=x.ant;}
		--elementos;
		}
	}

void insertar(nodo x){
	if(elementos==0){
		I=x;
		++elementos;}
	else{
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

class TablaHash{
	lista[] T;

TablaHash(int k){
	T=new lista[k];
	for(int i=0;i<k;i++){
		T[i]=new lista();}
	}

int hash(int k){
	if(k<0){
		return (-k)%15;}
	else{
		return k%15;}
	}

void insertar(nodo x){
	T[hash(x.val)].insertar(x);}

nodo buscar(int k){
	return T[hash(k)].buscar(k);}

void borrar(nodo x){
	T[hash(x.val)].borrar(x);}

void imprimir(){
	for(int i=0;i<T.length;i++){
		System.out.print("T["+i+"]: ");
		T[i].print();}
	}
	
}//FIN class TablaHash

