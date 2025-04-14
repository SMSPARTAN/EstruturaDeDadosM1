// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include "../include/Lue.hpp"
#include <stdexcept>

template<typename T>
Lue<T>::Lue() {
  firstNode = nullptr;
  lastNode = nullptr;
  listSize = 0;
}

// List I/O
template<typename T>
void Lue<T>::push_back(T data) {
  Node<T>* newNode = new Node<T>(data);

  if(firstNode == nullptr) {
    firstNode = newNode;
    lastNode = newNode;
  } else {
    lastNode->Nlink = newNode;
    lastNode = newNode;
  }

  listSize++;
}

template<typename T>
void Lue<T>::remove(int index) {
  if(index < 0 || index >= listSize) {
    throw std::out_of_range("Index out of Bounds - remove");
  }

  Node<T>* nodeToDelete = this->getNode(index);
  if(index == listSize - 1) {
    lastNode = this->getNode(index - 1);
    lastNode->Nlink = nullptr;

    nodeToDelete->Nlink = nullptr;
    delete nodeToDelete;

    return;
  } else if (index == 0) {
    firstNode = this->getNode(index + 1);
    
    nodeToDelete->Nlink = nullptr;
    delete nodeToDelete;

    return;
  }

  this->getNode(index - 1) = nodeToDelete->Nlink;

  nodeToDelete->Nlink = nullptr;
  delete nodeToDelete;

  listSize--;
} 

template<typename T>
void Lue<T>::remove(T search) {
  this->remove(this->getIndex(search));
}

// Search methods
template<typename T>
T& Lue<T>::operator[](int index) {
  if(index < 0 || index >= listSize) {
    throw std::out_of_range("Index out of Bounds - operator");
  }

  Node<T>* searchNode = firstNode;
  for(int i = 0; i < index; i++) {
    searchNode = searchNode->Nlink;
  }

  return searchNode->data;
}

template<typename T>
T& Lue<T>::operator[](int index) const {
  if(index < 0 || index >= listSize) {
    throw std::out_of_range("Index out of Bounds - operator");
  }

  Node<T>* searchNode = firstNode;
  for(int i = 0; i < index; i++) {
    searchNode = searchNode->Nlink;
  }

  return searchNode->data;
}

template<typename T>
bool Lue<T>::exists(T search) {
  try {
    this->getIndex(search);
    return true;
  } catch (std::out_of_range &_) {
    return false;
  }
}

template<typename T>
bool Lue<T>::exists(T search) const {
  try {
    this->getIndex(search);
    return true;
  } catch (std::out_of_range &_) {
    return false;
  }
}

template<typename T>
int Lue<T>::getIndex(T search) {
  Node<T>* searchNode = firstNode;

  for(int i = 0; i < listSize; i++) {
    if (searchNode->data == search) {
      return searchNode->data;
    }
    searchNode = searchNode->Nlink;
  }
}

template <typename T>
Node<T>* Lue<T>::getNode(int index) {
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
template<typename T>
int Lue<T>::size() const { return listSize; };