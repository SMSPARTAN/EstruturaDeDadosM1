#include "../include/Lde.h"

#include <iostream>
#include <format>

int main() {
  Lde<std::string> lista;
  lista.inserir("Hello");
  lista.inserir(" ");
  lista.inserir("World!");

  lista.remover(" ");

  std::cout << std::format("{}{}\n", lista[0], lista["World!"]);

  return 0;
}