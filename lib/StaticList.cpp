// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include "../include/StaticList.hpp"
#include <stdexcept>

// List I/O
template<typename T>
void StaticList<T>::push_back(T data) {
  if(lastPos >= MAX_SIZE) {
    throw std::overflow_error("Over Maximum Array Capacity -- 100 Elements");
  }

  array[lastPos] = data;
}

template<typename T>
void StaticList<T>::remove(int index) {
  if(index >= lastPos || index < 0) {
    throw std::out_of_range("Index out of Bounds - remove");
  }

  for(int i = index; i < lastPos; i++) {
    array[i] = array[i + 1];
  }

  lastPos--;
}

template<typename T>
void StaticList<T>::remove(T search) {
  this->remove(this->getIndex(search));
}

// Search methods
template <typename T>
T& StaticList<T>::operator[](int index) {
  if(index < 0 || index >= lastPos) {
    throw std::out_of_range("Index out of Bounds -- operator");
  }

  return array[index];
}

template<typename T>
bool StaticList<T>::exists(T search) {
  for(auto & elemento : array) {
    if(elemento == search) {
      return true;
    }
  }

  return false;
}

template<typename T>
int StaticList<T>::getIndex(T search) {
  int index = 0;
  for(auto & elemento : array) {
    if (elemento == search) {
      return index;
    }
    index++;
  }
  
  throw std::out_of_range("Index out of Bounds - getIndex");
}

// List data
template<typename T>
int StaticList<T>::size() const {
  return lastPos;
};