// Samuel Sarno de Almeida, Lucas André Alexandre

#include "../include/Lde.hpp"

#include <iostream>
#include <format>

int main() {
  Lde<std::string> lista;
  lista.push_back("Hello");
  lista.push_back(" ");
  lista.push_back("World!");

  lista.remove(" ");

  std::cout << std::format("{} {}", lista[0], lista[1]);

  return 0;
}