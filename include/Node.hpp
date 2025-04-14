// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

template <typename T>
class Node {
public:
  explicit Node(T data);
  explicit Node(Node<T> *NoPtr);
  Node(Node<T> &copyNode);

  T data;
  Node<T> *Plink;
  Node<T> *Nlink;
};

#include "../lib/Node.cpp"
