// Definição de Lista Estática

#pragma once

#define MAX_TAM 28

template<typename T>
class ListaEstatica {
private:
  T array[MAX_TAM];
  int ultPos;
public:
  ListaEstatica() : ultPos(0) {}
  
  // List I/O
  void inserir(T dado);
  void remover(int index);
  void remover(T pesquisa);

  // Search methods
  T& operator[](int index);
  bool existe(T pesquisa);
  int getIndex(T pesquisa);

  // Lista data
  [[nodiscard]] int tamanho() const;
};

#include "../lib/ListaEstatica.cpp"//`