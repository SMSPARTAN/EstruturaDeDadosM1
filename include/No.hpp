// Definição da classe No

#pragma once

template <typename T>
class No {
protected:
  No(T dado);
  No(No<T> *NoPtr);
  No(No<T> &copyNo);

  T dado;
  No<T> *eloA;
  No<T> *eloS;
};

#include "../lib/No.cpp"
