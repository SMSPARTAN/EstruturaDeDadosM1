// Definição da classe Lde

#pragma once

#include "No.h"
#include <stdexcept>

template <typename T>
class Lde {
private:
  No<T> *primeiroNo;
  No<T> *ultimoNo;
  int tamanhoLista;

public:
  Lde();
 
  // List I/O
  void inserir(T dado);
  void remover(int index);
  void remover(T termoDePesquisa);

  // Search methods
  T& operator[](int index);
  bool existe(T termoDePesquisa);
  int getIndex(T termoDePesquisa);
  No<T>* getNo(int index);
  No<T>* getNo(T termoDePesquisa);

  // List dado
  int tamanho() const;
};

#include "../lib/Lde.cpp"
