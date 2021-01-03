!para cuando tenemos una funcion numerica
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


real(8) function rectangulo
	use variables
	real(8) h
	rectangulo=0
	h=(b-a)/n
	do i=0,n
		rectangulo=rectangulo+funcionloca(a+h*i)*h
	end do
	return
end function

real(8) function trapecio
	use variables
	real(8) h
	h=(b-a)/n
	trapecio=0
	do i=0,n-1
		trapecio=trapecio+(h/2)*(funcionloca(a+h*i)+funcionloca(a+h*(i+1)))
	end do
	return
end function

real(8) function simpson
	use variables
	real(8)	h
	h=(b-a)/n
	simpson=0
	do i=0,n-1
		simpson=simpson+(h/6)*(funcionloca(a+h*i)+4*funcionloca(a+(h/2)*(2*i+1))+funcionloca(a+h*(i+1)))
	end do
	return
end function

