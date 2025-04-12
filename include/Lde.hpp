// Definição da classe Lde

#pragma once

#include "No.hpp"

template <typename T>
class Lde {
private:
  No<T> *primeiroNo;
  No<T> *ultimoNo;
  int tamanhoLista;

  // Search method
  No<T>* getNo(int index);
public:
  Lde();
 
  // List I/O
  void inserir(T dado);
  void remover(int index);
  void remover(T pesquisa);

  // Search methods
  T& operator[](int index);
  bool existe(T pesquisa);
  int getIndex(T pesquisa);

  // List data
  [[nodiscard]] int tamanho() const;
};

#include "../lib/Lde.cpp"
