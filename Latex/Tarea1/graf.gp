set terminal latex
set output 'graf.tex'
set size 1,1
set xlabel '$x$'
set ylabel '$f(x)=\dot{x}$'
set key noautotitle
set xzeroaxis
set yzeroaxis
plot [-1:1][-1:1] x - x/(1+x*x)
