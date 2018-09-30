

# Ponteiros

### Versão com referências

O ponteiro é uma ferramenta poderosa da linguagem C/C++, pois armazena o endereço de memória, ou seja o ponteiro pode armazenar o endereço de memória de uma variável, possibilitando a oportunidade que você "brinque" com a memória em seu programa.

 - Exemplo:
 
       int n = 2;
       int *p;
       p = &n;
       std::cout << *p << std::endl; 
 
Nesse exemplo, o ponteiro `p`, recebe o endereço de memória da variável `n`, assim o conteúdo de `p` passa a ser o mesmo de `n`, pois `p` está apontando para o endereço de `n`, portanto quando executar o programa o valor de `*p` será 2. 

O `*` é para acessar o conteúdo de `p`, chamado de **derreferência**.  O `&`é utilizado para **referência** do endereço de memória.

Foi um exemplo básico utilizando ponteiro, porém o ponteiro é utilizado para fazer a alocação dinâmica de memória de variáveis, vetores, matrizes, structs, além disso, é utilizado apontar para funções entre outros.

O ponteiro é muito útil quando uma variável tem que ser acessada em diferentes partes de um programa. Porém, deve ser usado de forma cuidadosa para não ter erro de lógica em seu programa.

#### Referências:
- https://www.inf.pucrs.br/~pinho/PRGSWB/Ponteiros/ponteiros.html
- http://linguagemc.com.br/ponteiros-em-c/

