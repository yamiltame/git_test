program rk2

implicit none

real, parameter :: PI = acos(-1.0)

real, dimension(2) :: y0, yout, k1, k2, ytemp

integer i, j, cuenta, imprimir, JMAX
real h, t0, t, TMAX, theta, thetapunto

! Parametros del modelo
real c, w, p 

c= 0.1
w= 17.5

! Se piden condiciones iniciales y parámetros h (paso de tiempo), TMAX y FLAG:
! Se necesitan n condiciones iniciales

print *, "Introduzca las condiciones iniciales y el parametro p:"
read *, theta, thetapunto, p

print *, "Escriba el paso deseado y el tiempo máximo de integración:"
read *, h, TMAX

print *,"A cada cuantos pasos quiere que se impriman datos:"
read *, imprimir
  
y0(1)=theta
y0(2)=thetapunto

print *, "Las condiciones iniciales son: y0(1)=", y0(1), "y0(2)=", y0(2) 
print *, "Se integra desde 0 hasta", TMAX, "con un paso", h
print *, "Se imprimirán datos a cada", imprimir, "pasos"

JMAX = ceiling(TMAX/h)
t0 = 0.0
cuenta = 0

print *, "Parametro p =", p, "Num de pasos= ", JMAX 

open(10, file = "rk2.dat")


! Ciclo principal, evolución temporal
do while(p<28) !ciclo para que haga RK2 variando el parametro p
	t0=0.0		!inicicalizar las variables a las condiciones 
	cuenta=0
	y0(1)=theta
	y0(2)=thetapunto
	yout=0
	ytemp=0
	! Imprimimos la condición inicial:
	write(10,*) p, y0(1)/PI, y0(2)
	do j = 1, JMAX   	    
	   k1(1) = y0(2)
	   k1(2) = - c*y0(2) - (1.0 + p*cos(w*t0) )*sin(y0(1))
	   !k1(2) = - sin(y0(1))

	   ytemp(1) = y0(1) + h*k1(1) 
	   ytemp(2) = y0(2) + h*k1(2) 
	   t = t0 + h

	   k2(1) = ytemp(2)
	   k2(2) = -c*ytemp(2) - (1.0 + p*cos(w*t) )*sin(ytemp(1))
	   !k2(2) = - sin(ytemp(1))

	   do i = 1, 2
		   if(yout(1)>(2*pi))then
				yout(1)=yout(1)-2*pi
			else if(yout(1)<(-2*pi)) then
				yout(1)=yout(1)+2*pi
			end if
	       	yout(i) = y0(i) + 0.5*h*(k1(i) + k2(i))
	   end do
      
	   cuenta = cuenta + 1      
	   if(cuenta == imprimir) then
			write(10,*) p, yout(1)/PI, yout(2), t
	    	 cuenta = 0
	   end if
	   
	   y0 = yout
	   t0 = t   

   end do
   p=p+0.1d0
end do

close(10)

end program rk2

