class jugador{
	String Nom; int Pts;

jugador(String n, int p){
	Nom=n; Pts=p;}

int puntos(){
	return Pts;}

String imprimir(){
	String a=Nom+" = "+Pts;
	return a;}
}//FIN
