set terminal latex
set output 'grafica1.tex'
set size 1,1
set key autotitle columnheader
set xlabel '$t$'
set ylabel 'valor'
plot 'LE_trans.dat' w l 
