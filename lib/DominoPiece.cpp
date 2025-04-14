// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include "../include/DominoPiece.hpp"
#include <algorithm>

DominoPiece::DominoPiece(int x, int y) {
  a = std::min(x, y);
  b = std::max(x, y);
}

bool DominoPiece::operator==(const DominoPiece &other) const {
  return (a == other.a) && (b == other.b);
}

bool DominoPiece::matches(int number) const {
  return (a == number) || (b == number);
}

int DominoPiece::getOther(int number) const {
  if (a == number)
    return b;
  if (b == number)
    return a;
  return -1;
}

std::string DominoPiece::toString() const {
  return "[" + std::to_string(a) + "|" + std::to_string(b) + "]";
}

int DominoPiece::sum() const {
  return a + b;
}

bool DominoPiece::isDouble() const {
  return a == b;
}