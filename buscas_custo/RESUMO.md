

# Custo computacional

### Introdução ao Custo Computacional

   Para comparar a eficiência dos algoritmos, uma medida do grau de dificuldade de um algoritmo chamado complexidade computacional foi desenvolvido por Juris Hartmanis e Richard E. Stearns. 
     <p>A complexidade computacional é um ramo que se concentra em classificar problemas computacionais e relacionar entre si, indica quanto esforço é necessário para aplicar um algoritmo ou como é caro.
   <p> Um algoritmo mesmo funcionando corretamente, pode não ser viável sua implementação por requerer muito espaço e tempo. Assim, quando se fala em complexidade computacional umas perguntas surgem, como:
   
   - O problema é tratável? 
   - O algoritmo demanda uma grande demanda de recursos computacionais?
   - E o custo desse algoritmo?
   
   Esta última pergunta exige uma análise computacional do algoritmo.

O custo de um algoritmo leva em consideração alguns aspectos, alguns deles são:
- O tempo de execução;
- Utilização da memória;
- Utilização de disco;
- Custo de implementação.

 Além destes, existem muitos outros aspectos que se leva em consideração. O tempo é geralmente o fator mais importante a ser considerado do que o espaço, então geralmente para considerar a eficiência focam na quantidade de tempo decorrido ao processar dados.

### Tempo de execução

   <p> Um algoritmo pode rodar mais rápido para certo conjunto de dados do que para outros, portanto, normalmente se considera a complexidade do pior caso do tempo. 
     <p>Se for analisar o tempo de execução de um algoritmo experimentalmente, há algumas limitações como implementar e testar o código, só pode ser feito para um conjunto limitado de casos e para comparar dois algoritmos e necessário o mesmo ambiente de hardware e software. 
     <p>Além disso, os resultados de testes em tempo de execução dependem da linguagem em que o algoritmo é escrito, mesmo sendo realizados testes na mesma máquina. Os programas que são compilados executam muito mais rápido do que quando são interpretados.
   <p>Assim para comparar dois algoritmos estima-se a eficiência de cada algoritmo para um tamanho n do problema, ou seja, calculando o número de operações sobre n elementos, determinando a taxa de crescimento de cada algoritmo. 
    Para se referir ao custo utiliza-se a notação O(n), o que significa que um algoritmo é "da ordem de",  introduzida em 1894 por Paul Bachmann.
Podemos ter:

- Tempo constante : O(1) é raro de acontecer;
- Tempo sublinear: O(log n) é muito rápido;
- Tempo linear: O(n) é muito rápido;
- Tempo O(nlog n) é mais comum;
- Tempo polinomial é considerado eficiente;
- Tempo exponencial é considerado intratável.

### Algoritmos determinísticos
 O algoritmo determinístico é um algoritmo que, dada uma certa entrada, ela produzirá sempre a mesma saída, com a máquina responsável sempre passando pela mesma sequência de estados. Algoritmos determinísticos são, de longe, o tipo mais estudado e conhecido de algoritmo, assim como um dos mais práticos, uma vez que podem ser executados em máquinas reais de forma eficiente. Por exemplo, um algoritmo que computa uma função matemática é um algoritmo determinístico, pois uma função tem um valor único para cada entrada dada e o algoritmo é um processo que produz este valor em particular como saída.
 
 Encontrar algoritmos determinísticos para alguns problemas é difícil. Por exemplo, existem algoritmos probabilísticos simples e eficientes que determinam se um dado número é primo e apresentam uma pequena margem de erro. Os algoritmos determinísticos conhecidos para resolver o mesmo problema ainda são consideravelmente mais lentos na prática.
 
### Algoritmos não determinísticos

O algoritmo não determinístico é um algoritmo que, dada uma certa entrada de dados, apresenta comportamentos diferentes em diferentes execuções, ou seja, é aquele que pode produzir resultados diferentes mesmo com os mesmos dados entrados, ao contrário de um algoritmo determinístico. 

Algoritmos que dependem de dados externos, como o tempo, concorrência ou falha de hardware, por exemplo, são exemplos de algoritmos não determinístico pois, possivelmente ou certamente produzirá um resultado diferente.

Um  exemplo também é o algoritmo probabilístico pois utiliza a probabilidade como parte de sua lógica, ou seja, o algoritmo deve acessar um gerador de números pseudo-aleatórios. O algoritmo utiliza bits aleatórios como um guia para o seu comportamento. Diferente dos algoritmos convencionais, um algoritmo probabilístico, dada uma mesma sequência de entrada, não necessariamente leva a um mesmo estado final.

