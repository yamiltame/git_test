import java.util.Scanner;

class multmatr{

static Scanner opc=new Scanner(System.in);
static int m[][];
static int s[][];

public static void main(String[]args){
	int i;
        int n=pedirnum("ingresa el número de matrices a multiplicar: ");
        int p[]=new int[n+1];
        boolean compatible=true;
        m=new int[n+1][n+1];
        s=new int[n+1][n+1];
        int dimensiones[]=new int[2*n];
        for(i=0;i<(2*n);i+=2){
                System.out.println("Matriz A"+((i/2)+1));
                dimensiones[i]=pedirnum("filas: ");
                dimensiones[i+1]=pedirnum("columnas: ");}
        for(i=1;i<((2*n)-1);i+=2){
                if(dimensiones[i]!=dimensiones[i+1]){
                        compatible=false;
                        break;}
                }
        if(compatible){
                p[0]=dimensiones[0];
                for(i=1;i<n;i++){
                        p[i]=dimensiones[2*i-1];}
		p[n]=dimensiones[2*n-1];
                Matrixchainorder(p);
		System.out.println("FORMA ÓPTIMA DE MULTIPLICAR: ");
		printoptimal(s,1,n);
		System.out.println("");
		System.out.println("");
		}
        else{ System.out.println("Matrices incompatibles");}

}

static int pedirnum(String mess){
        int s=0;
        boolean E=true;
        do{
                try{
                        System.out.print(mess);
                        s=opc.nextInt();
                        E=false;}
                catch(java.util.InputMismatchException e){
                        System.out.println("Error! Ingresa números Enteros");
                        opc=new Scanner(System.in);}
        }while(E);
        return s;
        }

static void printoptimal(int s[][],int i,int j){
	if(i==j){
		System.out.print("A"+i);}
	else{
		System.out.print("(");
		printoptimal(s,i,s[i][j]);
		printoptimal(s,s[i][j]+1,j);
		System.out.print(")");}
	}

static void Matrixchainorder(int p[]){
	int n=p.length-1;
        int i,l,j,k;
        for(i=1;i<=n;i++){
                m[i][i]=0;
		}
        for(l=2;l<=n;l++){
                for(i=1;i<=(n-l+1);i++){
                        j=i+l-1;
                        m[i][j]=1000000000;
                        for(k=i;k<=(j-1);k++){
                                int q= m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j];
                                if(q<m[i][j]){
                                        m[i][j]=q;
                                        s[i][j]=k;
                                        }
                                }
                        }
                }
        }

}//FIN
