// Definição da classe Lde

#pragma once

#include "Node.h"
#include <stdexcept>

template <typename T>
class Lde {
private:
  Node<T> *firstNode;
  Node<T> *lastNode;
  int listSize;

public:
  Lde();
 
  // List I/O
  void insert(T information);
  void remove(int index);
  void remove(T searchTerm);

  // Search methods
  T& operator[](T searchTerm);
  T& operator[](int index);
  const T& operator[](int index) const;
  Node<T>* getNode(int index);
  Node<T>* getNode(T searchTerm);

  // List information
  int size() const;
};

#include "../lib/Lde.cpp"
