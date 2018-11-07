

# Ponteiros

### Versão com referências

 O ponteiro é uma ferramenta poderosa da linguagem C/C++, pois armazena o endereço de memória, ou seja o ponteiro pode armazenar o endereço de memória de uma variável, possibilitando a oportunidade que você "brinque" com a memória em seu programa.

 - Exemplo:
 
       int n = 2;
       int *p;
       p = &n;
       std::cout << *p << std::endl; 
 
Nesse exemplo, o ponteiro `p`, recebe o endereço de memória da variável `n`, assim o conteúdo de `p` passa a ser o mesmo de `n`, pois `p` está apontando para o endereço de `n`, portanto quando executar o programa o valor de `*p` será 2. 

O `*` é para acessar o conteúdo de `p`, chamado de **derreferência**.  O `&`é utilizado para **referência** do endereço de memória. Pode imprimir o endereço de memória que o ponteiro armazena, como o exemplo abaixo:
 - Exemplo:
 
       int n = 2;
       int *p;
       p = &n;
       std::cout << p << std::endl;         //imprime o endereço de mémoria que p armazena
       std::cout << &n << std::endl;
Nesse exemplo, vai imprimir na tela o endereço que `p` armazena, no caso o endereço de `n`. Os endereços de memória são em hexadecimal, por exemplo, 0x77ffdb0dea7ec, é um exemplo de endereço de memória.

O ponteiro é muito útil quando uma variável tem que ser acessada em diferentes partes de um programa.
Porém, deve ser usado de forma cuidadosa para não ter erro de lógica em seu programa.

Foi um exemplo básico utilizando ponteiro, porém o ponteiro é utilizado para fazer a alocação dinâmica de memória de variáveis, vetores, matrizes, structs, além disso, é utilizado apontar para funções entre outros.

 #### Arrays e ponteiros

Um ponteiro pode a apontar para o primeiro elemento de um vetor. Para atribuir o endereço de um vetor para um ponteiro basta utilizar o próprio nome dado ao vetor, isto é, o nome representa o endereço do primeiro elemento.
 - Exemplo:
 
       int v[] = {1, 2, 3, 4, 5, 6, 7, 8};
       int *p;
       int i;
       p = v;
       for(i  =  0;  i  <  8;  ++i)
       {
               cout <<  *(p  +  i) << endl;      //acessa cada elemento do vetor
       }
Os ponteiros também podem ser declarados na forma de vetores, como o exemplo abaixo. Ou seja, possibilitando a construção de uma matriz.
 - Exemplo:
 
       int  * p[2];           //vetor de ponteiros
       int v1[3]  =  {1,  2,  3};  
       int  v2[3]  =  {4,  5,  6};  
       p[0]  =  v1;          //atribui o endereço do vetor1 para o ponteiro pt[0]
       p[1]  =  v2;          //atribui o endereço do vetor2 para o ponteiro pt[1]

Um vetor pode ser declarado na forma de ponteiro. Isso possibilita a alocação dinâmica da memória.
- Exemplo:
 
       int  * v;  
       int tam = 8;        //tamanho do vetor
       v = new int[tam];

#### Ponteiros para funções
Pode-se utilizar o ponteiro para chamar uma função.
- Exemplo:
 
       int soma(int x, int y)
       {  
            return x + y;
       }
       
       int sub(int x, int y)
       {  
            return x - y;
       }
       
       int main()
       {
	       int *pfunc;
	       pfunc = soma(2,4);
	       pfunc = sub(4,2);
       }
     
#### Referências:
- Pinho. M. S.**Ponteiros**. PUCRS. Disponível em: <https://www.inf.pucrs.br/~pinho/PRGSWB/Ponteiros/ponteiros.html>. Acesso em: 05 de nov. de 2018.
- Casavella. E. **Ponteiros em C**. Intellectuale. Disponível em: <http://linguagemc.com.br/ponteiros-em-c/>. Acesso em: 05 de nov. de 2018.
- Garcia F. D. **Ponteiro em C: Arrays**. Embarcados. 2015. Disponível em: <https://www.embarcados.com.br/ponteiro-em-c-arrays/>. Acesso em: 05 de nov. de 2018.
