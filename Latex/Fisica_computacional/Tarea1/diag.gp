set terminal latex
set output 'diagrama.tex'
set size 1,1
set xlabel '$r$'
set ylabel '$x_f$'
set key noautotitle
plot [-5:0][-3:3] 'Bifurcacion.dat' w p pt 7 ps 0.4