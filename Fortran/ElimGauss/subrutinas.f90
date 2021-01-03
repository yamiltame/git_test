subroutine Inicializar
	use parametros
	use variables
	implicit none
	integer i,j
	allocate(C(n,n))
	allocate(A(n,n+1))
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
		end do
	end do
	A(1,4)=7.85d0
	A(2,4)=-19.3d0
	A(3,4)=71.4d0
end subroutine

subroutine verificar
	use parametros
	use variables
	if ( rank(C) /= rank(A)) then
		print*, 'sistema incompatible'
		call exit(0)
	else 
		print*, 'sistema compatible'
	end if
end subroutine

integer function obtenerpivote(j)
	use parametros
	use variables
	implicit none
	integer j
	real(8) M,mf,abs
	integer p,f,k
	M=0
	p=j
	do f=j,n+1
		do k=j,n+1
			mf=0.0
			abs=DABS(A(f,k))
			if( abs > mf) then
				mf=abs
			end if
		end do
		if(A(f,j)/mf > M) then
			M=A(f,j)/mf
			p=f
		end if
	end do
	obtenerpivote=p
return 
end function

subroutine cambiarfila(i,p)
	use parametros
	use variables
	implicit none
	integer i,p
	integer l
	real(8) t
	do l=1,n+1
		t=A(i,l)
		A(i,l)=A(p,l)
		A(p,l)=t
	end do
end subroutine

subroutine triangulacion
	use variables
	use parametros
	implicit none
	integer obtenerpivote
	integer j,i,k,p
	real(8) m
	do j=1,n-1
		p=obtenerpivote(j)
		call cambiarfila(j,p)
		print*, 'Pivoteo'
		call imprimir
		do i=j,n-1
			m=A(i+1,j)/A(j,j)
			do k=j,n+1
				A(i+1,k)=A(i+1,k) - m*A(j,k)
			end do
		end do
	end do 
end subroutine

subroutine unosendiagonal
	use variables
	use parametros
	implicit none
	integer i,j
	real(8) t
	do i=0,n-1
		t=A(n-i,n-i)
		do j=n-i,n+1
			A(n-i,j)=A(n-i,j)/t
		end do
	end do
end subroutine

subroutine sustitucion
	use parametros
	use variables
	implicit none
	integer i,j
	real(8) res
	allocate(R(n))
	R(n)=A(n,n+1)
	do i=1,n-1
		res=0
		do j=0,i-1
			res=res-A(n-i,n-j)*R(n-j)
		end do
		R(n-i)=A(n-i,n+1)+res
	end do
end subroutine

subroutine EliminacionGauss
	call triangulacion
	call unosendiagonal
	call sustitucion
end subroutine

subroutine GaussJordan
	use variables
	use parametros
	integer i,k,j
	real(8) t,m
	do i=1,n-1
		do j=0,i-1
			m=A(i-j,i+1)
			do k=i+1,n+1
				A(i-j,k)=A(i-j,k)-A(i+1,k)*m
			end do
		end do
	end do
end subroutine
			
subroutine imprimir
	use parametros 
	use variables
	implicit none
	integer i,j
	do, i=1,n
    	write(*,*) ( A(i,j), j=1,n+1 )
	enddo
end subroutine

subroutine imprimirresultados
	use parametros
	use variables
	print*, 'resultados: '
	print*, R
end subroutine

