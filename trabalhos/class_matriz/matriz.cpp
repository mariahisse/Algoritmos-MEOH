#include "matriz.h"
#include <iostream>

using namespace std;

//Função que retorna a quantidade de linhas da matriz
int Matriz::getLinha() const{
    return lin;
}

//Função retorna a quantidade de colunas da matriz
int Matriz::getColuna() const{
    return col;
}

int Matriz::get(int i, int j) const{
    return mat[i][j];
}

//Construtor
Matriz::Matriz(int lin, int col){
    alocaMatriz(&mat, lin, col);
}

//Construtor por cópia
Matriz::Matriz(const Matriz &novamatriz){
    this->lin = novamatriz.getLinha();
    this->col = novamatriz.getColuna();
    alocaMatriz(&mat, lin, col);
    for(unsigned i=0;i<lin;i++){
        for(unsigned j=0;j<col;j++){
            mat[i][j] = novamatriz.get(i,j);
        }
    }
}

//Função que aloca dinamicamente as linhas e colunas de uma matriz
void Matriz::alocaMatriz(int ***matriz, int m, int n){
    int **matrix;
    matrix = new int* [m];
    for(unsigned i=0;i<m;i++){
        matrix[i] = new int [n];
    }
    lin=m;
    col=n;
    *matriz=matrix;
}

//Função que dasaloca a matriz
void Matriz::desalocaMatriz(int **matriz){
    for(unsigned k=0;k<col;k++){
        delete matriz[k];
    }
    delete[] matriz;
}

//Destrutor
Matriz::~Matriz(){
    desalocaMatriz(mat);
}

//Overloading do operador []
int* Matriz::operator[](int valor){
    return mat[valor];
}

//Operador de atribuição =, para atribuir valores
Matriz& Matriz::operator =(const Matriz& copiamatriz){
    int linha, coluna;
    linha = copiamatriz.getColuna();
    coluna = copiamatriz.getLinha();
    desalocaMatriz(mat);
    alocaMatriz(&mat, linha, coluna);
    for(unsigned i=0;i<linha;i++){
        for(unsigned j=0;j<coluna;j++){
            mat[i][j] = copiamatriz.get(i,j);
        }
    }
    this->lin = linha;
    this->col = coluna;
    return *this;
}

//Operador de + (soma), para somar os elementos de duas matrizes de mesma ordem
Matriz Matriz::operator +(const Matriz& m1){
    int linha, coluna;
    linha = m1.getLinha();
    coluna = m1.getColuna();
    Matriz m(lin,col);
    for(unsigned i=0;i<lin;i++){
        for(unsigned j=0;j<col;j++){
            m[i][j] = mat[i][j];
        }
    }
    if(linha==lin && coluna==col){
        for(unsigned i=0;i<lin;i++){
            for(unsigned j=0;j<col;j++){
                m[i][j] += m1.get(i,j);
            }
        }
        return m;
    }
    else{
        throw invalid_argument("Nao eh possivel somar!");
    }
}

//Operador - para subtrair os elementos de duas matrizes de mesma ordem
Matriz Matriz::operator -(const Matriz& m2){
    Matriz m(lin,col);
    int linha, coluna;
    linha = m2.getLinha();
    coluna = m2.getColuna();
    for(unsigned i=0;i<lin;i++){
        for(unsigned j=0;j<col;j++){
            m[i][j] = mat[i][j];
        }
    }
    if(linha==lin && coluna==col){
        for(unsigned i=0;i<lin;i++){
            for(unsigned j=0;j<col;j++){
                m[i][j] -= m2.get(i,j);
            }
        }
        return m;
    }
    else{
        throw invalid_argument("Nao eh possivel subtrair!");
    }
}

//Operador * para multiplicação de duas matrizes
Matriz Matriz::operator *(const Matriz& m3){
    int aux = 0;
    int linha, coluna;
    linha = m3.getLinha();
    coluna = m3.getColuna();
    Matriz m(lin,coluna);
    if(linha==col){
        for(unsigned i=0;i<lin;i++){
            for(unsigned j=0;j<coluna;j++){
                for(unsigned k=0;k<linha;k++){
                    aux += mat[i][k] * m3.get(k,j);
                }
                m[i][j] = aux;
                aux = 0;
            }
        }
        return m;
    }
    else{
        throw invalid_argument("Nao eh possivel multiplicar!");
    }
}

//Função para atribuir valores a matriz
void atribuiValoresMatriz(Matriz &matriz){
    int linha, coluna;
    linha = matriz.getLinha();
    coluna = matriz.getColuna();
    for(unsigned i=0;i<linha;i++){
        for(unsigned j=0;j<coluna;j++){
            matriz[i][j] = i+j;
        }
    }
}

//Operador << para imprimir a matriz
ostream& operator <<(ostream& ost, Matriz& matt){
    int linha, coluna;
    linha = matt.getLinha();
    coluna = matt.getColuna();
    for(unsigned i=0;i<linha;i++){
        for(unsigned j=0;j<coluna;j++){
            ost << matt[i][j] << "\t";
        }
        ost << endl;
    }
    return ost;
}
