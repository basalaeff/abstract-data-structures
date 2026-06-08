// ============================================================================
// A11 БИНАРНОЕ СОХРАНЕНИЕ В ФАЙЛ
// ============================================================================
template <typename T>
void Array<T>::saveToBinaryFile(const std::string& filename) const {
  std::ofstream outFile(filename, std::ios::binary);
  if (!outFile) {
    std::cout << "Cannot open file for binary writing: " << filename
              << std::endl;
    return;
  }
  outFile.write(reinterpret_cast<const char*>(&size_), sizeof(size_));
  outFile.write(reinterpret_cast<const char*>(&maxCapacity_),
                sizeof(maxCapacity_));
  for (int i = 0; i < size_; ++i) {
    size_t len = data_[i].size();
    outFile.write(reinterpret_cast<const char*>(&len), sizeof(len));
    outFile.write(data_[i].c_str(), len);
  }
  outFile.close();
}