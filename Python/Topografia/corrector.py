import math

def diferencia(angulo1, angulo2):
	da=angulo2-angulo1
	angulo= angulo1 + da/10
	return angulo


f=open("data","r")
c=open("datacor","w+")
b=float(f.readline().split(" ")[0])
a=float(f.readline().split(" ")[1])
c.write("%f %f\n" % (b,a))
da=0.0                    
i=1
j=0
s=0.0
T=f.readlines()
for l in T:
	i=i+1
	aa=a
	b=float(l.split(" ")[0])
	a=float(l.split(" ")[1])
	if(i<=58):
		c.write("%f %f\n" % (b,a))
	if(i>58):
		print a
		c.write("%f %f\n" % (b,178))

f.close()
c.close()
