// Samuel Sarno de Almeida, Lucas André Alexandre

#include "../include/DominoUI.hpp"
#include "../include/Game.hpp"

int main() {
  DominoUI::printWelcome();

  try {
    Game game(4);
    game.distributePieces();

    bool continueGame = true;
    while (continueGame && !game.isGameOver()) {
      continueGame = DominoUI::processInput(game);
      if (continueGame) {
        game.playTurn();

        // Exibe o log atualizado
        DominoUI::clearScreen();
        game.printLastLogEntry();
        DominoUI::printGameState(game);
      }
    }

    DominoUI::printLog(game.getLog());
    DominoUI::printResults(game);

  } catch (const std::exception &e) {
    std::cerr << "Erro fatal: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Erro desconhecido!" << std::endl;
  }

  return 0;
}