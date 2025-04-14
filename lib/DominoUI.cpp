// Samuel Sarno de Almeida, Lucas André Alexandre
#pragma once

#include "../include/DominoUI.hpp"
#include <iomanip>
#include <iostream>

using namespace std;

void DominoUI::printWelcome() {
  cout << "========================================\n"
       << "          JOGO DE DOMINÓ 1.0           \n"
       << "========================================\n\n";
}

void DominoUI::printLog(const Lue<string> &log) {
  cout << "\n=== HISTÓRICO DE JOGADAS ===\n";
  for (int i = 0; i < log.size(); i++) {
    cout << "• " << log[i] << endl;
  }
}

void DominoUI::printResults(const Game &game) {
  cout << "\n=== RESULTADO FINAL ===\n";

  // Encontrar vencedor ou calcular pontuações
  int minScore = 1000;
  int winningPlayer = -1;
  bool draw = false;

  // Calcular pontuações e verificar vitória
  for (int i = 0; i < game.players.size(); i++) {
    const auto &hand = game.players[i].getHand();
    int score = 0;

    // Exibir mão do jogador
    cout << "Jogador " << i << " ("
         << hand.size() << " peças): ";
    for (int j = 0; j < hand.size(); j++) {
      cout << hand[j].toString() << " ";
      score += hand[j].sum();
    }

    cout << "\nPontuação: " << score << endl
         << endl;

    // Verificar menor pontuação
    if (score < minScore) {
      minScore = score;
      winningPlayer = i;
      draw = false;
    } else if (score == minScore) {
      draw = true;
    }
  }

  // Exibir resultado final
  if (winningPlayer != -1 && !draw) {
    cout << "Vencedor: Jogador " << winningPlayer
         << " com " << minScore << " pontos!\n";
  } else {
    cout << "Empate técnico! Todos com " << minScore
         << " pontos.\n";
  }
}

// Função adicional para exibir estado durante o jogo
void DominoUI::printGameState(const Game &game) {
  cout << "\n=== ESTADO ATUAL ==="
       << "\nPeças no monte: " << game.getBoneyard().size()
       << "\nExtremidades: " << game.getBoard().getLeftEnd()
       << " | " << game.getBoard().getRightEnd()
       << "\nPróximo jogador: " << game.getCurrentPlayerIndex()
       << "\nMesa: ";

  const auto &boardState = game.getBoard().getBoardState();
  if (boardState.empty()) {
    cout << "Vazia";
  } else {
    // Exibir no máximo 10 peças por linha
    int count = 0;
    for (int i = 0; i < boardState.size(); i++) {
      cout << boardState[i];
      if (++count % 10 == 0)
        cout << "\n      ";
      else
        cout << " ";
    }
  }
  cout << endl;
}

// Função para exibir ajuda
void DominoUI::printHelp() {
  cout << "\nCOMANDOS DISPONÍVEIS:\n"
       << "• (enter) - Continuar jogo\n"
       << "• q       - Sair do jogo\n"
       << "• h       - Exibir ajuda\n"
       << "• l       - Exibir histórico\n"
       << "• s       - Exibir estado atual\n";
}

bool DominoUI::processInput(Game &game) {
  char input = '\0';

  cout << "\n> Pressione 'c' para continuar ou 'h' para ajuda...";

  // Limpa quaisquer erros anteriores e buffers
  cin.clear();
  // cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Lê o input do usuário
  cin.get(input);

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  switch (input) {
  case 'q':
    return false;
  case 'h':
    printHelp();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    break;
  case 'l':
    printLog(game.getLog());
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    break;
  case 's':
    printGameState(game);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    break;
  case 'c':
    break;
  default:
    cout << "Comando inválido! Use 'h' para ajuda.\n";
  }

  return true;
}

void DominoUI::clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}