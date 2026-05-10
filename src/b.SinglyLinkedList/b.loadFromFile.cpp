#include <fstream>

#include "b.SinglyLinkedList.hpp"

// ============================================================================
// ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================
void SinglyLinkedList::loadFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Cannot open file for reading: " + filename);
  }
  // Очищаем текущий список
  while (head_ != nullptr) {
    removeHead();
  }
  // Загружаем новые элементы
  std::string value;
  while (std::getline(file, value)) {
    if (!value.empty()) {  // пропускаем пустые строки
      addToTail(value);
    }
  }
  file.close();
}