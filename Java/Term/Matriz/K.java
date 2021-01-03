class opmatrices{

public static matriz suma(matriz a,matriz b){
	matriz c=new matriz(a.damex(),a.damey());
	int i,j,k;
	for(i=0;i<a.damex();i++){
			for(j=0;j<a.damey();j++){k=a.damevalor(i,j)+b.damevalor(i,j); c.setvalue(i,j,k);}}
return c;}

public static matriz multesc(matriz a, int b){
	matriz c=new matriz(a.damex(),a.damey());
	int i,j,k;
	for(i=0;i<c.damex();i++){
		for(j=0;j<c.damey();j++){k=a.damevalor(i,j)*b; c.setvalue(i,j,k);}}
return c;}

/*public static matriz mult(matriz a, matriz b){
	matric c=new matriz(a.damex(),b.damey());
	*/
}//FIN

