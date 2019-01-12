using namespace std;

//Algoritmo que ordena um vetor em ordem crescente
void quick_sort(vector<unsigned>&vet){
   int aux;
   for(unsigned i(0); i<vet.size(); ++i){
      for(unsigned j(i+1); j<vet.size(); ++j){
          if(vet[i] > vet[j]){
             aux = vet[i];
             vet[i] = vet[j];
             vet[j] = aux;
          }
      }
   }
}

//Algoritmo que verifica se a lista está ordenada em forma crescente
bool ordena(vector<unsigned>vet){
   for(unsigned i(1); i<vet.size(); ++i){
      if(vet[i-1] > vet[i]){
         return false;
       }
   }
   return true;

}

