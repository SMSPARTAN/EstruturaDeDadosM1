// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include "../include/Node.hpp"

template <typename T>
Node<T>::Node(T data) : data(data), Plink(nullptr), Nlink(nullptr) {}

template <typename T>
Node<T>::Node(Node<T> *NoPtr) {
  this->data = NoPtr->data;
  this->Plink = NoPtr->Plink;
  this->Nlink = NoPtr->Nlink;
}

template <typename T>
Node<T>::Node(Node<T> &copyNode) {
  this->data = copyNode.data;
  this->Plink = copyNode.Plink;
  this->Nlink = copyNode.Nlink;
}