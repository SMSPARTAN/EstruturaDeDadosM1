// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include <string>

struct DominoPiece {
  int a;
  int b;

  DominoPiece(int x = -1, int y = -1);
  bool operator==(const DominoPiece &other) const;
  bool matches(int number) const;
  int getOther(int number) const;
  std::string toString() const;
  int sum() const;
  bool isDouble() const;
};

#include "../lib/DominoPiece.cpp"