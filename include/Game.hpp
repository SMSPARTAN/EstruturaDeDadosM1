// Samuel Sarno de Almeida, Lucas André Alexandre

#pragma once

#include "Board.hpp"
#include "Lue.hpp"
#include "Player.hpp"
#include "StaticList.hpp"
#include <iostream>

class Game {
private:
  Lue<Player> players;
  StaticList<DominoPiece> boneyard;
  Board board;
  Lue<std::string> gameLog;
  int currentPlayerIndex;
  int passCount;

  void createAllPieces();
  void shufflePieces();
  void determineStartingPlayer();
  bool drawPiece(Player &player);
  void log(const std::string &message);

  friend class DominoUI;

public:
  explicit Game(int numPlayers);

  void distributePieces();
  void playTurn();
  bool isGameOver() const;
  void printGameState() const;
  void runGame();
  const Lue<std::string> &getLog() const;
  const StaticList<DominoPiece> &getBoneyard() const { return boneyard; }
  const Lue<Player> &getPlayers() const { return players; }
  const Board &getBoard() const { return board; }
  int getCurrentPlayerIndex() const { return currentPlayerIndex; }
  int getPassCount() const { return passCount; }
  void printLastLogEntry() const;
};

#include "../lib/Game.cpp"