set terminal latex
set output 'grafica2.tex'
set size 1,1
set key autotitle columnheader
set xlabel '$t$'
set ylabel 'valor'
plot [0:1.6][-20:20] for [i=2:5] 'LE_trans.dat' using 1:i w l 
