/*************************************************/
/**** Calculo de los Coeficientes de Lyapunov ****/
/****        con el metodo de Benettin        ****/
/***** para el Modelo hipercaotico de Rossler ****/
/*************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "nrutil.c"

#define SIX (1.0/6.0)

FILE *fp;
double a, b, c, d, Delta_t,x0,Y0,z0,w0;
int ntau, Nr, Ntot,Ntrans,IO;

int main()
{
  void mirk4(double y[], int n, double h, double yout[],double t,
	     void (*derivadas)(double t, double y[],double f[]));
  void parametros();
  void derivadasRossler(double t, double y[], double f[]);
  void derivadas(double t, double y[], double f[]);
  void OGS(double v1[], double v2[], double v3[], double v4[], double V1[], 
	   double V2[], double V3[], double V4[], double N[]);

  double *cum,*yR,*yRout,*y,*yout,*v1,*v2,*v3,*v4,*V1,*V2,*V3,*V4,*N;
  double t;
  int n,j,k,m;

  yR=dvector(1,4);
  yRout=dvector(1,4);

  y=dvector(1,20);
  yout=dvector(1,20);
 
  v1=dvector(1,4);
  v2=dvector(1,4);
  v3=dvector(1,4);
  v4=dvector(1,4);
  V1=dvector(1,4);
  V2=dvector(1,4);
  V3=dvector(1,4);
  V4=dvector(1,4);
  N=dvector(1,4);
  cum=dvector(1,4);
  
  parametros();

  printf("a = %f, b= %f, c= %f, d= %f\n",a,b,c,d);
  printf("Delta_t = %f\n",Delta_t);
  Ntot=Nr*ntau;
  printf("Ntot= %d Nr= %d ntau= %d\n",Ntot,Nr,ntau);
  printf("Imprimiremos cada %d iteraciones de ortogonalizacion\n",IO);
  printf("CI: x0= %f, y0= %f, z0= %f, w0= %f\n",x0,Y0,z0,w0);
  printf("Daremos %d pasos para acercarnos al atractor\n",Ntrans);
  printf("Es decir, integramos de t=0 a t= %f\n",Ntrans*Delta_t);

  // Calculo (transitorio) para acercarnos al atractor
  n=4;
  t=0.0;
  fp=fopen("LE_trans.dat","w");
  fprintf(fp,"tiempo\t $x$\t $y$\t $z$\t $w$\t \n");

  // CI para el ciclo transitorio

  yR[1]=x0; yR[2]=Y0; yR[3]=z0; yR[4]=w0;

  for(j=1;j<=Ntrans;j++){
    mirk4(yR,n,Delta_t,yRout,t,derivadasRossler);
    t+=Delta_t;
    yR=yRout;
    fprintf(fp,"%e\t%e\t%e\t%e\t%e\n",t,yR[1],yR[2],yR[3],yR[4]);
  }
  printf("Fin del ciclo transitorio, se llego a\n");
  printf("(x0,y0,z0,w0)=( %e, %e, %e, %e )\n",yR[1],yR[2],yR[3],yR[4]);
  
  fclose(fp);
  
/*  x0=yRout[1];
  Y0=yRout[2];
  z0=yRout[3];
  w0=yRout[4];
  t=0.0;
  printf("Iniciaremos el calculo en\n");
  printf("x0= %f, y0= %f, z0= %f, w0= %f, t=%f\n",x0,Y0,z0,w0,t);

  // Condiciones iniciales para la evolucion de y[1,20]

  // A) Variables del modelo Hípercaotico de Rössler
  
  y[1]=x0; y[2]=Y0, y[3]=z0; y[4]=w0;
  cum[1]=0.0; cum[2]=0.0; cum[3]=0.0; cum[4]=0.0;

  // B) Variables de la ecs del espacio "tangente"

  for(k=5;k<=20;k++) y[k]=0.0;
  
  y[5]=1.0; y[10]=1.0; y[15]=1.0; y[20]=1.0;
  n=20;  // Numero de ecuaciones

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
    for(k=1;k<=4;k++){
      v1[k]=y[4*k+1];
      v2[k]=y[4*k+2];
      v3[k]=y[4*k+3];
      v4[k]=y[4*k+4];
    }
    OGS(v1,v2,v3,v4,V1,V2,V3,V4,N);
    for(k=1;k<=4;k++) 
      cum[k] = cum[k] + log(N[k]);
    // Normalice el exponente e imprima cada IO iteraciones
    
    if((m%IO)==0 || m==Nr)
      fprintf(fp,"%f\t%e\t%e\t\%e\t%e\n",t-Delta_t,cum[1]/t,
	      cum[2]/t,cum[3]/t,cum[4]/t);
    // Valores de y[] para re-entrar al ciclo del Runge-Kutta

    for(k=1;k<=4;k++){
      y[4*k+1]=V1[k];
      y[4*k+2]=V2[k];
      y[4*k+3]=V3[k];
      y[4*k+4]=V4[k];
    }
    
  }

  fclose(fp);
  printf("Lambda1= %e , Lambda2= %e, Lambda3= %e, Lambda4= %e\n",
	 cum[1]/t,cum[2]/t,cum[3]/t,cum[4]/t);
  printf("Suma de lambdas = %f\n",(cum[1]/t)+(cum[2]/t)+(cum[3]/t)+(cum[4]/t));

	*/
}

