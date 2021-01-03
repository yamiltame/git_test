/*************************************************/
/**** Calculo de los Coeficientes de Lyapunov ****/
/****        con el metodo de Benettin        ****/
/****         para el Modelo de Lorenz        ****/
/*************************************************/
/********     Ricardo Becerril Bárcenas   ********/
/********        Maricela Rodriguez       ********/
/********        18 de Junio de 2013      ********/
/*************************************************/
      
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "nrutil.c"

#define SIX (1.0/6.0)

FILE *fp;

double SIGMA, B, R, Delta_t,x0,Y0,z0;
int ntau, Nr, Ntot,Ntrans,IO;

int main()
{
  void mirk4(double y[], int n, double h, double yout[],double t,
	     void (*derivadas)(double t, double y[],double f[]));
  void parametros();
  void derivadasLorenz(double t, double y[], double f[]);
  void derivadas(double t, double y[], double f[]);
  void OGS(double v1[], double v2[], double v3[], double V1[], 
	   double V2[], double V3[], double N[]);

  double *cum,*yL,*yLout,*y,*yout,*v1,*v2,*v3,*V1,*V2,*V3,*N;
  double t;
  int n,j,k,m;

  yL=dvector(1,3);
  yLout=dvector(1,3);

  y=dvector(1,12);
  yout=dvector(1,12);
 
  v1=dvector(1,3);
  v2=dvector(1,3);
  v3=dvector(1,3);
  V1=dvector(1,3);
  V2=dvector(1,3);
  V3=dvector(1,3);
  N=dvector(1,3);
  cum=dvector(1,3);

  parametros();

  printf("SIGMA = %f, B= %f, R= %f\n",SIGMA,B,R);
  printf("Delta_t = %f\n",Delta_t);
  Ntot=Nr*ntau;
  printf("Ntot= %d Nr= %d ntau= %d\n",Ntot,Nr,ntau);
  printf("Imprimeremos cada %d iteraciones de ortogonalizacion\n",IO);
  printf("CI: x0= %f, y0= %f, z0= %f\n",x0,Y0,z0);
  printf("Daremos %d pasos para acercarnos al atractor\n",Ntrans);
  printf("Es decir, integramos de t=0 a t= %f\n",Ntrans*Delta_t);

  // Calculo (transitorio) para acercarnos al atractor
  n=3;
  t=0.0;
  fp=fopen("LE_trans.dat","w");

  // CI para el ciclo transitorio

  yL[1]=x0; yL[2]=Y0; yL[3]=z0;

  for(j=1;j<=Ntrans;j++){
    mirk4(yL,n,Delta_t,yLout,t,derivadasLorenz);
    t+=Delta_t;
    yL=yLout;
    fprintf(fp,"%e\t%e\t%e\t%e\n",t,yL[1],yL[2],yL[3]);
    //printf("t=%e y1= %e y2= %e y3= %e\n",t,yL[1],yL[2],yL[3]);
  }
  printf("Fin del ciclo transitorio, se llego a\n");
  printf("(x0,y0,z0)=( %e, %e, %e )\n",yL[1],yL[2],yL[3]);
  
  fclose(fp);
  
  x0=yLout[1];
  Y0=yLout[2];
  z0=yLout[3];
  t=0.0;
  printf("Iniciaremos el calculo en\n");
  printf("x0= %f, y0= %f, z0= %f, t=%f\n",x0,Y0,z0,t);

  // Condiciones iniciales para la evolucion de y[1,12]

  // A) Variables del modelo de Lorenz
  
  y[1]=x0; y[2]=Y0, y[3]=z0;
  cum[1]=0.0; cum[2]=0.0; cum[3]=0.0;

  // B) Variables de la ecs del espacio "tangente"

  for(k=4;k<=12;k++) y[k]=0.0;
  
  y[4]=1.0; y[8]=1.0; y[12]=1.0;
  n=12;  // Numero de ecuaciones

  //Nr es el numero de ortogonalizaciones que se haran

  printf("se integraran las %d ecuaciones de t=0 a t= %f\n",
	 n,Ntot*Delta_t);

  fp=fopen("LE.dat","w");

  for(m=1;m<=Nr;m++){
    for(j=1;j<=ntau;j++){
      mirk4(y,n,Delta_t,yout,t,derivadas);
      y=yout;
      t+=Delta_t;
    }
    // Construccion de la base ortonoramal por la OGS
    for(k=1;k<=3;k++){
      v1[k]=y[3*k+1];
      v2[k]=y[3*k+2];
      v3[k]=y[3*k+3];
    }
    OGS(v1,v2,v3,V1,V2,V3,N);
    for(k=1;k<=3;k++) 
      cum[k] = cum[k] + log(N[k]);
    
    // Normalice el exponente e imprima cada IO iteraciones
    
    if((m%IO)==0 || m==Nr)
      fprintf(fp,"%f\t%e\t%e\t\%e\n",t-Delta_t,cum[1]/t,
	      cum[2]/t,cum[3]/t);
    // Valores de y[] para re-entrar al ciclo del Runge-Kutta

    for(k=1;k<=3;k++){
      y[3*k+1]=V1[k];
      y[3*k+2]=V2[k];
      y[3*k+3]=V3[k];
    }
    
  }

  fclose(fp);
  printf("Lambda1= %e , Lambda2= %e, Lambda3= %e\n",
	 cum[1]/t,cum[2]/t,cum[3]/t);
  printf("Suma de lambdas = %f\n",(cum[1]/t)+(cum[2]/t)+(cum[3]/t));

}


