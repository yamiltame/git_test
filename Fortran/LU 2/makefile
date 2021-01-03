main: parametros.o variables.o subrutinas.o programa.o
	gfortran -o main parametros.o variables.o subrutinas.o programa.o

parametros.o: parametros.f90
	gfortran -O -c parametros.f90
variables.o: variables.f90
	gfortran -O -c variables.f90
subrutinas.o: subrutinas.f90
	gfortran -O -c subrutinas.f90
programa.o: programa.f90
	gfortran -O -c programa.f90

clean: 
	rm *.mod; rm *.o; rm *.dat; rm main
