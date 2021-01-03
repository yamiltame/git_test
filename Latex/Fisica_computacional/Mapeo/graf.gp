set terminal latex
set output "R.tex"
set size 0.6,0.5
set xtics format ""
set ytics format ""
set xlabel 'Numero de individuos'
set ylabel '$r$'
set key noautotitle
set key title '$\frac{N_{n+1}}{N_n}$'
plot [0:1][0:1] 1-x*x 
