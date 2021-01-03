import math

def angulo(t):
	return (450.0-t)*math.acos(-1.0)/180.0

def dz(b):
	return (191.0*b)/math.sqrt(25.0*25.0 + b*b)

def dr(b):
	return 25.0*191.0/math.sqrt(25.0*25.0 + b*b)

def make_points(entrada,salida):
	f=open(entrada,"r")
	c=open(salida,"w+")
	T=f.readlines()
	z=0.0
	x=0.0
	y=0.0
	c.write("%f %f %f\n" % (x,y,z))
	for l in T:
		data=l.split(" ")
		b=float(data[0])
		t=float(data[1])
		a=angulo(t)
		z=z+dz(b)
		x=x+dr(b)*math.cos(a)
		y=y+dr(b)*math.sin(a)
		c.write("%f %f %f\n" % (x,y,z))
	c.write("%f %f %f\n" % (0,0,0))
	f.close()
	c.close()

make_points("data","contorno")
make_points("datacor","contornocor")

N=open("niveles","r")
T=N.readlines()
i=0
z=0.0
x=0.0
y=0.0
c=1
for l in T:
	name="nivel"+str(c)
	file=open(name,"w+")
	data=l.split(" ")
	if(i % 4==0 ):
		a=angulo(float(data[0]))
	if(i % 4==1):
		b=float(data[0])
		x=x+dr(b)*math.cos(a)
		y=y+dr(b)*math.sin(a)
		z=z+dz(b)
		file.write("%f %f %f\n" % (x,y,z))
	if(i % 4==2):
		for d in data:
			a=angulo(float(d))
			b=0.0
			x=x+dr(b)*math.cos(a)
			y=y+dr(b)*math.sin(a)
			file.write("%f %f %f\n" % (x,y,z))
	if(i % 4==3):
		file.close()
		c=c+1
	i=i+1
	
N.close()
