// ============================================================================
// БИНАРНАЯ ЗАГРУЗКА ИЗ ФАЙЛА
// ============================================================================
template <typename T>
void Array<T>::loadFromBinaryFile(const std::string& filename) {
  std::ifstream inFile(filename, std::ios::binary);
  if (!inFile) {
    std::cout << "Cannot open file for binary reading: " << filename
              << std::endl;
    return;
  }
  inFile.read(reinterpret_cast<char*>(&size_), sizeof(size_));
  inFile.read(reinterpret_cast<char*>(&maxCapacity_), sizeof(maxCapacity_));
  delete[] data_;
  data_ = new T[maxCapacity_];
  for (int i = 0; i < size_; ++i) {
    size_t len;
    inFile.read(reinterpret_cast<char*>(&len), sizeof(len));
    data_[i].resize(len);
    inFile.read(&data_[i][0], len);
  }
  inFile.close();
}
