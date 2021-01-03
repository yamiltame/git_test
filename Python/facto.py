import math

N=int(input("entra un n: "))
s=0.0
for n in range(1,N+1):
	f = float((n**5))/math.factorial(2*n)
	s = s + f
	print(f)

print("value of suma: ",s)
