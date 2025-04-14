// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include "../include/Lde.hpp"
#include <stdexcept>

template <typename T>
Lde<T>::Lde() {
  firstNode = nullptr;
  lastNode = nullptr;
  listSize = 0;
}

// List I/O
template <typename T>
void Lde<T>::push_back(T data) {
  Node<T>* newNode = new Node<T>(data);

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
    throw std::out_of_range("Index out of Bounds -- remove");
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

  Node<T>* noAntecessor = nodeToDelete->Plink;
  Node<T>* noSucessor = nodeToDelete->Nlink;

  noAntecessor->Nlink = noSucessor;
  noSucessor->Plink = noAntecessor;

  nodeToDelete->Plink = nullptr;
  nodeToDelete->Nlink = nullptr;

  listSize--;

  delete nodeToDelete;
}

template <typename T>
void Lde<T>::remove(T search) {
  this->remove(this->getIndex(search));
}

// Search methods
template <typename T>
T& Lde<T>::operator[](int index) {
  if(index < 0 || index >= listSize) {
    throw std::out_of_range("Index out of Bounds -- Operator");
  }

Node<T>* noAtual = firstNode;
  for(int i = 0; i < index; i++) {
   noAtual = noAtual->Nlink;
  }

  return noAtual->data;
}

template <typename T>
T& Lde<T>::operator[](int index) const {
  if(index < 0 || index >= listSize) {
    throw std::out_of_range("Index out of Bounds -- Operator");
  }

Node<T>* noAtual = firstNode;
  for(int i = 0; i < index; i++) {
   noAtual = noAtual->Nlink;
  }

  return noAtual->data;
}

template<typename T>
bool Lde<T>::exists(T search) {
  try {
    this->getIndex(search);
    return true;
  } catch (std::out_of_range &_) {
    return false;  
  }
}

template<typename T>
bool Lde<T>::exists(T search) const {
  try {
    this->getIndex(search);
    return true;
  } catch (std::out_of_range &_) {
    return false;  
  }
}

template<typename T>
int Lde<T>::getIndex(T search) {
  Node<T>* searchNode = firstNode;
  for(int i = 0; i < listSize; i++) {
    if(searchNode->data == search) {
      return i;
    }
    searchNode = searchNode->Nlink;
  }

  throw std::out_of_range("Index out of Bounds -- getIndex");
}

template<typename T>
int Lde<T>::getIndex(T search) const {
  Node<T>* searchNode = firstNode;
  for(int i = 0; i < listSize; i++) {
    if(searchNode->data == search) {
      return i;
    }
    searchNode = searchNode->Nlink;
  }

  throw std::out_of_range("Index out of Bounds -- getIndex");
}

template <typename T>
Node<T>* Lde<T>::getNode(int index) {
  if(index < 0 || index >= listSize) {
    throw std::out_of_range("Index out of Bounds -- getNode");
  }

  Node<T>* returnNode = firstNode;
  for(int i = 0; i < index; i++) {
    returnNode = returnNode->Nlink;
  }

  return returnNode;
}

// List data
template <typename T>
int Lde<T>::size() const {
  return listSize;
}
