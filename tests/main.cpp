#include "../include/Lde.hpp"

#include <iostream>
#include <format>

int main() {
  Lde<std::string> lista;
  lista.inserir("Hello");
  lista.inserir(" ");
  lista.inserir("World!");

  lista.remover(" ");

  std::cout << std::format("{} {}", lista[0], lista[1]);

  return 0;
}