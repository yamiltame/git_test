subroutine Inicializar
	use parametros
	use variables
	implicit none
	integer i,j
	allocate(X(n))
	allocate(Y(n))
	allocate(L(n,n))
	allocate(U(n,n))
	allocate(C(n,n))
	allocate(A(n,n+1))
	allocate(Aux(n,n+1))
	C(1,1)=3.0d0
	C(1,2)=-0.1d0
	C(1,3)=-0.2d0
	C(2,1)=0.1d0
	C(2,2)=7.0d0
	C(2,3)=-0.3d0
	C(3,1)=0.3d0
	C(3,2)=-0.2d0
	C(3,3)=10.0d0
	do i=1,n
		do j=1,n
			A(i,j)=C(i,j)
			L(i,j)=0
		end do
	end do
	A(1,4)=7.85d0
	A(2,4)=-19.3d0
	A(3,4)=71.4d0
end subroutine

subroutine DescompLU
	use parametros
	use variables
	implicit none
	integer i,j,k
	real(8) m
	U=C
	do i=1,n
		L(i,i)=1
	end do
	do j=1,n-1
		do i=j,n-1
			m=U(i+1,j)/U(j,j)
			L(i+1,j)=m
			do k=j,n
				U(i+1,k)=U(i+1,k)-A(j,k)*m
			end do
		end do
	end do
end subroutine

subroutine sustadelante
	use parametros
	use variables
	implicit none
	integer i,j
	real(8) res
	do i=1,n
		do j=1,n+1
			if (j /= n+1) then
				Aux(i,j)=L(i,j)
			else
				Aux(i,j)=A(i,n+1)
			end if
		end do
	end do
	Y(1)=Aux(1,n+1)/L(1,1)
	do i=1,n
		res=0
		do j=1,i-1
			res=res-L(i,j)*Y(j)
		end do
		Y(i)=(Aux(i,n+1)+res)/L(i,i)
	end do
end subroutine

subroutine sustatras
	use parametros
	use variables
	implicit none
	integer i,j
	real(8) res
	do i=1,n
		do j=1,n+1
			if (j /= n+1) then
				Aux(i,j)=U(i,j)
			else
				Aux(i,j)=Y(i)
			end if
		end do
	end do
	X(n)=Y(n)/U(n,n)
	do i=1,n-1
		res=0
		do j=0,i-1
			res=res-U(n-i,n-j)*X(n-j)
		end do
		X(n-i)=(Y(n-i)+res)/U(n-i,n-i)
	end do
end subroutine

subroutine imprimir
	use parametros 
	use variables
	implicit none
	integer i,j
	print*, 'Matriz L'
	do, i=1,n
    	write(*,*) ( L(i,j), j=1,n+1 )
	end do
	print*, 'Matriz U'
	do, i=1,n
    	write(*,*) ( U(i,j), j=1,n+1 )
	end do
	print*, 'resultados: ',X
end subroutine
