#include <iostream>

using namespace std;

class Matriz{

    public:
        Matriz(int m, int n);
        Matriz (Matriz& copiamatriz);
        Matriz& operator =(Matriz& copiamatriz){
            this->lin = copiamatriz.lin;
            this->col = copiamatriz.col;
            DesalocaMatriz();
            AlocaMatriz(lin,col);
            for(i=0;i<lin;i++){
                for(j=0;j<col;j++){
                    mat[i][j] = copiamatriz[i][j];
                }
            }
            return *this;
        }
        int* operator[](int valor);
        ~Matriz();
    private:
        int **mat;
        int i, j, k, col, lin;
        void AlocaMatriz(int m, int n);
        void AtribuiValoresMatriz();
        void DesalocaMatriz();
};
//Construtor
Matriz::Matriz(int m, int n){
    AlocaMatriz(m, n);
    AtribuiValoresMatriz();
}
//Construtor por cópia
Matriz::Matriz(Matriz &novamatriz){

    this->lin = novamatriz.lin;
    this->col = novamatriz.col;
    AlocaMatriz(lin, col);
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            mat[i][j] = novamatriz[i][j];
        }
    }
}
//Função que aloca dinamicamente as linhas e colunas de uma matriz
void Matriz::AlocaMatriz(int m, int n){
    mat = new int* [m];
    for(i=0;i<m;i++){
            mat[i] = new int [n];
    }
    lin=m;
    col=n;
}
//Função para atribuir valores a matriz
void Matriz::AtribuiValoresMatriz(){

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            mat[i][j] = i+j;
        }
    }
}
//Função que dasaloca a matriz
void Matriz::DesalocaMatriz(){
    for(k=0;k<col;k++){
        delete mat[k];
    }
    delete[] mat;
}
//Overloading do operador []
int *Matriz::operator[](int valor){
    return mat[valor];
}
//Destrutor
Matriz::~Matriz(){
    DesalocaMatriz();
}
//Função para imprimir a matriz
void ImprimeMatriz(Matriz &m, int l, int c){
    int i, j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    int m, n;
    cout << "Digite o valor de linhas para a matriz: ";
    cin >> m;
    cout << "Digite o valor de colunas para a matriz: ";
    cin >> n;
    Matriz construindo_matriz(m, n);
    cout << "Matriz 1: " << endl;
    ImprimeMatriz(construindo_matriz, m, n);
    Matriz a2(construindo_matriz);
    cout << endl;
    cout << "Matriz 2: " << endl;
    ImprimeMatriz(a2, m, n);
    a2[0][0] = 40;
    cout << endl;
    cout << "Matriz 1: (depois da alteracao da matriz 2)" << endl;
    ImprimeMatriz(construindo_matriz, m, n);
    Matriz a3(m,n);
    a3[0][0] = 30;
    a3[0][1] = 20;
    cout << endl;
    cout << "Matriz 3 (antes):"<< endl;
    ImprimeMatriz(a3, m, n);
    a3 = construindo_matriz;
    cout << endl;
    cout << "Matriz 3 (depois):" << endl;
    ImprimeMatriz(a3, m, n);
    return 0;
}
