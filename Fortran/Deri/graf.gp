set terminal png
set output "cos.png"
set size 1,1
set key noautotitle
set key title '$cos(x)$'
plot 'cos.dat' 
set output "derivada.png"
set size 1,1
set key noautotitle
set key title 'derivada'
plot 'deriv.dat'
