import math
import cmath
import numpy as np
import matplotlib.pyplot as plt
import scipy.linalg as la

#condiciones iniciales
x0=60.05
y0=2.043
z0=0.031

A=np.array([
[-0.189,6.794,-61.831],
[0.002,-0.07,0.02],
[0.001,-0.038,0.238]
])

evals,evecs = la.eig(A)

b=np.array([x0,y0,z0])

c=np.linalg.solve(evecs,b)

k1=evecs[:,0]
k2=evecs[:,1]
k3=evecs[:,2]

print "EIGENVALORES \n",evals
print "EIGENVECTORES\n",k1
print k2
print k3

print "Coeficientes para condiciones iniciales\n",c


popo=cmath.exp(3.1416j)
print popo



def solchid(t):
	x=[0,0,0]
	lr=evals[1].real
	li=evals[1].imag
	cr=c[1].real
	ci=c[1].imag
	for i in range(3):
		x[i]=c[0]*k1[i].real*math.exp(evals[0]*t)+math.exp(lr*t)*(cr*k2[i].real*2*math.cos(li*t)-cr*k2[1].imag*2*math.sin(li*t)-ci*k2[1].real*2*math.sin(li*t)+ci*k2[1].imag*2*math.cos(li*t))
	return x

def solucion(t):
	x=[0,0,0]
	for i in range(3):
		x[i]=c[0]*k1[i]*cmath.exp(evals[0]*t)+c[1]*k2[i]*cmath.exp(evals[1]*t)+c[2]*k3[i]*cmath.exp(evals[2]*t)
	return x

alces=open("alces_1.txt","w")
coyotes=open("coyotes_1.txt","w")
lobos=open("lobos_1.txt","w")

for t in range(101):
	agno=t
#	P=solucion(t)
	P=solchid(t)
	alces.write("%f,%f\n" % (agno,P[0]) )
	coyotes.write("%f,%f\n" % (agno,P[1]) )
	lobos.write("%f,%f\n" % (agno,P[2]) )

#estimaciones de tiempo 
P=solchid(50)
print "en 50 agnos"
print "Alces: ",P[0]
print "coyotes: ",P[1]
print "lobos: ",P[2]

P=solchid(100)
print "en 100 agnos"
print "Alces: ",P[0]
print "coyotes: ",P[1]
print "lobos: ",P[2]
P=solchid(150)
print "en 150 agnos"
print "Alces: ",P[0]
print "coyotes: ",P[1]
print "lobos: ",P[2]
P=solchid(200)
print "en 200 agnos"
print "Alces: ",P[0]
print "coyotes: ",P[1]
print "lobos: ",P[2]

alces.close()
coyotes.close()
lobos.close()
	
