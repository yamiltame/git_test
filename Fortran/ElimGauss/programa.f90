program ElimGauss
	call Inicializar
	call verificar
	call EliminacionGauss
	print*, 'Eliminacion gaussiana'
	call imprimir
	call GaussJordan
	print*, 'Gauss-Jordan'
	call imprimir
	call imprimirresultados
end program
