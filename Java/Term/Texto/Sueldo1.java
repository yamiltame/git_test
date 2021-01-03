import java.io.*;
class sueldo
{
	public static void main(String args []) 
	{
		String respuesta;
		double sue;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		try
		{
			System.out.println("Intrudusca el sueldo del trabajador");
			respuesta=br.readLine();
			sue=Double.valueOf(respuesta).doubleValue();
			if(sue>=1000)
			{
				sue=sue*1.12;
			}
			else if(sue>0 && sue<1000)
			{
				sue=sue*1.15;
			}
			if(sue<0)
			{
				System.out.println("El sueldo no puede ser negativo");
			}
			else
			{
				System.out.println("El sueldo con aunmento incorporado es= "+sue);				
			}
		}
		catch(Exception e)
		{
			System.out.println("No puedes introducir letras");
		}
	}
}
