using namespace std;

//Algoritmo de busca simples(busca em cada posição do vetor)
unsigned* busca_ingenua(vector<unsigned>vet, unsigned valor, unsigned* inicio, unsigned* fim, unsigned& contador){
   unsigned *position(NULL);
   while(inicio <= fim){
	if(*inicio == valor){
          position = inicio;
          ++contador;
          return position;
        }
        ++inicio;
        ++contador;
   }
   return position;
}

//Algoritmo de busca binária(busca dividindo o vetor ao meio)
int busca_binaria(vector<unsigned>vet, unsigned valor, unsigned inicio, unsigned fim, unsigned& contador){
   unsigned meio;
   int position(-1);
   meio = inicio + ((fim - inicio)/2);
   if(vet[inicio] == valor){
      ++contador;
      return position = inicio;
   }
   else if(vet[fim] == valor){
      ++contador;
      return position = fim;
   }
   while(fim != meio and inicio != meio){
      if(vet[meio] == valor){
         ++contador;
         return position = meio;
      }
      else if(vet[meio] > valor){
         ++contador;
         fim = meio;
         meio = inicio + ((fim - inicio)/2);
      }
      else{
         ++contador;
         inicio = meio;
         meio = inicio + ((fim - inicio)/2);
      }
   }
   return position;
}
