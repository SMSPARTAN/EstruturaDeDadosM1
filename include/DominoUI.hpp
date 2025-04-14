// Samuel Sarno De Almeida, Lucas André Alexandre

#pragma once

#include "Game.hpp"
#include <iostream>
#include <limits>

class DominoUI {
public:
  static void printWelcome();
  static void printHelp();
  static void printGameState(const Game& game);
  static void printLog(const Lue<std::string> &log);
  static void printResults(const Game &game);
  static bool processInput(Game& game);
  static void clearScreen();
};

#include "../lib/DominoUI.cpp"