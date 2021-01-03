subroutine contarlineas(archivo) !metodo para contar los puntos en el archivo
	use variables
	character (len=*) archivo
	integer i,eastat
	n=0
	open(1,file=archivo)
	do
		read(1,*,END=10)
		n=n+1
	end do
	10 close(1)
end subroutine

subroutine Inicializar(archivo) !se inicializa la matriz para calcular las diferencias asignando los 
	use variables               !puntos en las dos primeras columnas
	character (len=*) archivo
	integer i
	call contarlineas(archivo)
	allocate(D(2*n-1,n+1)) 
	D=0
	open(1,file=archivo)
	do i=1,n
		read(1,*,END=10)D(2*i-1,1),D(2*i-1,2)
	end do
	10 close(1)
end subroutine


subroutine calculardiferencias !metodo para calcular las diferencias
	use variables
	integer i,p,j
	p=0
	do i=3,n+1
		if(mod(i,2)==1) then  !checar si es par o impar la columna
			p=p+1             !si la columna es impar entonces se llena la columna en las filas pares de arriba hacia abajo usando la columna anterior y el contador 'p'
			do j=p,n-p		  !nos determina el intevalo de la diferencia y el indice de las x		
				D(2*j,i)=(D(2*j-1,i-1)-D(2*j+1,i-1))/(D(2*(j-p)+1,1)-D(2*(j+p)-1,1))
			end do
		else                  !si la columna es par llenamos la columna en las filas impares igual usando 'p' para indicar el intervalo de las diferencias 
			do j=p+1,n-p
				D(2*j-1,i)=(D(2*(j-1),i-1)-D(2*j,i-1))/(D(2*(j-p)-1,1)-D(2*(j+p)-1,1))
			end do
		end if
	end do
end subroutine

real(8) function evaluar(x) !Funcion que simula el polinomio a partir de los valores de las diferencias calculados en la matriz D
	use variables
	real(8) f,g,x
	integer i,j
	g=0                 !variable para ir sumando 
	f=1					!variable que se usa como factor de los (x-x1)(x-x2)...
	do i=1,n			!ciclo sobre la suma
		g=g+f*D(i,i+1)  
		f=1
		do j=1,i		!ciclo de la multiplicacion
			f=f*(x-D(2*j-1,1))
		end do
	end do
	evaluar=g			!valor del polinomio en x
	return
end function

real(8) function horner(x,m) !Evaluacion del polinomio usando la evaluacion de Horner
	use variables          !la unica diferencia es que la implementacion es mas sencilla ya que solo utiliza un ciclo
	real(8) x,s
	integer m
	s=D(m,m+1)
	do i=m-1,1,-1
		s=s*(x-D(2*i-1,1)) + D(i,i+1)
	end do
	horner=s
	return
end function	

real(8) function Lagrange(x,m) !funcion que simula el polinomio de Lagrange
	use variables
	real(8) x,f,L
	integer m
	f=0
	do i=1,m	!ciclo de la suma  
		L=1
		do j=1,m	!ciclo de la multiplicacion para 
			if(j/=i) then	!verificar que j e i no sean iguales
				L=L*(x-D(2*j-1,1))/(D(2*i-1,1)-D(2*j-1,1)) 
			end if
		end do
		f=f+L*D(2*i-1,2)	!sumar el factor de los cocientes (x-x2)(x-x3).../(x1-x2)(x1-x3)... por el valor de f(xi) representado por D(2*i-1,2)
	end do
	Lagrange=f 
	return
end function

real(8) function Error(x,m) !funcion para calcular el error del polinomio de Newton
	use variables
	integer m,i
	real(8) x,mult
	mult=1
	if(m>=n) then			!verificar que m no es mayor o igual a n, ya que necesitamos m+1 puntos y solo tenemos n
		print*, 'Falta un punto, no es posible calcular el error'
	else		
		do i=1,m			!ciclo de la multiplicacion sobre (x-x1)(x-x2)...(x-xm)
			mult=mult*(x-D(2*i-1,1))
		end do
		Error=mult*D(m+1,m+2) !multiplicar por el factor F[xm+1,xm,...,x1] que esta representado por D(m+1,m+2)
		return
	end if
end function
	
subroutine imprimir !metodo que imprime la matriz con formato de tabla, lo utilice para verificar el funcionamiento del codigo
    use variables
    implicit none
    integer i,j
    do, i=1,2*n-1
        write(*,*) ( D(i,j), j=1,n+1 )
    enddo
end subroutine

