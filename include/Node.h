// Definição da classe Node

#pragma once

template <typename T>
class Node {
public:
  Node(T information);
  Node(Node<T> *nodePtr);
  Node(Node<T> &copyNode);

  T information;
  Node<T> *Plink;
  Node<T> *Nlink;
};

#include "../lib/Node.cpp"
