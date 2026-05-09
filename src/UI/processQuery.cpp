#include "ConsoleUI.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// ============================================================================
// ФУНКЦИЯ ОБРАБОТКИ ЗАПРОСОВ
// ============================================================================
void ConsoleUI::processQuery(const std::string& query) {
  std::vector<std::string> tokens;
  std::stringstream ss(query);
  std::string token;

  while (std::getline(ss, token, ' ')) {
    if (!token.empty()) {
      tokens.push_back(token);
    }
  }

  if (tokens.empty()) {
    std::cout << "Error: empty query." << std::endl;
    return;
  }

  const std::string& cmd = tokens[0];

  // ============================================================================
  // МАССИВ(A)
  // ============================================================================

  // ============================================================================
  // A1 Добавление элемента(в конец массива): AADD value
  // ============================================================================
  if (tokens[0] == "AADD") {
    if (tokens.size() == 2) {
      std::string value = tokens[1];
      array_.addToTheEnd(value);
    } else {
      std::cout << "Error: AADD command requires 1 arguments." << std::endl;
    }
  } else {
    std::cout << "Unknown command: " << cmd << std::endl;
  }
}