class quebrado
{
	private int numerador, denominador;

	quebrado()
	{
		
	}

	quebrado(int numerador, int denominador)
	{
		this.numerador = numerador;
		this.denominador = denominador;
		
	}

	public int dameNumerador ()
	{
		return numerador;
	}

	public int dameDenominador ()
	{
		return denominador;
	}

	public void cambiaNumerador(int valor)
	{
		numerador = valor;
	}

	public void cambiaDenominador(int valor)
	{
		denominador = valor;
	}

}
