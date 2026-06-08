//==============================================================================
// D6 ЗАГРУЗКА ИЗ БИНАРНОГО ФАЙЛА
//==============================================================================
template <typename T>
void Stack<T>::loadFromBinaryFile(const std::string& filename) {
  std::ifstream inFile(filename, std::ios::binary);
  if (!inFile) {
    throw std::runtime_error("Cannot open file for binary reading: " +
                             filename);
  }

  clear();  // Очистить текущий стек перед загрузкой
  std::vector<T> tempStorage;

  while (true) {
    if constexpr (std::is_same_v<T, std::string>) {
      size_t len = 0;
      if (!inFile.read(reinterpret_cast<char*>(&len), sizeof(len))) break;

      std::string value(len, '\0');
      if (len > 0) {
        if (!inFile.read(&value[0], len)) break;  // Читаем прямо в буфер строки
      }
      tempStorage.push_back(std::move(value));
    } else {
      T value;
      if (!inFile.read(reinterpret_cast<char*>(&value), sizeof(T))) break;
      tempStorage.push_back(value);
    }
  }

  // добавляем элементы в стек в обратном порядке (LIFO)
  for (auto it = tempStorage.rbegin(); it != tempStorage.rend(); ++it) {
    push(*it);
  }

  inFile.close();
}