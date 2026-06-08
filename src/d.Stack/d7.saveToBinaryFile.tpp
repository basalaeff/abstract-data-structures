// ============================================================================
// D7 СОХРАНЕНИЕ В БИНАРНЫЙ ФАЙЛ
// ============================================================================
template <typename T>
void Stack<T>::saveToBinaryFile(const std::string& filename) const {
  std::ofstream outFile(filename, std::ios::binary);
  if (!outFile) {
    throw std::runtime_error("Cannot open file for binary writing: " +
                             filename);
  }

  Node<T>* current = top_;
  while (current) {
    // Для std::string
    if constexpr (std::is_same_v<T, std::string>) {
      size_t len = current->data_.size();
      outFile.write(reinterpret_cast<const char*>(&len), sizeof(len));
      if (len > 0) {
        outFile.write(current->data_.c_str(), len);
      }
    } else {
      // Для POD типов (int, double и т.д.)
      outFile.write(reinterpret_cast<const char*>(&current->data_), sizeof(T));
    }
    current = current->next_;
  }
  outFile.close();
}