// Metodo de Runge-Kutta de orden 4

void mirk4(double y[], int n, double h, double yout[],double t,
	   void (*derivadas)(double t, double y[],double f[]))
{

  double *k1, *k2, *k3, *k4;
  double *ytemp,*f;
  int j;

  k1=dvector(1,n);
  k2=dvector(1,n);
  k3=dvector(1,n);
  k4=dvector(1,n);
  f=dvector(1,n);
  ytemp=dvector(1,n);

  derivadas(t,y,f);
  for(j=1;j<=n;j++){
    k1[j] = h*f[j];
    ytemp[j] = y[j] + 0.5*k1[j];
  }

  derivadas(t + 0.5*h, ytemp,f);
  for(j=1;j<=n;j++){    
    k2[j] = h*f[j];
    ytemp[j] = y[j] + 0.5*k2[j];
  }

  derivadas(t+0.5*h, ytemp,f);
  for(j=1;j<=n;j++){     
    k3[j] = h*f[j];
    ytemp[j] = y[j] + k3[j];
  }

  derivadas(t+h, ytemp,f);
  for(j=1;j<=n;j++)  
    k4[j] = h*f[j];

  for(j=1;j<=n;j++)
    yout[j]=y[j]+ SIX*(k1[j]+2.0*k2[j]+2.0*k3[j]+k4[j]);

  free_dvector(k1,1,n);
  free_dvector(k2,1,n);
  free_dvector(k3,1,n);
  free_dvector(k4,1,n);
  free_dvector(ytemp,1,n);
  free_dvector(f,1,n);
  
}

void derivadasLorenz(double t, double y[], double f[])
{
  f[1] = SIGMA*(y[2]-y[1]);
  f[2] = R*y[1] - y[2] - y[1]*y[3];
  //f[2] = R*(1.0+A*sin(W*t))*y[1] - y[2] - y[1]*y[3];
  f[3] = y[1]*y[2] - B*y[3];
}

// Derivadas del sistema compuesto: Modelo-Lorenz, Evolucion de Ejes

void derivadas(double t, double y[], double f[])
{
  int I;

  f[1] = SIGMA*(y[2]-y[1]);
  f[2] = R*y[1] - y[2] - y[1]*y[3];
  f[3] = y[1]*y[2] - B*y[3];
  
  for(I=0;I<=2;I++){
    f[4+I] = SIGMA*(y[7+I] - y[4+I]); 
    f[7+I] = (R-y[3])*y[4+I] - y[7+I] - y[1]*y[10+I];
    f[10+I] = y[2]*y[4+I] + y[1]*y[7+I] -B*y[10+I];
  }

}

// Entran los vectores v1, v2, v3
// Salen V1, V2, V3 ortonromalizados

void OGS(double v1[], double v2[], double v3[], double V1[], 
	 double V2[], double V3[], double N[])
{
  double Norma(double X[]);
  double dot(double X[], double Y[]);

  int k;
  double Coef21, Coef31, Coef32;

  // Normalice el primer vector

  N[1] = Norma(v1);
  for(k=1;k<=3;k++) V1[k]=v1[k]/N[1];

  // Genere los otros 2 vectores ortogonales
  // Obtencion ndel vector V2

  Coef21 = dot(v2,V1);  
  for(k=1;k<=3;k++) V2[k] = v2[k] - Coef21*V1[k];
  N[2] = Norma(V2);
  for(k=1;k<=3;k++) V2[k] = V2[k]/N[2];

  // Obtencion del vector V3

  Coef31 = dot(v3,V1);
  Coef32 = dot(v3,V2);
  for(k=1;k<=3;k++) V3[k] = v3[k] - Coef31*V1[k] - Coef32*V2[k];
  N[3] = Norma(V3);
  for(k=1;k<=3;k++) V3[k] = V3[k]/N[3];

}

double Norma(double X[])
{
  int k;
  double suma;

  for(suma=0.0,k=1;k<=3;k++) suma += X[k]*X[k];

  suma = sqrt(suma);

  return suma;

}

double dot(double X[], double Y[])
{
  double suma;
  int k;

  for(suma=0.0,k=1;k<=3;k++) suma += X[k]*Y[k];

  return suma;

}

void parametros()
{
  printf("Parametros SIGMA,B,R\n");
  scanf("%lf %lf %lf",&SIGMA,&B,&R);
  printf("Escriba el paso de tiempo Delta_t\n");
  scanf("%lf",&Delta_t);
  printf("Introduzca Nr: Num de ortogonalizaciones\n");
  printf("y ntau: Num de pasos de tiempo entre ortogonalizaciones\n");
  scanf("%d %d",&Nr,&ntau); 
  printf("A cada cuantos pasos imprimimos\n");
  printf("Escriba un entero IO tal que Nr/IO sea entero\n");
  scanf("%d",&IO); 
  if((Nr%IO) != 0) {
    printf("IO debe ser tal que Nr/IO es cero y no lo es, saliendo\n");
    exit(1);
  }
  printf("Condiciiones iniciales x0,y0,z0\n");
  scanf("%lf %lf %lf",&x0,&Y0,&z0);
  printf("Escriba el numero de pasos dados para el edo transitorio\n");
  scanf("%d",&Ntrans);
}
