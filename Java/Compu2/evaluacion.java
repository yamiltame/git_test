class evaluacion{

public static void main(String[]args){
	busqueda B=new busqueda();
	B.insFile();
	busqueda A=B;
	busqueda C=B;
	
	long t1=System.currentTimeMillis();
	B.quicksort();
	long t2=System.currentTimeMillis();
	long tf=t2-t1;
	System.out.println("Tiempo de Quicksort: "+tf);

	t1=System.currentTimeMillis();
	A.selection();
	t2=System.currentTimeMillis();
	tf=t2-t1;
	System.out.println("Tiempo de Selection sort: "+tf);

	t1=System.currentTimeMillis();
	C.insertion();
	t2=System.currentTimeMillis();
	tf=t2-t1;
	System.out.println("Tiempo de insertion sort: "+tf);

	C.Ver();}
}
