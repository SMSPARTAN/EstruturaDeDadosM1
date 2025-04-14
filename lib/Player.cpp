// Samuel Sarno de Almeida, Lucas André Alexandre
#pragma once

#include "../include/Player.hpp"

Player::Player(int playerId)
    : id(playerId) {}

void Player::addPiece(const DominoPiece &piece) {
  hand.push_back(piece);
}

bool Player::hasPiece(const DominoPiece &piece) const {
  return hand.exists(piece);
}

void Player::removePiece(const DominoPiece &piece) {
  hand.remove(piece);
}

const Lde<DominoPiece> &Player::getHand() const {
  return hand;
}

int Player::getId() const {
  return id;
}

bool Player::hasPlayablePiece(int left, int right) const {
  for (int i = 0; i < hand.size(); i++) {
    if (hand[i].matches(left) || hand[i].matches(right)) {
      return true;
    }
  }
  return false;
}

DominoPiece Player::findBestPlay(int left, int right) const {
  DominoPiece bestPlay(-1, -1);
  int maxScore = -1;

  for (int i = 0; i < hand.size(); i++) {
    const DominoPiece &piece = hand[i];
    int score = 0;

    if (piece.isDouble())
      score += 10;
    score += piece.sum();

    if ((piece.matches(left) || piece.matches(right)) && score > maxScore) {
      bestPlay = piece;
      maxScore = score;
    }
  }
  return bestPlay;
}