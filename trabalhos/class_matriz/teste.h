//Testes para verificar a classe matriz e seus métodos

TEST(MATRIZ, teste_pega_linha) {
  Matriz m1(5,5);
  ASSERT_EQ(m1.getLinha(), 5);
}

TEST(MATRIZ, segundo_teste_pega_linha) {
  Matriz m1(5,5);
  Matriz m2(4,4);
  ASSERT_NE(m1.getLinha(), m2.getLinha());
}

TEST(MATRIZ, teste_pega_coluna) {
  Matriz m1(5,5);
  Matriz m2(4,4);
  ASSERT_NE(m1.getColuna(), m2.getColuna());
}

TEST(MATRIZ, segundo_teste_pega_coluna) {
  Matriz m1(5,5);
  ASSERT_EQ(m1.getColuna(), 5);
}

TEST(MATRIZ, teste_pega_elemento_matriz) {
  Matriz m1(5,5);
  m1[0][0] = 5;
  ASSERT_EQ(m1.get(0,0), 5);
}

TEST(MATRIZ, teste_compara_matriz_igual) {
  Matriz m1(5,5), m2(5,5);
  atribuiValoresMatriz(m1);
  atribuiValoresMatriz(m2);
  ASSERT_TRUE(m1 == m2);
}

TEST(MATRIZ, teste_compara_matriz_diferente) {
  Matriz m1(5,5), m2(5,5);
  atribuiValoresMatriz(m1);
  atribuiValoresMatriz(m2);
  m2[0][0] = 100;
  ASSERT_FALSE(m1 == m2);
}

TEST(MATRIZ, teste_funcao_valor_matriz_soma) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  ASSERT_EQ(m1[0][0], 0);
}

TEST(MATRIZ, teste_operador_colchetes) {
  Matriz m1(5,5);
  m1[0][0] = 100;
  ASSERT_EQ(m1[0][0], 100);
}

TEST(MATRIZ, teste_copia_matriz) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(m1);
  int i, j, l, c;
  l=m1.getLinha();
  c=m1.getColuna();
  ASSERT_TRUE(m1 == m2);
}

TEST(MATRIZ, teste_copia_alterando_valor) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(m1);
  m2[0][0] = 100;
  ASSERT_EQ(m1[0][0], 0);
}

TEST(MATRIZ, teste_soma_matriz) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(5,5);
  atribuiValoresMatriz(m2);
  Matriz m3(m1+m2);
  ASSERT_EQ(m3[0][0], 0);
}

TEST(MATRIZ, teste_soma_excecao_matriz) {
  Matriz m1(5,5);
  Matriz m2(4,4);
  ASSERT_THROW(Matriz m3(m1+m2), std::invalid_argument);
}

TEST(MATRIZ, teste_multplicacao_excecao_matriz) {
  Matriz m1(5,5);
  Matriz m2(4,4);
  ASSERT_THROW(Matriz m3(m1*m2), std::invalid_argument);
}

TEST(MATRIZ, teste_multiplicacao_matriz) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(5,5);
  atribuiValoresMatriz(m2);
  Matriz m3(m1*m2);
  ASSERT_EQ(m3[0][0], 30);
}

TEST(MATRIZ, segundo_teste_multiplicacao_matriz) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(5,5);
  atribuiValoresMatriz(m2);
  Matriz m3(m1*m2);
  m3[0][0] = 100;
  ASSERT_EQ(m3[0][0], 100);
}

TEST(MATRIZ, teste_subtracao_excecao_matriz) {
  Matriz m1(5,5);
  Matriz m2(4,4);
  ASSERT_THROW(Matriz m3(m1-m2), std::invalid_argument);
}

TEST(MATRIZ, teste_subtracao_matriz) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(5,5);
  atribuiValoresMatriz(m2);
  m2[0][0] = 40;
  Matriz m3(m1-m2);
  ASSERT_EQ(m3[0][0], -40);
}

TEST(MATRIZ, segundo_teste_subtracao_matriz) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(5,5);
  atribuiValoresMatriz(m2);
  m2[0][0] = 40;
  Matriz m3(5,5);
  m3 = m1-m2;
  ASSERT_EQ(m3[0][0], -40);
}

TEST(MATRIZ, terceiro_teste_subtracao_matriz) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(5,5);
  atribuiValoresMatriz(m2);
  m2[0][0] = 40;
  Matriz m3(4,4);
  m3 = m1-m2;
  ASSERT_EQ(m3[0][0], -40);
}

TEST(MATRIZ, teste_operador_atribuicao) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(5,5);
  m2 = m1;
  int i, j, l, c;
  l=m1.getLinha();
  c=m1.getColuna();
  ASSERT_TRUE(m1 == m2);
}

TEST(MATRIZ, segundo_teste_operador_atribuicao) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(4,4);
  m2 = m1;
  int i, j, l, c;
  l=m1.getLinha();
  c=m1.getColuna();
  ASSERT_TRUE(m1 == m2);
}

TEST(MATRIZ, terceiro_teste_operador_atribuicao) {
  Matriz m1(5,5);
  atribuiValoresMatriz(m1);
  Matriz m2(5,5);
  m2 = m1;
  m2[0][0] = 100;
  ASSERT_EQ(m1[0][0], 0);
}
