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

//Construtor que inicia a posi��o da lista com NULL
CircularList::CircularList(){
  position=NULL;
}

//Destrutor que retira um n� at� a lista estar vazia
CircularList::~CircularList(){
  while(!IsEmpty()){
     PopPosition();
  }
}

//M�todo para retornar a informa��o do n� que position aponta
int CircularList::GetPosition(){
  if(IsEmpty()){
    throw std::invalid_argument("Empty list");
  }
  return position->info;
}

//M�todo para verificar se a lista est� vazia
bool CircularList::IsEmpty(){
  if(position==NULL){
    return true;
  }else{
    return false;
  }
}

//M�todo para position apontar para o pr�ximo node
void CircularList::PositionNext(){
    if(IsEmpty()){
        throw std::invalid_argument("Empty list");
    }
    position = position->next;
}

//M�todo para position apontar para o node anterior
void CircularList::PositionPrevious(){
    if(IsEmpty()){
        throw std::invalid_argument("Empty list");
    }
    position = position->previous;
}

//M�todo para retirar o position da lista e o position ser� o pr�ximo
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

//M�todo para adicionar um n� depois do position
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

//M�todo para adicionar um n� antes do position
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
