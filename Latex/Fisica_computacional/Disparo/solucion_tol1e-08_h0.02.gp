set terminal latex
set output 'solucion_tol1e-08_h0.02.tex'
set size 1,1
 set key noautotitle
set xlabel '$x$'
set ylabel '$y$'
plot [1:2][2:2.5] 'solucion_tol1e-08_h0.02' w p pt 7 ps 0.4
