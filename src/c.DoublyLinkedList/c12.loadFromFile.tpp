// ============================================================================
// C12 ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================
template <typename T>
void DoublyLinkedList<T>::loadFromFile(const std::string& filename) {
  // Очищаем текущий список
  while (head_ != nullptr) {
    removeFromHead();
  }

  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Unable to open file: " + filename);
  }

  T value;
  while (file >> value) {
    addToTail(value);
  }
  file.close();
}