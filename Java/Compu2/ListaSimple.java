class ListaSimple{

Nodo I,F,t;

ListaSimple(){
	F=null;
	I=F;}

boolean vacia(){
	return I==null;}

void insIni(Nodo n){
	n.sig=I;
	I=n;}

void insFin(Nodo n){
	F.sig=n;
	F=n;}

Nodo GetyBorrarIni(){
	if(vacia()){ System.out.println("Lista vacía");}
	else{
		t=I;
		I=I.sig;
		}
	return t;}

Nodo GetyBorrarFin(){
	if(vacia()){ System.out.println("Lista vacía");}
	else{} 
	return I;
	}

void imprimir(){
	Nodo t=I;
	while(t!=null){
		System.out.println(t.V);
		t=t.sig;}
	}
}//Fin clase
	
