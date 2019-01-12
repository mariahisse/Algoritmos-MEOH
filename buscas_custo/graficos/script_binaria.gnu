reset
set title "Busca binaria"
set xlabel "Tamanho do vetor (x)"
set ylabel "Numero de iteracoes necessarias f(x)"
f(x) = a*log(b*x + c) + d
set nokey
set grid
set term post eps enhanced color
set out 'busca_binaria.eps'
fit f(x) 'busca.txt' u ($1):($3) via a, b, c, d
plot 'busca.txt' u ($1):($3) w points ps 2, f(x)\
