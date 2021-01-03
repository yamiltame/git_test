subroutine asignarmemo
	use parametros
	use variables
	allocate(a(n,n))		
	allocate(b(n,n))		
	allocate(c(n,n))		
end subroutine

subroutine Inicializar
	use parametros
	use variables
	integer i,j
	do i=1,2
		do j=1,2
			a(i,j)=i
			b(i,j)=j
		end do
	end do
end subroutine

subroutine multiplicar
	use parametros
	use variables
	integer i,j,k
	real s
	do i=1,2
		do j=1,2
			s=0
			do k=1,2
				s=s+a(i,k)*b(k,j)
			end do
		c(i,j)=s
		end do
	end do
	print*, a
	print*, b
	print*, c
	
end subroutine 
		
subroutine escribir
    use parametros
    use variables
    integer i,j
    call multiplicar
    open(10,file='datos.dat')
    do i=1,n
        do j=1,n
            write(10,*)c(i,j)
        end do
    end do
    close(10)
end subroutine
