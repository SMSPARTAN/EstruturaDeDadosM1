// Implementação dos métodos de No.hpp
#include "../include/No.h"

template <typename T>
No<T>::No(T dado) : dado(dado), eloA(nullptr), eloS(nullptr) {}

template <typename T>
No<T>::No(No<T> *NoPtr) {
  this->dado = NoPtr->dado;
  this->eloA = NoPtr->eloA;
  this->eloS = NoPtr->eloS;
}

template <typename T>
No<T>::No(No<T> &copyNo) {
  this->dado = copyNo.dado;
  this->eloA = copyNo.eloA;
  this->eloS = copyNo.eloS;
}