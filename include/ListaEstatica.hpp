// Definição de Lista Estática

#pragma once

#define MAX_TAM 100

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
  void remover(T termoDePesquisa);

  // Search methods
  T& operator[](int index);
  bool existe(T termoDePesquisa);
  int getIndex(T termoDePesquisa);

  // Lista data
  [[nodiscard]] int tamanho() const;
};

#include "../lib/ListaEstatica.cpp"//`