import java.util.Scanner;
class operacionesquebrados
{

	public static quebrado suma (quebrado a, quebrado b){
		int num=((a.dameNumerador()*b.dameDenominador())+(a.dameDenominador()*b.dameNumerador()));
		int den=a.dameDenominador()*b.dameDenominador();
		quebrado c=new quebrado(num,den);
		return c;}

	public static quebrado resta(quebrado a, quebrado b){
		int num=((a.dameNumerador()*b.dameDenominador())-(a.dameDenominador()*b.dameNumerador()));
		int den=a.dameDenominador()*b.dameDenominador();
		quebrado c=new quebrado(num, den);
		return c;}

	public static quebrado multiplicacion(quebrado a, quebrado b){
		int num=a.dameNumerador()*b.dameNumerador();
		int den=a.dameDenominador()*b.dameDenominador();
		quebrado c=new quebrado(num, den);
		return c;}

	public static quebrado division(quebrado a, quebrado b){
		int num=a.dameNumerador()*b.dameDenominador();
		int den=a.dameDenominador()*b.dameNumerador();
		quebrado c=new quebrado(num,den);
		return c;}

	
}
