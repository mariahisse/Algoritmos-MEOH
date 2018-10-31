#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node{
  public:
    Node(int inf, Node* nodePrevious=NULL, Node* nodeNext=NULL);
    int info;
    Node* next;
    Node* previous;
};

//Construtor que recebe uma informação, um ponteiro que aponta para o anterior e outro para o próximo
Node::Node(int inf, Node* nodePrevious, Node* nodeNext){
  info=inf;
  previous=nodePrevious;
  next=nodeNext;
}

#endif // NODE_H_INCLUDED
