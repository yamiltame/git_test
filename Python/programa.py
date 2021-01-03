i=0
b=0
M=0
m=100000
sum=0.0
c=0
f=open("datos","r")
T=f.readlines()
for l in T:
	fila=l.split(" ")
	d1=int(fila[0])
	d2=float(fila[1])
	if(b!=d1):
		i=i+1
		if(b==1):
			print("evento: ",i-i/2," T_M: ",M," T_m: ",m," promedio: ",sum/c)
			m=100000
			M=0
			c=0
			sum=0.0
		b=d1
	if(d1==1):
		c=c+1
		if(d2>M):
			M=d2
		if(d2<m):
			m=d2
		sum=sum+d2

f.close()

if(b==1):
	print("evento: ",i-i/2," T_M: ",M," T_m: ",m," promedio: ",sum/c)
	
