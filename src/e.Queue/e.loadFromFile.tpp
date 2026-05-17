// ============================================================================
// ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================

template <typename T>
void Queue<T>::loadFromFile(const std::string& filename) {
  // Очищаем текущую очередь перед загрузкой
  while (front_ != nullptr) {
    pop();
  }

  std::ifstream inFile(filename);
  if (!inFile.is_open()) {
    throw std::out_of_range("Cannot open file for reading: " + filename);
  }
  T value;
  while (inFile >> value) {
    push(value);
  }
  inFile.close();
}