#include "e.Queue.hpp"
#include <fstream>
#include <stdexcept>

// ============================================================================
// ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================

void Queue::loadFromFile(const std::string& filename) {
  // Очищаем текущую очередь перед загрузкой
  while (front_ != nullptr) {
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