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
    // ============================================================================
    // A3 Получение элемента(по индексу): AGET index
    // ============================================================================
  } else if (cmd == "AGET") {
    if (tokens.size() == 2) {
      int index = stoi(tokens[1]);
      std::string item = array_.get(index);
      std::cout << "Item by index " << index << ": " << item << std::endl;
    } else {
      std::cout << "Error: AGET command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // A4 Удаление элемента(по индексу): ADEL index
    // ============================================================================
  } else if (cmd == "ADEL") {
    if (tokens.size() == 2) {
      int index = stoi(tokens[1]);
      array_.removeByIndex(index);
    } else {
      std::cout << "Error: ADEL command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // A5 Замена элемента(по индексу): ASET index value
    // ============================================================================
  } else if (cmd == "AREPLACE") {
    if (tokens.size() == 3) {
      int index = stoi(tokens[1]);
      std::string value = tokens[2];
      array_.replaceByIndex(index, value);
    } else {
      std::cout << "Error: AREPLACE command requires 2 arguments." << std::endl;
    }
    // ============================================================================
    // A6 Получение длины массива: ALENGTH
    // ============================================================================
  } else if (cmd == "ALEN") {
    if (tokens.size() == 1) {
      std::cout << "Length of the array: " << array_.length() << std::endl;
    } else {
      std::cout << "Error: ALEN command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // B1 Добавление элемента (в голову): BADDHEAD value
    // ============================================================================
  } else if (cmd == "BADDHEAD") {
    if (tokens.size() == 2) {
      std::string value = tokens[1];
      singlyList_.addToHead(value);
    } else {
      std::cout << "Error: BADDHEAD command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // B2 Добавление элемента (в хвост): BADDTAIL value
    // ============================================================================
  } else if (cmd == "BADDTAIL") {
    if (tokens.size() == 2) {
      std::string value = tokens[1];
      singlyList_.addToTail(value);
    } else {
      std::cout << "Error: BADDTAIL command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // B3 Удаление элемента (из головы): BDELHEAD
    // ============================================================================
  } else if (cmd == "BDELHEAD") {
    if (tokens.size() == 1) {
      singlyList_.removeHead();
    } else {
      std::cout << "Error: BDELHEAD command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // B4 Удаление элемента (из хвоста): BDELTAIL
    // ============================================================================
  } else if (cmd == "BDELTAIL") {
    if (tokens.size() == 1) {
      singlyList_.removeTail();
    } else {
      std::cout << "Error: BDELTAIL command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // C1 Добавление элемента (в голову): CADDHEAD value
    // ============================================================================
  } else if (cmd == "CADDHEAD") {
    if (tokens.size() == 2) {
      std::string value = tokens[1];
      doublyList_.addToHead(value);
    } else {
      std::cout << "Error: CADDHEAD command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // C2 Добавление элемента (в хвост): CADDTAIL value
    // ============================================================================
  } else if (cmd == "CADDTAIL") {
    if (tokens.size() == 2) {
      std::string value = tokens[1];
      doublyList_.addToTail(value);
    } else {
      std::cout << "Error: CADDTAIL command requires 1 arguments." << std::endl;
    }
    // ============================================================================
    // C3 Удаление элемента (из головы): CDELHEAD
    // ============================================================================
  } else if (cmd == "CDELHEAD") {
    if (tokens.size() == 1) {
      doublyList_.removeHead();
    } else {
      std::cout << "Error: CDELHEAD command requires 0 arguments." << std::endl;
    }
    // ============================================================================
    // C4 Удаление элемента (из хвоста): CDELTAIL
    // ============================================================================
  } else if (cmd == "CDELTAIL") {
    if (tokens.size() == 1) {
      doublyList_.removeTail();
    } else {
      std::cout << "Error: CDELTAIL command requires 0 arguments." << std::endl;
    }
  } else if (cmd == "PRINT") {
    // ============================================================================
    // A7 Печать массива: APRINT
    // ============================================================================
    array_.print();
  } else {
    std::cout << "Unknown command: " << cmd << std::endl;
  }
}
