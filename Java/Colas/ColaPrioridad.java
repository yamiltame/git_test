/*
 * ImplementaciÃ³n de la estructura de datos "Cola de prioridad"
 *
 *		La cola de prioridad es una estructura de datos que realiza
 *		las siguientes operaciones:
 *		a) Insertar un elemento;
 *		b) Borrar el valor mÃ¡ximo.
 *
 *    La cola de prioridad se implementa con un heap o montÃ­culo.
 *
 *    El Ã¡rbol binario es una estructura de multinivel donde se tiene
 *    una relaciÃ³n de un elemento con, posiblemente, otros dos elementos.
 *    El elemento del cual dependen los otros dos elementos, es conocido
 *    como "nodo padre" y a los otros como "nodos hijos", siendo el primero
 *    de estos el nodo izquierdo y el otro el nodo derecho.
 *
 *    El heap es un Ã¡rbol binario balanceado que se va llenando 
 *    por niveles. El heap tiene la propiedad de que el valor de
 *    cualquier nodo interno es mayor o igual que sus hijos.
 *
 * 	Para representar al Ã¡rbol binario se hace de manera implÃ­cita
 * 	usando un arreglo. 
 *
 * 	Como se requiera saber el Ã­ndice donde se encuentran los
 * 	nodos que tienen relaciÃ³n con el nodo i, se puede usar lo
 * 	siguiente:
 * 	 
 *        hijo izquierdo  2i+1
 *        hijo derecho    2(i+1)
 *        padre           (i-1)/2
 */

public class ColaPrioridad {
	private int tam = 0; /* cantidad de elementos en la cola de prioridad */
	private int[] arbol; /* Arreglo para guardar el Ã¡rbol binario */
	public static int CAP = 100; /* Capacidad mÃ¡xima del arreglo */

	/* Constructor de la cola de prioridad */
	public ColaPrioridad() {
		arbol = new int[CAP];
	}

	/* MÃ©todo para insertar en la colecciÃ³n un valor pasado. Se agrega
	 * en el nivel mÃ¡s inferior y en la posiciÃ³n mÃ¡s a la derecha.
	 * Como se usa un arreglo esta posiciÃ³n estÃ¡ en la primera localidad
	 * vacÃ­a mÃ¡s a la izquierda. 
	 * DespuÃ©s de insertar se debe revisar que se mantenga la propiedad
	 * del heap, revisando el valor insertado contra el valor del nodo
	 * padre.
	 */
	public void insertar(int v) {
		/* Antes de insertar verificar si hay espacio */
		if ( tam == CAP )
			System.out.println("Â¡Cola llena! ");
		else {
			/* Se realiza una revisiÃ³n ascendente de la propiedad del heap */
			arbol[tam] = v; // Se inserta en la siguiente posiciÃ³n vacÃ­a
			int hijo = tam;
			int padre = (hijo-1)/2;
			tam++;
			while( padre!=hijo &&  arbol[padre]<arbol[hijo] ) {
				/* intercambiar */
				int t = arbol[padre]; /* variable temporal para el intercambio */
				arbol[padre] = arbol[hijo];
				arbol[hijo] = t;
				hijo = padre;
				padre = (hijo-1)/2;
			}
		}
	}

	/* MÃ©todo para quitar de la colecciÃ³n el mÃ¡ximo valor.
	 * Se realiza una revisiÃ³n descendente, donde el valor
	 * de la raÃ­z se compara contra el mÃ¡ximo de sus hijos.
	 * En el caso de que sea menor se hace un intercambio y
	 * se sigue revisando hacia abajo hasta que se cumpla
	 * la propiedad o se llegue al Ãºltimo nivel.
	 */
	public int borrar() {
		int max = -1; // variable para devolver el mÃ¡ximo
		if ( tam != 0 ) {
			max = arbol[0]; // Guardar en max el valor mÃ¡s grande 
			tam--;
			arbol[0] = arbol[tam]; // Mover el Ãºltimo elemento insertado a la raÃ­z
			int padre = 0;
			int hijo = 1; // hijo izquierdo

			// obtener el mayor entre hijo izquierdo y derecho
			if( hijo+1<tam && arbol[hijo]<arbol[hijo+1] )
				hijo++;

			while( hijo<tam && arbol[padre]<arbol[hijo] ) {
				// intercambiar por no cumplir la propiedad
				int t = arbol[padre];
				arbol[padre] = arbol[hijo];
				arbol[hijo] = t;

				// bajar un nivel, entonces el nuevo padre es el hijo
				// y calcular el nuevo hijo izquierdo
				padre = hijo;
				hijo = 2*padre+1;
				if( hijo+1<tam && arbol[hijo]<arbol[hijo+1] ) 
					hijo++;
			}

		}
		return max;
	}

	public boolean vacia() {
		return tam==0;
	}

	public String toString() {
		String a = "TamaÃ±o: "+tam+", [";
		for(int i=0; i<tam; ++i) {
			if( i != 0 )
				a += ",";
			a += arbol[i];
		}
		a += "]";
		return a;
	}

	public static void main(String[] args) {
		ColaPrioridad cp = new ColaPrioridad();
		System.out.println("Realizando aleatoriamente 100 operaciones en la cola de prioridad ...");
		for(int i=0; i<30; i++) {
			if(Math.random()<0.75) {
				int val = (int) (Math.random()*100+1);
				System.out.println("  --> Agregar  "+val);
				cp.insertar(val);
			}
			else {
				System.out.print("  <-- Borrar mÃ¡ximo: ");
				int max = cp.borrar();
				System.out.println(max==-1 ?  "cola vacÃ­a" : max);
			}
			System.out.println("   Estado: "+cp);
		}
		if(!cp.vacia()){
			System.out.println(" vaciando cola de prioridad (mayor a menor)...");
			while(!cp.vacia())
				System.out.println("    "+cp.borrar());
		}

	}
}
