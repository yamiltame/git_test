class lista{
	nodo I= new nodo();
	nodo t;

void agregarInicio(int v){
	t=I;
	I=new nodo(v);
	I.Sig=t;
	}

void print(){
	t=I;
	while(t.Sig!=null){
		System.out.print(t.val+",");
		t=t.Sig;
		}
	}

lista(){
	I=new nodo(0);}
}
