#include <iostream>
#include <random>
#include <vector>
#include "quick_sort.h"
#include "busca.h"
#include "gtest/gtest.h"
#include "teste.h"

using namespace std;
int main(int argc, char **argv)
{
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}

/*int main(){
   random_device rd;
   mt19937 gen(rd());
   unsigned inicio(0), contadori(0), *position, contadorb(0), valor;
   for(unsigned i(1000); i<=100000; i=i+1000){
      vector<unsigned> vec;
      uniform_int_distribution <> dis(1, i);
      for(unsigned j(0); j<i; ++j){
         vec.push_back(dis(gen));
      }
      quick_sort(vec);
      position = busca_ingenua(vec, dis(gen), &vec[0], &vec[vec.size() - 1], contadori);
      cout << i << " " << contadori;
      valor = busca_binaria(vec, dis(gen), inicio, vec.size() - 1, contadorb);
      cout << " " << contadorb << endl;
      contadori = 0;
      contadorb = 0;
   }
   return 0;
}*/
