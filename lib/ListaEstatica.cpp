// Implementação de lista estática

#pragma once

#include "../include/ListaEstatica.hpp"
#include <stdexcept>

// List I/O
template<typename T>
void ListaEstatica<T>::inserir(T dado) {
  if(ultPos >= MAX_TAM) {
    throw std::overflow_error("Over Maximum Array Capacity -- 100 Elements");
  }

  array[ultPos] = dado;
}

template<typename T>
void ListaEstatica<T>::remover(int index) {
  if(index >= ultPos || index < 0) {
    throw std::out_of_range("Index out of Bounds - remover");
  }

  for(int i = index; i < ultPos; i++) {
    array[i] = array[i + 1];
  }

  ultPos--;
}

template<typename T>
void ListaEstatica<T>::remover(T pesquisa) {
  this->remover(this->getIndex(pesquisa));
}

// Search methods
template <typename T>
T& ListaEstatica<T>::operator[](int index) {
  if(index < 0 || index >= ultPos) {
    throw std::out_of_range("Index out of Bounds -- operator");
  }

  return array[index];
}

template<typename T>
bool ListaEstatica<T>::existe(T pesquisa) {
  for(auto & elemento : array) {
    if(elemento == pesquisa) {
      return true;
    }
  }

  return false;
}

template<typename T>
int ListaEstatica<T>::getIndex(T pesquisa) {
  int index = 0;
  for(auto & elemento : array) {
    if (elemento == pesquisa) {
      return index;
    }
    index++;
  }
  
  throw std::out_of_range("Index out of Bounds - getIndex");
}

// List data
template<typename T>
int ListaEstatica<T>::tamanho() const {
  return ultPos;
};