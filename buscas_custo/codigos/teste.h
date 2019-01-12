//Testes para as funções quick sort, busca binária e ingênua 

TEST(ORDENAR, TESTE_UM){
    vector <unsigned> vec ({5, 1, 4, 13, 12, 2, 20, 18});
    quick_sort(vec);
    ASSERT_TRUE(ordena(vec));
}

TEST(ORDENAR, TESTE_DOIS){
    vector <unsigned> vec ({20, 18, 13, 12, 5, 4, 2, 1});
    quick_sort(vec);
    ASSERT_TRUE(ordena(vec));
}


TEST(ORDENAR, JA_ORDENADA){
    vector <unsigned> vec ({1, 2, 4, 5, 12, 13, 18, 20});
    quick_sort(vec);
    ASSERT_TRUE(ordena(vec));
}

TEST(BUSCA, ENCONTRADO) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 13, 0, vec.size() - 1, contador);
    ASSERT_TRUE(position == 4);
}

TEST(BUSCA, ENCONTRADO_LIMITE) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 2, 0, vec.size() - 1, contador);
    ASSERT_TRUE(position == 0);
}

TEST(BUSCA, ENCONTRADO_LIMITE_FINAL) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 20, 0, vec.size() - 1, contador);
    ASSERT_TRUE(position == vec.size() - 1);
}

TEST(BUSCA, NAO_ENCONTRADO) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 4, 0, vec.size() - 1, contador);
    ASSERT_TRUE(position == -1);
}

TEST(BUSCA, NAO_ENCONTRADO_2) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 22, 0, vec.size() -1, contador);
    ASSERT_TRUE(position == -1);
}

TEST(BUSCA, NAO_ENCONTRADO_3) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 1, 0, vec.size() - 1, contador);
    ASSERT_TRUE(position == -1);
}

TEST(BUSCA, NAO_ENCONTRADO_4) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 6, 0, vec.size() - 1, contador);
    ASSERT_TRUE(position == -1);
}

TEST(BUSCA, NAO_ENCONTRADO_5) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 11, 0, vec.size() - 1, contador);
    ASSERT_TRUE(position == -1);
}

TEST(BUSCA, NAO_ENCONTRADO_6) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 18, 0, vec.size() - 1, contador);
    ASSERT_TRUE(position == -1);
}

TEST(BUSCA, CONTADOR) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 18, 0, vec.size() - 1, contador);
    ASSERT_TRUE(contador == 3);
}

TEST(BUSCA, CONTADOR_2) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 2, 0, vec.size() - 1, contador);
    ASSERT_TRUE(contador == 1);
}

TEST(BUSCA, CONTADOR_3) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 10, 0, vec.size() - 1, contador);
    ASSERT_TRUE(contador == 1);
}

TEST(BUSCA, CONTADOR_4) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0);
    int position;
    position = busca_binaria(vec, 20, 0, vec.size() - 1, contador);
    ASSERT_TRUE(contador == 1);
}

TEST(BUSCA_SIMPLES, ENCONTRADO_LIMITE) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 2, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(*position == 2);
}

TEST(BUSCA_SIMPLES, ENCONTRADO_LIMITE_FINAL) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 20, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(*position == 20);
}

TEST(BUSCA_SIMPLES, ENCONTRADO) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 13, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(*position == 13);
}

TEST(BUSCA_SIMPLES, ENCONTRADO_2) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 5, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(*position == 5);
}

TEST(BUSCA_SIMPLES, NAO_ENCONTRADO) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 4, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(position == NULL);
}

TEST(BUSCA_SIMPLES, NAO_ENCONTRADO_2) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 12, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(position == NULL);
}

TEST(BUSCA_SIMPLES, NAO_ENCONTRADO_3) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 21, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(position == NULL);
}

TEST(BUSCA_SIMPLES, NAO_ENCONTRADO_4) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 1, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(position == NULL);
}

TEST(BUSCA_SIMPLES, CONTADOR) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 1, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(contador == 7);
}

TEST(BUSCA_SIMPLES, CONTADOR_2) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 20, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(contador == 7);
}

TEST(BUSCA_SIMPLES, CONTADOR_3) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 15, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(contador == 7);
}

TEST(BUSCA_SIMPLES, CONTADOR_4) {
    vector <unsigned> vec ({2, 5, 8, 10, 13, 16, 20});
    unsigned contador(0), *position;
    position = busca_ingenua(vec, 10, &vec[0], &vec[vec.size() - 1], contador);
    ASSERT_TRUE(contador == 4);
}
