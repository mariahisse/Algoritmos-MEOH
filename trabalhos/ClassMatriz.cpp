#include <iostream>

using namespace std;

class Matriz{

    public:
        Matriz(int lin, int col);
        Matriz(const Matriz& copiamatriz);
        Matriz& operator =(const Matriz& copiamatriz);
        const Matriz operator +(const Matriz& m1);
        const Matriz operator -(const Matriz& m2);
        const Matriz operator *(const Matriz& m3);
        int* operator[](int valor);
        int GetLinha();
        int GetColuna();
        ~Matriz();
    private:
        int **mat;
        int i, j, k, linha1, coluna1, lin, col;
        void AlocaMatriz(int ***matriz, int m, int n);
        void DesalocaMatriz(int **matriz);
};

//Função que retorna a quantidade de linhas da matriz
int Matriz::GetLinha(){
    return lin;
}

//Função retorna a quantidade de colunas da matriz
int Matriz::GetColuna(){
    return col;
}

//Construtor
Matriz::Matriz(int lin, int col){
    AlocaMatriz(&mat, lin, col);
}

//Construtor por cópia
Matriz::Matriz(const Matriz &novamatriz){
    this->lin = novamatriz.lin;
    this->col = novamatriz.col;
    AlocaMatriz(&mat, lin, col);
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            mat[i][j] = novamatriz.mat[i][j];
        }
    }
}

//Função que aloca dinamicamente as linhas e colunas de uma matriz
void Matriz::AlocaMatriz(int ***matriz, int m, int n){
    int **matrix;
    matrix = new int* [m];
    for(i=0;i<m;i++){
            matrix[i] = new int [n];
    }
    lin=m;
    col=n;
    *matriz=matrix;
}

//Função que dasaloca a matriz
void Matriz::DesalocaMatriz(int **matriz){
    for(k=0;k<col;k++){
        delete matriz[k];
    }
    delete[] matriz;
}

//Destrutor
Matriz::~Matriz(){
    DesalocaMatriz(mat);
}

//Overloading do operador []
int* Matriz::operator[](int valor){
    return mat[valor];
}

//Operador de atribuição =, para atribuir valores
Matriz& Matriz::operator =(const Matriz& copiamatriz){
    this->linha1 = copiamatriz.lin;
    this->coluna1 = copiamatriz.col;
    DesalocaMatriz(mat);
    AlocaMatriz(&mat, linha1, coluna1);
    for(i=0;i<linha1;i++){
        for(j=0;j<coluna1;j++){
            mat[i][j] = copiamatriz.mat[i][j];
        }
    }
    return *this;
}

//Operador de + (soma), para somar os elementos de duas matrizes de mesma ordem
const Matriz Matriz::operator +(const Matriz& m1){
    this->linha1 = m1.lin;
    this->coluna1 = m1.col;
    Matriz m(lin,col);
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            m[i][j] = mat[i][j];
        }
    }
    if(linha1==lin && coluna1==col){
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                m[i][j] += m1.mat[i][j];
            }
        }
        return m;
    }
    else{
        throw invalid_argument("Nao eh possivel somar!");
    }
}

//Operador - para subtrair os elementos de duas matrizes de mesma ordem
const Matriz Matriz::operator -(const Matriz& m2){
    Matriz m(lin,col);
    this->linha1 = m2.lin;
    this->coluna1 = m2.col;
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            m[i][j] = mat[i][j];
        }
    }
    if(linha1==lin && coluna1==col){
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                m[i][j] -= m2.mat[i][j];
            }
        }
        return m;
    }
    else{
        throw invalid_argument("Nao eh possivel subtrair!");
    }
}

//Operador * para multiplicação de duas matrizes
const Matriz Matriz::operator *(const Matriz& m3){
    int aux = 0;
    this->linha1 = m3.lin;
    this->coluna1 = m3.col;
    Matriz m(lin,coluna1);
    if(linha1==col){
        for(i=0;i<lin;i++){
            for(j=0;j<coluna1;j++){
                for(k=0;k<linha1;k++){
                    aux += mat[i][k] * m3.mat[k][j];
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
void AtribuiValoresMatriz(Matriz &matriz){
    int i, j, linha, coluna;
    linha = matriz.GetLinha();
    coluna = matriz.GetColuna();
    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            matriz[i][j] = i+j;
        }
    }
}

//Operador << para imprimir a matriz
ostream& operator <<(ostream& ost, Matriz& matt){
    int i, j, linha, coluna;
    linha = matt.GetLinha();
    coluna = matt.GetColuna();
    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            ost << matt[i][j] << "\t";
        }
        ost << endl;
    }
    return ost;
}

int main()
{
    int m, n;
    cout << "Digite o valor de linhas para a matriz: ";
    cin >> m;
    cout << "Digite o valor de colunas para a matriz: ";
    cin >> n;
    Matriz a1(m, n);
    AtribuiValoresMatriz(a1);
    cout << "Matriz 1: " << endl;
    cout << a1 << endl;
    Matriz a2(a1);
    cout << endl;
    cout << "Matriz 2: " << endl;
    cout << a2 << endl;
    a2[0][0] = 40;
    cout << "Matriz 2: (alterando um valor) " << endl;
    cout << a2 << endl;
    cout << endl;
    cout << "Matriz 1: (depois da alteracao da matriz 2)" << endl;
    cout << a1 << endl;
    cout << "Digite o valor de linhas para a matriz: ";
    cin >> m;
    cout << "Digite o valor de colunas para a matriz: ";
    cin >> n;
    Matriz a3(m,n);
    AtribuiValoresMatriz(a3);
    a3[0][0] = 30;
    a3[0][1] = 20;
    cout << endl;
    cout << "Matriz 3 (antes):"<< endl;
    cout << a3 << endl;
    a3 = a1;
    cout << endl;
    cout << "Matriz 3 (depois, igual a matriz 1):" << endl;
    cout << a3 << endl;
    Matriz a4(a1+a2);
    cout << endl;
    cout << "Matriz 4 (matriz 1 + matriz 2):" << endl;
    cout << a4 << endl;
    Matriz a5(a1-a2);
    cout << endl;
    cout << "Matriz 5 (matriz 1 - matriz 2):" << endl;
    cout << a5 << endl;
    Matriz a6(a1*a3);
    cout << endl;
    cout << "Matriz 6 (matriz 1 * matriz 2):" << endl;
    cout << a6 << endl;
    return 0;
}
