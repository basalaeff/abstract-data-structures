// ============================================================================
// B14 ЗАГРУЗКА ИЗ БИНАРНОГО ФАЙЛА
// ============================================================================
template <typename T>
void SinglyLinkedList<T>::loadFromBinaryFile(const std::string& filename) {
  std::ifstream inFile(filename, std::ios::binary);
  if (!inFile) {
    std::cout << "Cannot open file for binary reading: " << filename
              << std::endl;
    return;
  }
  clear();  // Очистить текущий список перед загрузкой
  while (!inFile.eof()) {
    size_t len;
    inFile.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (inFile.eof()) break;  // Проверка конца файла
    T value(len, '\0');
    inFile.read(&value[0], len);
    addToTail(value);
  }
  inFile.close();
}