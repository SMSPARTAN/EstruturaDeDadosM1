// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include "../include/Board.hpp"

Board::Board()
    : leftEnd(-1)
    , rightEnd(-1) {}

void Board::placeInitialPiece(const DominoPiece &piece) {
  placedPieces.push_back(piece);
  leftEnd = piece.a;
  rightEnd = piece.b;
}

bool Board::canPlacePiece(const DominoPiece &piece) const {
  return piece.matches(leftEnd) || piece.matches(rightEnd);
}

void Board::placePieceLeft(const DominoPiece &piece) {
  int newEnd = piece.getOther(leftEnd);
  if (newEnd != -1) {
    placedPieces.push_back(piece);
    leftEnd = newEnd;
  }
}

void Board::placePieceRight(const DominoPiece &piece) {
  int newEnd = piece.getOther(rightEnd);
  if (newEnd != -1) {
    placedPieces.push_back(piece);
    rightEnd = newEnd;
  }
}

int Board::getLeftEnd() const { return leftEnd; }
int Board::getRightEnd() const { return rightEnd; }

std::string Board::getBoardState() const {
  std::string state;
  for (int i = 0; i < placedPieces.size(); i++) {
    state += placedPieces[i].toString() + " ";
  }
  return state;
}