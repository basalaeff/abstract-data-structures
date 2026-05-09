#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "ConsoleUI.hpp"

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
  if (cmd == "AADD") {
    if (tokens.size() == 2) {
      std::string value = tokens[1];
      array_.addToTheEnd(value);
    } else {
      std::cout << "Error: AADD command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // A2 Добавление элемента(по индексу): AINSERT index value
    // ============================================================================
  } else if (cmd == "AINSERT") {
    if (tokens.size() == 3) {
      int index = stoi(tokens[1]);
      std::string value = tokens[2];
      array_.addToTheIndex(index, value);
    } else {
      std::cout << "Error: AINSERT command requires 2 arguments." << std::endl;
    }
  }
  else {
    std::cout << "Unknown command: " << cmd << std::endl;
  }
}