// ============================================================================
// ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================
template <typename T>
void Array<T>::loadFromFile(const std::string& filename) {
  std::ifstream inFile(filename);
  if (!inFile.is_open()) {
    throw std::runtime_error("Cannot open file for reading: " + filename);
  }
  T value;
  size_ = 0;
  while (inFile >> value && size_ < maxCapacity_) {
    data_[size_] = value;
    size_++;
  }
  inFile.close();
}
