// Implementação dos métodos de Node.hpp
#include "../include/Node.h"

template <typename T>
Node<T>::Node(T information) : information(information), Plink(nullptr), Nlink(nullptr) {}

template <typename T>
Node<T>::Node(Node<T> *nodePtr) {
  this->information = nodePtr->information;
  this->Plink = nodePtr->Plink;
  this->Nlink = nodePtr->Nlink;
}

template <typename T>
Node<T>::Node(Node<T> &copyNode) {
  this->information = copyNode.information;
  this->Plink = copyNode.Plink;
  this->Nlink = copyNode.Nlink;
}