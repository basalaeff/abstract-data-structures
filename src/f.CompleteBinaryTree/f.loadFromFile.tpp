// ============================================================================
// ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================
template <typename T>
void CBTree<T>::loadFromFile(const std::string& file) {
  clear(root_);
  std::ifstream load(file);
  if (!load.is_open()) {
    throw std::runtime_error("Failed to open file for loading");
  }

  T value;
  while (load >> value) {
    insert(value);
  }
  load.close();
}
