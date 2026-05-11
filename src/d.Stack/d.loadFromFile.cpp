#include "d.Stack.hpp"
#include <fstream>
#include <stdexcept>

// ============================================================================
// ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================

void Stack::loadFromFile(const std::string& filename) {
  // Очищаем текущий стек перед загрузкой
  while (top_ != nullptr) {
    pop();
  }

  std::ifstream inFile(filename);
  if (!inFile.is_open()) {
    throw std::out_of_range("Cannot open file for reading: " + filename);
  }
  std::string line;
  while (std::getline(inFile, line)) {
    push(line);
  }
  inFile.close();
}