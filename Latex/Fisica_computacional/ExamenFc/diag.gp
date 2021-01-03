set term png
set output 'bif.png'
plot [27:28][0:2] 'rk2.dat' w p pt 7 ps 1
