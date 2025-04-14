// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#define MAX_SIZE 28

template<typename T>
class StaticList {
private:
  T array[MAX_SIZE];
  int lastPos;
public:
  StaticList() : lastPos(0) {}
  
  // List I/O
  void push_back(T data);
  void remove(int index);
  void remove(T search);

  // Search methods
  T& operator[](int index);
  bool exists(T search);
  int getIndex(T search);

  // Lista data
  [[nodiscard]] int size() const;
};

#include "../lib/StaticList.cpp"