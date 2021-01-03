program interpolacion
	use variables
	real(8) newton,l,abs,r,horner,Lagrange,Error
	call Inicializar('puntos.dat')
	call calculardiferencias
	do i=2,n
		r=Error(2.0d0,i-1)
		print*, 'Error estimado con',i-1,'puntos en 2.0:',r
		newton=horner(2.0d0,i)
		print*, 'valor con interpolacion newton',i,'puntos:',newton			
		l=Lagrange(2.0d0,i)
		print*, 'valor con interpolacion lagrange',i,'puntos:',l	
		abs=log(2.0d0)- newton
		print*, 'Error absoluto Newton en 2.0 con',i,'puntos:',abs
		abs=log(2.0d0)- l
		print*, 'Error absoluto Lagrange en 2.0 con',i,'puntos:',abs
	end do
end program
