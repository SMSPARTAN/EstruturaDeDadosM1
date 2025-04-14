// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include "DominoPiece.hpp"
#include "StaticList.hpp"

class Board {
private:
  StaticList<DominoPiece> placedPieces;
  int leftEnd;
  int rightEnd;

public:
  Board();
  void placeInitialPiece(const DominoPiece &piece);
  bool canPlacePiece(const DominoPiece &piece) const;
  void placePieceLeft(const DominoPiece &piece);
  void placePieceRight(const DominoPiece &piece);
  int getLeftEnd() const;
  int getRightEnd() const;
  std::string getBoardState() const;
};

#include "../lib/Board.cpp"