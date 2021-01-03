set terminal latex
set output 'exponentes2.tex'
set size 1,1
set key noautotitle
set key title 'exponentes' 
set xlabel '$t$'
plot 'LE.dat' w l 
