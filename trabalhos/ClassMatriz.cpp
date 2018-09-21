#include <iostream>

using namespace std;

class Matriz{

    public:
        Matriz(int m, int n){
            mat = new int* [m];
            for(i=0;i<m;i++){
                mat[i] = new int [n];
            }
            lin=m;
            col=n;
        };
        int* operator[](int valor);
        void AtribuiValoresMatriz();
        void ImprimeMatriz();
        ~Matriz(){
            for(k=0;k<col;k++){
                    delete mat[k];
            }
            delete[] mat;
            cout << "Matriz destruida!" <<endl;

        };
    private:
        int **mat;
        int i, j, k, col, lin;
};

void Matriz::AtribuiValoresMatriz(){

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            mat[i][j] = i+j;
        }
    }
}

void Matriz::ImprimeMatriz(){

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}
int *Matriz::operator[](int valor){
    return mat[valor];
}
int main()
{
    int m, n;
    cout << "Digite o valor de linhas: ";
    cin >> m;
    cout << "Digite o valor de colunas: ";
    cin >> n;
    Matriz construindo_matriz(m, n);
    construindo_matriz.AtribuiValoresMatriz();
    construindo_matriz.ImprimeMatriz();
    return 0;
}
