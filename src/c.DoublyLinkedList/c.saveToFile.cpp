#include <fstream>
#include <iostream>

#include "c.DoublyLinkedList.hpp"

// ============================================================================
// СОХРАНЕНИЕ В ФАЙЛ
// ============================================================================
void DoublyLinkedList::saveToFile(const std::string& filename) const {
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << filename << std::endl;
    return;
  }
  DoublyNode* current = head_;
  while (current != nullptr) {
    file << current->data_ << "\n";
    current = current->next_;
  }
  file.close();
}
