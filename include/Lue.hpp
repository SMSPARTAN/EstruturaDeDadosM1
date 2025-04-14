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
  bool exists(T search);
  int getIndex(T search);

  // List data
  [[nodiscard]] int size() const;
};

#include "../lib/Lue.cpp"