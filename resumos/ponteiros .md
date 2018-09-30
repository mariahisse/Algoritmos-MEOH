

# Ponteiros

### Minha versão

O ponteiro é uma ferramenta poderosa da linguagem C/C++, pois aponta para o endereço de memória, possibilitando a oportunidade que você "brinque" com a memória em seu programa.

 - Exemplo:
 
       int n = 2;
       int *p;
       p = &n;
       std::cout << *p << std::endl; 
       
Nesse exemplo, o ponteiro `p`, recebe o endereço de memória da variável `n`, assim o conteúdo de `p` passa a ser o mesmo de `n`, pois `p` está apontando para o endereço de `n`, portanto quando executar o programa o valor de `*p` será 2. O `*` é para acessar o conteúdo de `p`.

Porém, o ponteiro deve ser usado de forma cuidadosa para não ter erro de lógica em seu programa.

