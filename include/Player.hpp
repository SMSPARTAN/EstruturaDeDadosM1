// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include "DominoPiece.hpp"
#include "Lde.hpp"

class Player {
private:
  int id;
  Lde<DominoPiece> hand;

public:
  explicit Player(int playerId);
  void addPiece(const DominoPiece &piece);
  bool hasPiece(const DominoPiece &piece) const;
  void removePiece(const DominoPiece &piece);
  const Lde<DominoPiece> &getHand() const;
  int getId() const;
  bool hasPlayablePiece(int left, int right) const;
  DominoPiece findBestPlay(int left, int right) const;
};

#include "../lib/Player.cpp"