// Metodo de Runge-Kutta de orden 4

void mirk4(double y[], int n, double h, double yout[],double t,
	   void (*derivadasRossler)(double t, double y[],double f[]))
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

  derivadasRossler(t,y,f);
  for(j=1;j<=n;j++){
    k1[j] = h*f[j];
    ytemp[j] = y[j] + 0.5*k1[j];
  }

  derivadasRossler(t + 0.5*h, ytemp,f);
  for(j=1;j<=n;j++){    
    k2[j] = h*f[j];
    ytemp[j] = y[j] + 0.5*k2[j];
  }

  derivadasRossler(t+0.5*h, ytemp,f);
  for(j=1;j<=n;j++){     
    k3[j] = h*f[j];
    ytemp[j] = y[j] + k3[j];
  }

  derivadasRossler(t+h, ytemp,f);
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

void derivadasRossler(double t, double y[], double f[])
{
  f[1] = (-1)*(y[2]+y[3]);
  f[2] = y[1] + a*y[2] + y[4];
  f[3] = b + y[1]*y[3];
  f[4] = -c*y[4] + d*y[3];
}

// Derivadas del sistema compuesto: Rossler, Evolucion de Ejes

void derivadas(double t, double y[], double f[])
{
  int I;

  f[1] = (-1)*(y[2] + y[3]);
  f[2] = y[1] + a*y[2] + y[4];
  f[3] = b + y[1]*y[3];
  f[4] = c*y[4] - d*y[3];
  
  for(I=0;I<=3;I++){
    f[5+I] = (-1)*(y[9+I] + y[13+I]); 
    f[9+I] = y[5+I] + a*y[9+I] + y[17+I];
    f[13+I] = y[3]*y[5+I] + y[13+I]*y[1];
    f[17+I] = c*y[17+I] - d*y[13+I];
  }

}

// Entran los vectores v1, v2, v3, v4
// Salen V1, V2, V3, V4 ortonromalizados

void OGS(double v1[], double v2[], double v3[], double v4[], double V1[], 
	 double V2[], double V3[], double V4[], double N[])
{
  double Norma(double X[]);
  double dot(double X[], double Y[]);

  int k;
  double Coef21, Coef31, Coef32, Coef41, Coef42, Coef43;

  // Normalice el primer vector

  N[1] = Norma(v1);
  for(k=1;k<=4;k++) V1[k]=v1[k]/N[1];

  // Genere los otros 2 vectores ortogonales
  // Obtencion ndel vector V2

  Coef21 = dot(v2,V1);  
  for(k=1;k<=4;k++) V2[k] = v2[k] - Coef21*V1[k];
  N[2] = Norma(V2);
  for(k=1;k<=4;k++) V2[k] = V2[k]/N[2];

  // Obtencion del vector V3

  Coef31 = dot(v3,V1);
  Coef32 = dot(v3,V2);
  for(k=1;k<=4;k++) V3[k] = v3[k] - Coef31*V1[k] - Coef32*V2[k];
  N[3] = Norma(V3);
  for(k=1;k<=4;k++) V3[k] = V3[k]/N[3];

  // Obtencion del vector V4

  Coef41 = dot(v4,V1);
  Coef42 = dot(v4,V2);
  Coef43 = dot(v4,V3);
  for(k=1;k<=4;k++) V4[k] = v4[k] - Coef41*V1[k] - Coef42*V2[k] - Coef43*V3[k];
  N[4] = Norma(V4);
  for(k=1;k<=4;k++) V4[k] = V4[k]/N[4];

}

double Norma(double X[])
{
  int k;
  double suma;

  for(suma=0.0,k=1;k<=4;k++) suma += X[k]*X[k];

  suma = sqrt(suma);

  return suma;

}

double dot(double X[], double Y[])
{
  double suma;
  int k;

  for(suma=0.0,k=1;k<=4;k++) suma += X[k]*Y[k];

  return suma;

}

void parametros()
{
  printf("Parametros a,b,c,d\n");
  scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
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
  printf("Condiciiones iniciales x0,y0,z0,w0\n");
  scanf("%lf %lf %lf %lf",&x0,&Y0,&z0,&w0);
  printf("Escriba el numero de pasos dados para el edo transitorio\n");
  scanf("%d",&Ntrans);
}

