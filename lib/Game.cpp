// Samuel Sarno de Almeida, Lucas André Alexandre
#pragma once

#include "../include/Game.hpp"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

Game::Game(int numPlayers)
    : currentPlayerIndex(0)
    , passCount(0) {
  if (numPlayers < 2 || numPlayers > 4) {
    throw std::invalid_argument("Número de jogadores inválido (2-4)");
  }

  for (int i = 0; i < numPlayers; i++) {
    players.push_back(Player(i));
  }

  createAllPieces();
  shufflePieces();
}

void Game::createAllPieces() {
  for (int i = 0; i <= 6; i++) {
    for (int j = i; j <= 6; j++) {
      boneyard.push_back(DominoPiece(i, j));
    }
  }
}

void Game::shufflePieces() {
  srand(static_cast<unsigned>(time(nullptr)));
  for (int i = boneyard.size() - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    DominoPiece temp = boneyard[i];
    boneyard[i] = boneyard[j];
    boneyard[j] = temp;
  }
}

void Game::distributePieces() {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < players.size(); j++) {
      if (boneyard.size() > 0) {
        players[j].addPiece(boneyard[0]);
        boneyard.remove(0);
      }
    }
  }
  determineStartingPlayer();
}

void Game::determineStartingPlayer() {
  int maxDouble = -1;

  // Procura maior duplo
  for (int i = 0; i < players.size(); i++) {
    const Lde<DominoPiece> &hand = players[i].getHand();
    for (int j = 0; j < hand.size(); j++) {
      DominoPiece piece = hand[j];
      if (piece.isDouble() && piece.a > maxDouble) {
        maxDouble = piece.a;
        currentPlayerIndex = i;
      }
    }
  }

  // Se não encontrou duplos, procura maior soma
  if (maxDouble == -1) {
    int maxSum = -1;
    for (int i = 0; i < players.size(); i++) {
      const Lde<DominoPiece> &hand = players[i].getHand();
      for (int j = 0; j < hand.size(); j++) {
        int sum = hand[j].sum();
        if (sum > maxSum) {
          maxSum = sum;
          currentPlayerIndex = i;
        }
      }
    }
  }

  // Coloca peça inicial no tabuleiro
  DominoPiece startingPiece = players[currentPlayerIndex].findBestPlay(0, 0);
  players[currentPlayerIndex].removePiece(startingPiece);
  board.placeInitialPiece(startingPiece);

  log("Jogador " + std::to_string(currentPlayerIndex) +
      " inicia com " + startingPiece.toString());
}

void Game::playTurn() {
  Player &currentPlayer = players[currentPlayerIndex];
  DominoPiece pieceToPlay = currentPlayer.findBestPlay(
      board.getLeftEnd(), board.getRightEnd());

  bool played = false;

  if (pieceToPlay == DominoPiece(-1, -1)) {
    // Tenta comprar peças
    while (boneyard.size() > 0 && !played) {
      DominoPiece newPiece = boneyard[0];
      currentPlayer.addPiece(newPiece);
      boneyard.remove(0);
      log("Jogador " + std::to_string(currentPlayerIndex) +
          " comprou " + newPiece.toString());

      if (currentPlayer.hasPlayablePiece(board.getLeftEnd(), board.getRightEnd())) {
        pieceToPlay = currentPlayer.findBestPlay(
            board.getLeftEnd(), board.getRightEnd());
      }
    }
  }

  if (pieceToPlay != DominoPiece(-1, -1)) {
    if (pieceToPlay.matches(board.getLeftEnd())) {
      board.placePieceLeft(pieceToPlay);
      currentPlayer.removePiece(pieceToPlay);
      log("Jogador " + std::to_string(currentPlayerIndex) +
          " colocou " + pieceToPlay.toString() + " na esquerda");
      played = true;
    } else if (pieceToPlay.matches(board.getRightEnd())) {
      board.placePieceRight(pieceToPlay);
      currentPlayer.removePiece(pieceToPlay);
      log("Jogador " + std::to_string(currentPlayerIndex) +
          " colocou " + pieceToPlay.toString() + " na direita");
      played = true;
    }
  }

  if (!played) {
    log("Jogador " + std::to_string(currentPlayerIndex) + " passou");
    passCount++;
  } else {
    passCount = 0;
  }

  // Exibir estado atual após cada jogada
  std::cout << "\n--- Estado Atualizado ---";
  std::cout << "\nPasses consecutivos: " << passCount << "/" << players.size();
  std::cout << "\nPróximo jogador: " << ((currentPlayerIndex + 1) % players.size());
  std::cout << "\n-----------------------------\n";

  currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

bool Game::isGameOver() const {
  // Verificação detalhada
  std::cout << "\nVerificando condições de término:";
  std::cout << "\n• Passes consecutivos: " << passCount;
  std::cout << "\n• Peças no monte: " << boneyard.size();

  for (int i = 0; i < players.size(); i++) {
    std::cout << "\n• Jogador " << i << " tem " << players[i].getHand().size() << " peças";
    if (players[i].getHand().size() == 0) {
      std::cout << " → VITÓRIA!";
      return true;
    }
  }

  if (passCount >= players.size()) {
    std::cout << "\n→ JOGO BLOQUEADO!";
    return true;
  }

  return false;
}

void Game::runGame() {
  while (!isGameOver()) {
    playTurn();
  }

  // Determina resultado final
  for (int i = 0; i < players.size(); i++) {
    if (players[i].getHand().size() == 0) {
      log("Jogador " + std::to_string(i) + " venceu!");
      return;
    }
  }
  log("Jogo bloqueado! Todos passaram consecutivamente.");
}

void Game::log(const std::string &message) {
  gameLog.push_back(message);
}

const Lue<std::string> &Game::getLog() const {
  return gameLog;
}

void Game::printLastLogEntry() const {
  if (gameLog.size() > 0) {
    std::cout << "Última jogada: "
              << gameLog[gameLog.size() - 1]
              << std::endl;
  }
}