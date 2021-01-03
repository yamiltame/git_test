#numero de pasos
N=1000
#tiempo inicial
t0=0.0
#tiempo final
tf=10.0
#paso
h=(tf-t0)/N

#condiciones iniciales
x=2
y=4
t=0.0

#funcion de la derivada de x respecto al tiempo
def dxdt(x,y):
	return -2*x+y

#derivada de y respecto al tiempo
def dydt(x,y):
	return -5*x+2*y

#abrir archivos para los datos
#datos de x(t)
filexrunge=open("filexR.txt","w")
filexrunge.write("%f,%f\n" % (t,x))
fileyrunge=open("fileyR.txt","w")
fileyrunge.write("%f,%f\n" % (t,y))
#empieza el ciclo del runge kutta 4

for i in range(1,N+1):
	#paso del tiempo
	t=t+h
	#calculamos los valores de los k's
	kx1=dxdt(x,y)
	ky1=dydt(x,y)
	kx2=dxdt(x+0.5*kx1*h,y+0.5*ky1*h)
	ky2=dydt(x+0.5*kx1*h,y+0.5*ky1*h)
	kx3=dxdt(x+0.5*kx2*h,y+0.5*ky2*h)
	ky3=dydt(x+0.5*kx2*h,y+0.5*ky2*h)
	kx4=dxdt(x+kx3*h,y+ky3*h)
	ky4=dydt(x+kx3*h,y+ky3*h)

	#hacemos el paso en x
	x=x+(1.0/6.0)*h*(kx1+2*kx2+2*kx3+kx4)

	#hacemos el paso en y
	y=y+(1.0/6.0)*h*(ky1+2*ky2+2*ky3+ky4)

	#escribimos en el archivo	
	filexrunge.write("%f,%f\n" % (t,x))
	fileyrunge.write("%f,%f\n" % (t,y))

filexrunge.close()
fileyrunge.close()

