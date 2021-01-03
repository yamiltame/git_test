import math

N=int(input("entra un n: "))
s=0.0
for n in range(1,N+1):
	f = ((-1.0)**n)/(n*n)
	s = s + f

print("value of suma: ",s)
