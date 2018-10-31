#ifndef CLASSLIST_H_INCLUDED
#define CLASSLIST_H_INCLUDED

class CircularList{
  public:
    CircularList();
    ~CircularList();
    void AddNodeBefore(int value);
    void AddNodeAfter(int value);
    bool IsEmpty();
    void PopPosition();
    void PositionNext();
    void PositionPrevious();
    int GetPosition();
    bool HasValue(int value);
    Node *position;
};

//Construtor que inicia a posição da lista com NULL
CircularList::CircularList(){
  position=NULL;
}

//Destrutor que retira um nó até a lista estar vazia
CircularList::~CircularList(){
  while(!IsEmpty()){
     PopPosition();
  }
}

//Método para retornar a informação do nó que position aponta
int CircularList::GetPosition(){
  if(IsEmpty()){
    throw std::invalid_argument("Empty list");
  }
  return position->info;
}

//Método para verificar se a lista está vazia
bool CircularList::IsEmpty(){
  if(position==NULL){
    return true;
  }else{
    return false;
  }
}

//Método para position apontar para o próximo node
void CircularList::PositionNext(){
    if(IsEmpty()){
        throw std::invalid_argument("Empty list");
    }
    position = position->next;
}

//Método para position apontar para o node anterior
void CircularList::PositionPrevious(){
    if(IsEmpty()){
        throw std::invalid_argument("Empty list");
    }
    position = position->previous;
}

//Método para retirar o position da lista e o position será o próximo
void CircularList::PopPosition(){
  if(IsEmpty()){
    throw std::invalid_argument("Empty list");
  }
  Node *aux = position;
  if(position->next == position){
    position = NULL;
  }
  else{
    position->previous->next = position->next;
    position->next->previous = position->previous;
    position = position->next;
  }
  delete aux;
}

//Método para adicionar um nó depois do position
void CircularList::AddNodeBefore(int value){
  Node *aux = new Node(value);
  if(IsEmpty()){
    aux->next = aux;
    aux->previous = aux;
    position = aux;
  }else{
      aux->next = position->next;
      aux->previous = position;
      position->next->previous = aux;
      position->next = aux;
  }
}

//Método para adicionar um nó antes do position
void CircularList::AddNodeAfter(int value){
  Node *aux = new Node(value);
  if(IsEmpty()){
    aux->next = aux;
    aux->previous = aux;
    position = aux;
  }else{
      aux->next = position;
      aux->previous = position->previous;
      position->previous->next = aux;
      position->previous = aux;
  }
}

bool CircularList::HasValue(int value){
  Node *aux = position;
  do{
     if(aux->info == value){
       return true;
     }
     aux = aux->next;
  }while(aux != position);
  return false;
}

#endif // CLASSLIST_H_INCLUDED
