#numero de pasos
N=50000
#tiempo inicial
t0=0.0
#tiempo final
tf=200.0
#paso
h=(tf-t0)/N

#condiciones iniciales
x=60.05
y=2.043
z=0.031
t=0.0

#funcion de la derivada de x respecto al tiempo
def dxdt(x,y,z):
	return 0.009*x+0.027*y+2.043*z-0.005*x*y-1.6133*x*z+0.024*z*y

#derivada de y respecto al tiempo
def dydt(x,y,z):
	return 0.024*x+0.0005*y+5.312*z-0.01*x*y-3.959*x*z+0.048*y*z

def dzdt(x,y,z):
	return 0.009*x+0.027*y+2.043*z-0.005*x*y-1.6133*x*z+0.024*z*y

#abrir archivos para los datos
#datos de x(t)
filexrunge=open("alces.txt","w")
filexrunge.write("%f,%f\n" % (t,x))
fileyrunge=open("coyotes.txt","w")
fileyrunge.write("%f,%f\n" % (t,y))
filezrunge=open("lobos.txt","w")
filezrunge.write("%f,%f\n" % (t,z))
#empieza el ciclo del runge kutta 4
salto=0
for i in range(1,N+1):
	#paso del tiempo
	t=t+h
	#calculamos los valores de los k's
	kx1=dxdt(x,y,z)
	ky1=dydt(x,y,z)
	kz1=dzdt(x,y,z)
	kx2=dxdt(x+0.5*kx1*h,y+0.5*ky1*h,z+0.5*kz1*h)
	ky2=dydt(x+0.5*kx1*h,y+0.5*ky1*h,z+0.5*kz1*h)
	kz2=dzdt(x+0.5*kx1*h,y+0.5*ky1*h,z+0.5*kz1*h)
	kx3=dxdt(x+0.5*kx2*h,y+0.5*ky2*h,z+0.5*kz2*h)
	ky3=dydt(x+0.5*kx2*h,y+0.5*ky2*h,z+0.5*kz2*h)
	kz3=dzdt(x+0.5*kx2*h,y+0.5*ky2*h,z+0.5*kz2*h)
	kx4=dxdt(x+kx3*h,y+ky3*h,z+kz3*h)
	ky4=dydt(x+kx3*h,y+ky3*h,z+kz3*h)
	kz4=dzdt(x+kx3*h,y+ky3*h,z+kz3*h)

	#hacemos el paso en x
	x=x+(1.0/6.0)*h*(kx1+2*kx2+2*kx3+kx4)

	#hacemos el paso en y
	y=y+(1.0/6.0)*h*(ky1+2*ky2+2*ky3+ky4)

	#hacemos el paso en z
	z=z+(1.0/6.0)*h*(kz1+2*kz2+2*kz3+kz4)

	#escribimos en el archivo	
	if(salto%50==0):
		filexrunge.write("%f,%f\n" % (t,x))
		fileyrunge.write("%f,%f\n" % (t,y))
		filezrunge.write("%f,%f\n" % (t,z))

filexrunge.close()
fileyrunge.close()
filezrunge.close()

