set terminal latex
set output 'error_tol1e-06_h0.02.tex'
set size 1,1
 set key noautotitle
set xlabel '$x$'
set ylabel 'error'
plot [1:2][0:0.02] 'error_tol1e-06_h0.02' w p pt 7 ps 0.4