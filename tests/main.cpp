#include "../include/Lde.h"

#include <iostream>
#include <format>

int main() {
  Lde<std::string> lista;
  lista.insert("Hello");
  lista.insert(" ");
  lista.insert("World!");

  lista.remove(" ");

  std::cout << std::format("{}{}\n", lista[0], lista["World!"]);

  return 0;
}