reset
set title "Busca ingenua"
set xlabel "Tamanho do vetor (x)"
set ylabel "Numero de iteracoes necessarias f(x)"
f(x) = a*x + b;
set nokey
set grid
set term post eps enhanced color
set out 'busca_ingenua.eps'
fit f(x) 'busca.txt' u ($1):($2) via a, b
plot 'busca.txt' u ($1):($2) w points ps 2, f(x)\
