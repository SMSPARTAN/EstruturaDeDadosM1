#pragma once

#include "../include/Lue.hpp"
#include <stdexcept>

template<typename T>
Lue<T>::Lue() {
  primeiroNo = nullptr;
  ultimoNo = nullptr;
  tamanhoLista = 0;
}

// List I/O
template<typename T>
void Lue<T>::inserir(T dado) {
  auto* novoNo = new No<T>(dado);

  if(primeiroNo == nullptr) {
    primeiroNo = novoNo;
    ultimoNo = novoNo;
  } else {
    ultimoNo->eloS = novoNo;
    ultimoNo = novoNo;
  }

  tamanhoLista++;
}

template<typename T>
void Lue<T>::remover(int index) {
  if(index < 0 || index >= tamanhoLista) {
    throw std::out_of_range("Index out of Bounds - remover");
  }

  No<T>* noParaDeletar = this->getNo(index);
  if(index == tamanhoLista - 1) {
    ultimoNo = this->getNo(index - 1);
    ultimoNo->eloS = nullptr;

    noParaDeletar->eloS = nullptr;
    delete noParaDeletar;

    return;
  } else if (index == 0) {
    primeiroNo = this->getNo(index + 1);
    
    noParaDeletar->eloS = nullptr;
    delete noParaDeletar;

    return;
  }

  this->getNo(index - 1) = noParaDeletar->eloS;

  noParaDeletar->eloS = nullptr;
  delete noParaDeletar;

  tamanhoLista--;
} 

template<typename T>
void Lue<T>::remover(T pesquisa) {
  this->remover(this->getIndex(pesquisa));
}

// Search methods
template<typename T>
T& Lue<T>::operator[](int index) {
  if(index < 0 || index >= tamanhoLista) {
    throw std::out_of_range("Index out of Bounds - operator");
  }

  No<T>* noDePesquisa = primeiroNo;
  for(int i = 0; i < index; i++) {
    noDePesquisa = noDePesquisa->eloS;
  }

  return noDePesquisa->dado;
}

template<typename T>
bool Lue<T>::existe(T pesquisa) {
  try {
    this->getIndex(pesquisa);
    return true;
  } catch (std::out_of_range &_) {
    return false;
  }
}

template<typename T>
int Lue<T>::getIndex(T pesquisa) {
  No<T>* noDePesquisa = primeiroNo;

  for(int i = 0; i < tamanhoLista; i++) {
    if (noDePesquisa->dado == pesquisa) {
      return noDePesquisa->dado;
    }
    noDePesquisa = noDePesquisa->eloS;
  }
}

template <typename T>
No<T>* Lue<T>::getNo(int index) {
  if(index < 0 || index >= tamanhoLista) {
    throw std::out_of_range("Index out of Bounds -- getNo");
  }

  No<T>* returnNo = primeiroNo;
  for(int i = 0; i < index; i++) {
    returnNo = returnNo->eloS;
  }

  return returnNo;
}

// List data
template<typename T>
int Lue<T>::tamanho() const { return tamanhoLista; };