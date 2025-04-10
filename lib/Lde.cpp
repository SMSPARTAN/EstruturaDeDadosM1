// Implementação dos métodos de Lde.hpp
#include "../include/Lde.h"

template <typename T>
Lde<T>::Lde() {
  firstNode = nullptr;
  lastNode = nullptr;
  listSize = 0;
}

// List I/O
template <typename T>
void Lde<T>::insert(T information) {
  Node<T>* newNode = new Node<T>(information);

  if(firstNode == nullptr) {
    firstNode = newNode;
    lastNode = newNode;
  } else {
    newNode->Plink = lastNode;
    lastNode->Nlink = newNode;
    lastNode = newNode;
  }

  listSize++;
}

template <typename T>
void Lde<T>::remove(int index) {
  if(index < 0 || index >= listSize) {
    throw std::out_of_range("Index out of Bounds -- Remove");
  }

  Node<T> *nodeToDelete = this->getNode(index);
  if(index == listSize - 1) {
    lastNode = lastNode->Plink;
    lastNode->Nlink = nullptr;

    nodeToDelete->Plink = nullptr;
    nodeToDelete->Nlink = nullptr;
    delete nodeToDelete;  

    return;
  } else if (index == 0) {
    firstNode = firstNode->Nlink;
    firstNode->Plink = nullptr;

    nodeToDelete->Nlink = nullptr;
    delete nodeToDelete;

    return;
  }

  Node<T>* previousNode = nodeToDelete->Plink;
  Node<T>* nextNode = nodeToDelete->Nlink;

  previousNode->Nlink = nextNode;
  nextNode->Plink = previousNode;

  nodeToDelete->Plink = nullptr;
  nodeToDelete->Nlink = nullptr;

  listSize--;

  delete nodeToDelete;
}

template <typename T>
void Lde<T>::remove(T searchTerm) {
  Node<T> *nodeToDelete = this->getNode(searchTerm);
  if(nodeToDelete == lastNode) {
    lastNode = lastNode->Plink;
    lastNode->Nlink = nullptr;

    nodeToDelete->Plink = nullptr;
    nodeToDelete->Nlink = nullptr;
    delete nodeToDelete;  

    return;
  } else if (nodeToDelete == firstNode) {
    firstNode = firstNode->Nlink;
    firstNode->Plink = nullptr;

    nodeToDelete->Nlink = nullptr;
    delete nodeToDelete;

    return;
  }

  Node<T>* previousNode = nodeToDelete->Plink;
  Node<T>* nextNode = nodeToDelete->Nlink;

  previousNode->Nlink = nextNode;
  nextNode->Plink = previousNode;

  nodeToDelete->Plink = nullptr;
  nodeToDelete->Nlink = nullptr;

  listSize--;

  delete nodeToDelete;
}

// Search methods
template <typename T>
T& Lde<T>::operator[](T searchTerm) {
  Node<T>* searchNode = firstNode;
  while(searchNode != nullptr) {
    if(searchNode->information == searchTerm) {
      return searchNode->information;
    }

    searchNode = searchNode->Nlink;
  }

  throw std::out_of_range("Index out of Bounds -- No such object in list");
}

template <typename T>
T& Lde<T>::operator[](int index) {
  if(index < 0 || index >= listSize) {
    throw std::out_of_range("Index out of Bounds -- Operator");
  }

Node<T>* currentNode = firstNode;
  for(int i = 0; i < index; i++) {
   currentNode = currentNode->Nlink;
  }

  return currentNode->information;
}

template <typename T>
const T& Lde<T>::operator[](int index) const {
  if(index < 0 && index >= listSize) {
    throw std::out_of_range("Index out of Bounds -- Operator");
  }

  Node<T>* currentNode = firstNode;
  for(int i = 0; i < listSize; i++) {
    currentNode = currentNode->Nlink;
  }

  return currentNode->information;
}

template <typename T>
Node<T>* Lde<T>::getNode(int index) {
  if(index < 0 || index >= listSize) {
    throw std::out_of_range("Index out of Bounds -- getnNode");
  }

  Node<T>* returnNode = firstNode;
  for(int i = 0; i < index; i++) {
    returnNode = returnNode->Nlink;
  }

  return returnNode;
}

template <typename T>
Node<T>* Lde<T>::getNode(T searchTerm) {
Node<T>* returnNode = firstNode;

while(returnNode != nullptr) {
  if(returnNode->information == searchTerm) {
  return returnNode;
  }

  returnNode = returnNode->Nlink;
}

  throw std::out_of_range("Index out of Bounds -- getNode(searchTerm)");
}

// List information
template <typename T>
int Lde<T>::size() const {
  return listSize;
}
