#pragma once

#include "No.hpp"

template<typename T>
class Lue {
private:
  No<T> *primeiroNo;
  No<T> *ultimoNo;
  int tamanhoLista;
  No<T>* getNo(int index);
public:
  Lue();

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