### Análise sobre custo
 
   A análise foi feita em relação ao número de iterações que o algoritmo demora para encontrar um número para uma determinada entrada de dados. A entrada de dados foi gerada com números aleatórios e foi utilizado o algoritmo de quick sort para ordenar o vetor, que também possui um custo, mas que não foi levado em conta nesta análise.
   
   #### Busca ingênua
  <p> A busca ingênua percorre todo o vetor, ou seja cada posição do vetor e compara o valor ao valor buscado. Ao fazer a análise, ou seja, qual a quantidade de iterações necessárias para encontrar um valor em um vetor de tamanho x. <p>

 Foi gerado vetores de tamanho x, que no caso começa em 1000, indo de 1000 em 1000 até 100000,  com números gerados aleatoriamente de 1 até o tamanho do vetor e o número a ser procurado também foi gerado aleatoriamente. O resultado obtido foi colocado em um arquivo texto e plotado, obtendo o gráfico abaixo, que foi gerado utilizando o programa gnuplot. 
 
 ![Busca ingenua](https://i.imgur.com/gOJP3GS.jpg)
   
   Ao analisá-lo, observa-se que há um comportamento linear, ou seja uma reta, portanto fitou-se a reta f(x) = ax + b, tendo como resultado para os coeficientes a = 0,680 e b = 0,478.
 
  Portanto a busca ingênua é de ordem O(N), ou seja para um vetor de tamanho N, é provável que demore N iterações. Percebe-se que há pontos fora da reta, estes pontos são de iterações que demoraram menos, pois foi encontrado o valor procurado antes. 
   
  #### Busca binária
 <p> A busca binária é um algoritmo de busca em vetores que parte do pressuposto de que o vetor está ordenado e realiza sucessivas divisões do espaço de busca, ou seja divide o tamanho do vetor a metade, comparando o elemento buscado com o elemento no meio do vetor. Se o elemento do meio do vetor for o procurado, a busca termina com sucesso. Caso contrário, se o elemento do meio for menor que o elemento buscado, então a busca continua na metade posterior do vetor, repetindo o processo de divisão. E finalmente, se o elemento do meio vier for maior que o elemento buscado, então a busca continua na metade anterior do vetor, repetindo o processo de divisão. Esse processo acontece até que se encontre o elemento ou determina-se que não há esse elemento no vetor.  <p>

   <p>Foi gerado vetores de tamanho x, que no caso no caso começa em 1000, indo de 1000 em 1000 até 100000,  com números gerados aleatoriamente de 1 até o tamanho do vetor e o número a ser procurado também foi gerado aleatoriamente. O resultado obtido foi colocado em um arquivo texto e plotado, obtendo o gráfico abaixo, que foi gerado utilizando o programa gnuplot.
   
![Busca binaria](https://i.imgur.com/bi6ESa8.jpg)
  
   Ao analisá-lo, observa-se o comportamento de uma curva de função logarítmica, logo fitou-se a função f(x) = alog (bx + c) + d, com os valores encontrados para os coeficientes a = 1,404 e b = 0,443, c= 0,948 e d = 0,659.

  Portanto, a busca binária é de ordem O(log N), ou seja para um vetor de tamanho N é provável que demore log N iterações para encontrar o número. Percebe-se que há alguns pontos fora da reta, estes pontos são de iterações que demoraram menos, pois foi encontrado o valor procurado antes do esperado. 
  
  #### Conclusões
  
  Para a busca ingênua obtemos que a complexidade do algoritmo é de ordem O(N), ou seja, o valor esperado para se encontrar um elemento no vetor é o próprio tamanho do vetor, porém como observamos pelo gráfico, há pontos fora da reta, pois foi utilizado números aleatórios, ou seja, não produz sempre o mesmo resultado final, logo é um algoritmo probabilístico. e não se pode prever ao certo se vai demorar o valor esperado, pois pode-se encontrar antes.
  
  Para a busca binária obtemos que a complexidade do algoritmo é de ordem O(log N), porém, assim como a busca ingênua, também apresenta pontos fora da curva, isto porque é um algoritmo que também foi utilizado números aleatórios, ou seja, também não produz sempre o mesmo resultado final, logo é um algoritmo probabilístico e não se pode prever certamente quantas iterações vai demorar, pois pode encontrar antes ou depois do esperado.
  
  Com os resultados obtidos podemos concluir que a busca binária é mais indicada por ser mais rápida, ou seja, gasta-se um menor número de iterações para se encontrar o elemento em um vetor.
  
### Referências
- *Complexidade computacional*. Wikipédia. Disponível em: <https://pt.wikipedia.org/wiki/Complexidade_computacional>. Acesso em: 20 de dez. de 2018.
- *Complexidade de algoritmos*. Wiki. Disponível em: <http://wiki.icmc.usp.br/images/d/de/Analise_complexidade.pdf>. Acesso em: 20 de dez. de 2018.
- DROZDEK, A. Data Structures and Algorithms in C++.  4 ed. Boston: CENGAGE Learning, 2012.
- *O que é um Algoritmo determinístico e não determinístico?*. Stack Overflow. Disponível em: https://pt.stackoverflow.com/questions/102597/o-que-%C3%A9-um-algoritmo-determin%C3%ADstico-e-n%C3%A3o-determin%C3%ADstico. Acesso em: 02 de jan. de 2019.
