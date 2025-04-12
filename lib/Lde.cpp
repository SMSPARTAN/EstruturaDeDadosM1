// Implementação dos métodos de Lde.hpppp
#pragma once

#include "../include/Lde.hpp"
#include <stdexcept>

template <typename T>
Lde<T>::Lde() {
  primeiroNo = nullptr;
  ultimoNo = nullptr;
  tamanhoLista = 0;
}

// List I/O
template <typename T>
void Lde<T>::inserir(T dado) {
  No<T>* novoNo = new No<T>(dado);

  if(primeiroNo == nullptr) {
    primeiroNo = novoNo;
    ultimoNo = novoNo;
  } else {
    novoNo->eloA = ultimoNo;
    ultimoNo->eloS = novoNo;
    ultimoNo = novoNo;
  }

  tamanhoLista++;
}

template <typename T>
void Lde<T>::remover(int index) {
  if(index < 0 || index >= tamanhoLista) {
    throw std::out_of_range("Index out of Bounds -- remover");
  }

  No<T> *noParaDeletar = this->getNo(index);
  if(index == tamanhoLista - 1) {
    ultimoNo = ultimoNo->eloA;
    ultimoNo->eloS = nullptr;

    noParaDeletar->eloA = nullptr;
    noParaDeletar->eloS = nullptr;
    delete noParaDeletar;  

    return;
  } else if (index == 0) {
    primeiroNo = primeiroNo->eloS;
    primeiroNo->eloA = nullptr;

    noParaDeletar->eloS = nullptr;
    delete noParaDeletar;

    return;
  }

  No<T>* noAntecessor = noParaDeletar->eloA;
  No<T>* noSucessor = noParaDeletar->eloS;

  noAntecessor->eloS = noSucessor;
  noSucessor->eloA = noAntecessor;

  noParaDeletar->eloA = nullptr;
  noParaDeletar->eloS = nullptr;

  tamanhoLista--;

  delete noParaDeletar;
}

template <typename T>
void Lde<T>::remover(T pesquisa) {
  No<T> *noParaDeletar = this->getNo(pesquisa);
  if(noParaDeletar == ultimoNo) {
    ultimoNo = ultimoNo->eloA;
    ultimoNo->eloS = nullptr;

    noParaDeletar->eloA = nullptr;
    noParaDeletar->eloS = nullptr;
    delete noParaDeletar;  

    return;
  } else if (noParaDeletar == primeiroNo) {
    primeiroNo = primeiroNo->eloS;
    primeiroNo->eloA = nullptr;

    noParaDeletar->eloS = nullptr;
    delete noParaDeletar;

    return;
  }

  No<T>* noAntecessor = noParaDeletar->eloA;
  No<T>* noSucessor = noParaDeletar->eloS;

  noAntecessor->eloS = noSucessor;
  noSucessor->eloA = noAntecessor;

  noParaDeletar->eloA = nullptr;
  noParaDeletar->eloS = nullptr;

  tamanhoLista--;

  delete noParaDeletar;
}

// Search methods

template <typename T>
T& Lde<T>::operator[](int index) {
  if(index < 0 || index >= tamanhoLista) {
    throw std::out_of_range("Index out of Bounds -- Operator");
  }

No<T>* noAtual = primeiroNo;
  for(int i = 0; i < index; i++) {
   noAtual = noAtual->eloS;
  }

  return noAtual->dado;
}

template<typename T>
bool Lde<T>::existe(T pesquisa) {
  try {
    this->getIndex(pesquisa);
    return true;
  } catch (std::out_of_range &_) {
    return false;  
  }
}

template<typename T>
int Lde<T>::getIndex(T pesquisa) {
  No<T>* noDePesquisa = primeiroNo;
  for(int i = 0; i < tamanhoLista; i++) {
    if(noDePesquisa->dado == pesquisa) {
      return i;
    }
    noDePesquisa = noDePesquisa->eloS;
  }

  throw std::out_of_range("Index out of Bounds -- getIndex");
}

template <typename T>
No<T>* Lde<T>::getNo(int index) {
  if(index < 0 || index >= tamanhoLista) {
    throw std::out_of_range("Index out of Bounds -- getNo");
  }

  No<T>* returnNo = primeiroNo;
  for(int i = 0; i < index; i++) {
    returnNo = returnNo->eloS;
  }

  return returnNo;
}

template <typename T>
No<T>* Lde<T>::getNo(T pesquisa) {
No<T>* returnNo = primeiroNo;

while(returnNo != nullptr) {
  if(returnNo->dado == pesquisa) {
  return returnNo;
  }

  returnNo = returnNo->eloS;
}

  throw std::out_of_range("Index out of Bounds -- getNo(pesquisa)");
}

// List dado
template <typename T>
int Lde<T>::tamanho() const {
  return tamanhoLista;
}
