subroutine Inicializar
	use parametros
	use variables
	real dx
	integer i
	allocate(X(0:n))
	allocate(F(0:n))
	allocate(D(0:n))
	dx=(cs-ci)/n
	do i=0,n
		X(i)=dx*i
		F(i)=cos(X(i))
	end do
end subroutine

subroutine derivada
	use variables
	use parametros
	integer i
	dx=(cs-ci)/n
	do i=0,n-1
		D(i)=(F(i+1)-F(i))/dx
	end do
end subroutine

subroutine escribir
	use parametros
	use variables
	open(0,file='cos.dat')
	do i=0,n
		write(0,*) X(i),F(i)
	end do
	close(0)
	open(1,file='deriv.dat')
	do i=0,n
		write(1,*) X(i),D(i)
	end do
	close(1)	
end subroutine 

