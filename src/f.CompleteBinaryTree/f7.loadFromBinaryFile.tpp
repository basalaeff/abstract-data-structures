// ============================================================================
// F7 ЗАГРУЗКА ИЗ БИНАРНОГО ФАЙЛА
// ============================================================================
template <typename T>
void CBTree<T>::loadFromBinaryFile(const std::string& file) {
  clear(root_);

  std::ifstream load(file, std::ios::binary);
  if (!load.is_open()) {
    throw std::runtime_error("Failed to open file for loading");
  }

  while (load.peek() != EOF) {
    // 1. Читаем размер строки
    size_t len = 0;
    load.read(reinterpret_cast<char*>(&len), sizeof(size_t));

    if (load.eof()) break;

    // 2. Читаем данные
    std::string value(len, '\0');  // Создаем строку нужной длины
    if (len > 0) {
      load.read(&value[0], len);
    }

    insert(value);
  }

  load.close();
}