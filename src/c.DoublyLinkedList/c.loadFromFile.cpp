#include <fstream>
#include <iostream>

#include "c.DoublyLinkedList.hpp"

// ============================================================================
// ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================
void DoublyLinkedList::loadFromFile(const std::string& filename) {
  // Очищаем текущий список
  while (head_ != nullptr) {
    removeFromHead();
  }

  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Unable to open file: " << filename << std::endl;
    return;
  }

  std::string value;
  while (file >> value) {
    addToTail(value);
  }
  file.close();
}