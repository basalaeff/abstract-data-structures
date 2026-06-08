// ============================================================================
// B12 ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================
template <typename T>
void SinglyLinkedList<T>::loadFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Cannot open file for reading: " + filename);
  }
  // Очищаем текущий список
  while (head_ != nullptr) {
    removeFromHead();
  }
  // Загружаем новые элементы
  T value;
  while (file >> value) {
    addToTail(value);
  }
  file.close();
}