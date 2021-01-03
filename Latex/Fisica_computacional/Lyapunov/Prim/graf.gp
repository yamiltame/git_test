set terminal latex
set output 'grafica1.tex'
set size 1,1
set key autotitle columnheader
set xlabel '$t$'
set ylabel 'valor'
plot for [i=2:5] 'LE_trans.dat' using 1:i w l 
