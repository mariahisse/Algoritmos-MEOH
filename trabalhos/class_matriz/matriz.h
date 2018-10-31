#ifndef Matriz_h
#define Matriz_h

class Matriz{

    public:
        Matriz(int lin, int col);
        Matriz(const Matriz& copiamatriz);
        Matriz& operator =(const Matriz& copiamatriz);
        Matriz operator +(const Matriz& m1);
        Matriz operator -(const Matriz& m2);
        Matriz operator *(const Matriz& m3);
        int* operator[](int valor);
        int getLinha() const;
        int getColuna() const;
        int get(int i, int j) const;
        ~Matriz();
    private:
        int **mat;
        int lin, col;
        void alocaMatriz(int ***matriz, int m, int n);
        void desalocaMatriz(int **matriz);
};

#endif 
