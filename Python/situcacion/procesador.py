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

#paso de euler
def eulerx(x,y):
	return x + h*dxdt(x,y)

def eulery(x,y):
	return y + h*dydt(x,y)

#abrir archivos para los datos
#datos de x(t)
f1=open("archivoxt.txt","w")
f1.write("%f,%f\n " % (t,x))
#datos y(t)
f2=open("archivoyt.txt","w")
f2.write("%f,%f\n " % (t,y))

for i in range(1,N+1):
	#paso del tiempo
	t=t+h
	#calculamos la derivada de x
	dx=dxdt(x,y)
	#calculamos la derivada de y
	dy=dydt(x,y)
	#hacemos el paso para la siguiente x
	x=x+h*dx
	#hacemos el paso para la siguiente y
	y=y+h*dy
	#escribimos el archivo	
	f1.write("%f,%f\n " % (t,x))
	f2.write("%f,%f\n " % (t,y))

f1.close()
f2.close()

