set terminal latex
set output 'error_tol1e-08_h0.01.tex'
set size 1,1
 set key noautotitle
set xlabel '$x$'
set ylabel 'error'
plot [1:2][0:0.02] 'error_tol1e-08_h0.01' w p pt 7 ps 0.4