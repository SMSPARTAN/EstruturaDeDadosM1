// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include "Node.hpp"

template<typename T>
class Lue {
private:
  Node<T> *firstNode;
  Node<T> *lastNode;
  int listSize;
  Node<T>* getNode(int index);
public:
  Lue();

  // List I/O
  void push_back(T data);
  void remove(int index);
  void remove(T search);

  // Search methods
  T& operator[](int index);
  T& operator[](int index) const;
  bool exists(T search);
  bool exists(T search) const;
  int getIndex(T search);

  // List data
  int size() const;
};

#include "../lib/Lue.cpp"